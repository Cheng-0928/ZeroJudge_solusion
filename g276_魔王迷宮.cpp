#include <bits/stdc++.h>
#define int long long
#define X first
#define Y second
#define Cheng0928 ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n,m,k;
const int X = 1, Y = 2, S = 3, T = 4, out = 5;
/*struct boss{
    int X;
    int Y;
    int S;
    int T;
    bool out;
};*/

bool check_out(int x, int y){
    return (x < m && y < n) && (x >= 0 && y >= 0);
}

void sol(){
    //int n,m,k;
    cin >> n >> m >> k;
    //cout << n << m;
    int tmp = n;
    n = m;m = tmp;
    vector<vector<int>> mp(n+2, vector<int>(m+2, 0));
    vector<vector<int>> bosses(k, vector<int>(6, 0));
    int b_cnt = k, ans = 0;
    for(int i = 0;i<k;i++){
        cin >> bosses[i][X] >> bosses[i][Y] >> bosses[i][S] >> bosses[i][T];
        if(check_out(bosses[i][X], bosses[i][Y])) bosses[i][out] = 0;
        else{
            b_cnt--;bosses[i][out] = 1;
        }
        //cout << bosses[i][X] << ' ' << bosses[i][Y] << ' ' << bosses[i][out] << '\n';
    }

    while(b_cnt){
        vector<pair<int,int>> record;
        for(int i = 0;i<k;i++) if(!bosses[i][out]) mp[bosses[i][Y]][bosses[i][X]]++;
        for(int i = 0;i < k;i++){

            if(!bosses[i][out]){
                //mp[bosses[i][Y]][bosses[i][X]]++;
                bosses[i][X] += bosses[i][S];
                bosses[i][Y] += bosses[i][T];
                if(!check_out(bosses[i][X], bosses[i][Y])){
                    bosses[i][out] = 1;
                    b_cnt--;
                    //continue;
                }
                else if(mp[ bosses[i][Y] ][ bosses[i][X] ]){
                    b_cnt--;
                    bosses[i][out] = 1;
                    record.push_back({bosses[i][X], bosses[i][Y]});
                }
            }
            //cout << bosses[i][X] << ' ' << bosses[i][Y] << ' ' << bosses[i][out]  << ' ' <<  i << '\n';

        }
        for(int i = 0;i<((signed)record.size());i++){
            mp[ record[i].second ][ record[i].first ] = 0;
        }
    }

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++) ans+=(mp[i][j] > 0);
        //cout << '\n';
    }
    cout << ans << '\n';

}

signed main()
{
    Cheng0928
    /*int t;
    cin >> t;
    while(t--)*/ sol();
    return 0;
}
