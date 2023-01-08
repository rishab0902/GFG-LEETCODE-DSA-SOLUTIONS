//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
  	int findWaysUtil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp){
    
    if(ind == 0){
        if(target==0 && arr[0]==0)return 2;
        if(target==0 || arr[0]==target)return 1;
        return 0;
    }
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    int notTaken = findWaysUtil(ind-1,target,arr,dp);
    
    int taken = 0;
    if(arr[ind]<=target)
        taken = findWaysUtil(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= (notTaken + taken);
}
    int findTargetSumWays(vector<int>&arr ,int target) {
        //Your code here
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if((sum+target)%2!=0)return 0;
        target=(sum+target)/2;
        // cout<<target;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return findWaysUtil(n-1,target,arr,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends