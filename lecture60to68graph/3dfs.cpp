void dfs(int src, map<int, bool>& visited ) {
        visited[src] = true;
        cout << src << ", ";

        for(auto neighbour: adjList[src]) {
            if(!visited[neighbour]) {
                dfs(neighbour, visited);
            }
        }
    }
void dfs(int src, map<int, bool>& visited ) {
        visited[src] = true;
        cout << src << ", ";

        for(auto neighbour: adjList[src]) {
            if(!visited[neighbour]) {
                dfs(neighbour, visited);
            }
        }
    }
    Graph<int> g2;
    g2.addEdge(0,2,0);
    g2.addEdge(2,3,0);
    g2.addEdge(2,4,0);
    g2.addEdge(3,4,0);
    g2.addEdge(1,3,0);
    
    cout << "Printing DFS Traversal " << endl;
    
    map<int, bool> visited2;
    for(int i=0; i<5; i++) {
        if(!visited[i]) {
            g2.dfs(i, visited);
        }
    }
    //g2.dfs(0, visited2);
    