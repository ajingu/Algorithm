#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Node
{
    int key;
    Node *prev, *next;
};

Node *nil;

void init()
{
    nil = (Node *)malloc(sizeof(Node));
    nil -> next = nil;
    nil -> prev = nil;
}

void insert(int key)
{
    Node *x = (Node *)malloc(sizeof(Node));
    x -> key = key;
    x -> next = nil -> next;
    nil -> next -> prev = x;
    nil -> next = x;
    x -> prev = nil;
}

Node* listSearch(int key)
{
    Node *cur = nil -> next;
    while(cur!=nil && cur->key!=key)
    {
        cur = cur -> next;
    }
    return cur;
}

void deleteNode(Node *t)
{
    if (t == nil) return;
    t -> prev -> next = t -> next;
    t -> next -> prev = t -> prev;
    free(t);
}

void deleteFirst()
{
    deleteNode(nil -> next);
}

void deleteLast()
{
    deleteNode(nil -> prev);
}

void deleteKey(int key)
{
    deleteNode(listSearch(key));
}

int main()
{
    init();

    int n, x;
    char ch[100];

    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%s", ch);

        switch(ch[0])
        {
            case 'i':
                scanf("%d", &x);
                insert(x);
                break;

            case 'd':
                if(strlen(ch) == 6)
                {
                    scanf("%d", &x);
                    deleteKey(x);
                }
                else if(ch[6] == 'F')
                {
                    deleteFirst();
                }
                else
                {
                    deleteLast();
                }
                break;
        }
    }

    Node *cur = nil -> next;
    while(cur != nil)
    {
        printf("%d", cur -> key);
        cur = cur -> next;
        if(cur != nil)
        {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}