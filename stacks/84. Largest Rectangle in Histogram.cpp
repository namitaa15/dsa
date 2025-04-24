class Solution {
public:
    vector<int>nse(vector<int>& arr)
    {
        stack<int>st;
        int n=arr.size();
        vector<int>ans;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                ans.push_back(n);
            }
            else
            {
                ans.push_back(st.top());
            }
            st.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    vector<int>pse(vector<int>& arr)
    {
        stack<int>st;
        int n=arr.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]>arr[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(st.top());
            }
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& arr) {
         vector<int>nsee=nse(arr);
         vector<int>psee=pse(arr);
         int n=arr.size();
         int maxi=0;
         for(int i=0;i<n;i++)
         {
            maxi=max(maxi,(nsee[i]-psee[i]-1)*arr[i]);
         }
         return maxi;
    }
};
