void topoSort() {
        //step1: find out all indegrees
        map<int, int> indegree;
        queue<int> q;

        //initialse indegree with 0
        for(auto i: adjList) {
            indegree[i.first] = 0;
        }
        
        for(auto i: adjList) {
            for(auto j: i.second) {
                indegree[j]++;
            }
        }

        //step2: push in q, indegree -> 0
        for(auto i: indegree) {
            if(i.second == 0) {
                q.push(i.first);
            }
        }

        //step3: BFS
        while(!q.empty()) {
            int front = q.front();
            cout << front << " ";
            q.pop();

            for(auto neigh: adjList[front]) {
                indegree[neigh]--;
                if(indegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }
    cout << endl;
        
    }
