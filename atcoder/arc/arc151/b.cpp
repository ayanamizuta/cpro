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
LL m;
int p[200000];
int main()
{
  cin >> n >> m;
  REP(i, n)
  {
    cin >> p[i];
    p[i]--;
  }
  mint ret = 0;
  int components = n;
  auto uf = atcoder::dsu(n);
  REP(i, n)
  {
    if (!uf.same(i, p[i]))
      ret += mint(m) * mint(m - 1) / 2 * mint(m).pow(components - 2);
    // cerr << ret.val() << endl;
    if (!uf.same(i, p[i]))
    {
      uf.merge(i, p[i]);
      components--;
    }
  }
  cout << ret.val() << endl;
}