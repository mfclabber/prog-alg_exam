// 5. Адаптировать реализацию класса Graph для представления графа в виде матрицы инцидентности.

#include <iostream>

using namespace std;

class Graph {
private:
    bool** adjMatrix;
    bool** incidence_matrix;
    int numVertices;
    int count;
public:
    Graph(int numVertices) {
        this->numVertices = numVertices;
        adjMatrix = new bool* [numVertices];
        for (int i = 0; i < numVertices; i++) {
            adjMatrix[i] = new bool[numVertices];
            for (int j = 0; j < numVertices; j++)
                adjMatrix[i][j] = false;
        }
    }

    void addEdge(int i, int j) {
        adjMatrix[i][j] = true;
        adjMatrix[j][i] = true;
    }

    void removeEdge(int i, int j) {
        adjMatrix[i][j] = false;
        adjMatrix[j][i] = false;
    }

    bool isEdge(int i, int j) {
        return adjMatrix[i][j];
    }

    // преобразования матрицы смежности в матрицу инцидентности
    void adjToinc() {
        count = 0; // количество ребер * 2
        int C = 0; // номер текущего ребра

        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                count += this->isEdge(i, j); // считаем кол-во ребер
            }
        }

        count /= 2; // так вершины цикличны в матрице смежности
        incidence_matrix = new bool* [numVertices];
        //Заполним матрицу значениями
        for (int i = 0; i < numVertices; ++i) { // строки вершины
            incidence_matrix[i] = new bool[count];
            for (int j = 0; j < count; ++j) { // столбцы ребра
                incidence_matrix[i][j] = false;
            }
        }

        // Обходим исходную матрицу выше диагонали, и ищем смежные ребра

        for (int i = 0; i < numVertices; ++i) { // строки вершины
            for (int j = i + 1; j < count + 1; ++j) { // столбцы ребра
                if (this->isEdge(i, j)) {
                    incidence_matrix[i][C] = true;
                    incidence_matrix[j][C++] = true;
                }
            }
        }
    }

    // печать матрицы смежности
    void toString() {
        for (int i = 0; i < numVertices; i++) {
            cout << i << " : ";
            for (int j = 0; j < numVertices; j++)
                cout << adjMatrix[i][j] << " ";
            cout << "\n";
        }
    }

    // печать матрицы инцидентности
    void toStringInc(){
        cout << "\n";
        for (int i = 0; i < numVertices; i++) {
            cout << i << " : ";
            for (int j = 0; j < count; j++)
                cout << incidence_matrix[i][j] << " ";
            cout << "\n";
        }
    }

    ~Graph() {
        for (int i = 0; i < numVertices; i++)
            delete[] adjMatrix[i];
        delete[] adjMatrix;
    }
};
int main() {
    Graph g(6);

    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(4, 5);
    g.addEdge(3, 4);
    g.toString();

    /*
      14 24 35 45 56
    1  1  0  0  0  0
    2  0  1  0  0  0
    3  0  0  1  0  0
    4  1  1  0  1  0
    5  0  0  1  1  1
    6  0  0  0  0  1
    */

    g.adjToinc();
    g.toStringInc();
}