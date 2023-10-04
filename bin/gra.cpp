#include "animations.hpp"
#include "colors.hpp"

#include <chrono>
#include <thread>
#include <iostream>
#include <fstream>


void boot_animation();

bool test() {
	const std::string& file_path = "/home/test42/gra/42.c";
	system("clear");
    std::ifstream file(file_path);
    if (!file) {
        std::cerr << C_ERROR << "Oj, coś poszło nie tak... Plik nie został zapisany." << std::endl;
        return false;
    }

    if (file.peek() == std::ifstream::traits_type::eof()) {
        std::cerr << C_ERROR << "Oj, coś poszło nie tak... Plik nie został zapisany." << std::endl;
        return false;
    }

    std::string compile_command = "gcc -o gra " + file_path + " -lm";// > /dev/null 2>&1";
    int compile_result = system(compile_command.c_str());

    if (compile_result != 0) {
        std::cerr << C_ERROR << "Coś poszło nie tak podczas kompilacji..." << std::endl;
        return false;
    }
    system("./gra");
    return true;
}

int main(int ac, char **av)
{
	if (ac > 1)
	{
		if(av[1][0] == '0')
			instructions();
		else if (av[1][0] == '1')
		{
			if (test() == true)
				std::cout << GREEN <<"\nGratulujemy! Napisałeś/aś swój pierwszy program!\nWłaśnie zostałeś/aś początkującym/ą programistą/ką. :)\n\nBardzo dziękujemy za udział w naszej grze.\nBy odebrać nagrodę,\nzgłoś się do Igi w miejscu, gdzie rozpoczynałeś/aś grę." << std::endl;
			else
				std::cout << GREEN <<"Spróbuj ponownie :)" << std::endl;
		}
		else
			system("rm /home/test42/gra/42.c");
	}
	return 0;
}
