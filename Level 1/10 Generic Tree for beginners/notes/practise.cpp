#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    vector<Node*> children;
};
Node * newNode(int value){
    Node * node = new Node();
    node->data = value;
    return node;
}
Node * construct(vector<int> &arr,int n){
    stack<Node*> st; //  stack of Node pointers called st is created
    Node * root = NULL;
    for(int i=0;i<n;i++){
        if(arr[i]==-1){
            st.pop();
        }
        else{
            Node * node = newNode(arr[i]);
            if(st.size()>0){
                st.top()->children.push_back(node);
            }else{
                root = node;
            }
            st.push(node);
        }
    }
    return root;
}
void display(Node*root){
    string str = to_string(root->data)+"-> ";
    for(Node * child:root->children){
        str+=to_string(child->data)+", ";
    }
    str+=".";
    cout<<str<<endl;
    for(Node * child:root->children){
        display(child);
    }
}
int size(Node * root){
    int s = 0;
    for(Node * child:root->children){
        int cs = size(child);
        s+=cs;
    }
    return s+1;
}
int maximum(Node * root){
    int mx = INT_MIN;
    for(Node * child:root->children){
        int cm = maximum(child);
        mx = max(mx,cm);
    }
    mx = max(mx,root->data);
    return mx;
}
int height(Node * root){
    int ht = -1;
    for(Node * child:root->children){
        int ch = height(child);
        ht = max(ht,ch);
    }
    return ht+1;
}
void traversals(Node * root){
    cout<<"Node pre "<<root->data<<endl;
    for(Node * child:root->children){
        cout<<"Edge pre "<<root->data<<"--"<<child->data<<endl;
        traversals(child);
        cout<<"Edge post "<<root->data<<"--"<<child->data<<endl;
    }
    cout<<"Node post "<<root->data<<endl;
}
void level_order(Node * root){
    queue<Node*> q;
    q.push(root);
    while(q.size()>0){ // while the size of the queue is greater than 0
        Node * node = q.front(); // get the front node of the queue
        q.pop(); // pop the front node of the queue
        cout<<node->data<<" "; // print the data of the node
        for(Node * child:node->children){ // for each child of node, push it into the queue
            q.push(child); // push the child into the queue
        }
    }
    cout<<"."; 
}
void level_orderFirst(Node * root){
    queue<Node*> q;
    q.push(root);
    queue<Node*> pq;
    while(q.size()>0){
        Node * node = q.front();
        q.pop();
        cout<<node->data<<" ";
        for(Node * child:node->children){
            pq.push(child);
        }
        if(q.size()==0){
            swap(q,pq);
            cout<<endl;
        }
    }
    cout<<endl;
}
Node * level_orderSecond(Node * root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>0){
        Node * node = q.front();
        q.pop();
        if(node!=NULL){
            cout<<node->data<<" ";
            for(Node * child:node->children){
                q.push(child);
            }
        }else{
            if(q.size()>0){
                q.push(NULL);
                cout<<endl;
            }
        }
    }
    cout<<endl;
}
Node * level_orderThird(Node * root){
    queue<Node *> q;
    q.push(root);
    while(q.size()>0){
        int size = q.size();
        while(size-->0){
            Node * node = q.front();
            q.pop();
            cout<<node->data<<" ";
            for(Node * child:node->children){
                q.push(child);
            }
        }
        cout<<endl;
    }
}
void level_order_zigzag(Node * root){
    if(root==NULL or root->children.size()==0){
        return;
    }
    stack<Node*> q,pq;
    q.push(root);
    int level = 1;
    while(q.size()>0){
        Node * temp = q.top();
        q.pop();
        cout<<temp->data<<" ";
        if(level%2==1){
            for(Node * child:temp->children){
                pq.push(child);
            }
        }else{
            for(int i=temp->children.size()-1;i>=0;i--){
                pq.push(temp->children[i]);
            }
        }
        if(q.size()==0){
            swap(q,pq);
            cout<<endl;
            level++;
        }
    }
}
void mirror(Node * root){
    for(Node * child:root->children){
        mirror(child);
    }
    reverse(root->children.begin(),root->children.end());
}
void removeLeaves(Node * root){
    for(int i=root->children.size()-1;i>=0;i--){
        Node * child = root->children[i];
        if(child->children.size()==0){
            root->children.erase(root->children.begin()+i);
        }
    }
    for(Node * child:root->children){
        removeLeaves(child);
    }
}
Node * getTail(Node * root){
    while(root->children.size()==1){
        root=root->children[0];
    }
    return root;
}
Node * linear_ize(Node * root){
    for(Node * child:root->children){
        linear_ize(child);
    }
    while(root->children.size()>1){
        Node * lc = root->children.back();
        root->children.pop_back();
        Node * sl = root->children.back();
        Node * slt = getTail(sl);
        slt->children.push_back(lc);
    }
}
Node * linear_ize2(Node * root){
    if(root->children.size()==0){ // if the root has no children, return the root
        return root;
    }
    Node * lkt = linear_ize2(root->children[root->children.size()-1]); // get the last child of the root
    while(root->children.size()>1){
        Node * lc = root->children.back(); // get the last child of the root
        root->children.pop_back(); // pop the last child of the root
        Node * sl = root->children.back(); // get the second last child of the root
        Node * slt = linear_ize2(sl); // get the tail of the second last child of the root
        slt->children.push_back(lc); // push the last child of the root into the tail of the second last child of the root
    }
    return lkt; // return the last child of the root
}
bool find(Node * root, int data){
    if(root->data==data){
        return true;
    }
    for(Node * child:root->children){
        bool fic = find(child,data);
        if(fic){
            return true;
        }
    }
    return false;
}
vector<int> NodeToRootPath(Node * root, int data){
    if(root->data==data){
        vector<int> base;
        base.push_back(root->data);
        return base;
    }
    for(Node * child:root->children){
        vector<int> ptc = NodeToRootPath(child,data);
        if(ptc.size()>0){
            ptc.push_back(root->data);
            return ptc;
        }
    }
    vector<int> temp;
    return temp;
}
int lca(Node * root,int data1,int data2){
    vector<int> path1 = NodeToRootPath(root,data1);
    vector<int> path2 = NodeToRootPath(root,data2);
    int i = path1.size()-1;
    int j = path2.size()-1;
    while(i>=0 and j>=0 and path1[i]==path2[j]){
        i--;
        j--;
    }
    return path1[i+1];
}
int distance(Node *root,int data1,int data2){
    vector<int> path1 = NodeToRootPath(root,data1);
    vector<int> path2 = NodeToRootPath(root,data2);
    int i = path1.size()-1;
    int j = path2.size()-1;
    while(i>=0 and j>=0 and path1[i]==path2[j]){
        i--;
        j--;
    }
    i++;
    j++;
    return i+j; // distance btw two nodes means total edges between them... 
}
bool areSimilar(Node * rootA, Node * rootB){
    if(rootA->children.size()!=rootB->children.size()){
        return false;
    }
    for(int i=0;i<rootA->children.size();i++){
        Node * childA = rootA->children[i];
        Node * childB = rootB->children[i];
        if(areSimilar(childA,childB)==false){
            return false;
        }
    }
    return true;
}
bool isMirror(Node * rootA, Node * rootB){
    if(rootA->children.size()!=rootB->children.size()){
        return false;
    }
    for(int i=0;i<rootA->children.size();i++){
        Node * childA = rootA->children[i];
        Node * childB = rootB->children[rootB->children.size()-1-i];
        if(isMirror(childA,childB)==false){
            return false;
        }
    }
    return true;
}
bool isSymmetric(Node * root){
    return isMirror(root,root);
}
Node * pre, * succ;
int state = 0;
void PredecessorAndSuccessor(Node * root, int data){
    if(state == 0){
        if(root->data==data){
            state = 1;
        }else{
            pre = root;
        }
    }else if(state == 1){
        succ = root;
        state = 2;
    }
    for(Node * child:root->children){
        PredecessorAndSuccessor(child,data);
    }
}
int c = INT_MAX;
int f = INT_MIN;
void CeilAndFloor(Node * root,int data){
    if(root->data>data){
        if(root->data<c){
            c = root->data;
        }
    }
    if(root->data<data){
        if(root->data>f){
            f = root->data;
        }
    }
    for(Node * child:root->children){
        CeilAndFloor(child,data);
    }
}
int kthLarge(Node * root,int k){
    int factor = INT_MAX;
    for(int i=0;i<k;i++){
        CeilAndFloor(root,factor);
        factor = f;
        f = INT_MIN;
    }
    return factor;
}
int maxSum = 0;
int maxSumNode = 0;
int subSumTree(Node * root){
    int sum = 0;
    for(Node * child:root->children){
        sum+=subSumTree(child);
    }
    sum+=root->data;
    if(sum>maxSum){
        maxSum = sum;
        maxSumNode = root->data;
    }
    return sum;
}
int dia = 0;
int diameter(Node * root){
    int dch = -1;
    int sDch = -1;
    for(Node * child:root->children){
        int ch = diameter(child);
        if(dch<ch){
            sDch = dch;
            dch = ch;
        }else if(sDch<ch){
            sDch=ch;
        }
    }
    if(dia<dch+sDch+2){
        dia = dch+sDch+2;
    }
    return dch+1;
}
void iterativePreAndPostOrder(Node * root){
    stack<pair<Node*,int>> st;
    st.push({root,-1});
    string pre,post;
    while(st.size()>0){
        pair<Node*,int> top = st.top();
        st.pop();
        if(top.second==-1){
            pre+=to_string(top.first->data)+" ";
            top.second++;
            st.push(top);
        }else if(top.second==top.first->children.size()){
            post+=to_string(top.first->data)+" ";
        }else{
            pair<Node*,int> newPair(top.first->children[top.second],-1);
            top.second++;
            st.push(top);
            st.push(newPair);
        }
    }
    cout<<"preOrder: "<<pre<<endl;
    cout<<"postOrder: "<<post<<endl;
}
int main(){
    int n;
    cin>>n;

    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    Node * root = construct(arr,n);
    display(root);
    cout<<size(root)<<endl;
    cout<<maximum(root)<<endl;
    cout<<height(root)<<endl;
    traversals(root);
    level_order(root);
    level_orderFirst(root);
    level_orderSecond(root);
    level_orderThird(root);
    level_order_zigzag(root);
    mirror(root);
    display(root);
    removeLeaves(root);
    display(root);
    linear_ize(root);
    display(root);
    linear_ize2(root);
    display(root);
    cout<<find(root,150);
    vector<int> ans = NodeToRootPath(root,50);
    cout<<"[";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
        if(i!=ans.size()-1)
        cout<<", ";
    }
    cout<<"]"<<endl;
    cout<<lca(root,120,80);
    cout<<distance(root,100,110);
    int m;
    cin>>m;
    vector<int> arr2;
    for(int i=0;i<m;i++){
        int val;
        cin>>val;
        arr2.push_back(val);
    }
    Node * root2 = construct(arr2,n);
    cout<<areSimilar(root,root2);
    cout<<isMirror(root,root2);
    cout<<isSymmetric(root);
    PredecessorAndSuccessor(root,-120);
    cout<<(pre!=NULL?pre->data:-1)<<endl;
    cout<<(succ!=NULL?succ->data:-1)<<endl;
    CeilAndFloor(root,70);
    cout<<c<<endl;
    cout<<f<<endl;
    cout<<kthLarge(root,8);
    subSumTree(root);
    cout<<maxSumNode<<"@"<<maxSum<<endl;
    diameter(root);
    cout<<dia;
    iterativePreAndPostOrder(root);
    return 0;
}