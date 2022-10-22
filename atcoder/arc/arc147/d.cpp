#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define LL long long

int n, m;
int main()
{
  cin >> n >> m;
  mint ret = 1;
  REP(i, m)
  ret *= n;
  REP(i, n - 1)
  ret *= m;
  cout << ret.val() << endl;
}