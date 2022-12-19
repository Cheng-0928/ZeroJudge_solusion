#include <bits/stdc++.h>
#define int long long
#define X first
#define Y second
#define Cheng0928 ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//#define size(a) signed(a.size());

using namespace std;

vector<int> a{1,1,1,1}, b{3}, c{2,2}, d{1,3}, e{1,2,2};
int R,C,n, ept;
int x_pos[50];
vector<int> block_type(char t){

    if(t == 'A') return a;
    if(t == 'B') return b;
    if(t == 'C') return c;
    if(t == 'D') return d;
    if(t == 'E') return e;
}

bool push_block(char t, int y){
    vector<int> block;
    block = block_type(t);
    int sz = block.size() - 1;int i = 0;
    int x = 0;
    while(i <= sz){
        //cout << x_pos[i] << '\n';
        x = max(x, x_pos[y + i] + block[i]);
        i++;
    }
    //cout << x << ' ';
    if(x > C) return 0;
    i = 0;
    for(i;i<=sz;i++){
        x_pos[y + i] = x;
        ept-=block[i];
    }
    return 1;
}

void sol(){
    cin >> R >> C >> n;
    ept = R * C;int trash = 0;
    while(n--){
        char t;int y;
        cin >> t >> y;
        if(!push_block(t,y)) trash++;
        //else cout << "true\n";
    }
    cout << ept << ' ' << trash << '\n';
}

signed main()
{
    Cheng0928
    /*int t;
    cin >> t;
    while(t--) */sol();
    return 0;
}
