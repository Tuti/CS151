// Program Name: 		main.cpp
// File Name: 			c-String
// Programmer: 			Jose Huerta, Sahni Coe, Dylan Norris-Hinkle, Victor Lopez
// Date last Motified: 	15 March 2018
//
// Program Statement: Showcase a multitude of different c-string functions
//
// Overall Plan: (Step by step)
// 1. Declare variable, initialize, and apply the c-strings
// 2. Apply the functions of Table 12-1
//		A) strlen function will get the length of the string
//		B) strcat function will concatenate the string
//  	C) strcpy function will copy the string
//		D) strcmp function will compare string1 and string2
// 3. Use four methods  of www.cplusplus.com/reference/clibrary/cstring
//		A) strcpy function will copy the string
//		B) strcat function will concatenate the string
//		C) strpbrk fuction will find the character in the string
//		D) memset function will replace the string with block meory
// 4. Makes two string/numeric functions
//		A) atoi function will convert a tring to an int
// 		B) atol function will convert a string to long integer

#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	char s1[80]; //declaration
	char s2[80]; //declaration
	char strTemp[80];//declaration
	strcpy(s1, "something"); //initialization 
	strcpy(s2, "else"); //initialization 
	strcpy(strTemp, ""); //initialization 
	const int size = 80;
	int numericValue = 0;
	int longValue = 0;
	char greetings[size] = "5000";
	char greet[size] = "1000000000";
	
	std::cout << "s1: " << s1 << "\n"; //use
	std::cout << "s2: " << s2 << "\n\n"; //use
	
	std::cout << "Size of string: " << strlen(s1) << "\n"; // strlen
	
	strcat(s1, s2);
	std::cout << "Append s2 to s1: " << s1 << "\n\n";
	
	strcpy(s1, s2);
	std::cout << "s1: " << s1 << "\n\n";
	
	strcpy(s1, "a");
	strcpy(s2, "b");
	
	std::cout << "s1: " << s1 << " s2: " << s2 << "\n";
	std::cout << "s1 and s2 comparision: " << strcmp(s1, s2) << "\n\n";
	
	strcpy(s1, "f");  // using strcpy
	strcpy(s2, "else"); // using strcpy
	
	char *pch = strpbrk(s2, s1); //using strpbrk
	std::cout << "Checking if the letter f occurs in the word else (if nothing prints, it does not occur): " << "\n\n";
	while (pch != NULL) {
		std::cout << pch << "\n";
	}
	
	strcpy(s1, "this"); // using strcpy
	strcpy(s2, " and that"); // using strcpy
	
	strcat(strTemp, s1); // using strcat
	strcat(strTemp, s2); // using strcat
	
	std::cout << "Strcat demo: \n";
	puts(strTemp);
	
	std::cout << "\ns1 before memset: " << s1 << "\n"; // using memset
	memset (s1, '-', 4);
	std::cout << "s1 after memset: " << s1 << "\n";
	std::cout << " " << std::endl;
	std::cout << "String greeting " << std::endl;
	std::cout << greetings << std::endl;
	numericValue = atoi(greetings); // using atoi
	longValue = atol(greet); // using atol
	std::cout << "integer numericValue is to string greeting" << std::endl;
	std::cout << numericValue << std::endl;
	std::cout << "String Greeting" << std::endl;
	std::cout << greet << std::endl;
	std::cout << "Long value of string greet: " << std::endl;
	std::cout << longValue << std::endl;
	
	
	system("pause");
	return 0;
}
