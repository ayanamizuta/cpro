#include <atcoder/all>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int n,m;
string ss[100];

int main(){
    cin>>n>>m;
    REP(i,n)cin>>ss[i];
    int start = 0,goal = 1+n*m*2;
    auto graph = atcoder::mf_graph<int>(1+n*m+n*m+1);
    REP(i,n){
        REP(j,m){
            if(ss[i][j]=='.'){
                graph.add_edge(start, 1+i*m+j, 1);
                graph.add_edge(1+n*m+i*m+j, goal, 1);
                if (i < n-1 && ss[i+1][j] == '.') graph.add_edge(1+i*m+j, 1+n*m+i*m+j+m, 1);
                if (j < m-1 && ss[i][j+1] == '.') graph.add_edge(1+i*m+j, 1+n*m+i*m+j+1, 1);
            }
        }
    }
    std::cout << graph.flow(start, goal) <<endl;
    for (auto e:graph.edges()) {
        cerr<<e.from<<" "<<e.to<<" "<<e.flow<<endl;
        int from = e.from,to = e.to,flow = e.flow;
        if (flow == 0 || from == start || to == goal) continue;
        if(to >= 1+n*m)to -= 1+n*m;
        else to -= 1;
        if(from >= 1+n*m)from -= 1+n*m;
        else from -= 1;
        if(from > to)swap(from,to);
        ss[from / m][from % m] = (from / m == to / m ? '>' : 'v');
        ss[to   / m][to   % m] = (from / m == to / m ? '<' : '^');
    }
    REP(i,n){
        cout<<ss[i]<<endl;
    }
}