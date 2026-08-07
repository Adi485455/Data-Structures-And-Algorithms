class Solution {
public:

    int digitProduct(int n){
        int a=1;
        while(n>0){
            a=a*(n%10);
            n/=10;
        }
        return a;
    }
    int smallestNumber(int n, int t) {
        while(true){
            if(digitProduct(n)%t==0){
                return n;
            }
            n++;
        }

    }
};