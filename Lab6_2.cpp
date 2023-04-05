#include <iostream>
using namespace std;
#include <chrono>
using namespace std::chrono;

//Initalizing a node structure
class Node 
{
public:
	int data;
	Node* next;

	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

//Initalizing a stack using linked list 
class Linkedlist 
{
	Node* head;

public:
	Linkedlist() 
    { 
        head = NULL; 
    }

	void Push(int data)
    {
    	Node* newNode = new Node(data);

        //Adding node to head
    	if (head == NULL) 
        {
    		head = newNode;
    		return;
    	}

    	// Adding node at end
    	Node* temp = head;
    	while (temp->next != NULL) 
        {
    		temp = temp->next;
    	}

    	// Insert at the last.
    	temp->next = newNode;
    }

    void Pop()
    {
        Node *temp1 = head, *temp2 = NULL;

	    if (head == NULL) 
        {
	    	cout << "Stack underflow" << endl;
	    	return;
	    }

	    temp1 = head;

        //Deleting the node and making the last node null
	    while (temp1->next != NULL) 
        {
	    	temp2 = temp1;
            temp1 = temp1->next;
	    }

	    temp2->next = temp1->next;

	    delete temp1;
    }

	void Display()
    {
    	Node* temp = head;

    	if (head == NULL) 
        {
    		cout << "Empty stack" << endl;
    		return;
    	}

        cout<<"Stack elements : ";
    	while (temp != NULL) 
        {
    		cout << temp->data << " ";
    		temp = temp->next;
    	}
        cout<<endl;
    }

	
};

// Driver Code
int main()
{
	Linkedlist stack;

    auto start = chrono::high_resolution_clock::now();

	// Stack operations
	stack.Push(8);
	stack.Push(10);
	stack.Push(5);
	stack.Push(11);
    stack.Push(15);
	stack.Push(23);
	stack.Push(6);
	stack.Push(18);
    stack.Push(20);
	stack.Push(17);
    stack.Display();
    stack.Pop();
    stack.Pop();
    stack.Pop();
    stack.Pop();
    stack.Pop();
	stack.Display();
    stack.Push(4);
	stack.Push(30);
	stack.Push(3);
	stack.Push(1);
	stack.Display();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\nTime taken by function : "<< duration.count() << " microseconds\n";


	return 0;
}


