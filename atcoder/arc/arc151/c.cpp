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

LL n;
int m;
LL x[200000];
int y[200000];
int main()
{
  cin >> n >> m;
  REP(i, m)
  cin >> x[i] >> y[i];
  if (m == 0)
  {
    cout << (n % 2 ? "Takahashi" : "Aoki") << endl;
    return 0;
  }
  LL init = x[0] - 1;
  LL term = n - x[m - 1];
  LL par = 0;
  REP(i, m - 1)
  {
    LL diff = x[i + 1] - x[i];
    if (diff == 1)
      continue;
    if (y[i] == y[i + 1])
      par++;
    par %= 2;
  }
  // cerr << par << " " << init << " " << term << endl;
  cout << ((par ^ init ^ term) ? "Takahashi" : "Aoki") << endl;
}