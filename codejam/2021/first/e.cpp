#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int t,p;
double s[100];
vector<double> q;
string a[100];


vector<double> rankify(vector<double> &X) {
  
    int N = X.size();
  
    // Rank Vector
    vector<double> Rank_X(N);
      
    for(int i = 0; i < N; i++) 
    {
        int r = 1, s = 1;
          
        // Count no of smaller elements
        // in 0 to i-1
        for(int j = 0; j < i; j++) {
            if (X[j] < X[i] ) r++;
            if (X[j] == X[i] ) s++;
        }
      
        // Count no of smaller elements
        // in i+1 to N-1
        for (int j = i+1; j < N; j++) {
            if (X[j] < X[i] ) r++;
            if (X[j] == X[i] ) s++;
        }
  
        // Use Fractional Rank formula
        // fractional_rank = r + (n-1)/2
        Rank_X[i] = r + (s-1) * 0.5;        
    }
      
    // Return Rank Vector
    return Rank_X;
}

double correlationCoefficient
        (vector<double> &X, vector<double> &Y)
{
    int n = X.size();
    double sum_X = 0, sum_Y = 0, 
                    sum_XY = 0;
    double squareSum_X = 0, 
        squareSum_Y = 0;
  
    for (int i = 0; i < n; i++)
    {
        // sum of elements of array X.
        sum_X = sum_X + X[i];
  
        // sum of elements of array Y.
        sum_Y = sum_Y + Y[i];
  
        // sum of X[i] * Y[i].
        sum_XY = sum_XY + X[i] * Y[i];
  
        // sum of square of array elements.
        squareSum_X = squareSum_X + 
                      X[i] * X[i];
        squareSum_Y = squareSum_Y + 
                      Y[i] * Y[i];
    }
  
    // use formula for calculating
    // correlation coefficient.
    double corr = (double)(n * sum_XY - 
                  sum_X * sum_Y) / 
                  sqrt((n * squareSum_X -
                       sum_X * sum_X) * 
                       (n * squareSum_Y -
                       sum_Y * sum_Y));
  
    return corr;
}



double est_s(int i){
  int n=0;
  REP(j,10000){
    if(a[i][j]=='1')n++;
  }
  double r = (double)n/(double)10000;
  double lhs = exp(6*(r-1));
  double exp_minus_s = (1-lhs)/(exp(3)*lhs-exp(-3));
  return -log(exp_minus_s);
}

double est_q(int j){
  double lb=-3;
  double ub=3;
  int mean = 0;
  REP(i,100){
    if(a[i][j]=='1')mean++;
  }
  while(abs(ub-lb)>0.01){
    double mid=(ub-lb)/2+lb;
    double est_mean=0;
    REP(i,100)est_mean+=1/(1+exp(mid-s[i]));
    if(est_mean < (double)mean)
      ub=mid;
    else
      lb=mid;
  }
  return lb;
}

double spearmanr(int i){
  vector<double> correct;
  REP(j,10000){
    correct.push_back(a[i][j]=='1'?-1:0);
  }
  return correlationCoefficient(q,correct);
}

void solve_one(int problem_num){
  q.resize(0);
  REP(i,100)cin>>a[i];

  REP(i,100)s[i]=est_s(i);
  
  REP(j,10000)q.push_back(est_q(j));

  vector<double> v;
  REP(i,100)v.push_back(spearmanr(i));
  int ret = min_element(ALL(v))-v.begin()+1;

  cout<<"Case #"<<problem_num<<": "<<ret<<endl;
}

int main(){
  cin>>t>>p;
  REP(i,t)solve_one(i+1);
  return 0;
}
