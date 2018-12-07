#include <iostream>
#include <string>
#define MAX 2000001
using namespace std;

int n = 0;
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

void heapIncreaseKey(int key)
{
    int i = n;
    keys[i] = key;
    while(i > 1 && keys[i/2] < keys[i])
    {
        swap(keys[i], keys[i/2]);
        i = i/2;
    }
}

void insert(int key)
{
    n++;
    heapIncreaseKey(key);
}

int heapExtractMax()
{
    int max = keys[1];
    //cout << "max: " << max << endl;
    keys[1] = keys[n];
    n--;
    maxHeapify(keys, 1);

    return max;
}

int main()
{
    int key;
    string s;

    while(true)
    {
        cin >> s;
        if(s == "insert")
        {
            cin >> key;
            insert(key);
        }
        else if(s == "extract")
        {
            cout << heapExtractMax() << endl;
        }
        else
        {
            break;
        }
    }

    return 0;
}