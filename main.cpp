

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
            if (!temp) {   // checks to see if temp is valid and doesnt go past the linked list
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode; 
            return;
            }
            newNode->next = temp->next; //
            newNode->prev = temp;
            if (temp->next)
            temp->next->prev = newNode;
            else
            tail = newNode;
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
            
            void delete_pos(int pos) 
            {
            if (!head) {
            cout << "List is empty." << endl;
            return;
            }
            if (pos == 1) {
            pop_front();
            return;
            }
            Node* temp = head;
            for (int i = 1; i < pos; i++){
            if (!temp) {
            cout << "Position doesn't exist." << endl;
            return;
            }
            else
            temp = temp->next;
            }
            if (!temp) {
            cout << "Position doesn't exist." << endl;
            return;
            }
            if (!temp->next) {
            pop_back();
            return;
            }
            Node* tempPrev = temp->prev;
            tempPrev->next = temp->next;
            temp->next->prev = tempPrev;
            delete temp;
            }

            void push_back(int v) 
            {
            Node* newNode = new Node(v);
            if (!tail)
            head = tail = newNode;
            else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            }
            }

            void push_front(int v) 
            {
            Node* newNode = new Node(v);
            if (!head)
            head = tail = newNode;
            else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            }
            }

            void pop_front() 
            {
            if (!head) {
            cout << "List is empty." << endl;
            return;
            }
            Node * temp = head;
            if (head->next) {
            head = head->next;
            head->prev = nullptr;
            }
            else
            head = tail = nullptr;
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
            
            ~DoublyLinkedList() 
            {
            while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
            }
            }

            void print() 
            {
            Node* current = head;
            if (!current) {
            cout << "List is empty." << endl;
            return;
            }
            while (current) {
            cout << current->data << " ";
            current = current->next;
            }
            cout << endl;
            }
            
            void print_reverse() 
            {
            Node* current = tail;
            if (!current) {
            cout << "List is empty." << endl;
            return;
            }
            while (current) {
            cout << current->data << " ";
            current = current->prev;
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
