#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define pf push_front
#define pb push_back
#define F first
#define S second
#define loop(i, m, n) for (int i = m; i < n; i++)
#define arep(i, v) for (auto i : v)
#define all(x) (x).begin(), (x).end()
#define yeah cout << YES << endl;
#define noi cout << NO << endl;

using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
void solve() {
  // TODO: Implement the solution
  ll n;cin>>n;
  ll arr[n];
  ll sum=0;
  for(ll i=0;i<n;i++){
    cin>>arr[i];sum+=arr[i];
  } 
  vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
    // dp[i][j] --> interval i to main max difference from starting person and next person
    // base case
    for(ll i=0;i<n;i++){
        dp[i][i]=arr[i];
    }
    // transition
    for(ll i=n-1;i>=0;i--){
        for(ll j=i+1;j<n;j++){
        dp[i][j]=max(arr[i]-dp[i+1][j],arr[j]-dp[i][j-1]);
        }
    }
    ll diff=dp[0][n-1] ;
    ll ans=(sum+diff)/2;
    cout << ans << endl;

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t=1;
  while (t--) {
    solve();
  }
}