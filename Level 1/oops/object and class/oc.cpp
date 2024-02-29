#include<bits/stdc++.h>
using namespace std;
class Person{
    public:
    int age;
    string name;
    void saysHi(){
        cout<<"Hi "<<name<<" ["<<age<<"]"<<endl;
    }
};

int main(){
    cout<<"Object and class : "<<endl;
    Person p1;
    p1.age=10;
    p1.name="abc";
    p1.saysHi();
    Person p2;
    p2.age=20;
    p2.name="xyz";
    p2.saysHi();
    Person & p3 = p1; // p3 is a reference to p1 
    p3.age = 30;
    p3.saysHi();
    p1.saysHi();
    return 0;
}
