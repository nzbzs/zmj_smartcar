#include"v.h"
using namespace std;

void ceshi() {
    Vector a(1, 1.5);
    Vector b(2, 2.5);
    a.print();
    b.print();

    b.add(a);
    b.dir_print();
}
int main()
{
 
    //ceshi();
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    Vector q(a, b);
    Vector p(c, d);

    q.add(p);
    cout << q.dir();

    return 0;
}