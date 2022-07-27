// Problem: Counting Rooms
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1192
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
//iRatherFear
#pragma GCC optimize(3, "Ofast", "inline")
#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include <numeric>
#include<map>
#include<set>
#include<cstring>
#include<cmath>
#include<vector>
#define endl '\n'
#define c1(x) cout << x << endl;
#define c2(x, y) cout << x << ' ' << y << endl;
#define c3(x, y, z) cout << x << ' ' << y << ' ' << z << endl;
#define c4(a, b, c, d) cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
#define print(test_google, google_val) cout << "Case #" << test_google << ": " << google_val << endl;
#define yah cout << "YES" << endl;
#define nah cout << "NO" << endl;
#define line cout << endl;
#define INF (int) 1e18
#define loop(i, a, b) for(int i = a; i < b; i++)
#define frl(n) for(int i = 0; i < n; i++)
#define ONLINE_JUDGE 
#define int long long int
/*--------------------stl----------------------------------------------*/
const int kMod = 1e9 + 7;
const std::string Yes = "Yes";
const std::string No = "No";
#define umap unordered_map
#define vec(x) vector<x> 
#define vi vector<int>
#define vb vector<bool>
#define vc vector<char>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vvb vector<vector<bool>> 
#define vpi vector<pair<int, int>> 
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define pi pair<int, int>
#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define sumv(v) accumulate(all(v), Zero)
#define maxv(v) *max_element(all(v))
#define minv(v) *min_element(all(v))
#define sortv(v) sort(all(v))
#define revv(v) reverse(all(v))
using namespace std;
#define rng(x) x.begin(), x.end()
#define pb push_back
#define F first
#define S second
#define SZ(x) ((int)(x).size()) 
template<typename T>
istream&operator>>(istream&is,vector<T>&v){for(auto&it:v)is>>it;return is;}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.F << "," << P.S << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
#ifndef ONLINE_JUDGE 
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define db(...)
#endif
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
// vector<int> v;inline bool read(int n) {a.resize(n);for(int i = 0; i < n; i++)cin >> a[i];return true;}
int bitsn(int n){int bit = 0;while(n){n /= 2;bit++;}return bit;}
void maxi(int &a, int b){a = max(a, b);}
void mini(int &a, int b){a = min(a, b);}
void modi(int &n){n = (n % kMod);}
int sumn(int n){int s = 0;while(n){s += n % 10;n /= 10;}return s;}
int powre(int num, int pwr){if(pwr == 0){return 1;}int x = powre(num, pwr / 2);x = (x * x)% kMod;return pwr & 1? (x * num) % kMod: x;}
int firstn(int n){return n * (n + 1) / 2;}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void pre(){
    
}
 
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
 
int n, m;
vvc grid;
vvb visi;
void dfs(int i, int j) {
    db(i, j);
    if(i >= n or j >= m or i < 0 or j < 0 or grid[i][j] == '#' or visi[i][j]) {
        return;
    }
    db("V", i, j);
    visi[i][j] = true;
    loop(k, 0, 4) {
        dfs(i + dx[k], j + dy[k]);
    }
}
 
void solve(int tt){
    cin >> n >> m;
    grid = vvc(n, vc(m)); cin >> grid;
    visi = vvb(n, vb(m, false));
    
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == '.' and visi[i][j] == false) {
                db("G", i, j);
                dfs(i, j);
                cnt++;
            }
        }
    }
    
    c1(cnt)
}//Solve End
 
int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt = 1;
    pre();
    // cin >> tt;
    frl(tt){
        solve(i + 1);
    }
}
