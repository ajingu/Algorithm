#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct Node
{
    int key;
    Node *parent, *left, *right;
};

Node *root = nullptr;

void insert(Node *z)
{
    Node *y = nullptr;
    Node *x = root;

    while(x != nullptr)
    {
        y = x;
        if(z->key < x->key)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }

    z->parent = y;

    if(y == nullptr)
    {
        root = z;
    }
    else if(z->key < y->key)
    {
        y->left = z;
    }
    else
    {
        y->right = z;
    }
}

Node* find(int k)
{
    Node *x = root;

    while(x != nullptr && k != x->key)
    {
        if(k < x->key)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }
    return x;
}

Node* getSuccessor(Node *z)
{
    Node *n = z->right;

    while(n->left != nullptr)
    {
        n = n->left;
    }
    return n;
}

void deleteNode(Node *z)
{
    Node *x, *y;

    //define y(to be deleted)
    if(z->left == nullptr || z->right == nullptr)
    {
        y = z;
    }
    else
    {
        y = getSuccessor(z);
    }

    //define x & change x's parent
    if(y->left != nullptr)
    {
        x = y->left;
    }
    else
    {
        x = y->right;
    }

    if(x != nullptr)
    {
        x->parent = y->parent;
    }

    //change child of y's parent
    if(y->parent == nullptr)
    {
        root = x;
    }
    else if(y == y->parent->left)
    {
        y->parent->left = x;
    }
    else
    {
        y->parent->right = x;
    }

    //change z key in case of 3
    if(y != z)
    {
        z->key = y->key;
    }

}

void printPreorder(Node *u)
{
    if(u == nullptr) return;

    cout << " " << u->key;
    printPreorder(u->left);
    printPreorder(u->right);
}

void printInorder(Node *u)
{
    if(u == nullptr) return;

    printInorder(u->left);
    cout << " " << u->key;
    printInorder(u->right);
}

void print()
{
    printInorder(root);
    cout << endl;
    printPreorder(root);
    cout << endl;
}

int main()
{
    int n, k;
    Node* node;
    string s;

    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> s;
        
        Node *z = new Node;
        z->key = 0;
        z->parent = nullptr;
        z->left = nullptr;
        z->right = nullptr;

        switch(s[0])
        {
            case 'i':
                cin >> z->key;
                insert(z);
                break;

            case 'f':
                cin >> k;
                if(find(k) == nullptr)
                {
                    cout << "no" << endl;
                }
                else
                {
                    cout << "yes" << endl;
                }
                break;

            case 'd':
                cin >> k;
                node = find(k);
                if(node != nullptr) deleteNode(node);
                break;

            case 'p':
                print();
                break;
        }
    }

    return 0;
}