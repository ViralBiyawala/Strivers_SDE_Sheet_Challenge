#include<bits/stdc++.h>

Node* findIntersection(Node* firstHead, Node* secondHead) {
    std::unordered_map<Node*, int> mapping;

    Node* head1 = firstHead;
    Node* head2 = secondHead;

    while (head1 != NULL) {
        mapping[head1]++;
        if (mapping[head1] > 1) {
            return head1;
        }
        head1 = head1->next;
    }

    while (head2 != NULL) {
        mapping[head2]++;
        if (mapping[head2] > 1) {
            return head2;
        }
        head2 = head2->next;
    }

    return NULL;
}
