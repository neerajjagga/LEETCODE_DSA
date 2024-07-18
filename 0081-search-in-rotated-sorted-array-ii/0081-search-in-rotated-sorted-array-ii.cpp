class Solution {
public:
   int findPivotIndex(vector<int> &nums) {
        int n = nums.size();
        int s = 0;
        int e = n-1;

        while(s <= e) {
            int mid = s + (e-s)/2;
            if(s == e) return s;
            if (nums[mid] == nums[e]) {
                e--;
            }
            // add condition (mid-1 >= 0) so that our index should be valid index
            else if(mid-1 >= 0 && nums[mid] < nums[mid-1]) return mid-1;
            // add condition (mid+1 < n ) so that our index should be valid index
            else if(mid+1 < n && nums[mid] > nums[mid+1]) return mid;
            else if(nums[s] > nums[mid]) e = mid-1;
            else s = mid+1;
        }
        return -1;
    }
    bool binarySearch(vector<int> &nums,int s, int e, int target) {
        int n = nums.size();

        while(s <= e) {
            int mid = s + (e-s)/2;
            if(nums[mid] == target) {
                return true;
            }
            else if(nums[mid] < target) {
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = -1;
        int pivotIndex = findPivotIndex(nums);
        if(target == nums[pivotIndex]) return true;

        if(binarySearch(nums, 0, pivotIndex, target)) {
            return true;
        }
        
        if(binarySearch(nums, pivotIndex+1, n-1, target)){
            return true;
        }

        return false;
    }
};