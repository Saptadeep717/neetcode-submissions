using pvi = pair<int, vector<int>>;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        int n = points.size();
        priority_queue<pvi>pq;

        for(int i = 0; i<n; i++){
            int dis = points[i][0]*points[i][0] + points[i][1]*points[i][1];

            pq.push({dis,{points[i][0], points[i][1]}});
            if(pq.size() > k)pq.pop();
        }

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
