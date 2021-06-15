#include<iostream>
using namespace std;

int insert(int arr[], int n, int x, int cap, int pos ){
    if(n==cap){
        return n;
    }
    int index=pos-1;
    for(int i=n-1; i>=index; i-- ){
        arr[i+1] = arr[i];
    }
    arr[index]=x;
    return n+1;

}

int main() {
    int arr1[]={5,6,7,8,9};
    int n=5, x=30, cap=6;
    int pos=3;
    cout<<"before insertion = ";
    for(int i=0; i<n; i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    cout<<"after inserton = ";
    n = insert(arr1, n, x, cap, pos);

    for(int i=0; i<n; i++){
        cout<<arr1[i]<<" ";
    }



    return 0 ;
}