

#include <iostream>
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class DoublyLinkedList  //creating class for list
        {
        private:

            struct Node {
            int data;    // value to be held in node
            Node* prev;  // pointer to go backwards
            Node* next;     // pointer to go forwards
            Node(int val, Node* p = nullptr, Node* n = nullptr) {
            data = val; 
            prev = p;
            next = n;
            }
        };
        Node* head; // pointer to poitn at beginging of list
        Node* tail; // pointer to point at end of list

        public:
            DoublyLinkedList() { head = nullptr; tail = nullptr; } // default constuctors pointing to null

            void insert_after(int value, int position)  //insertaion function
            {
            if (position < 0) {  // ot check to make sure teh position chosen in list actually exists
            cout << "Position must be >= 0." << endl; 
            return;
            }

            Node* newNode = new Node(value); // create a new node to hold data of the node wanting to isnert
            if (!head) {
            head = tail = newNode; // if list is empty new node gets added in
            return;
            }
            Node* temp = head; // list not empty so make temp node to point to the head
            for (int i = 0; i < position && temp; ++i) // loop to advance temp 
            temp = temp->next;
            
            if (!temp) 
            {   // checks to see if temp is valid and doesnt go past the linked list
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode; 
            return;
            }

            newNode->next = temp->next; //whatever newNode is poitning at assign it to temp
            newNode->prev = temp; //the old node is going to be pointed to where temp is
            
            if (temp->next) // check to make sure newnode isn't being placed in end
            temp->next->prev = newNode; //we want what temp next to point at the newNode(one being inserted)
                                        //as opposed to the one pointing after it
            
            else
            tail = newNode;  // if inserting at tail, want to newNode to be at tail, and temp next points at it
            temp->next = newNode;
            }

            void delete_val(int value) 
            {
            if (!head) return;
            Node* temp = head;
            while (temp && temp->data != value)
            temp = temp->next;
            if (!temp) return;
            if (temp->prev)
            temp->prev->next = temp->next;
            else
            head = temp->next;
            if (temp->next)
            temp->next->prev = temp->prev;
            else
            tail = temp->prev;
            delete temp;
            }
            
            void delete_pos(int pos) //delete node based on position
            {
            if (!head) {  //check to see if list is empty
            cout << "List is empty." << endl;
            return;
            }
            if (pos == 1) { //if the first position
            pop_front(); //call pop_front that deletes the first node the head
            return;
            }
            Node* temp = head; //temp node
            for (int i = 1; i < pos; i++){
            if (!temp) {  //check to make sure the position is valid
            cout << "Position doesn't exist." << endl;
            return;
            }
            else
            temp = temp->next;  //optherwise progress the temp  
            }
            if (!temp) {
            cout << "Position doesn't exist." << endl;
            return;
            }
            if (!temp->next) { //if temp next isnt pointing at anything, at tail, use popback to delete it
            pop_back();
            return;
            }

            Node* tempPrev = temp->prev; 
            tempPrev->next = temp->next;
            temp->next->prev = tempPrev;
            delete temp;
            }

            void push_back(int v)  // add node to tail
            {
            Node* newNode = new Node(v); // new node to add
            if (!tail)
            head = tail = newNode; // if empty klist add it in and have it be head and tail of list
            else {
            tail->next = newNode; // if not, point the tail to the new node
            newNode->prev = tail; // the new node is pointing backwards to old tail
            tail = newNode; // newnode is new tail
            }
            }

            void push_front(int v)  //add node to ehad
            {
            Node* newNode = new Node(v); //node to add
            if (!head) //if empty opint tail and head to the new node
            head = tail = newNode;
            else {
            newNode->next = head; //point newnode forards to the head
            head->prev = newNode; // old head now point backwards to enwnode
            head = newNode; // the newnode is the new head
            }
            }

            void pop_front()  //delete the first node
            {
            if (!head) { //check to see it list is empty, head not pointint to anything
            cout << "List is empty." << endl;
            return;
            }
            Node * temp = head; //create temp node that points to head
            if (head->next) {
            head = head->next; //have previous head point forwards to the next node
            head->prev = nullptr; //the new head points backwards to null nad not the temo that is pointing to head
            }
            else
            head = tail = nullptr; //if only one node, head and tail point to null and list is empty
            delete temp;
            }
            
            void pop_back() 
            {
            if (!tail) {
            cout << "List is empty." << endl;
            return;
            }
            Node * temp = tail;
            if (tail->prev) {
            tail = tail->prev;
            tail->next = nullptr;
            }
            else
            head = tail = nullptr;
            delete temp;
            }
            
            ~DoublyLinkedList() //class destructor
            {
            while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
            }
            }

            void print() 
            {
            Node* current = head; //node to traverse list
            if (!current) {
            cout << "List is empty." << endl; // check to see the list is not empty
            return;
            }
            while (current) { //while not empty, and current is pointint at something
            cout << current->data << " "; //print the data stored in node
            current = current->next; //have current point at the next node
            }
            cout << endl;
            }
            
            void print_reverse() 
            {
            Node* current = tail; //new node to traverse lsit
            if (!current) {     //check to see current is actually pointing at somehting and list is not empty
            cout << "List is empty." << endl;
            return;
            }
            while (current) { //while pointing at something, keep iterating loop
            cout << current->data << " "; //print the value at that location
            current = current->prev;    //point backwards to previous node
            }
            cout << endl;
            }

            void every_other_element()
            {
                Node * current = head; //create a node to traverse list and point it to head
                while(current) // while current points to something run the loop
                {
                    cout<<current->data<<" "; //print the data of the first element 
                    current = current->next->next; // point it to the next one ,and then the next one
                    //current = current->next;        so it should skip the next one in the list
                }
            }
};

int main() {
//cout << MIN_NR + MIN_LS + MAX_NR + MAX_LS; // dummy statement to avoid compiler warning

DoublyLinkedList list;    // create a list
int size = rand()% (MAX_LS - MIN_LS + 1) + MIN_LS;  

for(int i = 0; i < size; ++i)
    list.push_back(rand() % (MAX_NR - MIN_NR + 1) + MIN_NR); //populate list 

list.print(); //print list
cout<<endl<<endl; 

list.every_other_element(); //print every other function




return 0;
}
