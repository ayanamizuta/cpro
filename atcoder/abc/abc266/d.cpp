#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define LL long long

int n;
int t[100000], x[100000];
LL a[100000];
LL dp[100001][6];
int main()
{
  cin >> n;
  REP(i, n)
  cin >> t[i] >> x[i] >> a[i];
  int cur = 0;
  FOR(i, 1, 100001)
  {
    LL bonus = 0;
    int index = -1;
    if (cur < n && t[cur] == i)
    {
      bonus = a[cur];
      index = x[cur];
      cur++;
    }
    REP(j, 5)
    {
      dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + 1]);
      if (j)
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
      if (index == j && i >= index)
        dp[i][j] += bonus;
    }
  }
  LL ret = 0;
  REP(i, 5)
  ret = max(ret, dp[100000][i]);
  cout << ret << endl;
}