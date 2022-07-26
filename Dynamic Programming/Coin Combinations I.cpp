//iRatherFear// Problem: Coin Combinations I
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1635
#include<bits/stdc++.h>
#define int long long int
const int kMod = 1e9 + 7;
using namespace std;

void solve(){
    int n, x; cin >> n >> x;
    vector<int> v(n); 

    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    vector<int> dp(x + 1);
    for(int i = 1; i <= x; i++) {
        int sm = 0;
        for(auto itr: v) {
            if(itr > i) {
                break;
            } 
            if(itr == i) {
                sm++;
            }
            sm += dp[i - itr];
        }
        dp[i] = sm % kMod;
    }
    
    int ans = dp[x];
    cout << ans << endl;
}//Solve End

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
