// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    
	    if(n <= 6)
	        return n;
	    
	    // code here
	    vector<ull> v(n);
	    v[0] = 1;
	    
	    int i2 = 0, i3 = 0, i5 = 0;
	    ull multi2 = 2, multi3 = 3, multi5 = 5;
	    ull nextUgly = 1;
	    
	    for(int i = 1; i < n; i++)
	    {
	        nextUgly = min(multi2, min(multi3, multi5));
	        v[i] = nextUgly;
	        
	        if(nextUgly == multi2){
	            i2++;
	            multi2 = v[i2] * 2;
	        }
	        if(nextUgly == multi3){
	            i3++;
	            multi3 = v[i3] * 3;
	        }
	        if(nextUgly == multi5){
	            i5++;
	            multi5 = v[i5] * 5;
	        }
	    }
	    return nextUgly;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
