class Solution {
public:
    string process(string str) {
        string result;
        for (char ch : str) {
            if (ch == '#') {
                if (!result.empty()) {
                    result.pop_back();
                }
            } else {
                result.push_back(ch);
            }
        }
        return result;
    }

    bool backspaceCompare(string s, string t) {
        return process(s) == process(t);
    }
};
