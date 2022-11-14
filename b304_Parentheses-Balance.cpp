#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  cin.ignore();
  while(n--){
    string s;
    getline(cin,s);
    stack<char> stc;
    bool cou = 1;
    for(char c : s){
      if(c == '(' || c == '[') stc.push(c);
      if((c == ')' || c == ']')){
          if(c == ')') {
              if(stc.empty() || stc.top() != '(') cou = 0;
              else stc.pop();
          }
          if(c == ']') {
              if(stc.empty() || stc.top() != '[') cou = 0;
              else stc.pop();
          }
      }
    }
    cou &= stc.empty();
    cout << (cou ? "Yes\n" : "No\n");
  }
  return 0;
}
