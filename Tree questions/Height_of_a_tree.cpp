#include<iostream>
using namespace std;

int height(struct Node* node){
    if(node==NULL){
        return 0;
    }
    int left=height(node->left);
    int right= height(node->right);
    int and=max(left,right)+1;
}
return ans;

int main(){
 cout<<height(node);
return 0;
}