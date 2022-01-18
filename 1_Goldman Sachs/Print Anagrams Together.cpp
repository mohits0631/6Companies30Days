// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<vector<string>> Anagrams(vector<string> &string_list)
    {
        map<string, int> mp;
        vector<string> sorted_strings;

        for (auto &s : string_list)
        {
            string curr = s;
            sort(curr.begin(), curr.end());
            sorted_strings.push_back(curr);
            mp[curr] = 1;
        }

        int n = string_list.size();
        // code here
        vector<vector<string>> res;

        for (auto itr = mp.begin(); itr!= mp.end(); itr++)
        {
            vector<string> grp;
            for (int j = 0; j < n; j++)
                if (itr->first == sorted_strings[j])
                {
                    grp.push_back(string_list[j]);
                }
            res.push_back(grp);
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
        int n;
        cin >> n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin >> string_list[i];
        Solution ob;
        vector<vector<string>> result = ob.Anagrams(string_list);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for (int j = 0; j < result[i].size(); j++)
            {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
// } Driver Code Ends
