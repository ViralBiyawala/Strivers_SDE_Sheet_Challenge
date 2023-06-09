#include <bits/stdc++.h> 
bool isPalindrome(LinkedListNode<int> *head) {
    // Check for empty list or single node
    if (!head || !head->next)
        return true;

    // Find the middle of the list using slow and fast pointers
    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the list
    LinkedListNode<int> *prev = nullptr;
    LinkedListNode<int> *curr = slow->next;
    LinkedListNode<int> *next = nullptr;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // Compare the first and second halves of the list
    LinkedListNode<int> *first = head;
    LinkedListNode<int> *second = prev;
    while (second) {
        if (first->data != second->data)
            return false;
        first = first->next;
        second = second->next;
    }

    return true;
}
