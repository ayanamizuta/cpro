#include <bits/stdc++.h>
#include <atcoder/all>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

using namespace std;
LL inf=1e9;
int main(){
	int n,k;cin>>n>>k;
	atcoder::mcf_graph<LL,LL> g(n*2+2);
	int s=n*2,t=s+1;
	g.add_edge(s,t,n*k,inf);
	REP(i,n){
		g.add_edge(s,i,k,0);
		g.add_edge(i+n,t,k,0);
		REP(j,n){
			LL a;cin>>a;
			g.add_edge(i,j+n,1,inf-a);
		}
	}
	auto fl =g.flow(s,t,n*k);
	auto cost = fl.second;
	vector<string> grid(n,string(n,'.'));
	for(auto e:g.edges()){
		if(e.from!=s&&e.to!=t&&e.flow>0){
			grid[e.from][e.to-n]='X';
		}
	}
	cout<<k*n*inf-cost<<endl;
	for(auto s:grid)cout<<s<<endl;
}
