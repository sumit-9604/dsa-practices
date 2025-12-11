#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int bsearch(int arr[],int n,int t){      //[O(log n)]
    int st=0;
    int end=n-1;

while (st<=end){
int mid=st+(end-st)/2;
if (t<arr[mid])          {end=mid-1;}
else if (t>arr[mid])     {st=mid+1;}
else                      {return mid;}}}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
int rabs(int arr[],int n,int t){
    int st=0; int end=n-1;
    while (st<=end){
        int mid=st+ (end-st)/2;
        if(arr[mid]==t){return mid;}
        if (arr[st]<arr[mid]){ //left sorted
            if (arr[st]<=t && t<=arr[mid])   {end=mid-1;}
            else                             {st=mid+1;}}

        else{

            if (arr[mid]<=t && t<=arr[end])   {st=mid+1;}
            else                              {end=mid-1;}}}}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
int peak(vector<int> &v ){
    int st=1;
    int end = v.size() -1;
    while (st<=end){
    int mid = st+ (end-st)/2;

    if(v[mid]>v[mid+1] && v[mid]>v[mid-1])     {return mid;}

    else if(v[mid]>v[mid-1])                   {st=mid+1;}

    else                                       {end=mid-1;}}}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int se(vector<int> v){
    int st=0;
    int end = v.size()-1;
    while (st<=end){
        int mid=st+(end-st)/2;
        if(mid==0 && v[0]!=v[1])                                {return mid;}      //first element
        if(mid==end && v[end]!=v[end-1])                        {return mid;}      //last element

        if(v[mid]!=v[mid-1] && v[mid]!=v[mid+1])                {return mid;}      //mid e;ement

        if (mid%2==0) {
        if (v[mid]==v[mid-1])                                   {end=mid-1;}       // even left
        else                                                    { st=mid+1;}}      // even right
      
        else{
        if (v[mid]==v[mid-1])                                   {st=mid+1;}        // odd right
        else                                                    {end=mid-1;}}}}    // odd left

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




bool isvalid(vector <int>&arr,int n,int m,int mid){
    int s=1;
    int pages=0;
    for (int i = 0; i < n; i++){

    if (arr[i]>mid)            {return false;}
    if(pages+arr[i]<=mid)      {pages+=arr[i];}
    else                       {s++;pages=arr[i];}}
    return s>m?false:true;}


int allocate(vector <int> &arr,int n,int m){     //[O(nlogn)]
    if (m>n)                    {return -1;}
    
    int sum=0;
    for (int i = 0; i<n; i++)   {sum += arr[i];}
   int st=0;
   int end=sum;
   int ans=-1;
   while (st<=end){
    int mid =st+(end-mid)/2;
    if (isvalid(arr,n,m,mid))    {end=mid-1;
                                  ans=mid;}
    else                         {st=mid+1;}}}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
bool ispossible(int arr[],int n,int m,int maxt){
    int p=1;
    int t=0;
    for (int i = 0; i < n; i++){
        if (t+arr[i]<=maxt)     {t+=arr[i];}
        else                    {p++; t=arr[i];}}
        return p<=m;}






int painter(int arr[],int n,int m){
    int sum=0;
    int maxv=INT16_MIN;
    for (int i = 0; i < n; i++){
        sum+=arr[i];
        maxv=max(arr[i],maxv);}
    int st=maxv;
    int end=sum;
    int ans=-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if (ispossible(arr,n,m,mid)){
            ans=mid;
            end=mid-1;}
        else                        
        {st=mid+1;}}
    return ans;   }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


bool ispossiblebull(vector<int> &bull ,int b,int s,int mad){
    sort(bull.begin(),bull.end());
    int cows=1;
    int laststall=bull[0];
    for(int i=1;i<s;i++){
        if (bull[i]-laststall>=mad){
        cows++;
        laststall=bull[i];}
        if (b==cows){
        return true;}}
        return false;

}

int aggbull(vector<int> &bull,int b,int s){
    int st=1;
    int ans=-1;
    int maxx=INT16_MAX;
    int minn=INT16_MIN;
    for (int i = 0; i < s; i++){
        maxx=max(bull[i],maxx);
        minn=min(bull[i],minn);}
    int end=maxx-minn;
    while (st<=end){
        int mid=st+(end-st)/2;
        if(ispossiblebull(bull,b,s,mid))    
        {ans=mid;
        st=mid+1;}
        else{end=mid-1;}}
        return ans;}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
