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
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        map<int,int>mpp;
        int ans =0;
        for(int i=0;i<n; i++){
            mpp[intervals[i].start] += 1;
            mpp[intervals[i].end] -= 1;
        }
        for(auto it : mpp){
            ans+=it.second;
            if(ans > 1) return false;
        }
        return true;
    }
};
