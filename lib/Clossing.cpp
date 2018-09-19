//return the number of indices s.t. i<j and v[j]<v[i]
int Clossing(vector<LL> v){
  int v_len=v.size();
  if(v_len>1){
    int v1_len = v_len/2;
    int v2_len = v_len-v1_len;
    vector<LL> v1,v2;
    REP(i,v_len){
      if(i<v1_len)
	v1.push_back(v[i]);
      else
	v2.push_back(v[i]);
    }
    int ret1=tentou(v1);
    sort(v1.begin(),v1.end());
    int ret2=tentou(v2);
    sort(v2.begin(),v2.end());
    int ind=0,su=0;
    REP(i,v1_len){
      while(true){
	if(v1[i]<=v2[ind] || ind==v2_len-1){
	  su+=ind;
	  if(v1[i]>v2[v2_len-1])
	    su++;
	  break;
	}
	ind++;
      }
    }
    return su+ret1+ret2;
  }
  return 0;
}

int main(){
  vector<LL>v;
  int n;
  cin>>n;
  LL a;
  REP(i,n){
    cin>>a;
    v.push_back(a);
  }
  cout<<tentou(v)<<endl;
  return 0;
}
