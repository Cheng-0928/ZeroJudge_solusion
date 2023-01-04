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
    vector<int> server(n);vector<vector<int>> Q(n, vector<int>(m));
    for(auto &vec : Q){
        for(int &it : vec) cin >> it;
   }
   vector<int> ans(k, 0);
   for(int method = 0;method<k;method++){
        for(int &it : server) cin >> it;
        vector<vector<int>> c(m, vector<int>(m, 0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                c[server[i]][j]+=Q[i][j];
            }
        }
        for(int i = 0;i < m;i++){
            for(int j = 0;j<m;j++){
                if(i == j) ans[method]+=c[i][j];
                else if(c[i][j] <= 1000) ans[method]+=c[i][j]*3;
                else{
                    ans[method]+=1000*3;
                    ans[method]+=(c[i][j] - 1000) * 2;
                }
            }
        }
   }

   sort(ans.begin(), ans.end());
   cout << *ans.begin() << '\n';


}

signed main()
{
    Cheng0928
    /*int t;
    cin >> t;
    while(t--) */sol();
    return 0;
}
