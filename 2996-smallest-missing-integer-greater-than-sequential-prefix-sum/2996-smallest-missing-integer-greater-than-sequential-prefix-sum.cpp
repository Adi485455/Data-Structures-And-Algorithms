class Solution {
public:
    int prefix(vector<int>&nums){
        int n=nums.size();
       int presum = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                presum+=nums[i];
            }else{
                break;
            }
        }
        return presum;
    }
    int missingInteger(vector<int>& nums) {
        unordered_set<int>st;

        for(int x :nums){
            st.insert(x);
        }
        int pSum=prefix(nums);

        while(pSum >0){
            if(st.count(pSum)){
                pSum++;
            }else{
                break;
            }
        }
        
 return pSum;
    }
};