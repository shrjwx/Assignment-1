class Stack {

    int* arr;
    int top;
    int capacity;

public:
    Stack(int size) { // The constructor has been defined for you
        arr = new int[size];
        capacity = size;
        top = -1;
    }
    ~Stack() {
        delete[] arr;
    }

    // Function to add an element to the stack
    void push(int x) {
        if (isFull()) {
            cout << "Stack overflow. Cannot push " << x << endl;
            return;
        }
        arr[++top] = x;  // Add element and increment top
    }

    // Function to pop the top element
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow. Cannot pop." << endl;
            return -1; // Return -1 when there's nothing to pop
        }
        return arr[top--];  // Return the top element and decrement top
    }

    // Function to display the elements of the stack
    void display() const {
        if (isEmpty()) {
            cout << "Empty";
        } else {
            for (int i = 0; i <= top; i++) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }

private:

    // Function to check if the stack is full
    bool isFull() const {
        return top == capacity - 1; // Return true if the stack is full
    }

    // Function to check if the stack is empty
    bool isEmpty() const {
        return top == -1; // Return true if the stack is empty
    }
};

// Stacks have been defined globally for the towers A, B, and C for printing the towers at each step
Stack* A;
Stack* B;
Stack* C;

// Function to display the contents of the towers
void displayTowers() {
    cout << "Tower A: ";
    A->display();
    cout << "Tower B: ";
    B->display();
    cout << "Tower C: ";
    C->display();
    cout << "\n";
}

// Recursive function to move disks in Towers of Hanoi
void rearrangeDisks(int n, Stack& A, Stack& B, Stack& C, char from, char to, char aux) {
    if (n == 1) {
        int disk = A.pop();
        C.push(disk);
        cout << "Move disk " << disk << " from " << from << " to " << to << endl;
        displayTowers();
        return;
    }

    rearrangeDisks(n - 1, A, C, B, from, aux, to);  // Move n-1 disks from A to B using C as auxiliary
    int disk = A.pop();
    C.push(disk);  // Move the nth disk from A to C
    cout << "Move disk " << disk << " from " << from << " to " << to << endl;
    displayTowers();
    rearrangeDisks(n - 1, B, A, C, aux, to, from);  // Move n-1 disks from B to C using A as auxiliary
}

int main() { // The main function has been defined for you, do not edit anything here.
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;

    A = new Stack(n);
    B = new Stack(n);
    C = new Stack(n);

    // Initialize Tower A with n disks (largest disk at the bottom)
    for (int i = n; i >= 1; i--) {
        A->push(i);
    }

    // Display initial tower setup
    displayTowers();

    // Rearrange disks from A to C using B as auxiliary
    rearrangeDisks(n, *A, *B, *C, 'A', 'C', 'B');

    delete A;
    delete B;
    delete C;

    return 0;
}