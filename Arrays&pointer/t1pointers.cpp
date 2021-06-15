#include <iostream>
using namespace std;

int main()
{
    int x = 5;
    cout << x << endl;
    cout << (&x) << endl;    //Ampersand operator-->stores address of the variable
    cout << (*(&x)) << endl; //star operator-->prints value at a address

    int y = 10;
    int *ptr = &y;
    cout << *ptr << " ";
    //ptr is a pointer variable tht stores address of y and *ptr stores the value of addrress stored in saved address
    y = y + 30;
    cout << *ptr << " ";
    cout << ptr << " ";
    *ptr = *ptr + 40;
    cout << y << endl;

    int *p1;
    cout<<p1<<" ";
    cout<<*p1<<endl;

    int *P1;
    double *P2;
    string *P3;
                      
    cout<<(sizeof P1)<<" ";
    cout<<(sizeof P2)<<" ";
    cout<<(sizeof P3)<<" "<<endl;
    /*since all P1,P2,P3 store address,so they take same memory despite being int,double,string,etc*/
    

    int arr[] = {20,30,40,50};
    int *Ptr = arr;
    cout<<*(Ptr+2)<<endl;  //ptr+2 stores address of {40}

    

    return 0;
}