#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string printMinNumberForPattern(string str)
    {
        string ans = ""; // Minimum number following pattern

        int i = 0;
        int cur = 1;    // cur val following pattern
        int dCount = 0; // Count of char 'D'
        while (i < str.length())
        {

            char ch = str[i];

            // If 1st ch == 'I', incr and add to ans
            if (i == 0 && ch == 'I')
            {
                ans += to_string(cur);
                cur++;
            }

            // If cur char == 'D',
            // incr dCount as well, since we always
            // start counting for dCount from i+1
            if (ch == 'D')
            {
                dCount++;
            }

            int j = i + 1; // Count 'D' from i+1 index
            while (j < str.length() && str[j] == 'D')
            {
                dCount++;
                j++;
            }

            int k = dCount; // Store dCount
            while (dCount >= 0)
            {
                ans += to_string(cur + dCount);
                dCount--;
            }

            cur += (k + 1); // Manages next cur val
            dCount = 0;
            i = j;
        }

        return ans;
        // -------------------------------------------- ANOTHER SOLUTION WITH O(N) SPACE --------------------------------------------
        string res = "";
        stack<char> st;
        int n = s.length();
        
        char counter = '1';
        for(int i = 0; i < n; i++)
        {
            st.push(counter++);
            if(s[i]=='I')
            {
                while(!st.empty())
                {
                    res += st.top();
                    st.pop();
                }
            }
        }
        st.push(counter++);
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }
 
        return res;
    }
 
   
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0;
}
// } Driver Code Ends
