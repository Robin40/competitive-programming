typedef pair<int, int> par;
vector<int> dist(n, 1e9);
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
