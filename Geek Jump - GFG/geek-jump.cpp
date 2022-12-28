//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int fjump(vector<int>& height, int n,vector<int> &dp){
      if(n==0)return 0;
      if(dp[n]!=-1)return dp[n];
      int right=INT_MAX;
      int left=fjump(height,n-1,dp)+abs(height[n]-height[n-1]);
      
      if(n>1) right=fjump(height,n-2,dp)+abs(height[n]-height[n-2]);
      
      return dp[n]=min(left,right);
  }
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n,-1);
        return fjump(height,n-1,dp);
     
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends