#include <bits/stdc++.h>
#define int long long
#define X first
#define Y second
#define Cheng0928 ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define size(a) signed(a.size())

using namespace std;

const int WOOD = 0, V = 1, H = 2;//木樁, 垂直, 水平
const int dx[4] = {0,0,-1,1};
const int dy[4] = {-1,1,0,0};
const int line_side[4] = {V, V, H, H};
int m, n, h;//height, weight
pair<int,int> nxt = {0,0};

int a[100][100][3];

bool vailed(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool near(int r, int c, int dir){
    c+=dx[dir];r+=dy[dir];
    while(vailed(c,r) && !a[r][c][WOOD]){
        c+=dx[dir];r+=dy[dir];
    }
    if(!vailed(c,r)) return 0;
    nxt = {c,r};
    return 1;
}

void line_oper(int x, int y, int t, int dir){
    if(t == 1) a[y][x][line_side[dir]] = 0;
    else {
        a[y][x][line_side[dir]] = 1;
        //cout << 1;
    }
    //cout << t;
}

int ept_cnt(){
    int ret = 0;
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++) ret+=(a[i][j][V] || a[i][j][H] || a[i][j][WOOD]);
    }
    return ret;
}

void oper(int r, int c, int t){
    for(int dir = 0;dir < 4; dir++){
        //pair<int, int> nxt
        if(near(r, c, dir)){
            for(int x = c+dx[dir], y = r+dy[dir];nxt != make_pair(x,y) && vailed(x,y); x+=dx[dir], y+=dy[dir]){
                line_oper(x, y, t, dir);
            }
        }
    }
    if(t == 1){
        a[r][c][WOOD] = 0;
        a[r][c][V] = 0;
        a[r][c][H] = 0;
    }
    else a[r][c][WOOD] = 1;
    //return ept_cnt();
}

void sol(){
    int ans = 0;
    //int m,n,h;
    cin >> m >> n >> h;
    while(h--){
        int r, c, t;
        cin >> r >> c >> t;
        //cout << r << c << t << '\n';
        oper(r, c, t);
        //cout << a[0][1][V];
        ans = max(ans, ept_cnt());
        //cout << ans << endl;
    }
    cout << ans << '\n' << ept_cnt() << '\n';

}

signed main()
{
    Cheng0928
    /*int t;
    cin >> t;
    while(t--) */sol();
    return 0;
}
