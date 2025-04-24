class Solution {
public:
    string reverseWords(string s) {
        vector<string>ans;
        string word;
        for(char c:s)
        {
            if(c!=' ')
            {
                word=word+c;
            }
            else if(!word.empty())
            {
                ans.push_back(word);
                word.clear();
            }
        }
        if (!word.empty()) {
        ans.push_back(word);
    }
        reverse(ans.begin(),ans.end());
        int n=ans.size();
        string sen=ans[0];
        for(int i=1;i<n;i++)
        {
            sen=sen+" "+ans[i];
        }
        return sen;
    }
};
