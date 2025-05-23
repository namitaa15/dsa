class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi=0;
        int n=s.length();
        int start=0;
        map<char,int>mp;
        for(int i=0;i<n;i++)
        {
            if(mp.find(s[i])!=mp.end() && mp[s[i]]>=start)
            {
               start=mp[s[i]]+1;
            }
            mp[s[i]]=i;
            maxi=max(maxi,i-start+1);
        }
       return maxi;
    }
};
