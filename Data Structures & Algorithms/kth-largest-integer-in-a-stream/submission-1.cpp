class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>minH;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i=0;i<nums.size();i++){
            minH.push(nums[i]);
            if(minH.size() > k) minH.pop();
        }
    }
    
    int add(int val) {
        minH.push(val);
        if(minH.size() > k) minH.pop();
        return minH.top();
    }
};
