// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string s)
{ 
  // --------------------------- SOLUTION USING LOOP AND COUNTER ---------------------------------
  string dest = "";
    for(int i = 0; i < src.size(); i++){
        dest += src[i];
        int cnt = 1;
        while(i+1 < src.size() && src[i] == src[i+1]){
            cnt++;
            i++;
        }
        dest+=to_string(cnt);
    }
    return dest;
  
  // --------------------------- SOLUTION USING MAPS ---------------------------------
  //Your code here 
  /*
  int n = s.length();
  string res = "";
  unordered_map<char, int> mp;
  
  mp[s[0]]++;
  
  for(int i = 1; i < n; i++)
  {
      if(s[i] != s[i-1])
      {
        res += (s[i-1] + to_string(mp[s[i-1]]));
        mp.erase(s[i-1]);
      }
        mp[s[i]]++;
  }
  res += (s[n-1] + to_string(mp[s[n-1]]));
  return res;
  */
}     
