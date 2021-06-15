#include<iostream>
using namespace std;

int Getlargest(int arr[],int n){
    
    for(int i=0; i<n; i++){
        bool flag=true;
        for(int j=0; j<n; j++){
            if(arr[j] > arr[i]){
                flag = false;
                break;
            }
            if(flag==true){
                return i;
            }
        }

    }
    return -1;
}

int Getlargest2(int arr[], int n){
    int res = 0;//initialized a variable which will be index of largest element
    for(int i=0; i<n; i++){//loop to check wheather ohter elemrnts are greater than arr[res]
        if(arr[i]>arr[res]){
            res = i;          //if they are greater update res to i
        }
    }
    return res;
}

int secondLargest(int arr[], int n){
    int largest = Getlargest2(arr,n);
    int res = -1;
    for(int i=0; i<n; i++){
        if(arr[i] != arr[largest]){
            if(res==-1){
                res=i;
            }
            else if(arr[i]>arr[res]){
                res=i;
            }
        }
    }
    return res;

}
int secondLargest2(int arr[],int n){
    int result=-1,largest1=0;
    for(int i=1; i<n; i++){
        if(arr[i]>arr[largest1]){               //EFFICIENT APPROCH WITH 0(n)
            result=largest1;
            largest1=i;
        }
        else if(arr[i] != arr[largest1]){
            if(arr[i]>arr[result]){
                result=i;
            }
        }
    }
    return result;
}

int main(){
    int arr1[]={5,38,678,2};
    cout<<Getlargest2(arr1,4)<<endl;
    cout<<secondLargest(arr1,4)<<endl;
    cout<<secondLargest2(arr1,4)<<endl;
    return 0;
}