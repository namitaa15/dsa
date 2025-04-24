1358. Number of Substrings Containing All Three Characters
Given a string s consisting only of characters a, b and c.
Return the number of substrings containing at least one occurrence of all these characters a, b and c.
Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:

Input: s = "abc"
Output: 1

class Solution {
public:
    int numberOfSubstrings(string s) {
        int lasts[4]={-1,-1,-1};
        int cnt=0;
        for(int i=0;i<s.length();i++)
        {
            lasts[s[i]-'a']=i;
            if(lasts[0]!=-1 && lasts[1]!=-1 && lasts[2]!=-1)
            {
                cnt=cnt+(1+min({lasts[0],lasts[1],lasts[2]}));
            }
        }
        return cnt;
    }
};
