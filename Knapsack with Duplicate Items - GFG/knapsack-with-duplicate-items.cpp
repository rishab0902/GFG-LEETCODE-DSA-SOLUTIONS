//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int n, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(n,vector<int> (W+1,0));
      for(int i=wt[0];i<=W;i++)
          dp[0][i]=(i/wt[0])*val[0];
      for(int ind=1;ind<n;ind++){
          for(int cap=0;cap<=W;cap++){
             int nottake=0+dp[ind-1][cap];
             int take =INT_MIN;
             if(wt[ind]<=cap){
                 take=val[ind]+dp[ind][cap-wt[ind]];
             }
             dp[ind][cap]=max(nottake,take);
          }
      }
      return dp[n-1][W];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends