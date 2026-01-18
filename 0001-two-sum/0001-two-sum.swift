class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var Dict=[Int:Int]()
        for i in 0..<nums.count{
            let num=nums[i]
            let more=target-num
            if let index=Dict[more]{
                return [index,i]
            }
            Dict[num]=i
        }
        return [-1,-1];
    }
}