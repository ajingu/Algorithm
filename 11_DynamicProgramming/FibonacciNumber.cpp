#include <iostream>
#define MAX 50
using namespace std;

int F[MAX];

void makeFibonacci(int n)
{
    F[0] = 1;
    F[1] = 1;
    for(int i=2; i<n+1; i++)
    {
        F[i] = F[i-1] + F[i-2];
    }
}

int main()
{
    int n;
    cin >> n;

    makeFibonacci(n);

    cout << F[n] << endl;

    return 0;
}