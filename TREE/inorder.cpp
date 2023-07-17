//  L N R
// left waali node print then beech wali node print then right waali node print
#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
int data;
node* left;
node* right;
node(int data){
    this-> data= data;
    this->left=NULL;
    this->right=NULL;
}
};
node* binary(node* root){
    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;
    root= new node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter left of "<<data<<endl;
    root->left=binary(root->left);
    cout<<"enter right of "<<data<<endl;
    root->right=binary(root->right);
    return root;
}
void inorder(node*root){
    //base case
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
node* root=NULL;
root=binary(root);
inorder(root);
return 0;
}