#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main(){
    int n;
    cout<<"enter no. of records:";
    cin>>n;
    vector<char> arr(n);
    cout<<"enter attendance(P - present,A - absent):";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    unordered_map<int,int> mp;
    mp[0]= -1;  
    int sum=0;
    int maxlen=0;
    for (int i=0;i<n;i++){
        if(arr[i]=='P'){
            sum+=1;
        }
        else if(arr[i]=='A'){
            sum-=1;
        }
        else{
            cout<<"invalid input";
            return 0;
        }

        if(mp.find(sum)!=mp.end()){
            maxlen = max(maxlen, i-mp[sum]);
        } 
        else{
            mp[sum]=i;
        }
    }
    if(maxlen==0){
        cout<<"0";
    } 
    else{
        cout<<"max length:"<<maxlen;
    }
    return 0;
}