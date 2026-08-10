#include<iostream>
using namespace std;
int main(){
  int n;
cout<<"Enter number of elements:";
cin>>n;
int arr[n];
cout<< "Enter"<<n<<"elements:";
for(int i=0;i<n;i++){
cin >>arr[i];
}
int smallest=arr[0];
for (int i=1; i<n; i++){
if (arr[i]<smallest){
smallest=arr[i];
}
}
cout<<"Smallest element="<<smallest<<endl;
return 0;
}
