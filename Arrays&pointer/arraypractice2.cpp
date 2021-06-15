#include <iostream>
#include <cmath>
using namespace std;

int search(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            return i;
    }

    return -1;
}

int main()
{
    int n;
    cout << "enter size of array = ";
    cin >> n;
    int arr1[n];
    
    
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    cout << endl;
    int x;
    cout << "x = ";
    cin >> x;
    cout << "the required index is = " << search(arr1, n, x);

    return 0;
}