// Pattern Matching : Brute Force Algorithm

#include<iostream>

using namespace std;

void match(char*, char*);

void match(char* tmpstr, char *tmppatt){

	char *s, *p;
	bool found = false;

	while(*tmpstr != '\0'){

		s = tmpstr;
		p = tmppatt;

		while(*s != '\0'){

			if(*p == *s){

				p++;
				s++;

			}

			else
				break;

		}


			if(*p == '\0')
				found = true;

		tmpstr++;

	}

	if(found)
		cout << "\nPattern found\n";
	else
		cout << "\nPattern not found\n";

}

void display(char* str){

	cout << endl;
	while(*str != '\0'){

		cout << *str;
		str++;

	}

	cout << endl;

}

int main(){

	char str[100] = "We are trying to match a pattern";
	char patt[] = "We are";

	cout << "\nGiven string is :\n";
	display(str);
	cout << "\nPattern to be checked :\n";
	display(patt);
	match(str, patt);

}
