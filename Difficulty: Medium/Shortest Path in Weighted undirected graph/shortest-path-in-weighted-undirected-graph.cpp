//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adjList(n+1);
        for(int i=0; i<m; i++){
            adjList[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adjList[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        vector<int> dist(n+1,INT_MAX);
        dist[1] = 0;
        vector<int> prev(n+1,-1);
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,1});
        
        while(!pq.empty()){
            int w = pq.top().first;
            int v = pq.top().second;
            pq.pop();
            
            for(auto it: adjList[v]){
                int edgeWeight = it.second;
                int adjNode = it.first;
                if(w+edgeWeight < dist[adjNode]){
                    dist[adjNode] = w + edgeWeight;
                    prev[adjNode] = v;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        
        vector<int> ans;
        if(prev[n]==-1){
            ans.push_back(-1);
            return ans;
        }
        else{
            int currVertex = n;
            while(currVertex!=-1){
                ans.push_back(currVertex);
                currVertex = prev[currVertex];
            }
            ans.push_back(dist[n]);
            reverse(ans.begin(),ans.end());
            return ans;
        }
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends