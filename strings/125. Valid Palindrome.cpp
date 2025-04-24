class Solution {
public:
void removeNonAlphanumeric(string& s) {
    s.erase(remove_if(s.begin(), s.end(), [](unsigned char c) { return !isalnum(c); }), s.end());
}
void toLowercase(string& s) {
    transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return tolower(c); });
}

    bool isPalindrome(string s) {
        toLowercase(s);
        removeNonAlphanumeric(s);
        int n=s.size();
        for(int i=0;i<(n/2);i++)
        {
            if(s[i]!=s[n-i-1])
            {
                return false;
            }
        }
        return true;
    }
};
