/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)
{
        Node* l3=new Node();int c=0;
        Node* tmp=l3;
        Node* p1=num1;
        Node* p2=num2;
        while(p1&&p2)
        {
            int s=(p1->data)+(p2->data)+c;
            c=s/10;
            tmp->next=new Node(s%10);
            tmp=tmp->next;
            p1=p1->next;
            p2=p2->next;
        }
        while(p1)
        {
            int s=(p1->data)+c;
            c=s/10;
            tmp->next=new Node(s%10);
            tmp=tmp->next;
            p1=p1->next;
        }
        while(p2)
        {
            int s=(p2->data)+c;
            c=s/10;
            tmp->next=new Node(s%10);
            tmp=tmp->next;
            p2=p2->next;
        }
        if(c)
            tmp->next=new Node(c);
        l3=l3->next;
        return l3;
}
