#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 10000
#define INFTY 1 << 30
#define WHITE 0
#define GRAY 1
#define BLACK 2
using namespace std;

int n;
int Colors[MAX];
int d[MAX];
priority_queue<pair<int, int> > PQ;
vector<pair<int, int> > AdjList[MAX];

void dijkstra()
{
    for(int i=0; i<n; i++)
    {
        Colors[i] = WHITE;
        d[i] = INFTY;
    }

    d[0] = 0;
    PQ.push(make_pair(0, 0));
    Colors[0] = GRAY;

    while(!PQ.empty())
    {
        pair<int, int> f = PQ.top(); PQ.pop();

        int u = f.second;
        Colors[u] = BLACK;

        if(d[u] < -f.first) continue;

        for(int i=0; i<AdjList[u].size(); i++)
        {
            int v = AdjList[u][i].first;
            if(Colors[v] == BLACK) continue;
            if(d[u] + AdjList[u][i].second < d[v])
            {
                d[v] = d[u] + AdjList[u][i].second;
                Colors[v] = GRAY;
                PQ.push(make_pair(-d[v], v));
            }
        }
    }
}

int main()
{
    cin >> n;

    int u, k, v, c;
    for(int i=0; i<n; i++)
    {
        cin >> u >> k;
        for(int j=0; j<k; j++)
        {
            cin >> v >> c;
            AdjList[u].push_back(make_pair(v, c));
        }
    }

    dijkstra();

    for(int i=0; i<n; i++)
    {
        cout << i << " " << d[i] << endl;
    }

    return 0;
}