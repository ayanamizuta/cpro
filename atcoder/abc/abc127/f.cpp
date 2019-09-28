#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

template<typename T,const int MAXSSTN=200010>
class StarrySkyTree{
public:
  int size=0;
  int depth=0; // the depth of the tree
  int best=0;  // the index of maximum element
  int start=0; // the initial index of inputs
  T dat_add[4 * MAXSSTN];
  T dat[4 * MAXSSTN];
  StarrySkyTree(int n){
    init(n);
    for(int i=start;i<start+n;i++){
      int tmp=i;
      while(par(tmp)!=-1){
	dat[par(tmp)]=parent(tmp);
	tmp=par(tmp);
      }
    }
    int i=0;
    while(i<start)i=(dat[i]==dat[2*i+1])?2*i+1:2*i+2;
    best=i-start;
  }
  StarrySkyTree(int n,T* v){
    init(n);
    for(int i=start;i<(1<<(depth+1));i++){
      if(i<start+n)
	dat[i]=v[i-start];
    }
    for(int i=start;i<start+n;i++){
      int tmp=i;
      while(par(tmp)!=-1){
	dat[par(tmp)]=parent(tmp);
	tmp=par(tmp);
      }
    }
    int i=0;
    while(i<start)i=(dat[i]==dat[2*i+1])?2*i+1:2*i+2;
    best=i-start;
  }
  T max_element(int a, int b){ return max_element(a, b, 0, 0, (1<<depth)); }
  void add(int s, int t, T x){ add(s, t, 0, 0, (1<<depth), x); }
  void add(int i, T x){ add(i, i + 1, 0, 0, (1<<depth), x); }

  int par(int i){
    if(i==0)
      return -1;
    return (i-1)/2;
  }

  void update(int d,T x){
    int i=d+start;
    dat[i]=x;
    while(par(i)!=-1){
      dat[par(i)]=parent(i);
      i=par(i);
    }
    i=0;
    while(i<start){
      i=(dat[i]==dat[2*i+1])?2*i+1:2*i+2;
    }
    best=i-start;
  }
  void dump(){
    for(int i=0;i<(depth+1);i++){
      for(int j=0;j<(1<<i);j++)
	print_(dat[j+(1<<i)-1]);
      cerr<<endl;
    }
    cerr<<endl;
  }
private:
  void print_(T a){
    cerr<<a<<" ";
  }
  T unit_max(){
    return -1e18;
  }
  T unit_add(){
    return 0;
  }
  T max_(T a,T b){
    return max(a,b);
  }
  T add_(T a,T b){
    return a+b;
  }
  T parent(int tmp){
    return (tmp<((tmp+1)/2*4-1-tmp))?max_(dat[tmp],dat[(tmp+1)/2*4-1-tmp]):max_(dat[(tmp+1)/2*4-1-tmp],dat[tmp]);
  }
  void init(int n){
    size=n;
    while((1<<depth)<n)depth++;
    start=(1<<depth)-1;
    for(int i=0;i<4*MAXSSTN;i++){
      dat_add[i]=unit_add();
      dat[i]=unit_max();
    }
    for(int i=start;i<(1<<(depth+1));i++){
      dat[i]=unit_max();
    }
  }
  T max_element(int a, int b, int k, int l, int r){
    if(b <= l || r <= a) return unit_max();
    if(a <= l && r <= b) return add_(dat[k],dat_add[k]);

    T vl = max_element(a, b, k * 2+1, l, (l + r) / 2);
    T vr = max_element(a, b, k * 2+2, (l + r) / 2, r);
    return add_(max_(vl, vr),dat_add[k]);
  }
  void add(int a, int b, int k, int l, int r, T x){
    if(b <= l || r <= a) return;
    if(a <= l && r <= b){
      dat_add[k] =add_(dat_add[k],x);
    }else{
      add(a, b, k * 2+1, l, (l + r) / 2, x);
      add(a, b, k * 2+2, (l + r) / 2, r, x);
      dat[k] = max_(add_(dat[k * 2+1],dat_add[k * 2+1]), add_(dat[k * 2 + 2],dat_add[k * 2 + 2]));
    }
  }
};

int q;

struct tri{
  int qid;
  LL a;
  LL b;
};

int main(){
  StarrySkyTree<LL> sst(200000);
  vector<tri> v;
  vector<LL> as;
  REP(i,q){
    int qid;
    cin>>qid;
    if(qid==1){
      LL a,b;
      cin>>a>>b;
      v.push_back(qid,a,b);
      as.push_back(a);
    }else{
      v.push_back(2,0,0);
    }
  }
  sort(ALL(as));
  int mina=0;
  int updnum=0;
  REP(i,n){
    if(v[i].qid==1){
      sst.add(0,ind[i]);
      updnum++;
      int lb=0,ub=n;
      while(lb<ub){
	if(sst.max_element(lb,lb)==medind && sst.max_element(lb+1,lb+1)==medind-1){
	  
	}
	
      }
      if(indinv[lb] <= mina){
	medval = (updnum%2==1)?:
      }
      mina = indinv[lb];
      medval = 
    }else{
      cout<<mina<<" "<<medval<<endl;
    }
  }
  return 0;
}
