//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int n, vector<int> &bills) {
        // sort(bills.begin(),bills.end());
        int c5=0,c10=0,c20=0;
        if(bills[0]!=5)return false;
        c5=1;
        for(int i=1;i<n;i++){
            if(bills[i]==5)c5++;
            else if(bills[i]==10){
                if(c5>0){
                    c10++;
                     c5--;
                    // contine;
                   
                }
                else return false;
            }
            else{
                if(c5>=3 || (c10>0 && c5>0)){
                    if(c10 && c5){
                        c10--;
                        c5--;
                        c20++;
                    }
                    else {
                        c5-=3;
                        c20++;
                    }
                }
                else return false;
            }
        }
        return true;
        // code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends