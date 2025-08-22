#include "ItemTracking.h"
#include <iomanip>
#include <fstream>
#include <iostream>

ItemTracking::ItemTracking(const std::string& inputFile, const std::string& outputFile) { // Create default constructor. that takes the input file and output file as an argument.
	LoadFile(inputFile);
	SaveCountInFile(outputFile);
}

void ItemTracking::LoadFile(const std::string& fileName) { // this function opens the file and fills the contents of the file into a map, then closes the file.
	std::ifstream inFile(fileName); // open file.
	std::string item;
	while (inFile >> item) { //populate map.
		++countMap[item];
	}
	inFile.close(); // closes file after opening map.
}

void ItemTracking::SaveCountInFile(const std::string& fileName) { // this function saves the items
	std::ofstream outFile(fileName);
	for (const auto& pair : countMap) {
		outFile << pair.first << " " << pair.second << "";
	}
	outFile.close(); // closes the output file after saving information
}

int ItemTracking::GetItemCount(const std::string& itemName) const { // this function will be used with the user input to return the count of the keyword that the user enters.
	auto it = countMap.find(itemName);
	if (it != countMap.end()) {
		return it->second;
	}
	return 0;
}

void ItemTracking::PrintAllCount() const { // this function is to print all of the individual items from the map, and output their count in a list to the screen.
	for (const auto& pair : countMap) {
		std::cout << std::left << std::setw(15) << pair.first << ": " << pair.second << "\n";
	}
}

void ItemTracking::PrintHistogram() const { // this function does the same as PrintAllCount, but instead uses a histogram to visually represent the number of times an item was purchased.
	for (const auto& pair : countMap) {
		std::cout << std::left << std::setw(15) << pair.first << ": " << std::string(pair.second, '$') << "\n";
	}
}

void ItemTracking::PrintMenu() const { // this is a function that will print out the main menu for the user. Using this will help to reduce the amount of code in main.
	std::cout << "\n       Corner Grocer Item Counter       \n";
	std::cout << "1. Find item count\n";
	std::cout << "2. Print all items count\n";
	std::cout << "3. Print all items histogram\n";
	std::cout << "4. Exit\n";
	std::cout << "Please choose a menu option by number: ";
}
