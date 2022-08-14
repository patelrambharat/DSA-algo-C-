vector<int> dijkstra(int src, int n ) {
        vector<int> dist(n, INT_MAX);

        //distance, nodeName
        set<pair<int,int> > st;

        //initial step:
        dist[src] = 0;
        st.insert(make_pair(0,src));

        while(!st.empty()) {
            //step1: get the top element
            auto top = *(st.begin());
            //pop
            st.erase(st.begin());

            int nodeDistance = top.first;
            int node = top.second;

            //step2: explore neighbour
            for(auto neighbour: adjList[node]) {
                //neighbour.first -> neighbour node name
                //neighbour.second -> neighbour weight
                
                if(nodeDistance + neighbour.second < dist[neighbour.first]) {
                    //remove old record
                    auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                    //if record is found, then erase it
                    if(record != st.end()) {
                        st.erase(record);
                    }

                    //dist update
                    dist[neighbour.first] = nodeDistance + neighbour.second ;

                    //push new record
                    st.insert(make_pair(dist[neighbour.first], neighbour.first));
                }
            }
        }
        return dist;
    } 