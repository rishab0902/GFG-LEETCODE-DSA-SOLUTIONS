//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class node{
    public:
    int data;
    int row;
    int col;
    
    node(int d,int r,int c){
        data=d;
        row=r;
        col=c;
    }
};
class compare{
    public:
    bool operator()(node *a,node*b){
        return a->data>b->data;
    }
};
class Solution{
    public:
    
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
          //code here
          int ansfi,ansla;
          int mini=INT_MAX;
          int maxi=INT_MIN;
          priority_queue<node *,vector<node*>,compare> minhp;
          
          for(int i=0;i<k;i++){
              int element=arr[i][0];
              maxi=max(maxi,element);
              mini=min(mini,element);
              minhp.push(new node(element,i,0));
              
          }
          ansfi=mini,ansla=maxi;
          
          
          while(!minhp.empty()){
              node* temp=minhp.top();
              minhp.pop();
              mini=temp->data;
              if(maxi-mini<ansla-ansfi){
                  ansfi=mini;
                  ansla=maxi;
              }
              if(temp->col+1<n ){
                  maxi=max(maxi,arr[temp->row][temp->col+1]);
                  minhp.push(new node(arr[temp->row][temp->col+1],temp->row,temp->col+1));
                  
              }
              else break;
          }
          return {ansfi,ansla};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


// } Driver Code Ends