//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  //recursive soln;
  int f(int day,int last,vector<vector<int>>& points){
      if(day==0){
          int maxi=0;
          for(int i=0;i<3;i++){
              if(i!=last)
              maxi=max(maxi,points[0][i]);
          }
          return maxi;
      }
      int maxi=0;
        for(int i=0;i<3;i++){
              if(i!=last){
                  int point=points[day][i]+f(day-1,i,points);
              maxi=max(maxi,point);
              }
          }
          return maxi;
  }
    // memoization
   int f(int day,int last,vector<vector<int>>& points,vector<vector<int>>& dp){
      if(day==0){
          int maxi=0;
          for(int i=0;i<3;i++){
              if(i!=last)
              maxi=max(maxi,points[0][i]);
          }
          return maxi;
      }
      if(dp[day][last]!=-1)return dp[day][last];
      int maxi=0;
        for(int i=0;i<3;i++){
              if(i!=last){
                  int point=points[day][i]+f(day-1,i,points,dp);
              maxi=max(maxi,point);
              }
          }
          dp[day][last]=maxi;
          return dp[day][last];
  }

  
    int maximumPoints(vector<vector<int>>& points, int n) {
           vector < vector < int > > dp(n, vector < int > (4, 0));

  dp[0][0] = max(points[0][1], points[0][2]);
  dp[0][1] = max(points[0][0], points[0][2]);
  dp[0][2] = max(points[0][0], points[0][1]);
  dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

  for (int day = 1; day < n; day++) {
    for (int last = 0; last < 4; last++) {
      dp[day][last] = 0;
      for (int task = 0; task <= 2; task++) {
        if (task != last) {
          int activity = points[day][task] + dp[day - 1][task];
          dp[day][last] = max(dp[day][last], activity);
        }
      }
    }

  }

  return dp[n - 1][3];
        // vector<vector<int>> dp(n,vector<int>(4,-1));
        // return f(n-1,3,points,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends