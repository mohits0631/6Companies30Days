// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // ------------------ Approach requiring space ------------------
        // int A, B;
        // unordered_map<int, int> mp;
        // for (int i = 0; i < n; i++)
        // {
        //     mp[arr[i]]++;
        //     if (mp[arr[i]] == 2)
        //         B = arr[i];
        // }
        // for (int i = 1; i <= n; i++)
        // {
        //     if (mp.find(i) == mp.end())
        //     {
        //         A = i;
        //         break;
        //     }
        // }
        // arr[0] = B;
        // arr[1] = A;
        // return arr;
        
        // ------------------ Approach requiring O(1) space ------------------
        int xorValue = arr[0];
        
        // calculate the xor of all array elements
        for(int i = 1; i < n;i++)
            xorValue ^= arr[i];
        // calculate the xor of xorValue with i = 1 to n
        for(int i = 1; i <= n;i++)
            xorValue ^= i;
            
        // get the number with only the rightmost bit of xorValue
        int setBitNum = xorValue & ~(xorValue - 1);
        
        // Now we divide the array elements into 2 parts
        int A = 0, B = 0;
        for(int i = 0; i < n; i++)
        {
            if(arr[i] & setBitNum) // arr[i] belongs to first set
                A ^= arr[i];
            else           // arr[i] belongs to second set
                B ^= arr[i];
        }
        for(int i = 1; i <= n; i++)
        {
            if(i & setBitNum) // arr[i] belongs to first set
                A ^= i;
            else      // arr[i] belongs to second set
                B ^= i;
        }
        
        // now we have both numbers just check which one appears twice
        int countA = 0;
        for(int i = 0; i < n; i++)
        {
            if(arr[i] == A)
                countA++;
        }
        
        if(countA == 2)
        {
            arr[0] = A;
            arr[1] = B;
        }
        else
        {
            arr[0] = B;
            arr[1] = A;
        }
        return arr;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends
