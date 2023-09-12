//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int isPerfectNumber(long long N) {
        // long long sum=0;
        // vector<long long> pred(N,0);
        // for(int i=0;i<Math.sqrt(N);i++){
        //     for(int j=i;j<N;j+=i){
        //         if(N%j==0 && pred[j]==1){
        //             sum+=j;
        //             pred[j]=1;
        //         }
        //     }
        // }
        // // cout<<sum<<endl;
        // if(sum==N)return 1;
        // return 0;
    long long i; long long sum = 1;
        if(N<=1)
        return 0;
        for(i=2;i*i<N;i++)
        {
            if(N%i==0)
            {
            sum += i;
            sum += (N/i);
            }
        }
       return sum==N;
        // code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends