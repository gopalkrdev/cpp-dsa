#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main(){
  string str;
cout<<"Enter a sentence:";
getline(cin,str);
stringstream ss(str);
string word;
int count=0;
while(ss>>word){
count++;
}
cout<<"Number of words;"; << cout <<endl;
return 0;
}
