#include <bits/stdc++.h>
using namespace std;
bool comp(const pair<int,int>&a,const pair<int,int>&b){
    if(a.second== b.second){
        return (a.first<b.first);
    }
    else{
        return (a.second>b.second);
    }
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    unordered_map<int,int> mp;
	    vector<pair<int,int>> res;
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        mp[arr[i]]++;
	    }
	    for(auto e:mp){
	        res.push_back({e.first,e.second});
	    }
	    sort(res.begin(),res.end(),comp);
	    for(auto e:res){
	        for(int i=0;i<e.second;i++){
	            cout<<e.first<<" ";
	        }
	    }
	    cout<<endl;
	   
	    
	}
	return 0;
}