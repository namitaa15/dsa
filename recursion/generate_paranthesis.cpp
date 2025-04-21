22. Generate Parentheses
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]

code-
  class Solution {
public:
    void backtrack(string current, int open, int close, int n, vector<string>& result) {
        if (current.length() == n * 2) {
            result.push_back(current);
            return;
        }

        if (open < n)
            backtrack(current + "(", open + 1, close, n, result);
        if (close < open)
            backtrack(current + ")", open, close + 1, n, result);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack("", 0, 0, n, result);
        return result;
    }
};
