#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    
    // cin>>str; // cin will take the input till the space...
    // cout<<str<<endl; 

    getline(cin,s); // getline will take the input till the new line character...
    cout<<s<<endl; 
    s.insert(3,"abc"); // insert the string at the 3rd index...
    cout<<s<<endl;
    cout<<s[2]<<endl; // accessing the string like an array...
    cout<<s.at(3)<<endl; // accessing the string like an array...
    cout<<s.length()<<endl; // length of the string...
    cout<<s.size()<<endl; // size of the string...
    cout<<s.substr(3,4)<<endl; // substring of the string...
    cout<<s<<endl; 
    cout<<s.substr(3)<<endl; // substring of the string...
    cout<<s<<endl;
    cout<<"find : "<<s.find("abc")<<endl; // find the substring in the string...
    cout<<s.erase(3,2)<<endl;
    cout<<s<<endl;
    cout<<s.erase(3)<<endl;
    cout<<s<<endl;
    string s1="garima ";
    string s2="salvi ";
    string s3="vaishnav";
    string st = s1+s2;
    cout<<st<<endl;
    cout<<s1.compare(s2)<<endl; // compare the two string...
    cout<<s1.compare(s1)<<endl; // compare the two string...
    cout<<s1.compare(s3)<<endl; // compare the two string...
    st = st.append(s3);
    cout<<st<<endl;
    cout<<st.length()<<endl;
    s1.clear();
    cout<<s1.length()<<endl;
    cout<<s1.empty()<<endl; 
    cout<<s2.empty()<<endl;
    cout<<s2.length()<<endl; 
    cout<<st<<endl;
    return 0;
}
