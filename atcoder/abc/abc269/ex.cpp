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

int n;
int p[200000], sizes[200200];
vector<int> children[200200], heavy_children[200200], light_children[200200];
fps heavy(int);

fps all_product(vector<fps> &fpss)
{
  if (fpss.empty())
    return {1};
  vector<fps> to, from = vector<fps>(fpss);
  while (from.size() != 1)
  {
    to.resize(0);
    int index = 0;
    while (index < from.size())
    {
      if (index + 1 < from.size())
      {
        to.push_back(from[index] * from[index + 1]);
        index += 2;
      }
      else
      {
        to.push_back(from[index]);
        index++;
      }
    }
    swap(from, to);
  }
  return from[0];
}

pair<fps, fps> sub(int begin, int end, vector<fps> &g)
{
  if (begin == end)
    return {fps{1}, fps{0}};
  if (begin == end - 1)
    return {g[begin], g[begin]};
  auto [sub1, sub1_tri] = sub(begin, (begin + end) / 2, g);
  auto [sub2, sub2_tri] = sub((begin + end) / 2, end, g);
  return {sub1 * sub2, sub1_tri + sub1 * sub2_tri};
}

vector<fps> make_heavy(int c)
{
  if (heavy_children[c].empty())
    return {fps{1}};
  vector<fps> res;
  while (true)
  {
    vector<fps> lights;
    for (auto child : light_children[c])
    {
      lights.push_back(heavy(child));
    }
    res.push_back(all_product(lights));
    if (heavy_children[c].empty())
      break;
    c = heavy_children[c][0];
  }
  /*cerr << c << endl;
  for (auto fp : res)
  {
    REP(i, fp.size())
        cerr << fp[i].val() << " ";
    cerr << endl;
  }*/
  return res;
}

fps heavy(int c)
{
  auto g = make_heavy(c);
  auto [g_all, g_all_tri] = sub(0, g.size() - 1, g);
  return fps{0, 1} * (g_all_tri + fps{1}) + g_all * g.back();
}

void make_heavy_path(int c)
{
  if (children[c].empty())
    return;
  for (auto i : children[c])
    light_children[c].push_back(i);
  heavy_children[c].push_back(light_children[c].back());
  light_children[c].pop_back();
  for (auto &i : light_children[c])
  {
    if (sizes[heavy_children[c][0]] < sizes[i])
      swap(heavy_children[c][0], i);
  }
  for (auto c_ : children[c])
  {
    make_heavy_path(c_);
  }
}

int main()
{
  cin >> n;
  REP(i, n - 1)
  {
    cin >> p[i + 1];
    p[i + 1]--;
    children[p[i + 1]].push_back(i + 1);
  }
  for (int i = n - 1; i; i--)
  {
    sizes[p[i]] += 1 + sizes[i];
  }
  make_heavy_path(0);
  auto ans = heavy(0);
  ans.resize(n + 1);
  FOR(i, 1, n + 1)
  cout << ans[i].val() << endl;
}