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
vector<int> x, d;
int label[1000001];
int table[1000001];
int main()
{
  cin >> n >> m;
  x.resize(n);
  d.resize(m);
  REP(i, n)
  cin >> x[i];
  REP(i, m)
  cin >> d[i];
  int lb = 0,ub=1000000;
  int label_max = 0;
  REP(i, m)
  {
    int mid=(lb+ub)/2;
    if(d[i]<mid){
      lb=d[i];
      label[lb]=-(i+1);
    }else{
      ub=d[i];
    }
    FOR(j, last, d[i])
    {
      label[j] = 2 * d[i] - j;
    }
  }
}