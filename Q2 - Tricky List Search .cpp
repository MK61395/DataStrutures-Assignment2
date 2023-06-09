//Muhammad_Kashif_21i-0851 .

/*
#include <iostream>

using namespace std;

class Node {
public:
    const int data; // do not change this
    Node* next;
    Node* prev;

    Node(int d) : data(d) {
        this->next = NULL;
        this->prev = NULL;
    }
};

void insertionSort(Node*& head, Node*& tail) {
    if (head == NULL || head == tail) {
        return;
    }

    Node* curr = head->next;//starting from second node as first is already sorted
    while (curr != NULL) {
        Node* tempvar = curr->prev;
        while (tempvar != NULL && tempvar->data > curr->data) {//iterating backwards.If tempvar is greater than curr, we will swap
            // swap curr and tempvar nodes
            if (tempvar->prev != NULL) {
                tempvar->prev->next = curr;
            }
            curr->prev = tempvar->prev;
            tempvar->prev = curr;
            tempvar->next = curr->next;
            if (curr->next != NULL) {
                curr->next->prev = tempvar;
            }
            curr->next = tempvar;
            if (head == tempvar) {
                head = curr;
            }
            if (tail == curr) {
                tail = tempvar;
            }
            // move tempvar pointer left
            tempvar = curr->prev;
        }
        curr = curr->next;
    }
}

int input(Node*& head, Node*& tail, int no_of_elements) {
    int num;
    for (int i = 0; i < no_of_elements; i++) {
        cout << "Enter the value of node " << i + 1 << ": ";
        cin >> num;
        Node* newNode = new Node(num);  // create a new node with the user input as its data
        if (head == NULL) {  // if the list is currently empty, set the head and tail pointers to the new node
            head = tail = newNode;
        }
        // if the list is not empty, add the new node to the end of the list
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    return no_of_elements;  // return the number of elements added
}


bool isSorted(Node*& head, Node*& tail) {
    Node* curr = head;
    while (curr != NULL && curr != tail) {
        if (curr->data > curr->next->data) {
            return false;
        }
        curr = curr->next;
    }
    return true;
}


bool binarySearch(Node*& head, Node*& tail, Node*& mid, int search_number) {
    // check if the head and tail pointers are not null and not equal to each other
    // indicates that the search has not yet covered the fulle list
    while (head != NULL && tail != NULL && head != tail) {
        if (mid->data == search_number) {  // check if the middle node contains the search_number
            return true;
        }
        else if (mid->data > search_number) {// if the mid data is greater than the number, search the left half
            tail = mid->prev;     //set tail to prev
        }
        else {
            head = mid->next;
        }
        mid = head;
        int len = 0;    //calculate length of remaining list
        while (mid != tail) {
            len++;
            mid = mid->next;
        }
        mid = head;    // set the middle node to the node in the middle of the remaining list
        for (int i = 0; i < len / 2; i++) {
            mid = mid->next;
        }
    }
    if (head != NULL && head->data == search_number) {  // if the head pointer is not null and if the data in the head node is equal to the search_number
        return true;
    }
    return false;
}



int main() {
    Node* head = NULL;
    Node* tail = NULL;

    int no_of_elements;
    cout << "Enter the number of total elements in the list: ";
    cin >> no_of_elements;

    input(head, tail, no_of_elements);

    //cout << "Before sorting:\n";
    if (isSorted(head, tail)) {
        cout << "The list is already sorted.\n";
    }
    else
    {
        cout << "The list needs to be sorted.\n";
        insertionSort(head, tail);
    }
    //else {
    //    insertionSort(head, tail);
    //    cout << "After sorting:\n";
    //}

    int search_number;
    cout << "Enter a number to search in the list: ";
    cin >> search_number;
    Node* mid = head;
    int len = 0;
    while (mid != tail) {
        len++;
        mid = mid->next;
    }
    mid = head;
    for (int i = 0; i < len / 2; i++) {
        mid = mid->next;
    }

    if (binarySearch(head, tail, mid, search_number)) {
        cout << "Number " << search_number << " was found in the list.\n";
    }
    else {
        cout << "Number " << search_number << " was not found in the list.\n";
    }

    return 0;
}

*/