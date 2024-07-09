class Solution {
public:

    int findPivotIndex(vector<int> &nums) {
        int n = nums.size();
        int s = 0;
        int e = n-1;

        while(s <= e) {
            int mid = s + (e-s)/2;
            // if array contains only 1 element 
            if(s == e) return s;
            // add condition (mid-1 >= 0) so that our index should be valid index
            else if(mid-1 >= 0 && nums[mid] < nums[mid-1]) return mid-1;
            // add condition (mid+1 < n ) so that our index should be valid index
            else if(mid+1 < n && nums[mid] > nums[mid+1]) return mid;
            else if(nums[s] > nums[mid]) e = mid-1;
            else s = mid+1;
        }
        return -1;
    }

    int binarySearch(vector<int> &nums,int s, int e, int target) {
        int n = nums.size();

        while(s <= e) {
            int mid = s + (e-s)/2;
            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] < target) {
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int pivotIndex = findPivotIndex(nums);
        int n = nums.size();
        int ans  = -1;

        // search in A
        if(target >= nums[0] && target <= nums[pivotIndex]) {
            ans = binarySearch(nums, 0, pivotIndex, target);
        }
        else { 
            // search in B
            ans = binarySearch(nums, pivotIndex+1, n-1, target);
        }
        return ans;
    }
};