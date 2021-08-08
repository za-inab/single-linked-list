#include <iostream>
#include <conio.h>

using namespace std;

//CLass list node to make a list
class ListNode{
public:
    int data;
    ListNode  *next;

    ListNode()
    {
        next = NULL;
        data = 0;
    }



};


class MyLinkedList{
public:
    ListNode *start; // special variable which stores address of the head node.
    ListNode *last; // special variable which stores address of the last node.

    ListNode *PredLoc_; //to be used by Search(value) method to store address of logical predecessor of value in a list.
    ListNode *Loc_; //to be used by Search(value) method to store address of the node containing the searched value in a list. If it is not found it contains NULL.

    MyLinkedList()// constructor of class MyLinkedList
    {
        start = NULL;  //initiallizing start pointer with null
        Loc_= NULL;    //initiallizing Loc_ pointer which stores the adress of next node with NULL
        PredLoc_= NULL; // initiallizing PredLoc_ which stored the adress of previous node with NULL
    }

    //Insert function to insert values in the list

    //Function to insert values at the end of the list
    void InsertValue(int value)
    {
        ListNode *temp=new ListNode(); // temp node variable
        temp->data=value; // the value to be stored in list is added in data field of temp node
        Loc_=start; //pointing Loc_ towards the first address of the list
        PredLoc_=NULL; //Pred loc is null


        /*If starting node is empty, the new node becomes the first node else a loop runs till
         * Null value is reached by loc then temp node is assigned the position of Loc and last variable
         * is also given the address of the temp node. */

        if(start== NULL)
            start=temp;
        if(Loc_!=NULL)
        {
            for(int i=0;Loc_!=NULL;i++)
            {
                PredLoc_=Loc_;
                Loc_=Loc_->next;
            }
            PredLoc_->next=temp;
            Loc_=temp;
            Loc_->next=NULL;
            last=Loc_;
            last->next=NULL;

        }
        PrintList();

    }

    // This function tells us if list is empty or not
    bool IsEmpty()
    {
        return (start == NULL && last == NULL);
    }

    /*Function to insert values at the start of the list. This function stores values
     * in a temp node and insert that node at the start of the list*/
    void InsertAtFront(int value)
    {
        ListNode *new_node = new ListNode();
        new_node->data = value;

        if (start == NULL)
        {
            start = new_node;
        }
        else
        {
            new_node->next = start;
            start = new_node;
        }
        PrintList();

    }

    /*This function is used to insert the values at the end of the list. This function stores
     * the value in a temporary variable. A loop runs until it reaches the last node and then stores the
     * address of the new temp node in the last and assign the address of the temp variable to the last
     * pointer which points to the last node of the list.*/


    /*Printing function that prints list. Uses a temporary variable to access the next node and at each node
     * prints the data in each node.*/
    void PrintList()
    {
        ListNode *temp=start;

        if (temp == NULL)
            cout << "Single Linked List is empty" << endl;
        else
        {
            cout << "The Elements of list are" << endl;
            for (int i = 0;temp!=NULL; i++)
            {
                cout << i + 1 << ") " << temp->data << endl;
                temp=temp->next;

            }
        }

    }

    /*Insert sorted function that stores a new value in a list in a sorted position. This function first
     * uses search function to find out weather a value exists or not. If the value exists then it tells
     * not to duplicate the value and if value does not exist then returns the predecessor of the position
     * at which new value is to be inserted*/
    void InsertSorted(int value)
    {

        Search(value);
        if (Loc_ != NULL)
        {
            cout << "The given value exists. Can't re-enter a value "<<endl;
        }

        else
        {
            if (PredLoc_ == NULL)
            {
                InsertAtFront(value);


            }
            else {
                if (PredLoc_ == last)
                {
                    InsertValue(value);

                }
                else
                {
                    ListNode *new_node = new ListNode();
                    new_node->data = value;

                    new_node->next = PredLoc_->next;
                    PredLoc_->next = new_node;

                }
            }
        }
        PrintList();

    }

    /*Thsi function stores the location of the value to be searched. if the value is found,
     * its location is stored otherwise the it returns the null value inside a pointer
     * indicating that value was not found*/
    void Search(int value)
    {
        Loc_ = start;
        PredLoc_ = NULL;

        while ( Loc_->data < value && Loc_!=NULL)
        {
            PredLoc_ = Loc_;
            Loc_ = Loc_->next;

        }
        if (Loc_ != NULL && Loc_->data != value)
        {
            Loc_ = NULL;
        }
        if(Loc_== NULL)
            cout<<"The value "<<value<<"don't exists in list"<<endl;
        else
            cout<<"The value "<<value<<" exists "<<endl;

        PrintList();


    }

    void Delete(int value)
    {
        //if list empty then return
        if (start == NULL)
        {
            cout << "List is empty";
            return;
        }
        else
        {
            Search(value);

            ListNode *temp=new ListNode();

            if(PredLoc_==NULL && Loc_==last)
            {
                temp=start;
                delete temp;
            }
            else
            {
                if(PredLoc_==NULL)
                {
                    temp=Loc_;
                    Loc_=Loc_->next;
                    PredLoc_=NULL;
                    delete temp;
                }
                if(Loc_->next==NULL)
                {
                    temp=Loc_;
                    Loc_=PredLoc_;
                    delete temp;
                }
                else
                {
                    temp=Loc_;
                    PredLoc_->next=Loc_->next;
                    Loc_=Loc_->next;
                    delete temp;

                }

            }


        }
        PrintList();
    }
    void DestroyList()
    {
        ListNode *temp ;

        while (start->next != NULL)
        {
            temp=start;
            start=start->next;
            delete temp;
        }
        temp=start;
        start=NULL;
        delete temp;
        PrintList();


    }
    
    /*code for reverse printing. Uses recursive function and prints the value of temp at each step*/
    void ReversePrint(ListNode *temp)
    {
        if(temp!=NULL) {
            ReversePrint(temp->next);
            cout<<temp->data<<endl;
        }
        else
            return;
    }

};

int main()
{



    cout<<"Implementing different functions on singly Linked List"<<endl;
    MyLinkedList myList = *new MyLinkedList();
    myList.InsertValue(1);
    myList.InsertValue(2);
    myList.InsertValue(3);
    myList.InsertValue(5);
    myList.InsertValue(6);
    myList.InsertValue(7);
    myList.PrintList();
    cout<<endl;

    cout<<"Printing List"<<endl;
    myList.PrintList();

    cout<<"Inserting ISEmpty function to check if list is empty or not"<<endl;
    if(myList.IsEmpty()==0)
        cout<<"Linked list is not empty "<<endl;
    else
        cout<<"Linked list is empty "<<endl;

    cout<<endl;

    cout<<"Inserting 0 at start using insert at front function"<<endl;
    myList.InsertAtFront(0);
    cout<<endl;

    cout<<endl;
    cout<<"Inserting 8 at end using insert at end function"<<endl;
    myList.InsertValue(8);
    cout<<endl;

    cout<<endl;
    cout<<"Using search function to find if 5 exists or not"<<endl;
    myList.Search(5);
    cout<<endl;

    cout<<endl;
    cout<<"Inserting 4 at the middle using insert sorted function"<<endl;
    myList.InsertSorted(4);
    cout<<endl;



    cout<<endl;
    cout<<"Using delete function to delete the value of 5"<<endl;
    myList.Delete(5);
    cout<<endl;

    cout<<"Using delete list function to delete complete list "<<endl;
    myList.DestroyList();
    cout<<endl;




    return 0;
}
