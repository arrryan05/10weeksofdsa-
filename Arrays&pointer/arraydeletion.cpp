#include <iostream>
#include <cmath>
using namespace std;

int deleteEle(int arr[], int n, int x)
{
	int i = 0;

	for(i = 0; i < n; i++) //this loop searches among all eleent wheather element is present or not 
	{                      //if elemrnt is present then loop breakes and futher instructons and executed
		if(arr[i] == x)
			break;
	}

	if(i == n)            //if while searching we do not find the element we end the function
		return n;

	for(int j = i; j < n - 1; j++)//if we find the element at jth index then we replace all further elemnts by -1th element
	{
		arr[j] = arr[j + 1];
	}

	return n-1;
} 

    
int main() {
	
       int arr[] = {3, 8, 12, 5, 6}, x = 12, n = 5;

       cout<<"Before Deletion"<<endl;

       for(int i=0; i < n; i++)
       {
       	cout<<arr[i]<<" ";
       }

       cout<<endl;

     
       n = deleteEle(arr, n, x);

       cout<<"After Deletion"<<endl;

       for(int i=0; i < n; i++)
       {
       		cout<<arr[i]<<" ";
       }
    
}