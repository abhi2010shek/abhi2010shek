//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Structure for the linked list node
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to print nodes in a given circular linked list
void printList(struct Node *head) {
    if (head != NULL) {
        struct Node *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    } else {
        cout << "empty" << endl;
    }
    cout << endl;
}


// } Driver Code Ends
class Solution {
  public:
    // Function to reverse a circular linked list
    Node* reverse(Node* head) {
        Node* endNode = head;
        while(endNode->next != head){
            endNode = endNode->next;
        }
        
        Node* prev = endNode, *curr = head;
        while(curr != endNode){
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        curr->next = prev;
        return curr;
    }

    // Function to delete a node from the circular linked list
    Node* deleteNode(Node* head, int key) {
         //finding endNode
        Node* endNode = head;
        while(endNode->next != head){
            endNode = endNode->next;
        }
        
        if(head->data == key){
            endNode->next = head->next;
            Node* temp = head;
            head = head->next;
            delete(temp);
            return head;
        }
        Node* prev = endNode, *curr = head;
        bool isDeleted = false;
        while(curr != endNode){
            if(!isDeleted && curr->data == key){
                Node* temp = curr->next;
                prev->next = curr->next;
                curr->next = NULL;
                curr = temp;
                isDeleted = true;
            }
            prev = curr;
            curr = curr->next;
        }
        if(!isDeleted && endNode->data == key){
            prev->next = head;
            endNode->next = NULL;
            delete(endNode);
        }
        return head;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Reading input into a vector
        while (ss >> number) {
            arr.push_back(number);
        }

        int key;
        cin >> key;
        cin.ignore();

        // Creating the circular linked list
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        tail->next = head; // Make the list circular

        Solution ob;

        // Delete the node with the given key
        head = ob.deleteNode(head, key);

        // Reverse the circular linked list
        head = ob.reverse(head);

        // Print the modified list
        printList(head);
    }
    return 0;
}

// } Driver Code Ends