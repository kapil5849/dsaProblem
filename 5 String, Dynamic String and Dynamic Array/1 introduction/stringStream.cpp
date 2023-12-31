// whole concept of the string stream in cpp... 

#include<bits/stdc++.h>
using namespace std;
int main(){
    stringstream ss;
    // two ways to make the input... 
    ss<<"abc"<<" "<<"def"<<" "<<"ghi";
    cout<<ss.str()<<endl; // str() is used to convert the string stream into the string...
    ss.str("123 456 789");
    cout<<ss.str()<<endl; // str() is used to convert the string stream into the string...

    // right shift operator in cpp... 

    string s1,s2,s3;
    ss>>s1;
    ss>>s2;
    ss>>s3;
    cout<<s1<<" "<<endl<<s2<<" "<<endl<<s3<<endl;
    cout<<ss.str()<<endl;
    ss.str(""); // clear the string stream, without using this the string stream will not clear...
    cout<<ss.str()<<endl;
    ss.clear(); // clear the string stream...
    cout<<ss.str()<<endl;
    cout<<"empty string"<<endl;
    return 0;
}
