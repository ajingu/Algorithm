#include <iostream>
using namespace std;

struct Process { char name[100]; int time; };

int head = 0;
int tail = 0;
Process Q[100000];
const int MAX = 100000;

bool isEmpty()
{
    return head == tail;
}

void enqueue(Process x)
{
    Q[tail] = x;
    if(tail+1 == MAX)
    {
        tail = 0;
    }
    else
    {
        tail++;
    }
}

Process dequeue()
{
    Process x = Q[head];
    if(head+1 == MAX)
    {
        head = 0;
    }
    else
    {
        head++;
    }

    return x;
}

void RoundRobin(int quantum)
{
    int time = 0;

    while(!isEmpty())
    {
        Process p = dequeue();
        if(p.time <= quantum)
        {
            time += p.time;
            p.time = 0;
            cout << p.name << " " << time << endl;
        }
        else
        {
            time += quantum;
            p.time -= quantum;
            enqueue(p);
        }
    }
}

int main()
{
    int n, q;

    cin >> n >> q;
    for(int i=0; i<n; i++) { cin >> Q[i].name >> Q[i].time; }
    tail = n;

    RoundRobin(q);

    return 0;
}