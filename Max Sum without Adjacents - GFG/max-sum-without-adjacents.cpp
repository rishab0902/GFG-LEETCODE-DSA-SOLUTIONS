//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    int dp[n];
	    dp[0]=arr[0];
	    int pick;
	   // int m=INT_MIN;
	    
	    for(int i=1;i<n;i++){
	        if(i-2>=0){
	        pick=arr[i]+dp[i-2];
	        }
	        else{ pick=arr[i];
	        }
	       int npick=dp[i-1];
	        dp[i]=max(pick,npick);
	    }
	    return dp[n-1];
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends