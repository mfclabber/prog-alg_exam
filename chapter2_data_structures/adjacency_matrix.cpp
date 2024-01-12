// 3. Построить матрицу смежности для графа, заданного преподавателем.

#include <iostream>
#include <vector>

using namespace std;
 
int main()
{
    int n, m, x, y;

    cout << "Введите количество вершин: ";
    cin >> n;
    cout << "Введите количество рёбер: ";
    cin>> m;

    std::vector<std::vector<int>> a(n, std::vector<int>(n, 0));

    cout << "Введите рёбра: " << endl;
    for(int i=0; i < m; ++i)
    {
        cin >> x >> y;
        a[x-1][y-1]=1;
        a[y-1][x-1]=1;
    }
    cout << endl;

    cout << "Матрица смежности: " << endl;
    for(int i=0; i < n; ++i)
    {
        for(int j=0; j < n;j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}