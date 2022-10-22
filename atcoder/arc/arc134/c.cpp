#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define LL long long

int n, k;
LL a[100000];

mint comb(LL m)
{
  mint ret = 1,div=1;
  FOR(i, m + 1, m + k)
  ret *= mint(i);
  FOR(i, 1, k)
  div *= mint(i);
  return ret/div;
}

int main()
{
  cin >> n >> k;
  REP(i, n)
  cin >> a[i];
  LL su = 0;
  FOR(i, 1, n)
  su += a[i];
  LL m = a[0] - (su + k);
  if (m < 0)
  {
    cout << 0 << endl;
    return 0;
  }
  mint ret = mint(1);
  ret *= comb(m);
  FOR(i, 1, n)
  ret *= comb(a[i]);
  cout << ret.val() << endl;
  return 0;
}