#include <bits/stdc++.h>
#define int long long
#define X first
#define Y second
#define Cheng0928 ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define size(a) signed(a.size())

using namespace std;

void sol(){
    int k, q, r;
    cin >> k >> q >> r;
    vector<vector<char>> vec;
    vector<char> first(k);
    for(int i = 0;i<k;i++) cin >> first[i];
    vec.push_back(first);
    for(int i = 1;i<=q;i++){
        vector<char> per(k);
        for(int j = 0;j<k;j++){
            int p;
            cin >> p;
            per[p-1] = vec[i-1][j];
        }
        vec.push_back(per);

    }
    for(int i = 0;i<r;i++){
        for(int j = 1;j<=q;j++) cout << vec[j][i];
        cout << '\n';
    }
}

signed main()
{
    Cheng0928
    /*int t;
    cin >> t;
    while(t--) */sol();
    return 0;
}
