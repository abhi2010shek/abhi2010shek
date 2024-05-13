//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        // code here
        vector<int>ed[v+1];
        for(auto i:edges){
            ed[i[0]].push_back(i[1]);
            ed[i[1]].push_back(i[0]);
        }
        int count=0;
        vector<int>vis(v+1,0);
        for(int i=1;i<=v;i++){
            vector<int>vis2(v+1,0);
            if(vis[i]==0){
                queue<int>q;
                q.push(i);
                bool isValid=true;
                bool isVisited=false;
                int size=0;
                while(!q.empty()){
                    int x=q.front();
                    vis[x]=1;
                    q.pop();
                    if(isVisited==false){
                        isVisited=true;
                        vis2[x]=1;
                        size=ed[x].size();
                        for(auto ed2:ed[x]){
                            vis2[ed2]=1;
                            q.push(ed2);
                        }
                    }
                    else if(isValid==false){
                        for(auto ed2:ed[x]){
                            if(vis[ed2]==0){
                                q.push(ed2);
                            }
                            vis[ed2]=1;
                            vis2[ed2]=1;
                        }
                    }
                    else{
                        // cout<<ed[x].size()<<endl;
                        if(ed[x].size()==size){
                            for(auto ed2:ed[x]){
                                // cout<<ed2<<' '<<vis2[ed2]<<endl;
                                if(vis2[ed2]==0){
                                    isValid=false;
                                    q.push(x);
                                    break;
                                }
                            }
                        }
                        else{
                            isValid=false;
                            q.push(x);
                        }
                    }
                
                }
                if(isValid){
                    count++;
                }
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    }
}

// } Driver Code Ends