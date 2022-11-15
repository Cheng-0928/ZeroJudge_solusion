#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
  int m,n;
  cin >> m >> n;
  string e[m];
  deque<char> s,t;
  
  for(string &str : e) cin >> str;
  for(int i = 0;i<n;i++){
    char c;
    cin >> c;
    t.push_back(c);
  }
  deque<char> tmp;
  tmp = t;
  for(int i = m-1;i>=0;i--){
    
    int cnt = 0;
    for(int j = n-1;j>=0;j--){
      if(e[i][j] == '1'){
        cnt++;
        s.push_back(tmp[j]);
      }
      else{
        s.push_front(tmp[j]);
      }
    }
    
    if(cnt%2){
      int v = (n+1)/2;
      for(int j = 0;j<(n/2);j++){
        swap(s[j], s[j+v]);
      }
    }
    tmp = s;
    s.clear();
  }
  for(int i = 0;i<n;i++){
    cout << tmp[i];
  }
  return 0;
}
