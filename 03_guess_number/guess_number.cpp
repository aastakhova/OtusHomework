#include <iostream>
#include <fstream>
#include "high_score.h"

int main(int argc, char** argv){
    int max_value = 100;
    // parse command line arguments
	if (argc >= 2) {
		std::string arg1_value{ argv[1] };
		if (arg1_value == "-max") {
            if (argc < 3) {
				std::cout << "Wrong usage! The argument '-max' requires some value!" << std::endl;
				return -1;
			}
			// parse the string to the int value
			max_value = std::stoi(argv[2]);
			std::cout << "max value was set to " << max_value << std::endl;
		}

        if (arg1_value == "-table") {
            read_high_score_file();
            std::exit(0);
        }
	}

	int current_value = 0;
	bool not_win = true;

	std::srand(std::time(nullptr)); // use current time as seed for random generator

	const int random_value = std::rand() % max_value;

	// Ask about name
	std::cout << "Hi! Enter your name, please:" << std::endl;
	std::string user_name;
	std::cin >> user_name;

    std::cout << "Enter your guess:" << std::endl;
    int attempts_count = 0;

	do {
		std::cin >> current_value;
        attempts_count++;
		if (current_value < random_value) {
			std::cout << "greater than " << current_value << std::endl;
		}
		else if (current_value > random_value) {
			std::cout << "less than " << current_value << std::endl;
		}
		else {
			std::cout << "you win!" << std::endl;
			break;
		}

	} while(true);

    write_high_score(user_name, attempts_count);
	read_high_score_file();
    return 0;
}