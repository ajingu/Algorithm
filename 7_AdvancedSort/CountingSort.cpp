#include <iostream>
using namespace std;

void countingSort(int A[], int B[], int k, int n)
{
    int C[k+1];

    for(int i=0; i<k+1; i++)
    {
        C[i] = 0;
    }

    for(int j=1; j<n+1; j++)
    {
        C[A[j]]++;
    }

    for(int i=1; i<k+1; i++)
    {
        C[i]+=C[i-1];
    }

    for(int j=n; j>0; j--)
    {
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }
}

int main()
{
    int n;
    int *A, *B;

    cin >> n;

    A = new int[n+1];
    B = new int[n+1];
    
    for(int i=1; i<n+1; i++){ cin >> A[i]; }

    countingSort(A, B, 10000, n);

    for(int j=1; j<n+1; j++)
    { 
        if(j > 1) cout << " ";
        cout << B[j];
    }

    cout << endl;

    return 0;
}