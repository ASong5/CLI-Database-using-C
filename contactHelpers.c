/* -------------------------------------------
Name: Andrew Song
Student number: 117301184
Email: asong5@myseneca.ca
Section: Q
Date: 12/02/18
----------------------------------------------
Assignment: 2
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS
#define MAXCONTACTS 5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// This source file needs to "know about" the functions you prototyped
//       in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:

#include "contactHelpers.h"

//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+

// clearKeyboard:  Empty function definition 
void clearKeyboard(void)
{
	while (getchar() != '\n')
		;  // empty statement intentional 
}

// pause: Empty function definition goes here:

void pause(void)
{
	printf("(Press Enter to Continue)\n");
	clearKeyboard();
}

// getInt: Empty function definition goes here:

int getInt(void)
{
	int integer = 0;
	char NL;

	do {
		scanf("%d%c", &integer, &NL);
		if (NL != '\n') {
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}
	} while (NL != '\n');
	return integer;
}

// getIntInRange: Empty function definition goes here:

int getIntInRange(int lower, int upper)
{
	int integer = 0;

	integer = getInt();
	while (integer < lower || integer > upper) {
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", lower, upper);
		integer = getInt();
	}
	return integer;
}

// yes: Empty function definition goes here:

int yes(void)
{
	char character, NL;

	do {
		scanf("%c%c", &character, &NL);

		if (NL == '\n') {
			if (character == 'y' || character == 'Y') {
				return 1;
			}

			else if (character == 'n' || character == 'N') {
				return 0;
			}
		}
		else {
			clearKeyboard();
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable: ");
		}
	} while (1);
}

// menu: Empty function definition goes here:

int menu(void)
{
	int option = 0;

	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n\n");

	printf("Select an option:> ");
	option = getIntInRange(0, 6);
	printf("\n");
	return option;
}

// contactManagerSystem: Empty function definition goes here:

void contactManagerSystem(void)
{
	struct Contact contacts[MAXCONTACTS] =
	{ { {"Rick", {'\0'}, "Grimes" },
		{11, "Trailer Park", 0, "A7A 2J2", "King City" },
		{"4161112222", "4162223333", "4163334444" } },
	  {
		{"Maggie", "R.", "Greene" },
		{55, "Hightop House", 0, "A9A 3K3", "Bolton" },
		{"9051112222", "9052223333", "9053334444" } },
	  {
		{"Morgan", "A.", "Jones" },
		{77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough"},
		{"7051112222", "7052223333", "7053334444" } },
	  {
		{"Sasha", {'\0'}, "Williams" },
		{55, "Hightop House", 0, "A9A 3K3", "Bolton"},
		{"9052223333", "9052223333", "9054445555" } },
	};
	int option = 0;
	do {
		option = menu();

		switch (option)
		{
		case 1:
			displayContacts(contacts, MAXCONTACTS);
			pause();
			break;
		case 2:
			addContact(contacts, MAXCONTACTS);
			pause();
			break;
		case 3:
			updateContact(contacts, MAXCONTACTS);
			pause();
			break;
		case 4:
			deleteContacts(contacts, MAXCONTACTS);
			pause();
			break;
		case 5:
			searchContacts(contacts, MAXCONTACTS);
			pause();
			break;
		case 6:
			sortContacts(contacts, MAXCONTACTS);
			pause();
			break;
		case 0:
			printf("Exit the program? (Y)es/(N)o: ");
			option = yes();
			if (option == 1) {
				printf("\nContact Management System: terminated\n");
				exit(1);
			}
			printf("\n");
		}
	} while (1);
}
// Reads and validates for a valid 10 digit number. If character is found or not 10 digits, throw error.
void getTenDigitPhone(char telNum[])
{
	int needInput = 1;
	char character = '\0';

	while (needInput == 1) {
		scanf(" %10[0-9]", telNum);
		character = getchar();
		// (String Length Function: validate entry of 10 characters and only digits)
		if (character == '\n' && strlen(telNum) == 10)
			needInput = 0;
		else {
			printf("Enter a 10-digit phone number: ");
			if (character != '\n')
				clearKeyboard();
		}
	}
}
// Returns the index of the received cell phone number. If not found, return -1.
int findContactIndex(const struct Contact *contacts, int size, const char *cellNum)
{
	int match;
	int i;
	for (i = 0; i < size; i++) {
		match = strcmp(cellNum, contacts[i].numbers.cell);
		if (match == 0)
			return i;
	}
	return -1;
}
// Displays the header for displaying contacts.
void displayContactHeader(void)
{
	printf("+-----------------------------------------------------------------------------+");
	printf("\n|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}
// Displays total valid contacts counter.
void displayContactFooter(int size)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", size);
}
// Provides the formatting for displaying contacts.
void displayContact(const struct Contact *contacts)
{
	if (contacts->name.middleInitial[0] == '\0')
		printf(" %s %s\n", contacts->name.firstName, contacts->name.lastName);
	else
		printf(" %s %s %s\n", contacts->name.firstName, contacts->name.middleInitial, contacts->name.lastName);
	printf("    C: %-10s   H: %-10s   B: %-10s\n", contacts->numbers.cell, contacts->numbers.home, contacts->numbers.business);
	printf("       %d %s, ", contacts->address.streetNumber, contacts->address.street);
	if (contacts->address.apartmentNumber > 0)
		printf("Apt# %d, ", contacts->address.apartmentNumber);
	printf("%s, %s\n", contacts->address.city, contacts->address.postalCode);
}
// Displays all valid contacts via header/footer functions, as well as displayContact function.
void displayContacts(const struct Contact *contacts, int size)
{
	int i, validContact = 0;
	displayContactHeader();
	for (i = 0; i < size; i++) {
		if (strlen(contacts[i].numbers.cell) > 0) {
			displayContact(&contacts[i]);
			validContact++;
		}
	}
	displayContactFooter(validContact);
}
// Prompts user for a cell phone number, if found, displays specified user via displayContact function
void searchContacts(const struct Contact *contacts, int size)
{
	int cellIndex;
	char cellNumber[11];
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNumber);
	cellIndex = findContactIndex(contacts, MAXCONTACTS, cellNumber);
	if (cellIndex > -1) {
		printf("\n");
		displayContact(&contacts[cellIndex]);
		printf("\n");
	}
	else
		printf("*** Contact NOT FOUND ***\n\n");
}
// If empty slot available, allows user to add new contact via getContact function. Otherwise, throws error stating full contact list.
void addContact(struct Contact *contacts, int size)
{
	int i, match = 0;
	for (i = 0; i < size; i++) {
		if (strlen(contacts[i].numbers.cell) == 0) {
			getContact(&contacts[i]);
			printf("--- New contact added! ---\n\n");
			match = 1;
			break;
		}
	}
	if (match == 0)
		printf("*** ERROR: The contact list is full! ***\n\n");
}
/* Prompts user for a cell phone number, if found, calls getName, getAddress,
and getNumbers individually for updating contact information for contact with
that cell phone number. */
void updateContact(struct Contact *contacts, int size)
{
	int cellIndex;
	char cellNumber[11];
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNumber);
	cellIndex = findContactIndex(contacts, MAXCONTACTS, cellNumber);
	if (cellIndex == -1)
		printf("*** Contact NOT FOUND ***\n\n");
	else {
		printf("\nContact found:\n");
		displayContact(&contacts[cellIndex]);
		printf("\n");
		printf("Do you want to update the name? (y or n): ");
		if (yes() == 1)
			getName(&contacts[cellIndex].name);
		printf("Do you want to update the address? (y or n): ");
		if (yes() == 1)
			getAddress(&contacts[cellIndex].address);
		printf("Do you want to update the numbers? (y or n): ");
		if (yes() == 1)
			getNumbers(&contacts[cellIndex].numbers);
		printf("--- Contact Updated! ---\n\n");
	}
}
// Prompts user for cell number, if found, deletes contact with that number (after selecting 'y').
void deleteContacts(struct Contact *contacts, int size)
{
	int cellIndex;
	char cellNumber[11];
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNumber);
	cellIndex = findContactIndex(contacts, MAXCONTACTS, cellNumber);
	if (cellIndex == -1)
		printf("*** Contact NOT FOUND ***\n");
	else {
		printf("\nContact found:\n");
		displayContact(&contacts[cellIndex]);
		printf("\nCONFIRM: Delete this contact? (y or n): ");
		if (yes() == 1) {
			contacts[cellIndex].numbers.cell[0] = '\0';
			printf("--- Contact deleted! ---\n");
		}
		printf("\n");
	}
}
/* Sorts contact list via selection sort algorithm. Uses strtoll() to convert cell phone number to its integer format for
number comparison. Prototype for this function: long long strtoll(const char *nptr, char **endptr, int base);
strtoll() is used because strol() would overflow when used with a number in the billions (cell phone number is 10
digits -> in the billions). atoll() would work as well, but it is not as safe because it returns 0 upon any error, which
will lead to erroneous results if we were to consider 0 as a valid input (even though we are not for this milestone, I believe
it is still better practice). Strtoll() will throw an exception upon error, which is much safer. */
void sortContacts(struct Contact *contacts, int size)
{
	int i, j, validContacts = 0;

	// Stores placeholder variable 'temp' of type Contact for swapping.
	struct Contact temp;
	// Pointer that will point to address of unconverted string in strtoll().
	char *ptr;

	// Grabs number of valid contacts and stores in 'validContacts' variable .
	for (i = 0; i < size; i++)
		if (strlen(contacts[i].numbers.cell) > 0)
			validContacts++;

	// Selection sort algorithm to sort array from lowest to highest based on cell phone number.
	for (i = 0; i < validContacts; i++) {	
		for (j = i + 1; j < validContacts; j++) {
			if (strtoll(contacts[j].numbers.cell, &ptr, 10) < strtoll(contacts[i].numbers.cell, &ptr, 10)) {		
				temp = contacts[i];
				contacts[i] = contacts[j];
				contacts[j] = temp;
			}
		}
	}
	printf("--- Contacts sorted! ---\n\n");
}