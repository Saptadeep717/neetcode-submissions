/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    using p = pair<int,int>;
    int minMeetingRooms(vector<Interval>& intervals) {
       int n = intervals.size();
        map<int,int>mpp;
        int ans =0, res=0;
        for(int i=0;i<n; i++){
            mpp[intervals[i].start] += 1;
            mpp[intervals[i].end] -= 1;
        }
        for(auto it : mpp){
            ans+=it.second;
            res = max(res,ans);
        }
        return res;
    }
};
