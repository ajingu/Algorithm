#include <iostream>
using namespace std;

int linearSearch(int A[], int n, int key)
{
    int i = 0;
    A[n] = key;

    while(A[i] != key)
    {
        i++;
    }

    if(i == n)
    {
        return -1;
    }

    return i;
}

int main()
{
    int n, S[10000], q, t;
    int cnt = 0;

    cin >> n;
    for(int i=0; i<n; i++) { cin >> S[i]; }
    cin >> q;
    for(int i=0; i<q; i++) 
    {
        cin >> t;
        if(linearSearch(S, n, t) > -1) cnt++;
    }

    cout << cnt << endl;

    return 0;
}