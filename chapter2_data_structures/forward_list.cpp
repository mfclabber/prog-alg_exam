// 1. Реализовать односвязный список для произвольного типа элементов.

#include <iostream>

using namespace std;

template<typename T>
class forward_list{
public:
    forward_list();
    ~forward_list();
    bool empty();
    T& front();
    void push_front(T);
    void pop_front();
    T& operator[] (int index);
private:
    // Структура узла односвязного списка
    struct Node{
        Node* next; // указатель на следующий узел
        T data; // значение узла
     
        Node(T data): data(data), next(nullptr){}
    };

    Node* head; // корень списка
};

// конструктор
template <typename T>
forward_list<T>::forward_list(){
    head = nullptr;
}

template<typename T>
forward_list<T>::~forward_list()
{   
    while(head != nullptr)
    {   
        Node* nextNode = head->next;
        delete head;
        head = nextNode;
    }
    cout << "All elements delete";
}

// Проверка на наличие элементов
template <typename T>
bool forward_list<T>::empty(){
    return head == nullptr;
}

// Получение значения первого элемента
template <typename T>
T& forward_list<T>::front(){
    return head->data;
}

// добавление элемента в конец списка
template <typename T>
void forward_list<T>::push_front(T data){
    Node* p = new Node(data);

    if (!empty())
        p->next = head;
    head = p;
}

// удаление первого элемента
template <typename T>
void forward_list<T>::pop_front(){
    if (!empty()){
        Node* p = head;
        head = head->next;
        delete p;
    }else{
        cout << "List empty." << endl; 
        return; 
    }
}

// оператор индексирования
template <typename T>
T& forward_list<T>::operator[] (const int index){
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
    forward_list<int> lst;

    cout << (lst.empty()? "TRUE": "FALSE") << "\n";

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