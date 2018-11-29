#include <iostream>
using namespace std;

int n, A[20];

bool solve(int i, int m)
{
    if(m == 0) return true;
    if(i >= n) return false;

    bool res = solve(i+1, m) || solve(i+1, m-A[i]);

    return res;
}

int main()
{
    int q, m;

    cin >> n;
    for(int i=0; i<n; i++) { cin >> A[i]; }
    cin >> q;
    for(int i=0; i<q; i++)
    {
        cin >> m;
        bool b = solve(0, m);
        if(b)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }

    return 0;
}