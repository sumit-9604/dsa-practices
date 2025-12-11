#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int printarr(vector <int> &v,int n){
    for (int i = 0; i <n; i++){
        cout<<v[i]<<"\t"<<endl;}}



int Bubble(vector<int> &v ,int n){      //O[n2]
    for (int  i = 0; i <n-1; i++){
        for (int j = 0; j<n-i-1; j++){
            if (v[j]>v[j+1]){
                swap(v[j],v[j+1]);}}}}



int selection(int arr[],int n){
    for (int i = 0; i < n-1; i++){
        int smallindex=i;
        for (int j= i+1; j<n ; j++){
            if (arr[j]<arr[smallindex]){
                smallindex=j;}}
        swap(arr[i],arr[smallindex]);}}


int insertion(int arr[],int n){
    for (int i = 0; i < n-1; i++){
        int curr=arr[i];
        int prev=i-1;
        while (prev >= 0 && arr[prev]>curr){
            arr[prev+1]=arr[prev];
            prev--;}
        arr[prev+1]=curr;}}


int dutch(vector<int>&v){
    int low=0;
    int mid=0;
    int high=v.size()-1;
    while(mid<=high){
        if(v[mid]==0){
            swap(v[mid],v[low]);
            mid++;
            low++;}

        else if(v[mid]==1)
            {mid++;}

        else{
            swap(v[mid],v[high]);
            high--;}}}



void nextarr(vector<int>&v){
    int pivit= -1;
    int n= v.size();

    for (int i = n-2; i >=0; i--){
        if (v[i]<v[i+1]){
            pivit =i;
            break;}}
    if(pivit==-1){
        reverse(v.begin(),v.end());
        return ;}


    for (int i = n-1; i >=0; i--){
        if (v[pivit]<v[i]){
            swap(v[pivit],v[i]);
            break;}}

    int i=pivit+1;
    int j=n-1;
    while(i<j){
        swap(v[i++],v[j--]);}}

void merge(vector<int> &arr , int st, int mid , int end){
    vector<int> temp;
    int i = st;
    int j = mid+1;
    while (i<=mid && j <= end){
        
        if (arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;}

        else{
            temp.push_back(arr[j]);
            j++;}}
    
    while (i<=mid){
        temp.push_back(arr[i]);
        i++;}

    while(j<= end){
        temp.push_back(arr[j]);
        j++;}
        
    for (int idx = 0; i < temp.size(); i++){   // copying temp into array
        arr[idx+st] = temp[idx];}
}


int partition (vector<int> &arr , int st , int end){
    int idx = st-1;
    int pvt = arr[end];
    for (int j = 0; j < end; j++){
        if (arr[j] <= pvt){
            idx++;
            swap(arr[j],arr[idx]);}}

    idx++;
    swap(arr[end],arr[idx]);
    return idx;}


void quicksortrecursive(vector<int> &arr , int st , int end){
    if (st < end){
        int pvtidx = partition(arr,st,end);
        quicksortrecursive(arr,st,pvtidx-1);
        quicksortrecursive(arr,pvtidx+1,end);
        
    }
    
}



void mergesortrecursive(vector<int> &arr , int st , int end){
    //O(nlogn)
    if(st<end){
    int mid = st+(end-st)/2;
    mergesortrecursive(arr,st,mid);
    mergesortrecursive(arr,mid+1,end);

    merge(arr,st,mid,end);}}
 
int mergeinversioncount(vector<int> &arr , int st, int mid , int end){
    vector<int> temp;
    int i = st;
    int j = mid+1;
    int count = 0;
    while (i<=mid && j <= end){
        
        if (arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;}

        else{
            temp.push_back(arr[j]);
            j++;
            count += mid-i+1;}}
    
    while (i<=mid){
        temp.push_back(arr[i]);
        i++;}

    while(j<= end){
        temp.push_back(arr[j]);
        j++;}
        
    for (int idx = 0; i < temp.size(); i++){
        arr[idx+st] = temp[idx];}
    
        return count;}


int inverioncountbymergesort(vector<int> &arr , int st , int end){
    //O(nlogn)
    if(st<end){
    int mid = st+(end-st)/2;
    int leftic = inverioncountbymergesort(arr,st,mid);
    int rightic = inverioncountbymergesort(arr,mid+1,end);
    int count = mergeinversioncount(arr,st,mid,end);
    return leftic+rightic+count;}

    return 0;
}



int main(){
    vector<int> arr = {1,3,5,10,2,6,8,9};
    int ans = inverioncountbymergesort(arr,0,arr.size()-1);
    cout<<"the answer is "<<ans<<endl;


}