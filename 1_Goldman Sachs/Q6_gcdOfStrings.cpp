class Solution {
    int gcd(int a, int b)
    {
        return b==0? a: gcd(b,a%b);
    }
public:
    string gcdOfStrings(string str1, string str2) {
        
        if(str1+str2 != str2+str1)
            return "";
        
        int n1 = str1.length();
        int n2 = str2.length();
        
        int lenGCD = gcd(n1,n2);
        
        return str1.substr(0, lenGCD);
    }
};
