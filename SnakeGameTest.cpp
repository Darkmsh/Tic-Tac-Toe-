// SnakeGameTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
using namespace std;

#include <iostream>
#include <string>

string space[3][3] = { { "1","2","3"}, { "4","5","6" }, { "7","8","9" } };
int spaceValue[3][3] = { {-1,-1,-1}, {-1,-1,-1 }, { -1,-1,-1 } };
bool playerTurn = true;
bool game = true;

void logic(int);
void winner(int);
void computer(int);
void resault(int);

//It draws the place of game
void draw()
{
	cout << "         |          |         " << endl;
	cout << "    " << space[0][0] << "    |" << "    " << space[0][1] << "     |" << "    " << space[0][2] << "    " << endl;
	cout << "_________|__________|_________" << endl;
	cout << "         |          |         " << endl;
	cout << "    " << space[1][0] << "    |" << "    " << space[1][1] << "     |" << "    " << space[1][2] << "    " << endl;
	cout << "_________|__________|_________" << endl;
	cout << "         |          |         " << endl;
	cout << "    " << space[2][0] << "    |" << "    " << space[2][1] << "     |" << "    " << space[2][2] << "    " << endl;
	cout << "         |          |         " << endl;

}
//This check player input
int player()
{
	bool check = true;
	string input;
	do
	{
		cout << "players turn";
		cin >> input;
		if (input == "1" || input == "2" || input == "3" || input == "4" || input == "5" || input == "6" || input == "7" || input == "8" || input == "9")
		{
			check = false;
		}
	} while (check);
	int out = stoi(input);
	return(out);
}

int Round = 0;
//Change turn of player to ai and ai to player
void switchPlayer()
{
	int i = 0;
	while (game)
	{

		if (playerTurn)
		{
			int playerInput = player();
			logic(playerInput);
			playerTurn = false;
		}
		else
		{
			playerTurn = true;
			cout << "it's computers turn" << endl;
			computer(Round);
		}
		if (i > 9)
		{
			break;
		}
		draw();
		i++;
		Round++;
		winner(Round);
	}
}
//logic is for writing X for player
void logic(int inputNum)
{
	switch (inputNum)
	{
	case 1:space[0][0] = "X";
		spaceValue[0][0] = 1;
		break;
	case 2:space[0][1] = "X";
		spaceValue[0][1] = 1;
		break;
	case 3:space[0][2] = "X";
		spaceValue[0][2] = 1;
		break;
	case 4:space[1][0] = "X";
		spaceValue[1][0] = 1;
		break;
	case 5:space[1][1] = "X";
		spaceValue[1][1] = 1;
		break;
	case 6:space[1][2] = "X";
		spaceValue[1][2] = 1;
		break;
	case 7:space[2][0] = "X";
		spaceValue[2][0] = 1;
		break;
	case 8:space[2][1] = "X";
		spaceValue[2][1] = 1;
		break;
	case 9:space[2][2] = "X";
		spaceValue[2][2] = 1;
		break;

	}
}
//Main
int main()
{
	draw();
	switchPlayer();
	return 0;

}


int win[2] = { -1,-1 };

// winner check how is the winner stiuations of winning
void winner(int round)
{

	if (round > 4)
	{
		if (spaceValue[0][0] != -1 && spaceValue[0][1] != -1 && spaceValue[0][2] != -1)
		{

			if (spaceValue[0][0] == 1 && spaceValue[0][1] == 1 && spaceValue[0][2] == 1)
			{
				win[0] = 1;
				win[1] = 1;

			}
			if (spaceValue[0][0] == 0 && spaceValue[0][1] == 0 && spaceValue[0][2] == 0)
			{
				win[0] = 1;
				win[1] = 0;
			}
		}
		if (spaceValue[1][0] != -1 && spaceValue[1][1] != -1 && spaceValue[1][2] != -1)
		{
			if (spaceValue[1][0] == 1 && spaceValue[1][1] == 1 && spaceValue[1][2] == 1)
			{
				win[0] = 1;
				win[1] = 1;
			}
			if (spaceValue[1][0] == 0 && spaceValue[1][1] == 0 && spaceValue[1][2] == 0)
			{
				win[0] = 1;
				win[1] = 0;
			}
		}
		if (spaceValue[2][0] != -1 && spaceValue[2][1] != -1 && spaceValue[2][2] != -1)
		{
			if (spaceValue[2][0] == 1 && spaceValue[2][1] == 1 && spaceValue[2][2] == 1)
			{
				win[0] = 1;
				win[1] = 1;
			}
			if (spaceValue[2][0] == 0 && spaceValue[2][1] == 0 && spaceValue[2][2] == 0)
			{
				win[0] = 1;
				win[1] = 0;
			}
		}
		//////////////////
		if (spaceValue[0][0] != -1 && spaceValue[1][0] != -1 && spaceValue[2][0] != -1)
		{
			if (spaceValue[0][0] == 1 && spaceValue[1][0] == 1 && spaceValue[2][0] == 1)
			{
				win[0] = 1;
				win[1] = 1;
			}
			if (spaceValue[0][0] == 0 && spaceValue[1][0] == 0 && spaceValue[2][0] == 0)
			{
				win[0] = 1;
				win[1] = 0;
			}
		}

		if (spaceValue[0][1] != -1 && spaceValue[1][1] != -1 && spaceValue[2][1] != -1)
		{
			if (spaceValue[0][1] == 1 && spaceValue[1][1] == 1 && spaceValue[2][1] == 1)
			{
				win[0] = 1;
				win[1] = 1;
			}
			if (spaceValue[0][1] == 0 && spaceValue[1][1] == 0 && spaceValue[2][1] == 0)
			{
				win[0] = 1;
				win[1] = 0;
			}
		}

		if (spaceValue[0][2] != -1 && spaceValue[1][2] != -1 && spaceValue[2][2] != -1)
		{
			if (spaceValue[0][2] == 1 && spaceValue[1][2] == 1 && spaceValue[2][2] == 1)
			{
				win[0] = 1;
				win[1] = 1;
			}
			if (spaceValue[0][2] == 0 && spaceValue[1][2] == 0 && spaceValue[2][2] == 0)
			{
				win[0] = 1;
				win[1] = 0;
			}
		}
		/////////////////
		if (spaceValue[0][0] != -1 && spaceValue[1][1] != -1 && spaceValue[2][2] != -1)
		{
			if (spaceValue[0][0] == 1 && spaceValue[1][1] == 1 && spaceValue[2][2] == 1)
			{
				win[0] = 1;
				win[1] = 1;
			}
			if (spaceValue[0][0] == 0 && spaceValue[1][1] == 0 && spaceValue[2][2] == 0)
			{
				win[0] = 1;
				win[1] = 0;
			}
		}
		if (spaceValue[0][2] != -1 && spaceValue[1][1] != -1 && spaceValue[2][2] != -1)
		{
			if (spaceValue[0][2] == 1 && spaceValue[1][1] == 1 && spaceValue[2][0] == 1)
			{
				win[0] = 1;
				win[1] = 1;
			}
			if (spaceValue[0][2] == 0 && spaceValue[1][1] == 0 && spaceValue[2][0] == 0)
			{
				win[0] = 1;
				win[1] = 0;
			}
		}
		resault(round);
	}



}
//it shows the who is the winner
void resault(int round)
{
	if (win[0] == 1)
	{
		if (win[1] == 1)
		{
			cout << "player win" << endl;

		}
		else
		{
			cout << "Computer win";
		}
		game = false;
	}
	if (win[0] == -1 && round == 10)
	{
		cout << "Darw";
		game = false;

	}
}




bool notCenter = true;
int vhoIf[2] = { 0,0 };
int situation = 0;

//Ai 
void computer(int round)
{
	if (spaceValue[1][1] == -1)
	{
		space[1][1] = "O";
		spaceValue[1][1] = 0;
		notCenter = false;


	}
	else if (spaceValue[1][1] == 0)
	{
		if (round == 3)
		{

			if (spaceValue[0][0] == 1 && spaceValue[0][1] == 1)
			{
				spaceValue[0][2] = 0;
				space[0][2] = "O";
				situation = 0;
			}
			else if (spaceValue[0][0] == 1 && spaceValue[0][2] == 1)
			{
				spaceValue[0][1] = 0;
				space[0][1] = "O";
				situation = 9;
			}
			else if (spaceValue[0][0] == 1 && spaceValue[1][0] == 1)
			{
				spaceValue[2][0] = 0;
				space[2][0] = "O";
				situation = 2;
			}
			else if (spaceValue[0][0] == 1 && spaceValue[2][0] == 1)
			{
				spaceValue[1][0] = 0;
				space[1][0] = "O";
				situation = 1;
			}
			else if (spaceValue[1][0] == 1 && spaceValue[2][0] == 1 || spaceValue[0][1] == 1 && spaceValue[0][2] == 1)
			{
				spaceValue[0][0] = 0;
				space[0][0] = "O";
				situation = 3;
			}
			////////////
			else if (spaceValue[2][2] == 1 && spaceValue[0][2] == 1)
			{
				spaceValue[1][2] = 0;
				space[1][2] = "O";
				situation = 4;
			}
			else if (spaceValue[2][2] == 1 && spaceValue[1][2] == 1)
			{
				spaceValue[0][2] = 0;
				space[0][2] = "O";
				situation = 5;
			}
			else if (spaceValue[2][2] == 1 && spaceValue[2][0] == 1)
			{
				spaceValue[2][1] = 0;
				space[2][1] = "O";
				situation = 6;
			}
			else if (spaceValue[2][2] == 1 && spaceValue[2][1] == 1)
			{
				spaceValue[2][0] = 0;
				space[2][0] = "O";
				situation = 10;
			}
			else if (spaceValue[2][0] == 1 && spaceValue[2][1] == 1 || spaceValue[1][2] == 1 && spaceValue[0][2] == 1)
			{
				spaceValue[2][2] = 0;
				space[2][2] = "O";
				situation = 7;
			}
			else if (spaceValue[1][0] == 1 && spaceValue[0][1] == 1 || spaceValue[1][2] == 1 && spaceValue[2][1] || spaceValue[1][0] == 1 && spaceValue[2][1] || spaceValue[0][1] == 1 && spaceValue[1][2] == 1)
			{
				if (spaceValue[1][0] == 1 && spaceValue[0][1] == 1)
				{
					spaceValue[0][0] = 0;
					space[0][0] = "O";
					situation = 8;
				}
				if (spaceValue[1][2] == 1 && spaceValue[2][1])
				{
					spaceValue[2][2] = 0;
					space[2][2] = "O";
					situation = 11;
				}
				if (spaceValue[1][0] == 1 && spaceValue[2][1])
				{
					spaceValue[2][0] = 0;
					space[2][0] = "O";
					situation = 12;
				}
				else
				{
					spaceValue[0][2] = 0;
					space[0][2] = "O";
					situation = 13;
				}
			}
			else if (spaceValue[1][0] == 1 && spaceValue[1][2] == 1 || spaceValue[0][1] == 1 && spaceValue[2][1] == 1)
			{
				spaceValue[0][0] = 0;
				space[0][0] = "O";
				situation = 14;
			}
		}
		//in else ai win the game
		if (round == 5)
		{
			switch (situation)
			{
			case 0:
				if (spaceValue[2][0] == 1)
				{
					spaceValue[1][0] = 0;
					space[1][0] = "O";
					situation = 0;
				}
				else
				{
					spaceValue[2][0] = 0;
					space[2][0] = "O";
				}
				break;
			case 1:
				if (spaceValue[1][2] == 1)
				{
					spaceValue[0][1] = 0;
					space[0][1] = "O";
					situation = 1;
				}
				else
				{
					spaceValue[1][2] = 0;
					space[1][2] = "O";

				}
				break;
			case 2:
				if (spaceValue[0][2] == 1)
				{
					spaceValue[0][1] = 0;
					space[0][1] = "O";
					situation = 1;
				}
				else
				{
					spaceValue[0][2] = 0;
					space[0][2] = "O";
				}
			case 3:
				if (spaceValue[2][2] == 1)
				{
					if (spaceValue[0][2] == 1)
					{
						spaceValue[1][2] = 0;
						space[1][2] = "O";
						situation = 0;
					}
					else
					{
						spaceValue[2][1] = 0;
						space[2][1] = "O";
						situation = 2;
					}
				}
				else
				{
					spaceValue[2][2] = 0;
					space[2][2] = "O";
				}
				break;
			case 9:
				if (spaceValue[2][1] == 1)
				{
					spaceValue[1][2] = 0;
					space[1][2] = "O";
					situation = 3;
				}
				else
				{
					spaceValue[2][1] = 0;
					space[2][1] = "O";
				}
				break;
			case 4:
				if (spaceValue[1][0] == 1)
				{
					spaceValue[2][1] = 0;
					space[2][1] = "O";
					situation = 4;
				}
				else
				{
					spaceValue[1][0] = 0;
					space[1][0] = "O";
				}
				break;
			case 5:
				if (spaceValue[2][0] == 1)
				{
					spaceValue[2][1] = 0;
					space[2][1] = "O";
					situation = 4;
					
				}
				else
				{
					spaceValue[2][0] = 0;
					space[2][0] = "O";
				}
				break;
			case 6:
				if (spaceValue[0][1] == 1)
				{
					spaceValue[1][2] = 0;
					space[1][2] = "O";
					situation = 5;
				}
				else
				{
					spaceValue[0][1] = 0;
					space[0][1] = "O";
				}
				break;
			case 7:
				if (spaceValue[0][0] == 1)
				{
					if (spaceValue[2][0] == 1)
					{
						spaceValue[1][0] = 0;
						space[1][0] = "O";
					}
					else
					{
						spaceValue[0][1] = 0;
						space[0][1] = "O";
					}
				}
				else
				{
					spaceValue[0][0] = 0;
					space[0][0] = "O";
				}
				break;
			case 8:
				if (spaceValue[2][2] == 1)
				{
					spaceValue[2][0] = 0;
					space[2][0] = "O";
				}
				else
				{
					spaceValue[2][2] = 0;
					space[2][2] = "O";
				}
				break;
			case 10:
				if (spaceValue[0][2] == 1)
				{
					spaceValue[1][2] = 0;
					space[1][2] = "O";
				}
				else
				{
					spaceValue[0][2] = 0;
					space[0][2] = "O";
				}
				break;
			case 11:
				if (spaceValue[0][0] == 1)
				{
					spaceValue[0][2] = 0;
					space[0][2] = "O";
				}
				else
				{
					spaceValue[0][0] = 0;
					space[0][0] = "O";
				}
				break;
			case 12:
				if (spaceValue[0][2] == 1)
				{
					spaceValue[2][2] = 0;
					space[2][2] = "O";
				}
				else
				{
					spaceValue[0][2] = 0;
					space[0][2] = "O";
				}
				break;
			case 13:
				if (spaceValue[2][0] == 1)
				{
					spaceValue[2][2] = 0;
					space[2][2] = "O";
				}
				else
				{
					spaceValue[2][0] = 0;
					space[2][0] = "O";
				}
				break;
			case 14:
				if (spaceValue[2][2] == 1)
				{
					if (spaceValue[2][0] == 1)
					{
						spaceValue[0][2] = 0;
						space[0][2] = "O";
					}
					else
					{
						spaceValue[2][0] = 0;
						space[2][0] = "O";
					}
					//we will win
				}
				else
				{
					spaceValue[2][2] = 0;
					space[2][2] = "O";
				}
				break;
			}
			
		}
		//Round 4
		if (round == 7)
		{
			switch (situation)
			{
			case 0:
				if (spaceValue[1][2] == 1)
				{
					spaceValue[2][2] = 0;
					space[2][2] = "O";
				}
				else
				{
					spaceValue[2][0] = 0;
					space[2][0] = "O";
				}
				break;
			case 1:
				if (spaceValue[2][1] == 1)
				{
					spaceValue[2][2] = 0;
					space[2][2] = "O";
				}
				else
				{
					spaceValue[2][1] = 0;
					space[2][1] = "O";
				}
				break;
			case 2:
				if (spaceValue[0][1] == 1)
				{
					spaceValue[0][2] = 0;
					space[0][2] = "O";
				}
				else
				{
					spaceValue[0][1] = 0;
					space[0][1] = "O";
				}
				break;
			case 3:
				if (spaceValue[2][1] == 1)
				{
					spaceValue[2][0] = 0;
					space[2][0] = "O";
				}
				else
				{
					spaceValue[2][1] = 0;
					space[2][1] = "O";
				}
				break;
			case 4:
				if (spaceValue[0][1] == 1)
				{
					spaceValue[0][0] = 0;
					space[0][0] = "O";
				}
				else
				{
					spaceValue[0][1] = 0;
					space[0][1] = "O";
				}
				break;
			case 5:
				if (spaceValue[0][0] == 1)
				{
					spaceValue[0][2] = 0;
					space[0][2] = "O";
				}
				else
				{
					spaceValue[0][0] = 0;
					space[0][0] = "O";
				}
				break;
			}

		}
	}

	else {

		if (notCenter)
		{
			space[0][0] = "O";
			spaceValue[0][0] = 0;
			if (round == 2 || round == 3)
			{

			}
		}
		if (round == 2 || round == 3)
		{
			//vertical
			if (spaceValue[0][1] == 1 || spaceValue[2][1] == 1)
			{
				vhoIf[0] = 0;
				if (spaceValue[0][1] == 1)
				{
					spaceValue[2][1] = 0;
					space[2][1] = "O";
					vhoIf[1] = 0;
				}
				else {
					spaceValue[0][1] = 01;
					space[0][1] = "O";
					vhoIf[1] = 1;
				}
			}

			//horizantal
			else if (spaceValue[1][0] == 1 || spaceValue[1][2] == 1)
			{
				vhoIf[0] = 1;
				if (spaceValue[1][0] == 1)
				{
					spaceValue[1][2] = 0;
					space[1][2] = "O";
					vhoIf[1] = 0;
				}
				else {
					spaceValue[1][0] = 01;
					space[1][0] = "O";
					vhoIf[1] = 1;
				}
			}
			//oblique
			else if (spaceValue[0][2] == 1 || spaceValue[1][2] == 1 || spaceValue[2][2] == 1 || spaceValue[2][0] == 1)
			{
				vhoIf[0] = 2;
				if (spaceValue[0][2] == 1)
				{
					spaceValue[2][0] = 0;
					space[2][0] = "O";
					vhoIf[1] = 0;

				}
				else {
					spaceValue[0][2] = 0;
					space[0][2] = "O";
					vhoIf[1] = 1;

				}

			}
		}
		if (round == 4 || round == 5)
		{
			if (vhoIf[0] == 2 && vhoIf[1] == 0)
			{
				if (spaceValue[1][0] == 1)
				{
					spaceValue[1][2] = 0;
					space[1][2] = "O";

					vhoIf[0] = 1;
					vhoIf[1] = 0;
				}
				else
				{
					spaceValue[1][0] = 0;
					space[1][0] = "O";
				}
			}


			else if (vhoIf[0] == 2 && vhoIf[1] == 1)
			{
				if (spaceValue[0][1] == 1)
				{
					spaceValue[2][1] = 0;
					space[2][1] = "O";

					vhoIf[0] = 2;
					vhoIf[1] = 0;
				}
				else
				{
					spaceValue[0][1] = 0;
					space[0][1] = "O";
				}
			}
		}
		if (round == 6 || round == 7)
		{
			if (vhoIf[0] == 2 && vhoIf[1] == 0)
			{
				if (spaceValue[1][0] == 1)
				{
					spaceValue[1][2] = 0;
					space[1][2] = "O";
				}
				else
				{
					spaceValue[1][0] = 0;
					space[1][0] = "O";
				}
			}
			if (vhoIf[0] == 1 && vhoIf[1] == 0)
			{
				if (spaceValue[2][1] == 1)
				{
					spaceValue[0][1] = 0;
					space[0][1] = "O";
				}
				else
				{
					spaceValue[2][1] = 0;
					space[2][1] = "O";
				}
			}
		}
	}
}









