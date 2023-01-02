//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int k=0;
	    for(int i=0;i<n;i++)k+=arr[i];
	    
	    
	     vector<bool> prev(k+1,false);
	     prev[0] = true;
        
        if(arr[0]<=k)
            prev[arr[0]] = true;
	    for(int ind = 1; ind<n; ind++){
            vector<bool> cur(k+1,false);
            cur[0] = true;
            for(int target= 1; target<=k; target++){
                bool notTaken = prev[target];
        
                bool taken = false;
                    if(arr[ind]<=target)
                        taken = prev[target-arr[ind]];
            
                cur[target]= notTaken||taken;
            }
            prev = cur;
        }
        int minm=INT_MAX;
        for(int i=0;i<=k/2;i++){
            if(prev[i]==1){
                minm=min(minm,abs((k-i)-i));
            }
            
        }
        return minm;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends