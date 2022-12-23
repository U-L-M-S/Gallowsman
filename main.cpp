#include <iostream>
#include <string>
#include <algorithm>  // for std::find
#include <random>     // for std::mt19937
#include <chrono>     // for std::chrono::system_clock

int main() {
  // Initialize a random number generator
  std::mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());

  // List of words to choose from
  const std::vector<std::string> words = {
    "DOG", "BIRD", "SHARK", "CAT", "ZEBRA", "BURRO", "CROCODILE", "SNAKE", "FISH", "MONKEY"
  };

  // Choose a random word from the list
  const std::string chosen_word = words[rng() % words.size()];

  // Create a string to hold the letters that have been correctly guessed
  std::string correctly_guessed(chosen_word.size(), '*');

  // Number of remaining attempts
  int remaining_attempts = 10;

  // Loop until the word is fully revealed or the user runs out of attempts
  while (std::find(correctly_guessed.begin(), correctly_guessed.end(), '*') != correctly_guessed.end() && remaining_attempts > 0) {
    std::cout << "You are looking for the following word: " << correctly_guessed << std::endl;
    std::cout << "You have " << remaining_attempts << " attempts remaining." << std::endl;

    char c;
    std::cin >> c;

    // Check if the input letter appears in the chosen word
    if (chosen_word.find(c) == std::string::npos) {
      // The letter does not appear in the word, decrement the remaining attempts
      --remaining_attempts;
    } else {
      // The letter appears in the word, reveal it in the correctly guessed string
      for (std::size_t i = 0; i < chosen_word.size(); ++i) {
        if (chosen_word[i] == c) {
          correctly_guessed[i] = c;
        }
      }
    }
  }

  // Display the final result
  if (remaining_attempts > 0) {
    std::cout << "Congratulations! You won! |o|" << std::endl;
  } else {
    std::cout << "Oh... You lost. More luck next time..." << std::endl;
  }

  return 0;
}

