/*
 Leetcode 739. Daily Temperatures

Problem:
Given a list of daily temperatures `t`, return a list such that, for each day in the input, 
tells you how many days you would have to wait until a warmer temperature. 
If there is no future day for which this is possible, put 0 instead.

Input: t = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

 Approach:
- Traverse the array in reverse.
- Use a monotonic stack to keep indices of days with temperatures.
- For each day, pop from the stack until a warmer day is found.
- The difference in indices gives the answer.
- If no warmer day, the answer remains 0.
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> ans(n, 0);
        stack<int> st; // stack stores indices

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && t[i] >= t[st.top()]) {
                st.pop(); // remove colder/same temps
            }

            if (!st.empty()) {
                ans[i] = st.top() - i; // days to wait
            }

            st.push(i); // store current day
        }

        return ans;
    }
};
