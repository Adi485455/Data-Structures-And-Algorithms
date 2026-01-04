class Solution {
    func maxProfit(_ a: [Int]) -> Int {
        let n=a.count
        var Min=a[0]
        var prof=0
        for i in 1..<n {
            let cost=a[i]-Min
            prof=max(prof,cost)
            Min=min(Min,a[i])
        }
        return prof
    }
}