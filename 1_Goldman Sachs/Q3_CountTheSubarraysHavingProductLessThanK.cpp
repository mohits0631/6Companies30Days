// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 // } Driver Code Ends

class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int wl = 0, wr = 0;
        int bestWindow = 0;
        long long p = 1;
        
        while(wr < n)
        {
            p = p * a[wr];
            
            while(p >= k)
            {
                p /= a[wl];
                wl++;
            }
            if(p < k)
            {
                wr++;
                bestWindow += wr-wl;
            }
        }
        return bestWindow;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends
