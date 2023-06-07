#include <bits/stdc++.h>
using namespace std;

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)//1 3 2 4 null
{
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *curr = head;

    while (curr != NULL)
    {
        LinkedListNode<int> *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}
