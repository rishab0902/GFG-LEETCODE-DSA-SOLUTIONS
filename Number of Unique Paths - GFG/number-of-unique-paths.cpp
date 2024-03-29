//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //combination way;
    // int NumberOfPath(int a, int b)
    // {
    //   int n= a+b-2;
    //   int r=b-1;
    //   int result=1;
    //   int j=1;
    //   for(int i=0;i<r;i++){
    //       result=result*(n-i)/j;
    //       j++;;
    //   }
    //   return result;
    // /}
    //Function to find total number of unique paths.
    
    //recursion
//      int f(int i,int j) {
// if(i==0&& j==0) return 1;
// if(i<0 || j<0) return 0;
// int up = f(i-1,j);
// int left = f(i,j-1);
// return up+left;
// }

//memoization;
 int f(int i,int j,vector<vector<int>> &dp) {
if(i==0&& j==0) return 1;
if(i<0 || j<0) return 0;
if(dp[i][j]!=-1)return dp[i][j];
int up = f(i-1,j,dp);
int left = f(i,j-1,dp);
return dp[i][j]=up+left;
}
    int NumberOfPath(int m, int n)
    {
      int dp[m][n];
        for(int i=0; i<m ;i++){
      for(int j=0; j<n; j++){
          
          //base condition
          if(i==0 && j==0){
              dp[i][j]=1;
              continue;
          }
          
          int up=0;
          int left = 0;
          
          if(i>0) 
            up = dp[i-1][j];
          if(j>0)
            left = dp[i][j-1];
            
          dp[i][j] = up+left;
      }
  }
  
  return dp[m-1][n-1];

    //     vector<vector<int>> dp(a,vector<int>(b,-1));
    // return f(a-1,b-1,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends