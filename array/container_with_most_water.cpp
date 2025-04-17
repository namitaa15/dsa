/* Leetcode 11
You are given an integer array height of length n. There are n vertical lines drawn such that 
the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. 
In this case, the max area of water (blue section) the container can contain is 49.
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0;
        int r=n-1;
        int maxi=INT_MIN;
        while(l<=r)
        {
            int a=min(height[l],height[r])*(r-l);
             maxi=max(a,maxi);
             if(height[l]<=height[r])
             {
                l++;
             }
             else
             {
                r--;
             }
        }
        return maxi;
    }
};
