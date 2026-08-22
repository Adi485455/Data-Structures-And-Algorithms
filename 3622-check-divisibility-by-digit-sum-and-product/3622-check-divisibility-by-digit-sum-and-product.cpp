class Solution {
public:
    bool checkDivisibility(int n) {
        int prev = n;
        int add =0;
        int mul = 1;
        while(n > 0){
            add+=(n%10);
            mul*=(n%10);
            n/=10;
        }
        if ((prev%(add+mul))==0){
            return true;
        }
        return false;
    }
};