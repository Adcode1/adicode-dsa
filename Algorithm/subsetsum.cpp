#include <bits/stdc++.h>
using namespace std;
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<bool>>dp(n,vector<bool>(k+1,0));
    for(int i=0;i<n;i++) dp[i][0]=true;
    dp[0][arr[0]]=true;
    for(int i=1;i<n;i++){
        for(int target=1;target<=k;target++){
            bool take=false;
            bool notake=dp[i-1][target];
            if(arr[i]<=target) take=dp[i-1][target-arr[i]];
            dp[i][target]=take|notake;
        }
    }
    return dp[n-1][k];
}
// src->https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION