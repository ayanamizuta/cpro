#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long
#define ITER 5000000
#define ITER2 50000
#define ITERP 100000
#define MAX 200

int n;
int x[MAX],y[MAX];
int c[MAX];
double su=0.0;
vector<int> v;

double score(){
  double ret=0.0,su=0.0;
  REP(i,n){
    ret+=(double)((x[c[i]]-x[c[(i+1)%n]])*(x[c[i]]-x[c[(i+1)%n]])+(y[c[i]]-y[c[(i+1)%n]])*(y[c[i]]-y[c[(i+1)%n]]));
    su+=sqrt((double)((x[c[i]]-x[c[(i+1)%n]])*(x[c[i]]-x[c[(i+1)%n]])+(y[c[i]]-y[c[(i+1)%n]])*(y[c[i]]-y[c[(i+1)%n]])));
  }
  return ret*(double)n-su*su;
}

double scorev(){
  double ret=0.0,su=0.0;
  REP(i,n){
    ret+=(double)((x[v[i]]-x[v[(i+1)%n]])*(x[v[i]]-x[v[(i+1)%n]])+(y[v[i]]-y[v[(i+1)%n]])*(y[v[i]]-y[v[(i+1)%n]]));
    su+=sqrt((double)((x[v[i]]-x[v[(i+1)%n]])*(x[v[i]]-x[v[(i+1)%n]])+(y[v[i]]-y[v[(i+1)%n]])*(y[v[i]]-y[v[(i+1)%n]])));
  }
  return ret*(double)n-su*su;
}

int dd(int i,int j){
  return (x[c[(n+i)%n]]-x[c[(n+j)%n]])*(x[c[(n+i)%n]]-x[c[(n+j)%n]])+(y[c[(n+i)%n]]-y[c[(n+j)%n]])*(y[c[(n+i)%n]]-y[c[(n+j)%n]]);
}

double d(int i,int j){
  return sqrt((double)dd(i,j));
}

double scorediff(int i,int j){
  double tmp = d(i-1,i)+d(i+1,i)+d(j-1,j)+d(j+1,j)-(d(i-1,j)+d(i+1,j)+d(j-1,i)+d(j+1,i));
  return (double)(dd(i-1,j)+dd(i+1,j)+dd(j-1,i)+dd(j+1,i)-(dd(i-1,i)+dd(i+1,i)+dd(j-1,j)+dd(j+1,j)))*(double)n+tmp*(2*su-tmp);
}

int main(){
  cin>>n;
  REP(i,n)cin>>x[i]>>y[i];
  REP(i,n){c[i]=i;v.push_back(i);}
  double sc=score();
  double sc_in;
  random_device rnd;
  mt19937 mt;
  mt.seed(rnd());
  
  REP(i,ITERP){
    random_shuffle(v.begin(),v.end());
    sc_in = scorev();
    if(sc>sc_in){
      sc=sc_in;
      REP(j,n)c[j]=v[j];
    }
  }
  
  
  int tmp1,tmp2;
 
  REP(i,n)su+=d(i,i+1);
  
  REP(i,ITER){
    tmp1=mt()%n;
    tmp2=mt()%n;
    if(tmp1==tmp2)continue;
    if(scorediff(tmp1,tmp2)<0){
      su+=d(tmp1-1,tmp2);
      su+=d(tmp1+1,tmp2);
      su+=d(tmp1,tmp2-1);
      su+=d(tmp1,tmp2+1);
      su-=d(tmp1-1,tmp1);
      su-=d(tmp1+1,tmp1);
      su-=d(tmp2,tmp2-1);
      su-=d(tmp2,tmp2+1);
      swap(c[tmp1],c[tmp2]);
    }
  }
  REP(i,n)cout<<c[i]<<endl;
  return 0;
}
