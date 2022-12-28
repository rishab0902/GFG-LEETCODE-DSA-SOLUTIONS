//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> vect, long long n, long long x){
         long long l=0,r=n-1,ans=-1;

        while(l<=r){

            long long mid =(l+r)/2;

            if(vect[mid]==x) return mid;

            if(vect[mid]>x) r=mid-1;

            else {

                ans=l;

                l=mid+1;

            }

        }

        return ans;

    }
        
        // Your code here
        
    // }
};


//{ Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}
// } Driver Code Ends