#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data=0;
    Node * left;
    Node * right;
    Node(int data,Node * left,Node * right){
        this->data=data;
        this->left=left;
        this->right=right;
    }
};
Node* construct(vector<int> & arr,int low,int high){
    if(low>high){
        return NULL;
    }
    int mid = (low+high)/2;
    int data = arr[mid];
    Node * lc = construct(arr,low,mid-1);
    Node * rc = construct(arr,mid+1,high);
    Node * node = new Node(data,lc,rc);
    return node;
}
void display(Node * node){
    if(node==NULL){
        return;
    }
    string str = "";
    str+=node->left== NULL? "." : to_string(node->left->data) + " ";
    str+="<-" + to_string(node->data) + "->";
    str+=node->right==NULL? "." : to_string(node->right->data) + " ";
    cout<<str<<endl;
    display(node->left);
    display(node->right);
}
int size(Node * node){
    if(node==NULL){
        return 0;
    }
    int ls = size(node->left);
    int rs = size(node->right);
    int ts = ls+rs+1;
    return ts;
}
int sum(Node * node){
    if(node==NULL){
        return 0;
    }
    int ls=sum(node->left);
    int rs=sum(node->right);
    int ts=ls+rs+node->data;
    return ts;
}
int max(Node * node){
    if(node->right!=NULL){
        return max(node->right);
    }else{
        return node->data;
    }
}
int min(Node * node){
    if(node->left!=NULL){
        return min(node->left);
    }
    else{
        return node->data;
    }
}
bool find(Node * node,int data){
    if(node==NULL){
        return false;
    }
    if(data>node->data){
        return find(node->right,data);
    }
    else if(data<node->data){
        return find(node->left,data);
    }
    else{
        return true;
    }
}
Node * add(Node * node,int data){
    if(node==NULL){
        return new Node(data,NULL,NULL);
    }
    if(data>node->data){
        node->right = add(node->right,data);
    }
    else if(data<node->data){
        node->left = add(node->left,data);
    }
    else{

    }
    return node;
}
Node * remove(Node * node,int data){
    if(data>node->data){
        node->right = remove(node->right,data);
    }
    else if(data<node->data){
        node->left = remove(node->left,data);
    }
    else{
        if(node->left!=NULL and node->right!=NULL){
            int lMax = max(node->left);
            node->data=lMax;
            node->left = remove(node->left,lMax);
            return node;
        }else if(node->left!=NULL){
            return node->left;
        }else if(node->right!=NULL){
            return node->right;
        }else{
            return NULL;
        }
    }
    return node;
}
int sumForReplace =0;
void rwSol(Node * node){
    if(node==NULL){
        return;
    }
    rwSol(node->right);
    int od = node->data;
    node->data=sumForReplace;
    sumForReplace+=od;
    rwSol(node->left);
}
int lca(Node * node,int d1,int d2){
    if(d1<node->data and d2<node->data){
        return lca(node->left,d1,d2);
    }else if(d1>node->data and d2>node->data){
        return lca(node->right,d1,d2);
    }else{
        return node->data;
    }
}
void pir(Node *node,int d1,int d2){
    if(node==NULL){
        return;
    }
    if(d1<node->data and d2<node->data){
        pir(node->left,d1,d2);
    }
    else if(d1>node->data and d2>node->data){
        pir(node->right,d1,d2);
    }
    else{
        pir(node->left,d1,d2);
        cout<<node->data<<endl;
        pir(node->right,d1,d2);
    }
}
void targetSumPair(Node * root,Node * node,int tar){
    if(node==NULL){
        return;
    }
    targetSumPair(root,node->left,tar);
    int comp = tar - node->data;
    if(node->data<comp){
        if(find(root,comp)==true){
            cout<<node->data<<" "<<comp<<endl;
        }
    }
    targetSumPair(root,node->right,tar);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
       string x;
       cin>>x;
       if(x=="n"){
           arr[i]=-1;
       }
       else{
           arr[i]=stoi(x);
       }
    }
    Node * root = construct(arr,0,n-1);
    // display(root);
    // cout<<"size :"<<size(root)<<endl;
    // cout<<"sum :"<<sum(root)<<endl;
    // cout<<"maximum :"<<max(root)<<endl;
    // cout<<"minimum :"<<min(root)<<endl;
    // cout<<"find :"<<find(root,75)<<endl;
    // add(root,61);
    // cout<<"size :"<<size(root)<<endl;
    // cout<<"sum :"<<sum(root)<<endl;
    // cout<<"maximum :"<<max(root)<<endl;
    // cout<<"minimum :"<<min(root)<<endl;
    // cout<<"find :"<<find(root,75)<<endl;
    // remove(root,61);
    // cout<<"size :"<<size(root)<<endl;
    // cout<<"sum :"<<sum(root)<<endl;
    // cout<<"maximum :"<<max(root)<<endl;
    // cout<<"minimum :"<<min(root)<<endl;
    // cout<<"find :"<<find(root,75)<<endl;
    // rwSol(root);
    // display(root);
    // cout<<lca(root,12,30)<<endl;
    // pir(root,12,65);
    // targetSumPair(root,root,100);

    
    return 0;
}
