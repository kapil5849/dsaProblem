#include<bits/stdc++.h>
using namespace std;
vector<int> data;
int _size(){
    return data.size();
}
void upHeapIfy(int i){
    while(i>0){
        int pi = (i-1)/2;
        if(data[i]<data[pi]){
            swap(data[i],data[pi]);
        }
        else break;
        i=pi;
    }
}
void downHeapIfy(int pi){
    while(true){
        int mini = pi;
        int li = 2 * pi + 1;
        if(li<data.size() and data[li]<data[mini]){
            mini=li;
        }
        int ri = 2 * pi + 2;
        if(ri<data.size() and data[ri]<data[mini]){
            mini=ri;
        }
        if(pi==mini) break;
        swap(data[pi],data[mini]);
        pi=mini;
    }
}
void add(int val){
    data.push_back(val);
    upHeapIfy(data.size()-1);
}
int _remove(){
    if(_size()==0){
        cout<<"underflow"<<endl;
        return -1;
    }
    swap(data[0],data[data.size()-1]);
    int val = data[data.size()-1];
    data.pop_back();
    downHeapIfy(0);
    return val;
}
int peek(){
    if(_size()==0){
        cout<<"underflow"<<endl;
        return -1;
    }
    return data[0];
}
int main(){
    while(1){
        string str;
        getline(cin,str);
        if(str[0]=='a'){
            string num = str.substr(4,str.length());
            int val = stoi(num);
            add(val);
        }
        else if(str[0]=='r'){
            int val = _remove();
            if(val!=-1){
                cout<<val<<endl;
            }
        }
        else if(str[0]=='p'){
            int val = peek();
            if(val!=-1){
                cout<<val<<endl;
            }
        }
        else break;
    }
}

