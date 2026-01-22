class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return intervals;

        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) { return a[0] < b[0]; });

        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for (auto &interval : intervals) {
            auto &current = res.back();
            if (current[1] >= interval[0]) {
                current[1] = max(current[1], interval[1]);
            } else {
                res.push_back(interval);
            }
        }
        return res;
    }
};