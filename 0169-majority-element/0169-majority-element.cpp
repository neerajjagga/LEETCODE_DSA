class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // implement binary search

        int start = 0;
        int end = n - 1;

        int mid = start + (end-start)/2;

        return nums[mid];
    }
};