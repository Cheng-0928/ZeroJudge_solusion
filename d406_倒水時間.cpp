#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int mp[101][101], visited[101][101], graph[101][101];
queue<pair<int,int>> p;
int mx[4] = {-1,1,0,0}, my[4] = {0,0,1,-1};
int s, ca = 1;

void bfs(){
  while(p.size()){
    int x = p.front().first, y = p.front().second;
    p.pop();
    
    for(int i = 0;i<(s == 1 ? 4 : 3);i++){
      if(graph[y + my[i]][x + mx[i]] == 1 && visited[y + my[i]][x + mx[i]] == 0){
        p.push({x + mx[i], y + my[i]});
        visited[y + my[i]][x + mx[i]] = 1;
        mp[y + my[i]][x + mx[i]] = mp[y][x]+1;
      }
    }
  }
}

int main() {
  while(cin >> s){
    cout << "Case " << ca << ':' << '\n';
    for(int i = 0;i<101;i++){
      for(int j = 0;j<101;j++){
        mp[i][j] = 0;
        visited[i][j] = 0;
        graph[i][j] = 0;
      }
    }
    int n,m;
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
      for(int j = 1;j<=m;j++){
        cin >> graph[i][j];
      }
    }
    for(int i = 1;i<=m;i++){
      if(graph[1][i] == 1){
        p.push({i,1});
        visited[1][i] = 1;
        mp[1][i] = 1;
        bfs();
        break;
      }
    }
    for(int i = 1;i<=n;i++){
      for(int j = 1;j<m;j++){
        cout << mp[i][j] << ' ';
      }
      cout << mp[i][m] << '\n';
    }
    ca++;
  }
}
