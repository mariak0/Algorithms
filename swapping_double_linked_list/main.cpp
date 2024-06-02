#include <iostream>
using namespace std;

struct Node
{
   int data;
   struct Node *prev;
   struct Node *next;
};
struct Node* head = NULL;        //Create new "node" struct and a pointer named head

void put(int newdata)        //The function "put" creates a new node and stores the new number
{
   struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));  //Allocates a "node" structure size block of memory, returning a pointer to the beginning of the block.
   (*newnode).data = newdata;
   (*newnode).prev = NULL;
   (*newnode).next = head;
   if(head != NULL)
   (*head).prev = newnode ;
   head = newnode;
}

void print()           //Displays the list
{
   struct Node* ptr; //pointer ptr
   ptr = head;
   while(ptr != NULL)
   {
      cout<< (*ptr).data <<"  "; //print ptr == next
      ptr = (*ptr).next; 
   }
}

void Search(Node **head, int n) //searching for the node method
				//use int n as a helping variable
{
    
    Node *cur1 = *head; //create pointer cur1 (current) equal to pointer head
    Node *prev1 = NULL; ////create pointer prev1 (previous)

    
    while(cur1 && cur1 -> data != n) 
    {
        prev1 = cur1;  //make prev1 equal to cur1
        cur1 = cur1 -> next; //make cur1 the next node
    }

    
    Node *cur2 = cur1 -> next; //cur1 equal to cur2
    Node *prev2 = cur1; //cur1 equal to pointer prev2


    if (cur1 -> data == n) cout << endl << n << " Found :) "; /*check if number exist and print */
    if (cur1 == NULL || cur2 == NULL) /*check if node is the last*/
	cout << endl <<"No swap needed: "<< n <<" is the last"; 
    if (prev1 != NULL) prev1 -> next = cur2; /*make prev1 next node end equal to cur2*/
    if (prev2 != NULL) prev2 -> next = cur1; /*make prev1 next node end equal to cur1*/
    if (prev1 == NULL)
    {
    *head = cur2;
        prev2 -> next = cur1;
    }
    
    
	//swapping
    Node *temp; 
    temp = cur2 -> next;
    cur2 -> next = cur1 -> next;
    cur1 -> next = temp;


    cout << endl << "List after swapping: "; //print the list after swapping nodes
    print();
}

int main()
{
    int num;

    put(17);
    put(62);
    put(5);
    put(34);
    put(22);
    put(46);


    cout << "The stored numbers in the linked list are : ";
    print();

    cout << endl << "Please enter a number to be found in the linked list : ";
    cin >> num;

    Search(&head, num);

    return 0;
}
