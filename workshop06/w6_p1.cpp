#include <iostream>
#include <iomanip>
#include <fstream>
#include "Utilities.h"
#include "Utilities.h"
#include "Autoshop.h"
#include "Autoshop.h"


void loadData(const char* filename, sdds::Autoshop& as)
{
	std::ifstream file(filename);
	if (!file)
	{
		std::cerr << "ERROR: Cannot open file [" << filename << "].\n";
		return;
	}
	while (file)
	{
		sdds::Vehicle* aVehicle = sdds::createInstance(file);
		if (aVehicle)
			as += aVehicle;
	}
}

// ws cars.txt vans.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	sdds::Autoshop as,av;
	loadData(argv[1], as);
	std::cout << "--------------------------------\n";
	std::cout << "|  Car in the autoshop!        |\n";
	std::cout << "--------------------------------\n";
	as.display(std::cout);
	std::cout << "--------------------------------\n";

	loadData(argv[2], av);
	std::cout << "------------------------------------------------------------\n";
	std::cout << "|  Van in the autoshop!                                    |\n";
	std::cout << "------------------------------------------------------------\n";
	av.display(std::cout);
	std::cout << "------------------------------------------------------------\n";

	return 0;
}
