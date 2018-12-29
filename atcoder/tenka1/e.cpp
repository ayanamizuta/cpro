#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

int h,w;
string s[300];
char rot1[600][600],rot2[600][600];
int cum_rot1[601][600],cum_rot2[601][600];
LL ret=0;


int main(){
  cin>>h>>w;
  REP(i,h)
    cin>>s[i];
  
  REP(i,600){
    REP(j,600){
      rot1[i][j]='.';
      rot2[i][j]='.';
    }
  }
  
  REP(i,h){
    REP(j,w){
      if((i+j)%2==0){
	rot1[(i+j)/2][(h-1)/2+(j-i)/2] = s[i][j];
      }else{
	rot2[(i+j)/2][(h-1)/2+(j-i+1)/2] = s[i][j];
      }
    }
  }
  
  REP(i,601){
    REP(j,600){
      cum_rot1[i][j]=0;
      cum_rot2[i][j]=0;
    }
  }
  
  REP(j,(h+1)/2+(w+1)/2){
    REP(i,(h+1)/2+(w+1)/2+1){
      if(i==0){
	cum_rot1[i][j]=0;
	cum_rot2[i][j]=0;
      }else{
	cum_rot1[i][j]=cum_rot1[i-1][j]+((rot1[i-1][j]=='#')?1:0);
	cum_rot2[i][j]=cum_rot2[i-1][j]+((rot2[i-1][j]=='#')?1:0);
      }
    }
  }
  /*
  REP(i,10){
    REP(j,10)
      cerr<<rot2[i][j];
    cerr<<endl;
  }
  REP(i,10){
    REP(j,10)
      cerr<<cum_rot2[i][j];
    cerr<<endl;
  }
  */
  
  REP(j,(h+1)/2+(w+1)/2){
    REP(i1,(h+1)/2+(w+1)/2){
      FOR(i2,i1+1,(h+1)/2+(w+1)/2){
	if(rot1[i1][j] == '#' && rot1[i2][j] == '#'){
	  if(j>=i2-i1)
	    ret+=cum_rot1[i2+1][j-(i2-i1)]-cum_rot1[i1][j-(i2-i1)];
	  if(600-j>i2-i1)
	    ret+=cum_rot1[i2+1][j+(i2-i1)]-cum_rot1[i1][j+(i2-i1)];
	}
	if(rot2[i1][j] == '#' && rot2[i2][j] == '#'){
	  if(j>=i2-i1)
	    ret+=cum_rot2[i2+1][j-(i2-i1)]-cum_rot2[i1][j-(i2-i1)];
	  if(600-j>i2-i1)
	    ret+=cum_rot2[i2+1][j+(i2-i1)]-cum_rot2[i1][j+(i2-i1)];
	}
      }
    }
  }

  REP(i,600){
    REP(j,600){
      rot1[i][j]='.';
      rot2[i][j]='.';
    }
  }

  REP(i,h){
    REP(j,w){
      if((i+j)%2==0){
	rot1[(h-1)/2+(j-i)/2][(i+j)/2] = s[i][j];
      }else{
	rot2[(h-1)/2+(j-i+1)/2][(i+j)/2] = s[i][j];
      }
    }
  }
  
  REP(i,601){
    REP(j,600){
      cum_rot1[i][j]=0;
      cum_rot2[i][j]=0;
    }
  }

  REP(j,(h+1)/2+(w+1)/2){
    REP(i,(h+1)/2+(w+1)/2+1){
      if(i==0){
	cum_rot1[i][j]=0;
	cum_rot2[i][j]=0;
      }else{
	cum_rot1[i][j]=cum_rot1[i-1][j]+((rot1[i-1][j]=='#')?1:0);
	cum_rot2[i][j]=cum_rot2[i-1][j]+((rot2[i-1][j]=='#')?1:0);
      }
    }
  }

  REP(j,(h+1)/2+(w+1)/2){
    REP(i1,(h+1)/2+(w+1)/2){
      FOR(i2,i1+1,(h+1)/2+(w+1)/2){
	if(i2-i1<2)continue;
	if(rot1[i1][j] == '#' && rot1[i2][j] == '#'){
	  if(j>=i2-i1)
	    ret+=cum_rot1[i2][j-(i2-i1)]-cum_rot1[i1+1][j-(i2-i1)];
	  if(600-j>i2-i1)
	    ret+=cum_rot1[i2][j+(i2-i1)]-cum_rot1[i1+1][j+(i2-i1)];
	}
	if(rot2[i1][j] == '#' && rot2[i2][j] == '#'){
	  if(j>=i2-i1)
	    ret+=cum_rot2[i2][j-(i2-i1)]-cum_rot2[i1+1][j-(i2-i1)];
	  if(600-j>i2-i1)
	    ret+=cum_rot2[i2][j+(i2-i1)]-cum_rot2[i1+1][j+(i2-i1)];
	}
      }
    }
  }
  
  cout<<ret<<endl;
  return 0;
}
