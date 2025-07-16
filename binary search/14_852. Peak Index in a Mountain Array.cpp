852. Peak Index in a Mountain Array
You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

Return the index of the peak element.

Your task is to solve it in O(log(n)) time complexity.

Example 1:

Input: arr = [0,1,0]

Output: 1

Example 2:

Input: arr = [0,2,1,0]

Output: 1

Example 3:

Input: arr = [0,10,5,2]

Output: 1

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
       int n= arr.size();
       if(arr[0]>arr[1])
       {
            return 0;
       }
       if(arr[n-1]>arr[n-2])
       {
            return n-1;
       }
       int low=1;
       int high=n-2;
       while(low<=high)
       {
            int mid=low +(high-low)/2;
            if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1])
            {
                return mid;
            }
            if(arr[mid]>arr[mid-1])
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
       }
       return 0;
    }
};
