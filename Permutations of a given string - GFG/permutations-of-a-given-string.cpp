//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void solve(string nums, set<string> &ans,int index){
    if(index>=nums.size()){
        ans.insert(nums);
        return;
    }
    for(int j=index;j<nums.size();j++){
        swap(nums[index],nums[j]);
        solve(nums,ans,index+1);
        //backtrack
        swap(nums[index],nums[j]);
    }
}
		vector<string>find_permutation(string nums)
		{
		    vector<string> res;
		    set<string> ans;
		    int index=0;
       solve(nums,ans,index);
       for(auto it:ans){
           res.push_back(it);
       }
  
       return res;
		    // Code here there
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends