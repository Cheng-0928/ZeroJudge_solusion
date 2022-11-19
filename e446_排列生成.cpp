#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int n;
  cin >> n;
  vector<int> vec;
  for(int i = 1;i<=n;i++){
    vec.push_back(i);
  }
  do{
    for(int i = 0;i<n;i++){
      if(vec[i] >= 10) cout.put(1 + '0');
      cout.put(vec[i]%10 + '0');cout.put(' ');
    }
    cout.put('\n');
  }while(next_permutation(vec.begin(), vec.end()));
  return 0;
}
