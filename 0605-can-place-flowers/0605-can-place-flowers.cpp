class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int cnt=0;
        int x=f.size();
        
        if(n==0)return true;
        
        if(x==1){
            if(!f[0])cnt++;
           return (cnt==n);
        }
        
        if(f[0]==0 && f[1]==0){
            f[0]=2;
            cnt++;
        }
        for(int i=1;i<x-1;i++){
            if(f[i]==0){
                if(f[i-1]==0 && f[i+1]==0){
                    f[i]=2;
                    cnt++;
                }
            }
        }
           if(!f[x-1] && !f[x-2]){
               f[x-1]=2;
               cnt++;
           }
       
        return(cnt>=n);
           
    }
};