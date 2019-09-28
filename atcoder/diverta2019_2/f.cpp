#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

LL mod = 10000000000;

void flush(vector<vector<int>> &w,int n){
  REP(i,n){
    REP(j,n){
      cerr<<w[i][j]<<" ";
    }
  }
}

vector<vector<int>> randgen(int n,random_device &rnd){
  vector<vector<int>> w;   
  std::mt19937 mt(rnd());
  REP(i,n){
    w.push_back(vector<int>());
    REP(j,n){
      w[i].push_back(0);
    }
  }
  REP(i,n){
    FOR(j,i+1,n){
      w[i][j] = max(1,(int)(mt()%(mod)));
      w[j][i]=w[i][j];
    }
  }
  return w;
}

bool verify(vector<vector<int>> &w,vector<int> &v,int n,map<LL,int> &mp){
  LL s=0;
  REP(i,n-1){
    s+=w[v[i]][v[i+1]];
  }
  //cerr<<"dbg"<<" "<<w[0][1]<<" "<<s<<" "<<mp[s]<<endl;
  if(mp[s]<2){
    mp[s]+=1;
    return true;
  }
  cerr<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
  return false;
}

void sim(int n){
  bool bl=false;
  vector<vector<int>> w;
  std::random_device rnd;  
  while(true){
    w=randgen(n,rnd);
    vector<int> v;
    REP(i,n)v.push_back(i);
    map<LL,int> mp;
    do{
      bl=false;
      if(!verify(w,v,n,mp))break;
      bl=true;
    }while(next_permutation(ALL(v)));
    if(bl)break;
  }
  cerr<<n<<endl;
  flush(w,n);
  cerr<<endl;
}

int main(){
  FOR(i,9,11){
    sim(i);
  }
  return 0;
}
