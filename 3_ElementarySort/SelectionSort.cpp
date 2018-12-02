#include <iostream>
using namespace std;

void trace(int A[], int N)
{
    int i;
    for(i=0; i<N; i++)
    {
        if(i>0) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

int selectionSort(int A[], int N)
{
    int minj;
    int count = 0;

    for(int i=0; i<N; i++)
    {
        minj = i;
        for(int j=i; j<N; j++)
        {
            if(A[j] < A[minj])
            {
                minj = j;
            }
        }
        if(i != minj) count++;
        swap(A[i], A[minj]);
    }

    return count;
}

int main()
{
    int N;
    int A[100];

    cin >> N;
    for(int i=0; i<N; i++) cin >> A[i];
    
    int count = selectionSort(A, N);
    trace(A, N);
    cout << count << endl;

    return 0;
}