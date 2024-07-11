// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) 
{
    SinglyLinkedListNode* result = nullptr;
    
    if (!head1)
    {
        return head2;
    }
    if (!head2)
    {
        return head1;
    }
    
    if (head1->data <= head2->data)
    {
        result = head1;
        result->next = mergeLists(head1->next, head2);
    }
    else
    {
        result = head2;
        result->next = mergeLists(head1, head2->next);
    }
  return result;
}
