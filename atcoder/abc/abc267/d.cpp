#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define LL long long

int n, m;
LL dp[2001][2001];
LL a[2000];
int main()
{
  cin >> n >> m;
  REP(i, n)
  cin >> a[i];

  REP(i, 2001)
  {
    REP(j, 2001)
    {
      dp[i][j] = -10000000000000;
    }
  }
  REP(i, 2001)
  dp[i][0] = 0;
  FOR(i, 1, n + 1)
  {
    FOR(j, 1, m + 1)
    {
      if (i >= j)
        dp[i][j] = max(dp[i - 1][j - 1] + (LL)j * a[i - 1], dp[i - 1][j]);
    }
  }
  cout << dp[n][m] << endl;
}