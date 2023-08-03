//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long sumBetweenTwoKth( long long arr[], long long n, long long K1, long long K2)
    {
        // Your code goes here
         priority_queue<long long,vector<long long>,greater<long long>> pq;
         long long ans=0;
	    for(int i=0;i<n;i++){
	        pq.push(arr[i]);
	    }
	    for(int i=0;i<K1;i++)pq.pop();
	    for(int i=K1 ;i<K2-1;i++){
	        ans+=pq.top();
	        pq.pop();
	    }
	    return ans;
	   // vector<int> ans;
	   // for(int i=0;i<k;i++){
	   //     ans.push_back(pq.top());
	   //     pq.pop();
	   // }
	   // return ans;
    }
};

//{ Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}

// } Driver Code Ends