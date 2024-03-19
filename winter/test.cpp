#include <stdio.h>
#include <pthread.h>

#define N 10 // Change this value to the desired Fibonacci sequence length

// Structure to hold arguments for the thread function
struct ThreadArgs {
    int n;
    long long result;
};

// Function to calculate Fibonacci number
long long fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Thread function to calculate Fibonacci number and store the result in the ThreadArgs structure
void *fibonacciThread(void *args) {
    struct ThreadArgs *threadArgs = (struct ThreadArgs *)args;
    threadArgs->result = fibonacci(threadArgs->n);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    struct ThreadArgs threadArgs;

    // Create a thread to calculate Fibonacci number
    threadArgs.n = N;
    pthread_create(&thread, NULL, fibonacciThread, (void *)&threadArgs);

    // Wait for the thread to finish
    pthread_join(thread, NULL);

    // Print the result
    printf("Fibonacci(%d) = %lld\n", N, threadArgs.result);

    return 0;
}
