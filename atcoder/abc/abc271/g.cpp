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
int x, y;
string c;
vector<vector<mint>> mat;
mint vec[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};

void print_mat(vector<vector<mint>> m)
{
  REP(i, 24)
  {
    REP(j, 24)
    {
      cerr << m[i][j].val() << " ";
    }
    cerr << endl;
  }
}

vector<vector<mint>> mat_mul(vector<vector<mint>> &m1, vector<vector<mint>> &m2)
{
  vector<vector<mint>> ret;
  ret.resize(24);
  REP(i, 24)
  ret[i].resize(24);
  REP(i, 24)
  {
    REP(j, 24)
    {
      REP(k, 24)
      {
        ret[i][k] += m1[i][j] * m2[j][k];
      }
    }
  }
  return ret;
}

vector<vector<mint>> mat_pow()
{
  LL p = n;

  vector<vector<mint>> b, ret;
  b.resize(24);
  REP(i, 24)
  b[i].resize(24);
  ret.resize(24);
  REP(i, 24)
  ret[i].resize(24);

  REP(i, 24)
  {
    REP(j, 24)
    b[i][j] = mat[i][j];
    ret[i][i] = 1;
  }

  while (p > 0)
  {
    if (p % 2)
    {

      ret = mat_mul(ret, b);
    }
    b = mat_mul(b, b);
    p /= 2;
  }
  return ret;
}

int main()
{
  cin >> n;
  cin >> x >> y;
  cin >> c;
  mat.resize(24);
  REP(i, 24)
  mat[i].resize(24);
  REP(i, 24)
  {
    mint prob = mint(1);
    FOR(j, i + 1, 24)
    {
      if (c[j] == 'T')
      {
        mat[i][j] += prob * mint(x) / mint(100);
      }
      else
      {
        mat[i][j] += prob * mint(y) / mint(100);
      }
      prob -= mat[i][j];
    }
    REP(j, i + 1)
    {
      if (c[j] == 'T')
      {
        mat[i][j] += prob * mint(x) / mint(100);
      }
      else
      {
        mat[i][j] += prob * mint(y) / mint(100);
      }
      prob -= mat[i][j];
    }
    REP(j, 24)
    mat[i][j] /= (1 - prob);
  }

  mint ret = 0;
  auto matpow = mat_pow();

  REP(i, 24)
  {
    if (c[i] == 'A')
      ret += matpow[23][i];
  }
  cout << ret.val() << endl;
}