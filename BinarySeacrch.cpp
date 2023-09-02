#include <iostream>
#include <string.h>
using namespace std;
int binarySearch(int A[], int low, int high, int x)
{
    if (low > high) {
        return -1;
    }
    int mid = (low + high) / 2;
    if (x == A[mid]) {
        return mid;
    }
    else if (x < A[mid]) {
        return binarySearch(A, low,  mid - 1, x);
    }
    else {
        return binarySearch(A, mid + 1,  high, x);
    }
}

int main(){
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    cout<<"Enter the array elements"<<endl;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the value to be found in the array"<<endl;
    int f;
    cin>>f;
    int pos=binarySearch(arr,0,n,f);
    if(pos!=-1){
    cout<<"Element found at "<<pos+1<<"th position "<<endl;
    }
    else
    cout<<"NOT FOUND"<<endl;

    return 0;
}
