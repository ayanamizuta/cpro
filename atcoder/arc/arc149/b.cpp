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
int a_[300000], b[300000], d1[300000], d2[300000];

int longest_increasing_subsequence(vector<int> &arr)
{
  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
    auto it = lower_bound(ans.begin(), ans.end(), arr[i]);
    if (it == ans.end())
    {
      ans.push_back(arr[i]);
    }
    else
    {
      *it = arr[i];
    }
  }
  return ans.size();
}

int lis(vector<int> const &a)
{
  int len1 = 1, len2 = 1;
  d1[1] = a[1];
  d2[1] = a[1];
  for (int i = 2; i <= n; i++)
  {
    if (d1[len1] >= a[i])
      d1[++len1] = a[i];
    else
    {
      int p1 = upper_bound(d1 + 1, d1 + 1 + len1, a[i], greater<int>()) - d1;
      d1[p1] = a[i];
    }
    if (d2[len2] < a[i])
      d2[++len2] = a[i];
    else
    {
      int p2 = lower_bound(d2 + 1, d2 + 1 + len2, a[i]) - d2;
      d2[p2] = a[i];
    }
  }
  return len2;
}

int main()
{
  cin >> n;
  int ret = 0;
  vector<int> v(n);
  REP(i, n)
  cin >> a_[i];
  REP(i, n)
  cin >> b[i];
  REP(i, n)
  {
    v[a_[i] - 1] = b[i];
  }
  // cerr << v[0] << " " << v[1] << " " << v[2] << " " << endl;
  ret = max(ret, n + longest_increasing_subsequence(v));
  // cerr << longest_increasing_subsequence(v) << endl;
  REP(i, n)
  {
    v[b[i] - 1] = a_[i];
  }
  ret = max(ret, n + longest_increasing_subsequence(v));
  // cerr << longest_increasing_subsequence(v) << endl;
  cout << ret << endl;
}