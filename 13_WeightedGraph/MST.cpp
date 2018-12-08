#include <iostream>
#define MAX 100
#define INFTY 10000
#define WHITE 0
#define GRAY 1
#define BLACK 2
using namespace std;

int n;
int M[MAX][MAX];
int Colors[MAX];
int d[MAX];
int p[MAX];

void prim()
{
    for(int i=0; i<n; i++)
    {
        Colors[i] = WHITE;
        d[i] = INFTY;
    }

    d[0] = 0;
    p[0] = -1;

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
            if(Colors[v] == BLACK || M[u][v] == -1) continue;
            if(M[u][v] < d[v])
            {
                d[v] = M[u][v];
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
            cin >> M[i][j];
        }
    }

    prim();

    int sum = 0;
    for(int i=0; i<n; i++)
    {
        sum += d[i];
    }

    cout << sum << endl;

    return 0;
}