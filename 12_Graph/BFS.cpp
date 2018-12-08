#include <iostream>
#include <queue>
#define MAX 100
#define INFTY 2000000000
#define WHITE 0
#define GRAY 1
#define BLACK 2
using namespace std;

int n;
int M[MAX][MAX];
int Colors[MAX];
int d[MAX];
int t = 0;
queue<int> Q;

void bfs()
{
    for(int i=0; i<n; i++)
    {
        Colors[i] = WHITE;
        d[i] = INFTY;
    }

    Colors[0] = GRAY;
    d[0] = 0;
    Q.push(0);
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for(int v=0; v<n; v++)
        {
            if(M[u][v]==1 && Colors[v] == WHITE)
            {
                Colors[v] = GRAY;
                d[v] = d[u] + 1;
                Q.push(v);
            }
        }
        Colors[u] = BLACK;
    }

    for(int i=0; i<n; i++)
    {
        if(Colors[i] == WHITE)
        {
            d[i] = -1;
        }
    }
}

int main()
{
    int u, k, v;
    cin >> n;

    //initialization of M
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            M[i][j] = 0;
        }
    }

    for(int i=0; i<n; i++)
    {
        cin >> u >> k;
        for(int j=0; j<k; j++)
        {
            cin >> v;
            M[u-1][v-1] = 1;
        }
    }

    bfs();

    for(int i=0; i<n; i++)
    {
        cout << i+1 << " " << d[i] << endl;
    }
    
    return 0;
}