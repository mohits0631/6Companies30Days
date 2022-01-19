// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        
        int n = nums.size();
        if(n%2 == 1)
            return false;
        // Code here.
        unordered_map<int, int> mp;
        for(auto &n : nums)
        {
            mp[(n%k + k)%k]++; // putting remainders in map
        }
        
        for(auto &n : nums)
        {
            int rem = (n%k + k)%k;
            
            if(2*rem == k)
            {   
                if(mp[rem] & 1)
                    return false;
            }
            else if(rem == 0)
            {   
                if(mp[rem] & 1)
                    return false;
            }
            else if(mp[rem] != mp[k-rem])
                return false;
        }
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends
