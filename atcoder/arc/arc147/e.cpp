#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define LL long long

int n;
LL a[300000], b[300000];
bool violate[300000];
vector<LL> as;
vector<pair<LL, int>> v;
priority_queue<LL> pq;
int main()
{
  cin >> n;
  REP(i, n)
  {
    cin >> a[i] >> b[i];
    v.push_back({a[i], i});
    if (a[i] < b[i])
    {
      as.push_back(a[i]);
      pq.push(b[i]);
      violate[i] = true;
    }
    else
      violate[i] = false;
  }
  sort(ALL(v), [](const pair<LL, int> a, const pair<LL, int> b)
       { return a.first > b.first; });
  sort(ALL(as));
  int cnt = as.size(), ptr = 0;
  priority_queue<LL> l_pq;
  while (!pq.empty())
  {
    auto b_ = pq.top();
    // cerr << "dbg " << b_ << endl;
    if (as[as.size() - 1] >= b_)
    {
      pq.pop();
      as.pop_back();
      continue;
    }
    FOR(i, ptr, v.size())
    {

      if (v[i].first < b_)
      {
        ptr = i;
        break;
      }
      if (violate[v[i].second])
        continue;
      else
      {
        l_pq.push(-b[v[i].second]);
      }
    }
    while (!pq.empty() && pq.top() == b_)
    {
      pq.pop();
      if (l_pq.empty())
      {
        cout << -1 << endl;
        return 0;
      }
      auto lowest = -l_pq.top();
      // cerr << lowest << endl;
      l_pq.pop();
      pq.push(lowest);
      cnt++;
    }
    // cerr << "dbg2 " << mini << endl;
    // cerr << b_ << " " << mini << " dbg " << cnt << endl;
  }
  cout << n - cnt << endl;
}