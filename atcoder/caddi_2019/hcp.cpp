#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int l,n,m;
int r[1000],p[1000],a[100000],b[100000],c[100000],d[100000],internalscore[1000][1000];
int xs[1000],ys[1000],zs[1000];

int ind[1000];
vector<int> alive;

bool col(int x1,int y1,int z1,int r1,int x2,int y2,int z2,int r2){
  int xd=x1-x2;
  int yd=y1-y2;
  int zd=z1-z2;
  if((r1+r2)*(r1+r2)<xd*xd+yd*yd+zd*zd)return false;
  return true;
}

bool anycol(int x,int y,int z,int r_){
  REP(j_,alive.size()){
    int j = alive[j_];
    if(col(xs[ind[j]],ys[ind[j]],zs[ind[j]],r[ind[j]],x,y,z,r_))return true;
  }
  return false;
}

bool outofwall(int x,int y,int z,int r){
  return (x < r) || (y < r) || (z < r) || (l-x < r) || (l-y < r) || (l-z < r); 
}

struct face{
  int ind1=0;
  int ind2=0;
  int ind3=0;
};

vector<face> vf;

struct point{
  int x=0;
  int y=0;
  int z=0;
};



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

int sinmaskx[6] = {0,0,1,0,-1,0};
int sinmasky[6] = {0,-1,0,1,0,0};
int sinmaskz[6] = {-1,0,0,0,0,1};

point nn_pt(int x1,int y1,int z1,int x2,int y2,int z2){
  int score=100000000;
  point ret;
  REP(i,6){
    int xd = x1-(x2+sinmaskx[i]);
    int yd = y1-(y2+sinmasky[i]);
    int zd = z1-(z2+sinmaskz[i]);
    if(xd*xd+yd*yd+zd*zd < score){
      score=xd*xd+yd*yd+zd*zd;
      ret.x=x2+sinmaskx[i];
      ret.y=y2+sinmasky[i];
      ret.z=z2+sinmaskz[i];
    }
  }
  return ret;
}

int internal_score(int i,face f){
  return internalscore[min(ind[i],ind[f.ind1])][max(ind[i],ind[f.ind1])]+internalscore[min(ind[i],ind[f.ind2])][max(ind[i],ind[f.ind2])]+internalscore[min(ind[i],ind[f.ind3])][max(ind[i],ind[f.ind3])];
}
#define MASK 26
/*
int maskx[MASK] = {0,0,1,0,-1,0};
int masky[MASK] = {0,-1,0,1,0,0};
int maskz[MASK] = {-1,0,0,0,0,1};
*/
int maskx[MASK] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,0,0,0,0,0,0   ,1,1,1,1,1,1,1,1,1};
int masky[MASK] = {-1,-1,-1,0,0,0   ,1,1,1   ,-1,-1,-1,0,0,1,1,1,-1,-1,-1,0,0,0   ,1,1,1};
int maskz[MASK] = {-1,0,1  ,-1,0,1  ,-1,0,1  ,-1,0,1,-1,1,-1,0,1,-1,0,1  ,-1,0,1  ,-1,0,1};

// take some afford
int maskvx[8] = {0,0,0,0,1,1,1,1};
int maskvy[8] = {0,0,1,1,0,0,1,1};
int maskvz[8] = {0,1,0,1,0,1,0,1};

point vec_sub(point p1,point p2){
  return {p1.x-p2.x,p1.y-p2.y,p1.z-p2.z};
}

point outer_prod(point p1,point p2){
  return {p1.y*p2.z-p1.z*p2.y,p1.z*p2.x-p1.x*p2.z,p1.x*p2.y-p1.y*p2.x};
}

int inner_prod(point p1,point p2){
  return p1.x*p2.x+p1.y*p2.y+p1.z*p2.z;
}

LL mse_loss_sub(point p,int r,point t){
  return ((LL)(p.x-t.x)*(LL)(p.x-t.x)+(LL)(p.y-t.y)*(LL)(p.y-t.y)+(LL)(p.z-t.z)*(LL)(p.z-t.z)-(LL)r*(LL)r)*((LL)(p.x-t.x)*(LL)(p.x-t.x)+(LL)(p.y-t.y)*(LL)(p.y-t.y)+(LL)(p.z-t.z)*(LL)(p.z-t.z)-(LL)r*(LL)r);
}

LL mse_loss(point p1,point p2,point p3,int r1,int r2,int r3,point target,int target_r){
  return mse_loss_sub(p1,r1+target_r,target)+mse_loss_sub(p2,r2+target_r,target)+mse_loss_sub(p3,r3+target_r,target);
}

point face_nn_pt(int face_ind,int i_){
  point ret;
  face f = vf[face_ind];
  point p1 = {xs[ind[f.ind1]],ys[ind[f.ind1]],zs[ind[f.ind1]]};
  point p2 = {xs[ind[f.ind2]],ys[ind[f.ind2]],zs[ind[f.ind2]]};
  point p3 = {xs[ind[f.ind3]],ys[ind[f.ind3]],zs[ind[f.ind3]]};
  point op = outer_prod(vec_sub(p2,p1),vec_sub(p3,p1));

  int maxi=0,maxscore=0;
  REP(i,8){
    ret = {maskvx[i]*l,maskvy[i]*l,maskvz[i]*l};
    int sc_=inner_prod(op,vec_sub(ret,p1));
    if(sc_>maxscore){maxscore=sc_;maxi=i;}
  }
  ret = {maskvx[maxi]*l,maskvy[maxi]*l,maskvz[maxi]*l};
  
  
  int r1 = r[ind[f.ind1]];
  int r2 = r[ind[f.ind2]];
  int r3 = r[ind[f.ind3]];
  int r_ = r[ind[i_]];

  while(true){
    LL loss = mse_loss(p1,p2,p3,r1,r2,r3,ret,r_);
    int nexti=-1;
    REP(i,MASK){
      point ret_in = ret;
      ret_in.x += maskx[i];
      ret_in.y += masky[i];
      ret_in.z += maskz[i];
      LL mseloss =  mse_loss(p1,p2,p3,r1,r2,r3,ret_in,r_);
      if(loss > mseloss && !col(p1.x,p1.y,p1.z,r1,ret_in.x,ret_in.y,ret_in.z,r_)
	 && !col(p2.x,p2.y,p2.z,r2,ret_in.x,ret_in.y,ret_in.z,r_)
	 && !col(p3.x,p3.y,p3.z,r3,ret_in.x,ret_in.y,ret_in.z,r_)){loss = mseloss;nexti=i;}
    }
    if(nexti==-1)break;
    ret.x += maskx[nexti];
    ret.y += masky[nexti];
    ret.z += maskz[nexti];
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
  REP(i,n){
    REP(j,n)internalscore[i][j]=0;
  }
  REP(i,m){cin>>a[i]>>b[i]>>c[i]>>d[i];a[i]--;b[i]--;internalscore[a[i]][b[i]]+=d[i];}

  vector<pair<pair<int,int>,int>> tmp;
  REP(i,n){pair<int,int> p_ = make_pair(i,p[i]);tmp.push_back(make_pair(p_,r[i]));};
  sort(ALL(tmp),[](pair<pair<int,int>,int> x,pair<pair<int,int>,int> y){return (x.second < y.second)? true:(x.second > y.second?false:(x.first).second > (y.first).second);});
  REP(i,n)ind[i] = tmp[i].first.first;

  //initial three cells
  // magic numbers (think tetrahedron whose vertices are (0,0,0),(0,L,L),(L,0,L),(L,L,0)) and contract it.
  /*
  xs[ind[0]]=358;
  ys[ind[0]]=358;
  zs[ind[0]]=358;
  alive.push_back(0);

  xs[ind[1]]=642;
  ys[ind[1]]=642;
  zs[ind[1]]=358;
  alive.push_back(1);

  xs[ind[2]]=642;
  ys[ind[2]]=358;
  zs[ind[2]]=642;
  alive.push_back(2);

  xs[ind[3]]=358;
  ys[ind[3]]=642;
  zs[ind[3]]=642;
  alive.push_back(3);
  */
  int ign=4;
  int ratio=100000;
  int threshold=100;
  int itersize=40000;
  int shrink;
  int width = 2*max(r[ind[ign-4]],max(r[ind[ign-3]],max(r[ind[ign-2]],r[ind[ign-1]])));
  REP(i,143){
    if(2*(284-2*i)*(284-2*i)<width*width)break;
    shrink=i;
  }
  int mag1=358+shrink,mag2=642-shrink;
  REP(i,ign-4){xs[ind[i]]=-1;ys[ind[i]]=-1;zs[ind[i]]=-1;}

  xs[ind[ign-4]]=mag1;
  ys[ind[ign-4]]=mag1;
  zs[ind[ign-4]]=mag1;
  alive.push_back(ign-4);

  xs[ind[ign-3]]=mag2;
  ys[ind[ign-3]]=mag2;
  zs[ind[ign-3]]=mag1;
  alive.push_back(ign-3);

  xs[ind[ign-2]]=mag2;
  ys[ind[ign-2]]=mag1;
  zs[ind[ign-2]]=mag2;
  alive.push_back(ign-2);

  xs[ind[ign-1]]=mag1;
  ys[ind[ign-1]]=mag2;
  zs[ind[ign-1]]=mag2;
  alive.push_back(ign-1);

  //recursive hcp
  vf.push_back({ign-4,ign-3,ign-2});
  vf.push_back({ign-3,ign-1,ign-2});
  vf.push_back({ign-4,ign-1,ign-3});
  vf.push_back({ign-4,ign-2,ign-1});

  random_device rnd;
  mt19937 mt(rnd());
  int criterion = 201;
  //FOR(i,4,n){
  FOR(i,ign,n){
    //cerr<<i<<endl;
    xs[ind[i]]=-1;
    ys[ind[i]]=-1;
    zs[ind[i]]=-1;
    if(r[ind[i]] > threshold && (ratio*p[ind[i]]<r[ind[i]]*r[ind[i]]*r[ind[i]])){continue;}
    
    sort(ALL(vf),[=](face x,face y){return internal_score(i,x)>internal_score(i,y);});

    if(r[ind[i]]<criterion){// possible hcp
      REP(j,vf.size()){
	point pt = face_nn_pt(j,i);
	if(!anycol(pt.x,pt.y,pt.z,r[ind[i]]) && !outofwall(pt.x,pt.y,pt.z,r[ind[i]])){
	  vf.push_back({vf[j].ind1,vf[j].ind2,i});
	  vf.push_back({vf[j].ind2,vf[j].ind3,i});
	  vf.push_back({vf[j].ind3,vf[j].ind1,i});
	  vf.erase(vf.begin() + j);
	  xs[ind[i]]=pt.x;
	  ys[ind[i]]=pt.y;
	  zs[ind[i]]=pt.z;
	  alive.push_back(i);
	  break;
	}
      }
    }
    if(xs[ind[i]]==-1){
      criterion=min(criterion,r[ind[i]]);
      REP(iter,itersize){
	int x = mt()%l;
	int y = mt()%l;
	int z = mt()%l;
	if(abs(500-x) < r[ind[i]] && abs(500-y) < r[ind[i]] && abs(500-z) < r[ind[i]])continue;
	xs[ind[i]]=x;
	ys[ind[i]]=y;
	zs[ind[i]]=z;
	REP(j_,alive.size()){
	  int j = alive[j_];
	  if(col(xs[ind[j]],ys[ind[j]],zs[ind[j]],r[ind[j]],x,y,z,r[ind[i]])){
	    xs[ind[i]]=-1;
	    ys[ind[i]]=-1;
	    zs[ind[i]]=-1;
	    break;
	  }
	}
	if(outofwall(x,y,z,r[ind[i]])){
	  xs[ind[i]]=-1;
	  ys[ind[i]]=-1;
	  zs[ind[i]]=-1;
	}
	if(xs[ind[i]]==-1)continue;
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
  }

  REP(i,n){
    cout<<xs[i]<<" "<<ys[i]<<" "<<zs[i]<<endl;
  }

  
  REP(i_,alive.size()){
    int i = alive[i_];
    cerr<<i<<" "<<xs[ind[i]]<<" "<<ys[ind[i]]<<" "<<zs[ind[i]]<<" "<<r[ind[i]]<<endl;
  }
  
  cerr<<alive.size()<<endl;
  cerr<<global_score()<<endl;
  
  return 0;
}
