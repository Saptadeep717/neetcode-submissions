class Solution {
public:
    
    
    int trap(vector<int>& h) {
        int n = h.size();
        int left=0,right=n-1,leftMax=0,rightMax=0,ans=0;
        while(left<right){
            //that means i am sure that something bigger is alaways in right
            if(h[left]<=h[right]){
                if(leftMax<=h[left]) leftMax=h[left];
                //then this point has something also bigger on left side
                else ans+= (leftMax-h[left]);
                left++;
            }
             //that means i am sure that something bigger is alaways in left
            else{
                 if(rightMax<=h[right]) rightMax=h[right];
                //then this point has something also bigger on right side
                else ans+= (rightMax-h[right]);
                right--;
            }
        }

        return ans;
      
        

    }
};
