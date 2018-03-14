#include <iostream>
#include <string>
#include <cstring>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	char s1[80]; //declaration
	char s2[80]; //declaration
	char strTemp[80];//declaration
	strcpy(s1, "something"); //initialization 
	strcpy(s2, "else"); //initialization 
	strcpy(strTemp, ""); //initialization 
	
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
	
	strcpy(s1, "f"); 
	strcpy(s2, "else");
	
	char *pch = strpbrk(s2, s1); //using strpbrk
	std::cout << "Checking if the letter f occurs in the word else (if nothing prints, it does not occur): " << "\n\n";
	while (pch != NULL) {
		std::cout << pch << "\n";
	}
	
	strcpy(s1, "this"); 
	strcpy(s2, " and that");
	
	strcat(strTemp, s1);
	strcat(strTemp, s2);
	
	std::cout << "Strcat demo: \n";
	puts(strTemp);
	
	std::cout << "\ns1 before memset: " << s1 << "\n";
	memset (s1, '-', 4);
	std::cout << "s1 after memset: " << s1 << "\n";
	
	
	system("pause");
	return 0;
}
