class Solution {
public:
    using p = pair<int,int>;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int n = nums.size();
        for(int i=0;i<n;i++)mpp[nums[i]]++;

        priority_queue<p, vector<p>, greater<p>>pq;
        for(auto it:mpp){
            pq.push({it.second, it.first});
            if(pq.size()>k)pq.pop();
        }
        vector<int>ans;
        while(pq.size() >0 ){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
