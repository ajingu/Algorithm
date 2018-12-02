#include <iostream>
using namespace std;

struct Card { char suit, value; };

bool isStable(Card C1[], Card C2[], int N)
{
    for(int i=0; i<N; i++)
    {
        if(C1[i].suit != C2[i].suit) return false;
    }
    return true;
}

void trace(Card A[], int N)
{
    int i;
    for(i=0; i<N; i++)
    {
        if(i>0) cout << " ";
        cout << A[i].suit << A[i].value;
    }
    cout << endl;
}

void bubbleSort(Card A[], int N)
{
    int i, j;
    bool flag = 1;
    i = 0;
    
    while(flag)
    {
        flag = 0;
        for (j=N-1; j>i; j--)
        {
            if(A[j].value < A[j-1].value)
            {
                swap(A[j], A[j-1]);
                flag = 1;
            }
        }
        i++;
    }
}

void selectionSort(Card A[], int N)
{
    int minj;

    for(int i=0; i<N; i++)
    {
        minj = i;
        for(int j=i; j<N; j++)
        {
            if(A[j].value < A[minj].value)
            {
                minj = j;
            }
        }
        swap(A[i], A[minj]);
    }
}

int main()
{
    int N;
    Card C1[100], C2[100];

    cin >> N;
    for(int i=0; i<N; i++) cin >> C1[i].suit >> C1[i].value;
    for(int i=0; i<N; i++) C2[i] = C1[i];

    bubbleSort(C1, N);
    selectionSort(C2, N);

    bool flag = isStable(C1, C2, N);

    trace(C1, N);
    cout << "Stable" << endl;
    trace(C2, N);
    if(flag)
    {
        cout << "Stable" << endl;
    }
    else
    {
        cout << "Not stable" << endl;
    }

    return 0;
}