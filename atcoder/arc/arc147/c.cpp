#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define LL long long

int n;
LL l[300000], r[300000];
vector<pair<LL, int>> counts;
int main()
{
  cin >> n;
  REP(i, n)
  {
    cin >> l[i] >> r[i];
    counts.push_back({l[i], 1});
    counts.push_back({r[i], -1});
  }
  sort(ALL(counts), [](const pair<LL, int> a, const pair<LL, int> b)
       { return a.first == b.first ? a.second > b.second : a.first < b.first; });
  LL ret = 0;
  vector<LL> lefts(n);
  REP(i, n)
  lefts[i] = l[i];
  sort(ALL(lefts));
  REP(i, n - 1)
  {
    auto dif = lefts[i + 1] - lefts[i];
    ret += dif * (i + 1) * (n - i - 1);
  }
  // inti cal
  int left = 0, cur = 0;
  REP(i, counts.size() - 1)
  {
    auto p1 = counts[i];
    // cerr << p1.first << " " << p1.second << endl;
    cur += p1.second;
    if (p1.second == -1)
      left += 1;
    auto p2 = counts[i + 1];
    if (left < n - left - cur)
    {
      // cerr << cur << " " << left << " " << n - left - cur << endl;
      ret -= (p2.first - p1.first) * (n - left - cur - left) * cur;
    }
    else
      break;
  }
  cout << ret << endl;
}