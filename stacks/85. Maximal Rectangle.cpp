int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    heights.push_back(0);  // Sentinel to flush stack at the end
    int maxArea = 0;

    for (int i = 0; i < heights.size(); i++) {
        while (!st.empty() && heights[i] < heights[st.top()]) {
            int height = heights[st.top()]; st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }

    return maxArea;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    int maxArea = 0, cols = matrix[0].size();
    vector<int> height(cols, 0);

    for (auto& row : matrix) {
        for (int j = 0; j < cols; j++) {
            height[j] = (row[j] == '1') ? height[j] + 1 : 0;
        }

        maxArea = max(maxArea, largestRectangleArea(height));
    }

    return maxArea;
}
