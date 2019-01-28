#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long


struct affine{
  double a=1.0;
  double b=0.0;
};


bool operator<(affine a, affine b){
  return true;
}


bool operator==(affine a, affine b){
  return true;
}

//StarrySky Tree
// intarval update & max
template<typename T,const int MAXSSTN=100010>
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
    cerr<<a.a<<" "<<a.b<<" ";
  }
  T unit_max(){
    affine a;
    return a;
  }
  T unit_add(){
    affine a;
    return a;
  }
  T max_(T a,T b){
    affine ret = {a.a*b.a,b.b+a.b*b.a};
    return ret;
  }
  T add_(T a,T b){
    affine ret = {a.a*b.a,b.b+a.b*b.a};
    return ret;
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
      dat[k] = max_(add_(dat[k * 2+1],dat_add[k * 2+1]),add_(dat[k * 2 + 2],dat_add[k * 2 + 2]));
    }
  }
};


template<typename T>
vector<int> comp_1d(int n,vector<T> &v){
  std::vector<T> v_copy = v;
  sort(v_copy.begin(),v_copy.end());
  for(int i=0;i<v_copy.size()-1;i++){
    if(*(v_copy.end()-1-i)==*(v_copy.end()-2-i))v_copy.erase(v_copy.end()-1-i);
  }
  std::vector<int> v_ret;
  for(int i=0;i<v.size();i++){
    int ind = (int)std::distance(v_copy.begin(),std::lower_bound(v_copy.begin(), v_copy.end(), v[i]));
    v_ret.push_back(ind);
  }
  return v_ret;
}

LL n;
int m;
int main(){
  cin>>n>>m;
  
  vector<LL> v(m);
  vector<affine> v_affine;
  
  REP(i,m){
    cin>>v[i];
    affine af;
    cin>>af.a>>af.b;
    v_affine.push_back(af);
  }
  auto v_ = comp_1d(m,v);
  double ma=1.0,mi=1.0;
  StarrySkyTree<affine> sst((int)m);
  REP(i,m){
    //sst.dump();
    sst.update(v_[i],v_affine[i]);
    affine af =sst.dat[0];
    ma=max(ma,af.a+af.b);
    mi=min(mi,af.a+af.b);
  }
  printf("%.10lf\n",mi);
  printf("%.10lf\n",ma);
  return 0;
}
