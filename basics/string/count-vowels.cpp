#include<iostream>
#include<string>
using namespace std;
int main(){
  string str;
int count=0;
cout<<"Enter a string:";
getline(cin,str);
for (char ch:str){
if (ch=='a'|| ch=='e'|| ch=='i'||
  ch=='o'|| ch== 'u'||
  ch=='A'|| ch=='E' || ch=='I' ||
  ch== 'O' || ch== 'U' || {
  count++;
  }
  }
  cout<<"Number of vowels:"<<count <<endl;
return 0;
}
