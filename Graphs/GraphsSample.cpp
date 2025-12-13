#include "head.h"
void bfs(int s,int v,vector<int> adjList[],vi &vis){
        queue<int> q;
        q.push(s);
        vis[s] = 1;
        while(!q.empty()){
        	int node = q.front();
        	q.pop();
        	cout<<node<<" ";
        	for(auto i : adjList[node]){
        		if(!vis[i]){
        			q.push(i);
        			vis[i] = 1;
        		}
        	}
        }
        for(int i=0;i<v;i++) if(!vis[i]) bfs(i,v,adjList,vis);
        return;
}
void dfs1(int s,int v,vector<int> adjList[],vi &vis){
	stack<int> st;
	st.push(s);
	vis[s] = 1;
	while(st.empty() == false){
		int node = st.top();
		st.pop();
		cout<<node<<" ";
		for(auto i : adjList[node]){
			if(!vis[i]){
				st.push(i);
				vis[i] = 1;
			}
		}
	}
	for(int i=0;i<v;i++) if(!vis[i]) dfs1(i,v,adjList,vis);
	return;
}
void dfs2(int node,int v,vector<int> adjList[],vi &vis){
	cout<<node<<" ";
	vis[node] = 1;
	for(auto adjNode : adjList[node]){
		if(!vis[adjNode]) dfs2(adjNode,v,adjList,vis);
	}
	for(int i=0;i<v;i++) if(!vis[i]) dfs2(i,v,adjList,vis);
	return;
}
int NumberOfConnectedComponents(int v,vi adjList[]){
	vi vis(v,0);
	int cnt = 0;
	for(int i=0;i<v;i++) {
		if(vis[i] == 0){
			cnt++;
			dfs1(i,v,adjList,vis);
		}
	}
	return cnt;
}
vector<vector<int>> FloodFill(int sr,int sc,vvi image,int iniColor,int finalColor){

	vvi ans = image;
    int n = image.size();
    int m = image[0].size();
	queue<pair<int,int>> q;
	q.push({sr,sc});
	ans[sr][sc] = finalColor;
	int delrow[] = {-1,0,+1,0};
	int delcol[] = {0,-1,0,+1};
    while(!q.empty()){
    	int row = q.front().first;
    	int col = q.front().second;
    	q.pop();
    	for(int i=0;i<4;i++){
			int nrow = row + delrow[i];
			int ncol = col + delcol[i];
			if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && image[nrow][ncol] == iniColor && ans[nrow][ncol] != finalColor){
				ans[nrow][ncol] = finalColor;
				q.push({nrow,ncol});
			}
    	}
    }
	return ans;
}
int MinTimeToRottOranges(vvi grid){
	/*
           0 - no orange
           1 - fresh orange
           2 - rotten orange => 1 rooten orange rots fresh oranges on its four sides

	*/
	int n = grid.size();
	int m = grid[0].size();
	vvi vis(m,vi(m,0));
	queue<pair<pair<int,int>,int>> q;
	int freshOranges = 0;
	for(int row = 0;row < n;row++){
		for(int col = 0;col < m;col++){
			if(grid[row][col] == 2){
				vis[row][col] = 1;
				q.push({{row,col},0});
			}
			if(grid[row][col] == 1) freshOranges++;
		}
	}
	int minTime = 0;
	int delrow[] = {0,1,0,-1};
	int delcol[] = {-1,0,1,0};
	int freshOrangesRotted = 0;
	while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int time = q.front().second;
        q.pop();
        minTime = max(minTime,time);
        for(int i=0;i<4;i++){
        	int nrow = row + delrow[i];
        	int ncol = col + delcol[i];
        	if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0){
        		q.push({{nrow,ncol},time+1});
        		vis[nrow][ncol] = 1;
        		freshOrangesRotted++;

        	}
        }
	}
	if(freshOranges != freshOrangesRotted) return -1;
	return minTime;
}
vvi NearestCellHaving1(vvi grid){
	int n = grid.size();
	int m = grid[0].size();
	vvi vis(n,vi(m,0));
	vvi ans = grid;
	queue<pair<pair<int,int>,int>> q;
	for(int row = 0;row < n;row++){
		for(int col = 0;col < m;col++){
			if(grid[row][col] == 1){
				vis[row][col] = 1;
				ans[row][col] = 0;
				q.push({{row,col},0});
			}
		}
	}
	int delrow[] = {0,1,0,-1};
	int delcol[] = {-1,0,1,0};
	while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
        	int nrow = row + delrow[i];
        	int ncol = col + delcol[i];
        	if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m  && vis[nrow][ncol] == 0){
        		vis[nrow][ncol] = 1;
                ans[nrow][ncol] = dist+1;
        		q.push({{nrow,ncol},dist+1});
        	}
        }
	}
	return ans;
}
int	NumberOfDistinctIslands_bfs(vvi grid){
	int n = grid.size();
	int m = grid[0].size();
	vvi vis(n,vi(m,0));
	set<vector<pair<int,int>>> s;
	for(int x=0;x<n;x++){
       for(int y=0;y<m;y++){
	       	if(grid[x][y] == 1 && vis[x][y] == 0){
				vis[x][y] = 1;
				queue<pair<int,int>> q;
				vector<pair<int,int>> island;
				q.push({x,y});
				int delrow[] = {0,+1,0,-1};
				int delcol[] = {-1,0,+1,0};
				while(!q.empty()){
                    int row = q.front().first;
                    int col = q.front().second;
                    island.push_back({row-x,col-y});
                    q.pop();
                    for(int i=0;i<4;i++){
                    	int nrow = row + delrow[i];
                    	int ncol = col + delcol[i];
                    	if(nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0){
                    		vis[nrow][ncol] = 1;
                    		q.push({nrow,ncol});
                    	}
                    }
				}
				s.insert(island);
	       	}
       }
    }
    return s.size();

}
int NumberOfDistinctIslands_dfs(vvi grid){
	int n = grid.size();
	int m = grid[0].size();
	vvi vis(n,vi(m,0));
	set<vector<pair<int,int>>> s;
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			if(grid[x][y] == 1 && !vis[x][y]){
				vis[x][y] = 1;
				stack<pair<int,int>> st;
				vector<pair<int,int>> island;
				st.push({x,y});
				int delrow[] = {0,1,0,-1};
				int delcol[] = {-1,0,1,0};
				while(!st.empty()){
					int row = st.top().first;
					int col = st.top().second;
					island.push_back({row-x,col-y});
					st.pop();
					for(int i=0;i<4;i++){
						int nrow = row + delrow[i];
						int ncol = col + delcol[i];
						if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
							vis[nrow][ncol] = 1;
							st.push({nrow,ncol});
						}
					}
				}
				s.insert(island);
			}
		}
	}
	return s.size();
}
vvc SurroundedRegionsReplaceX(vvc grid){
	int n = grid.size();
	int m = grid[0].size();
	vvc ans = grid;
	vvi vis(n,vi(m,0));
	int delcol[] = {-1,0,+1,0};
	int delrow[] = {0,+1,0,-1};
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			if((x == 0 || y == 0 || x == n-1 || y == m-1) && (grid[x][y] == 'O' && !vis[x][y])){
				queue<pair<int,int>> q;
				q.push({x,y});
				vis[x][y] = 1;
				while(!q.empty()){
					int row = q.front().first;
					int col = q.front().second;
					q.pop();
					for(int i=0;i<4;i++){
						int nrow = row + delrow[i];
						int ncol = col +delcol[i];
						if(nrow >=0 && nrow < n && ncol >=0 && ncol < m && grid[nrow][ncol] == 'O' && !vis[nrow][ncol]){
							q.push({nrow,ncol});
							vis[nrow][ncol] = 1;
						}
					}

				}
			}
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(grid[i][j] == 'O' && !vis[i][j]){
				ans[i][j] = 'X';
			}
		}
	}
	return ans;
}
int NumberOfEnclaves(vvi grid){
	int n = grid.size();
	int m = grid[0].size();
	int ans = 0;
	vvi vis(n,vi(m,0));
	int delcol[] = {-1,0,+1,0};
	int delrow[] = {0,+1,0,-1};
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			if((x == 0 || y == 0 || x == n-1 || y == m-1) && (grid[x][y] == 1 && !vis[x][y])){
				queue<pair<int,int>> q;
				q.push({x,y});
				vis[x][y] = 1;
				while(!q.empty()){
					int row = q.front().first;
					int col = q.front().second;
					q.pop();
					for(int i=0;i<4;i++){
						int nrow = row + delrow[i];
						int ncol = col +delcol[i];
						if(nrow >=0 && nrow < n && ncol >=0 && ncol < m && grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
							q.push({nrow,ncol});
							vis[nrow][ncol] = 1;
						}
					}

				}
			}
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(grid[i][j] == 1 && !vis[i][j]){
				ans++;
			}
		}
	}
	return ans;
}

bool isBipartite_dfs(int V,vector<int> adjList[]){
	vi color(V,0);
	for(int i=0;i<V;i++){
      if(color[i] == 0){
           stack<int> st;
		    st.push(i);
		    color[i] = 1;
		    while(!st.empty()){
		        int node = st.top();
		        st.pop();
		        for(auto neighbour : adjList[node]){
	                if(color[neighbour] == 0){
		              	color[neighbour] = (color[node] == 1) ? 2 : 1;
		              	st.push(neighbour);
	                }
	                else if(color[neighbour] == color[node]) return false;
		        }
            }
      }
	}
    return true;
}

bool isBipartite_bfs(int V,vector<int> adjList[]){
	vi color(V,0);
	for(int i=0;i<V;i++){
      if(color[i] == 0){
           queue<int> q;
		    q.push(i);
		    color[i] = 1;
		    while(!q.empty()){
		        int node = q.front();
		        q.pop();
		        for(auto neighbour : adjList[node]){
	                if(color[neighbour] == 0){
		              	color[neighbour] = (color[node] == 1) ? 2 : 1;
		              	q.push(neighbour);
	                }
	                else if(color[neighbour] == color[node]) return false;
		        }
            }
      }
	}
	return true;
}

bool DetectCyleInUnDirectedGraph_dfs(int V,vector<int> adjList[]){
	vi vis(V,0);
	for(int i=0;i<V;i++){
      if(vis[i] == 0){
           stack<pair<int,int>> st;
		    st.push({i,-1});
		    vis[i] = 1;
		    while(!st.empty()){
		        int node = st.top().first;
		        int parent = st.top().second;
		        st.pop();
		        for(auto neighbour : adjList[node]){
	                if(vis[neighbour] == 0){
		              	vis[neighbour] = 1;
		              	st.push({neighbour,node});
	                }
	                else if(parent != neighbour) return true;
		        }
            }
      }
	}
	return false;
}

bool DetectCyleInUnDirectedGraph_bfs(int V,vector<int> adjList[]){
	vi vis(V,0);
	for(int i=0;i<V;i++){
      if(vis[i] == 0){
           queue<pair<int,int>> q;
		    q.push({i,-1});
		    vis[i] = 1;
		    while(!q.empty()){
		        int node = q.front().first;
		        int parent = q.front().second;
		        q.pop();
		        for(auto neighbour : adjList[node]){
	                if(vis[neighbour] == 0){
		              	vis[neighbour] = 1;
		              	q.push({neighbour,node});
	                }
	                else if(parent != neighbour) return true;
		        }
            }
      }
	}
	return false;
}
vector<int> TopologicalSort(int V,vector<int> adjList[]){
	vector<int> toposort;
	queue<int> q;
	vector<int> indegree(V,0);
	for(int node = 0;node < V;node++){
		for(auto neighbour : adjList[node]){
			indegree[neighbour]++;
		}
	}
    
    for(int node = 0;node<V;node++) if(indegree[node] == 0) q.push(node);

    while(!q.empty()){
    	int node = q.front();
    	q.pop();
    	toposort.push_back(node);
    	for(auto neighbour : adjList[node]){
    		indegree[neighbour]--;
    		if(indegree[neighbour] = 0) q.push(neighbour);
    	}
    }
    return toposort;
}
bool DetectCyleInDirectedGraph_dfs_helper(int node,int vis[],int pathVisited[],vector<int> adjList[]){
	vis[node] = 1;
	pathVisited[node] = 1;
	for(auto neighbour : adjList[node]){
		if(!vis[neighbour] && DetectCyleInDirectedGraph_dfs_helper(neighbour,vis,pathVisited,adjList)) return true;
		else if(vis[neighbour] && pathVisited[neighbour]) return true;
	}
	pathVisited[node] = 0;
	return false;
}
bool DetectCyleInDirectedGraph_dfs(int V,vector<int> adjList[]){
    int vis[V] = {0};
    int pathVisited[V] = {0};
	for(int node = 0;node<V;node++){
		if(DetectCyleInDirectedGraph_dfs_helper(node,vis,pathVisited,adjList)){
			return true;	
		} 
	}
	return false;
}
bool DetectCyleInDirectedGraph_bfs(int V,vector<int> adjList[]){
    vector<int> indegree(V,0);
    for(int node=0;node<V;node++){
    	for(auto it : adjList[node]){
    		indegree[it]++;
    	}
    }
    queue<int> q;
    for(int node=0;node<V;node++) if(indegree[node] == 0) q.push(node);
    int cnt = 0;
    while(!q.empty()){
    	int node = q.front();
    	cnt++;
    	q.pop();
    	for(auto neighbour : adjList[node]){
    		indegree[neighbour]--;
    		if(indegree[neighbour] == 0) q.push(neighbour);
    	}
    }
	return (cnt != V);
}
int maxPathInMatrix(vvi grid){
	int n = grid.size();
	int m = grid[0].size();
	queue<pair<pair<int,int>,int>> q;
	vvi indegree(n,vi(m,0));
	int delrow[] = {+1,0,-1,0};
	int delcol[] = {0,-1,0,+1};
	for(int row=0;row<n;row++){
		for(int col=0;col<m;col++){
			for(int k=0;k<4;k++){
                int nrow = row + delrow[k];
                int ncol = col + delcol[k];
                if(nrow >=0 && nrow < n && ncol >=0 && ncol < m && grid[row][col] < grid[nrow][ncol])
                	indegree[nrow][ncol]++;
			}
		}
	}
	for(int row=0;row<n;row++){
		for(int col=0;col<m;col++){
            if(indegree[row][col] == 0) q.push({{row,col},1});
		}
	}
	int maxPath = 1;
	while(!q.empty()){
		int row = q.front().first.first;
		int col = q.front().first.second;
		int pathDist = q.front().second;
		q.pop();
		maxPath = max(maxPath,pathDist);
		for(int k=0;k<4;k++){
            int nrow = row + delrow[k];
            int ncol = col + delcol[k];
            if(nrow >=0 && nrow < n && ncol >=0 && ncol < m && grid[row][col] < grid[nrow][ncol]){
            	indegree[nrow][ncol]--;
            	if(indegree[nrow][ncol] == 0) q.push({{nrow,ncol},pathDist+1});
            }
		}
	}
	return maxPath;
}

int NumberOfIncreasingPathsInMatrix(vvi grid){
	int n = grid.size();
	int m = grid[0].size();
	queue<pair<int,int>> q;
	vector<vector<int>> indegree(n,vector<int>(m,0));
	int delrow[] = {+1,0,-1,0};
	int delcol[] = {0,-1,0,+1};
	for(int row=0;row<n;row++){
		for(int col=0;col<m;col++){
			for(int k=0;k<4;k++){
                int nrow = row + delrow[k];
                int ncol = col + delcol[k];
                if(nrow >=0 && nrow < n && ncol >=0 && ncol < m && grid[row][col] < grid[nrow][ncol])
                	indegree[nrow][ncol]++;
			}
		}
	}
	for(int row=0;row<n;row++){
		for(int col=0;col<m;col++){
            if(indegree[row][col] == 0) {
	             q.push({row,col});
	         }
		}
	}
    int mod = 1e9+7;
	vector<vector<long long int>> ans (n,vector<long long int>(m,1));
	while(!q.empty()){
		int row = q.front().first;
		int col = q.front().second;
		q.pop();
		for(int k=0;k<4;k++){
            int nrow = row + delrow[k];
            int ncol = col + delcol[k];
            if(nrow >=0 && nrow < n && ncol >=0 && ncol < m && grid[row][col] < grid[nrow][ncol]){
            		indegree[nrow][ncol]--;
            		if(indegree[nrow][ncol] == 0) q.push({nrow,ncol});
            		ans[nrow][ncol] += ans[row][col];
                    ans[nrow][ncol]%=mod;
            }
		}
	}
	long long int maxPath = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			maxPath += ans[i][j];
            maxPath%=mod;
		}
	}
	return (int)maxPath%mod;
}

int NumberOfIncreasingPathsInMatrix_bfs_helper(int i,int j,int n,int m,vector<vector<int>> &grid,vector<vector<int>> &dp,int val){
    if(min(i,j)<0 || i>=n || j>=m || grid[i][j]<=val) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int mod = 1e9+7;
    int up = NumberOfIncreasingPathsInMatrix_bfs_helper(i,j-1,n,m,grid,dp,grid[i][j]) % mod;
    int down = NumberOfIncreasingPathsInMatrix_bfs_helper(i-1,j,n,m,grid,dp,grid[i][j]) % mod;
    int right = NumberOfIncreasingPathsInMatrix_bfs_helper(i+1,j,n,m,grid,dp,grid[i][j]) % mod;
    int left = NumberOfIncreasingPathsInMatrix_bfs_helper(i,j+1,n,m,grid,dp,grid[i][j]) % mod;
    return dp[i][j] = (1 + up + down + left + right )%mod;
}

int NumberOfIncreasingPathsInMatrix_bfs(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(1002,vector<int>(1002,-1));
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans += NumberOfIncreasingPathsInMatrix_bfs_helper(i,j,n,m,grid,dp,0);
        }
    }
    return ans;
}
vector<int> Dijkstra_PQ(int Source,int V,vector<int> adjList[]){
    vector<int> distance(V,1e9);
    distance[Source] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,Source});
    while(!pq.empty()){
    	int dist = pq.top().first;
    	int node = pq.top().second;
    	pq.pop();
    	for(auto neighbour : adjList[node]){
    		if(dist + distance[node] < distance[neighbour]){
    			distance[neighbour] = dist + distance[node];
    			pq.push({distance[neighbour],neighbour});
    		}
    	}
    }
    return distance;
}
void readGraph(){
    int V,E;
    cin >> V >> E;
    vector<int> adjList[V];
    vvi adjMatrix(V,vi(V,0));
    for(int i=0;i<E;i++){
    	int u , v;
    	cin >> u >> v;
    	adjList[u].push_back(v);
    	adjList[v].push_back(u);
    	adjMatrix[u][v] = adjMatrix[v][u] = 1;
    }
    cout << DetectCyleInDirectedGraph_bfs(V,adjList);
}

vector<int> Dijkstra_Set(int Source,int V,vector<int> adjList[]){
     set<pair<int,int>> s;
     s.insert({0,Source});
     vector<int> distance(V,1e9);
     distance[Source] = 0;
     while(!s.empty()){
         pair<int,int> p = *(s.begin());
         int node = p.second;
         int dist = p.first;
         s.erase(p);
         for(auto neighbour : adjList[node]){
             if(dist + distance[node] < distance[neighbour]){
             	s.erase({distance[neighbour],neighbour});
             	distance[neighbour] = dist + distance[node];
             	s.insert({distance[neighbour],neighbour});
             }
         }
     }
     return distance;
 }
int flightsWithinKStops(int V,int Source,int destination,int k,vector<vector<int>> edges){
    vector<pair<int,int>> adjList[V];
    int e = edges.size();
    for(int i=0;i<e;i++){
    	adjList[edges[i][0]].push_back({edges[i][1],edges[i][2]});
    }
    vector<int> distance(V,1e9);
    distance[Source] = 0;
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{Source,0}}); // {k,{node,dist}}
    while(!q.empty()){
    	int nthstop = q.front().first;
    	int node = q.front().second.first;
    	int dist = q.front().second.second;
    	q.pop();
    	if(nthstop > k) continue; 
    	for(auto it:adjList[node]){
    		int adjNode = it.first;
    		int edgeWeight = it.second;
           if(dist + edgeWeight < distance[adjNode] && nthstop <= k){
	           	distance[adjNode] = dist + edgeWeight;
	           	q.push({nthstop+1,{adjNode,distance[adjNode]}});
           }
    	}
    }
    if(distance[destination] == 1e9) return -1;
    return distance[destination];
}

int maxIslandArea_bfs(int row,int col,vector<vector<int>> &grid,vector<vector<int>> &vis){
	int n = grid.size();
	int m = grid[0].size();
	if(row < 0 || row >= n || col < 0 || col >= m || grid[row][col] == 0 || vis[row][col] == 1) return 0;
	vis[row][col] = 1;
	int delcol[] = {-1,0,+1,0};
	int delrow[] = {0,-1,0,+1};
	int area = 0;
	for(int i=0;i<4;i++){
		int newrow = row + delrow[i] ;
		int newcol = col + delcol[i];
        area += maxIslandArea_bfs(newrow,newcol,grid,vis);
	}
	return 1 + area;
}
int maxIslandArea(vector<vector<int>> grid){
	int n = grid.size();
	int m = grid[0].size();
	vector<vector<int>> vis(n,vector<int> (m,0));
	int maxi = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!vis[i][j]) maxi = max(maxi,maxIslandArea_bfs(i,j,grid,vis)) ;
		}
	}
    cout << "max Area = "<<maxi<<endl;
    return maxi;
}

int ShortestDistanceInBinaryMaze(vector<vector<int>> grid){
	int n = grid.size();
	vvi distance(n,vi(n,1e9));
	distance[0][0] = 0;
	queue<pair<int,pair<int,int>>> q;
	q.push({0,{0,0}});
	int delrow[] = {0,-1,0,+1};
	int delcol[] = {+1,0,-1,0};
	while(!q.empty()){
		int dist = q.front().first;
		int row = q.front().second.first;
		int col = q.front().second.second;
		if(row == n-1 && col == n-1) break;
		for(int i=0;i<4;i++){
			int newrow = row + delrow[i];
			int newcol = col + delcol[i];
           if(newrow >= 0 && newrow <= n && newcol >= 0 && newcol < n && grid[newrow][newcol] == 1 && 1 + dist < distance[newrow][newcol] ){
                distance[newrow][newcol] = dist + 1 ;
           	    q.push({distance[newrow][newcol],{newrow,newcol}});
           }
		}
	}
	if(distance[n-1][n-1] == 1e9) return -1;
	return distance[n-1][n-1];
}
void kosarajusAlgorithmDFS1(int node,vector<int> &vis,vector<int> adjList[],stack<int> &st){
	vis[node] = 1;
	for(auto adjNode : adjList[node]){
		if(!vis[adjNode]) kosarajusAlgorithmDFS1(adjNode,vis,adjList,st);
	}
	st.push(node);
}
void kosarajusAlgorithmDFS2(int node,vector<int> &vis,vector<int> RadjList[],vector<int> &component){
	vis[node] = 1;
	component.push_back(node);
	for(auto adjNode : RadjList[node]){
		if(!vis[adjNode]) kosarajusAlgorithmDFS2(adjNode,vis,RadjList,component);
	}
}
vector<vector<int>> kosarajusAlgorithm(int V,vector<vector<int>> &edges){
	vector<int> vis(V,0);
	vector<int> adjList[V];
	vector<int> RadjList[V];
	for(auto edge : edges){
		adjList[edge[0]].push_back(edge[1]);
		RadjList[edge[1]].push_back(edge[0]);

	}
	stack<int> st;
	for(int node = 0;node<V;node++) if(!vis[node]) kosarajusAlgorithmDFS1(node,vis,adjList,st);
    vector<vector<int>> ConnectedComponents;
    vis = vector<int> (V,0);
    int cnt = 0;
    while(!st.empty()){
    	int node = st.top();
    	st.pop();
    	if(!vis[node]){
    	   vector<int> component;
	       cnt ++;
           kosarajusAlgorithmDFS2(node,vis,RadjList,component);
           ConnectedComponents.push_back(component);
    	}
    }
    cout << "Number of ConnectedComponents = " << cnt << endl;
    return ConnectedComponents;
}


bool isEuclidianPath_Directed(int V , vector<vector<int>> &edges){
      vector<int> indegree(V,0);
      vector<int> outdegree(V,0);
      for(auto edge : edges){
	      	indegree[edge[1]]++;
	      	outdegree[edge[0]]++;
      }
      int intermediateNodes = 0;
      int SourceNode = 0;
      int DestinationNode = 0;
      for(int i=0;i<V;i++){
	      	if(indegree[i] == outdegree[i]) intermediateNodes++;
	      	else if(indegree[i] - outdegree[i] == 1) DestinationNode++;
	      	else if(outdegree[i] - indegree[i] == 1) SourceNode++;
	      	else return false;
      }
      if(DestinationNode == 1 && SourceNode == 1 && intermediateNodes == V-2) return true;
      return false;
}

bool isEuclidianCircuit_Directed(int V , vector<vector<int>> &edges){
      vector<int> indegree(V,0);
      vector<int> outdegree(V,0);
      for(auto edge : edges){
	      	indegree[edge[1]]++;
	      	outdegree[edge[0]]++;
      }
      for(int i=0;i<V;i++) if(indegree[i] != outdegree[i]) return false;
      return true;
}

bool isEuclidianPath_UnDirected(int V,vector<vector<int>> edges){
     vector<int> degree(V,0);
     for(auto edge : edges){
     	degree[edge[0]]++;
     	degree[edge[1]]++;
     }
     int intermediateNodes = 0;
     int endNodes = 0;
     for(int i=0;i<V;i++){
     	if(degree[i]%2 == 0) intermediateNodes++;
     	else endNodes++;
     }
     if(intermediateNodes == V-2 && endNodes == 2) return true;
     return false;
}
bool isEuclidianCircuit_UnDirected(int V,vector<vector<int>> edges){
     vector<int> degree(V,0);
     for(auto edge : edges){
     	degree[edge[0]]++;
     	degree[edge[1]]++;
     }
     int intermediateNodes = 0;
     int endNodes = 0;
     for(int i=0;i<V;i++) if(degree[i]%2) return false;
     return true;
}
void MotherVertexDfs(int node,vector<int> &vis,vector<int> adjList[],stack<int> &st){
	 vis[node] = 1;
	 for(auto adjNode : adjList[node]){
		 if(!vis[adjNode]) MotherVertexDfs(adjNode,vis,adjList,st);
	 }
	 st.push(node);
}
int findMotherVertex(int V,vector<vector<int>> &edges){
/*
Reaching the Solution -

Approach-1 : indegree == 0 concept doesnt work here because the directed graph may
		     contain a simple cycle then indegree of all nodes == 1. (Wrong)

Approach-2 : We can have topological sort and then independent vertex will be in the
		     first position of the topoligical sort . but applying bfs(queue) i.e
		     using kahn's algorithm we cannot retrieve the topological sort because ,
		     in kahn's algorihtm(bfs) we start with the nodes with indegree == 0. (Wrong)

Approach-3 : We can still go with toposort through dfs . Though the toposort would be wrong in this
             dfs incase of cyclic Directed Graphs , But We can assume that this toposort is correct
             and check wether it is possible to reach all the nodes from the top node in the stack.

             we push the node after its dfs call is completed;

 case 1: we have a mother vertex - 

        case 1.a - suppose we have source as mother vertex then => this source would end up visiting
                   all nodes and this node will be pushed in the last and stay as the top of the stack.

        case 1.b - suppose we start dfs with a non Mother vertex .
        	       There can be again 2 Cases - 

        	       1.b.1 - (This case Boils to Case 1.a) Mother vertex is reached from the first dfs Source node.
        	               if the source node reaches the mother vertex and then mother vertex will
        	               reach all the nodes.
        	               But the key observation is that any node that can reach mother vertex is 
        	               also a mother vertex.

        	       1.b.2 - mother vertex is unreachable from source vertex.
        	               i.e after the completion of dfs call of Source vertex there will be
        	               still unvisited nodes which includes Mother vertex and when called via dfs
        	               then this mother vertex would still come at the top of the stack.

        	               >> let's consider a worst case scenario for 1.b.2

        	               0 <-- 1 <-- 2 <-- 3
        	               source = 0
        	               dfs(0) -> only 0 visted (bottom of stack)
        	               dfs(1) -> only 1 visited (top of 0)
        	               dfs(2) -> only 2 visited (top of 1)
        	               dfs(3) -> only 3 visited (top of 2) => Final top of stack

        	               >> another example 1.b.2

        	               2 <-- 0 --> 1 
                                 ^
                                 |
                                 3
                            source = 0
                            dfs(0) -> dfs(1) -> dfs(2) nodes 2,1,0 are visited (node 0 is at top)
                            now dfs(3) -> only 3 visted (final top of stack)

case 2: we do not have a mother vertex -
	    Then stack will conatain vertices in order of completion time of dfs calls
	    so the last completed dfs call for a node would remain at the top of the stack
	    so from that node we again do a simple dfs to validate mother vertex , and then all
	    node will not be visited and we will return -1.
	*/
	vector<int> adjList[V];
	for(auto edge : edges){
         adjList[edge[0]].push_back(edge[1]);
	}
    stack<int> st;
    vector<int> vis(V,0);
    for(int node = 0;node<V;node++) if(!vis[node]) MotherVertexDfs(node,vis,adjList,st);
    int MotherVertex = st.top();
    vis = vector<int> (V,0);
    queue<int> q;
    q.push(MotherVertex);
    vis[MotherVertex] = 1;
    int visitedNodes = 0;
    while(!q.empty()){
    	int node = q.front();
    	q.pop();
    	visitedNodes++;
    	for(auto adjNode : adjList[node]){
    		if(!vis[adjNode]){
    			q.push(adjNode);
    			vis[adjNode] = 1;
    		}
    	}
    }
	return ((visitedNodes == V) ? MotherVertex : -1);
}

void longestCycleInDG_dfs(int node,vector<int> &vis,vector<int> &pathVis,vector<int> adjList[],int &maxi){
      for(int adjNode : adjList[node]){
            if(!vis[adjNode]){
                  vis[adjNode] = 1;
                  pathVis[adjNode] = pathVis[node] + 1;
                  longestCycleInDG_dfs(adjNode,vis,pathVis,adjList,maxi);
                  pathVis[adjNode] = -1;
            }
            else if(pathVis[adjNode] != -1){
                  maxi = max(maxi,pathVis[node] - pathVis[adjNode] + 1);
            }
      }
}

int longestCycleInDG(){

  /*
	 only works when every node has atmax one outgoing edge ,
	 which means that there is atmax one way to reach from node u to node v (observe)
	 
	 else it boils down to np hard problem , which involves checking for cycles starting at each node
	  then all you need to do is apply the same algorithm for each vertex with new visited and new pathvisited 
	  array evrerytime for each node

	  the optimal approach to this problem is Johnsons Algorihtm  -> tushar youtube (concept) 
  */

	int n , e;
  cin >> n >> e;
  vector<int> adjList[n];
  for(int i=0;i<e;i++){
      int u , v;
      cin >> u >> v;
      adjList[u].push_back(v);
  }
  int maxi = -1;
  vector<int> vis(n,0), pathVis(n,-1);
  for(int i=0;i<n;i++){
      if(!vis[i]){
            vis[i] = 1;
            pathVis[i] = 0;
            longestCycleInDG_dfs(i,vis,pathVis,adjList,maxi);
            pathVis[i] = -1;
      }
  }
  return maxi;
}

int main(){
	int v , e;
	cin >> v >> e;
	vector<vector<int>> edges(e,vector<int>(2,0));
	for(int i=0;i<e;i++){
	  cin >> edges[i][0] >> edges[i][1];
	  edges[i][0];
	  edges[i][1];
	}
	// vvi nums = kosarajusAlgorithm(v,edges);
	// piv2(nums);
	cout << "mother vertex = " << findMotherVertex(v,edges)<<endl;
    cout << "DEAD END" << endl;
}