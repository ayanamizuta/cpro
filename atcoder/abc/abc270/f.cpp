#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define LL long long

using fps = vector<mint>;
fps operator*(const fps &a, const fps &b) { return atcoder::convolution(a, b); }
fps operator+(const fps &a, const fps &b)
{
  fps c{a};
  if (a.size() < b.size())
    c.resize(b.size());
  for (int i = 0; i < (int)b.size(); i++)
    c[i] += b[i];
  return c;
}

int n, m;
int x[200000], y[200000], a[200000], b[200000];
LL z[200000];

int main()
{
  cin >> n >> m;
  REP(i, n)
  cin >> x[i];
  REP(i, n)
  cin >> y[i];
  REP(i, m)
  {
    cin >> a[i] >> b[i] >> z[i];
    a[i]--;
    b[i]--;
  }
  LL ret = 1000000000000000;

  // without air ship
  LL cost_all = 0;
  atcoder::dsu uf(n);
  vector<pair<LL, int>> edges;
  REP(i, m)
  edges.push_back({z[i], i});
  sort(ALL(edges));
  for (auto [cost, idx] : edges)
  {
    if (uf.same(a[idx], b[idx]))
      continue;
    cost_all += cost;
    uf.merge(a[idx], b[idx]);
  }
  if (uf.groups().size() == 1)
    ret = min(ret, cost_all);

  cost_all = 0;
  atcoder::dsu uf1(n + 1);
  edges.resize(0);
  REP(i, m)
  edges.push_back({z[i], i});
  REP(i, n)
  edges.push_back({x[i], m + i});
  sort(ALL(edges));
  for (auto [cost, idx] : edges)
  {
    if (idx < m)
    {
      if (uf1.same(a[idx], b[idx]))
        continue;
      cost_all += cost;
      uf1.merge(a[idx], b[idx]);
    }
    else
    {
      idx -= m;
      if (uf1.same(idx, n))
        continue;
      cost_all += cost;
      uf1.merge(idx, n);
    }
  }
  if (uf1.groups().size() == 1)
    ret = min(ret, cost_all);

  cost_all = 0;
  atcoder::dsu uf2(n + 1);
  edges.resize(0);
  REP(i, m)
  edges.push_back({z[i], i});
  REP(i, n)
  edges.push_back({y[i], m + i});
  sort(ALL(edges));
  for (auto [cost, idx] : edges)
  {
    if (idx < m)
    {
      if (uf2.same(a[idx], b[idx]))
        continue;
      cost_all += cost;
      uf2.merge(a[idx], b[idx]);
    }
    else
    {
      idx -= m;
      if (uf2.same(idx, n))
        continue;
      cost_all += cost;
      uf2.merge(idx, n);
    }
  }
  if (uf2.groups().size() == 1)
    ret = min(ret, cost_all);

  cost_all = 0;
  atcoder::dsu uf3(n + 2);
  edges.resize(0);
  REP(i, m)
  edges.push_back({z[i], i});
  REP(i, n)
  edges.push_back({x[i], m + i});
  REP(i, n)
  edges.push_back({y[i], m +n+ i});
  sort(ALL(edges));
  for (auto [cost, idx] : edges)
  {
    if (idx < m)
    {
      if (uf3.same(a[idx], b[idx]))
        continue;
      cost_all += cost;
      uf3.merge(a[idx], b[idx]);
    }
    else if(idx<m+n)
    {
      idx -= m;
      if (uf3.same(idx, n))
        continue;
      cost_all += cost;
      uf3.merge(idx, n);
    }
    else
    {
      idx -= m+n;
      if (uf3.same(idx, n+1))
        continue;
      cost_all += cost;
      uf3.merge(idx, n+1);
    }
  }
  if (uf3.groups().size() == 1)
    ret = min(ret, cost_all);

  cout << ret << endl;
}