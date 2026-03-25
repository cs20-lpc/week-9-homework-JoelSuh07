#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "ArrayQueue.hpp"
#include "LinkedQueue.hpp"

using namespace std;

// Factory Class to generate the appropriate Queue type
class QueueFactory {
public:
    // Returns a LinkedQueue if no size is specified (size < 0)
    // Returns an ArrayQueue if a specific size is provided
    static Queue<int>* GetQueue(int size = -1) {
        if (size < 0) {
            return new LinkedQueue<int>();
        } else {
            return new ArrayQueue<int>(size);
        }
    }
};

int main() {
    srand(time(0));

    // Simulation 1: Ticket Counter (Fixed Capacity)
    cout << "--- Simulation 1: Ticket Counter (Array-based Queue) ---" << endl;
    Queue<int>* ticketCounter = QueueFactory::GetQueue(10);
    int turnedAway = 0;
    int served1 = 0;

    for (int i = 0; i < 100; ++i) {
        int action = (rand() % 3) - 1; // Generates -1, 0, or 1
        
        if (action < 0) {
            if (!ticketCounter->isEmpty()) {
                ticketCounter->dequeue();
                served1++;
            }
        } else {
            try {
                ticketCounter->enqueue(1);
            } catch (string e) {
                turnedAway++;
            }
        }
    }
    cout << "Customers served: " << served1 << endl;
    cout << "Customers turned away: " << turnedAway << endl;
    cout << "Final queue length: " << ticketCounter->getLength() << endl << endl;

    delete ticketCounter;

    // Simulation 2: Bank Service Line (Dynamic Capacity)
    cout << "--- Simulation 2: Bank Service Line (Linked-list Queue) ---" << endl;
    Queue<int>* bankLine = QueueFactory::GetQueue(); // No parameter = LinkedQueue
    int served2 = 0;

    for (int i = 0; i < 100; ++i) {
        int action = (rand() % 4) - 1; // Generates -1, 0, 1, or 2
        
        if (action < 0) {
            if (!bankLine->isEmpty()) {
                bankLine->dequeue();
                served2++;
            }
        } else {
            // LinkedQueue grows dynamically, no need for try-catch for "full" state
            bankLine->enqueue(1);
        }
    }
    cout << "Customers served: " << served2 << endl;
    cout << "Final queue length: " << bankLine->getLength() << endl;

    delete bankLine;

    return 0;
}
