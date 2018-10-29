#include <functional>
using namespace std;

template <typename T>
class SegmentTree{
  
  std::vector<T> segtree;
  std::function<T(T,T)> upd;
  int depth=0; // the depth of thetree
  int best=0;  // the index of maximum element
  int start=0; // the index of start point of additional elements
  
  SegmentTree(std::vector<T> v, T(*upd_in)(T,T)){
    upd = upd_in;
    for(int i=0;i<v.size();i++)
      segtree.push_back(v[i]);
    while((1<<depth)<v.size()){
      depth++;
    }
    start=(1<<depth)-1;
    REP(i,1<<(depth+1)){
      if(i<start)
	segt[i]=0;
      else if(i<start+n)
	segt[i]=input[i-start];
      else
	segt[i]=-INT_MAX;
    }
    FOR(i,start,start+n){
    int tmp=i;
    while(par(tmp)!=-1){
      segt[par(tmp)]=max(segt[tmp],segt[(tmp+1)/2*4-1-tmp]);
      tmp=par(tmp);
    }
    }
    int i=0;
    while(i<start){
      i=(segt[i]==segt[2*i+1])?2*i+1:2*i+2;
    }
    best=i-start;
  }

  public int par(int i){
    if(i==0)
      return -1;
    return (i-1)/2;
  }

  public void update(int d,T x){
    int i=d+start;
    segt[i]=x;
    while(par(i)!=-1){
      segt[par(i)]=max(segt[i],segt[(i+1)/2*4-1-i]);
      i=par(i);
    }
    i=0;
    while(i<start){
      i=(segt[i]==segt[2*i+1])?2*i+1:2*i+2;
    }
    best=i-start;
  }

  public T max_element(){
    return segtree[best];
  }
  
}

//max segt
//segt[best]->max value


void update(int d,int x){
  int i=d+start;
  segt[i]=x;
  while(par(i)!=-1){
    segt[par(i)]=max(segt[i],segt[(i+1)/2*4-1-i]);
    i=par(i);
  }
  i=0;
  while(i<start){
    i=(segt[i]==segt[2*i+1])?2*i+1:2*i+2;
  }
  best=i-start;
}
