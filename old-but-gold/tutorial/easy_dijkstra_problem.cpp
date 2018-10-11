/// http://www.spoj.com/problems/EZDIJKST/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define pb push_back
typedef pair<int, int> par;
typedef vector<vector<par>> wgraph;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int T;
    cin>>T;
    rep(t,T) {
        int n, m;
        cin>>n>>m;
        wgraph g(n);
        rep(i,m) {
            int u, v, w;
            cin>>u>>v>>w;
            --u;--v;
            g[u].pb({v, w});
        }
        int start, finish;
        cin>>start>>finish;
        --start;--finish;

        int inf = 1e9;
        vector<int> dist(n, inf);
        dist[start] = 0;
        set<par> s;
        s.insert({0, start});
        while (not s.empty()) {
            int u = s.begin() -> second;
            s.erase(s.begin());
            for (par p : g[u]) {
                int v = p.first, w = p.second;
                if (dist[u] + w < dist[v]) {
                    s.erase({dist[v], v});
                    dist[v] = dist[u] + w;
                    s.insert({dist[v], v});
                }
            }
        }

        if (dist[finish] == inf)
            cout<<"NO\n";
        else
            cout<<dist[finish]<<'\n';
    }

    return 0;
}
