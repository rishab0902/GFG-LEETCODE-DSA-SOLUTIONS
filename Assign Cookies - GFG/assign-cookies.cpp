//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxChildren(int N, int M, vector<int> &greed, vector<int> &sz) {
        long sum=0;
        sort(greed.begin(),greed.end());
        sort(sz.begin(),sz.end());
        int k=0;
        int cnt=0;
        for(int i=0;i<N;i++){
            if(k<M){
               while(greed[i]>sz[k] && k<M-1){
                   k++;
               }
                  if(greed[i]<= sz[k]){cnt++;
                   k++;
               }
               else return cnt;
                   
            }
            else return cnt;
        }
        // code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;

        vector<int> greed(N), sz(M);
        for (int i = 0; i < N; i++) {
            cin >> greed[i];
        }
        for (int i = 0; i < M; i++) {
            cin >> sz[i];
        }
        Solution obj;
        cout << obj.maxChildren(N, M, greed, sz) << endl;
    }
    return 0;
}
// } Driver Code Ends