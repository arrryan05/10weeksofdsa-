//TREE DATA STRUCTURES
/*-->Non linear data structure
  -->root->children->leaf
  -->recursive in nature
  -->degree of a node(No. of children it has)
  -->non leaf nodes are also called internal nodes

Applications
  ->used to represent heirarchical data
  ->folder structure
  ->in oops(inheritance)

VAriations of trees
  ->trie
  ->suffix tree
  ->binary index tree
  ->segment tree
*/

//binary tree->eachchildren has atmost 2 children
#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int key; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NULL;
  }
};
    
int main() {
	
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
}

//Tree traversal
//1.Inorder traversal
void inOrder(Node *root){   //TC-O(n),AS-O(h)
  if(root!= NULL){
    inOrder(root->left);
    cout<<(root->key)<<" ";
    inOrder(root->right);
  }
}



//2.Preorder traversal
void preorder(Node *root){    //tc-O(n),au-O(h)
    if(root!=NULL){
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);    
    }
}

//Postorder travresal
void postorder(Node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->key<<" ";
    }
} 

//Height of binary tree
int height(Node *root){       //tc-O(n),au-O(h)
    if(root==NULL)
        return 0;
    else
        return (1+max(height(root->left),height(root->right)));
}

//Print node at k dist
void printKdist(Node *root,int k){   //tc-O(n),tc-O(h)
  if(root==NULL) return;
  if(k==0){
    cout<<(root->key)<<" ";
  }
  else{
    printKdist(root->left,k-1);
    printKdist(root->right,k-1);
  }
}

//Breath first search(level order traversal)
void printLevel(Node *root){      //tc-O(n)
    if(root==NULL)return;
    queue<Node *>q;
    q.push(root);
    while(q.empty()==false){
        Node *curr=q.front();
        q.pop();
        cout<<curr->key<<" ";
        if(curr->left!=NULL)
            q.push(curr->left);
        if(curr->right!=NULL)
            q.push(curr->right);
    }
}  

//Size of binary tree
int getSize(Node *root){       //tc-O(n)
  if(root==NULL){
    return 0;
  }
  else{
    return 1+getSize(root->left)+getSize(root->right);
  }
}

//max value in binary tree
int getMax(Node *root){          //tc-O(n)
    if(root==NULL)
        return INT_MIN;
    else
        return max(root->key,max(getMax(root->left),getMax(root->right)));
} 




