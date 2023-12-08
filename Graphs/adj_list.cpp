#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class graph
{
public:
    unordered_map<int, list<int>> adj;
    void edges(int u, int v, bool direction)
    {
        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }
    void print()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto k : i.second)
            {
                cout <<","<< k ;
            }
            cout << endl;
        }
    }
};

int main()
{
    int n, m;
    cout << "enter number of nodes" << endl;
    cin >> n;
    cout << "enter number of edges" << endl;
    cin >> m;
    graph g;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.edges(u, v, 0);
    }

    g.print();
    return 0;
}