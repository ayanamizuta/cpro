#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define LL long long

int n;
int a[200001];
mint val[200001], su[200001];
int main()
{
  cin >> n;
  REP(i, n - 1)
  cin >> a[i + 1];
  val[n - 1] = 2;
  su[n - 1] = val[n - 1];
  FOR(i, 2, n)
  {
    val[n - i] = ((su[n - i + 1] - su[n - i + 1 + a[n - i]] + a[n - i] + 1) / mint(a[n - i]));
    su[n - i] = su[n - i + 1] + val[n - i];
  }
  cout << val[1].val() << endl;
}