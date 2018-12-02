#include <iostream>
using namespace std;

int partition(int A[], int p, int r)
{
    int x = A[r];
    int i = p-1;
    for(int j=p; j<r; j++)
    {
        if(A[j] <= x)
        {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1], A[r]);
    return i+1;
}

int main()
{
    int n, A[100000];

    cin >> n;
    for(int i=0; i<n; i++) { cin >> A[i]; }

    int standard = partition(A, 0, n-1);

    for(int i=0; i<n; i++)
    {
        if(i > 0)
        {
            cout << " ";
        }

        if(i == standard)
        {
            cout << "[" << A[i] << "]";
        }
        else
        {
            cout << A[i];
        }
    }
    cout << endl;

    return 0;
}