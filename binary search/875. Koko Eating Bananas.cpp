875. Koko Eating Bananas

Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. 
  If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23

class Solution {
public:
    long long func(vector<int>& piles, long long mid)
    {
        long long n=piles.size();
        long long total=0;
        for(long long i=0;i<n;i++)
        {
            total=total+ceil((double)piles[i]/(double)mid);
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long n=piles.size();
        long long maxi=*max_element(piles.begin(),piles.end());
        long long low=1;
        long long high=maxi;
        long long ans;
        while(low<=high)
        {
            long long mid=(low+high)/2;
            long long totalh=func(piles,mid);
            if(totalh<=h)
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
