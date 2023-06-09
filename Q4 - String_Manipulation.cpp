//Muhammad_Kashif_21i-0851 .


/*
#include <iostream>
#include <fstream>
using namespace std;


class StringList {
public:
    char alphabet;
    StringList* next;
    StringList(char data) {
        this->alphabet = data;
        this->next = NULL;
    }
};

int find_Length(StringList*& s, int counter) 
{
    if (s == NULL) 
    {
       // Base case: end of the list reached, return the counter
       return counter;
    }
    else 
    {
       // Recursive case: continue to the next node and increment the counter
       return find_Length(s->next, counter + 1);
    }
}

class String_Manipulation {
public:
    void createList(StringList*& head, string fileName) {
        ifstream file(fileName);
        char c;
        while (file.get(c)) {
            StringList* node = new StringList(c);
            if (head == NULL) {
                head = node;
            }
            else {
                StringList* ptr = head;
                while (ptr->next != NULL) {
                    ptr = ptr->next;
                }
                ptr->next = node;
            }
        }
        file.close();
    }

    int Calculate_length(StringList* head) {
        if (head == NULL) {
            return 0;
        }
        else {
            return 1 + Calculate_length(head->next);
        }
    }

    bool substring(StringList* head, string str) {
        int len = str.length();
        StringList* ptr = head;
        while (ptr != NULL) {
            if (ptr->alphabet == str[0]) {
                StringList* temp = ptr;
                int i = 1;
                while (i < len && temp->next != NULL && temp->next->alphabet == str[i]) {
                    temp = temp->next;
                    i++;
                }
                if (i == len) {
                    return true;
                }
            }
            ptr = ptr->next;
        }
        return false;
    }

    int substring_position(StringList* head, string str) {
        int len = str.length();
        StringList* ptr = head;
        int index = 0;
        while (ptr != NULL) {
            if (ptr->alphabet == str[0]) {
                StringList* temp = ptr;
                int i = 1;
                while (i < len && temp->next != NULL && temp->next->alphabet == str[i]) {
                    temp = temp->next;
                    i++;
                }
                if (i == len) {
                    return index;
                }
            }
            ptr = ptr->next;
            index++;
        }
        return -1;
    }

    void replaceString(StringList*& head, string find, string replace) {
        int length1 = find.length();
        int length2 = replace.length();
        StringList* ptr = head;
        while (ptr != NULL) {
            if (ptr->alphabet == find[0]) {
                StringList* temp = ptr;
                int i = 1;
                while (i < length1 && temp->next != NULL && temp->next->alphabet == find[i]) {
                    temp = temp->next;
                    i++;
                }
                if (i == length1) {
                    StringList* node = new StringList(replace[0]);
                    StringList* temp2 = temp->next;
                    temp->next = node;
                    for (int j = 1; j < length2; j++) {
                        node->next = new StringList(replace[j]);
                        node = node->next;
                    }
                    node->next = temp2;
                    ptr = node;
                }
            }
            ptr = ptr->next;
        }
    }

    
    void appendText(StringList* head, string appends, int index) {
        StringList* curr = head;
        int counter = 0;
        while (curr != NULL) {
            if (counter == index) {
                // Traverse the append string and add each character as a new node
                for (char c : appends) {
                    StringList* newNode = new StringList(c);
                    newNode->next = curr->next;
                    curr->next = newNode;
                    curr = newNode;
                }
                return;
            }
            curr = curr->next;
            counter++;
        }
    }

    void deleteText(StringList* head, string delText) {
        StringList* curr = head;
        StringList* prev = NULL;
        bool found = false;
        while (curr != NULL) {
            // Check if current node's alphabet is equal to the first character of delText
            if (curr->alphabet == delText[0]) {
                StringList* temp = curr;
                bool match = true;
                // Traverse the delText string and compare each character with the subsequent nodes
                for (int i = 1; i < delText.length(); i++) {
                    temp = temp->next;
                    if (temp == NULL || temp->alphabet != delText[i]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    found = true;
                    // Remove the matching nodes from the linked list
                    if (prev == NULL) {
                        head = temp->next;
                    }
                    else {
                        prev->next = temp->next;
                    }
                    curr = temp->next;
                    continue;
                }
            }
            prev = curr;
            curr = curr->next;
        }
        if (!found) {
            cout << "Text not found for deletion" << endl;
        }
    }
};


int main() {
    StringList* head = NULL;
    String_Manipulation obj;
    obj.createList(head,"Q4- String Paragraph.txt");

   // int length1 = find_Length(head, 0); // length = 3
    //cout << length1 << endl;

    // Find its length
    int length = obj.Calculate_length(head);
    cout << "The Length of the String is: " << length << endl;


    string sub;
    cout << "Enter the substring to find: ";
    cin >> sub;

    int subLength = sub.length();
    cout << "The lenghth of the substring is: " << subLength << endl;

    // Check if substring exists
    bool status = obj.substring(head, sub);
    if (status) {
        cout << "The substring exists in the provided .txt file" << endl;
    }
    else {
        cout << "The substring does not exist in the provided .txt file" << endl;
    }

    int position = obj.substring_position(head, sub);
    if (position == -1) {
        cout << "The substring was not found!" << endl;
    }
    else {
        cout << "The substring was found at " << position << " position" << endl;
    }

    // Replace text
    string find, replace;
    cout << "Enter text you want to replace: ";
    cin >> find;
    cout << "Enter the replacement text: ";
    cin >> replace;
    obj.replaceString(head, find, replace);

    // Append text
    string appendText;
    int index;
    cout << "Enter text you want to append: ";
    cin >> appendText;
    cout << "Enter index at which to append: ";
    cin >> index;
    obj.appendText(head, appendText, index);

    // Delete text
    string delText;
    cout << "Enter the text to delete: ";
    cin >> delText;
    obj.deleteText(head, delText);


    StringList* newcurr = head;
    cout << "Here's the updated file " << endl << endl;
    while (newcurr != NULL) {
        cout << newcurr->alphabet;
        newcurr = newcurr->next;
    }
    return 0;
}

*/