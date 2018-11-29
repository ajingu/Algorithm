#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct Point{ double x, y; };

double theta = M_PI * 60.0 / 180.0;

void print(Point p)
{
    cout << fixed << setprecision(8);
    cout << p.x << " " << p.y << endl;
}

void koch(int d, Point p1, Point p2)
{
    if(d == 0) return;

    Point s, u, t;

    s.x = (2.0*p1.x + 1.0*p2.x) / 3.0;
    s.y = (2.0*p1.y + 1.0*p2.y) / 3.0;
    t.x = (1.0*p1.x + 2.0*p2.x) / 3.0;
    t.y = (1.0*p1.y + 2.0*p2.y) / 3.0;
    u.x = (t.x - s.x)*cos(theta) - (t.y - s.y)*sin(theta) + s.x;
    u.y = (t.x - s.x)*sin(theta) + (t.y - s.y)*cos(theta) + s.y;
    
    koch(d-1, p1, s);
    print(s);
    koch(d-1, s, u);
    print(u);
    koch(d-1, u, t);
    print(t);
    koch(d-1, t, p2);
}

int main()
{
    int n;
    Point p1, p2;
    p1.x = 0.0;
    p1.y = 0.0;
    p2.x = 100.0;
    p2.y = 0.0;

    cin >> n;

    print(p1);
    koch(n, p1, p2);
    print(p2);

    return 0;
}