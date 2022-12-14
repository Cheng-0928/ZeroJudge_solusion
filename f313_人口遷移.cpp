#include <bits/stdc++.h>
using namespace std;

int xm[4] = {0,0,-1,1};
int ym[4] = {-1,1,0,0};

int main() {
  int R,C,k,m;
  cin >> R >> C >> k >> m;
  vector<vector<int>> mp(R+2, vector<int>(C+2, -1));
  for(int y = 1;y<=R;y++){
    for(int x = 1;x<=C;x++) cin >> mp[y][x];
  }
  while(m--){
    vector<vector<int>> nmp(R+2, vector<int>(C+2));
    nmp = mp;
    for(int y = 1;y<=R;y++){
      for(int x = 1;x<=C;x++){
        int mov = 0;
        if(mp[y][x] == -1) continue;
        for(int i = 0;i<4;i++){
          if(mp[y+ym[i]][x+xm[i]] == -1) continue;
          mov++;
          nmp[y+ym[i]][x+xm[i]]+=(mp[y][x] / k);
        }
        nmp[y][x]-=(mp[y][x] / k) * mov;
        
      }
    }
    mp.clear();mp = nmp;
  }
  int mi = 1000, ma = 0;
  for(int y = 1;y<=R;y++){
    for(int x = 1;x<=C;x++){
      if(mp[y][x] == -1) continue;
      mi = min(mi, mp[y][x]);ma = max(ma, mp[y][x]);
    }
  }
  cout << mi << '\n' << ma << '\n';
  
  return 0;
}
