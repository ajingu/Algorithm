#include <iostream>
using namespace std;

int main()
{
    int n, u, k, e;
    cin >> n;

    int M[n][n];
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
            cin >> e;
            M[u-1][e-1] = 1;
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(j > 0) cout << " ";
            cout << M[i][j];
        }

        cout << endl;
    }

    return 0;
}