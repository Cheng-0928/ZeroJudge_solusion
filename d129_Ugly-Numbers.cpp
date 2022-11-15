#include <iostream>
#include <set>
using namespace std;

int main() {
  set<int> st;
  st.insert(1);
  int cnt = 0;
  for(auto it = st.begin();it != st.end();it++){
    cnt++;
    if(cnt == 1500) cout << "The 1500'th ugly number is " << *it << '.';
    else{
      st.insert(*it * 2);
      st.insert(*it * 3);
      st.insert(*it * 5);
    }
  }
  return 0;
}
