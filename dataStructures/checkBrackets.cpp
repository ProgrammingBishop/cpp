#include <iostream>
#include <stack>
#include <string>


struct Bracket 
{
	char opening;
	int  position;
	
	Bracket(char opening, int position) :
		opening(opening), position(position) {}

	bool matchChar(char closing) 
	{
		if (opening == '[' && closing == ']') { return true; }
		if (opening == '{' && closing == '}') { return true; }
		if (opening == '(' && closing == ')') { return true; }
		return false;
	}
};


/*
Utilize a stack to check if a string input contains matching brackets
	1) If closing doesn't match opening, output position in string where mismatch closing occurs
	2) If opening has no matching closing, output position in string where mismatch opening occurs
*/
int main()
{
	std::string text;
	getline(std::cin, text);
	std::stack <Bracket> opening_brackets_stack;

	char next;
	for (int position = 0; position < text.length(); position++)
	{
		next            = text[position];
		Bracket bracket = Bracket(next, position); 

		if (next == '(' || next == '[' || next == '{') 
		{
			opening_brackets_stack.push(bracket);
			continue;
		}

		if (next == ')' || next == ']' || next == '}')
		{
			if (!opening_brackets_stack.empty())
            		{
				Bracket top_of_stack = opening_brackets_stack.top();
				if (top_of_stack.matchChar(next))
                		{
                    			opening_brackets_stack.pop();
                		}
			}
			
			else
			{
				std::cout << (position + 1) << std::endl;
				system("pause");
				exit(0);
			}
		}
	}

	if (!opening_brackets_stack.empty())
	{
		Bracket remaining_bracket = opening_brackets_stack.top();
		std::cout << (remaining_bracket.position + 1) << std::endl;
	}
	else
    	{
        	std::cout << "Success" << std::endl;
   	}

	system("pause");
	return 0;
}
