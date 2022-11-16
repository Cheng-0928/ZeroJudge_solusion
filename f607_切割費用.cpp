#include <iostream>
#include <set>
#define int long long

using namespace std;

signed main() {
  
  int n, l;
  cin >> n >> l;
  set<int> st;
  st.insert(0);st.insert(l);
  int cut[n+1];
  for(int i = 0;i<n;i++){
    int x,p;
    cin >> x >> p;
    cut[p] = x;
  }
  int ans = 0;
  for(int i = 1;i<=n;i++){
    ans+=  (*st.lower_bound(cut[i]) - *--st.upper_bound(cut[i]));
    st.insert(cut[i]);
  }
  cout << ans;
  return 0;
}
