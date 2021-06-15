#include <iostream>
#include <cmath>
using namespace std;

bool isSorted(int arr[], int n)  //naiver method with complexity thet(n^2)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(arr[j] < arr[i])
				return false;
		}
	}

	return true;
} 
bool isSorted2(int arr[], int n)       //efficient method 
{
	for(int i = 1; i < n; i++)         //for every ith element we check i-1th elemnt if it is greaterthan false or else true
	{
	    if(arr[i] < arr[i - 1])
	        return false;
	}

	return true;
} 

int main(){
	int arr[]={23,45,56,19,89};
	cout<<isSorted2(arr,5)<<endl;
	return 0;
}
