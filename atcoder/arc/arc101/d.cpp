#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

int n;
vector<LL> v,v_sorted;

template <typename T>
long long Clossing(std::vector<T> &v, bool(*gt)(T,T)){
  long long v_len=(long long)v.size();
  if(v_len>1){
    long long v1_len = v_len/2;
    long long v2_len = v_len-v1_len;
    std::vector<T> v1,v2;
    copy(v.begin(), v.begin()+v1_len, back_inserter(v1));
    copy(v.begin()+v1_len, v.end(), back_inserter(v2));
    long long ret1=Clossing(v1,gt);
    std::sort(v1.begin(),v1.end(),gt);
    long long ret2=Clossing(v2,gt);
    std::sort(v2.begin(),v2.end(),gt);
    int idx2=0;
    long long acm=0;
    for(int idx1=0;idx1<v1_len;idx1++){
      while(true){
	if(!gt(v2[idx2],v1[idx1]) || idx2==v2_len-1){
	  acm+=idx2;
	  if(gt(v2[v2_len-1],v1[idx1]))
	    acm++;
	  break;
	}
	idx2++;
      }
    }
    return acm+ret1+ret2;
  }
  return 0;
}

bool comp(int i1,int i2){
  return i1<i2;
}

LL solve(LL val){
  vector<int>t;
  t.push_back(0);
  REP(i,n)
    (v[i]<=val)?t.push_back(-1):t.push_back(1);
  REP(i,n)
    t[i+1]+=t[i];
  return Clossing(t,comp);
}

int main(){
  cin>>n;
  LL a;
  REP(i,n){
    cin>>a;
    v.push_back(a);
    v_sorted.push_back(a);
  }
  if(n==1){
    cout<<v[0]<<endl;
    return 0;
  }
  sort(v_sorted.begin(),v_sorted.end());

  LL med = n*(n+1)/2/2+1;

  int pos = n/2-1,diff=max(1,pos/2);
  while(true){
    LL pos_c = solve(v_sorted[pos]);
    LL pos_suc_c = solve(v_sorted[pos+1]);
    if(pos_c < med && pos_suc_c >= med)break;
    if(pos_c >= med)pos-=diff;
    else pos+=diff;
    if(pos==n-2 || pos==-1)break;
    diff=max(1,diff/2);
  }

  cout<<v_sorted[pos+1]<<endl;
  return 0;
}
