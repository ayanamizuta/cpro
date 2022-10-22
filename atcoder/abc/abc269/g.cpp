#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define LL long long

int n, m, offset = 0;
vector<int> v;
int dp[200001];

vector<int> partition(int k)
{
  vector<int> ret;
  int x = 1;
  while (k)
  {
    ret.push_back(min(x, k));
    k -= min(x, k);
    x *= 2;
  }
  return ret;
}

int main()
{
  cin >> n >> m;
  map<int, int> mp;
  int init = 0;
  REP(i, n)
  {
    int a, b;
    cin >> a >> b;
    init += a;
    mp[b - a]++;
  }
  REP(i, m + 1)
  dp[i] = 1000000000;
  dp[init] = 0;
  for (auto [key, num] : mp)
  {
    auto steps = partition(num);
    for (auto step : steps)
    {
      REP(i_, m + 1)
      {
        int i = key > 0 ? m - i_ : i_;
        if (i + key * step >= 0 && i + key * step <= m)
        {
          dp[i + key * step] = min(dp[i + key * step], dp[i] + step);
        }
      }
    }
  }

  REP(i, m + 1)
  {
    cout << (dp[i] > 200000 ? -1 : dp[i]) << endl;
  }
}