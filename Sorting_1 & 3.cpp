#include<iostream>
#include<string>
using namespace std;

void insertionSort(int array[],int n){
    for(int i=0;i<n;i++){
        int j=i;
        while(j>0 && array[j-1]>array[j]){
            swap(array[j-1],array[j]);
            j--;
        }
    }
}

void selectionSort(int array[],int n){
    for(int i=0; i<=n-2;i++){
        int mini = i;
        for(int j=i; j<=n-1;j++){
            if(array[j]<array[mini]){
                mini = j;
            }
        }
        swap(array[i],array[mini]);
    }
}

void merge(int array[],int low,int mid,int high){
    int k=0;
    int i = low;
    int j = mid+1;

    int temp[100];

    while(i<=mid and j<=high){
        if(array[i]<=array[j]){
            temp[k] = array[i];
            i++;
        }else{
            temp[k] = array[j];
            j++;
        }
        k++;
    }

    while(i<=mid){
        temp[k] = array[i];
        i++;
        k++;
    }

    while(j<=high){
        temp[k] = array[j];
        j++;
        k++;
    }

    for(i=low,k=0;i<=high;i++,k++){
        array[i] = temp[k];
    }
}

void mergesort(int array[],int low, int high){
    if(low<high){
        int mid = (high+low)/2;

        mergesort(array,low,mid);
        mergesort(array,mid+1,high);

        merge(array,low,mid,high);
    }
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
    cout<<endl;
    mergesort(array,0,n-1);
    cout<<"\nYour array after Sorting is: ";
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;

    return 0;
}