//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int f(int i, int j,int m, vector<vector<int> > &matrix, 
    vector<vector<int> > &dp) {
  
  if(j<0 || j>=m)
        return -1e9;
    if(i==0)
        return matrix[0][j];
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    int up = matrix[i][j] + f(i-1,j,m,matrix,dp);
    int leftDiagonal = matrix[i][j] + f(i-1,j-1,m,matrix,dp);
    int rightDiagonal = matrix[i][j] + f(i-1,j+1,m,matrix,dp);
    
    return dp[i][j]= max(up,max(leftDiagonal,rightDiagonal));
  
    }
    int maximumPath(int n, vector<vector<int>> matrix)
    {
    int m = matrix[0].size();
    
    vector<vector<int>> dp(n,vector<int>(m,-1));
    
    int maxi = INT_MIN;
    
    for(int j=0; j<m;j++){
        int ans = f(n-1,j,m,matrix,dp);
        maxi = max(maxi,ans);
    }
    
    return maxi;

        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends