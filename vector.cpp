#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<unordered_map>
#include<unordered_set>
using namespace std;

int singlenumber(vector <int> &v){   //[O(n)]
    int ans=0;
    for(int i:v){
        ans=ans^i;}
    cout<<ans<<endl;
    return ans;}

int maxsa(int arr[],int n){   //bruteforce  [O(n2)]
    int maxsum=INT8_MIN;
    for (int st = 0; st<n; st++){
        int currsum=0;
        for (int end = st; end<n; end++){
            currsum=currsum+arr[end];
            maxsum=max(currsum,maxsum);}}
        
    cout<<"the max subarray sum ="<<maxsum<<endl;}


int kadansalgo(int arr[],int n){  //[O(n)]
    int maxsum=INT16_MIN;
            int currsum=0;
    for (int i = 0; i < n; i++){
        currsum=currsum+arr[i];
        maxsum=max(currsum,maxsum);
        if (currsum<0){
            currsum=0;}}
    cout<<"maximum subarray is = "<<maxsum<<endl;}


int pairsum(vector<int> num,int target){// [O(n2)]
    int n=num.size();
    for(int i=0;i<n;i++){
        for (int j = 0; i < n; j++){
            if (num[i]+num[j]==target){
            cout<<num[i]<<" and "<<num[j]<<" is "<<target<<endl;}}}}



int pairsumtwoptr(vector<int> v,int target){  //[O(n)]
    int n=v.size();
    int i=0,j=n-1;
    while(i<j){
        int ps=v[i]+v[j];
        if (ps<target){i++;}

        else if(ps>target){j--;}
        
        else if(ps==target){
            i++,j--;                  //loop se out hone ke liye
            cout<<v[i]<<" and "<<v[j]<<endl;}}}


int majority(vector<int> v){          //[O(n2)]

    int n=v.size();
    for(int i=0;i<n;i++){
        int ans=0;
        for(int j=0;j<n;j++){
            if(v[i]==v[j]){
                ans++;}}

        if(ans>n / 2){cout<<v[i]<<endl;
        return ans;}}}

int power(int x,int n){
    int bf=n;
    int ans=1;
    while (bf>0){
    if (bf%2==1)   {ans *= x;}
    x*=x;
    bf=bf/2;}
    cout<<ans<<"\n";}

int container(int arr[],int n){
    int maxwater=0;
    for (int i = 0; i <n; i++){
        for (int j=i+1; j<n;j++){
        int wt = j-i;
        int ht = min(arr[i],arr[j]);
        int area =wt*ht;
        maxwater=max(area,maxwater);}}
        cout<<maxwater<<endl;}


int subarrsumtarget(vector<int> &arr ,int t){
    int n = arr.size();

    int count = 0;
    for (int i = 0; i < n; i++)
    {    int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum+=arr[j];
            if (sum == t) count++;}}
    return count;
}

int subarrsumtarget_prefixsum(vector<int> &arr , int t){
    vector<int> prifixsumm;
    int count = 0;
    prifixsumm[0] = arr[0];

    for (int i = 1; i < arr.size() ; i++){
        prifixsumm[i] = prifixsumm[i-1]+arr[i];}

    unordered_map<int , int> m;
    for (int j = 0; j < count; j++)
    {
        if(prifixsumm[j] == t) count++;
        int val = prifixsumm[j] - t;
        if(m.find(val) != m.end())
        {
            count +=m[val];
        }
        
    }
    

}



int main(){
    int heights[]={1,8,6,2,5,4,8,3,7};
    container(heights,9);
 

}