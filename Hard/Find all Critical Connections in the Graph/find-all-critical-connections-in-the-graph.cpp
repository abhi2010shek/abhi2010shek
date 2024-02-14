//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
	void dfs(int node,int parent,vector<bool> &vis,vector<int> &disc,vector<int> &low,int timer,vector<vector<int>> &ans,vector<int> adj[]){
        vis[node] = 1;
        disc[node] = low[node] = timer++;
        for(auto nbr : adj[node]){
            if(nbr == parent)
              continue;
            if(!vis[nbr]){
               dfs(nbr,node,vis,disc,low,timer,ans,adj);
               low[node] = min(low[node],low[nbr]);
               
               if(low[nbr] > disc[node]){
                   ans.push_back({min(nbr,node),max(nbr,node)});
               }
            }
            else{
                low[node] = min(low[node],disc[nbr]);
            }
        }
    }
	vector<vector<int>>criticalConnections(int v, vector<int> adj[]){
	    vector<vector<int>> ans;
	    int parent = -1;
	    vector<bool> vis(v,0);
	    vector<int> disc(v,-1);
	    vector<int> low(v,-1);
	    int timer = 0;
	    
	    for(int i=0;i<v;i++){
	        if(!vis[i]){
	            dfs(i,parent,vis,disc,low,timer,ans,adj);
	        }
	    }
	   
	   sort(ans.begin(),ans.end());
	    
	    return ans;
	}
};

//{ Driver Code Starts.

int main(){
	int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}
// } Driver Code Ends