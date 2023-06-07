#include <bits/stdc++.h>

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if (first == NULL) {
        return second;
    }
    if (second == NULL) {
        return first;
    }

    Node<int>* mergedHead = NULL;
    Node<int>* mergedTail = NULL;

    if (first->data <= second->data) {
        mergedHead = first;
        mergedTail = first;
        first = first->next;
    } else {
        mergedHead = second;
        mergedTail = second;
        second = second->next;
    }

    while (first != NULL && second != NULL) {
        if (first->data <= second->data) {
            mergedTail->next = first;
            mergedTail = mergedTail->next;
            first = first->next;
        } else {
            mergedTail->next = second;
            mergedTail = mergedTail->next;
            second = second->next;
        }
    }

    if (first != NULL) {
        mergedTail->next = first;
    }
    if (second != NULL) {
        mergedTail->next = second;
    }

    return mergedHead;

}
