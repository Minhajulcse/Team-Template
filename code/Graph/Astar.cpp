const int N = 1e3 + 5;
const long long INF = 1e18;

vector<pair<int,int>> g[N];
vector<long long> dist(N, INF);
bool vis[N];

void astar(int source, int goal) {
    set<pair<long long,int>> st;

    dist[source] = 0;
    st.insert({heuristic(source, goal), source});

    while(!st.empty()) {
        auto p = *st.begin();
        st.erase(st.begin());

        int v = p.second;

        if(vis[v]) continue;
        vis[v] = true;

        if(v == goal) return; // goal reached

        for(auto child : g[v]) {
            int child_v = child.first;
            int child_wt = child.second;

            if(dist[v] + child_wt < dist[child_v]) {
                dist[child_v] = dist[v] + child_wt;
                long long f = dist[child_v] + heuristic(child_v, goal);
                st.insert({f, child_v});
            }
        }
    }
}
