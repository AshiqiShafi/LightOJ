#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
 
int N, M, ans;
char a[25][25];
bool vis[25][25];
 
bool isValid(int x, int y) {
  if (x >= 1 && x <= N && y >= 1 && y <= M && !vis[x][y] && a[x][y] == '.') {
    return true;
  }
  return false;
}
 
void dfs (int x, int y) {
  vis[x][y] = 1;
  ans++;
  for (int k = 0; k < 4; k++) {
    int i = x + dx[k];
    int j = y + dy[k];
    if (isValid(i, j)) dfs(i, j);
  }
}
 
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, tc = 1; cin >> t;
  while (t--) {
    memset(vis, false, sizeof(vis));
    cin >> N >> M;
    swap(N, M);
    int x, y;
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= M; j++) {
        cin >> a[i][j];
        if (a[i][j] == '@') {
          x = i, y = j;
        }
      }
    }
    ans = 0;
    dfs(x, y);
    cout << "Case " << tc++ << ": " << ans << '\n';
  }
  return 0;
}
