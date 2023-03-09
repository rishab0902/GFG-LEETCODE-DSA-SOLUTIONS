//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int editDistance(string S1, string S2) {
        // Code here
         int n = S1.size();
    int m = S2.size();
    
    vector<int> prev(m+1),cur(m+1);
    
    for(int j=0;j<=m;j++){
        prev[j] = j;
    }
    
    for(int i=1;i<n+1;i++){
        cur[0]=i;
        for(int j=1;j<m+1;j++){
            if(S1[i-1]==S2[j-1])
               cur[j] = prev[j-1];
            
            else cur[j] = 1+min(prev[j-1],min(prev[j],cur[j-1]));
        }
        prev=cur;
    }
    
    return prev[m];
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends