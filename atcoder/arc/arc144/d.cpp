#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define LL long long

LL n, k;
int main()
{
  cin >> n >> k;
  mint ret = 0;
  ret += 1 + k;
  mint fst = 1, snd = 1, pow2 = 1;
  REP(i, n)
  {
    fst *= (k - i);
    fst /= (i + 1);
    snd *= (n - i);
    snd /= (i + 1);
    pow2 *= 2;
    ret += fst * snd * pow2 * (k + 1);
    mint tmp = fst;
    tmp *= (k + 1);
    tmp /= (i + 2);
    ret -= tmp * snd * pow2 * (i + 1);
  }
  cout << ret.val() << endl;
}