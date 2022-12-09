#include <bits/stdc++.h>
using namespace std;

int f[6] = {3,1,0,5,4,2};
int r[6] = {1,5,2,3,0,4};

int main() {
  int n,m;
  cin >> n >> m;
  vector<vector<int>> v(n,vector<int>(6));
  for(int i = 0;i<n;i++){
    for(int j = 0;j<6;j++) v[i][j] = j+1;
  }
  while(m--){
    int a,b;
    cin >> a >> b;
    vector<int> c;
    c = v[a-1];
    if(b > 0) swap(v[a-1], v[b-1]);
    else if(b == -1) for(int i = 0;i<6;i++) swap(v[a-1][distance(v[a-1].begin(), find(v[a-1].begin(), v[a-1].end(), c[i]))], v[a-1][f[i]]);
    else if(b == -2) for(int i = 0;i<6;i++) swap(v[a-1][distance(v[a-1].begin(), find(v[a-1].begin(), v[a-1].end(), c[i]))], v[a-1][r[i]]);
  }
  for(int i = 0;i<n;i++) cout << v[i][0] << ' ';
  cout << '\n';
  return 0;
}
