class MedianFinder {
public:
    priority_queue<int>maxH;
    priority_queue<int,vector<int>,greater<int>>minH;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxH.push(num);
        minH.push(maxH.top());
        maxH.pop();

        if(maxH.size() < minH.size()){
            maxH.push(minH.top());
            minH.pop();
        }

    }
    
    double findMedian() {
        if(maxH.size() > minH.size()) return maxH.top();
        return (double) (maxH.top() + minH.top())/2.00;
    }
};
