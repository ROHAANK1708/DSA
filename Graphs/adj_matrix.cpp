#include <iostream>
using namespace std;
class graph
{
   public:
        
    int arr[10][10]={0};
    void edges(int u, int v, bool direction)
    {
        
        arr[u][v] = 1;
        if (direction == 0)
        {
            arr[v][u] = 1;
        }
    }
    void print(int n, int m){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
           
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
    cout<<"enter edges"<<endl;
    int arr[n][m] = {0};
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.edges(u, v, 0);
    }
    cout<<"matrix is"<<endl;
     g.print(n,m);
    return 0;
}