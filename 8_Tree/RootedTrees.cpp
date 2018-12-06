#include <iostream>
#define MAX 100001
using namespace std;

struct Node { int parent, left, right; };
struct Node T[MAX];
int D[MAX];

void setDepth(int u, int p)
{
    D[u] = p;

    if(T[u].right != -1)
    {
        setDepth(T[u].right, p);
    }
    
    if(T[u].left != -1)
    {
        setDepth(T[u].left, p+1);
    }
}

void printChildren(int u)
{
    int c = T[u].left;
    int i = 0;
    while(c != -1)
    {
        if(i > 0)
        {
            cout << ", ";
        }
        cout << c;
        c = T[c].right;

        i++;
    }
}

int main()
{
    int n, id, k, curC, root;
    cin >> n;

    //initialization
    for(int i=0; i<n; i++)
    {
        T[i].parent = -1;
        T[i].left = -1;
        T[i].right = -1;
    }

    for(int i=0; i<n; i++)
    {
        int lastC = -1;

        cin >> id >> k;

        for(int j=0; j<k; j++)
        {
            cin >> curC;

            //left
            if(j == 0)
            {
                T[id].left = curC;
            }

            //parent
            T[curC].parent = id;

            //right
            if(lastC > -1)
            {
                T[lastC].right = curC;
            }
            lastC = curC;
        }
    }

    for(int i=0; i<n; i++)
    {
        if(T[i].parent == -1)
        {
            root = i;
            break;
        }
    }
    setDepth(root, 0);

    for(int i=0; i<n; i++)
    {
        cout << "node " << i << ": parent = " << T[i].parent;
        cout << ", depth = " << D[i] << ", ";

        if(T[i].parent == -1)
        {
            cout << "root";
        }
        else if(T[i].left == -1)
        {
            cout << "leaf";
        }
        else
        {
            cout << "internal node";
        }

        cout << ", [";
        printChildren(i);
        cout << "]" << endl;
    }

    return 0;
}