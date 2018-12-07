#include <iostream>
#include <string>
using namespace std;

int lcs(string x, string y)
{
    int m = x.length();
    int n = y.length();
    int c[m+1][n+1];

    for(int i=0; i<m+1; i++)
    {
        c[i][0] = 0;
    }

    for(int j=1; j<n+1; j++)
    {
        c[0][j] = 0;
    }

    for(int i=1; i<m+1; i++)
    {
        for(int j=1; j<n+1; j++)
        {
            if(x[i-1] == y[j-1])
            {
                c[i][j] = c[i-1][j-1] + 1;
            }
            else
            {
                c[i][j] = max(c[i][j-1], c[i-1][j]);
            }
        }
    }

    return c[m][n];
}

int main()
{
    int n;
    string x, y;

    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> x;
        cin >> y;
        cout << lcs(x, y) << endl;
    }

    return 0;
}