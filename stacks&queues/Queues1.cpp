//****QUEUES***
/*->first inpit first output type(items are added from 1 end and removed from other end)
  ->Operations- # enqueue-addition from rear end
                # dequeue-removal from front 
                # getFrom-get front item
                # getRear-get rear item
                # size()
  ->Application- # whenever single user and multiple user
                 # first come first serve services
                 # Router/switches and mail queues
                 # syncronization b/w 2 devices
                 # variation--> dequeue,priority queue,doubly ended priority queue                            
*/

//Implementation using arrays 
#include <bits/stdc++.h> 
using namespace std; 

 
class Queue { 
public: 
	int front, rear, size; 
	unsigned capacity; 
	int* array; 
}; 

 
Queue* createQueue(unsigned capacity) 
{ 
	Queue* queue = new Queue(); 
	queue->capacity = capacity; 
	queue->front = queue->size = 0; 

	 
	queue->rear = capacity - 1; 
	queue->array = new int[( 
		queue->capacity * sizeof(int))]; 
	return queue; 
} 

 
int isFull(Queue* queue) 
{ 
	return (queue->size == queue->capacity); 
} 


int isEmpty(Queue* queue) 
{ 
	return (queue->size == 0); 
} 


void enqueue(Queue* queue, int item) 
{ 
	if (isFull(queue)) 
		return; 
	queue->rear = (queue->rear + 1) 
				% queue->capacity; 
	queue->array[queue->rear] = item; 
	queue->size = queue->size + 1; 
	cout << item << " enqueued to queue\n"; 
} 

 
int dequeue(Queue* queue) 
{ 
	if (isEmpty(queue)) 
		return INT_MIN; 
	int item = queue->array[queue->front]; 
	queue->front = (queue->front + 1) 
				% queue->capacity; 
	queue->size = queue->size - 1; 
	return item; 
} 


int front(Queue* queue) 
{ 
	if (isEmpty(queue)) 
		return INT_MIN; 
	return queue->array[queue->front]; 
} 

 
int rear(Queue* queue) 
{ 
	if (isEmpty(queue)) 
		return INT_MIN; 
	return queue->array[queue->rear]; 
} 

 
int main() 
{ 
	Queue* queue = createQueue(1000); 

	enqueue(queue, 10); 
	enqueue(queue, 20); 
	enqueue(queue, 30); 
	enqueue(queue, 40); 

	cout << dequeue(queue) 
		<< " dequeued from queue\n"; 

	cout << "Front item is "
		<< front(queue) << endl; 
	cout << "Rear item is "
		<< rear(queue) << endl; 

	return 0; 
} 

//Linkedlist implementation of queue
//maintain 2 pointers headnode-front and lastnode-rear
struct QNode { 
	int data; 
	QNode* next; 
	QNode(int d) 
	{ 
		data = d; 
		next = NULL; 
	} 
}; 

struct Queue { 
	QNode *front, *rear; 
	Queue() 
	{ 
		front = rear = NULL; 
	} 

	void enQueue(int x) 
	{ 

		 
		QNode* temp = new QNode(x); 

		 
		if (rear == NULL) { 
			front = rear = temp; 
			return; 
		} 

		 
		rear->next = temp; 
		rear = temp; 
	} 

    void deQueue() 
	{ 
		 
		if (front == NULL) 
			return; 

	 
		QNode* temp = front; 
		front = front->next; 

	
		if (front == NULL) 
			rear = NULL; 

		delete (temp); 
	} 
}; 

//Queue in C++ STL
#include <iostream>
#include <queue>
using namespace std;

int main() 
{ 
    queue <int> q; 
    q.push(10); 
    q.push(20); 
    q.push(30); 
  

    cout << q.front() << " " << q.back() << endl; 
 
    q.pop(); 
    
    cout << q.front() << " " << q.back() << endl; 

    //queue traversal
    while(q.empty() == false)
   {
       cout << q.front() << " " << q.back() << endl;
       q.pop();
   }
    
  
    return 0; 
}





