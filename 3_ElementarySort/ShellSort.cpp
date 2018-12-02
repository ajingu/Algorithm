#include <iostream>
#include <vector>
using namespace std;

long cnt = 0;
int m;
vector<int> G;

void insertionSort(int A[], int n, int g)
{
    for(int i=g; i<n; i++)
    {
        int v = A[i];
        int j = i - g;
        while(j>=0 && A[j] > v)
        {
            A[j+g] = A[j];
            j = j - g;
            cnt++;
        }
        A[j+g] = v;
    }
}

void shellSort(int A[], int n)
{
    int j = 1;

    while(j <= n)
    {
        G.push_back(j);
        j = 3 * j + 1;
    }

    m = G.size();

    for(int i=m-1; i>=0; i--)
    {
        insertionSort(A, n, G[i]);
    }
}

int main()
{
    int n, A[1000000];

    cin >> n;
    for(int i=0; i<n; i++) cin >> A[i];

    shellSort(A, n);

    cout << m << endl;

    for(int i=m-1; i>=0; i--)
    {
        if(i<m-1) cout << " ";
        cout << G[i];
    }
    cout << endl;

    cout << cnt << endl;

    for(int i=0; i<n; i++)
    {
        cout << A[i] << endl;
    }

    return 0;
}