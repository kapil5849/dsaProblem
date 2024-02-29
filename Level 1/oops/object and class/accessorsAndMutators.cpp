#include<bits/stdc++.h>
using namespace std;
class Area {
    private:
    int length;
    int width;
    public:
    int getLength() const {
        return length;
    }
    int getWidth() const{
        return width;
    }
    void setLength(int l){
        if(l>0){
            length = l;
        }else{
            length = 1;
        }
    }
    void setWidth(int w){
        if(w>0){
            width = w;
        }else{
            width = 1;
        }
    }
    int getArea() const{
        return length*width;
    }
};

int main(){
    Area a;
    a.setLength(10);
    a.setWidth(20);
    cout<<a.getLength()<<" "<<a.getWidth()<<endl;
    cout<<a.getArea()<<endl;
    return 0;
}