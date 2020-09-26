#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

string s;
int one[1000001],zero[1000001],onemax[1000001],zeromax[1000001],border_begin[1000001],border_end[1000001];

int main(){
  cin>>s;
  int n = s.size();
  REP(i,n+1){
    if(i==n){
      cout<<1<<endl;
      return 0;
    }
    if(s[i]!='?')break;
  }
  REP(i,n+1){
    one[i]=0;
    zero[i]=0;
    
  }

  one[0]=0;
  REP(i,n){
    one[i+1] = one[i] + (s[i] == '1' ? 1 : -1);
  }
  onemax[n] = one[n];
  REP(i,n){
    onemax[n-1-i] = max(onemax[n-i],one[n-1-i]);
  }

  zero[0]=0;
  REP(i,n){
    zero[i+1] = zero[i] + (s[i] == '0' ? 1 : -1);
  }
  zeromax[n] = zero[n];
  REP(i,n){
    zeromax[n-1-i] = max(zeromax[n-i],zero[n-1-i]);
  }

  int onem=0,zerom=0;
  REP(i,n+1){
    onem=max(onem,onemax[i]-one[i]);
    zerom=max(zerom,zeromax[i]-zero[i]);
  }
  //cerr<<onem<<" "<<zerom<<endl;
  int max_cand=max(onem,zerom);

  REP(i,n+1){
    border_begin[i]=-1;
    border_end[i]=-1;
  }
  for(int i=0;i<n;i++){
    if(zeromax[i]-zero[i] == max_cand){
      int init_i=i;
      while(i<=n){
        i++;
        if(zero[i]-zero[init_i] == max_cand){
          border_end[i]=0;
          border_begin[init_i]=0;
          break;
        }
      }
      i--;
    }

    if(onemax[i]-one[i] == max_cand){
      int init_i=i;
      while(i<=n){
        i++;
        if(one[i]-one[init_i] == max_cand){
          border_end[i]=1;
          border_begin[init_i]=1;
          break;
        }
      }
      i--;
    }
  }
  /*
  REP(i,n+1)cerr<<zero[i]<<" ";
  cerr<<endl;
  REP(i,n+1)cerr<<zeromax[i]<<" ";
  cerr<<endl;

  REP(i,n+1)cerr<<one[i]<<" ";
  cerr<<endl;
  REP(i,n+1)cerr<<onemax[i]<<" ";
  cerr<<endl;

  REP(i,n+1)cerr<<border_begin[i]<<" ";
  cerr<<endl;
  REP(i,n+1)cerr<<border_end[i]<<" ";
  cerr<<endl;
  */

  int cnt=0,sign=-1;
  bool bl_cnt_init=false,bl_cnt_begin=false;
  REP(i,n+1){
    //cerr<<i<<" "<<bl_cnt_init<<" "<<bl_cnt_begin<<" "<<cnt<<endl;
    if(border_begin[i]!=-1 && !bl_cnt_init){
      bl_cnt_init=true;
    }else if(border_end[i]!=-1 && !bl_cnt_begin){
      bl_cnt_begin=true;
      sign=border_end[i];
    }
    if(bl_cnt_begin && border_begin[i]!=-1){
      bl_cnt_begin = false;
      bl_cnt_init=false;
      //cerr<<cnt<<endl;
      //cerr<<sign<<" "<<border_begin[i]<<endl;
      if(sign == border_begin[i] && cnt % 2 == 0 && cnt){
        cout<<max_cand+1<<endl;
        return 0;
      }
      if(sign != border_begin[i] && cnt % 2 == 1 && cnt){
        cout<<max_cand+1<<endl;
        return 0;
      }
      cnt=0;
    }
    if(bl_cnt_begin)cnt++;
  }

  cout<<max_cand<<endl;
  return 0;
}
