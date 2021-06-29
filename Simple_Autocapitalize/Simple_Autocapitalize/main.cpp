#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctype.h>
#include <vector>
#include <sstream>

using namespace std;

string AutoCapitalize(string inputString)
{
	int delimiter_counter = 0;
	char temp;
	string reconstituted_Input;
	bool afterDelimiterFlag = false;
	bool firstLetter = true;
	//bool already_capitalized = false;

	for (int i = 0; i <= inputString.length() - 1; i++) //iteriranje kroz input string
	{
		temp = inputString[i];	//trpamo slovo po slovo

		//SPACE JE ASCII 32, od točke je 46

		//ako već je veliko slovo
		if (!firstLetter)
		{
			if (temp >= 65 && temp <= 90)
			{
				reconstituted_Input += temp;
				afterDelimiterFlag = false;
			}
		}

		if (firstLetter == true)
		{
			temp = toupper(temp);
			reconstituted_Input += temp;
			firstLetter = false;
		}

		if (temp == 46)
		{
			afterDelimiterFlag = true;
		}


		if (temp > 96 && temp < 123) //provjera da li je unutar raspona malih slova ASCII-a
		{
			if (afterDelimiterFlag == true) // kapitaliziramo skolo tek ako je nakon točke
			{
				temp = toupper(temp);
				afterDelimiterFlag = false;
				reconstituted_Input += temp;

				//already_capitalized = true;
			}
			else
			{
				reconstituted_Input += temp; //ako nije unutar raspona ne znači da ne treba se unijeti, unesemo ga i dalje
			}

		}

		if (temp == 32) //ubaci space kad naiđes na space, jako jednostavno jer 32 = space u kontektstu chara
		{
			reconstituted_Input += " ";
		}

		//u slucaju da je vec veliko slovo
		//if (already_capitalized)
		//{
		//	if (temp >= 65 && temp <= 90)
		//	{
		//		reconstituted_Input += temp;
		//	}
		//	else
		//	{
		//		already_capitalized = false;
		//	}
		//}

		if (inputString[i + 1] == '.' /*&& inputString[i + 2] == ' '*/)
		{
			reconstituted_Input.append(".");
			//reconstituted_Input.append(" ");
		}

	}
	return reconstituted_Input;
}



int main()
{

	string input;
	cout << "unesi" << endl;
	getline(cin, input);

	cout << AutoCapitalize(input) << endl;

}
