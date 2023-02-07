#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> adj[N];
bool vis[N], isNode[N];
int cnt, cc;

void dfs(int u, int c) {
  cc++;
  vis[u] = 1;
  if (c == 1) cnt++;
  for (auto v : adj[u]) {
    if (!vis[v]) {
      dfs(v, c ^ 1);
    }
  }
}

inline void solve () {
  for (int i = 0; i < N; i++) {
    adj[i].clear();
    vis[i] = 0;
    isNode[i] = 0;
  }
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    isNode[u] = isNode[v] = 1;
  }
  int ans = 0;
  for (int i = 1; i <= 1e5; i++) {
    if (isNode[i] && !vis[i]) {
      cc = 0, cnt = 0;
      dfs(i, 1);
      ans += max(cnt, cc - cnt);
    }
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case " << i << ": ";
    solve();
  }
  return 0;
}
