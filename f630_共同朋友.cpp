#include <iostream>
#include <bitset>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int n;
  cin >> n;
  bitset<2505> bst[n+1];
  for(int i = 1;i<=n;i++){
    int f;
    cin >> f;
    for(int j = 0;j<f;j++){
      int p;
      cin >> p;
      bst[i][p] = 1;
    }
  }
  int ans = 0;
  for(int i = 1;i<=n;i++){
    for(int j = i+1;j<=n;j++){
      bitset<2505> v;
      v = (bst[i] & bst[j]);
      if(v.any()) ans++;
    }
  }
  cout << ans;
  return 0;
}
