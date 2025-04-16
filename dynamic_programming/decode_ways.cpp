/* Leetcode Problem 91
You have intercepted a secret message encoded as a string of numbers. The message is decoded via the following mapping:
"1" -> 'A'
"2" -> 'B'
...
"25" -> 'Y'
"26" -> 'Z'
Input: s = "226"
Output: 3
Explanation:
"226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
*/
class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0')
        {
            return 0;
        }
        int n=s.size();
        vector<int>dp(n+1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            if(s[i-1]!='0')
            {
                dp[i] += dp[i-1];
            }
            int twoDigits=stoi(s.substr(i-2,2));
            if(twoDigits>=10 && twoDigits<=26)
            {
                 dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
};
