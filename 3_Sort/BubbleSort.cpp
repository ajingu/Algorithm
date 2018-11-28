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

int bubbleSort(int A[], int N)
{
    int i, j, count;
    bool flag = 1;
    i = 0;
    count = 0;
    
    while(flag)
    {
        flag = 0;
        for (j=N-1; j>i; j--)
        {
            if(A[j] < A[j-1])
            {
                swap(A[j], A[j-1]);
                flag = 1;
                count++;
            }
        }
        i++;
    }

    return count;
}

int main()
{
    int N;
    int A[100];

    cin >> N;
    for(int i=0; i<N; i++) cin >> A[i];
    
    int count = bubbleSort(A, N);
    trace(A, N);
    cout << count << endl;

    return 0;
}