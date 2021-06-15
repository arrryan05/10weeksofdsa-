//CIRCULAR LINKED LIST

/*structure of cLL is similar to LL
  ->next of last node is head node
  ->empty circular ll is also represented by NULL
*/

//simple linked list implementation
#include <bits/stdc++.h> 
using namespace std; 

struct Node{
    int data;
    Node* next;
    Node(int d){
        data=d;
        next=NULL;
    }
};

int main() 
{ 
	Node *head=new Node(10);
	head->next=new Node(5);
	head->next->next=new Node(20);
	head->next->next->next=new Node(15);
	head->next->next->next->next=head;
	return 0;
} 

/*Advantages of cLL
    ->we can traverse whole ll from any node
    ->implementation of algo like raind robin becomes easy
    ->we can insert at the beginning and end by just maintaining
      one tail pointer.
*/

//Traversel of cLL
void printlist(Node *head){       //M1
    if(head==NULL)return;
    cout<<head->data<<" ";
    for(Node *p=head->next;p!=head;p=p->next)
        cout<<p->data<<" ";
}
void printlist(Node *head){       //M2
    if(head==NULL)return;
    Node *p=head;
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);    
}

//Insert at the begining
//navie method O(n)
Node *insertBegin(Node * head,int x){
    Node *temp=new Node(x);
    if(head==NULL)
        temp->next=temp;
    else{
        Node *curr=head;
        while(curr->next!=head)
            curr=curr->next;
        curr->next=temp;
        temp->next=head;
    }
    return temp;
}
//efficent method
Node *insertBegin(Node * head,int x){
    Node *temp=new Node(x);
    if(head==NULL){
        temp->next=temp;
        return temp;    
    }
    else{
        temp->next=head->next;
        head->next=temp;
        int t=head->data;
        head->data=temp->data;
        temp->data=t;
        return head;
    }
}

//Insert at the end
//method 1
Node *insertEnd(Node *head,int x){   //O(n)
    Node *temp=new Node(x);
    if(head==NULL){
        temp->next=temp;
        return temp;    
    }
    else{
        Node *curr=head;
        while(curr->next!=head)
            curr=curr->next;
        curr->next=temp;
        temp->next=head;
        return head;
    }
}
//method 2(swaping used)
Node *insertEnd(Node *head,int x){
    Node *temp=new Node(x);
    if(head==NULL){
        temp->next=temp;
        return temp;    
    }
    else{
        temp->next=head->next;
        head->next=temp;
        int t=head->data;
        head->data=temp->data;
        temp->data=t;
        return temp;
    }
}

//Delete head of circular LL
Node *delHead(Node *head){    //method 1
    if(head==NULL)return NULL;
    if(head->next==head){
        delete head;
        return NULL;
    }
    Node *curr=head;
    while(curr->next!=head)
        curr=curr->next;
    curr->next=head->next;
    delete head;
    return (curr->next);
}

//Delete kth node from begining
Node *deleteKth(Node *head,int k){
    if(head==NULL)return head;
    if(k==1)return delHead(head);
        Node *curr=head;
    for(int i=0;i<k-2;i++)
        curr=curr->next;
    Node *temp=curr->next;
    curr->next=curr->next->next;
    delete temp;
    return head;
}
