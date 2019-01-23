#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
using namespace std;



//O(n^3)
//implementation from the antbook
#define EPS (1e-8)
template <typename T>
std::vector<T> Gauss_Jordan(const std::vector<vector<T>> &A,const std::vector<T> &b){
  int n=A.size();
  std::vector<vector<T>> B(n,std::vector<T>(n+1));
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)B[i][j]=A[i][j];
  for(int i=0;i<n;i++)B[i][n]=b[i];

  for(int i=0;i<n;i++){
    int pivot=i;
    for(int j=i;j<n;j++){
      if(abs(B[j][i])>abs(B[pivot][i]))pivot=j;
    }
    swap(B[i],B[pivot]);

    if(abs(B[i][i])<EPS)return std::vector<T>();

    for(int j=i+1;j<=n;j++)B[i][j]/=B[i][i];
    for(int j=0;j<n;j++){
      if(i!=j){
	for(int k=i+1;k<=n;k++)B[j][k]-=B[j][i]*B[i][k];
      }
    }
  }
  std::vector<T> x(n);
  for(int i=0;i<n;i++)x[i]=B[i][n];
  return x;
}

//bitset optimization


//O(n^3)
//implementation from the antbook
#define BITN 200
bitset<BITN> Gauss_Jordan_bit(const std::vector<std::bitset<BITN>> &A,const std::bitset<BITN> &b){
  vector<int> where (m, -1);
  for (int col=0, row=0; col<m && row<n; ++col) {
    for (int i=row; i<n; ++i)
      if (a[i][col]) {
	swap (a[i], a[row]);
	break;
      }
    if (! a[row][col])
      continue;
    where[col] = row;

    for (int i=0; i<n; ++i)
      if (i != row && a[i][col])
	a[i] ^= a[row];
    ++row;
  }
  int n=A.size();
  std::vector<vector<T>> B(n,std::vector<T>(n+1));
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)B[i][j]=A[i][j];
  for(int i=0;i<n;i++)B[i][n]=b[i];

  for(int i=0;i<n;i++){
    int pivot=i;
    for(int j=i;j<n;j++){
      if(abs(B[j][i])>abs(B[pivot][i]))pivot=j;
    }
    swap(B[i],B[pivot]);

    if(abs(B[i][i])<EPS)return std::vector<T>();

    for(int j=i+1;j<=n;j++)B[i][j]/=B[i][i];
    for(int j=0;j<n;j++){
      if(i!=j){
	for(int k=i+1;k<=n;k++)B[j][k]-=B[j][i]*B[i][k];
      }
    }
  }
  std::vector<T> x(n);
  for(int i=0;i<n;i++)x[i]=B[i][n];
  return x;
}  
  

int main(){
  vector<int> ret;
  ret=Gauss_Jordan(mat,v);
  return 0;
}
