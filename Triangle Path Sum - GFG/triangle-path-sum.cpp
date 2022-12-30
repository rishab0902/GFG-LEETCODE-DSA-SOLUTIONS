//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  //recursive
//   int f(int i, int j, vector<vector<int> > &triangle,int n) {
//   if(i==n-1) return triangle[i][j];
    
//   int down = triangle[i][j]+f(i+1,j,triangle,n);
//   int diagonal = triangle[i][j]+f(i+1,j+1,triangle,n);
  
//   return min(down, diagonal);
  
// }

  //memo
  
int f(int i, int j, vector<vector<int> > &triangle,int n, 
    vector<vector<int> > &dp) {
  
    if(dp[i][j]!=-1)
    return dp[i][j];
  
    if(i==n-1) return triangle[i][j];
    
    int down = triangle[i][j]+f(i+1,j,triangle,n,dp);
    int diagonal = triangle[i][j]+f(i+1,j+1,triangle,n,dp);
  
    return dp[i][j] = min(down, diagonal);
  
    }
  
int minimizeSum(int n, vector<vector<int>>& triangle) {
    vector<vector<int> > dp(n,vector<int>(n,0));
    
    for(int j=0;j<n;j++){
        dp[n-1][j] = triangle[n-1][j];
    }
    
    for(int i=n-2; i>=0; i--){
        for(int j=i; j>=0; j--){
            
            int down = triangle[i][j]+dp[i+1][j];
            int diagonal = triangle[i][j]+dp[i+1][j+1];
            
            dp[i][j] = min(down, diagonal);
        }
    }
    
    return dp[0][0];
        // Code here
    //     vector<vector<int> > dp(n,vector<int>(n,-1));
    // return f(0,0,triangle,n,dp);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends