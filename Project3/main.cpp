/* CS 210 
 * Author: Cody Meaux
 * Date: 8/16/2025
 * Description: This code is designed to take a list of items purchased in a day as file. After that it will count the number of times an item appears on the list. There will be an option to 
 * have the user input an item they wish to look up, so that the program will output a numberic value for the times the word appears. a second option will print a list of all items purchased
 * with numbers that represent the frequency of purchases, by outputting the name of the item paired with the number of times the item appears on the list. The third option for the main menu
 * will be to print the same information from menu option two in the form of a histogram. This is my first attempt at not using namespace std as I saw some documentation that noted issues that can
 * arrise from using namespace std, and that they can be avoided by not using it. */

#include "ItemTracking.h"
#include <iostream>
#include <fstream>

int main() {

	ItemTracking track("CS210_Project_Three_Input_File.txt", "count.dat"); // creates an item tracking object using the input and output files as arguments.

	int menuInput; // creates a variable for the user menu input.
	std::string item; // creates a variable for the user to enter an item that they are trying to search for.

	do { // using a do-while ensures the menu prints in the beginning no matter what.
		track.PrintMenu(); // call print menu.
		std::cin >> menuInput; // get user input for the menu.

		while (std::cin.fail() || menuInput < 1 || menuInput > 4) { // accounts for incorrect input for the menu.
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "\nInvalid menu option. Please enter a number from 1 to 4: "; // prompts user to re-enter a menu option.
			std::cin >> menuInput; // get user input for the menu.
		}

		switch (menuInput) { // switch statement to iterate throught the menu options.
		case 1:
			std::cout << "Enter the item's name: "; //prompt the user to enter an item from the list.
			std::cin >> item; // get user input for which item to output information for.
			std::cout << item << "--" << track.GetItemCount(item) << std::endl; // output the item and it's count to the screen.(if item not present on list it will print 0).
			break;
		case 2:
			track.PrintAllCount(); // call PrintAllCount to print a list of items and the times they were purchased.
			break;
		case 3:
			track.PrintHistogram(); // call PrintHistogram to print the list of items and the times they were purchased visualized as a histogram.
			break;
		}
	} while (menuInput != 4); // if input is menu option 4 exit the program.

	std::cout << "\nGoodbye."; // output goodbye message to the user if they exit the menu.
	return 0;

}