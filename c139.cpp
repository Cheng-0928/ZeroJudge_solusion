#include <iostream>
using namespace std;

int visited[6][6], graph[6][6];
int ans[9];

void dfs(int i, int now){
  for(int p = 1;p<=5;p++){
    if(visited[now][p]) continue;
    if(!graph[now][p]) continue;
    ans[i] = now;
    if(i == 8){
      for(int it = 1;it<9;it++) cout << ans[it];
      cout << p;
      cout << '\n';
      continue;
    }
    visited[now][p]++;visited[p][now]++;
    dfs(i+1, p);
    visited[now][p]--;visited[p][now]--;
    
  }
}

int main() {
  graph[1][2]++;
  graph[1][5]++;
  graph[1][3]++;
  graph[2][1]++;
  graph[2][5]++;
  graph[2][3]++;
  graph[3][1]++;
  graph[3][2]++;
  graph[3][4]++;
  graph[3][5]++;
  graph[4][3]++;
  graph[4][5]++;
  graph[5][1]++;
  graph[5][2]++;
  graph[5][3]++;
  graph[5][4]++;
  dfs(1, 1);
  return 0;
}
