#include <iostream>
#define MAX 500001
using namespace std;

int n;
int keys[MAX];

void maxHeapify(int A[], int i)
{
    int largest;
    int l = i * 2;
    int r = l + 1;

    if(l <= n && A[l] > A[i])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }
    
    if(r <= n && A[r] > A[largest])
    {
        largest = r;
    }

    if(largest != i)
    {
        swap(A[largest], A[i]);
        maxHeapify(A, largest);
    }
}

void buildMaxHeap(int A[])
{
    for(int i=n/2; i>0; i--)
    {
        maxHeapify(A, i);
    }
}


int main()
{
    cin >> n;
    for(int i=1; i<n+1; i++)
    {
        cin >> keys[i];
    }

    buildMaxHeap(keys);

    for(int i=1; i<n+1;i++)
    {
        cout << " " << keys[i];
    }

    cout << endl;

    return 0;
}