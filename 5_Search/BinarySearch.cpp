#include <iostream>
using namespace std;

int binarySearch(int A[], int n, int key)
{
    int left = 0;
    int right = n;
    int mid;

    while(left < right)
    {
        mid = (left + right) / 2;

        if(A[mid] == key)
        {
            return mid;
        }
        else if(key < A[mid])
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    return -1;
}

int main()
{
    int n, S[100000], q, t;
    int cnt = 0;

    cin >> n;
    for(int i=0; i<n; i++) { cin >> S[i]; }
    cin >> q;
    for(int i=0; i<q; i++) 
    {
        cin >> t;
        if(binarySearch(S, n, t) > -1) cnt++;
    }

    cout << cnt << endl;

    return 0;
}