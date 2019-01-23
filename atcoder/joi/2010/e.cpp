#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

const int MAXSSTN = 100010;
class StarrySkyTree{
public:
  int size=0;
  int depth=0; // the depth of the tree
  int best=0;  // the index of maximum element
  int start=0; // the initial index of inputs
  long long dat_add[4 * MAXSSTN];
  long long dat[4 * MAXSSTN];
  StarrySkyTree(int n){
    size=n;
    while((1<<depth)<n)depth++;
    start=(1<<depth)-1;
    for(int i=start;i<(1<<(depth+1));i++){
      dat[i]=-1e15;
    }
  }
  StarrySkyTree(int n,long long* v){
    size=n;
    while((1<<depth)<n)depth++;
    start=(1<<depth)-1;
    for(int i=start;i<(1<<(depth+1));i++){
      if(i<start+n)
	dat[i]=v[i-start];
      else
	dat[i]=-1e15;
    }
    for(int i=start;i<start+n;i++){
      int tmp=i;
      while(par(tmp)!=-1){
	dat[par(tmp)]=max(dat[tmp],dat[(tmp+1)/2*4-1-tmp]);
	tmp=par(tmp);
      }
    }
    int i=0;
    while(i<start)i=(dat[i]==dat[2*i+1])?2*i+1:2*i+2;
    best=i-start;
  }
  long long max_element(int a, int b){ return max_element(a, b, 0, 0, (1<<depth)); }
  void add(int s, int t, long long x){ add(s, t, 0, 0, (1<<depth), x); }
  void add(int i, long long x){ add(i, i + 1, 0, 0, (1<<depth), x); }

  int par(int i){
    if(i==0)
      return -1;
    return (i-1)/2;
  }

  void update(int d,long long x){
    int i=d+start;
    dat[i]=x;
    while(par(i)!=-1){
      dat[par(i)]=max(dat[i]+dat_add[i],dat[(i+1)/2*4-1-i]+dat_add[(i+1)/2*4-1-i]);
      i=par(i);
    }
    i=0;
    while(i<start){
      i=(dat[i]==dat[2*i+1])?2*i+1:2*i+2;
    }
    best=i-start;
  }
  void dump(){
    cerr<<"SegTree:"<<endl;
    for(int i=0;i<depth+1;i++){
      for(int j=0;j<(1<<i);j++)
	cerr<<dat[j+(1<<i)-1]<<" ";
      cerr<<endl;
    }
    cerr<<endl;
    cerr<<"SegTree lazy addition:"<<endl;
    for(int i=0;i<depth+1;i++){
      for(int j=0;j<(1<<i);j++)
	cerr<<dat_add[j+(1<<i)-1]<<" ";
      cerr<<endl;
    }
    cerr<<endl;
  }
private:
  long long max_element(int a, int b, int k, int l, int r){
    if(b <= l || r <= a) return -1e15;
    if(a <= l && r <= b) return dat[k] + dat_add[k];

    long long vl = max_element(a, b, k * 2+1, l, (l + r) / 2);
    long long vr = max_element(a, b, k * 2+2, (l + r) / 2, r);
    return max(vl, vr) + dat_add[k];
  }
  void add(int a, int b, int k, int l, int r, long long x){
    if(b <= l || r <= a) return;
    if(a <= l && r <= b){
      dat_add[k] += x;
    }else{
      add(a, b, k * 2+1, l, (l + r) / 2, x);
      add(a, b, k * 2+2, (l + r) / 2, r, x);
      dat[k] = max(dat[k * 2+1] + dat_add[k * 2+1], dat[k * 2 + 2] + dat_add[k * 2 + 2]);
    }
  }
};

int n;
LL H;
LL d[100000],h[100000];

struct cost{
  int ind;
  LL val;
};

bool operator<(const cost &c1,const cost &c2){
  return c1.val<c2.val;
}

int main(){
  cin>>n>>H;
  vector<LL> heal(n,0);
  REP(i,n-1)
    cin>>d[i]>>h[i];
  StarrySkyTree sst(n);
  priority_queue<cost> que;
  LL ret=0;
  LL l=H;
  REP(i,n-1){
    sst.update(i,l);
    cost c={i,min(h[i],H-l)};
    que.push(c);
    l-=d[i];
    if(l>0)continue;
    else{
      while(l<=0){
	cost c = que.top();
	LL maxl = sst.max_element(c.ind,i+1);
	if(c.val > H-maxl){
	  que.pop();
	  c.val=H-maxl;
	  que.push(c);
	}else{
	  LL num = min((H-maxl)/c.val,1+(-l)/c.val);
	  sst.add(c.ind,i+1,c.val*num);
	  l+=c.val*num;
	  ret+=num;
	  heal[c.ind]+=num; 
	}
      }
    }
  }
  /*
  l=H;
  REP(i,n-1){
    l+=heal[i]*h[i];
    l=min(l,H);
    l-=d[i];
    if(l<=0){
      cerr<<i<<":0 life"<<endl;
    }
  }
  */
  cout<<ret<<endl;
  return 0;
}
