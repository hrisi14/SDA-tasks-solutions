#include <iostream>
#include<cstring>
using namespace std;

class Node 
{
    public:
        int data;
        Node *next;
        Node* prev;
       Node(int node_data, Node* newNext, Node* newPrev) 
       {
            this->data = node_data;
            this->next = newNext;
            this->prev = newPrev;
        }
};
class DoublyLinkedList 
{
    public:
        Node *head;
        Node *tail;
        Node* mid;
    
        size_t count  = 0;
    
        DoublyLinkedList() 
        {
            this->head = nullptr;
            this->tail = nullptr;
            this->mid = nullptr;
        }
    
    void add(int x)  //works as the push_back method
     {
          if (!this->head)
          {
              this->head = new Node(x, nullptr, nullptr);
              this->tail = this->head; 
              this->mid = this->head;
              this->count++;
              return;
          }
       
            Node* newNode = new Node(x, nullptr, this->tail);
            this->tail->next = newNode;          
            this->tail = newNode;
            this->count++;       //!!!  
            if(this->count%2!=0)
            {
                this->mid = this->mid->next;
            }          
      }
    
void gun() 
{
       if(this->head == this->tail)
       {
           delete this->head;
          this->head = this->tail = nullptr;
           this->mid = nullptr;
           this->count--;
           return;
       }  
        Node* current = this->tail;
        this->tail = this->tail->prev;
        delete current;
        this->tail->next = nullptr;      
    
    this->count--;
    if (this->count%2==0)
    {
        this->mid = this->mid->prev;
    }   
}    
    void milen()
    {  
        Node* tail2 = this->tail;
        if (this->count%2==0)
        {             
           this->tail->next = this->head;
          this->head->prev = this->tail;
             this->tail = mid;
            this->head = this->mid->next;
          this->head->prev = nullptr;
          this->tail->next = nullptr;
        }
        else
        {
        this->tail->next = this->head;
        this->head->prev = this->tail;
        this->tail = mid->prev;
        this->head = this->mid;            
        this->head->prev = nullptr;
        this->tail->next = nullptr; 
        } 
        this->mid = tail2;
    }   

void print() const 
{
   Node *current = this->head;

   while (current)
{
     cout << current->data << " ";
     current = current->next;
   } 
}

void free() 
{  
   Node* iter = this->head;
    while (iter)
    {
        Node* toDelete = iter;
        iter = iter->next;
        delete toDelete;
    }
    
    this->head = this->tail = nullptr;
} 
};
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    DoublyLinkedList* list = new DoublyLinkedList();
   int N;
    cin>>N;
    string input;
    for (int i = 0; i<N; i++)
   {       
        cin>>input;
        if (input=="add")
        {
            int x;
            cin>>x;
            list->add(x);
        }
        else if(input=="gun")
        {
            list->gun();
        }
        else if (input == "milen")
        {
            list->milen();
        }
    }    
   cout<<list->count<<endl;
    list->print();
    list->free();
    
}
