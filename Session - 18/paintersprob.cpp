class Solution {
  public:
  
    int minTime(vector<int>& arr, int k) {
        
        int n = arr.size();
        
        int l = *max_element(arr.begin(), arr.end());  
        int r = 0;                                     
        
        for(int i=0;i<n;i++){
            r+=arr[i];
        }
        
        int ans=r;
        
        while(l<=r){
            
            int mid=l+(r-l)/2;
            
            int painters=1;
            int currSum=0;
            
            for(int i=0;i<n;i++){
                
                if(currSum+arr[i]<=mid){
                    currSum+=arr[i];
                }
                else{
                    painters++;
                    currSum=arr[i];
                }
            }
            
            if(painters<=k){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;  
            }
        }
        
        return ans;
    }
};
