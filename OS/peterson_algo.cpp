#include <iostream>
#include <thread>
#include <vector>
using namespace std

const int N = 2; // Number of threads (producer and consumer)

std::vector<bool> flag(N, false); // Flags to indicate readiness
int turn = 0; // Variable to indicate turn

void producer(int j) {
    do {
        flag[j] = true; // Producer j is ready to produce
        turn = 1 - j;   // Allow consumer to consume
        while (flag[1 - j] && turn == 1 - j) {
            // Wait for consumer to finish
            // Producer waits if consumer is ready and it's consumer's turn
        }
        cout << "Producer\n";

        // Critical Section: Producer produces an item and puts it into the buffer

        flag[j] = false; // Producer is out of the critical section

        // Remainder Section: Additional actions after critical section
    } while (true); // Continue indefinitely
}

void consumer(int i) {
    do {
        flag[i] = true; // Consumer i is ready to consume
        turn = i;       // Allow producer to produce
        while (flag[1 - i] && turn == 1-i) {
            // Wait for producer to finish
            // Consumer waits if producer is ready and it's producer's turn
        }
        cout << "Consumer\n";

        // Critical Section: Consumer consumes an item from the buffer

        flag[i] = false; // Consumer is out of the critical section

        // Remainder Section: Additional actions after critical section
    } while (true); // Continue indefinitely
}

int main() {
    std::thread producerThread(producer, 0); // Create producer thread
    std::thread consumerThread(consumer, 1); // Create consumer thread

    producerThread.join(); // Wait for producer thread to finish
    consumerThread.join(); // Wait for consumer thread to finish

    return 0;
}