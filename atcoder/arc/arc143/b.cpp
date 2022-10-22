#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define LL long long

using mint = atcoder::modint998244353;

mint nck(int n_, int k)
{
  if (n_ < k)
    return 0;
  mint ret = 1;
  mint md = 1;
  FOR(i, 1, k + 1)
  md *= i;
  FOR(i, n_ - k + 1, n_ + 1)
  ret *= i;
  return ret / md;
}

int n;
int main()
{
  cin >> n;
  if (n == 1)
  {
    cout << 0 << endl;
    return 0;
  }
  mint cnt = 0;
  mint all = 1;
  REP(i, n * n)
  {
    all *= (i + 1);
  }
  FOR(i, 1, n * n + 1)
  {
    cnt += nck(i - 1, n - 1) * nck(n * n - i, n - 1);
  }
  // cerr << cnt.val() << endl;
  FOR(i, 1, n)
  {
    cnt *= i * i;
  }
  cnt *= n * n;
  FOR(i, 1, (n - 1) * (n - 1) + 1)
  {
    cnt *= i;
  }
  // cerr << cnt.val() << endl;
  cout << (all - cnt).val() << endl;
}