#include "bits/stdc++.h"
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define LL long long

int TRIAL = 30;

long pow(long b, long e, long mod)
{
    long b_ = b % mod;
    long ret = 1;
    while (e)
    {
        if (e & 1)
        {
            ret *= b_;
            ret %= mod;
        }
        b_ *= b_;
        b_ %= mod;
        e /= 2;
    }
    return ret;
}

string solve(long n)
{
    if (n == 1)
        return "No";
    if (n == 2)
        return "Yes";
    REP(i, TRIAL)
    {
        long b = rand() % (n - 2) + 2;
        if (pow(b, n - 1, n) != 1)
        {
            return "No";
        }
    }
    return "Yes";
}

int main()
{
    srand(42);
    int q;
    cin >> q;
    REP(i, q)
    {
        long n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}
