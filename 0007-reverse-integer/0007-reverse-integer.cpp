class Solution {
public:
    int reverse(int x) {
        int revnum =0;
        while(x!=0){
            int d= x%10;
            x= x/10;
            if(revnum >INT_MAX/10 || (revnum==INT_MAX/10 && d>7 )){
                return 0;
            }if(revnum <INT_MIN/10 || (revnum==INT_MIN/10 && d<-8 )){
                return 0;
            }revnum = revnum*10+d;
        }return revnum;
    }
};