//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
       private:
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<int>> &mat,int delrow[],int delcol[]){
        vis[row][col]=1;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<4;i++){
            int nrow =row +delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && mat[nrow][ncol]==1 ){
                dfs(nrow,ncol,vis,mat,delrow,delcol);
            }
        }
    }
  public:

    int numberOfEnclaves(vector<vector<int>> &mat) {
         int n=mat.size();
        int m=mat[0].size();
        // Code here
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        vector<vector<int>> vis(n,vector<int>(m,0));
        int res=0;
        for(int j=0;j<m;j++){
            if(!vis[0][j]&&mat[0][j]==1){
                dfs(0,j,vis,mat,delrow,delcol);
                res++;
            }
            if(!vis[n-1][j] && mat[n-1][j]==1){
                 dfs(n-1,j,vis,mat,delrow,delcol);
                 res++;
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0]&&mat[i][0]==1){
                dfs(i,0,vis,mat,delrow,delcol);
                res++;
            }
            if(!vis[i][m-1] && mat[i][m-1]==1){
                 dfs(i,m-1,vis,mat,delrow,delcol);
                 res++;
            }
        }
        // cout<<res<<endl;
        
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] && mat[i][j]==1)mat[i][j]=0;
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1)cnt++;
            }
        }
        return cnt;
        // return mat;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends