//LINKED LIST
//nodes are connected to each other through pointers
//easily insert,delete,search
//no predefined memory allocation

//Implementation of linkedlist
#include <bits/stdc++.h> 
using namespace std; 

struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

int main() 
{ 
	Node *head=new Node(10);
	Node *temp1=new Node(20);
	Node *temp2=new Node(30);
	head->next=temp1;
	temp1->next=temp2;
	cout<<head->data<<"-->"<<temp1->data<<"-->"<<temp2->data;
	return 0;
} 

//traversing in a linkedlist
#include <bits/stdc++.h> 
using namespace std; 

struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

void printlist(Node *head){
    Node *curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}

int main() 
{ 
	Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	head->next->next->next=new Node(40);
	printlist(head);
	return 0;
} 

//recursive implementation
//iterative solution is better than this because it requires less auxillary space
void rPrint(Node *head){
    if(head==NULL){
        return;
    }
    cout<<(head->data)<<" ";
    rPrint(head->next);
}

//Searching in a linked list
int search(Node * head, int x){  //iterative
    int pos=1;
    Node *curr=head;
    while(curr!=NULL){
        if(curr->data==x)
            return pos;
        else{
            pos++;
            curr=curr->next;
        }
    }
    return -1;
}



int search(Node * head, int x){   //recursive solution
    if(head==NULL)return -1;
    if(head->data==x)return 1;
    else{
        int res=search(head->next,x);
        if(res==-1)return -1;
        else return res+1;
    }
}

//INSERTION AT BEGINING OF LL  O(1)

Node *insertBegin(Node *head,int x){
    Node *temp=new Node(x);
    temp->next=head;
    return temp;
    
}


//insert in the end

Node *insertEnd(Node *head,int x){
    Node *temp=new Node(x);
    if(head==NULL)return temp;
    Node *curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
    return head;
    
}

//DELETE 1ST NODE
Node *delHead(Node *head){   //O(1)
    if(head==NULL)return NULL;
    else{
        Node *temp=head->next;
        delete(head);
        return temp;
    }
}
//DELETE LAST NODE
Node *delTail(Node *head){    //theta(n)
    if(head==NULL)return NULL;
    if(head->next==NULL){
        delete head;
        return NULL;
    }
    Node *curr=head;
    while(curr->next->next!=NULL)
        curr=curr->next;
    delete (curr->next);
    curr->next=NULL;
    return head;
}

//INSERT A DATA AT GIVEN POSITION
Node *insertPos(Node *head,int pos,int x){
    Node *temp=new Node(data);
    if(pos==1){
        temp->next=head;
        return head;
    }
    Node *curr=head;
    for(int i=1;i<pos-2; && curr != NULL ; i++){
        curr=curr->next;
    }
    if(curr==NULL){
        return head;
    }
    temp->next=curr->next;
    curr->next=temp;
    return head;
}

//Sorted insert in the linkedlist
Node *sortedInsert(Node *head,int x){
    Node *temp = new Node(x);
    if(head==NULL){
        return temp;
    }
    if(x<head->data){
        temp->next=head;
        return temp;
    }
    Node *curr=head;
    while(curr->next!=NULL && curr->next->data<x){
        curr=curr->next;
    }
    temp->next=curr->next;
    curr->next=temp;
    return head;

}

//Middle of linked list
void printMiddle(Node * head){    //NAIVE METHOD
    if(head==NULL)return;
    int count=0;
    Node *curr;
    for(curr=head;curr!=NULL;curr=curr->next)
        count++;
    curr=head;
    for(int i=0;i<count/2;i++)
        curr=curr->next;
    cout<<curr->data;
}

void printMiddle(Node * head){     //efficient method
    if(head==NULL)return;
    Node *slow=head,*fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<slow->data;
}

//nth node from the end
void printNthFromEnd(Node * head,int n){     //method1
    int len=0;
    for(Node *curr=head;curr!=NULL;curr=curr->next)
        len++;
    if(len<n)
        return;
    Node *curr=head;
    for(int i=1;i<len-n+1;i++)
        curr=curr->next;
    cout<<(curr->data)<<" ";
}

void printNthFromEnd(Node * head,int n){   //method2(2 pointer approach)
    int len=0;
    for(Node *curr=head;curr!=NULL;curr=curr->next)
        len++;
    if(len<n)
        return;
    Node *curr=head;
    for(int i=1;i<len-n+1;i++)
        curr=curr->next;
    cout<<(curr->data)<<" ";
}


//REVERSE A LINKEDLIST(iteratve)
Node *revList(Node *head){        //traverse twice
    vector<int> arr;
    for(Node *curr=head;curr!=NULL;curr=curr->next){
        arr.push_back(curr->data);
    }
    for(Node *curr=head;curr!=NULL;curr=curr->next){
        curr->data=arr.back();
        arr.pop_back();
    }
    return head;
}

Node *reverse(Node *head){
    Node *curr=head;
    Node *prev=NULL;
    while(curr!=NULL){
        Node *next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
//****DOUBTFULL****
Node *recRevL(Node *head){     //recursive approach
    if(head==NULL||head->next==NULL)return head;
    Node *rest_head=recRevL(head->next);
    Node *rest_tail=head->next;
    rest_tail->next=head;
    head->next=NULL;
    return rest_head;
}

//REMOVE DUPLICATES FROM SORTED LL
void Removedublicate(Node *head){
    Node *curr= head;
    while(curr != NULL && curr->next != NULL){
        if(curr->data ==curr->next->data){
           Node *temp=curr->next;
           curr->next=curr->next->next;
           delete(temp) ;
        }
        else{
            curr=curr->next;
        }
    }
}
