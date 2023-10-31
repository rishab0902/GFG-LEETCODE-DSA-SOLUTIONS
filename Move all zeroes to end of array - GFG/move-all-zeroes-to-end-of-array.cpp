//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    int l=0;
	    for(int i =0;i<n;i++){
	        if(arr[i]){
	           arr[l]=arr[i];
	           l++;
	           
	        }
	        
	    }
	    for(int i=l;i<n;i++){
	        arr[i]=0;
	    }
	    // code here
	   // int l=0,r=n-1;
	   // while(l<=r){
	   //     while(arr[l]!=0){
	   //         l++;
	   //     }
	   //     if(l>=n-1)break;
	   //     while(arr[r]==0)r--;
	   //     if(r<=0)break;
	   //    // cout<<l<<" "<<r<<endl;
	   //     if(l<r)
	   //     swap(arr[l],arr[r]);
	   //     r--;
	   //     l++;
	   
	        
	   // }
	}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.pushZerosToEnd(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends