//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long maximumProfit(vector<long long>&prices, int n, int fee) {
        // Code here
        vector<long long> ahead (2,0);
    vector<long long> cur(2,0);
    
    //base condition
    ahead[0] = ahead[1] = 0;
    
    long long profit;
    
    for(int ind= n-1; ind>=0; ind--){
        for(int buy=0; buy<=1; buy++){
            if(buy==0){// We can buy the stock
                profit = max(ahead[0], (-prices[ind] + ahead[1]-(long long)fee));
            }
    
            if(buy==1){// We can sell the stock
                profit = max(0+ahead[1], prices[ind] + ahead[0]);
            }
            cur[buy]  = profit;
        }
        
        ahead = cur;
    }
    return cur[0];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        int fee; cin>>fee;
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n, fee)<<"\n";
    }
    return 0;
}
// } Driver Code Ends