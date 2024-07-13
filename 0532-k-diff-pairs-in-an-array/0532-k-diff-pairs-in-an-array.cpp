class Solution {
public:

   // two pointer approach

        // sort(nums.begin(), nums.end());

        // set<pair<int, int>> ans;

        // int i=0, j=1;
        // while(j < nums.size()) {
        //     if(i == j) j++;
        //     int diff = nums[j] - nums[i];
        //     if(diff == k) {
        //         ans.insert({nums[i],nums[j]});
        //         i++, j++;
        //     }
        //     else if(diff > k){
        //         i++;
        //     }
        //     else {
        //         j++;
        //     }
        //     if(i == j) j++;
        // }
        // return ans.size();

    int binarySearch(vector<int> &nums, int start, int x)  {
        // here x = k + nums[i];
        int end = nums.size() - 1;
        while(start <= end) {
            int mid = start + (end-start)/2;

            if(nums[mid] == x) {
                return mid;
            }
            else if(x > nums[mid]) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return -1;
    }

    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        set<pair<int, int>> ans;

        for(int i=0; i<nums.size(); i++) {
            // i am in nums[i]
            // i have to search for nums[i]+k in the right subarray by using binary search
            if(binarySearch(nums, i+1, k+nums[i]) != -1) {
                ans.insert({nums[i], nums[i]+k});
            }
        }
        return ans.size();
    }
};