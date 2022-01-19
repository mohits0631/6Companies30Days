class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int currSum = 0;
        int s = 0;
        int res = INT_MAX;
        for(int e = 0; e < n; e++)
        {
            currSum += nums[e];
            // cleaning the previous window
            while(currSum >= target && s <= e)
            {
                if(currSum >= target)
                    res = min(res, e-s+1);
                currSum -= nums[s++];
            }
        }
        return (res == INT_MAX)? 0:res;
    }
};
