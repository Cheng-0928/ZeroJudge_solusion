#include <bits/stdc++.h>
#define int long long //TLE or MLE remove
#define f first
#define s second
#define Cheng0928 ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SIZE(a) signed(a.size())

using namespace std;

int run(string s){
    stack<int> stk, times;
    stringstream ss;
    ss.str(s);
    int n;
    ss >> n;
    stk.push(n);
    char c;
    while(ss >> c){


        if(c == '+') ss >> n, stk.push(n);
        else if(c == '*'){
            int sum = 0;
            while(!stk.empty()){
                sum+=stk.top();
                stk.pop();
            }
            ss >> n;
            stk.push(n);
            times.push(sum);
        }
    }
    int sum = 0;
    bool ok = 0;
    while(!stk.empty()){
        ok = 1;
        sum+=stk.top();
        stk.pop();
    }
    if(ok) times.push(sum);
    int ans = 1;
    while(!times.empty()){
        ans*=times.top();
        times.pop();
    }
    return ans;
}

int f(string s){
    stringstream ss;
    ss.str(s);
    int mins = 500, maxs = -500;
    while(getline(ss,s,',')){
        int n = run(s);
        mins = min(mins, n), maxs = max(maxs, n);
    }
    return maxs - mins;
}

void sol(){
    //freopen("cereal.in", "r", stdin);
    //freopen("cereal.out", "w", stdout);
    string s;
    cin >> s;
    stack<int> stk;
    for(int i = 0;i<SIZE(s);i++){
        if(s[i] == 'f') stk.push(i);
        else if(s[i] == ')'){
            int l = stk.top(), r = i;
            stk.pop();
            int n = f(s.substr(l+2, r-l+1-3));
            s.replace(l, r-l+1, to_string(n));
            i = l;
        }
    }
    cout << run(s) << '\n';



}

signed main()
{
    Cheng0928
    /*int t;
    cin >> t;
    while(t--)*/ sol();
    return 0;
}
