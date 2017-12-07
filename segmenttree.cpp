#include<bits/stdc++.h>
using namespace std;
class node{
    public:int update;
    public:int leftindex;
    public:int rightindex;
    public:node* leftnode;
    public:node* rightnode;
};
void build(node *temp,int l,int r){
    temp->leftindex = l;
    temp->rightindex = r;
    if (l == r){
        return;
    }
    else{
        cout << "test" << endl;
        node *temp1;
        temp1 = new node;
        temp->leftnode = temp1;
        build(temp1,l,(l+r)/2);
        node *temp2;
        temp2 = new node;
        temp->rightnode = temp2;
        build(temp2,((l+r)/2)+1,r);
    }
}
void print(node *temp){
    if (temp->leftindex == temp->rightindex){
        cout << temp->leftindex << " " << temp->rightindex << " " << temp->update << endl;
        return;
    }
    else{
        cout << temp->leftindex << " " << temp->rightindex <<" " << temp->update << endl;
        print(temp->leftnode);
        print(temp->rightnode);
    }
}
void update(node *temp,int l,int r){
    cout << temp->leftindex << " " << temp->rightindex << " l and r are " << l << " " << r << endl;
    int left = temp->leftindex;
    int right = temp->rightindex;
    
    /* P : Too many cases here, can be simplified to 3 cases, I'm sure the bug is here somewhere. Some oversight in a case
            Simplifying the cases, will allow us to fix any problems much more simply.
    
        Suppose that l and r are always in range of current node.
            - To prove this, this is true in root node.
            - From here on out, whenever you go to lc or rc, always make sure to cut the update range wrt to the node you are in,
                i.e. if your range would exceed r of the node you are going to, make the right of range = r. and so on.
          
        The below cases should be sufficient
        if(left >= l && right <= r)
            temp->update++;
        if(left != right)
        {
            if(l <= temp->leftnode->rightindex)
                update(temp->leftnode, l, min(r, temp->leftnode->rightindex));
            if(r >= temp->rightnode->leftindex)
                update(temp->rightnode, max(l, temp->rightnode->leftindex), r);
        }
        
    */
    if (left > l && right < r){
        temp->update = temp->update + 1;
    }
    else if (left > r || right < l){
        return;
    }
    else if (left > l && right > r){
        update(temp->leftnode,l,r);
        update(temp->rightnode,l,r);
    }
    else if (l > left && r > right){
        update(temp->leftnode,l,r);
        update(temp->rightnode,l,r);
    }
    else if (left == right){
        if (left == l || left == r){
            temp->update = temp->update + 1;
        }
    }
    else if (l == left && right < r){
        temp->update = temp->update + 1;
    }
    else if (l == left && right > r){
        temp->update = temp->update + 1;
    }
    else if (r == left && right > l){
        update(temp->leftnode,l,r);
        update(temp->rightnode,l,r);
    }
    else if (l == right && r > left){
        update(temp->leftnode,l,r);
        update(temp->rightnode,l,r);
    }
    else if (l == left && r == right){
        temp->update = temp->update + 1;
    }
    else if (l > left && right > r){
        update(temp->leftnode,l,r);
        update(temp->rightnode,l,r);
    }
    else if (l < left && r == right){
        temp->update = temp->update + 1;
    }
    else{
        return;
    }
}
int main(){
    int t,n,m,l,r,c,i;
    cin >> t;
    while (t > 0){
        cin >> n >> m;
        node *root;
        root = new node;
        build(root,0,n);
        print(root);
        for (i=0;i<m;i++){
            scanf("%d %d %d",&c,&l,&r);
            update(root,l,r);
            print(root);
        }
        t = t- 1;
    }
}
