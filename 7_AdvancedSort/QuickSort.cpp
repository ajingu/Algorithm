#include <iostream>
#define INFINITY 1000000001
using namespace std;

struct Card { char mark; int number; };

void merge(Card C[], int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    Card L[n1+1], R[n2+1];

    for(int i=0; i<n1; i++)
    {
        L[i] = C[left + i];
    }
    for(int i=0; i<n2; i++)
    {
        R[i] = C[mid + i];
    }
    L[n1].number = INFINITY;
    R[n2].number = INFINITY;

    int i = 0;
    int j = 0;
    for(int k=left; k<right; k++)
    {
        if(L[i].number <= R[j].number)
        {
            C[k] = L[i];
            i++;
        }
        else
        {
            C[k] = R[j];
            j++;
        }
    }
}

void mergeSort(Card C[], int left, int right)
{
    if(left+1 < right)
    {
        int mid = (left + right) / 2;
        mergeSort(C, left, mid);
        mergeSort(C, mid, right);
        merge(C, left, mid, right);
    }
}

int partition(Card C[], int p, int r)
{
    int x = C[r].number;
    int i = p-1;
    for(int j=p; j<r; j++)
    {
        if(C[j].number <= x)
        {
            i++;
            swap(C[i], C[j]);
        }
    }
    swap(C[i+1], C[r]);
    return i+1;
}

void quickSort(Card C[], int p, int r)
{
    if(p < r)
    {
        int q = partition(C, p, r);
        quickSort(C, p, q-1);
        quickSort(C, q+1, r);
    }
}

bool isStable(Card C1[], Card C2[], int n)
{
    for(int i=0; i<n; i++)
    {
        if(C1[i].mark != C2[i].mark)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int n;
    Card C1[100000], C2[100000];

    cin >> n;
    for(int i=0; i<n; i++) { cin >> C1[i].mark >> C1[i].number; }
    for(int i=0; i<n; i++) { C2[i] = C1[i]; }

    quickSort(C1, 0, n-1);
    mergeSort(C2, 0, n);

    if(isStable(C1, C2, n))
    {
        cout << "Stable" << endl;
    }
    else
    {
        cout << "Not stable" << endl;
    }

    for(int i=0; i<n; i++) { cout << C1[i].mark << " " << C1[i].number << endl; }

    return 0;
}