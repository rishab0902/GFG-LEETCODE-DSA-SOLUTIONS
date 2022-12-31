class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
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
    }
};