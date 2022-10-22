#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define LL long long

int n, m;
int a[100000];
int main()
{
  cin >> n >> m;
  REP(i, n)
  {
    cin >> a[i];
  }
  queue<pair<vector<mint>, vector<mint>>> que;
  REP(i, n)
  {
    vector<mint> zero = {1};
    vector<mint> val(11, 0);
    val[a[i]] = 1;
    que.push({zero, val});
  }
  while (que.size() != 1)
  {
    auto f1 = que.front();
    que.pop();
    auto f2 = que.front();
    que.pop();
    auto conv11 = atcoder::convolution(f1.first, f2.first);
    auto conv12 = atcoder::convolution(f1.second, f2.second);
    auto conv21 = atcoder::convolution(f1.first, f2.second);
    auto conv22 = atcoder::convolution(f1.second, f2.first);
    while (conv11.size() < conv12.size())
    {
      conv11.push_back(0);
    }
    REP(i, conv12.size())
    {
      conv11[i] += conv12[i];
    }
    while (conv21.size() < conv22.size())
    {
      conv21.push_back(0);
    }
    REP(i, conv22.size())
    {
      conv21[i] += conv22[i];
    }
    que.push({conv11, conv21});
  }
  auto result = que.front();
  cout << ((result.second.size() > m) ? result.second[m].val() : 0) << endl;
}