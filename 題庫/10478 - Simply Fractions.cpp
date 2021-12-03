#include <iostream>
using namespace std;

unsigned long long gcd(unsigned long long a, unsigned long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    while (cin >> t)
    {
        unsigned long long p = 0; // p/q
        unsigned long long q = 1;
        unsigned long long np = 0;
        unsigned long long nq = 1;
        unsigned long long r;
        while (t--)
        {
            cin >> np >> nq;
            r = gcd(np, nq);
            np /= r;
            nq /= r;

            p = p * nq + q * np;
            q = q * nq;
            r = gcd(p, q);
            p /= r;
            q /= r;
        }
        cout << p << "/" << q << endl;
    }
}
