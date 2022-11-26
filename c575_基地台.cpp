#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int  n, k;
vector<int> v;

bool sol(int d){
  int u = 0;
  int mn = v[0] +d;
  u++;
  for(int i = 1;i<n;i++){
    while(v[i] > mn){
      mn = v[i] + d;
      u++;
    }
  }
  return u<=k;
}

int main() {
  cin >> n >> k;
  for(int i = 0;i<n;i++) {
    int it;
    cin >> it;
    v.push_back(it);
  }
  sort(v.begin(),v.end());
  int l = 0, r = (v[n-1] - v[0])/k +1, ans;
  
  while(l<=r){
    int mid = (l+r)/2;
    if(sol(mid)){
      ans = mid;
      r = mid-1;
    }
    else{
      l = mid+1;
    }
  }
  cout << ans;
  return 0;
}
