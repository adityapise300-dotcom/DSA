#include<iostream>
#include<string>
using namespace std;

int LinearSearch(int array[],int n,int key){
    for(int i=0;i<n;i++){
        if(array[i]==key){
            return key;
        }
    }
    return -1;
}

int BinarySearch(int array[],int n, int key){
    int low = 0;
    int high = n-1;

    while(low<=high){
        int mid = (low+high)/2;

        if(key==array[mid]){
            return mid;
        }else if(key<array[mid]){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return -1;
}

int main(){
    int n;
    cout<<"\nEnter the number of elements in the array: ";
    cin>>n;
    int array[n];
    cout<<"\nEnter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    cout<<"\nYour Input array is: ";
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }

    int key;
    cout<<"\nEnter the key you want to search: ";
    cin>>key;

    int result = LinearSearch(array,n,key);

    if(result==-1){
        cout<<"Key not found";
    }else{
        cout<<"Key found at position "<<result<<endl;
    }

    return 0;
}