#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> pre, in;
int cnt = 0;

vector<int>::iterator pre_it;

void reconstruction(int l_idx, int r_idx)
{
    if(l_idx >= r_idx) return;

    int c = *pre_it++;

    vector<int>::iterator in_it = find(in.begin(), in.end(), c);
    if(in_it == in.end()) return;
    int m_idx = distance(in.begin(), in_it);

    reconstruction(l_idx, m_idx);
    reconstruction(m_idx + 1, r_idx);

    if(cnt > 0) cout << " ";
    cout <<  c;

    cnt++;
}

int main()
{
    int n, e;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> e;
        pre.push_back(e);
    }

    for(int i=0; i<n; i++)
    {
        cin >> e;
        in.push_back(e);
    }

    pre_it = pre.begin();

    reconstruction(0, n);

    cout << endl;

    return 0;
}