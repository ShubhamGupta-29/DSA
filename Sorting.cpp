#include<bits/stdc++.h>
using namespace std;

int selection_sort(int arr[],int n){
    for(int i =0;i<n-1;i++){

        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }

    }
}

int bubble_sort(int arr[],int n){
    int counter =1;
    while(counter<n-1){
        for(int i=0;i<n-counter;i++){

            if(arr[i]>arr[i+1]){
                swap(arr[i],arr[i+1]);
            }
        }
        counter++;
    }
}

int insertion_sort(int arr[],int n){
    for(int i=1;i<n;i++){
        int curr=arr[i];
        int j=i-1;
        while(arr[j]>curr && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=curr;
    }
}

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

//    selection_sort(arr,n);
//    bubble_sort(arr,n);
insertion_sort(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;

}