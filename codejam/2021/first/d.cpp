#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int t,n,q,x,y,z;
vector<int> v;

void receive_median(int x_,int y_,int z_){
  cout<<x_<<" "<<y_<<" "<<z_<<endl;
  cin>>y;
  if(y_==y){
    x=x_;
    z=z_;
  }else if(x_==y){
    x=y_;
    z=z_;
  }else{
    x=x_;
    z=y_;
  }
}

void insert_(int target,int ind){
  v.insert(v.begin()+ind,target);
}

int determine_position(int target,int from,int to){
  if(from>to){
    insert_(target,0);
    return 0;
  }
  int from_base=from,to_base=to;
  int from_ = from_base+max(1,(to_base-from_base)/3),to_=from_base+max(1,(to_base-from_base)/3)*2;
  if(from_base==to_base){
    if(from_base==0){
      from_=from_base;
      to_=from_base+1;
      to_base++;
    }else{
      from_=to_base-1;
      to_=to_base;
      from_base--;
    }
  }else if(to_base-from_base==1){
    from_=from_base;
    to_=to_base;
  }
  int rcv;
  while(from_!=to_){
    cout<<v[from_]<<" "<<v[to_]<<" "<<target<<endl;
    cin>>rcv;
    if(rcv==v[from_]){
      if(from_base==from_){
        insert_(target,from_);
        return from_;
      }
      to_base=from_-1;
    }else if(rcv==target){
      if(to_-from_==1){
        insert_(target,to_);
        return to_;
      }
      from_base=from_+1;
      to_base=max(from_base+1,to_-1);
    }else{
      if(to_base==to_){
        insert_(target,to_+1);
        return to_+1;
      }
      from_base=to_+1;
    }
    from_ = from_base+max(1,(to_base-from_base)/3);
    to_=from_base+max(1,(to_base-from_base)/3)*2;
    if(from_base==to_base){
      if(from_base==0){
        from_=from_base;
        to_=from_base+1;
        to_base++;
      }else{
        from_=to_base-1;
        to_=to_base;
        from_base--;
      }
    }else if(to_base-from_base==1){
      from_=from_base;
      to_=to_base;
    }
  }
  insert_(target,from_);
  return from_;
}

// true iff x<z
bool determine_order_xyz(int ypos){
  int med=0;
  if(!ypos){
    cout<<v[0]<<" "<<v[1]<<" "<<x<<endl;
    cin>>med;
    return med==v[0];//x v[0] v[1]
  }else{
    cout<<v[ypos-1]<<" "<<v[ypos]<<" "<<x<<endl;
    cin>>med;
    return med!=v[ypos];//ypos-1 ypos x
  }
}

void merge_unordered(){
  auto pos = determine_position(y,0,v.size()-1);
  auto order = determine_order_xyz(pos);
  if(order){
    determine_position(x,0,pos-1);
    determine_position(z,pos+1,v.size()-1);
  }else{
    determine_position(z,0,pos-1);
    determine_position(x,pos+1,v.size()-1);
  }
}

void merge_rest(){
  FOR(i,n/3*3,n){
    determine_position(i+1,0,v.size()-1);
  }
}

void solve_one(){
  v.resize(0);
  receive_median(1,2,3);
  v.push_back(x);
  v.push_back(y);
  v.push_back(z);

  REP(i,(n-3)/3){
    receive_median((i+1)*3+1,(i+1)*3+2,(i+1)*3+3);
    merge_unordered();
  }

  if(n%3){
    merge_rest();
  }

  REP(i,n){
    if(!i)cout<<v[i];
    else cout<<" "<<v[i];
  }
  cout<<endl;
  cin>>q;
}

int main(){
  cin>>t>>n>>q;
  REP(i,t)solve_one();
  return 0;
}
