#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define LL long long

LL n, m, q;
LL a, b, c, d;

mint row(LL i, LL begin, LL end)
{
  if (begin > end)
    return 0;
  mint num = (end - begin) / 2 + 1;
  mint summand = (i - 1);
  summand *= m;
  summand *= num;
  return summand + (end + begin) * num / 2;
}
mint column(LL j, LL begin, LL end)
{
  if (begin > end)
    return 0;
  mint num = (end - begin) / 2 + 1;
  mint summand = j;
  summand *= num;
  mint summand2 = m;
  summand2 *= 2;
  summand2 *= (1 + num) / 2;
  return summand + summand2;
}

int main()
{
  cin >> n >> m >> q;
  REP(i, q)
  {
    cin >> a >> b >> c >> d;
    mint ret = 0;
    if (a % 2)
    {
      LL c_ = c;
      if (!(c_ % 2))
        c_++;
      LL d_ = d;
      if (!(d_ % 2))
        d_--;
      ret += row(a, c_, d_);
      a++;
    }
    if (!(b % 2))
    {
      LL c_ = c;
      if ((c_ % 2))
        c_++;
      LL d_ = d;
      if ((d_ % 2))
        d_--;
      ret += row(b, c_, d_);
      b--;
    }
    if ((c % 2))
    {
      ret += column(c, a + 1, b);
      c++;
    }
    if (!(d % 2))
    {
      ret += column(d, a + 1, b);
      d--;
    }
    mint summand = (b + a);
    summand *= (b - a + 1);
    summand /= 2;
    summand *= (d - c + 1) / 2;
    mint summand2 = (d + c);
    summand2 *= (d - c + 1);
    summand2 /= 2;
    summand2 *= (b - a + 1) / 2;
    ret += summand + summand2;
    cout << ret.val() << endl;
  }
}