#include <iostream>
#include <queue>
using namespace std;

int main() {
  int n;
  cin >> n;
  queue<int> que;
  while(n--){
    int ty;
    cin >> ty;
    if(ty == 1){
      int x;
      cin >> x;
      que.push(x);
    }
    if(ty == 2) cout << (que.empty() ? -1 : que.front()) << '\n';
    if(ty == 3 && !que.empty()) que.pop();
  }
  return 0;
}
