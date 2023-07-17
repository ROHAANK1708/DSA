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
node* min(node*root){
    node* temp=root;
   while(temp->left!=NULL){
    temp=temp->left;
   }
   return temp;

}
node* deletenode(node* root,int data){
    if(root==NULL){
        return root;
    }
    if(root->data==data){
        //0 child
        if(root->left==NULL&&root->right==NULL){
            delete root;
            return NULL;
        }
        //1 child left
        if(root->left!=NULL&&root->right==NULL){
            node* temp =root->left;
            delete root;
            return temp;
        }
        //1 child right
        if(root->left==NULL&&root->right!=NULL){
            node* temp =root->right;
            delete root;
            return temp;
        }
        //2 child
        if(root->left==NULL&&root->right==NULL){
            int mini= min(root->right)->data;
            root->data=mini;
            root->right=deletenode(root->right,mini);
            return root;
        }
    }
    else if (root->data>data){
        root->left=deletenode(root->left,data);
        return root;
    }
    else{
        root->right=deletenode(root->right,data);
        return root;
    }
}

node* max(node*root){
    node* temp=root;
   while(temp->right!=NULL){
    temp=temp->right;
   }
   return temp;

}



int main(){
node* root=NULL;
insert(root);
traversal(root);
cout<<"minimum is:"<<min(root)->data<<endl;
cout<<"Maximum is:"<<max(root)->data<<endl;
cout<<" after deletion: "<<deletenode(root,7)->data<<endl;
traversal(root);
cout<<"minimum is:"<<min(root)->data<<endl;
cout<<"Maximum is:"<<max(root)->data<<endl;
return 0;
}