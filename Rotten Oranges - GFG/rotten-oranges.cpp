//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    // int drow[] = {-1, 0, +1, 0};
    // int dcol[] = {0, 1, 0, -1}; 
    // //Function to find minimum time required to rot all oranges. 
    // void dfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& vis,int n,int m){
    //     vis[r][c] = 2;
    //     for(int i=0;i<4;i++){
    //             int nrow=r+drow[i];
    //             int ncol=c+dcol[i];
    //             if((nrow>=0 && nrow<n) && (ncol>=0 && ncol<m)){
    //                 if(vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
    //               dfs(nrow,ncol,grid,vis,n,m);
    //                 }
    //             }
    //         // mark as rotten
            
    // }
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cntf=0;
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    
                }
                else if(grid[i][j]==1)cntf++;
                else continue;
            }
        }
        int cnt=0;
        int tm=0;
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, 1, 0, -1}; 
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            tm=max(tm,t);
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if((nrow>=0 && nrow<n) && (ncol>=0 && ncol<m)){
                    if(vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                  q.push({{nrow,ncol},t+1});
                  vis[nrow][ncol]=2;
                  cnt++;
                    }
                }
            
            
        }
        }
        if(cntf==cnt)return tm;
        return -1;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends