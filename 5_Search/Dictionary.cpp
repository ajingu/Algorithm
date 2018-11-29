#include <iostream>
#include <cstring>
#include <cmath>
#define M 1000003
using namespace std;

long T[M];

int h1(long key)
{
    return key % M;
}

int h2(long key)
{
    return 1 + (key % (M-1));
}

int h(long key, int i)
{
    return (h1(key) + i*h2(key)) % M;
}

int insert(long T[], long key)
{
    for(int i=0; i<M; i++)
    {
        int j = h(key, i);
        if(T[j] == -1)
        {
            T[j] = key;
            return j;
        }
    }

    return -1;
}

int search(long T[], long key)
{
    for(int i=0; i<M; i++)
    {
        int j = h(key, i);
        if(T[j] == key)
        {
            return j;
        }
        else if(T[j] == -1 or i >= M)
        {
            return -1;
        }
    }
    return -1;
}

int charToInt(char ch)
{
    switch(ch)
    {
        case 'A':
            return 1;
        case 'C':
            return 2;
        case 'G':
            return 3;
        case 'T':
            return 4;
        default:
            return 0;
    }
}

long getKey(char str[])
{
    long sum = 0;
    for(int i=0; i<strlen(str); i++)
    {
        sum += pow(5, i) * charToInt(str[i]);
    }
    return sum;
}

int main()
{
    int n;
    char command[100], str[12];

    for(int i=0; i<M; i++)
    {
        T[i] = -1;
    }

    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> command >> str;
        long key = getKey(str);
        if(command[0] == 'i')
        {
            insert(T, key);
        }
        else
        {
            if(search(T, key) > -1)
            {
                cout << "yes" << endl;
            }
            else
            {
                cout << "no" << endl;
            }
        }
    }

    return 0;
}