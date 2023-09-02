#include <iostream>
#include <string.h>
using namespace std;
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
    int flag=0;
    cin>>f;
    for(int i=0;i<n;i++){
        if(arr[i]==f){
            cout<<"Element found at "<<(i+1)<<"th position"<<endl;
            flag=1;
            break;
        }
    }
    if(flag==0){
        cout<<"Not Found"<<endl;
    }
    
    return 0;
}