#include <iostream>
#include <string.h>
using namespace std;
int primeFac(int a,int b){
    int c=0;
    int f=0;
    int i,j;
    for(i =1;i<(b/2);i++){
        c=0;
        if(b%i==0){
            for( j=2;j<(i/2);j++){
                if(i%j==0){
                    c++;
                }
            }
            if(c==0){
                if(a%i!=0)
                    return 0;
                
            }
        }
    }
    return 1;
}
int main(){
    int n;
    cin>>n;
    int a,b;
    for(int i=1;i<=n;i++){
        cin>>a;
        cin>>b;
        int f=primeFac(a,b);
        if(f!=0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
