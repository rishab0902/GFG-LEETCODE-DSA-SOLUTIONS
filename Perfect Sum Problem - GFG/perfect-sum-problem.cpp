//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	long M=1e9+7;
	int findWaysUtil(int ind, int target, int arr[], vector<vector<int>> &dp){
    
    if(ind == 0){
        if(target==0 && arr[0]==0)return 2;
        if(target==0 || arr[0]==target)return 1;
        return 0;
    }
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    int notTaken = findWaysUtil(ind-1,target,arr,dp);
    
    int taken = 0;
    if(arr[ind]<=target)
        taken = findWaysUtil(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= (notTaken + taken)%M;
}
	int rf(int ind,int arr[],int sum,vector<vector<int>> &dp){
	    if(sum==0)return 1;
	    if(ind==0)return (arr[0]==sum);
	    if(dp[ind][sum]!=-1)
            return dp[ind][sum];
	    int npick=rf(ind-1,arr,sum,dp);
	    int pick=0;
	    if(arr[ind]<=sum)
	        pick=rf(ind-1,arr,sum-arr[ind],dp);
	    
	    return dp[ind][sum]=npick+pick;
	}
	int perfectSum(int num[], int n, int k)
	{
	   // vector<vector<int>> dp(n,vector<int>(sum+1,0));
	     vector<vector<int>> dp(n,vector<int>(k+1,-1));
    
    // for(int i=0; i<n; i++){
    //     dp[i][0] = 1;
    // }
    
    // if(num[0]<=k)
    //     dp[0][num[0]] = 1;
    
    // for(int ind = 1; ind<n; ind++){
    //     for(int target= 1; target<=k; target++){
            
    //         int notTaken = dp[ind-1][target];
    
    //         int taken = 0;
    //             if(num[ind]<=target)
    //                 taken = dp[ind-1][target-num[ind]];
        
    //         dp[ind][target]= (notTaken%M + taken%M)%M;
    //     }
    // }
    
    // return dp[n-1][k]%M;
	    return findWaysUtil(n-1,k,num,dp)%M;
        // return rf(n-1,arr,sum,dp);
        
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends