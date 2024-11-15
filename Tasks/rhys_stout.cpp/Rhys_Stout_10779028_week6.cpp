#include "mbed.h"

DigitalOut led(LED1); // LED for visual feedback

#define STACK_SIZE 4 // Size of the stack (4 elements)
int stack[STACK_SIZE]; // Stack array
int top = 0; // Stack pointer

void push(int value) {
    if (top >= STACK_SIZE) {
        printf("ERROR- Stack is full.\n"); // Handle stack full case
        return;
    }
    stack[top++] = value; // Push value onto stack and increment top
}

int pop() {
    if (top <= 0) {
        printf("ERROR- Stack is empty.\n"); // Handle stack empty case
        return -1; // Return an error value
    }
    return stack[--top]; // Decrement top and return the value
}

void display_top() {
    if (top <= 0) {
        printf("Error: Stack is empty.\n"); // Handle stack empty case
    } else {
        printf("Top value: %d\n", stack[top - 1]); // Display the top value
    }
}

int main() {
    push(10);          // Push first value
    push(20);          // Push second value

    display_top();     // Display top value after pushing

    pop();             // Pop the top value
    display_top();     // Display new top value after popping

    while (1) {
        led = !led; // Blink LED
        ThisThread::sleep_for(500ms); // Wait half a second
    }
}








