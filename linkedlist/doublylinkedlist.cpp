//Doubly Linkedlist
//Each node has 2 pointer variables associated to it
//1.previous 2.next
#include <bits/stdc++.h> 
using namespace std; 

struct Node{
    int data;
    Node* prev;
    Node* next;
    Node(int d){
        data=d;
        prev=NULL;
        next=NULL;
    }
};

void printlist(Node *head){
    Node *curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }cout<<endl;
}

int main() 
{ 
	Node *head=new Node(10);
	Node *temp1=new Node(20);
	Node *temp2=new Node(30);
	head->next=temp1;
	temp1->prev=head;
	temp1->next=temp2;
	temp2->prev=temp1;
	printlist(head);
	return 0;
} 

/*ADVANTAGES
1.we can traverse in both the directions
2.can delete a given node in O(1) time
3.we can insert/del before any node given.
  DISADVANTAGE
1.extra space for previous
2.code become complex
*/

//insert at begining of DLL
Node *insertBegin(Node *head,int data){
    Node *temp=new Node(data);
    temp->next=head;
    if(head!=NULL)head->prev=temp;
    return temp;
    
}

//insert at the end
Node *insertEnd(Node *head,int data){
    Node *temp=new Node(data);
    if(head==NULL)return temp;
    Node *curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
    temp->prev=curr;
    return head;
}

//delete head of dLL
Node *delHead(Node *head){
    if(head==NULL)return NULL;
    if(head->next==NULL){
        delete head;
        return NULL;
    }    
    else{
        Node *temp=head;
        head=head->next;
        head->prev=NULL;
        delete temp;
        return head;
    }
}

//del last node
Node *delLast(Node *head){
    if(head==NULL)return NULL;
    if(head->next==NULL){
        delete head;
        return NULL;
    }    
    Node *curr=head;
    while(curr->next!=NULL)
        curr=curr->next;
    curr->prev->next=NULL;
    delete curr;
    return head;
    
}

//circular doubly LL
//insert in the begining of cdll
Node *insertAtHead(Node *head,int x){
    Node *temp=new Node(x);
    if(head==NULL){
        temp->next=temp;
        temp->prev=temp;
        return temp;
    }
    temp->prev=head->prev;
    temp->next=head;
    head->prev->next=temp;
    head->prev=temp;
    return temp;
}

//Reverse a doubly LL
//swap previous and next pointer for each node
Node *reverseDLL(Node *head){
    if(head==NULL || head->next==NULL){
        return head;
}
