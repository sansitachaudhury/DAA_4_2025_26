#include<bits/stdc++.h>
using namespace std;

int lower_bound(vector<int> arr, int n, int x){
    int l = 0;
    int r = n-1;
    int ans = n;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(arr[mid] >= x){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return ans;
}
int upper_bound(vector<int> arr, int n, int x){
    int l = 0;
    int r = n-1;
    int ans = n;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(arr[mid] > x){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return ans;
}
int main(){
    vector<int> arr = {0,1,3,4,5,6};
    vector<int> arr2 ={1,7,6,8,3,4,5};
    int sum = 4;
    sort(arr2.begin(), arr2.end());
    for(int i=0;i<arr.size();i++){
        int target = sum-arr[i];
        int lb = lower_bound(arr2, arr2.size(), target);
        int ub = upper_bound(arr2, arr2.size(), target);
        cout<<arr[i]<<" "<<
            target<<" "<<"occurence"<<" "<<ub-lb<<endl;
    }        
}

