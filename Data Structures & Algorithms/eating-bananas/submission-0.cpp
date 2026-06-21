class Solution {
public:
    bool isPossible(int mid, vector<int>&piles, int h){
        double time = 0;
        for(int i=0;i<piles.size();i++){
            time += ceil((double)piles[i] / (double)mid);
        }
        cout<<time<<" , "<< mid << endl;
        return (int)time <=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1, end = *max_element(piles.begin(),piles.end());
        int ans =0;
        while(start<=end){
            int mid = start + (end-start)/2;

            if(isPossible(mid,piles,h)){
                ans = mid;
                end = mid-1;
            }else start=mid+1;
        }

        return ans ;
    }
};
