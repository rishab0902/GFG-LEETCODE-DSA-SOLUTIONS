//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
       int x;
        for(int i=0;i<n;i++){
              if(i&1)x=0;
              else x=1;
              
            for(int j=0;j<=i;j++){
              
            cout<<x<<" ";
            x=!x;
        }
        cout<<endl;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends