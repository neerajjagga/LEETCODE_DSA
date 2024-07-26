class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        // total floors
        int n = bank.size();

        int preDeviceCount = 0;
        int lasers = 0;

        for(int i=0; i<n; i++) {
            int currentDeviceCount = 0;
            for(auto &ch: bank[i]) {
                if(ch == '1') {
                    currentDeviceCount++;
                }
            }
            lasers += (currentDeviceCount * preDeviceCount);

            if(currentDeviceCount != 0) {

              preDeviceCount = currentDeviceCount; 

            }
        }
       

        return lasers;
    }
};