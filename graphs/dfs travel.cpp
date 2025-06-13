class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int>result;
        vector<bool>visited(n,false);
        stack<int>st;
        st.push(0);
        
        while(!st.empty())
        {
            int node=st.top();
            st.pop();
            
            if(!visited[node])
            {
                visited[node]=true;
                result.push_back(node);
            }
            
            for(int i=adj[node].size()-1;i>=0;--i)
            {
                int neighbor=adj[node][i];
                if(!visited[neighbor])
                {
                    st.push(neighbor);
                }
            }
        }
        return result;
        
    }
};
