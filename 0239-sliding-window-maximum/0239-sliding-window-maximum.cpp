class Solution {
public:
    /*
    Approach :- First we the one slide so we've to move slide among the elements so,we need to keep track of the both of the elements or the both of the indx's first idx and the last idx. 
    -> So brute force be like use the two loops one start from i to n and second j=i to j=k and find the max element.

    -> So in the Optimal approach we need the data-structure in which we can keep track of the first and last element and also we can push from the front and last also.So we've the two choices doubly linked list and the deque but comparitively dequeue is much easy to implement.

    -> So first we gonna intiate the deque with INT_MIN and we gonna check when the current element less than prev or back element of the deque we gonna pop that element and push the current element in the deque from back.(As the front element will be the maximum among the window and we wanted deque in sorted order) so first indow complete.

    -> Then,this is only for the elements upto k so for the elements after k start the loop from the i=k to n
    first as we have the max element of the first window as the front of the deque we gonna add it to the res vector.
    Now first we gonna check is the front of the dequeue belongs to this window as by we know each window size is the k so by (i-k) we can check the deque front elements (idx) lie into the this window range or not if not then pop this front also.

    -> Adding :- Adding the elements to the deque by the same logic as the prev one by cheking the back of the dequeue.

    -> At last we update the new front of the dequeue to the res vector
    */
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>dq;
        vector<int>res;

        for (int i =0;i<k;i++){
            while(dq.size()>0 && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        for (int i=k;i<n;i++){
            res.push_back(nums[dq.front()]);
            while(dq.size()>0 && dq.front()<=i-k){
                dq.pop_front();
            }
            while(dq.size()>0 && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        res.push_back(nums[dq.front()]);
        return res;
    }
};