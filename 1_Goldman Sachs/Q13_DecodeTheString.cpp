// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        stack<char> stck;
        int n = s.length();
        
        for(int i = 0; i < n; i++)
        {
            if(s[i] != ']')
                stck.push(s[i]);
            else{
                string curr = "", num = "";
                
                while(stck.top() != '[' && stck.empty() == false){
                    curr = stck.top() + curr;
                    stck.pop();
                }
                
                stck.pop(); // pop the '['
                
                while(!stck.empty() && stck.top() >='0' && stck.top() <= '9')
                {
                    num= stck.top()+num;
                    stck.pop();
                }
                
                int number = stoi(num);
                
                for(int i = 0; i < number; i++)
                    for(auto &c:curr)
                        stck.push(c);
            }
        }
        
        string res = "";
        while(!stck.empty())
        {
            res = stck.top() + res;
            stck.pop();
        }
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
