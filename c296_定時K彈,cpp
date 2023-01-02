#include <bits/stdc++.h>
#define int long long
#define X first
#define Y second
#define Cheng0928 ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define size(a) signed(a.size())

using namespace std;

void sol(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> lucky(n+1, 0);
    for(int i = n - k + 1;i<=n;i++){
        lucky[i] = (lucky[i-1] + m)%i;
    }
    cout << lucky[n] + 1 << '\n';

}

signed main()
{
    Cheng0928
    /*int t;
    cin >> t;
    while(t--)*/ sol();
    return 0;
}
