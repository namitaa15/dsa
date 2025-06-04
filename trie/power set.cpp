class Solution {
  public:
    void solve(int i, string &s, string temp, vector<string>& ans) {
        if (i == s.size()) {
            if (temp != "")  // Don't include empty string
                ans.push_back(temp);
            return;
        }
        // Include current character
        solve(i + 1, s, temp + s[i], ans);
        // Exclude current character
        solve(i + 1, s, temp, ans);
    }

    vector<string> AllPossibleStrings(string s) {
        vector<string> ans;
        solve(0, s, "", ans);
        sort(ans.begin(), ans.end()); // For lexicographical order
        return ans;
    }
};
