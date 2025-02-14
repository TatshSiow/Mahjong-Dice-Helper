import random

def throw_two_dice():
    dice1 = random.randint(1, 6)
    dice2 = random.randint(1, 6)
    total = dice1 + dice2
    return dice1, dice2, total

def find_mahjong_position(total):   
    # Starting from South (position 2)
    thrower_position = 2
    positions = {1: 'West (Left)', \
                 2: 'South (Self)', \
                 3: 'East (Right)', \
                 4: 'North (Front)'}
    
    final_position = ((thrower_position - 1 + (total - 1)) % 4) + 1
    return positions[final_position]

def calculate_stacks():
    # First throw for position
    roll1, roll2, position_total = throw_two_dice()
    position = find_mahjong_position(position_total)
    
    # Second throw for stacks
    stack_roll1, stack_roll2, stack_total = throw_two_dice()
    
    # Total stacks is sum of both throws
    final_stack_count = position_total + stack_total
    
    print(f"--- First throw ---")
    print(f"Dice 1: {roll1}")
    print(f"Dice 2: {roll2}")
    print(f"Total : {position_total}")
    print(f"***Position rolled to {position}***")
    print()
    print(f"--- Second throw ---")
    print(f"Dice 1: {stack_roll1}")
    print(f"Dice 2: {stack_roll2}")
    print(f"Total : {stack_total}")
    print()
    print(f"--- Total Dice Value ---")
    print(f"{position_total} + {stack_total} = {final_stack_count}")
    print()
    print(f"--- Stacks Counting ---")
    if final_stack_count > 17:
        positions = ['West (Left)', \
                     'North (Front)', \
                     'East (Right)', \
                     'South (Self)']
        current_position_index = positions.index(position)  # Find the index of the current position
        next_position_index = (current_position_index + 1) % 4  # Cycle to the next position
        print(f"Stack starting from {positions[next_position_index]}")  # Return the next position's name
        print(f"Stack Position : {final_stack_count-17}")

    else:
        print(f"Stack Starting From {position}")   # Return the original position
        print(f"Stack Position : {final_stack_count+1}")

# Run the calculation
calculate_stacks()