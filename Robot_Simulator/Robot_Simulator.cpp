#include <iostream>
#include <string>
using namespace std;
string Fix_String(string input);
char Fix_Direction(char D);
void Coordinates(char Letter, char last_Direction,int *x, int *y);
char Direction(char Letter, char last_Direction);
int main(void)
{
	int i = 0, X_Point, Y_Point;
	string seq;
	char dir;
	cout << "Enter Robot's starting coordinates : " << endl;
	cout << "X = ";
	cin >> X_Point;
	cout << "Y = ";
	cin >> Y_Point;
	cout << "Enter Robot's starting direction (E , W , N , S ) : " ;
	cin >> dir;
	dir = Fix_Direction(dir);
	cout << "Movement Sequence You Are Allowed to enter : " << endl;
	cout << "L for Left" << endl;
	cout << "R for Right" << endl;
	cout << "A for Advance" << endl;
	cout << "Any other letter will be discarded" << endl;
	cout << "Please Enter Required Movement Sequence : ";
	cin >> seq;
	seq = Fix_String(seq);
	while (seq[i] != '\0')
	{
		Coordinates(seq[i], dir, &X_Point, &Y_Point);
		dir = Direction(seq[i], dir);
		cout << seq[i] << " ---> Your Robot Coordinates: { " << X_Point << " - " << Y_Point << " }  and your Robot is heading to: " << dir << " Direction" << endl;
		i++;
	}
	return 0;
}
string Fix_String(string input)
{
	int i = 0;
	string output;
	while (input[i] != '\0')
	{
		if (input[i] >= 'a' && input[i] <= 'z')
		{
			input[i] = input[i] - 32 ;
		}
		if (input[i] != 'R' && input[i] != 'L' && input[i] != 'A')
		{
			i++;
			continue;
		}
		output += input[i];
		i++;
	}
	output += '\0';
	return output;
}
char Fix_Direction(char D)
{
	if (D >= 'a' && D <= 'z')
	{
		D = D - 32;
	}
	while (D != 'N' && D != 'S' && D != 'E' && D != 'W' )
	{
		cout << endl<<"Enter a proper direction : ";
		cin >> D;
		D = Fix_Direction(D);
	}
	return D;
}
void Coordinates(char Letter , char last_Direction,int *x,int *y)
{
	if (Letter == 'A')
	{
		if (last_Direction == 'N')
		{
			*y = *y + 1;
		}
		else if (last_Direction == 'S')
		{
			*y= *y - 1;
		}
		else if (last_Direction == 'E')
		{
			*x = *x + 1;
		}
		else if (last_Direction == 'W')
		{
			*x = *x - 1;
		}
	}
}
/*char Direction(char Letter, char last_Direction)
{
	char direction;
	if (Letter == 'R')
	{
		if (last_Direction == 'E')
		{
			direction = 'S';
		}
		else if (last_Direction == 'W')
		{
			direction = 'N';
		}
		else if (last_Direction == 'N')
		{
			direction = 'E';
		}
		else if (last_Direction == 'S')
		{
			direction = 'W';
		}
	}
	else if (Letter == 'L')
	{
		if (last_Direction == 'E')
		{
			direction = 'N';
		}
		else if (last_Direction == 'W')
		{
			direction = 'S';
		}
		else if (last_Direction == 'N')
		{
			direction = 'W';
		}
		else if (last_Direction == 'S')
		{
			direction = 'E';
		}
	}
	else if (Letter == 'A')
	{
		direction = last_Direction;
	}
	return direction;
}*/
char Direction(char Letter, char last_Direction)
{
	int i;
	char directions[4] = { 'E', 'S' , 'W', 'N' };
	for (int j = 0; j < 4; j++)
	{
		if (last_Direction == directions[j])
		{
			i = j;
			break;
		}
	}
	if (Letter == 'R')
	{
		if (i == 3)
		{
			i = 0;
		}
		else {
			i++;
		}
	}
	else if (Letter == 'L')
	{
		if (i == 0)
		{
			i = 3;
		}
		else {
			i--;
		}
	}

	return directions[i];
}