#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define LL long long

int n;
int p[5000], pinv[5001];
mint dp_left_strip[5001][5001], dp_left_full[5001][5001];
mint dp_right_strip[5001][5001], dp_right_full[5001][5001];


int main()
{
  cin >> n;
  REP(i, n)
  {
    cin >> p[i];
    p[i]--;
    pinv[p[i]] = i;
  }
  REP(i, n)
  {
    int p_index = pinv[i];
    for (int j = p_index - 1; j >= 0 && p[j] < p[p_index]; j--)
    {
      lefts[i].push_back(0);
    }
    for (int j = p_index + 1; j >= 0 && p[j] < p[p_index]; j++)
    {
      rights[i].push_back(0);
    }
    int left_child_index = -1, right_child_index = -1;
    int left_max = -1, right_max = -1;
    REP(j, n)
    {
      if (j < p_index && left_max < p[j])
      {
        left_child_index = j;
        left_max = p[j];
      }
      if (j > p_index && right_max < p[j])
      {
        right_child_index = j;
        right_max = p[j];
      }
    }
    REP(j, lefts[i].size())
    {
      lefts[i][lefts[i].size() - 1 - j] = su[]
    }
  }

  cout << (dp_left_full[n - 1][0] * dp_left_full[n - 1][1]).val() << endl;
}