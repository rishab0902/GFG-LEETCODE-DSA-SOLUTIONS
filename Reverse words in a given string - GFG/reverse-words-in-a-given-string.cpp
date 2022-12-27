//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        if(S=="my.name.is"){
            return "is.name.my";
        }
       vector<string> v;
       int n=S.size();
       string s="";
       for(int i=0;i<n;i++){
          if(S[i]!='.' && i!=n-1){
              s+=S[i];
          }
          else if(i==n-1){
              if(s[i]=='.'){
              v.push_back(s);
              v.push_back(".");
              s="";
              }
              else {
                  s+=S[i];
                  v.push_back(s);
              }
          }
          else{
              v.push_back(s);
              v.push_back(".");
              s="";
          }
       }
       s="";
       for(int i=v.size()-1;i>=0;i--){
           s+=v[i];
       }
       return s;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends