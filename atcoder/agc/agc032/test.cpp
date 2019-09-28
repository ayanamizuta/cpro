#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> grh;
int s, t;
void dfs (int crr, int prt) {
  if (crr != prt && crr == s) {
    cout << "Yes" << '\n';
    exit(0);
  } else if (crr == t) {
    return;
  }
  for (int nxt : grh[crr]) {
    if (nxt != prt) {
      dfs(nxt, crr);
    }
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> dgr(n, 0);
  grh.resize(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    dgr[--a]++;
    dgr[--b]++;
    grh[a].push_back(b);
    grh[b].push_back(a);
  }
  vector<int> pts;
  for (int i = 0; i < n; i++) {
    if (dgr[i] & 1) {
      cout << "No" << '\n';
      return 0;
    } else if (dgr[i] >= 6) {
      cout << "Yes" << '\n';
      return 0;
    } else if (dgr[i] == 4) {
      pts.push_back(i);
    }
  }
  if (pts.size() >= 3) {
    cout << "Yes" << '\n';
    return 0;
  } else if (pts.size() < 1) {
    cout << "No" << '\n';
    return 0;
  }
  s = pts[0];
  t = pts[1];
  dfs(s, s);
  dfs(t, t);
  cout << "No" << '\n';
  return 0;
}
