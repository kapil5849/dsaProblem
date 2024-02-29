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
class Pair{
    public:
    Node * node;
    int state;
    Pair(Node * node,int state){
        this->node=node;
        this->state=state;
    }
};
Node *construct(vector<int> &arr){
    Node* root = new Node(arr[0],NULL,NULL);
    Pair * rtp = new Pair(root,1);
    stack<Pair*> st;
    st.push(rtp); 
    int idx=0;
    while(st.size()>0){
        Pair *top = st.top();
        if(top->state==1){
            idx++;
            if(arr[idx]!=-1){
                top->node->left = new Node (arr[idx],NULL,NULL);
                Pair * lp = new Pair(top->node->left,1);
                st.push(lp);
            }
            else{
                top->node->left = NULL;
            }
            top->state++;
        }else if(top->state==2){
            idx++;
            if(arr[idx]!=-1){
                top->node->right = new Node (arr[idx],NULL,NULL);
                Pair * rp = new Pair(top->node->right,1);
                st.push(rp);
            }
            else{
                top->node->right = NULL;
            }
            top->state++;
        }else{
            st.pop();
        }
    } 
    return root;
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
int size (Node * node){
    if(node==NULL){
        return 0;
    }
    int ls = size(node->left);
    int rs = size(node->right);
    int ts = ls + rs + 1;
    return ts;
}
int sum (Node * node){
    if(node==NULL){
        return 0;
    }
    int lsm = sum(node->left);
    int rsm = sum(node->right);
    int tsm = lsm+rsm+node->data;
    return tsm;
}
int max (Node * node){
    if(node==NULL){
        return INT_MIN;
    }
    int lm = max(node->left);
    int rm = max(node->right);
    int tm = max(node->data,max(lm,rm));
    return tm;
}
int height(Node * node){
    if(node==NULL){
        return -1;
    }
    int lh=height(node->left);
    int rh=height(node->right);
    int th = max(lh,rh)+1;
    return th;
}
void traversalPre(Node * node){
    if(node==NULL){
        return;
    }
    cout<<node->data<<", ";
    traversalPre(node->left);
    traversalPre(node->right);
}
void traversalIN(Node * node){
    if(node==NULL){
        return;
    }
    traversalIN(node->left);
    cout<<node->data<<", ";
    traversalIN(node->right);
}
void traversalPost(Node * node){
    if(node==NULL){
        return;
    }
    traversalPost(node->left);
    traversalPost(node->right);
    cout<<node->data<<", ";
}
void traversal(Node * node){
    if(node==NULL){
        return;
    }
    cout<<node->data<<"in preOrder."<<endl;
    traversal(node->left);
    cout<<node->data<<"in inOrder."<<endl;
    traversal(node->right);
    cout<<node->data<<"in postOrder."<<endl;
}
void levelOrder(Node * node){
    queue<Node*> q;
    q.push(node);
    while(q.size()>0){
        int cnt = q.size();
        for(int i=0;i<cnt;i++){
            Node * node = q.front();
            q.pop();
            cout<<node->data<<" ";
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }
        }
        cout<<endl;
    }
}
void iterativePrePostInOrderTraversal(Node * node){
    stack<Pair*> st;
    Pair * rtp = new Pair(node,1);
    st.push(rtp);
    string pre="";
    string in="";
    string post="";
    while(st.size()>0){
        Pair * top = st.top();
        int value = top->node->data;
        if(top->state==1){
            pre+=to_string(value) + " ";
            top->state++;
            if(top->node->left!=NULL){
                Pair * lp = new Pair(top->node->left,1);
                st.push(lp);
            }
        }else if(top->state==2){
            in+=to_string(value) + " ";
            top->state++;
            if(top->node->right!=NULL){
                Pair * rp = new Pair(top->node->right,1);
                st.push(rp);
            }
        }else{
            post+=to_string(value) +" ";
            st.pop();
        }
    }
    cout<<"preOrder: "<<pre<<endl;
    cout<<"inOrder: "<<in<<endl;
    cout<<"postOrder: "<<post<<endl;
}
bool find(Node * node,int data){
    if(node==NULL){
        return false;
    }
    if(node->data==data){
        return true;
    }
    bool left = find(node->left,data);
    if(left){
        return true;
    }
    bool right = find(node->right,data);
    if(right){
        return true;
    }
    return false;
}
vector<int> path;
bool NodeToRootPath(Node * node,int data){
    if(node==NULL){
        return false;
    }
    if(node->data==data){
        path.push_back(node->data);
        return true;
    }
    bool left = NodeToRootPath(node->left,data);
    if(left){
        path.push_back(node->data);
        return true;
    }
    bool right = NodeToRootPath(node->right,data);
    if(right){
        path.push_back(node->data);
        return true;
    }
    return false;
}
void printKLevelDown(Node * node,int k){
    if(node==NULL or k<0){
        return;
    }
    if(k==0){
        cout<<node->data<<" ";
    }
    printKLevelDown(node->left,k-1);
    printKLevelDown(node->right,k-1);
}

vector<Node*> helperKNodeFarPath(Node *node,int data){
    vector<Node*> temp;
    if(node==NULL){
        return temp;
    }
    vector<Node*> ans;
    if(node->data==data){
        ans.push_back(node);
        return ans;
    }
    vector<Node*> left = helperKNodeFarPath(node->left,data);
    if(left.size()>0){
        left.push_back(node);
        return left;
    }
    vector<Node*> right = helperKNodeFarPath(node->right,data);
    if(right.size()>0){
        right.push_back(node);
        return right;
    }
    return temp;
}
void helperPrintKLevelsDownFar(Node* node,int k,Node * block){
    if(node==NULL or node==block){
        return;
    }
    if(k==0){
        cout<<node->data<<endl;
        return;
    }
    helperPrintKLevelsDownFar(node->left,k-1,block);
    helperPrintKLevelsDownFar(node->right,k-1,block);
}
void printKNodesFar(Node * node,int data,int k){
    if(node==NULL){
        return;
    }
    Node * block=NULL;
    vector<Node*> ans = helperKNodeFarPath(node,data);
    for(int i=0;i<ans.size();i++){
        helperPrintKLevelsDownFar(ans[i],k-i,block);
        block=ans[i];
    }
}
void pathToLeafFromRoot(Node * node,string path,int sum,int low,int high){
    if(node==NULL){
        return;
    }
    if(node->left==NULL and node->right==NULL){
        sum=sum+node->data;
        if(sum>=low and sum<=high){
            cout<<path+to_string(node->data)<<endl;
        }
        return;
    }
    pathToLeafFromRoot(node->left,path+to_string(node->data)+" ",sum+node->data,low,high);
    pathToLeafFromRoot(node->right,path+to_string(node->data)+" ",sum+node->data,low,high);
}
Node * createLeftCloneTree(Node * node){
    if(node==NULL){
        return NULL;
    }
    Node * lcr = createLeftCloneTree(node->left);
    Node * rcr = createLeftCloneTree(node->right);
    Node * nn = new Node(node->data,lcr,NULL);
    node->left = nn;
    node->right=rcr;
    return node;
}
Node * transBackFromLeftClonedTree(Node * node){
    if(node==NULL){
        return NULL;
    }
    Node * lnn = transBackFromLeftClonedTree(node->left->left);
    Node * rnn = transBackFromLeftClonedTree(node->right);
    node->left = lnn;
    return node;
}
void printSingleChildNodes(Node * node,Node * parent){
    if(node==NULL){
        return;
    }
    if(parent!=NULL and parent->left==node and parent->right==NULL){
        cout<<node->data<<endl;
    }
    else if(parent!=NULL and parent->right==node and parent->left==NULL){
        cout<<node->data<<endl;
    }
    printSingleChildNodes(node->left,node);
    printSingleChildNodes(node->right,node);
}
Node * removeLeaves(Node * node){
    if(node==NULL){
        return NULL;
    }
    if(node->left==NULL and node->right==NULL){
        return NULL;
    }
    node->left = removeLeaves(node->left);
    node->right = removeLeaves(node->right);
    return node;
}
int diameter(Node * node){
    if(node==NULL){
        return 0;
    }
    int lh = height(node->left);
    int rh = height(node->right);
    int ld = diameter(node->left);
    int rd = diameter(node->right);
    int td = max(lh+rh+2,max(ld,rd));
    return td;
}
int til = 0;
int tilt(Node * node){
    if(node==NULL){
        return 0;
    }
    int ls = tilt(node->left);
    int rs = tilt(node->right);
    int lTilt = abs(ls-rs);
    til+=lTilt;
    int ts = ls+rs+node->data;
    return ts;
}
class BSTPair{
    public:
    bool isBST=false;
    int min=0;
    int max=0;
};
BSTPair BST(Node * node){
    if(node==NULL){
        BSTPair b;
        b.isBST=true;
        b.max = INT_MIN;
        b.min = INT_MAX;
        return b;
    }
    BSTPair lp = BST(node->left);
    BSTPair rp = BST(node->right);
    BSTPair mp;
    mp.min  = min(node->data,min(lp.min,rp.min));
    mp.max = max(node->data,max(lp.max,rp.max));
    if(lp.isBST==true and rp.isBST==true and (lp.max<node->data and rp.min>node->data)){
        mp.isBST=true;
    }
    return mp;
}
bool isBal = true;
int isBalanced(Node * node){
    if(node==NULL){
        return 0;
    }
    int lh = isBalanced(node->left);
    int rh = isBalanced(node->right);
    int gap = abs(lh-rh);
    if(gap>1){
        isBal = false;
    }
    int th = max(lh,rh)+1;
    return th;
}
// solve using pair...
// class BalPair{
//     int ht=0;
//     bool is_Bal=false;
// }
// BalPair isBalancedSecond(Node * node){
//     if(node==NULL){
//         BalPair b;
//         b.ht =0;
//         b.is_Bal=true;
//         return;
//     }
//     BalPair lp = isBalancedSecond(node->left);
//     BalPair rp = isBalancedSecond(node->right);
//     BalPair ans;
//     ans.is_Bal = abs(lp.ht - rp.ht)<=1 and lp.is_Bal==true and rp.is_Bal==true;
//     ans.ht=max(lp.ht,rp.ht)+1;
//     return ans;
// }

// largest BST Subtree... 
class BSTPairS{
    public:
    bool isBST=false;
    int min=0;
    int max=0;
    Node * lBstRoot=NULL;
    int lBstSize=0;
};
BSTPairS BSTs(Node * node){
    if(node==NULL){
        BSTPairS b;
        b.isBST=true;
        b.max = INT_MIN;
        b.min = INT_MAX;
        return b;
    }
    BSTPairS lp = BSTs(node->left);
    BSTPairS rp = BSTs(node->right);
    BSTPairS mp;
    mp.min  = min(node->data,min(lp.min,rp.min));
    mp.max = max(node->data,max(lp.max,rp.max));
    if(lp.isBST==true and rp.isBST==true and (lp.max<node->data and rp.min>node->data)){
        mp.isBST=true;
    }
    if(mp.isBST==true){
        mp.lBstRoot=node;
        mp.lBstSize=lp.lBstSize+rp.lBstSize+1;
    }
    else if(lp.lBstSize>rp.lBstSize){
        mp.lBstRoot=lp.lBstRoot;
        mp.lBstSize=lp.lBstSize;
    }
    else{
        mp.lBstRoot=rp.lBstRoot;
        mp.lBstSize=rp.lBstSize;
    }
    return mp;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        arr.push_back(m);
    }
    Node * root = construct(arr);
    // display(root);
    // cout<<"size: "<<size(root)<<endl;
    // cout<<"sum: "<<sum(root)<<endl;
    // cout<<"max: "<<max(root)<<endl;
    // cout<<"height: "<<height(root)<<endl;
    // traversal(root);
    // cout<<"preOrder: ";
    // traversalPre(root);
    // cout<<endl;
    // cout<<"inOrder: ";
    // traversalIN(root);
    // cout<<endl;
    // cout<<"postOrder: ";
    // traversalPost(root);
    // cout<<endl;
    // levelOrder(root);
    // iterativePrePostInOrderTraversal(root);
    // bool ans = find(root,87);
    // if(ans==0){
    //     cout<<"false"<<endl;
    // }
    // else{
    //     cout<<"true"<<endl;
    // }
    // bool final = NodeToRootPath(root,87);
    // if(final==0){
    //     cout<<"false"<<endl;
    // }
    // else{
    //     cout<<"true"<<endl;
    // }
    // for(int i=0;i<path.size();i++){
    //     cout<<path[i]<<" ";
    // }
    // cout<<endl;
    // printKLevelDown(root,3);
    // printKNodesFar(root,37,2);
    // pathToLeafFromRoot(root,"",0,150,250);
    // root = createLeftCloneTree(root);
    // display(root);
    // root = transBackFromLeftClonedTree(root);
    // display(root);
    // printSingleChildNodes(root,NULL);
    // root = removeLeaves(root);
    // display(root);
    // cout<<diameter(root)<<endl;
    // int r = tilt(root);
    // cout<<til<<endl;
    // BSTPair r = BST(root);
    // if(r.isBST==1){
    //     cout<<"true"<<endl;
    // }
    // else{
    //     cout<<"false"<<endl;
    // }
    // int r = isBalanced(root);
    // if(isBal==1){
    //     cout<<"true"<<endl;
    // }
    // else{
    //     cout<<"false"<<endl;
    // }
    BSTPairS r = BSTs(root);
    cout<<r.lBstRoot->data<<"@"<<r.lBstSize;

    return 0;
}



// 19
// 50 25 12 -1 -1 37 30 -1 -1 -1 75 62 -1 70 -1 -1 87 -1 -1   


