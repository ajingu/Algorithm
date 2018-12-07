#include <iostream>
#define MAX 251
using namespace std;

int n;
int keys[MAX];

void print(int i)
{
    cout << "node " << i << ": key = " << keys[i] << ", ";

    int parent = i/2;
    if(0 < parent)
    {
        cout << "parent key = " << keys[parent] << ", ";
    }

    int left = i*2;
    if(left < n+1)
    {
        cout << "left key = " << keys[left] << ", ";
    }

    int right = left + 1;
    if(right < n+1)
    {
        cout << "right key = " << keys[right] << ", ";
    }

    cout << endl;
}

int main()
{
    cin >> n;
    for(int i=1; i<n+1; i++)
    {
        cin >> keys[i];
    }

    for(int i=1; i<n+1; i++)
    {
        print(i);
    }

    return 0;
}