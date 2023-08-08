//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
struct myComp {
    bool operator()(
        pair<int, int> &a,
        pair<int, int> &b)
    {
        if(a.first > b.first){
            return true;
        }else if(a.first > b.first){
            return false;
        }else{
            return a.second < b.second;
        }
        return true;
    }
};
class Solution
{
  public:
    vector<int> kTop(int a[], int n, int k) 
    { 
        //code here.
        // 
         vector<int>vis(10001,0);
        vector<int>ans;
        for(int i=0;i<n;i++){
            vis[a[i]]++;
            priority_queue<pair<int,int>>pq;
            for(int j=1;j<10001;j++){
                if(vis[j]!=0){
                    pq.push({vis[j],-1*j});
                }
            }
            int K=k;
            while(K && !pq.empty()){
                ans.push_back(-1*pq.top().second);
                pq.pop();
                K--;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
	long long t;
	
	cin >> t;
	
	while(t--){
	    long long n;
	    long long k;
	    cin >> n;
	    cin >> k;
	    int a[n];
	    for(long long i = 0;i<n;i++){
	        cin >> a[i];
	    }
	        Solution ob;
	        vector<int> ans;
	        ans=ob.kTop(a,n,k);
	        for(int i=0;i<ans.size();i++)
	        {
	        cout<<ans[i];
	        cout<<" ";
	        }
	        cout<<'\n';
	    }
	return 0;
}

// } Driver Code Ends