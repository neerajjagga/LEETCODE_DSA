class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int e = n-1;

        while(s <= e) {
            int mid = s + (e-s)/2;
            if(nums[s] <= nums[e]) {
                return nums[s];
            }
            else if(mid < n && nums[mid] > nums[mid+1]) {
                return nums[mid+1];
            }
            else if(mid >= 0 && nums[mid] < nums[mid-1]) {
                return nums[mid];
            }
             else if (nums[s] <= nums[mid]) {
                // Corrected this line to move the start pointer
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }
        return -1;
    }
};