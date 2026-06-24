class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prer) {
        int n = prer.size();
        unordered_map<int, vector<int> >adj;
        vector<int>indeg(numCourses,0), topo;
        for(int i =0;i<n;i++){
            adj[prer[i][1]].push_back(prer[i][0]);
            indeg[prer[i][0]]++;
        }


        queue<int>q;
        for(int i=0;i<numCourses; i++){
            if(indeg[i]==0)q.push(i);
        }

        while(!q.empty()){
            int val = q.front();
            q.pop();
            topo.push_back(val);

            for(auto it : adj[val]){
                indeg[it]--;
                if(indeg[it]==0)q.push(it);
            }
        }

        return topo.size()==numCourses ? topo : vector<int>();

    }
};
