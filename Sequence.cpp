#include<iostream>
#include<iomanip>
#include<ctime>
#include <cstdlib> // for clearing screen
#include<conio.h> //for getch();
#include<windows.h> // for colors

using namespace std;

void initializeDeck();
void shuffleDeck(int deck[]);
void dealCards(int deck[]);
void initializeBoard(int deck[], int player1hand[], int player2hand[], int sizedeck);
void playturn(int board[][10], int deck[], int player1hand[], int player2hand[], int sizedeck);
void PrintCardsBoard(int board[][10]);
void PrintPlayerHand(int player1hand[]);
void PrintBoard(int board[][10], int player1hand[], int player2hand[], int currentplayer);
void clearScreen();							//For clearing Screen
bool check_Win(int board[][10], int currentplayer);
// Color codes
const int BLACK = 0;
const int BLUE = 1;
const int GREEN = 2;
const int CYAN = 3;
const int RED = 4;
const int MAGENTA = 5;
const int YELLOW = 6;
const int WHITE = 7;
// Function to set console text and background color
void setColor(int textColor, int bgColor)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}
int main()
{
	SetConsoleOutputCP(CP_UTF8);         		     //"Clubs♣   ";
	SetConsoleCP(CP_UTF8);							//"Spades♠  ";					
	//"Hearts♥  ";
	initializeDeck();							  //"Diamonds♦";
	cout << "    " << endl;

}
void initializeDeck()
{
	int deck[104];
	for (int i = 0; i < 13; i++)
	{											       // GIVING THE 8*13 CARDS THERE BASIC CARD TYPES
		deck[i] = i + 102;							  // 1. FOR SPADES   2.FOR CLUBS   3.FOR HEARTS    4.FOR DIAMONDS
		deck[i + 13] = i + 102;						     // 1. FOR SPADES   2.FOR CLUBS   3.FOR HEARTS    4.FOR DIAMONDS
		deck[i + 26] = i + 202;				       	    // GIVING THE VALUES FOR TWO CARDS IN A SAME COLOR
		deck[i + 39] = i + 202;				       	   // GIVING THE VALUES FOR TWO CARDS IN A SAME COLOR
		deck[i + 52] = i + 302;						  // GIVING THE VALUES FOR TWO CARDS IN A SAME COLOR
		deck[i + 65] = i + 302;						 // GIVING THE VALUES FOR TWO CARDS IN A SAME COLOR
		deck[i + 78] = i + 402;					    // GIVING THE VALUES FOR TWO CARDS IN A SAME COLOR	
		deck[i + 91] = i + 402;					   // GIVING THE VALUES FOR TWO CARDS IN A SAME COLOR	
	}
	deck[12] = 115;							 //ONE-EYED JACK'S ARE 15
	deck[38] = 215;
	deck[64] = 315;
	deck[90] = 415;
	shuffleDeck(deck);
}
void shuffleDeck(int deck[])
{
	srand(time(0));
	int ran1;
	for (int i = 0; i < 104; i++)
	{
		ran1 = rand() % 104;
		int temp = deck[i];
		deck[i] = deck[ran1];        // SORTING AND SHIFTING A RANDOM ELEMENT WITH 0TH THEN ,1ST THEN 2ND VICEVERSA
		deck[ran1] = temp;
	}
	cout << endl;
	dealCards(deck);
}
void dealCards(int deck[])
{
	int player1hand[7];        				  // A PLAYER CAN HAVE AT ANY TIME A MAXIMUM OF 106 CARDS
	int player2hand[7];    				     // BECAUSE 1 IS THE TOPCARD AND MINIMUM CARDS PLAYER 2 CAN HAVE MINIMUM OF 1
	int sizedeck = 0;
	for (int i = 0; i < 7; i++)
	{
		player1hand[i] = deck[i];             // GIVING 7 CARDS FROM THE SHUFFLED DECK
		deck[i] = 0;						  //KEEPING NOTICE OF CARDS IN PLAYERS HAND
		sizedeck++;							 // ALSO IN TOTAL DECK
	}
	for (int i = 7; i < 14; i++)
	{
		player2hand[i - 7] = deck[i];
		deck[i] = 0;                            // SSAME FOR PLAYER 2
		sizedeck++;
	}
	initializeBoard(deck, player1hand, player2hand, sizedeck);
}
void initializeBoard(int deck[], int player1hand[], int player2hand[], int sizedeck)
{
	int board[10][10];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if ((i == 0 && (j == 0 || j == 9)) || (i == 9 && (j == 0 || j == 9)))
			{
				board[i][j] = 9000;
			}
			else if (i == 0)
			{
				board[i][j] = j + 101;
			}
			else if (j == 9 && i < 5)
			{
				board[i][j] = i + j + 100;
			}
			else if (i == 1 && j < 5)
			{
				board[i][j] = 6 - j + 200;
			}
			else if (i == 1 && j > 4 && j < 9)
			{
				board[i][j] = 18 - j + 300;
			}
			else if (j == 0 && i < 9 && i>1)
			{
				board[i][j] = i + 205;
			}
			else if (j == 1 && i < 9 && i>1)
			{
				board[i][j] = 15 - i + 100;
			}
			else if (i == 8 && j < 7 && j>1)
			{
				board[i][j] = 8 - j + 100;
			}
			else if (i == 9 && j < 9 && j>0)
			{
				board[i][j] = 14 - j + 400;
			}
			else if (j == 9 && i < 9 && i>4)
			{
				board[i][j] = i - 3 + 400;
			}
			else if (j == 8 && i < 9 && i>1)
			{
				board[i][j] = 11 - i + 300;
			}
			else if (i == 2 && j < 8 && j>1)
			{
				board[i][j] = j + 400;
			}
			else if (j == 7 && i < 8 && i>2)
			{
				board[i][j] = i + 405;
			}
			else if (j == 7 && i == 8)
			{
				board[i][j] = 302;
			}
			else if (j == 6 && i == 7)
			{
				board[i][j] = 413;
			}
			else if (i == 3 && j < 7 && j>1)
			{
				board[i][j] = 8 - j + 200;
			}
			else if (j == 2 && i < 8 && i>3)
			{
				board[i][j] = i + 203;
			}
			else if (i == 7 && j < 6 && j>2)
			{
				board[i][j] = j + 208;
			}
			else if (j == 6 && i < 7 && i>3)
			{
				board[i][j] = 17 - i + 300;
			}
			else if (j == 3 && i < 7 && i>3)
			{
				board[i][j] = i + 302;
			}
			else if (i == 6 && j < 6 && j>3)
			{
				board[i][j] = j + 305;
			}
			else if (i == 4 && j < 6 && j>3)
			{
				board[i][j] = 9 - j + 300;
			}
			else if (i == 5 && j < 6 && j>3)
			{
				board[i][j] = j - 2 + 300;
			}
		}
	}
	playturn(board, deck, player1hand, player2hand, sizedeck);

}
void playturn(int board[][10], int deck[], int player1hand[], int player2hand[], int sizedeck)
{
	int currentplayer = 1, playerCard, move;
	for (int loop = 0; true; loop++)
	{
		cout << "\n  current player: " << currentplayer << endl;
		int player1Turns = 0, player2Turns = 0;
		int choice2, choice_Number2;
		PrintBoard(board, player1hand, player2hand, currentplayer);
		while (true)
		{
			cout << "\nEnter your card number according to your hand like 1,2,3,4,5,6,7 : ";
			cin >> move;
			move -= 1;
			choice2 = 900;
			char choice_2;
			while (choice2 > 11 || choice2 < 0 || choice_Number2>11 || choice_Number2 < 0)
			{
				cout << "\nWHICH BOX DO YOU WANT TO MOVE TO: ";
				cin >> choice_2;
				cin >> choice_Number2;
				choice2 = static_cast<int>(choice_2) - 65;
			}
			choice_Number2 -= 1;
			if (currentplayer == 1)
			{
				playerCard = player1hand[move];
				int type = playerCard % 100;
				int player = board[choice_Number2][choice2] / 1000;
				if (playerCard == board[choice_Number2][choice2] || type == 14)
				{
					player1hand[move] = deck[sizedeck++];
					board[choice_Number2][choice2] += 1000;
					break;
				}
				else if (type == 15 && player == 2)
				{
					player1hand[move] = deck[sizedeck++];
					board[choice_Number2][choice2] -= 1000;
					break;
				}
			}
			else
			{
				playerCard = player2hand[move];
				int type = playerCard % 100;
				int player = board[choice_Number2][choice2] / 1000;
				if (playerCard == board[choice_Number2][choice2] || type == 14)
				{
					player2hand[move] = deck[sizedeck++];
					board[choice_Number2][choice2] += 2000;
					break;
				}
				else if (type == 15 && player == 1)
				{
					player2hand[move] = deck[sizedeck++];
					board[choice_Number2][choice2] += 1000;
					break;
				}
			}
			cout << "\nwrong card enter again";
		}
		if (sizedeck == 108)
		{
			cout << "\nTHE DECK IS EMPTY";
			cout << "\nNo one wins";

			goto endd;
		}
		if (check_Win(board, currentplayer))
		{
			clearScreen();
			PrintBoard(board, player1hand, player2hand, currentplayer);
			cout << "\nPLAYER " << currentplayer << " WINS";
			endd:
			break;
		}
		if (currentplayer == 1) { currentplayer = 2; }            // CHANGES PLAYER 
		else if (currentplayer == 2) { currentplayer = 1; }       // KEEPS COUNT OF PLAYER TURNS
		clearScreen();
	}
}
void PrintBoard(int board[][10], int player1hand[], int player2hand[], int currentplayer)
{
	clearScreen();
	cout << "Are you ready player " << currentplayer << endl;
	_getch();
	clearScreen();
	cout << "Are you sure player " << currentplayer << endl;
	_getch();
	clearScreen();
	cout << "  CURRENT BOARD: \n";
	PrintCardsBoard(board);
	if (currentplayer == 1)
	{
		cout << "Player 1's Hand: \n";
		PrintPlayerHand(player1hand);
	}
	else
	{
		cout << "Player 2's Hand: \n";
		PrintPlayerHand(player2hand);
	}

}
void PrintCardsBoard(int board[][10])
{
	for (int i = 0; i < 10; i++)
	{
		cout << "   ";
		for (int j = 0; j < 10; j++)
		{
			int color = (board[i][j] / 100) % 10;
			int type = (board[i][j] % 100);
			if (color == 3 || color == 4)
			{
				setColor(RED, WHITE);
			}
			else
			{
				setColor(BLACK, WHITE);
			}
			if (type == 10)
			{
				cout << "10  ";
				if (color == 1)
				{
					cout << "♠";
				}
				else if (color == 2)
				{
					cout << "♣";
				}
				else if (color == 3)
				{
					cout << "♥";
				}
				else if (color == 4)
				{
					cout << "♦";
				}
				cout << "    ";
			}
			else if (type == 0)
			{
				cout << "☺☺☺☺☺☺☺☺☺";
			}
			else if (type == 11)
			{
				cout << "Q";
			}
			else if (type == 12)
			{
				cout << "K";
			}
			else if (type == 13)
			{
				cout << "A";
			}
			else
			{
				cout << setw(2) << type << "       ";
			}
			if (type == 11 || type == 12 || type == 13)
			{
				if (color == 1)
				{
					cout << "♠";
				}
				else if (color == 2)
				{
					cout << "♣";
				}
				else if (color == 3)
				{
					cout << "♥";
				}
				else if (color == 4)
				{
					cout << "♦";
				}
				cout << "       ";
			}
			setColor(BLACK, BLACK);
			cout << "1";

		}
		cout << endl;
		cout << "   ";
		for (int j = 0; j < 10; j++)
		{
			int player = board[i][j] / 1000;
			int color = board[i][j] / 100;
			int type = (board[i][j] % 100);
			if (color == 3 || color == 4)
			{
				setColor(RED, WHITE);
			}
			else
			{
				setColor(BLACK, WHITE);
			}
			if (player == 1)
			{
				setColor(BLUE, BLUE);
				cout << "111111111";
			}
			else if (player == 2)
			{
				setColor(GREEN, GREEN);
				cout << "111111111";
			}
			else if (type == 13)
			{
				cout << "         ";
			}
			else if (type == 0)
			{
				cout << "☺       ☺";
			}
			else if (type == 2 || type == 3)
			{
				cout << "    ";
				if (color == 1)
				{
					cout << "♠";
				}
				else if (color == 2)
				{
					cout << "♣";
				}
				else if (color == 3)
				{
					cout << "♥";
				}
				else if (color == 4)
				{
					cout << "♦";
				}
				cout << "    ";
			}
			else if (type == 4 || type == 5 || type == 6 || type == 7 || type == 8)
			{
				cout << "  ";
				if (color == 1)
				{
					cout << "♠   ♠";
				}
				else if (color == 2)
				{
					cout << "♣   ♣";
				}
				else if (color == 3)
				{
					cout << "♥   ♥";
				}
				else if (color == 4)
				{
					cout << "♦   ♦";
				}
				cout << "  ";
			}
			else if (type == 9 || type == 10)
			{
				cout << "  ";
				if (color == 1)
				{
					cout << "♠ ♠ ♠";
				}
				else if (color == 2)
				{
					cout << "♣ ♣ ♣";
				}
				else if (color == 3)
				{
					cout << "♥ ♥ ♥";
				}
				else if (color == 4)
				{
					cout << "♦ ♦ ♦";
				}
				cout << "  ";
			}
			else if (type == 11)
			{
				cout << "QUEEN    ";
			}
			else if (type == 12)
			{
				cout << "KING     ";
			}
			else if (color == 4)
			{
				cout << "         ";
			}
			setColor(BLACK, BLACK);
			cout << "1";

		}
		cout << endl;
		setColor(WHITE, BLACK);
		cout << setw(2) << i + 1 << " ";
		for (int j = 0; j < 10; j++)
		{
			int player = board[i][j] / 1000;
			int color = board[i][j] / 100;
			int type = (board[i][j] % 100);
			if (color == 3 || color == 4)
			{
				setColor(RED, WHITE);
			}
			else
			{
				setColor(BLACK, WHITE);
			}
			if (player == 1)
			{
				setColor(BLUE, BLUE);
				cout << "111111111";
			}
			else if (player == 2)
			{
				setColor(GREEN, GREEN);
				cout << "111111111";
			}
			else if (type == 0)
			{
				cout << "☺   ☺   ☺";
			}
			else if (type == 2 || type == 4)
			{
				cout << "         ";
			}
			else if (type == 13 || type == 3 || type == 5)
			{
				cout << "    ";
				if (color == 1)
				{
					cout << "♠";
				}
				else if (color == 2)
				{
					cout << "♣";
				}
				else if (color == 3)
				{
					cout << "♥";
				}
				else if (color == 4)
				{
					cout << "♦";
				}
				cout << "    ";
			}
			else if (type == 6)
			{
				cout << "  ";
				if (color == 1)
				{
					cout << "♠   ♠";
				}
				else if (color == 2)
				{
					cout << "♣   ♣";
				}
				else if (color == 3)
				{
					cout << "♥   ♥";
				}
				else if (color == 4)
				{
					cout << "♦   ♦";
				}
				cout << "  ";
			}
			else if (type == 7 || type == 8 || type == 9 || type == 10)
			{
				cout << "  ";
				if (color == 1)
				{
					cout << "♠ ♠ ♠";
				}
				else if (color == 2)
				{
					cout << "♣ ♣ ♣";
				}
				else if (color == 3)
				{
					cout << "♥ ♥ ♥";
				}
				else if (color == 4)
				{
					cout << "♦ ♦ ♦";
				}
				cout << "  ";
			}
			else if (type == 11 || type == 12)
			{
				cout << "    OF   ";
			}
			else
			{
				cout << "         ";
			}
			setColor(BLACK, BLACK);
			cout << "1";

		}
		cout << endl;
		cout << "   ";
		for (int j = 0; j < 10; j++)
		{
			int player = board[i][j] / 1000;
			int color = board[i][j] / 100;
			int type = (board[i][j] % 100);
			if (color == 3 || color == 4)
			{
				setColor(RED, WHITE);
			}
			else
			{
				setColor(BLACK, WHITE);
			}
			if (player == 1)
			{
				setColor(BLUE, BLUE);
				cout << "111111111";
			}
			else if (player == 2)
			{
				setColor(GREEN, GREEN);
				cout << "111111111";
			}
			else if (type == 0)
			{
				cout << "☺       ☺";
			}
			else if (type == 2 || type == 3)
			{
				cout << "    ";
				if (color == 1)
				{
					cout << "♠";
				}
				else if (color == 2)
				{
					cout << "♣";
				}
				else if (color == 3)
				{
					cout << "♥";
				}
				else if (color == 4)
				{
					cout << "♦";
				}
				cout << "    ";
			}
			else if (type == 4 || type == 5 || type == 6 || type == 7)
			{
				cout << "  ";
				if (color == 1)
				{
					cout << "♠   ♠";
				}
				else if (color == 2)
				{
					cout << "♣   ♣";
				}
				else if (color == 3)
				{
					cout << "♥   ♥";
				}
				else if (color == 4)
				{
					cout << "♦   ♦";
				}
				cout << "  ";
			}
			else if (type == 8 || type == 9 || type == 10)
			{
				cout << "  ";
				if (color == 1)
				{
					cout << "♠ ♠ ♠";
				}
				else if (color == 2)
				{
					cout << "♣ ♣ ♣";
				}
				else if (color == 3)
				{
					cout << "♥ ♥ ♥";
				}
				else if (color == 4)
				{
					cout << "♦ ♦ ♦";
				}
				cout << "  ";
			}
			else if (type == 11 || type == 12)
			{
				if (color == 1)
				{
					cout << "Spades♠  ";
				}
				else if (color == 2)
				{
					cout << "Clubs♣   ";
				}
				else if (color == 3)
				{
					cout << "Hearts♥  ";
				}
				else if (color == 4)
				{
					cout << "Diamonds♦";
				}
			}
			else
			{
				cout << "         ";
			}
			setColor(BLACK, BLACK);
			cout << "1";

		}
		cout << endl;
		cout << "   ";
		for (int j = 0; j < 10; j++)
		{
			int player = board[i][j] / 1000;
			int color = board[i][j] / 100;
			int type = (board[i][j] % 100);
			if (color == 3 || color == 4)
			{
				setColor(RED, WHITE);
			}
			else
			{
				setColor(BLACK, WHITE);
			}
			if (player == 1)
			{
				setColor(BLUE, BLUE);
				cout << "111111111";
			}
			else if (player == 2)
			{
				setColor(GREEN, GREEN);
				cout << "111111111";
			}
			else if (type == 0)
			{
				cout << "☺☺☺☺☺☺☺☺☺";
			}
			else if (type == 11 || type == 12 || type == 13)
			{
				cout << "       ";
				if (color == 1)
				{
					cout << "♠";
				}
				else if (color == 2)
				{
					cout << "♣";
				}
				else if (color == 3)
				{
					cout << "♥";
				}
				else if (color == 4)
				{
					cout << "♦";
				}
			}
			if (player == 0)
			{
				if (type == 11)
				{
					cout << "Q";
				}
				else if (type == 12)
				{
					cout << "K";
				}
				else if (type == 13)
				{
					cout << "A";
				}
				else if (type == 14 || type == 15)
				{
					cout << "J";
				}
				else if (type == 0 || player != 0)
				{
				}
				else
				{
					cout << "       " << setw(2) << type;
				}
			}
			setColor(BLACK, BLACK);
			cout << "1";

		}
		cout << endl << endl;
	}
	setColor(WHITE, BLACK);
	cout << "   ";
	for (int i = 65; i < 75; i++)      // SHOWS THE CARD NUMBER TO MAKE IT EASY AND CONVIENIENT
	{
		cout << "    " << static_cast<char>(i) << "     ";
	}
	cout << " " << endl;
}
void PrintPlayerHand(int player1hand[])
{
	for (int j = 0; j < 7; j++)
	{
		int color = player1hand[j] / 100;
		int type = (player1hand[j] % 100);
		if (color == 3 || color == 4)
		{
			setColor(RED, WHITE);
		}
		else
		{
			setColor(BLACK, WHITE);
		}
		if (type == 10)
		{
			cout << "10  ";
			if (color == 1)
			{
				cout << "♠";
			}
			else if (color == 2)
			{
				cout << "♣";
			}
			else if (color == 3)
			{
				cout << "♥";
			}
			else
			{
				cout << "♦";
			}
			cout << "    ";
		}
		else if (type == 0)
		{
			cout << "☺☺☺☺☺☺☺☺☺";
		}
		else if (type == 11)
		{
			cout << "Q";
		}
		else if (type == 12)
		{
			cout << "K";
		}
		else if (type == 13)
		{
			cout << "A";
		}
		else if (type == 14 || type == 15)
		{
			cout << "J";
		}
		else
		{
			cout << setw(2) << type << "       ";
		}
		if (type == 11 || type == 12 || type == 13 || type == 14 || type == 15)
		{
			if (color == 1)
			{
				cout << "♠";
			}
			else if (color == 2)
			{
				cout << "♣";
			}
			else if (color == 3)
			{
				cout << "♥";
			}
			else
			{
				cout << "♦";
			}
			cout << "       ";
		}
		setColor(BLACK, BLACK);
		cout << "1";
	}
	cout << endl;
	for (int j = 0; j < 7; j++)
	{
		int color = player1hand[j] / 100;
		int type = (player1hand[j] % 100);
		if (color == 3 || color == 4)
		{
			setColor(RED, WHITE);
		}
		else
		{
			setColor(BLACK, WHITE);
		}
		if (type == 0)
		{
			cout << "☺       ☺";
		}
		else if (type == 2 || type == 3)
		{
			cout << "    ";
			if (color == 1)
			{
				cout << "♠";
			}
			else if (color == 2)
			{
				cout << "♣";
			}
			else if (color == 3)
			{
				cout << "♥";
			}
			else
			{
				cout << "♦";
			}
			cout << "    ";
		}
		else if (type == 4 || type == 5 || type == 6 || type == 7 || type == 8)
		{
			cout << "  ";
			if (color == 1)
			{
				cout << "♠   ♠";
			}
			else if (color == 2)
			{
				cout << "♣   ♣";
			}
			else if (color == 3)
			{
				cout << "♥   ♥";
			}
			else
			{
				cout << "♦   ♦";
			}
			cout << "  ";
		}
		else if (type == 9 || type == 10)
		{
			cout << "  ";
			if (color == 1)
			{
				cout << "♠ ♠ ♠";
			}
			else if (color == 2)
			{
				cout << "♣ ♣ ♣";
			}
			else if (color == 3)
			{
				cout << "♥ ♥ ♥";
			}
			else
			{
				cout << "♦ ♦ ♦";
			}
			cout << "  ";
		}
		else if (type == 11)
		{
			cout << "QUEEN    ";
		}
		else if (type == 12)
		{
			cout << "KING     ";
		}
		else if (type == 14)
		{
			cout << "TWO-EYED ";
		}
		else if (type == 15)
		{
			cout << "ONE-EYED ";
		}
		else
		{
			cout << "         ";
		}
		setColor(BLACK, BLACK);
		cout << "1";

	}
	cout << endl;
	for (int j = 0; j < 7; j++)
	{
		int color = player1hand[j] / 100;
		int type = (player1hand[j] % 100);
		if (color == 3 || color == 4)
		{
			setColor(RED, WHITE);
		}
		else
		{
			setColor(BLACK, WHITE);
		}
		if (type == 0)
		{
			cout << "☺   ☺   ☺";
		}
		else if (type == 2 || type == 4)
		{
			cout << "         ";
		}
		else if (type == 13 || type == 3 || type == 5)
		{
			cout << "    ";
			if (color == 1)
			{
				cout << "♠";
			}
			else if (color == 2)
			{
				cout << "♣";
			}
			else if (color == 3)
			{
				cout << "♥";
			}
			else
			{
				cout << "♦";
			}
			cout << "    ";
		}
		else if (type == 6)
		{
			cout << "  ";
			if (color == 1)
			{
				cout << "♠   ♠";
			}
			else if (color == 2)
			{
				cout << "♣   ♣";
			}
			else if (color == 3)
			{
				cout << "♥   ♥";
			}
			else
			{
				cout << "♦   ♦";
			}
			cout << "  ";
		}
		else if (type == 7 || type == 8 || type == 9 || type == 10)
		{
			cout << "  ";
			if (color == 1)
			{
				cout << "♠ ♠ ♠";
			}
			else if (color == 2)
			{
				cout << "♣ ♣ ♣";
			}
			else if (color == 3)
			{
				cout << "♥ ♥ ♥";
			}
			else
			{
				cout << "♦ ♦ ♦";
			}
			cout << "  ";
		}
		else if (type == 11 || type == 12)
		{
			cout << "    OF   ";
		}
		else if (type == 14 || type == 15)
		{
			cout << "JACK  OF ";
		}
		else
		{
			cout << "         ";
		}
		setColor(BLACK, BLACK);
		cout << "1";

	}
	cout << endl;
	for (int j = 0; j < 7; j++)
	{
		int color = player1hand[j] / 100;
		int type = (player1hand[j] % 100);
		if (color == 3 || color == 4)
		{
			setColor(RED, WHITE);
		}
		else
		{
			setColor(BLACK, WHITE);
		}
		if (type == 0)
		{
			cout << "☺       ☺";
		}
		else if (type == 2 || type == 3)
		{
			cout << "    ";
			if (color == 1)
			{
				cout << "♠";
			}
			else if (color == 2)
			{
				cout << "♣";
			}
			else if (color == 3)
			{
				cout << "♥";
			}
			else
			{
				cout << "♦";
			}
			cout << "    ";
		}
		else if (type == 4 || type == 5 || type == 6 || type == 7)
		{
			cout << "  ";
			if (color == 1)
			{
				cout << "♠   ♠";
			}
			else if (color == 2)
			{
				cout << "♣   ♣";
			}
			else if (color == 3)
			{
				cout << "♥   ♥";
			}
			else
			{
				cout << "♦   ♦";
			}
			cout << "  ";
		}
		else if (type == 8 || type == 9 || type == 10)
		{
			cout << "  ";
			if (color == 1)
			{
				cout << "♠ ♠ ♠";
			}
			else if (color == 2)
			{
				cout << "♣ ♣ ♣";
			}
			else if (color == 3)
			{
				cout << "♥ ♥ ♥";
			}
			else
			{
				cout << "♦ ♦ ♦";
			}
			cout << "  ";
		}
		else if (type == 11 || type == 12 || type == 14 || type == 15)
		{
			if (color == 1)
			{
				cout << "Spades♠  ";
			}
			else if (color == 2)
			{
				cout << "Clubs♣   ";
			}
			else if (color == 3)
			{
				cout << "Hearts♥  ";
			}
			else
			{
				cout << "Diamonds♦";
			}
		}
		else
		{
			cout << "         ";
		}
		setColor(BLACK, BLACK);
		cout << "1";

	}
	cout << endl;
	for (int j = 0; j < 7; j++)
	{
		int color = player1hand[j] / 100;
		int type = (player1hand[j] % 100);
		if (color == 3 || color == 4)
		{
			setColor(RED, WHITE);
		}
		else
		{
			setColor(BLACK, WHITE);
		}
		if (type == 0)
		{
			cout << "☺☺☺☺☺☺☺☺☺";
		}
		else if (type == 11 || type == 12 || type == 13 || type == 14 || type == 15)
		{
			cout << "       ";
			if (color == 1)
			{
				cout << "♠";
			}
			else if (color == 2)
			{
				cout << "♣";
			}
			else if (color == 3)
			{
				cout << "♥";
			}
			else
			{
				cout << "♦";
			}
		}
		if (type == 11)
		{
			cout << "Q";
		}
		else if (type == 12)
		{
			cout << "K";
		}
		else if (type == 13)
		{
			cout << "A";
		}
		else if (type == 14 || type == 15)
		{
			cout << "J";
		}
		else if (type == 0)
		{
		}
		else
		{
			cout << "       " << setw(2) << type;
		}
		setColor(BLACK, BLACK);
		cout << "1";

	}
	setColor(WHITE, BLACK);
	cout << "";
	cout << endl;
	for (int i = 0; i < 7; i++)      // SHOWS THE CARD NUMBER TO MAKE IT EASY AND CONVIENIENT
	{
		cout << "    " << i + 1 << "     ";
	}
	cout << endl;

}
bool check_Win(int board[][10], int currentplayer)
{
	bool win = false;

	for (int i = 0; i < 10; i++)
	{
		if (win) break;

		for (int j = 0; j < 10; j++) {
			if (board[i][j] / 1000 == currentplayer || board[i][j] / 1000 == 9) {
				if (j <= 5) {
					if (board[i][j + 1] / 1000 == currentplayer &&
						board[i][j + 2] / 1000 == currentplayer &&
						board[i][j + 3] / 1000 == currentplayer &&
						(board[i][j + 4] / 1000 == currentplayer || board[i][j + 4] / 1000 == 9)) {
						win = true;
						break;
					}
				}
				if (i <= 5) {
					if (board[i + 1][j] / 1000 == currentplayer &&
						board[i + 2][j] / 1000 == currentplayer &&
						board[i + 3][j] / 1000 == currentplayer &&
						(board[i + 4][j] / 1000 == currentplayer || board[i + 4][j] / 1000 == 9))
					{
						win = true;
						break;
					}
				}
				if (i <= 5 && j <= 5) {
					if (board[i + 1][j + 1] / 1000 == currentplayer &&
						board[i + 2][j + 2] / 1000 == currentplayer &&
						board[i + 3][j + 3] / 1000 == currentplayer &&
						(board[i + 4][j + 4] / 1000 == currentplayer || board[i + 4][j + 4] / 1000 == 9))
					{
						win = true;
						break;
					}
				}
				if (i <= 5 && j >= 4) {
					if (board[i + 1][j - 1] / 1000 == currentplayer &&
						board[i + 2][j - 2] / 1000 == currentplayer &&
						board[i + 3][j - 3] / 1000 == currentplayer &&
						(board[i + 4][j - 4] / 1000 == currentplayer || board[i + 4][j - 4] / 1000 == 9)) {
						win = true;
						break;
					}
				}
			}
		}
	}
	return win;
}
void clearScreen() {
	system("CLS"); //For Windows
}