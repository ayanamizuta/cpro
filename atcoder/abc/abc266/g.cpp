#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define LL long long

mint comb(mint a, mint b)
{
  mint ret_num = 1, ret_denom = 1;
  REP(i, b.val())
  {
    ret_num *= a - i;
    ret_denom *= 1 + i;
  }
  return ret_num / ret_denom;
}

int r, g, b, k;
int main()
{
  cin >> r >> g >> b >> k;
  mint ret = comb(g + b, b) * comb(g, k) * comb(g + b + 1 - (g - k) + r - k - 1, r - k);
  cout << ret.val() << endl;
}