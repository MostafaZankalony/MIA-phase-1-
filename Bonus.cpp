#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Queue implementation using two stacks
class QueueUsingStacks {
private:
    stack<string> stack1, stack2;

public:
    // Enqueue operation
    void enqueue(string item) {
        stack1.push(item);
    }

    // Dequeue operation
    string dequeue() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        if (stack2.empty()) {
            throw out_of_range("Queue is empty!");
        }

        string item = stack2.top();
        stack2.pop();
        return item;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return stack1.empty() && stack2.empty();
    }
};

int main() {
    // Batman's Gadgets
    string batmanWeapons[] = { "Batarang", "GrappleGun", "ExplosiveGel", "Batclaw" };
    string batmanShields[] = { "CapeGlide", "SmokePellet" };

    // Create a queue using two stacks
    QueueUsingStacks queue;

    // Enqueue Batman's weapons
    for (string weapon : batmanWeapons) {
        queue.enqueue(weapon);
    }

    // Enqueue Batman's shields
    for (string shield : batmanShields) {
        queue.enqueue(shield);
    }

    // Display the contents of the queue
    cout << "Contents of the queue:" << endl;
    while (!queue.isEmpty()) {
        cout << queue.dequeue() << endl;
    }

    return 0;
}
