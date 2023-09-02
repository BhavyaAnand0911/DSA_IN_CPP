#include <iostream>
#include <string.h>
using namespace std;
void swap(int arr[],int j,int i){
            int temp=0;
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j>0;j--){
            if(arr[j]<arr[j-1]){
                swap(arr,j,j-1);
            }
            else{
                break;
            }
        }
    }
    cout<<"---------"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;;
    }
    return 0;
}