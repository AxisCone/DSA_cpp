#include<iostream>
using namespace std;

int binary_search(int arr[],int n,int key){
    int start = 0,end=n-1;
    
    while(start<=end){
     int mid = start + (end-start)/2;
     if(arr[mid]==key){
        return mid+1;  // for user indexing start form 1;
     }
     else if(arr[mid]<key){
        start = mid+1;
     }
     else{
        end = mid-1;
     }

    }

    return -1;  // means element not present

}

int main(){
    int n;
    cout<<"Enter the n.o of elements in array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter elements in array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int key;
    cout<<"Enter the key: ";
    cin>>key;

    int result=binary_search(arr,n,key);
    if(result==-1){
        cout<<"Entered key is not present";
    }
    else{
        cout<<"key"<<"("<<key<<")"<<" is present in "<<result<<"th position";
    }
}