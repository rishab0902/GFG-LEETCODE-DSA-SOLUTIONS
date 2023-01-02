//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int f(int ind,int arr[],int target,vector<vector<int>> &dp){
        if(target==0)return 1;
        if(ind==0)return (arr[0]==target);
        if(dp[ind][target]!=-1)return dp[ind][target];
        int nt=f(ind-1,arr,target,dp);
        int t=0;
        if(target>arr[ind]){
            t=f(ind-1,arr,target-arr[ind],dp);
        }
        return dp[ind][target]= nt||t;
    }
    int equalPartition(int n, int arr[])
    {
        // code here
        int k=0;
       for(int i=0;i<n;i++){
           k+=arr[i];
       }
        if(k&1)return false;
      k/=2;
    
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
        
        return prev[k];
        
    //     // int n=arr.size();
    //   vector<vector<int>> dp(10000,vector<int>(10000,-1));
    //   return f(n-1,arr,target,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends