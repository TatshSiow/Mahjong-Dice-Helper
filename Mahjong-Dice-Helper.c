#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to simulate throwing two dice
void throw_two_dice(int *dice1, int *dice2, int *total) {
    *dice1 = (rand() % 6) + 1;
    *dice2 = (rand() % 6) + 1;
    *total = *dice1 + *dice2;
}

// Function to find the Mahjong position
const char* find_mahjong_position(int total) {
    // Starting from South (position 2)
    int thrower_position = 2;
    const char* positions[] = {"West (Left)", "South (Self)", "East (Right)", "North (Front)"};

    int final_position = ((thrower_position - 1 + (total - 1)) % 4) + 1;
    return positions[final_position - 1]; // Adjust index for C (0-based)
}

// Function to calculate stacks
void calculate_stacks() {
    int roll1, roll2, position_total;
    int stack_roll1, stack_roll2, stack_total;
    const char* position;
    int final_stack_count;

    // First throw for position
    throw_two_dice(&roll1, &roll2, &position_total);
    position = find_mahjong_position(position_total);

    // Second throw for stacks
    throw_two_dice(&stack_roll1, &stack_roll2, &stack_total);

    // Total stacks is sum of both throws
    final_stack_count = position_total + stack_total;

    printf("--- First throw ---\n");
    printf("Dice 1: %d\n", roll1);
    printf("Dice 2: %d\n", roll2);
    printf("Total : %d\n", position_total);
    printf("*** Position rolled to %s ***\n\n", position);

    printf("--- Second throw ---\n");
    printf("Dice 1: %d\n", stack_roll1);
    printf("Dice 2: %d\n", stack_roll2);
    printf("Total : %d\n\n", stack_total);

    printf("--- Total Dice Value ---\n");
    printf("%d + %d = %d\n\n", position_total, stack_total, final_stack_count);

    printf("--- Stacks Counting ---\n");
    if (final_stack_count > 17) {
        const char* positions[] = {"West (Left)", "North (Front)", "East (Right)", "South (Self)"};
        int current_position_index;
        for (current_position_index = 0; current_position_index < 4; current_position_index++) {
            if (strcmp(positions[current_position_index], position) == 0) {
                break;
            }
        }
        int next_position_index = (current_position_index + 1) % 4;
        printf("Stack starting from %s\n", positions[next_position_index]);
        printf("Stack Position : %d\n", final_stack_count - 17);

    } else {
        printf("Stack Starting From %s\n", position);
        printf("Stack Position : %d\n", final_stack_count + 1);
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    calculate_stacks();
    return 0;
}