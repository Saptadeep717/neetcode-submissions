class Solution {
public:
    bool isPossible(vector<int>&piles, int rate, int h){
        int n = piles.size();
        int hoursNeeded = 0;
        for(int i=0;i<n;i++){
            hoursNeeded+= ceil ((piles[i] *1.00) / (rate*1.00));
        }
        cout<<hoursNeeded<<" -> "<< rate<<endl;
        return hoursNeeded<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low=1, high = *max_element(piles.begin(),piles.end());
        int ans = 0;
        while(low<=high){
            int mid = low + (high-low)/2;

            if(isPossible(piles, mid, h)){
                ans = mid;
                high=mid-1;
            }else low=mid+1;
        }

        return ans;
    }
};
