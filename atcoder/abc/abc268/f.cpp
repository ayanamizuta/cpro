#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define LL long long

int n;
struct S
{
  LL x_num;
  LL score;
  LL sum;
};
vector<S> v;
int main()
{
  cin >> n;
  REP(i, n)
  {
    string s;
    cin >> s;
    LL x_num = 0, score = 0, sum = 0;
    REP(i, s.size())
    {
      if (s[s.size() - 1 - i] != 'X')
      {
        LL c = s[s.size() - 1 - i] - '0';
        sum += c;
      }
      else
      {
        x_num++;
        score += sum;
      }
    }
    v.push_back(S{x_num, score, sum});
  }

  sort(ALL(v), [](S a, S b)
       { return a.sum * b.x_num < b.sum * a.x_num; });

  LL score = 0, cum = 0;
  REP(i, v.size())
  {
    auto s = v[v.size() - 1 - i];
    score += s.x_num * cum + s.score;
    cum += s.sum;
  }
  cout << score << endl;
}