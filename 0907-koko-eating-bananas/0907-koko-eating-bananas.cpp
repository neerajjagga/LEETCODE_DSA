class Solution {
public:
    
    long long int findTotalHours(vector<int> &piles, int sol) {
        long long int totalHours = 0;
        for(int i=0; i<piles.size(); i++) {
            totalHours += ceil((double)piles[i] / (double)sol);
        }
        return totalHours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());
        int ans = -1;

        while(start <= end) {
            int mid = start + (end-start)/2;
            long long int totalHours = findTotalHours(piles, mid);
            if(totalHours <= h) {
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return ans;
    }
};