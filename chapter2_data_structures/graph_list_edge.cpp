// 6. Адаптировать реализацию класса Graph для представления графа в виде списка ребер.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Graph {
private:
    bool** adjMatrix;
    bool** incidence_matrix;
    int numVertices;
    int count;
    vector<vector<string>> lst_edge;
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


    // преобразование матрицы смежности в список ребер
    void adjToLstEdge() { 
        string s;
        for (int i = 0; i < numVertices; i++) {
            lst_edge.push_back({});
            for (int j = 0; j < numVertices; j++)
                if(adjMatrix[i][j]){
                    s = to_string(i+1) + to_string(j+1);
                    lst_edge[i].push_back(s);
                }
        }
    }

    void toStringLstEdge() {
        for (int i = 0; i < numVertices; i++) {
            cout << i + 1<< " : ";
            for (int j = 0; j < lst_edge[i].size(); j++)
                cout << lst_edge[i][j] << " ";
            cout << "\n";
        }
    }

    // Печать матрицы смежности
    void toString() {
        for (int i = 0; i < numVertices; i++) {
            cout << i << " : ";
            for (int j = 0; j < numVertices; j++)
                cout << adjMatrix[i][j] << " ";
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

    /* посчитано вручную
      14 24 35 45 56
    1  1  0  0  0  0
    2  0  1  0  0  0
    3  0  0  1  0  0
    4  1  1  0  1  0
    5  0  0  1  1  1
    6  0  0  0  0  1
    */
    cout << "\n";
    
    g.adjToLstEdge();
    g.toStringLstEdge();
}