#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define LL long long

#define MOD 1000000007
#define FACT_MAX 20000000

LL fact[FACT_MAX], fact_inv[FACT_MAX];

class Combinatrics
{
private:
    long long mod = MOD;
    int fact_max = FACT_MAX;

public:
    Combinatrics()
    {
        fact[0] = 1;
        for (int i = 1; i < fact_max; i++)
        {
            fact[i] = (fact[i - 1] * i) % mod;
            fact_inv[i] = inv(fact[i]);
        }
    }

    long long power(long long n, long long e)
    {
        long long ret = 1;
        long long b = n;
        while (e)
        {
            if (e % 2 != 0)
                ret *= b;
            ret %= mod;
            b *= b;
            b %= mod;
            e /= 2;
        }
        return ret;
    }

    long long inv(long long n)
    {
        return power(n, mod - 2);
    }

    long long div(long long n1, long long n2)
    {
        return n1 * power(n2, mod - 2) % mod;
    }

    long long nck(int n, int k)
    {
        if (k > n || k < 0)
            return 0LL;
        if (k == n || k == 0)
            return 1LL;
        return (fact[n] * fact_inv[n - k] % mod) * fact_inv[k] % mod;
    }
};

LL n, a, b;

int main()
{
    cin >> n >> a >> b;
    LL e = a - b;
    mint ret;
    Combinatrics cb;
    FOR(d, max(int(e - 1), 0), a + b - 1)
    {
        mint cnt = 0;
        int p = 0;
        if ((d + a + b) % 2 == 0)
        {
            p = (a + b - 2 - d) / 2 + 1;
            cnt += cb.nck(a, p) * cb.nck(b, p) - cb.nck(b - 1, p) * cb.nck(a + 1, p);
            cnt -= cb.nck(a - 1, p) * cb.nck(b, p) - cb.nck(b - 1, p) * cb.nck(a, p);
        }
        else
        {
            if (e == 0)
                continue;
            p = (a + b - 3 - d) / 2 + 1;
            cnt += cb.nck(a - 1, p) * cb.nck(b, p);
            cnt -= cb.nck(b - 1, p) * cb.nck(a, p);
        }
        // cerr << p << " " << d << " " << p << " " << cnt.val() << " " << cb.nck(n - d, a + b) << endl;
        ret += cnt * cb.nck(n - d, a + b);
    }
    cout << ret.val() << endl;
}