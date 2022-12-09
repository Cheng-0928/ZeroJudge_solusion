#include <bits/stdc++.h>
using namespace std;
#define int long long

int xm[4] = {0,0,-1,1};
int ym[4] = {-1,1,0,0};

signed main() {
  int n,m;
  cin >> n >> m;
  vector<vector<int>> mp(n,vector<int>(m));
  vector<vector<int>> visited(n,vector<int>(m));
  int start_n = 1000005, ans = 0;pair<int,int> now;
  for(int i = 0;i<n;i++){
    for(int j = 0;j<m;j++){
      cin >> mp[i][j];
      if(mp[i][j] < start_n){
        now = {j,i};
        start_n = mp[i][j];
      }
    }
  }
  
  while(1){
    int x = now.first, y = now.second;
    ans+=mp[y][x];visited[y][x] = 1;
    int v = 10000000;
    int nx,ny;
    for(int i = 0;i<4;i++){
      if(x+xm[i] < m && y+ym[i] < n && x+xm[i] >=0 && y+ym[i] >= 0
         && mp[y+ym[i]][x+xm[i]] < v && visited[y+ym[i]][x+xm[i]] == 0){
        nx=x+xm[i];ny=y+ym[i];
        v = mp[y+ym[i]][x+xm[i]];
        //cout << v;
      }
    }
    if(v == 10000000) break;
    now = {nx,ny};
  }
  cout << ans << '\n';
  return 0;
}
