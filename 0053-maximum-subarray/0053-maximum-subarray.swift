class Solution {
    func maxSubArray(_ nums: [Int]) -> Int {
        var curr_sum=nums[0]
        var max_sum=nums[0]

        for i in 1..<nums.count {
            curr_sum=max(nums[i],curr_sum+nums[i])
            max_sum=max(curr_sum,max_sum)
        }
        return max_sum
    }
}