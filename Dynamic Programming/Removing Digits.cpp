//iRatherFear
// Problem: Removing Digits
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1637
#include<bits/stdc++.h>
#define INF (int) 1e18
#define int long long int
const int kMod = 1e9 + 7;
using namespace std;


int fun(int n, vector<int> &dp) {
    int &cur_ans = dp[n];

    if(cur_ans != -1) {
        return cur_ans;
    }

    if(n < 0) {
        return INF;
    }
    if(n == 0) {
        return 0;
    }
    
    cur_ans = INF;
    int temp = n;
    while(temp) {
        int digit = temp % 10;
        if(digit != 0) {
            cur_ans = min(cur_ans, 1 + fun(n - digit, dp));
        }
        temp /= 10;
    }
    
    return cur_ans;
}

int fun2(int n) {
    vector<int> dp(n + 1);

    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        int temp = i;
        int cur_ans = INF;
        while(temp) {
            int digit = temp % 10;
            if(digit != 0) {
                cur_ans = min(cur_ans, 1 + dp[i - digit]);
            }
            temp /= 10;
        }
        dp[i] = cur_ans;
    }

    return dp[n];
}

void solve(){
    int n; cin >> n;

    //Top down
    // vector<int> dp(n + 1, -1);
    // cout << fun(n, dp) << endl;

    //Bottom up
    cout << fun2(n) << endl;
}//Solve End

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
