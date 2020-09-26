#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

const int MAXSEGN = 250010;
class SegmentTree{
public:
  int size=0;
  int depth=0; // the depth of the tree
  int best=0;  // the index of maximum element
  int start=0; // the initial index of inputs
  long long dat[4 * MAXSEGN];
  
  SegmentTree(int n,long long* v){
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

  int par(int i){
    if(i==0)
      return -1;
    return (i-1)/2;
  }

  void update(int d,long long x){
    int i=d+start;
    dat[i]=x;
    while(par(i)!=-1){
      dat[par(i)]=max(dat[i],dat[(i+1)/2*4-1-i]);
      i=par(i);
    }
    i=0;
    while(i<start){
      i=(dat[i]==dat[2*i+1])?2*i+1:2*i+2;
    }
    best=i-start;
  }

  long long max_element(){
    return dat[0];
  }
  
};

int n,m,qnum;
LL f[250000];
string op;
int q;
bool cluster[500];
LL v[250000];

int main(){
    cin>>n>>m>>qnum;
    REP(i,200000)v[i]=0;
    REP(i,500)cluster[i]=false;
    REP(i,500*500){
        f[i]=0;
    }
    REP(i,m){
        int a,b;
        LL f_in;
        cin>>a>>b>>f_in;
        a--;
        b--;
        f[a*n+b]=f_in;
        f[b*n+a]=f_in;
    }
    SegmentTree segt(n*n,v);
    REP(i,qnum){
        cin>>op>>q;
        q--;
        if(op=="+"){
            REP(i,n){
                if(cluster[i]){
                    segt.update(i*n+q,0);
                    segt.update(q*n+i,0);
                }else{
                    segt.update(i*n+q,f[i*n+q]);
                    segt.update(q*n+i,f[q*n+i]);
                }
            }
            cluster[q]=true;
        }else{
            REP(i,n){
                if(cluster[i]){
                    segt.update(i*n+q,f[i*n+q]);
                    segt.update(q*n+i,f[q*n+i]);
                }else{
                    segt.update(i*n+q,0);
                    segt.update(q*n+i,0);
                }
            }
            cluster[q]=false;
        }
        cout<<segt.max_element()<<endl;
    }
    return 0;
}
