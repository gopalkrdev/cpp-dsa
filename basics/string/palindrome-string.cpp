#include<iostream>
#include<string>
using namespace std;
int main(){
  string str;
cout << "Enter a string:";
getline(cin, str);
string reversed ="";
for (int i= str.length()-1; i>=0; i--){
reversed +="";
}
if (str == reversed)
  cout<< "The string is a palindrome."<<endl;
else
  cout<< "The string is a not palindrome."<< endl;
return 0;
}
