//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        //code here
        //         vector<int> ans;
        //         // vector<int> emp;
	   	   // 	queue<int> q;
	   	   // 	int v=n;
	   	   // 	vector<int> indegree(v,0);
	   	   // 	for(int i=0;i<m;i++){
	   	   // 	    indegree[prerequisites[i][0]]++;
	   	   // 	}
	   	   // 	for(int i=0;i<n;i++){
	   	   // 	  //  cout<<indegree[i]<<endl;
	   	   // 	    if(indegree[i]==0){
	   	   // 	        q.push(i);
	   	   // 	    }
	   	   // 	}
	   	   // 	while(!q.empty()){
	   	   // 	    int node=q.front();
	   	   // 	    q.pop();
	   	   // 	    ans.push_back(node);
	   	    	    
	   	   // 	    for(int i=0;i<m;i++){
	   	   // 	        if(prerequisites[i][1]==node){
	   	   // 	            int it=prerequisites[i][0];
	   	   // 	          //  cout<<it<<endl;
	   	   // 	            indegree[it]--;
	   	   // 	            if(indegree[it]==0)q.push(it);
	   	    	            
	   	   // 	        }
	   	   // 	    }
	   	    	        
	   	   // 	    }
	   	    	  //  for(int i=0;i<ans.size();i++){
	   	    	  //      cout<<ans[i]<<" ";
	   	    	        
	   	    	  //  }
	   	    	  //  cout<<endl;
	   	   // 	   if(ans.size()==n)return ans;
	   	   // return {};
	   	   int V=n;
	   	    	  vector<int> adj[V];
		for (auto it : prerequisites) {
			adj[it[1]].push_back(it[0]);
		}



		int indegree[V] = {0};
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		vector<int> topo;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			topo.push_back(node);
			// node is in your topo sort
			// so please remove it from the indegree

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		if (topo.size() == V) return topo;
		return {};
	   	   

    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends