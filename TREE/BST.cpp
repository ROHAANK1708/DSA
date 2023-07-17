#include<iostream>
#include<queue>
using namespace std;
class node{
public:
int data;
node* left;
node* right;
node(int data){
    this->data=data;
    this->left=NULL;
    this->right=NULL;
}
};
node* build(node* &root, int data){
    if(root==NULL){
        root= new node(data);
        return root;
    }
    if (data>root-> data){
        root->right=build(root->right,data);
    }
    if(data<root->data){
        root->left=build(root->left,data);
    }
    return root;


}
void traversal(node* root){
    queue<node*> q;
    
    q.push(root);
    q.push(NULL);
  
    while(!q.empty()){
          node* temp=q.front();
          q.pop();
        if(temp==NULL){
            
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
  
}
void insert(node* &root){
    int data;
    cout<<"enter data for root and then for nodes"<<endl;
   cin>>data;

    while(data!=-1){
        root=build(root,data);
        cin>>data;
    }

}


int main(){
node* root=NULL;
insert(root);
traversal(root);
return 0;
}