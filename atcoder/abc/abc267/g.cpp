#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define LL long long

int n, k;
vector<int> a;
mint dp[5001][5001];
int main()
{
  cin >> n >> k;
  a.resize(n);
  REP(i, n)
  cin >> a[i];
  sort(ALL(a));
  dp[0][0] = 1;
  FOR(i, 1, n + 1)
  {
    int lows = lower_bound(ALL(a), a[i - 1]) - a.begin();
    REP(j, k + 1)
    {
      if (j)
        dp[i][j] = dp[i - 1][j] * (i - (lows - j)) + dp[i - 1][j - 1] * (lows - j + 1);
      else
        dp[i][j] = dp[i - 1][j] * (i - (lows - j));
    }
  }
  cout << dp[n][k].val() << endl;
}