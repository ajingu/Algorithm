#include <iostream>
#define MAX 2000000000;
using namespace std;

int main()
{
    int n;
    cin >> n;

    int m[n+1][n+1];
    int p[n+1];

    for(int i=1; i<n+1; i++)
    {
        cin >> p[i-1] >> p[i];
    }

    for(int i=1; i<n+1; i++)
    {
        m[i][i] = 0;
    }

    for(int l=2; l<n+1; l++) //l: かけ算をする行列の数
    {
        for(int i=1; i<n-l+2; i++) // i = 1...n-l+1
        {
            int j = i + l - 1; //j-i+1 = l
            m[i][j] = MAX;
            for(int k=i; k<j; k++)
            {
                m[i][j] = min(m[i][j], m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]);
            }
        }
    }

    cout << m[1][n] << endl;

    return 0;
}