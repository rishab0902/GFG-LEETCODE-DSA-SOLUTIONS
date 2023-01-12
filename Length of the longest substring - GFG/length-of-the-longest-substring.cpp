//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string s){
        //code
                 
        int l=0, r= 0, ans =0;

        int count[256]={0};
        
        while(r<s.size()){
            
            count[s[r]]++;
            
            while(count[s[r]]>1){
                count[s[l]]--;
                l++;
            }ans = max(ans, r-l+1);
            r++;
        }
return ans;  
        
        
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends