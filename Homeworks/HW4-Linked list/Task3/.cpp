/*
 * Complete the 'insertNodeAtPosition' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER data
 *  3. INTEGER position
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* getTail(SinglyLinkedListNode*& llist)
{
    SinglyLinkedListNode* current = llist;
    SinglyLinkedListNode* previous = nullptr;
    
    while(current)
    {
        previous = current;
        current = current->next;        
    }
    return previous;
}

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position)
{
     SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data); 
     if(position == 0)
     {      
        SinglyLinkedListNode* temp = llist;       
         llist = newNode;
         newNode->next = temp;
       return llist;            
     }  
     else if (llist == nullptr)
     {
      return nullptr;
    }
    SinglyLinkedListNode* current = llist;
    SinglyLinkedListNode* previous = nullptr;

    for (int i = 0; i < position; i++)
    {
      if (current != nullptr)
      {
        previous = current;
        current = current->next;
      }         
  }
    previous->next = newNode;
    newNode->next = current;
    return llist;   
}
