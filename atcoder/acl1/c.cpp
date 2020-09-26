#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int n,m;
LL inf = 1e9;
struct S{
    int x;
    int y;
};
string ss[51];

vector<S> stones;
bool board[50][50];

int main() {
    cin>>n>>m;
    REP(i,n)cin>>ss[i];
    REP(i,n){
        REP(j,m){
            if(ss[i][j] == 'o'){
                stones.push_back(S{i,j});
            }
        }
    }

    int stone=stones.size(),place=n*m;
    int start=stone+place,goal=stone+place+1;
    atcoder::mcf_graph<LL,LL> g(stone+place+2);

    REP(i,stone)g.add_edge(start,i,1,0);
    REP(i,place)g.add_edge(stone+i,goal,1,0);

    REP(sidx,stones.size()){
        auto s = stones[sidx];
        REP(i,n){
            REP(j,m){
                board[i][j]=false;
            }
        }
        int si=s.x,sj=s.y;
        board[si][sj]=true;
        g.add_edge(sidx,stone+si*m+sj,1,inf);

        REP(i,n){
            REP(j,m){
                if(i>0 && board[i-1][j] && ss[i][j]!='#'){
                    board[i][j]=true;
                    g.add_edge(sidx,stone+i*m+j,1,inf-(i+j-si-sj));
                }
                else if(j>0 && board[i][j-1] && ss[i][j]!='#'){
                    board[i][j]=true;
                    g.add_edge(sidx,stone+i*m+j,1,inf-(i+j-si-sj));
                }
            }
        }
    }

    auto [_,fl] =g.flow(start,goal,stone);
    cout<<inf*stone-fl<<endl;
}