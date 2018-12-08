#include <iostream>
#define MAX 100
#define INFTY 200000
#define WHITE 0
#define GRAY 1
#define BLACK 2
using namespace std;

int n;
int M[MAX][MAX];
int Colors[MAX];
int d[MAX];
int p[MAX];

void dijkstra(int s)
{
    for(int i=0; i<n; i++)
    {
        Colors[i] = WHITE;
        d[i] = INFTY;
    }

    d[s] = 0;
    p[s] = -1;

    while(true)
    {
        int u;
        int mincost = INFTY;
        for(int i=0; i<n; i++)
        {
            if(Colors[i] != BLACK && d[i] < mincost)
            {
                mincost = d[i];
                u = i;
            }
        }

        if(mincost == INFTY) break;

        Colors[u] = BLACK;

        for(int v=0; v<n; v++)
        {
            if(Colors[v] == BLACK || M[u][v] == INFTY) continue;
            if(d[u] + M[u][v] < d[v])
            {
                d[v] = d[u] + M[u][v];
                p[v] = u;
                Colors[v] = GRAY;
            }
        }
    }
}

int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            M[i][j] = INFTY;
        }
    }

    int u, k, v, c;
    for(int i=0; i<n; i++)
    {
        cin >> u >> k;
        for(int j=0; j<k; j++)
        {
            cin >> v >> c;
            M[u][v] = c;
        }
    }

    dijkstra(0);

    for(int i=0; i<n; i++)
    {
        cout << i << " " << d[i] << endl;
    }

    return 0;
}