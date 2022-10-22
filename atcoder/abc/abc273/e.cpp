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

vector<int> a;
int q, q_answers[500000];
pair<string, int> queries[500000];
vector<vector<int>> warps;
map<int, int> last_save;
vector<vector<int>> jumps;
vector<int> empty_jumps;

void rollback(int i)
{
  if (queries[i].first[0] == 'A')
  {
    a.pop_back();
  }
  else if (queries[i].first[0] == 'D')
  {
    if (queries[i].second != -1)
      a.push_back(queries[i].second);
  }
}

int last_a()
{
  if (a.empty())
    return -1;
  else
    return a.back();
}

void load_execute(int i)
{
  // cerr << i << endl;
  if (i >= q)
    return;
  if (queries[i].first[0] == 'A')
  {
    a.push_back(queries[i].second);
    q_answers[i] = queries[i].second;
  }
  else if (queries[i].first[0] == 'D')
  {
    if (a.empty())
    {
      q_answers[i] = -1;
    }
    else
    {
      int x = a.back();
      a.pop_back();
      q_answers[i] = last_a();
      queries[i].second = x;
    }
  }
  else if (queries[i].first[0] == 'S')
  {
    q_answers[i] = last_a();
    for (auto nxt : jumps[i])
    {
      q_answers[nxt] = last_a();
      load_execute(nxt + 1);
    }
  }
  else if (queries[i].first[0] == 'L')
  {
    return;
  }
  load_execute(i + 1);
  rollback(i);
}

int main()
{
  cin >> q;
  jumps.resize(q);
  int init = 0;
  REP(i, q)
  {
    string s;
    int x;
    cin >> s;
    if (s[0] == 'D')
      x = -1;
    else
      cin >> x;
    queries[i] = {s, x};
    if (s[0] == 'S')
    {
      last_save[x] = i;
    }
    if (s[0] == 'L')
    {
      if (last_save.find(x) == last_save.end())
      {
        empty_jumps.push_back(i);
        if (init == i)
          init++;
      }
      else
      {
        jumps[last_save[x]].push_back(i);
      }
    }
  }
  for (auto nxt : empty_jumps)
  {
    q_answers[nxt] = last_a();
    load_execute(nxt + 1);
  }
  load_execute(init);

  REP(i, q)
  {
    cout << q_answers[i] << " ";
  }
  cout << endl;
  return 0;
}