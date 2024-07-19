class Solution {
public:
    
    bool isPossibleSol(vector<int> &nums, int k, int sol) {
        int totalSum = 0;
        int countSubarray = 1;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] > sol) return false;

            if(totalSum + nums[i] > sol) {
                countSubarray++;
                totalSum = nums[i];

                if(countSubarray > k) return false;
            }
            else totalSum += nums[i];
        }
        return true;
    } 
    int splitArray(vector<int>& nums, int k) {
        int start = 0;
        int end = accumulate(nums.begin(), nums.end(), 0);
        int ans = -1;

        while(start <= end) {
            int mid = start + (end - start)/2;

            if(isPossibleSol(nums, k, mid)) {
                ans = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return ans;
    }
};