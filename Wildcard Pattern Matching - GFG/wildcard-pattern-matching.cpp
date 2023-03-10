//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
  bool isAllStars(string & S1, int i) {

  // S1 is taken in 1-based indexing
  for (int j = 1; j <= i; j++) {
    if (S1[j - 1] != '*')
      return false;
  }
  return true;
}
int f(int i,int j,string &pattern,string &str,vector<vector<int>> &dp){
    if(i<0 && j<0)return true;
    if(i<0 &&j>0)return false;
    if(j<0 && i>=0){
        for(int ii=0;ii<i;ii++){
            if(pattern[i]!='*')return false;
        }
        return true;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    if(pattern[i]==str[j] || pattern[i]=='?'){
        return dp[i][j]=f(i-1,j-1,pattern,str,dp);
    }
    if(pattern[i]=='*'){
        return dp[i][j]=f(i-1,j,pattern,str,dp) | f(i,j-1,pattern,str,dp);

    }
    return dp[i][j]=false;
}
/*You are required to complete this method*/
    int wildCard(string S1,string S2)
    {
  
  int n = S1.size();
  int m = S2.size();

  vector < vector < bool >> dp(n + 1, vector < bool > (m, false));

  dp[0][0] = true;

  for (int j = 1; j <= m; j++) {
    dp[0][j] = false;
  }
  for (int i = 1; i <= n; i++) {
    dp[i][0] = isAllStars(S1, i);
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {

      if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?')
        dp[i][j] = dp[i - 1][j - 1];

      else {
        if (S1[i - 1] == '*')
          dp[i][j] = dp[i - 1][j] || dp[i][j - 1];

        else dp[i][j] = false;
      }
    }
  }

  return dp[n][m];
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends