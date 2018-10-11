/// http://poj.org/problem?id=3041
// ugly conversion from C++11 to poj's G++

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;++i)
typedef vector<vector<int> > graph;
#define pb push_back

class Hopcroft {
	graph g;
	vector<int> U,dist;
	int inf;


	bool bfs() {
    	queue<int> q;
    	rep(i,U.size()) { int u = U[i]; if (match[u] == nil) {
        	dist[u] = 0;
        	q.push(u);
    	} else dist[u] = inf;}
    	dist[nil] = inf;
    	while (not q.empty()) {
        	int u = q.front(); q.pop();
        	if (u != nil) rep(i,g[u].size()) { int v = g[u][i]; if (dist[match[v]] == inf) {
            		dist[match[v]] = dist[u]+1;
            		q.push(match[v]);
        	}}
    	}
    	return (dist[nil] != inf);
	}


	bool dfs(int u) {
    	if(u != nil) {
        	rep(i,g[u].size()) { int v = g[u][i]; if (dist[match[v]] == dist[u]+1 and dfs(match[v])) {
            		match[v] = u;
            		match[u] = v;
            		return true;
        	}}
        	dist[u] = inf;
        	return false;
    	}
    	return true;
	}


public:
	vector<int> match;
	int nil, isPerfect, matchSize;
	Hopcroft(graph& gg, vector<int>& UU) {
            inf = 1e9; matchSize = 0;
    		g = gg; U = UU; nil = g.size();
    		match.assign(g.size()+1,nil);
    		dist.assign(g.size()+1,inf);
    		while (bfs()) rep(i,U.size()) { int u = U[i]; if (match[u] == nil and dfs(u))
        		++matchSize;}
		isPerfect = (matchSize == U.size() and g.size() == U.size()*2);


	}
};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin>>n>>m;
    graph g(n*2);
    rep(i,m) {
        int u, v;
        cin>>u>>v;
        --u; --v; v+=n;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<int> U(n);
    rep(i,n) U[i] = i;

    Hopcroft hc(g, U);
    int ans = hc.matchSize;

    cout<<ans<<endl;
    return 0;
}
