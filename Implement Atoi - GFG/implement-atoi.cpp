//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        int sum=0;
        int n=s.size();
        int i=0;
        if(s[0]=='-')i=1;
       for(i;i<n;i++){
           if(s[i]>=48 &&s[i]<58){
            //   cout<<s[i]<<endl;
            //   cout<<s[i]-'0'<<endl;
              
               sum=sum*10+(s[i]-'0');
           }
           else return -1;
           
       }
       if(s[0]=='-')return -1*sum;
       return sum;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends