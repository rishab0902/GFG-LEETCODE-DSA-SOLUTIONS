//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int f(int i,int j,string &s,string &t,vector<vector<int>> &dp){
        if(i<0||j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==t[j])return 1+f(i-1,j-1,s,t,dp);
        
        dp[i][j]= (0+max(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp)));
    }
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        // int dp[x][y];
        // vector<vector<int>> dp(x,vector<int>(y,-1));
           vector<vector<int>> dp(x+1,vector<int>(y+1,-1));
        for(int i=0;i<=x;i++){
        dp[i][0] = 0;
    }
    for(int j=0;j<=y;j++){
        dp[0][j] = 0;
    }
      
             
   for(int i=1;i<=x;i++){
       for(int j=1;j<=y;j++){
           if(s1[i-1]==s2[j-1]){
               dp[i][j]=1+dp[i-1][j-1];
           }
           else 
           dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
       }
   }
   return dp[x][y];
        // return f(x-1,y-1,s1,s2,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends