#include <iostream>
#define MAX 100
#define WHITE 0
#define GRAY 1
#define BLACK 2
using namespace std;

int n;
int M[MAX][MAX];
int Colors[MAX];
int d[MAX];
int f[MAX];
int t = 0;

void dfs(int u)
{
    Colors[u] = GRAY;
    d[u] = ++t;

    for(int i=0; i<n; i++)
    {
        if(M[u][i] == 1 && Colors[i] == WHITE)
        {
            dfs(i);
        }
    }

    Colors[u] = BLACK;
    f[u] = ++t;
}

void dfs_init()
{
    for(int i=0; i<n; i++)
    {
        Colors[i] = WHITE;
    }

    for(int i=0; i<n; i++)
    {
        if(Colors[i] == WHITE)
        {
            dfs(i);
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

    dfs_init();

    for(int i=0; i<n; i++)
    {
        cout << i+1 << " " << d[i] << " " << f[i] << endl;
    }

    return 0;
}