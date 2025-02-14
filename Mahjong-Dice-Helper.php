<?php

function throw_two_dice() {
    $dice1 = rand(1, 6);
    $dice2 = rand(1, 6);
    $total = $dice1 + $dice2;
    return array($dice1, $dice2, $total);
}

function find_mahjong_position($total) {
    $thrower_position = 2;
    $positions = array(
        1 => 'West (Left)',
        2 => 'South (Self)',
        3 => 'East (Right)',
        4 => 'North (Front)'
    );

    $final_position = (($thrower_position - 1 + ($total - 1)) % 4) + 1;
    return $positions[$final_position];
}

function calculate_stacks() {
    $first_throw = throw_two_dice();
    $position = find_mahjong_position($first_throw[2]);

    $second_throw = throw_two_dice();

    $final_stack_count = $first_throw[2] + $second_throw[2];

    echo "--- First throw ---\n";
    echo "Dice 1: " . $first_throw[0] . "\n";
    echo "Dice 2: " . $first_throw[1] . "\n";
    echo "Total : " . $first_throw[2] . "\n";
    echo "*** Position rolled to " . $position . " ***\n\n";

    echo "--- Second throw ---\n";
    echo "Dice 1: " . $second_throw[0] . "\n";
    echo "Dice 2: " . $second_throw[1] . "\n";
    echo "Total : " . $second_throw[2] . "\n\n";

    echo "--- Total Dice Value ---\n";
    echo $first_throw[2] . " + " . $second_throw[2] . " = " . $final_stack_count . "\n\n";

    echo "--- Stacks Counting ---\n";
    if ($final_stack_count > 17) {
        $positions = array(
            'West (Left)',
            'North (Front)',
            'East (Right)',
            'South (Self)'
        );

        $current_position_index = array_search($position, $positions); // Find the index
        $next_position_index = ($current_position_index + 1) % 4;
        echo "Stack starting from " . $positions[$next_position_index] . "\n";
        echo "Stack Position : " . ($final_stack_count - 17) . "\n";

    } else {
        echo "Stack Starting From " . $position . "\n";
        echo "Stack Position : " . ($final_stack_count + 1) . "\n";
    }
}

// Run the calculation
calculate_stacks();

?>