#include<iostream>
using namespace std;
int sumNatural(int n){
  if(n<=0)
    return 0;
return n+ sumNatural(n-1);
}
int main(){
  int n;
couy <<" Enter a number:";
cin >> n;
cout << "Sum ="<< sumNatural(n);
return 0;
}
