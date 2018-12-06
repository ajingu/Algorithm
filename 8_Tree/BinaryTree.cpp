#include <iostream>
#define MAX 26
using namespace std;

struct Node
{
    int parent, left, right;
};

int D[MAX];
int H[MAX];
Node T[MAX];

void setDepth(int u, int p)
{
    D[u] = p;

    if(T[u].right != -1)
    {
        setDepth(T[u].right, p+1);
    }
    
    if(T[u].left != -1)
    {
        setDepth(T[u].left, p+1);
    }
}

int setHeight(int u)
{
    int h1 = 0;
    int h2 = 0;

    if(T[u].right != -1)
    {
        h1 = setHeight(T[u].right) + 1;
    }

    if(T[u].left != -1)
    {
        h2 = setHeight(T[u].left) + 1;
    }
    
    return H[u] = max(h1, h2);
}

int getDegree(int u)
{
    int d1 = T[u].left == -1 ? 0 : 1;
    int d2 = T[u].right == -1 ? 0 : 1;
    return d1 + d2;
}

int getSibling(int u)
{
    int p = T[u].parent;
    if(p == -1) return -1;

    int l = T[p].left;
    if(l != -1 && l != u)
    {
        return l;
    }

    int r = T[p].right;
    if(r != -1 && r != u)
    {
        return r;
    }

    return -1;
}

int main()
{
    int n, id, root;

    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> id;
        cin >> T[id].left >> T[id].right;
    }

    for(int i=0; i<n; i++)
    {
        T[i].parent = -1;
    }

    for(int i=0; i<n; i++)
    {
        int l = T[i].left;
        if(l != -1)
        {
            T[l].parent = i;
        }

        int r = T[i].right;
        if(r != -1)
        {
            T[r].parent = i;
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
    setHeight(root);

    for(int i=0; i<n; i++)
    {
        cout << "node " << i << ": parent = " << T[i].parent;
        cout << ", sibling = " << getSibling(i);
        cout << ", degree = " << getDegree(i);
        cout << ", depth = " << D[i];
        cout << ", height = " << H[i] << ", ";

        if(T[i].parent == -1)
        {
            cout << "root" << endl;
        }
        else if(T[i].left == -1 && T[i].right == -1)
        {
            cout << "leaf" << endl;
        }
        else
        {
            cout << "internal node" << endl;
        }
        
    }

    return 0;
}