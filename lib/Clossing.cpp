//return the number of indices s.t. i<j and gt(v[j],v[i])
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
using namespace std;

template <typename T>
long long Clossing(const std::vector<T> &v, bool(*gt)(T,T)){
  long long v_len=(long long)v.size();
  if(v_len>1){
    long long v1_len = v_len/2;
    long long v2_len = v_len-v1_len;
    std::vector<T> v1(v1_len,0),v2(v2_len,0);
    copy(v.begin(), v.begin()+v1_len, v1.begin());
    copy(v.begin()+v1_len, v.end(), v2.begin());
    long long ret1=Clossing(v1,gt);
    std::sort(v1.begin(),v1.end(),gt);
    long long ret2=Clossing(v2,gt);
    std::sort(v2.begin(),v2.end(),gt);
    int idx2=0;
    long long acm=0;
    for(int idx1=0;idx1<v1_len;idx1++){
      while(true){
	if(!gt(v2[idx2],v1[idx1]) || idx2==v2_len-1){
	  acm+=idx2;
	  if(gt(v2[v2_len-1],v1[idx1]))
	    acm++;
	  break;
	}
	idx2++;
      }
    }
    return acm+ret1+ret2;
  }
  return 0;
}


/*
  --------demo--------
 */


bool gt(long long l1,long long l2){
  return l1<l2;
}

bool gte(long long l1,long long l2){
  return l1<=l2;
}


int main(){
  std::vector<long long>v;
  int n;
  /*
  cin>>n;
  long long a;
  for(int i=0;i<n;i++){
    cin>>a;
    v.push_back(a);
  }
  cout<<"gt:"<<Clossing(v,gt)<<endl;
  cout<<"gte:"<<Clossing(v,gte)<<endl;
  */
  std::vector<long long>v_big;
  for(int i=0;i<500000;i++){
    v_big.push_back(500000-i);
  }
  cout<<"gt:"<<Clossing(v_big,gt)<<endl;
  return 0;
}
