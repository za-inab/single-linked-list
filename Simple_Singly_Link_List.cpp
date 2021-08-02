# include <iostream> 
# include <conio.h>



class List_Node {
public:

	int data;
	List_Node * next;

	List_Node() {
		data = 0;
		next = NULL;
	}
};

class Linked_list {

	List_Node* first;
	List_Node* last;
	List_Node* loc;
	List_Node* pre_loc;

	Linked_list() {

		first = NULL;
		last = NULL;
		loc = NULL;
		pre_loc = NULL;

	}

	bool isEmpty()
	{
		return;
	}

	void insertAtFront(int val)
	{

	}

	void insertAtEnd(int val)
	{

	}

	void PrintList()
	{



	}

	void insertSorted(int val)
	{


	}

	void search(int val)
	{

	}

	void deleteValue(int val)
	{


	}

	void deleteList()
	{

	}

};


int main()
{
	


	return 0 ;
}

/*
1)	Create an empty linked list; // do so in the constructor.
2)	bool IsEmpty(); // checks whether the list is empty or not. Returns true if empty and false otherwise.
3)	InsertAtFront(value); // takes input from a user and inserts it at the front of a list
4)	InsertAtEnd(value); // takes input from a user and inserts it at the tail end of a list
5)	Void PrintList();
6)	InsertSorted(value); //If we want to maintain a sorted list, we should implement this function
7)	Search(value); This function shall search value in a list.If found, we will need to store two addresses :
a.Address of the node in which the searched value is found  in a pointer variable named Loc_; we will store NULL in Loc_ in case value is not found.
b.Address of the node which is logical predecessor of value in a list.
i.The Search() provides functionality for other operations such as insertion in a sorted list, deleting a value, modifying a value, printing it etc.
8)	Delete(value); // searches value and then  deletes it if found.
9)	DestroyList(); // Distroys all nodes of the list leaving the list in empty state.
*/