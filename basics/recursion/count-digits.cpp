#include<iostream>
using namespace std;
int countDigits(int n){
  if (n==0)
    return 0;
return 1 + countDigits(n/10);
}
int main(){
  int n;
cout<<"Enter a number:";
cin>>n;
if (n==0)
  cout<<"Number of digit=1";
else
  cout<<"Number of digit="<<countDigits(n);
return 0;
}
