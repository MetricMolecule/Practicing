class Solution {
public:
    double myPow(double x, int n) {
        long long e= n;
        if(e==0){return 1;}
        if(e<0){
            x= 1/x;
            e=-e;
        }
        if(e%2==0){
            return myPow(x*x, e/2);
        }else{
            return x*myPow(x*x,(e-1)/2);
        }
    }
};