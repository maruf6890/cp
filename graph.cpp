/*
 * 
 * 
 * Basic DFS Template
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
void initialize() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

const int MAX = 1e4 + 10;  
vector<int> g[MAX];  
bool visited[MAX];

void dfs(int vertex)
{
     // Before entering the child vertex (pre-visit action can go here)


    visited[vertex] = true;
    

    for (auto child : g[vertex]) {
        if (visited[child]) continue;  

        // Before entering the child vertex (pre-visit action can go here)
        dfs(child);  
        // After returning from child vertex (post-visit action can go here)
    }
     // After returning fromvertex (post-visit action can go here)
}

int main(void) {
    initialize();

    int vertex, edge;
    cin >> vertex >> edge;

    // Input graph edges
    for (int i = 0; i < edge; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);  
        g[b].push_back(a);  
    }
    dfs(1);  
    return 0;
}






//#include <bits/stdc++.h>
using namespace std;
const int MAX=10e5+10;
vector<int> graph[MAX];
bool isVisited[MAX];
void dfs(int vertex){
    isVisited[vertex]=true;
    
    //operation before accessing any vertax
    //cout<<vertex<<" ";
    for(auto child: graph[vertex])
    {
        
        if(isVisited[child])continue;
        //operation before entering any children
        
        // cout<<child<<" ";
        dfs( child);
        
         ////operation before exiting any vertax
    }
  
}
int main() {
	int v,e;
	cin>>v>>e;
	for(int i=1; i<=e; i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        
    }
    dfs(1);
    cout<<endl;
    
}

/*
 * 
 * 
 * connected component and all connected graph
 * 
 * 
 */

#include <bits/stdc++.h>

using namespace std;
const int MAX = 10e6 + 10;
vector < int > graph[MAX];
bool isVisited[MAX];
vector < int > currentGraph;
vector < vector < int > > connectedCommponent;
void dfs(int vertex) {
    isVisited[vertex] = true;
    currentGraph.push_back(vertex);
    for (auto child: graph[vertex])
    {
        if (isVisited[child]) continue;
        dfs(child);
    }

}
int main() {
    int v, e;
    cin >> v >> e;

    for (int i = 1; i <= e; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);

    }
    int c = 0;
    for (int i = 1; i <= v; i++)
    {
        if (isVisited[i]) continue;
        dfs(i);
        connectedCommponent.push_back(currentGraph);
        currentGraph.clear();
        c++;

    }
    for (auto v: connectedCommponent) {
        for (auto commponent: v) {
            cout << commponent << " ";
        }
        cout << endl;
    }




    cout << c << endl;


}


/*
 * 
 * 
 * Cycle Detection
 * 
 * 
 */


#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 10;
vector<int> graph[MAX];
bool isVisited[MAX];
bool isLooped = false;

bool dfs(int vertex, int parent) {
    isVisited[vertex] = true;
    
    for (auto child: graph[vertex]) {   
        if (isVisited[child] && child == parent) continue;  // Skip parent
        if (isVisited[child]) return true;  // Cycle detected
        if (dfs(child, vertex)) return true;
    }
    return false;
}

int main() {
    int v, e;
    cin >> v >> e;

    // Building the graph
    for (int i = 1; i <= e; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // Check for cycles in each component
    for (int i = 1; i <= v; i++) {
        if (!isVisited[i]) {
            if (dfs(i, -1)) {  // Start DFS from unvisited node
                isLooped = true;
                break;
            }
        }
    }

    // Output result
    if (isLooped) {
        cout << "Cycle detected" << endl;
    } else {
        cout << "No cycle found" << endl;
    }

    return 0;
}



///Matrix 



/*
 * 
 * 
 * DFS in tree
 * 
 * 
 */


#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 10;
vector<int> graph[MAX];

void dfs(int vertex, int parents)
{
    cout << vertex << " ";
    for(auto child: graph[vertex])
    {   
        if(parents == child) continue; // Skip if the child is the parent
        dfs(child, vertex); // Perform DFS on the child
    }
}

int main() {
    int vertex, edge;
    cin >> vertex >> edge; 
    
   
    for(int i = 1; i <= edge; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    
    dfs(1, -1);
}


/*
 * 
 * 
 * depth(top to bottom) and height (bottom to top) of a tree
 * 
 * 
 */

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 10;  
vector<int> graph[MAX];   
bool isVisited[MAX];      

int height[MAX]; 
int depth[MAX];  


void dfs(int vertex, int parents) {
    cout << vertex << " "; 
    
    
    for (auto child : graph[vertex]) {
        if (parents == child) continue;     
        // Calculate depth of the child (depth of parent + 1)
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
        // Calculate height of the current vertex (maximum height of children + 1)
        height[vertex] = max(height[vertex], height[child] + 1);
    }
}

int main() {
    int vertex, edge;
    cin >> vertex >> edge;  
    
    
    for (int i = 1; i <= edge; i++) {
        int a, b;
        cin >> a >> b;         
        graph[a].push_back(b);   
        graph[b].push_back(a); 
    }

    
    dfs(1, -1);
    
    cout << endl;

    // Output depth of each vertex
    cout << "Depth:" << endl;
    for (int i = 1; i <= vertex; i++) {
        cout << i << " -> " << depth[i] << endl;
    }

    // Output height of each vertex
    cout << "Height:" << endl;
    for (int i = 1; i <= vertex; i++) {
        cout << i << " -> " << height[i] << endl;
    }
}


//subtree calculation
//sub tree sum+ find even
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 10;
vector<int> graph[MAX];  // Adjacency list to represent the graph
int subtreeSum[MAX];     // Array to store the sum of each subtree

// DFS function to calculate subtree sums
void dfs(int vertex, int parents) {
    subtreeSum[vertex] = vertex;  // Initialize subtree sum with the value of the vertex
    
    // Traverse through all the children (adjacent vertices)
    for (auto child : graph[vertex]) {
        if (parents == child) continue;  // Skip the parent node to prevent backtracking

        // Recursively perform DFS on the child
        dfs(child, vertex);

        // Add the child's subtree sum to the current vertex's subtree sum
        subtreeSum[vertex] += subtreeSum[child];
    }
}

int main() {
    int vertex, edge;
    cin >> vertex >> edge;  // Input number of vertices and edges
    
    // Input edges and build the adjacency list for the graph
    for (int i = 1; i <= edge; i++) {
        int a, b;
        cin >> a >> b;           // Read edge between nodes a and b
        graph[a].push_back(b);    // Add b as a neighbor of a
        graph[b].push_back(a);    // Add a as a neighbor of b (since it's an undirected graph)
    }

    // Perform DFS starting from vertex 1, with -1 as the parent
    dfs(1, -1);

    // Query for subtree sums
    int q;
    cin >> q;  // Input number of queries
    while (q--) {
        int x;
        cin >> x;  // Input vertex to query
        cout << subtreeSum[x] << endl;  // Output the subtree sum of the given vertex
    }

    return 0;
}
// count even element 
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 10;
vector<int> graph[MAX];
int evenCount[MAX];

void dfs(int vertex, int parents) {
    if (vertex % 2 == 0) {
        evenCount[vertex] = 1;
    }

    for (auto child : graph[vertex]) {
        if (parents == child) continue;

        dfs(child, vertex);
        evenCount[vertex] += evenCount[child];
    }
}

int main() {
    int vertex, edge;
    cin >> vertex >> edge;

    for (int i = 1; i <= edge; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, -1);

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        cout << evenCount[x] << endl;
    }

    return 0;
}

//diameter of tree 
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 10;
vector<int> graph[MAX];
int depth[MAX];

void dfs(int vertex, int parents) {
    for (auto child : graph[vertex]) {
        if (parents == child) continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
    }
}

int main() {
    int vertex, edge;
    cin >> vertex >> edge;

    // Edge count must be vertex - 1 for it to be a valid tree
    if (edge != vertex - 1) {
        cout << "Invalid input, this is not a tree." << endl;
        return 0;
    }

    // Input graph
    for (int i = 1; i <= edge; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // First DFS from an arbitrary node (1 in this case)
    dfs(1, -1);

    // Find the farthest node from node 1
    int maxDepth = 0;
    int maxDepthNode = 1;
    for (int i = 1; i <= vertex; i++) {
        if (depth[i] > maxDepth) {
            maxDepth = depth[i];
            maxDepthNode = i;
        }
    }

    // Reset depth array for the second DFS
    memset(depth, 0, sizeof(depth));

    // Second DFS from the farthest node found
    dfs(maxDepthNode, -1);

    // Find the diameter of the tree
    int diameter = 0;
    for (int i = 1; i <= vertex; i++) {
        if (depth[i] > diameter) {
            diameter = depth[i];
        }
    }

    cout << diameter << endl;
    return 0;
}

//lowest common ansistor

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 10;
vector<int> graph[MAX];
int parent[MAX]; // Changed from parents[] to parent[] for clarity

// DFS to record parent of each node
void dfs(int vertex, int par) {
    parent[vertex] = par;  // Record the parent of the current vertex
    for (auto child : graph[vertex]) {
        if (child == par) continue; // Avoid going back to the parent
        dfs(child, vertex);
    }
}

// Function to build the path from node to root
vector<int> path(int vertex) {
    vector<int> pathVect;
    while (vertex != -1) { // Traverse upwards to the root
        pathVect.push_back(vertex);
        vertex = parent[vertex]; // Move to the parent
    }
    reverse(pathVect.begin(), pathVect.end()); // Reverse to get the path from root to the node
    return pathVect;
}

int main() {
    int vertex, edge;
    cin >> vertex >> edge;

    // Input graph
    for (int i = 1; i <= edge; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // Perform DFS starting from node 1 to set up the parent array
    dfs(1, -1);

    // Input the two nodes x and y for which we want to find the LCA
    int x, y;
    cin >> x >> y;

    // Get the paths from x and y to the root
    vector<int> pathX = path(x);
    vector<int> pathY = path(y);

    // Find the LCA by comparing the paths
    int minLen = min(pathX.size(), pathY.size());
    int lca = -1;

    for (int i = 0; i < minLen; i++) {
        if (pathX[i] == pathY[i]) {
            lca = pathX[i]; // Update LCA if the nodes are the same
        } else {
            break; // Paths diverge here, so stop
        }
    }

    // Output the LCA
    cout << lca << endl;

    return 0;
}

//edge deletion


//bfs
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 10;
vector<int> graph[MAX];
int level[MAX];
bool visited[MAX];

void bfs(int source) {
    queue<int> q;
    q.push(source);
    visited[source] = true;
    level[source] = 0;

    while (!q.empty()) {
        int currentV = q.front();
        q.pop();
        cout << currentV << " ";

        for (auto child : graph[currentV]) {
            if (!visited[child]) {
                q.push(child);
                visited[child] = true;
                level[child] = level[currentV] + 1;
            }
        }
    }
    cout << endl;
}

int main() {
    int vertex, edge;
    cin >> vertex >> edge;

    for (int i = 1; i <= edge; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs(1);

    return 0;
}
//shortest path
//multi source bsf

//digestra

//warshell algorithom

//disjoint set union

//krushkal algorithom