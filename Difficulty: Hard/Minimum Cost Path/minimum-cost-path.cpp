//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    #define P pair<int,pair<int,int>>
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int n = grid.size();
	    
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        dist[0][0]=grid[0][0];
        priority_queue<P,vector<P>,greater<P>>pq;
        
        pq.push({grid[0][0],{0,0}});
        
        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};
        
        while(!pq.empty()){
            int cur = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            
            for(int k=0;k<4;k++){
                int nr = i + dx[k];
                int nc = j + dy[k];
                if(nr>=0 && nr<n && nc>=0 && nc<n && cur + grid[nr][nc] < dist[nr][nc]){
                    dist[nr][nc] = cur + grid[nr][nc];
                    pq.push({dist[nr][nc],{nr,nc}});
                }
            }
        }
        
        return dist[n-1][n-1];
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends