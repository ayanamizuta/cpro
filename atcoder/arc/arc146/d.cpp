#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define LL long long

int n, m, k;
int p[200000], q[200000], x[200000], y[200000];
int ans[200000];
vector<int> v;
int main()
{
  cin >> n >> m >> k;
  REP(i, k)
  {
    cin >> p[i] >> x[i] >> q[i] >> y[i];
    p[i]--;
    q[i]--;
    v.push_back(i);
  }
  REP(i, n)
  ans[i] = 1;

  REP(j, 100)
  {
    random_shuffle(ALL(v));
    REP(i_, k)
    {
      int i = v[i_];
      if (ans[p[i]] > x[i] || (ans[q[i]] > y[i]))
      {
        ans[q[i]] = max(ans[q[i]], y[i] + 1);
        ans[p[i]] = max(ans[p[i]], x[i] + 1);
      }
      else if (ans[p[i]] == x[i] || ans[q[i]] == y[i])
      {
        ans[q[i]] = y[i];
        ans[p[i]] = x[i];
      }
    }
  }

  LL ret = 0;

  REP(i, n)
  {
    ret += ans[i];
    if (ans[i] > m)
    {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ret << endl;
}