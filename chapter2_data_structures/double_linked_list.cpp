// 2. Реализовать двухсвязный список для произвольного типа элементов.

#include <iostream>

using namespace std;

template<typename T>
class list{
public:
    list();
    ~list();
    void push_back(T);
    void push_front(T);
    T back();
    T front();
    void insert(size_t, T);
    void pop_back();
    void pop_front();
    T& operator[] (int index);

private:
    struct Node{
        T data;
        Node* next, *prev;

        Node(T data): data(data), next(nullptr), prev(nullptr){}
    };

    Node* head, *tail;
    size_t count;
};

template<typename T>
list<T>::list(): head(nullptr), tail(nullptr), count(0) {}

template<typename T>
list<T>::~list(){
    while(head != nullptr)
    {
        Node* nextNode = head->next;
        delete head;
        head = nextNode;
    }
    tail = nullptr;
    count = 0;
}

template<typename T>
void list<T>::push_front(T data){
    Node* newNode = new Node(data);
    if(newNode != nullptr){
        if (head == nullptr){
            head = tail = newNode;
            head->next = tail;
            tail->next = nullptr;
            head->prev = nullptr;
        }else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    ++count;
}

template<typename T>
void list<T>::push_back(T data){
    Node* newNode = new Node(data);
    if(newNode != nullptr){
        if (head == nullptr){
            head = tail = newNode;
            head->next = tail;
            tail->next = nullptr;
            head->prev = nullptr;
        }else{
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
    ++count;
}

template<typename T>
T list<T>::front(){
    if(head == nullptr) return T();
    return head->data;
}

template<typename T>
T list<T>::back(){
    if(head == nullptr) return T();
    return tail->data;
}

template<typename T>
void list<T>::insert(size_t idx, T val){
    if( head == nullptr || idx < 0 || idx > count + 1) return;
    if(idx == 0) push_front(val);
    if(idx == count + 1) push_front(val);
    
    Node* tmp = head;
    Node* newNode = new Node(val);
    for(int i=0; i < idx; ++i){
        tmp = tmp->next;
    }
 
    tmp->prev->next = newNode;
    newNode->next = tmp;
    newNode->prev = tmp->prev;
    tmp->prev = newNode;
    ++count;
}

template<typename T>
void list<T>::pop_back(){
    if(head == nullptr) return;
    Node* tmp = tail;
    tail = tail->prev;
    delete tmp;
}

template<typename T>
void list<T>::pop_front(){
    if(head == nullptr) return;
    Node* tmp = head;
    head = head->next;
    delete tmp;
}

// оператор индексирования
template <typename T>
T& list<T>::operator[] (const int index){
    int count = 0;
    Node* current = this->head;
    while(current != nullptr){
        if(count == index){
            return current->data;
        }
        current = current->next;
        count++;
    }
}

int main(){
    list<int> lst;

    lst.push_front(1);
    cout << lst.front() << "\n";

    lst.push_front(2);
    cout << lst.front() << "\n";
    lst.pop_front();
    cout << lst.front() << "\n";

    lst.push_front(3);
    lst.push_front(4);

    cout << lst[0] << ' ' << lst[1] <<"\n";
}