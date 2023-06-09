//Muhammad_Kashif_21i-0851 .

/*
#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

unordered_set<string> all_students;
unordered_set<string> common_students;

unordered_set<string> society1;
unordered_set<string> society2;
unordered_set<string> society3;

class student_Node {
public:
    string data;
    student_Node* next;
    student_Node(string data) {
        this->data = data;
        this->next = NULL;
    }
};


//The above portion cannot be changed

string* list_of_all_students(student_Node* head1, student_Node* head2, student_Node* head3)
{
    // Clear the all_students set in case this function is called more than once
    all_students.clear();

    if (!head1 && !head2 && !head3) {
        return nullptr;
    }

    // add all students to set
    if (head1) {
        while (head1 != NULL) {
            all_students.insert(head1->data);
            head1 = head1->next;
        }
    }

    if (head2) {
        while (head2 != NULL) {
            all_students.insert(head2->data);
            head2 = head2->next;
        }
    }

    if (head3) {
        while (head3 != NULL) {
            all_students.insert(head3->data);
            head3 = head3->next;
        }
    }

    // create result array
    string* result = new string[all_students.size()];
    int i = 0;
    for (auto it = all_students.begin(); it != all_students.end(); it++) {
        result[i] = *it;
        i++;
    }

    return result;
}

string* list_common_student_society(student_Node* head1, student_Node* head2, student_Node* head3)
{
    // Clear the common_students and society sets in case this function is called more than once
    common_students.clear();
    society1.clear();
    society2.clear();
    society3.clear();

    if (!head1 || !head2 || !head3) {
        return nullptr;
    }

    // add students to respective society sets
    while (head1 != NULL) {
        society1.insert(head1->data);
        head1 = head1->next;
    }

    while (head2 != NULL) {
        society2.insert(head2->data);
        head2 = head2->next;
    }

    while (head3 != NULL) {
        society3.insert(head3->data);
        head3 = head3->next;
    }

    // find intersection of all society sets
    for (auto it = society1.begin(); it != society1.end(); it++) {
        string student = *it;
        if (society2.find(student) != society2.end() && society3.find(student) != society3.end()) {
            common_students.insert(student);
        }
    }

    // create result array
    if (common_students.empty()) {
        return new string[1]{ "No common students" };
    }
    else {
        string* result = new string[common_students.size()];
        int i = 0;
        for (auto it = common_students.begin(); it != common_students.end(); it++) {
            result[i] = *it;
            i++;
        }
        return result;
    }
}

//Input function
void get_student_names(student_Node*& head) {
    string name;
    cout << "Enter names of students (enter 'done' to stop):\n";
    while (true) {
        cin >> name;
        if (name == "done" || name == "null") {
            break;
        }
        if (head == nullptr) {
            head = new student_Node(name);
        }
        else {
            student_Node* curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = new student_Node(name);
        }
    }
}




//you can make fuctions for input and output, Core logic will be in above two funcation. Main should only work as a runner.
int main()
{
    //student_Node* FGC_List;
    //student_Node* FAS_List;
    //student_Node* FDS_List;
    //string* result;

    //fill all llist
    //call both funcations
    //print results;


    //Calling helper function for inputting names
    student_Node* FGC_List = nullptr;
    get_student_names(FGC_List);

    student_Node* FAS_List = nullptr;
    get_student_names(FAS_List);

    student_Node* FDS_List = nullptr;
    get_student_names(FDS_List);

    string* result1 = list_of_all_students(FGC_List, FAS_List, FDS_List);
    cout << "List of all students include: ";
    for (int i = 0; i < all_students.size(); i++) {
        cout << result1[i] << " ";
    }
    cout << endl;

    string* result2 = list_common_student_society(FGC_List, FAS_List, FDS_List);
    cout << "List of common students include: ";
    for (int i = 0; i < common_students.size(); i++) {
        cout << result2[i] << " ";
    }

    cout << endl;
    return 0;
}*/