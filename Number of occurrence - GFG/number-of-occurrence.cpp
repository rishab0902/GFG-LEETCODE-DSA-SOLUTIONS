//{ Driver Code Starts

#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	     vector<int> ans;
        //  int n=arr.size();
    int y=-1;
    
    int left=0,right=n-1;
   while(left<=right){
       int mid=(right+left)/2;
       if(arr[mid]==x){
           y=mid;
           break;
       }
       else if(arr[mid]>x) right=mid-1;
       else left=mid+1;
       
   }
   int z=0;
//    cout<<y<<endl;
   if(y!=-1){
       z=1;
   }
   left=y;
   right=y;
   while(left >0 && arr[left-1]==x){
       left--;
       z++;
   }
    while(right<=n-2 && arr[right+1]==x){
       right++;
       z++;
   }
//   ans.push_back(left);
//   ans.push_back(right);
//   return ans;
//   }
//   return {-1, -1
return z;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends