//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int K, int N, int prices[]) {
        // int n=prices.size();
                                            
 vector<vector<int>> dp(N+1,vector<int>(2*K+1,0));
    
    for(int ind = N-1; ind>=0; ind--){
       for(int tran=2*K-1;tran>=0;tran--){
           if(tran%2==0)
                    dp[ind][tran] = max(0+dp[ind+1][tran], -prices[ind] + dp[ind+1][tran+1]);
              else
                    dp[ind][tran] = max(0+dp[ind+1][tran],prices[ind] + dp[ind+1][tran+1]);
            }
        }
    
    
    return dp[0][0];
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends