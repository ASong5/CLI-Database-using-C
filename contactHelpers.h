#pragma once
#pragma once
/* ------------------------------------------------------------------
Name: Andrew Song
Student number: 117301184
Email: asong5@myseneca.ca
Section: Q
Date: 12/02/18
---------------------------------------------------------------------
Assignment: 2
Milestone:  1
---------------------------------------------------------------------
Description: This header file modularizes general helper functions to
			 help reduce redundant coding for common repetitive tasks.
---------------------------------------------------------------------*/

// HINT: 
// You will most likely want to include this header file
// in other files of the project since it provides general 
// helper functions that can be used throughout.

#include "contacts.h"
//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// Clear the standard input buffer
void clearKeyboard(void);

// pause:
// Put function prototype below:
void pause(void);
// getInt:
// Put function prototype below:
int getInt(void);
// getIntInRange:
// Put function prototype below:
int getIntInRange(int, int);
// yes:
// Put function prototype below:
int yes(void);
// menu:
// Put function prototype below:
int menu(void);
// contactManagerSystem:
// Put function prototype below:
void contactManagerSystem(void);

void getTenDigitPhone(char *);

int findContactIndex(const struct Contact[], int, const char[]);

void displayContactHeader(void);

void displayContactFooter(int);

void displayContact(const struct Contact *);

void displayContacts(const struct Contact *, int);

void searchContacts(const struct Contact *, int);

void addContact(struct Contact *, int);

void updateContact(struct Contact *, int);

void deleteContacts(struct Contact *, int);

void sortContacts(struct Contact *, int);

