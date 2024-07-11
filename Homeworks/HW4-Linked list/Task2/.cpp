/*
 * Complete the 'removeDuplicates' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts INTEGER_SINGLY_LINKED_LIST llist as parameter.
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

SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) 
{
    if (!llist)
    {
        return nullptr;
    }
    SinglyLinkedListNode* previous = nullptr;
    SinglyLinkedListNode* current = llist;   
  
    previous = current;
    current = current->next;
    while(current!=nullptr)
    {
        if (previous->data==current->data)
      {
            previous->next= current->next;
            current = previous->next;
        }
        else
        {
            previous = current;
           current = current->next;
        }        
    }
    return llist;
}
