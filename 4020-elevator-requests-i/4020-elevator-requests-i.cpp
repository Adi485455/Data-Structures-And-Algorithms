class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int m = requests.size();
        int ans=requests[0];
        int start =0;
        while(start+1 < m){
            ans+= abs(requests[start]-requests[start + 1]);
            start ++;
        }
        return ans;
    }
};