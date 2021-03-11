#define INF 1e9

class Solution {
public:
    int jump(vector<int>& nums) {
        
        vector<int> d(nums.size(), 0);
        d[nums.size() - 1] = 0;
        
        for(int i = nums.size() - 2; i >= 0; i--) {
            int temp = INF;
            for(int j = i + 1; j <= i + nums[i]; j++) {
                if(j >= nums.size()) {
                    continue;
                }
                if(d[j] + 1 < temp) {
                    temp = d[j] + 1;
                }
            }
            
            d[i] += temp;
        }
        
        return d[0];
    }
};