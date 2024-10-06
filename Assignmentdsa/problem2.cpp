#include<iostream>
#include<vector>
#include<random>
#include<cmath>
#include<cstdint>
#include<string>
using namespace std;

class Node {
public:
    uint64_t value;
    Node* next;

    Node(uint64_t value) {
        this->value = value;
        this->next = nullptr;
    }
};

void append(Node* &tail, uint64_t d) {
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
string linkedListToString(Node* head) {
    string largeNumber = "";
    while (head != nullptr) {
        largeNumber += to_string(head->value); 
        head = head->next;
    }
    return largeNumber;
}

uint64_t modular_pow(uint64_t base, uint64_t exponent, uint64_t mod) {
    uint64_t result = 1;
    base = base % mod;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % mod;
        exponent = exponent >> 1;
        base = (base * base) % mod;
    }
    return result;
}

bool millerTest(uint64_t d, uint64_t n) {
    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<uint64_t> dis(2, n - 2);
    
    uint64_t a = dis(gen); 
    uint64_t x = modular_pow(a, d, n);

    if (x == 1 || x == n - 1)
        return true;

    while (d != n - 1) {
        x = (x * x) % n;
        d *= 2;

        if (x == 1) return false;
        if (x == n - 1) return true;
    }

    return false;
}
bool isPrime(uint64_t n, int k = 5) {
    if (n <= 1 || n == 4) return false;
    if (n <= 3) return true;

    uint64_t d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    for (int i = 0; i < k; i++)
        if (!millerTest(d, n))
            return false;

    return true;
}

int main() {
    Node* node1 = new Node(1234567890123456789ULL);
    Node* head = node1;
    Node* tail = node1;

    append(tail, 9876543210987654321ULL);  
    append(tail, 1234567890123456789ULL);  
    append(tail, 9876543210987654321ULL);  
    string largeNumber = linkedListToString(head);
    cout << "Large number: " << largeNumber << endl;
    uint64_t chunkToTest = 9876543210987654321ULL;  
    if (isPrime(chunkToTest)) {
        cout << chunkToTest << " is prime!" << endl;
    } else {
        cout << chunkToTest << " is not prime!" << endl;
    }

    return 0;
}
