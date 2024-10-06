#include <iostream>
using namespace std;

class Node {
public:
    int proceesId;
    int executionTime;
    int remainingTime;
    Node* next;

    Node(int proceesId, int executionTime) {
        this->proceesId = proceesId;
        this->executionTime = executionTime;
        this->remainingTime = executionTime;
        this->next = nullptr;
    }

    ~Node() {
        cout << "Successfully deleted process P" << proceesId << endl;
    }
};

void addProcess(Node*& head, int id, int time, Node*& tail) {
  Node* temp = new Node(id, time);
    tail->next = temp;
    tail = temp;
    tail->next = head;
}

void print(Node* head) {
    Node* temp = head;
    cout << "Current Process States: [";
    do {
        cout << "(P" << temp->proceesId << "," << temp->remainingTime << "),";
        temp = temp->next;
    } while (temp != head);
    cout << "]" << endl;
}

void ProcessTime(Node*& head, int time, Node*& tail) {
    bool processesRemaining = true;
    Node* temp = head;
    

    while (processesRemaining) {
        processesRemaining = false;
        do {
            if (temp->remainingTime > 0) {
                processesRemaining = true;
            if (temp->remainingTime <= time) {
                    cout << "P" << temp->proceesId << " completes execution." << endl;
                 temp->remainingTime = 0;
            } else {
                  temp->remainingTime -= time;
                  cout << "P" << temp->proceesId << " runs, remaining time: " << temp->remainingTime << endl;
              }
            }
            temp = temp->next;
        } while (temp != head);

        print(head);
        char addNew;
        cout << "Do you want to add a new process? (y/n) ";
        cin >> addNew;
       if (addNew == 'y' || addNew == 'Y') {
        int newProcessId ;
        cout << "Enter the new ID " <<  ": ";
        cin>>newProcessId;
            int newExecutionTime;
        cout << "Enter the new execution time " << newProcessId << ": ";
       cin >> newExecutionTime;
        addProcess(head, newProcessId, newExecutionTime, tail);
        cout << "New process P" << newProcessId << " added with execution time: " << newExecutionTime << endl;
         newProcessId++;
        }
    }
}

int main() {
    Node* process1 = new Node(1, 5);
    Node* head = process1;
    Node* tail = process1;
    tail->next = head;

    addProcess(head, 2, 10, tail);
     addProcess(head, 3, 15, tail);
    print(head);

    int processTime;
    cout << "Enter the CPU Time per Process per Cycle: ";
    cin >> processTime;

    ProcessTime(head, processTime, tail);

    return 0;
}
