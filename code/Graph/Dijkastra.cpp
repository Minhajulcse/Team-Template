const int N = 1e3 + 5;
const int INF = 1e10+5;
vector<pair < int , int > > g[N];
vector < int > dist(N,INF);
bool vis[N];
void dijkstra(int source) {
    set < pair < int , int > > st;
    st.insert({0,source});
    dist[source] = 0;
    while(st.size() > 0) {
        auto p = *st.begin();
        int wt = p.first;
        int v =  p.second;
        st.erase(st.begin());
        if(vis[v] == true) continue;
        vis[v] = true;
        for(auto child : g[v]) {
            int child_v = child.first;
            int child_wt = child.second;
            if(dist[v] + child_wt < dist[child_v]) {
                dist[child_v] = dist[v] + child_wt;
                st.insert({dist[child_v],child_v});
            }
        }
    }
}