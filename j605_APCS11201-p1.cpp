#include <bits/stdc++.h>
#define int long long
#define X first
#define Y second
#define Cheng0928 ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define size(a) signed(a.size())

using namespace std;

void sol(){
    int k;
    cin >> k;
    vector<pair<int,int>> scores;
    int failed = 0;
    for(int i = 0;i<k;i++){
        int t, s;
        cin >> t >> s;
        if(s == -1) failed++;
        else scores.push_back({s, -t});
    }
    sort(scores.begin(), scores.end());
    auto it = prev(scores.end());
    cout << (it->X - k - failed*2 < 0 ? 0 : it->X - k - failed*2) << ' ' << -(it->Y) << '\n';
}

signed main()
{
    Cheng0928
    /*int t;
    cin >> t;
    while(t--) */sol();
    return 0;
}
