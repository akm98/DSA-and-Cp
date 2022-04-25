#include<bits/stdc++.h>
using namespace std;

int main(){
    void mergeSort(vector<int> &arr,int l, int r);
    void sortArr(vector<int> &arr,int start, int end);

    vector<int> arr = {4,56,7,2,99,55,33,44,1,3,6,8,99,34,22};

    // sortarr
    // merge
    int l=0,r=arr.size();
    mergeSort(arr,l,r);

    for(int i:arr){
        cout<<i<<" - ";
    }

}
void sortArr(vector<int> &arr,int start, int end,int mid){
    int leftPointer = start, rightPointer=mid+1,k=start;
    vector<int> res(end+1);
   while(leftPointer<=mid and rightPointer<=end){
       if(arr[leftPointer]>arr[rightPointer]){
           res[k++] = arr[rightPointer++];
           
       }else{
           res[k++] = arr[leftPointer++];           
       }
   }
   
    if(leftPointer>mid){
        while(rightPointer<=end)
            res[k++] = arr[rightPointer++];
    }else{
       while(leftPointer<=mid)
            res[k++] = arr[leftPointer++];
    }



    for(k=start;k<=end;k++){
        arr[k] = res[k];
    }
    

}

void mergeSort(vector<int> &arr,int l, int r){
    if(l>=r) return;
    int m = (r+l)/2;

    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    sortArr(arr,l,r,m);
}

