//iRatherFear
// Problem: Dice Combinations
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1633
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int kMod = 1e9 + 7;
 
void solve(){
    int n; cin >> n;
    vector<int> dp(n + 1, 0);
    
    for(int i = 1; i <= n; i++) {
        if(i > 6) {
            int sm = 0;
            for(int j = i - 1; j >= i - 6; j--) {
                sm += dp[j];
                sm = sm % kMod;
            }
            dp[i] = sm;
        } else {
            int sum = 1;
            for(int j = i - 1; j > 0; j--) {
                sum += dp[j];    
            }
            dp[i] = sum;
        }
    }
    
    int ans = dp[n];
    cout << ans << endl;
}//Solve End
 
int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}
