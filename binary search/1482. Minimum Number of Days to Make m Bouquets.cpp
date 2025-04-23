1482. Minimum Number of Days to Make m Bouquets

You are given an integer array bloomDay, an integer m and an integer k.

You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

Example 1:

Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
Output: 3
Explanation: Let us see what happened in the first three days. x means flower bloomed and _ means flower did not bloom in the garden.
We need 3 bouquets each should contain 1 flower.
After day 1: [x, _, _, _, _]   // we can only make one bouquet.
After day 2: [x, _, _, _, x]   // we can only make two bouquets.
After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.
Example 2:

Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
Output: -1
Explanation: We need 3 bouquets each has 2 flowers, that means we need 6 flowers. We only have 5 flowers so it is impossible to get the needed bouquets and we return -1.

class Solution {
public:
    bool possible(vector<int>&arr,int day, int m, int k)
    {
        int n=arr.size();
        int cnt=0;
        int b=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=day)
            {
                cnt++;
            }
            else
            {
                b=b+(cnt/k);
                cnt=0;
            }
        }
        b=b+(cnt/k);
        return b>=m;
    }
    int minDays(vector<int>&arr, int m, int k) {
        int n=arr.size();
        if(1ll*1ll*m*k>n)
        {
            return -1;
        }
        int maxi=*max_element(arr.begin(),arr.end());
        int mini=*min_element(arr.begin(),arr.end());
        int high=maxi;
        int low=mini;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(possible(arr,mid,m,k))
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
};
