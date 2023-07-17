#include<iostream>
using namespace std;
class Trienode{
    public:
    char data;
    Trienode* children[26];
    bool isterminal;
    Trienode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isterminal=false;
    }
};
class trie{
Trienode* root;
void util(Trienode* root, string word){

}
void insertword(string word){
    util(root,word);
}
};
int main(){

return 0;
}