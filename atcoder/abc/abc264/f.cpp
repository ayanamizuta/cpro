#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define LL long long
int h, w;
LL r[2000], c[2000];
int a[2000][2000];
LL dp[2001][2001][4];
int main()
{
  cin >> h >> w;
  REP(i, h)
  cin >> r[i];
  REP(i, w)
  cin >> c[i];
  REP(i, h)
  {
    string s;
    cin >> s;
    REP(j, w)
    {
      a[i][j] = (int)s[j] - (int)'0';
    }
  }
  dp[0][0][0] = 0;
  dp[0][0][1] = c[0];
  dp[0][0][2] = r[0];
  dp[0][0][3] = r[0] + c[0];
  REP(i, h)
  {
    REP(j, w)
    {
      if (i == 0 && j == 0)
        continue;
      REP(k, 4)
      dp[i][j][k] = 100000000000000;
      if (i > 0)
      {
        if (a[i - 1][j] == a[i][j])
        {
          dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][0]);
          dp[i][j][2] = min(dp[i][j][2], dp[i - 1][j][2] + r[i]);
          dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j][1]);
          dp[i][j][3] = min(dp[i][j][3], dp[i - 1][j][3] + r[i]);
        }
        else
        {
          dp[i][j][2] = min(dp[i][j][2], dp[i - 1][j][0] + r[i]);
          dp[i][j][3] = min(dp[i][j][3], dp[i - 1][j][1] + r[i]);
          dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][2]);
          dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j][3]);
        }
      }
      if (j > 0)
      {
        if (a[i][j - 1] == a[i][j])
        {
          dp[i][j][0] = min(dp[i][j][0], dp[i][j - 1][0]);
          dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][1] + c[j]);
          dp[i][j][2] = min(dp[i][j][2], dp[i][j - 1][2]);
          dp[i][j][3] = min(dp[i][j][3], dp[i][j - 1][3] + c[j]);
        }
        else
        {
          dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][0] + c[j]);
          dp[i][j][3] = min(dp[i][j][3], dp[i][j - 1][2] + c[j]);
          dp[i][j][0] = min(dp[i][j][0], dp[i][j - 1][1]);
          dp[i][j][2] = min(dp[i][j][2], dp[i][j - 1][3]);
        }
      }
    }
  }
  LL ret = dp[h - 1][w - 1][0];
  ret = min(ret, dp[h - 1][w - 1][1]);
  ret = min(ret, dp[h - 1][w - 1][2]);
  ret = min(ret, dp[h - 1][w - 1][3]);
  cout << ret << endl;
}