//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
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
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends