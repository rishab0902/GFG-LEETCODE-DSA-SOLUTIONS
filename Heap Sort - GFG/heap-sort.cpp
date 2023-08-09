//{ Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
      // Your Code Here
      int smallest=i;
      int left=2*i+1;
      int right=2*i+2;
      
      if(left<n && arr[smallest]<arr[left])
      smallest=left;
      
      if(right<n && arr[smallest]<arr[right])
      smallest=right;
        
        
      if(smallest!=i)
      {
          swap(arr[smallest],arr[i]);
          heapify(arr,n,smallest);
      }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
    // Your Code Here
    for(int i=(n/2);i>=0;i--)
      {
          heapify(arr,n,i); //build heap use heapify jo har ik index nu sahi jgah ponchanda hai
      }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    
    {
        buildHeap(arr,n);
        for(int last=n-1;last>=0;last--) //pichon shuru karr
        {
            swap(arr[0],arr[last]);//swap last and first
            heapify(arr,last,0);//rescusive call krega heapify tai jo last elemnt aya hai ohnu shi jgah rkh do
        }
        //code here
    }
};




//{ Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends