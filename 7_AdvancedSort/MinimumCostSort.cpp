#include <iostream>
#include <algorithm>
using namespace std;

int sum = 0;

void minimumCostSort(int A[], int n)
{
    
}

int main()
{
    int n, A[1000];

    cin >> n;
    for(int i=0; i<n; i++) { cin >> A[i]; }

    minimumCostSort(A, n);

    cout << sum << endl;

    return 0;
}