#include <iostream>
#define MAX 26
using namespace std;

struct Node 
{
    int parent, left, right;
};

Node T[MAX];

void printPreorder(int u)
{
    if(u == -1) return;

    cout << " " << u;
    printPreorder(T[u].left);
    printPreorder(T[u].right);
}

void printInorder(int u)
{
    if(u == -1) return;

    printInorder(T[u].left);
    cout << " " << u;
    printInorder(T[u].right);
}

void printPostorder(int u)
{
    if(u == -1) return;

    printPostorder(T[u].left);
    printPostorder(T[u].right);
    cout << " " << u;
}

void print(int root)
{
    cout << "Preorder" << endl;
    printPreorder(root);
    cout << endl;
    cout << "Inorder" << endl;
    printInorder(root);
    cout << endl;
    cout << "Postorder" << endl;
    printPostorder(root);
    cout << endl;
}

int main()
{
    int n, id, root;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> id;
        cin >> T[id].left >> T[id].right;
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

    print(root);

    return 0;
}