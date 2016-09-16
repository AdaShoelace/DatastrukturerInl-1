/*
 * Pierre Leidbring 08/09/16
 */
#include <iostream>
#include "Stack.h"
#include <string>

using std::string;

string parseString(const string& stringToParse);

/*
 * Testprogram för att mata in sträng och testa stack såväl som parsningen.
*/
int main()
{
    bool again = true;

    while(again)
    {
        std::cout << "Enter a string containing brackets" << std::endl;
        string stringWithBrackets;
        std::cin >> stringWithBrackets;
        std::cout << parseString(stringWithBrackets) << std::endl;
        std::cout << "Go again? " << "<y/n>" << std::endl;
        char answer;
        std::cin >> answer;

        if(answer == 'n')
        {
            again = false;
        }else if(answer != 'y' && answer != 'n')
        {
            std::cout << "Unrecognized character. Please enter 'y' for 'yes' and 'n' for 'no'...";
        }
    }

    return 0;
}

/*
 * Funktion som tar en sträng och parsar denna för att kontrollera strängen enligt de regler
 * som gavs i uppgiftsinstruktionen.
 */
string parseString(const string& stringToParse)
{
    Stack<char> stack = Stack<char>();
    
    for(size_t i = 0; i < stringToParse.length(); i++)
    {
        char toMatch = stringToParse.at(i);
        
        if(toMatch == '(' || toMatch == '[' || toMatch == '{')
        {
            stack.push(toMatch);
        }else if((toMatch == ')' && stack.peek() == '(') || (toMatch == ']' && stack.peek() == '[')
            || (toMatch == '}' && stack.peek() == '{'))
        {
            stack.pop();
        }else if((toMatch == ')' && stack.peek() != '(') || (toMatch == ']' && stack.peek() != '[')
            || (toMatch == '}' && stack.peek() != '{'))
        {
            return "Text to parse: " + stringToParse + "\n" + "Brackets do not match." + "\n" +
                     "Text parsed...";
        }
    }

    if(stack.getSize() != 0)
    {
        return "Text to parse: " + stringToParse + "\n" + "Bracket is missing" + "\n" + 
                "Text parsed...";
    }else if(stack.getSize() == 0)
    {
        return "Text to parse: " + stringToParse + "\n" + "Text parsed...";
    }
}
