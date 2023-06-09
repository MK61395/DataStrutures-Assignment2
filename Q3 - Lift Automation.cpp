//Muhammad_Kashif_21i-0851

/*
#include <iostream>
using namespace std;

class lift_floors {
public:
    int  floor;
    char floor_status; //A for active N for not active
    lift_floors* next;
    lift_floors* prev;
    lift_floors(int data) {
        this->floor = data;
        this->next = NULL;
        this->prev = NULL;
        this->floor_status = 'A';
    }
};


int lift_operating_system(int requested_floor, lift_floors*& current, lift_floors*& head, lift_floors*& tail, char lift_status) {
    // determine valid floor range based on number of floors in the building
    int highest_floor = tail->floor;
    int lowest_floor = head->floor - 1;

    // validate requested floor
    if (requested_floor < lowest_floor || requested_floor > highest_floor) {
        cout << "Invalid Floor entered" << endl;
        return current->floor;
    }
    // check if lift is halted
    if (lift_status == 'H') {
        cout << "Lift is currently halted. Unhalt lift to use it. " << endl;
        return current->floor;
    }
    // move lift up
    if (requested_floor > current->floor) {
        if (current->next->floor_status == 'N') {
            cout << "Lift cannot go to this Floor" << endl;
            lift_status = 'H'; // update lift status to halt
            return current->floor;
        }
        cout << "Lift going up to floor " << current->next->floor << endl;
        return lift_operating_system(requested_floor, current->next, head, tail, lift_status);
    }
    // move lift down
    else if (requested_floor < current->floor) {
        if (current->prev->floor_status == 'N') {
            cout << "Lift cannot go to this Floor" << endl;
            lift_status = 'H'; // update lift status to halt
            return current->floor;
        }
        cout << "Lift going down to Floor " << current->prev->floor << endl;
        return lift_operating_system(requested_floor, current->prev, head, tail, lift_status);
    }
    // lift is already at requested floor
    else {
        cout << "Lift has arrived at Floor " << requested_floor << endl;
        return current->floor;
    }
}

int liftup(lift_floors*& current, lift_floors*& head, lift_floors*& tail, int requested_floor) {
    // base case: lift has reached requested floor
    if (current->floor == requested_floor) {
        return current->floor;
    }
    // check if lift can go up
    if (current->next->floor_status == 'N') {
        cout << "Lift cannot go to this Floor" << endl;
        return current->floor;
    }
    cout << "Lift going up to Floor " << current->next->floor << endl;
    return liftup(current->next, head, tail, requested_floor);
}

int liftdown(lift_floors*& current, lift_floors*& head, lift_floors*& tail, int requested_floor) {
    // base case: lift has reached requested floor
    if (current->floor == requested_floor) {
        return current->floor;
    }
    // check if lift can go down
    if (current->prev->floor_status == 'N') {
        cout << "Lift cannot go to this floor" << endl;
        return current->floor;
    }
    cout << "Lift going down to floor " << current->prev->floor << endl;
    return liftdown(current->prev, head, tail, requested_floor);
}

char halt_lift(char status) {
    status = 'H';
    cout << "Lift has been halted" << endl;
    return status;
}

char un_halt_lift(char status) {
    status = 'W';
    cout << "Lift is now working" << endl;
    return status;
}


void add_floor(lift_floors*& new_floor, lift_floors*& head, lift_floors*& tail) {
    if (head == NULL) {
        // if the list is empty, set the new floor as head and tail
        head = new_floor;
        tail = new_floor;
    }
    else {
        // add the new floor to the tail of the list
        tail->next = new_floor;
        new_floor->prev = tail;
        tail = new_floor;
    }
}

void skip_floor(lift_floors*& head, lift_floors*& tail, int floorNo) {
    // find the floor to skip
    lift_floors* current = head;
    while (current != NULL && current->floor != floorNo) {
        current = current->next;
    }
    if (current == NULL) {
        // floor not found
        cout << "Floor " << floorNo << " not found" << endl;
        return;
    }
    if (current->floor_status == 'N') {
        // floor is not operational
        cout << "Floor " << floorNo << " is not operational" << endl;
        return;
    }
    // update the neighboring floors
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    // remove the floor from the list
    if (current == head) {
        head = current->next;
    }
    if (current == tail) {
        tail = current->prev;
    }
    delete current;
}

void make_floor_operational(lift_floors*& head, lift_floors*& tail, int floorNo) {
    // find the floor to make operational
    lift_floors* current = head;
    while (current != NULL && current->floor != floorNo) {
        current = current->next;
    }
    if (current == NULL) {
        // floor not found
        cout << "Floor " << floorNo << " not found" << endl;
        return;
    }
    if (current->floor_status == 'O') {
        // floor is already operational
        cout << "Floor " << floorNo << " is already operational" << endl;
        return;
    }
    // make the floor operational
    current->floor_status = 'O';
}


int main()
{
    lift_floors* head;
    lift_floors* tail;
    lift_floors* current;
    int total_floors = 6; // total number of floors
    int current_floor = -1; // starts with basement
    int requested_service; //choice of user
    int requested_floor; //floor the lift goes on
    char status = 'W'; //W for working , H for halted

    //initialize everything and populate the linked list based on above data.
    head = new lift_floors(current_floor);
    tail = head;
    for (int i = 1; i < total_floors; i++) {
        tail->next = new lift_floors(i);
        tail->next->prev = tail;
        tail = tail->next;
    }
    current = head;

    while (1)
    {
        cout << "Please select a lift function of your choice: " << endl;
        cout << "1. Go to a specific floor" << endl;
        cout << "2. Halt the Lift" << endl;
        cout << "3. Unhalt the Lift" << endl;
        cout << "4. Show the current floor of the lift" << endl;
        cout << "5. Show all the floors with their status" << endl;
        cout << "6. Add a floor for the lift to operate" << endl;
        cout << "7. Skip a floor" << endl;
        cout << "8. Exit the Program" << endl;

        cin >> requested_service;

        switch (requested_service)
        {
        case 1:
        {
            cout << endl << "Enter Floor of choice: ";
            cin >> requested_floor;
            current_floor = lift_operating_system(requested_floor, current, head, tail, status);
            current = head;
            while (current != NULL) {
                if (current->floor == current_floor) {
                    break;
                }
                current = current->next;
            }
            break;
        }
        case 2:
        {
            status = halt_lift(status);
            break;
        }
        case 3:
        {
            status = un_halt_lift(status);
            break;
        }
        case 4:
        {
            cout << "Current floor is: " << current->floor << endl;
            break;
        }
        case 5:
        {
            current = head;
            while (current != NULL) {
                cout << "Floor " << current->floor << " is ";
                if (current->floor_status == 'A') {
                    cout << "active" << endl;
                }
                else {
                    cout << "not active" << endl;
                }
                current = current->next;
            }
            break;
        }
        case 6:
        {
            int new_floor_number;
            cout << endl << "Enter the Floor number to add: ";
            cin >> new_floor_number;

            if (new_floor_number < -1){//} || new_floor_number >= total_floors) {
                cout << "Invalid floor number" << endl;
                break;
            }

            lift_floors* new_floor = new lift_floors(new_floor_number);
            add_floor(new_floor, head, tail);
            total_floors++;

            cout << "Floor " << new_floor_number << " has been added" << endl;
            break;
        }
        case 7:
        {
            int floor_number_to_skip;
            cout << endl << "Enter the Floor number to skip: ";
            cin >> floor_number_to_skip;

            skip_floor(head, tail, floor_number_to_skip);
            total_floors--;

            cout << "Floor " << floor_number_to_skip << " has been skipped." << endl;
            break;
        }
        case 8:
        {
            cout << "Thankyou for using the Lift." << endl;
            exit(0);
            break;
        }
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
    return 0;
}

*/