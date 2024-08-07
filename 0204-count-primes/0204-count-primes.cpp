class Solution {
public:
    int countPrimes(int n) {
        if(n == 0) return false;

        vector<bool> prime(n, true); // all are prime marked already
        // prime[0] == prime[1] == false; //both zero and one are non-prime

        int ans = 0;
        for(int i=2; i<n; i++) {
            if(prime[i]) {
                ans++;

                int j = 2 * i; // to get multiple of i

                while(j < n) {
                    prime[j] = false;
                    j += i; 
                }
            }
        }
        return ans;
    }
};