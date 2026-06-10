class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        int m= edges.size();
        // logweights used and then negated and then finding the minimum distance sum
        vector<double> logweights(m,0);
        for(int i=0;i<m;i++){
            logweights[i]=-log(succProb[i]);
        }
        priority_queue<
            pair<double, int>,
            vector<pair<double, int>>,
            greater<pair<double, int>>
        > pq;
        // adjacency list used with pair node, weight to reach there with index as source
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<m;i++){
            vector<int> vec = edges[i];
            int u=vec[0];
            int v=vec[1];
            double w=logweights[i];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        // this is most important thing, the distance vector which stores minimum distance travelled to reach there
        vector<double> dist(n,INT_MAX);
        dist[start_node]=0;
        pq.push({0,start_node});
        while(!pq.empty()){
            auto p = pq.top();
            double currdist = p.first;
            int node = p.second;
            pq.pop();
            // the current distance is more than the minimum we already have, then skip
            if(currdist>dist[node]) continue;
            // if not then proceed to see the neighbors
            for(auto it : adj[node]){
                int neighbor=it.first;
                double weight=it.second;
                // adding the weight
                double newdist = currdist+weight;
                if(dist[neighbor]>newdist){
                    dist[neighbor]=newdist;
                    pq.push({newdist,neighbor});
                }
            }
        }
        return exp(-dist[end_node]);
    }
};