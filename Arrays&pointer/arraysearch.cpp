#include <iostream>
#include <cmath>
using namespace std;

int search(int arr[], int n, int x)
{
	for(int i = 0; i < n; i++)  //this loop runs to find out wheather item which is being searched is present at any index 
	{
		if(arr[i] == x)
			return i;
	}

	return -1; //if not present then function return 0
} 


    
int main() {
	
	int arr[] = {20, 5, 7, 25}, x = 5;

    cout<<search(arr, 4, x);  
    
}