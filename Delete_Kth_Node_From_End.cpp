/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* removeKthNode(Node* head, int K)
{
    Node* track = new Node();
    track->next = head;
    Node* f = track;
    Node* s = track;
    while(K--)
       f=f->next;    
    while(f->next!=NULL)
    {
        f=f->next;
        s=s->next;
    }
    s->next = s->next->next;
    return track->next;
}
