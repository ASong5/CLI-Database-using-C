
/* -------------------------------------------
Name: Andrew Song
Student number: 117301184
Email: asong5@myseneca.ca
Section: Q
Date: 12/02/18
----------------------------------------------
Assignment: 2
Milestone:  1
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file beforze referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:

#include "contacts.h"
#include "contactHelpers.h"

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-1 Milestone-4 |
// |        function definitions below...            |
// +-------------------------------------------------+

// getName:
void getName(struct Name *name) {

	int middleInput;

	printf("Please enter the contact's first name: ");
	scanf(" %30[^\n]s", name->firstName);
	clearKeyboard();

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	middleInput = yes();
	if (middleInput == 1) {
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %6[^\n]s", name->middleInitial);
		clearKeyboard();
	}
	else
		name->middleInitial[0] = '\0';

	printf("Please enter the contact's last name: ");
	scanf(" %35[^\n]s", name->lastName);
	clearKeyboard();
}

// getAddress:
void getAddress(struct Address *address) {
	int apartmentInput, placeholder;

	do {
		printf("Please enter the contact's street number: ");
		placeholder = getInt();
		if (placeholder < 0) 
			continue;
		
		address->streetNumber = placeholder;
		break;
	} while (1);

	printf("Please enter the contact's street name: ");
	scanf(" %40[^\n]s", address->street);
	clearKeyboard();

	printf("Do you want to enter an apartment number? (y or n): ");
	apartmentInput = yes();
	if (apartmentInput == 1) {
		do {
			printf("Please enter the contact's apartment number: ");
			placeholder = getInt();
			if (placeholder < 0) 
				continue;
	
			address->apartmentNumber = placeholder;
			break;
		} while (1);
	}

	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]s", address->postalCode);
	clearKeyboard();

	printf("Please enter the contact's city: ");
	scanf(" %40[^\n]s", address->city);
	clearKeyboard();
}

// getNumbers:
void getNumbers(struct Numbers *numbers) {
	char homeInput, businessInput;

	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(numbers->cell);

	printf("Do you want to enter a home phone number? (y or n): ");
	homeInput = yes();
	if (homeInput == 1) {
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(numbers->home);
	}
	else
		numbers->home[0] = '\0';

	printf("Do you want to enter a business phone number? (y or n): ");
	businessInput = yes();
	if (businessInput == 1) {
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(numbers->business);
	}
	else
		numbers->business[0] = '\0';
}

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// getContact:
// Define Empty function definition below:
void getContact(struct Contact *contact)
{
	getName(&contact->name);
	getAddress(&contact->address);
	getNumbers(&contact->numbers);
}

