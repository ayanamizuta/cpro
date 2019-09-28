#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int l,n,m;
int r[1000],p[1000],a[100000],b[100000],c[100000],d[100000];
int xs[1000],ys[1000],zs[1000];

bool col(int x1,int y1,int z1,int r1,int x2,int y2,int z2,int r2){
  int xd=x1-x2;
  int yd=y1-y2;
  int zd=z1-z2;
  if((r1+r2)*(r1+r2)<xd*xd+yd*yd+zd*zd)return false;
  return true;
}

bool outofwall(int x,int y,int z,int r){
  return (x < r) || (y < r) || (z < r) || (l-x < r) || (l-y < r) || (l-z < r); 
}

int ind[1000];
vector<int> alive;

int nearest_nn_ind(int x,int y,int z){
  int ret=0;
  int score = 100000000;
  REP(i,alive.size()){
    int xd = x-xs[ind[alive[i]]];
    int yd = y-ys[ind[alive[i]]];
    int zd = z-zs[ind[alive[i]]];
    if(xd*xd+yd*yd+zd*zd < score){score=xd*xd+yd*yd+zd*zd;ret=alive[i];}
  }
  return ret;
}

bool anycol(int x,int y,int z,int r_){
  REP(j_,alive.size()){
    int j = alive[j_];
    if(col(xs[ind[j]],ys[ind[j]],zs[ind[j]],r[ind[j]],x,y,z,r_))return true;
  }
  return false;
}

struct point{
  int x=0;
  int y=0;
  int z=0;
};

int maskx[6] = {0,0,1,0,-1,0};
int masky[6] = {0,-1,0,1,0,0};
int maskz[6] = {-1,0,0,0,0,1};

point nn_pt(int x1,int y1,int z1,int x2,int y2,int z2){
  int score=100000000;
  point ret;
  REP(i,6){
    int xd = x1-(x2+maskx[i]);
    int yd = y1-(y2+masky[i]);
    int zd = z1-(z2+maskz[i]);
    if(xd*xd+yd*yd+zd*zd < score){
      score=xd*xd+yd*yd+zd*zd;
      ret.x=x2+maskx[i];
      ret.y=y2+masky[i];
      ret.z=z2+maskz[i];
    }
  }
  return ret;
}

LL global_score(){
  LL ret=0;
  REP(i,n)if(xs[i]!=-1)ret+=p[i];
  REP(i,m){
    if(xs[a[i]]!=-1 && xs[b[i]]!=-1 && ((xs[a[i]]-xs[b[i]])*(xs[a[i]]-xs[b[i]])+(ys[a[i]]-ys[b[i]])*(ys[a[i]]-ys[b[i]])+(zs[a[i]]-zs[b[i]])*(zs[a[i]]-zs[b[i]]) <= c[i]*c[i]))ret+=d[i];
  }
  return ret;
}

int main(){
  cin>>l>>n>>m;
  REP(i,n)cin>>r[i]>>p[i];
  REP(i,m){cin>>a[i]>>b[i]>>c[i]>>d[i];a[i]--;b[i]--;}

  vector<pair<int,int>> v;
  REP(i,n)v.push_back(make_pair(i,p[i]));
  sort(ALL(v),[](pair<int,int> x,pair<int,int> y){return x.second > y.second;});
  REP(i,n)ind[i] = v[i].first;
  //REP(i,5)cerr<<v[i].second<<" "<<endl;

  random_device rnd;
  mt19937 mt(rnd());
  int cnt=0,cnt2=0;
  REP(i,n){
    REP(iter,40000){
      int x = mt()%l;
      int y = mt()%l;
      int z = mt()%l;
      xs[ind[i]]=x;
      ys[ind[i]]=y;
      zs[ind[i]]=z;
      REP(j_,alive.size()){
	int j = alive[j_];
	if(col(xs[ind[j]],ys[ind[j]],zs[ind[j]],r[ind[j]],x,y,z,r[ind[i]])){
	  xs[ind[i]]=-1;
	  ys[ind[i]]=-1;
	  zs[ind[i]]=-1;
	  cnt++;
	  break;
	}
      }
      if(outofwall(x,y,z,r[ind[i]])){
	xs[ind[i]]=-1;
	ys[ind[i]]=-1;
	zs[ind[i]]=-1;
	cnt2++;
      }
      if(xs[ind[i]]==-1)continue;
      // deflagment
      int nind = nearest_nn_ind(x,y,z);
      int x_in=x,y_in=y,z_in=z;
      while(alive.size()>0 && !anycol(x_in,y_in,z_in,r[ind[i]]) && !outofwall(x_in,y_in,z_in,r[ind[i]])){
	x=x_in;
	y=y_in;
	z=z_in;
	point pt=nn_pt(xs[ind[nind]],ys[ind[nind]],zs[ind[nind]],x,y,z);
	x_in=pt.x;
	y_in=pt.y;
	z_in=pt.z;
      }
      alive.push_back(i);
      xs[ind[i]]=x;
      ys[ind[i]]=y;
      zs[ind[i]]=z;
      break;
    }
  }
  cerr<<"log:"<<cnt<<" "<<cnt2<<endl;
  REP(i,n){
    cout<<xs[i]<<" "<<ys[i]<<" "<<zs[i]<<endl;
  }
  
  REP(i_,alive.size()){
    int i = alive[i_];
    cerr<<i<<" "<<xs[ind[i]]<<" "<<ys[ind[i]]<<" "<<zs[ind[i]]<<" "<<r[ind[i]]<<endl;
  }

  cerr<<global_score()<<endl;
  
  return 0;
}
