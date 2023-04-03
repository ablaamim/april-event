<?php
// array to map computer's random choice to rock, paper, or scissors
$choices = array(1 => 'rock', 2 => 'paper', 3 => 'scissors');

// prompt user for their choice
echo "Choose rock, paper, or scissors: ";
$user_choice = strtolower(trim(fgets(STDIN))); // read user input from command line

// validate user input
while (!in_array($user_choice, ['rock', 'paper', 'scissors'])) {
    echo "Invalid choice. Please choose rock, paper, or scissors: ";
    $user_choice = strtolower(trim(fgets(STDIN)));
}

// generate computer's random choice
$computer_choice = $choices[rand(1,3)];

// announce winner
if ($user_choice == $computer_choice) {
    echo "It's a tie! The computer also chose {$computer_choice}.\n";
} elseif (($user_choice == 'rock' && $computer_choice == 'scissors')
       || ($user_choice == 'paper' && $computer_choice == 'rock')
       || ($user_choice == 'scissors' && $computer_choice == 'paper')) {
    echo "Congratulations! You won! The computer chose {$computer_choice}.\n";

}
else {
    echo "Sorry, you lost! The computer chose {$computer_choice}.\n";
}
?>