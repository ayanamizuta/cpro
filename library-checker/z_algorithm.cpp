#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

string s;

int main(){
  cin>>s;
  vector<int> z(s.size());
  z[0] = s.size();
  int i = 1, j = 0;
  while(i < s.size()){
      cerr<<i<<" "<<j<<endl;
      while(i + j < s.size() && s[j] == s[i + j]) j++;
      z[i] = j;

      if(j == 0){
          i++;
          continue;
      }
      int k = 1;
      while(k < j && k + z[k] < j){
          z[i + k] = z[k];
          k++;
      }
      i += k;
      j -= k;
  }
  REP(i, s.size())cout << z[i] << " ";
  cout << endl;
  return 0;
}
