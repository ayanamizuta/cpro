#include <vector>

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
    cerr<<ind<<endl;
  }
  return v_ret;
}
