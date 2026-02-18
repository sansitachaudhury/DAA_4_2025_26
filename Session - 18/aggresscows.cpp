class Solution {
public:

    bool isPos(vector<int>& stalls,int k,int dist){

        int cows=1;
        int last=stalls[0];

        for (int i=1;i<stalls.size();i++){

            if(stalls[i]-last>=dist){
                cows++;
                last=stalls[i];
                if(cows>=k)
                    return true;
            }
        }
        return false;
    }
int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(),stalls.end());
        int l=1;
        int r=stalls.back()-stalls[0];
        int ans=0;
        while(l<=r){
            int mid=(l+r)/2;

            if(isPos(stalls,k,mid)){
                ans=mid;
                l=mid+ 1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};