

/*

	Madison Cuppett, Jose Huerta, Charlie Nguyen, Ryan Smith, Victor Lopez
	Project 2 Vectors 
	CS151 June Tu-Thu
	
	Algorithm: 
	
	START 
	
	Ask user for input
	Store expression given into a string
	Pass string into function
		Function parses string for characters, grouping numbers, operands, and paranthesis
		Use ascii codes to parse values 
		Push values on to vector
		Return values in vector to user in order and also in reverse order
	Display results
	
	END
*/

#include <string>
#include <iostream>
#include <vector>
using namespace std;

/* Prototypes */
vector<string> split(const string &expression);


int main()
{
	string expression;
	
	/*
	char something = 'c';
	string somethingelse = somethingelse.append(1, something);
	*/
	
	cout << "Enter expression: " << endl;
	cin >> expression;
	
	vector<string> splitted = split(expression);
	
	for(int i = 0; i < expression.size(); i++)
	{
		cout << expression[i] << endl;
	}
	
	string hold;
	cin >> hold;
	return 0;
}

vector<string> split(const string &expression)
{
	int counter = 0;
	int length = expression.size();
	vector<string> list;
	string temp;
	char current;
	char previous;
	
	
	for(int i = 0; i < length; i++)
	{
		current = expression.at(i);
		if(current >= '(' && current<= '/')
		{
			cout << "IF statement" <<endl;
			temp = temp.append(1, current);
			list.push_back(temp);		
			counter++;
			//previous = current;
			
		}
		
		else if(current >= '0' && current <= '9')
		{
			cout << "Else if" << endl;
			cout << "Previous: " << expression.at(i - 1) << endl;
				
				
			if(i > 0)
				{
					if(expression.at(i - 1) >= '0' && expression.at(i - 1) <= '9')
					{
					cout << "Appended to previous" << endl;
					list[i - 1] += current;				
					}
				}
				else
				{
					cout << "Did not append to previous" << endl;
					temp = temp.append(1, current);
					list.push_back(temp);		
				}
			}
			
			counter++;
			previous = current;
		}
		
		
		cout << endl << "Current Iteration: " << i + 1 << endl;
		cout << "Counter: " << counter << endl;
		 
		for(int x=0; x<list.size(); x++)
		{
			cout << "List[" << x << "] is " << list[x] << endl;
		}
		
	}
	
	return list;
	
}




