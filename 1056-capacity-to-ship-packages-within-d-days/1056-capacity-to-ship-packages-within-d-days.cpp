class Solution {
public:

    bool isPossibleSol(vector<int> &weights, int days, int sol) {
        int storeSum = 0;
        int countDays = 1;
        int n = weights.size();

        for(int i=0; i<n; i++) {
            if(weights[i] > sol) return false;

            if(weights[i] + storeSum > sol) {
                countDays++;
                storeSum = weights[i];

                if(countDays > days) return false;
            }
            else storeSum += weights[i];
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int ans = -1;
        int start = 0;
        int end = accumulate(weights.begin(), weights.end(), 0);

        while(start <= end) {
            int mid = start + (end-start)/2;

            if(isPossibleSol(weights, days, mid)) {
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        } 
        return ans;
    }
};