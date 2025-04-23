20. Valid Parentheses
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

code-
  class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char ch:s)
        {
            if(ch=='[' || ch=='{' || ch=='(')
            {
                st.push(ch);
            }
            else
            {
                if(st.empty())
                {
                    return false;
                }
                char top=st.top();
                st.pop();
                if((ch==']' && top!='[') || (ch=='}' && top!='{') || (ch==')' && top!='('))
                {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
