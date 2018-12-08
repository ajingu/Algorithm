#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define MAX 100000
#define WHITE 0
#define GRAY 1
#define BLACK 2
using namespace std;

int n;
int Colors[MAX];
int Groups[MAX];
vector<int> G[MAX];
queue<int> Q;

void bfs(int s)
{
    Colors[s] = GRAY;
    Groups[s] = s;
    Q.push(s);
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for(int i=0; i<G[u].size(); i++)
        {
            int v = G[u][i];
            if(Colors[v] == WHITE)
            {
                Colors[v] = GRAY;
                Groups[v] = s;
                Q.push(v);
            }
        }
        Colors[u] = BLACK;
    }
}

void bfs_init()
{
    for(int i=0; i<n; i++)
    {
        Colors[i] = WHITE;
    }

    for(int i=0; i<n; i++)
    {
        if(Colors[i] == WHITE) bfs(i);
    }
}

int main()
{
    int m;
    cin >> n >> m;

    int u1, u2;
    for(int i=0; i<m; i++)
    {
        cin >> u1 >> u2;
        G[u1].push_back(u2);
        G[u2].push_back(u1);
    }

    bfs_init();

    int q;
    cin >> q;
    for(int i=0; i<q; i++)
    {
        cin >> u1 >> u2;

        string result = Groups[u1] == Groups[u2] ? "yes" : "no";
        cout << result << endl;
    }

    return 0;
}