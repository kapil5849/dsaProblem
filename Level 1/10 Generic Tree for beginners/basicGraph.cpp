#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    vector<Node*> children;
};

Node * newNode(int val){
    Node * node = new Node;
    node->data=val;
    return node;
}

Node * construct(vector<int> &arr,int n){
    Node * root = NULL;
    stack<Node*> st;
    for(int i=0;i<n;i++){
        if(arr[i]==-1){
            st.pop();
        }
        else{
            Node * temp = newNode(arr[i]);
            if(st.size()>0){
                st.top()->children.push_back(temp);
            }
            else{
                root=temp;
            }
            st.push(temp);
        }
    }
    return root;
}

void display(Node * node){
    string str = to_string(node->data)+"-> ";
    for(Node * child:node->children){
        str+=to_string(child->data)+", ";
    }
    str=str+".";
    cout<<str<<endl;
    for(Node * child:node->children){
        display(child);
    }
}

int size(Node * node){
    int s=0;
    for(Node * child:node->children){
        int cs = size(child);
        s+=cs;
    }
    return s+1;
}

int maximum(Node * node){
    int mx=INT_MIN;
    for(Node * child:node->children){
        int cm = maximum(child);
        mx=max(mx,cm);
    }
    mx=max(mx,node->data);
    return mx;
}

int height(Node * node){
    int ht = -1;
    for(Node * child:node->children){
        int ch = height(child);
        ht=max(ht,ch);
    }
    return ht+1;
}

void traversals(Node * node){
    cout<<"Node Pre"<<node->data<<endl;
    for(Node * child:node->children){
        cout<<"Edge Pre"<<node->data<<"--"<<child->data<<endl;
        traversals(child);
        cout<<"Edge Post"<<node->data<<"--"<<child->data<<endl;
    }
    cout<<"Node Post"<<node->data<<endl;
}

void level_order(Node* node){
    queue<Node*> q;
    q.push(node);
    while(q.size()>0){
        Node* temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
    for(Node * child:temp->children){
        q.push(child);
    }
    }
    cout<<"."<<endl;
}

Node * linear_orderFirst(Node * node){
    queue<Node*> q;
    q.push(node);
    queue<Node*> pq;
    while(q.size()>0){
        Node* temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        for(Node * child:temp->children){
            pq.push(child);
        }
        if(q.size()==0){
            swap(q,pq);
            cout<<endl;
        }
    }
    cout<<endl;
}

Node * linear_orderSecond(Node * node){
    queue<Node*> q;
    q.push(node);
    q.push(NULL);
    while(q.size()>0){
        Node * temp = q.front();
        q.pop();
        if(temp!=NULL){
            cout<<temp->data<<" ";
            for(Node * child:temp->children){
                q.push(child);
            }
        }
        else{
            if(q.size()>0){
                q.push(NULL);
                cout<<endl;
            }
        }
    }
    cout<<endl;
}

Node * linear_orderThird(Node * node){
    queue<Node*> q;
    q.push(node);
    while(q.size()>0){
        int size = q.size();
        while(size-->0){
            Node * temp = q.front();
            q.pop();
            cout<<temp->data<<" ";
            for(Node * child:temp->children){
                q.push(child);
            }
        }
        cout<<endl;
    }
}

// level order line wise (generic tree)...

void level_order_zigzag(Node * node){
    if(node==NULL or node->children.size()==0){
        return;
    }
    stack<Node*> q,pq;
    q.push(node);
    int level = 1;
    while(q.size()>0){
        Node * temp = q.top();
        q.pop();
        cout<<temp->data<<" ";
        if(level%2==1){
            for(Node * child:temp->children){
                pq.push(child);                
           }
        }
        else{
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

void mirror(Node * node){
    for(Node* child:node->children){
        mirror(child);
    }
    reverse(node->children.begin(),node->children.end());
}

void removeLeaves(Node * node){
    for(int i=node->children.size()-1;i>=0;i--){
        Node * child = node->children[i];
        if(child->children.size()==0){
            node->children.erase(node->children.begin()+i);
        }
    }
    for(Node * child:node->children){
        removeLeaves(child);
    }
}

Node * getTail(Node * node){
    while(node->children.size()>0){
        node=node->children[0];
    }
    return node;
}

Node * linear_ize(Node * node){
    for(Node * child:node->children){
        linear_ize(child);
    }
    while(node->children.size()>1){
        Node * lc = node->children.back();
        node->children.pop_back();
        Node * sl = node->children.back();
        Node * tail = getTail(sl);
        tail->children.push_back(lc);
    }
}

Node * linear_ize2(Node* node){
    if(node->children.size()==0){
        return node;
    }
    Node * lkt = linear_ize2(node->children[node->children.size()-1]);
    while(node->children.size()>1){
        Node * lc = node->children.back();
        node->children.pop_back();
        Node * sl = node->children[node->children.size()-1];
        Node * slt = linear_ize2(sl);
        slt->children.push_back(lc);
    }
    return lkt;
}

bool find(Node * node,int data){
    if(node->data==data){
        return true;
    }
    for(Node * child:node->children){
        bool fic = find(child,data);
        if(fic){
            return true;
        }
    }
    return false;
}

vector<int> NodeToRootPath(Node * node,int data){
    if(node->data==data){
        vector<int> base;
        base.push_back(node->data);
        return base;
    }
    for(Node * child:node->children){
        vector<int> ptc = NodeToRootPath(child,data);
        if(ptc.size()>0){
            ptc.push_back(node->data);
            return ptc;
        }
    }
    vector<int> temp;
    return temp;
}

int lca(Node * node,int data1,int data2){
    vector<int> path1=NodeToRootPath(node,data1);
    vector<int> path2=NodeToRootPath(node,data2);
    int i=path1.size()-1;
    int j=path2.size()-1;
    while(i>=0 and j>=0 and path1[i]==path2[j]){
        i--;
        j--;
    }
    return path1[i+1];
}

int distance(Node * node,int data1,int data2){
    vector<int> path1=NodeToRootPath(node,data1);
    vector<int> path2=NodeToRootPath(node,data2);
    int i=path1.size()-1;
    int j=path2.size()-1;
    while(i>=0 and j>=0 and path1[i]==path2[j]){
        i--;
        j--;
    }
    i++;
    j++;
    return i+j;
}

bool areSimilar(Node * nodeA,Node * nodeB){
    if(nodeA->children.size()!=nodeB->children.size()){
        return false;
    }
    for(int i=0;i<nodeA->children.size();i++){
        Node * caseA = nodeA->children[i];
        Node * caseB = nodeB->children[i];
        if(areSimilar(caseA,caseB)==false){
            return false;
        }
    }
    return true;
}

bool isMirror(Node * nodeA,Node * nodeB){
    if(nodeA->children.size()!=nodeB->children.size()){
        return false;
    }
    for(int i=0;i<nodeA->children.size();i++){
        Node * caseA = nodeA->children[i];
        Node * caseB = nodeB->children[nodeB->children.size()-1-i];
        if(areSimilar(caseA,caseB)==false){
            return false;
        }
    }
    return true;
}

bool isSymmetric(Node * node){
    return isMirror(node,node);
}

Node * Pre;
Node * succ;
int state=0;
void PredecessorAndSuccessor(Node * node,int data){
    if(state==0){
        if(node->data==data){
            state=1;
        }else{
            Pre=node;
        }
    }else if(state==1){
        succ=node;
        state=2;
    }
    for(Node * child:node->children){
        PredecessorAndSuccessor(child,data);
    }
}

int c = INT_MAX; 
int f = INT_MIN; 
void CeilAndFloor(Node * node,int data){
    if(node->data>data){
        if(node->data<c){
            c=node->data;
        }
    }
    if(node->data<data){
        if(node->data>f){
            f=node->data;
        }
    }
    for(Node * child:node->children){
        CeilAndFloor(child,data);
    }
}

int kthLarge(Node* node,int k){
    int factor = INT_MAX;
    for(int i=0;i<k;i++){
        CeilAndFloor(node,factor);
        factor=f;
        f=INT_MIN;
    }
    return factor;
}

int mSum=0;
int mSumNode=0;
int subSumTree(Node *node){
    int sum=0;
    for(Node * child:node->children){
        int currSum=subSumTree(child);
        sum+=currSum;
    }
    sum+=node->data;
    if(sum>mSum){
        mSum=sum;
        mSumNode=node->data;
    }
    return sum;
}

int dia=0;
int diameter(Node * node){
    int dch=-1;
    int sDch =-1;
    for(Node * child:node->children){
        int ch = diameter(child);
        if(dch<ch){
            sDch=dch;
            dch=ch;
        }
        else if(sDch<ch){
            sDch=ch;
        }
    }
    if(dia<dch+sDch+2){
        dia=dch+sDch+2;
    }
    dch+=1;
    return dch;
}

void iterativePreAndPostOrder(Node* node){
    stack<pair<Node*,int>> st;
    st.push({node,-1});
    string preOrder,postOrder;
    while(st.size()!=0){
        pair<Node*,int> top = st.top();
        st.pop();
        if(top.second==-1){
            preOrder+=(to_string)(top.first->data)+" ";
            top.second+=1;
            st.push(top);
        }
        else if(top.second==top.first->children.size()){
            postOrder+=(to_string)(top.first->data)+" ";
        }
        else{
            pair<Node*,int> newPair(top.first->children[top.second],-1);
            top.second+=1;
            st.push(top);
            st.push(newPair);
        }
    }
    cout<<"preOrder : "<<preOrder<<endl;
    cout<<"postOrder : "<<postOrder<<endl;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        arr.push_back(val);
    }
    Node * root = construct(arr,n);
    // display(root);
    // int m;
    // cin>>m;
    // vector<int> array;
    // for(int i=0;i<m;i++){
    //     int val;
    //     cin>>val;
    //     array.push_back(val);
    // }
    // Node * root2 =  construct(array,m);
    // display(root2);

    // cout<<size(root)<<endl;

    // cout<<maximum(root)<<endl;

    // cout<<height(root)<<endl;

    // traversals(root);

    // level_order(root);
    // linear_orderFirst(root);
    // linear_orderSecond(root);
    // linear_orderThird(root);
    // level_order_zigzag(root);

    // cout<<"nikita"<<endl;

    // display(root);

    // mirror(root);
    // display(root);

    // removeLeaves(root);
    // display(root);

    // linear_ize(root);
    // display(root);

    // linear_ize2(root);
    // display(root);

    // if(find(root,130)==true){
    //     cout<<"true"<<endl;
    // }
    // else{
    //     cout<<"false"<<endl;
    // }

    // vector<int> ans=NodeToRootPath(root,120);
    // cout<<"[";
    // for(int i=0;i<ans.size();i++){
    //     cout<<ans[i];
    //     if(i!=ans.size()-1)
    //     cout<<", ";
    // }
    // cout<<"]"<<endl;

    // vector<int> ans1=NodeToRootPath(root,70);
    // cout<<"[";
    // for(int i=0;i<ans1.size();i++){
    //     cout<<ans1[i];
    //     if(i!=ans1.size()-1)
    //     cout<<", ";
    // }
    // cout<<"]"<<endl;

    // cout<<lca(root,70,60)<<endl;

    // cout<<distance(root,70,60)<<endl;

    // bool similar = areSimilar(root,root2);
    // if(similar==true){
    //     cout<<"true"<<endl;
    // }
    // else{
    //     cout<<"false"<<endl;
    // }

    // bool similar1 = isMirror(root,root2);
    // if(similar1==true){
    //     cout<<"true"<<endl;
    // }
    // else{
    //     cout<<"false"<<endl;
    // }

    // bool similarSymmetric = isSymmetric(root);
    // if(similarSymmetric==true){
    //     cout<<"true"<<endl;
    // }
    // else{
    //     cout<<"false"<<endl;
    // }

    // PredecessorAndSuccessor(root,100);
    // if(Pre==NULL){
    //     cout<<"predecessor = Not found"<<endl;
    // }
    // else{
    //     cout<<"Predecessor = "<<Pre->data<<endl;
    // }
    // if(succ==NULL){
    //     cout<<"Successor = Not found";
    // }
    // else{
    //     cout<<"Successor = "<<succ->data;
    // }

    // CeilAndFloor(root,70);
    // cout<<"ceil = "<<c<<endl;
    // cout<<"floor = "<<f<<endl;
    
    // cout<<kthLarge(root,8)<<endl;

    // subSumTree(root);
    // cout<<mSumNode<<"@"<<mSum<<endl;

    // diameter(root);
    // cout<<"diameter of tree : "<<dia<<endl;

    // iterativePreAndPostOrder(root);

    return 0;
}


// linear_orderFour with class of pair... solve it...
