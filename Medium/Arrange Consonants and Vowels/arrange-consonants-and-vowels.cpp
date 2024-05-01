//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void append(struct Node **headRef, char data) {
    struct Node *new_node = new Node(data);
    struct Node *last = *headRef;

    if (*headRef == NULL) {
        *headRef = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}


// } Driver Code Ends
/*
Structure of the node of the linked list is as
struct Node
{
    char data;
    struct Node *next;

    Node(char x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // task is to complete this function
    // function should return head to the list after making
    // necessary arrangements
    struct Node* arrangeCV(Node *head)
    {

        Node* node1=nullptr;
        Node* node2=nullptr;
        Node* head1=nullptr;
        Node* head2=nullptr;
        Node* curr=nullptr;
        Node* curr2=nullptr;

        Node* temp=head;
        while(temp){
            
            if(temp->data=='a' ||temp->data=='e' ||temp->data=='i' ||temp->data=='o' ||temp->data=='u')
            {
                
                 node1=new Node(temp->data);
                if(!head1){
                    head1=node1;
                }
                else{
                    curr->next=node1; 
                }
               
                curr=node1;
                
                
            }
            else{
                
                 node2=new Node(temp->data);
                if(!head2){
                    head2=node2;
                }
                else{
                    curr2->next=node2; 
                }
               
                curr2=node2;

            }

            temp=temp->next;
        }
        
        if (!head1) {
            return head2;
        }
        else
       
        temp=head1;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=head2;

        return head1;

    }
};


//{ Driver Code Starts.

// task is to complete this function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        char tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            append(&head, tmp);
        }
        Solution obj;
        head = obj.arrangeCV(head);
        printlist(head);
    }
    return 0;
}

// } Driver Code Ends