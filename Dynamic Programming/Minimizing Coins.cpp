//iRatherFear
// Problem: Minimizing Coins
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1634
 
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int kMod = 1e9 + 7;
const int INF = 1e18;
 
void solve(){
    int n, x; cin >> n >> x;
    vector<int> v(n); 
 
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    vector<int> dp(x + 1, INF);
    dp[0] = 0;
    
    sort(v.begin(), v.end());
    for(int i = 1; i <= x; i++) {
        for(auto itr: v) {
            if(itr > i) {
                break;
            } else if(itr == i) {
                dp[i] = 1;
            } else {
                dp[i] = min(dp[i], dp[i - itr] + 1);
            }
        }
    }
    
    int ans;
    if(dp[x] == INF) {
        ans = -1;
    } else {
        ans = dp[x];
    }
    
    cout << ans << endl;
}//Solve End
 
int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
