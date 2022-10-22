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

int n, s;
int a[100], b[100];
vector<int> dp[10001], dp_old[10001];
bool ish[100];
int main()
{
  cin >> n >> s;
  REP(i, n)
  cin >> a[i] >> b[i];
  REP(i, n)
  {
    for (int j = s; j >= 0; j--)
    {
      if ((i == 0 && j == 0) || !dp[j].empty() && abs(dp[j].back()) == i)
      {
        if (j + a[i] <= s)
          dp[j + a[i]].push_back(i + 1);
        if (j + b[i] <= s)
          dp[j + b[i]].push_back(-i - 1);
      }
    }
  }
  cout << (!dp[s].empty() ? "Yes" : "No") << endl;
  if (!dp[s].empty())
  {
    int i_ = s;
    int j_ = n - 1;
    while (j_ != -1)
    {
      for (auto elem : dp[i_])
      {
        // cerr << i_ << " " << j_ << " " << elem << endl;
        if (abs(elem) == j_ + 1)
        {
          ish[j_] = elem > 0;
          i_ -= ish[j_] ? a[j_] : b[j_];
          break;
        }
      }
      j_ -= 1;
    }
    REP(i, n)
    cout << (ish[i] ? "H" : "T");
    cout << endl;
  }
}