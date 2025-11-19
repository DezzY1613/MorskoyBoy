#include <iostream>
#include <Windows.h>
using namespace std;

bool winRed = false, winBlue = false;
bool gotov = false;

int peredBlue;
char korablPl1, korablPl2;
char korablPl1T, korablPl2T;
int xPl1 = 1, xPl2 = 1;
int xPlT1 = 1, xPlT2 = 1;
int korablsPl1, korablsPl2;

bool popadanie;
int popadaniePl1, popadaniePl2;
int popitkaPl1, popitkaPl2;
int mimoPl1, mimoPl2;

void Welcome() {

	char welcome[]{ 'Э','т', 'о', ' ', 'М', 'о', 'р', 'с', 'к', 'о', 'й', ' ', 'б', 'о', 'й', '!', '\n', ' \t','b','y', ' ', 'd', 'e', 'z', 'z'};

	for (int i = 0; i <= 24; i++)
	{
		cout << welcome[i];
		Sleep(100);
	}
	Sleep(500);
}


bool Menu() {
	bool contin = false;
	char MenuVibor;

	while (!contin) {
		system("cls");
		cout << "1) Начать игру \n2) Правила \n3) Выйти \nВаш выбор: ";
		cin >> MenuVibor;



		switch (MenuVibor) {
		case '1':
			system("cls");
			contin = true;
			break;
		case '2':
			system("cls");
			cout << "Правила простые:\n";
			cout << "Игровое поле — обычно квадрат 10x10 у каждого игрока, на котором размещается флот кораблей. \nУ нас будут использоваться поле 5x5 \nГоризонтали обычно нумеруются сверху вниз, а вертикали помечаются буквами слева направо. \nПри этом используются буквы русского алфавита от «а» до «к» (буквы «ё» и «й» обычно пропускаются) \nлибо от «а» до «и» (с использованием буквы «ё»), либо буквы латинского алфавита от «a» до «j». \nИногда используется слово «республика» или «снегурочка», так как в этих 10-буквенных словах ни одна буква не повторяется\nПоскольку существуют различные варианты задания системы координат, то об этом лучше заранее договориться.";
			cout << endl << "\nОжидайте...";
			Sleep(15000);
			break;
		case '3':
			system("cls");
			cout << "До свидания!\n";
			return 0;
			break;
		default:
			system("cls");
			cout << "Ответ не принят! \nОжидайте...";
			Sleep(5000);
			break;
		}
		continue;
	}


}


int main() {
	setlocale(LC_ALL, "Ru");
	Welcome();
	Menu();

	//random
	srand(time(NULL));
	int random = rand() % 25;

	
	char player1[] = { '0','o', '-', '-', '-', '-',
						'-', '-', '-', '-', '-',
						'-', '-', '-', '-', '-',
						'-', '-', '-', '-', '-',
						'-', '-', '-', '-', '-',
	};
	char player2[] = { '0','o', '-', '-', '-', '-',
						'-', '-', '-', '-', '-',
						'-', '-', '-', '-', '-',
						'-', '-', '-', '-', '-',
						'-', '-', '-', '-', '-',
	};

	char player1T[] = { '0','x', '-', '-', '-', '-',
						'-', '-', '-', '-', '-',
						'-', '-', '-', '-', '-',
						'-', '-', '-', '-', '-',
						'-', '-', '-', '-', '-',
	};
	char player2T[] = { '0','x', '-', '-', '-', '-',
						'-', '-', '-', '-', '-',
						'-', '-', '-', '-', '-',
						'-', '-', '-', '-', '-',
						'-', '-', '-', '-', '-',
	};

	char namespac[] = {'0','1', '2', '3', '4', '5',
					'a','b', 'c', 'd', 'e', '\n'};

	//Первый игрок ставит корабли...
	while (korablsPl1 != 4) { // Первый игрок
			system("cls");
			cout << "Поставлено " << korablsPl1 << " из 4х";
			cout << endl << "  ";

			//------------------------------------------------- ИГРОК 1
			for (int i = 6; i <= 11; i++) //Буквы ирока 1
			{
				cout << "\x1b[36m";
				if (i != 11) { cout << namespac[i] << " "; }
				else { cout << namespac[i]; }
				cout << "\x1b[0m";
			}
			for (int i = 1; i <= 25; i++) // поле игрока1
			{
				cout << "\x1b[36m";
				switch (i) {
				case 1:
					cout << namespac[1] << " ";
					break;
				case 6:
					cout << endl << namespac[2] << " ";
					break;
				case 11:
					cout << endl << namespac[3] << " ";
					break;
				case 16:
					cout << endl << namespac[4] << " ";
					break;
				case 21:
					cout << endl << namespac[5] << " ";
					break;
				}
				cout << player1[i] << " ";
			}
			cout << "\x1b[0m";
			//-------------------------------------------------

			cout << endl;

			//------------------------------------------------- ИГРОК 2
			cout << endl << "  ";
			for (int i = 6; i <= 11; i++) //Буквы ирока 2
			{
				cout << "\x1b[31m";
				if (i != 11) { cout << namespac[i] << " "; }
				else { cout << namespac[i]; }
				cout << "\x1b[0m";
			}
			for (int i = 1; i <= 25; i++) // поле игрока2
			{
				cout << "\x1b[31m";
				switch (i) {
				case 1:
					cout << namespac[1] << " ";
					break;
				case 6:
					cout << endl << namespac[2] << " ";
					break;
				case 11:
					cout << endl << namespac[3] << " ";
					break;
				case 16:
					cout << endl << namespac[4] << " ";
					break;
				case 21:
					cout << endl << namespac[5] << " ";
					break;
				}
				cout << player2T[i] << " ";
			}
			cout << "\x1b[0m";
			//-------------------------------------------------

			cout << "\n\nВыберите место для кораблей \nИспользуйте WSAD и 1 для потовности \nВаш выбор: ";
			cin >> korablPl1;
			switch (korablPl1) {
			case 'w':
				if (xPl1 - 5 > 0)
				{
					if (player1[xPl1 - 5] != 'O') {
						player1[xPl1] = '-';
						player1[xPl1 - 5] = 'o';
						xPl1 -= 5;
					}
					else if (xPl1 - 10 > 0) {
						player1[xPl1] = '-';
						player1[xPl1 - 10] = 'o';
						xPl1 -= 10;
					}
				}
				else { cout << "нельзя"; }

				break;

			case 's':
				if (xPl1 + 5 < 26)
				{
					if (player1[xPl1 + 5] != 'O') {
						player1[xPl1] = '-';
						player1[xPl1 + 5] = 'o';
						xPl1 += 5;
					}
					else if (xPl1 + 10 < 26) {
						player1[xPl1] = '-';
						player1[xPl1 + 10] = 'o';
						xPl1 += 10;
					}
				}
				else { cout << "нельзя"; }
				break;

			case 'a':
				if (xPl1 - 1 > 0)
				{
					if (player1[xPl1 - 1] != 'O') {
						player1[xPl1] = '-';
						player1[xPl1 - 1] = 'o';
						xPl1 -= 1;
					}
					else if (xPl1 - 2 > 0) {
						player1[xPl1] = '-';
						player1[xPl1 - 2] = 'o';
						xPl1 -= 2;
					}
				}
				else { cout << "нельзя"; }
				break;

			case 'd':
				if (xPl1 + 1 < 26)
				{
					if (player1[xPl1 + 1] != 'O') {
						player1[xPl1] = '-';
						player1[xPl1 + 1] = 'o';
						xPl1 += 1;
					}
					else if (xPl1 + 2 < 26)
					{
						player1[xPl1] = '-';
						player1[xPl1 + 2] = 'o';
						xPl1 += 2;
					}
				}
				else { cout << "нельзя"; }
				break;
			case '1':
				player1[xPl1] = 'O';
				xPl1 = 1;
				korablsPl1++;

				break;
			default:
				cout << "\nОтвет не принят";
				break;
			}
	}
	system("cls");
	cout << "Передайте управление другому игроку...\n";
	Sleep(2000);
	
	//Второй игрок ставит корабли...
	while (korablsPl2 != 4) { // Первый игрок
		system("cls");
		cout << "Поставлено " << korablsPl2 << " из 4х";
		cout << endl << "  ";

		//------------------------------------------------- ИГРОК 2
		for (int i = 6; i <= 11; i++) //Буквы ирока 2
		{
			cout << "\x1b[31m";
			if (i != 11) { cout << namespac[i] << " "; }
			else { cout << namespac[i]; }
			cout << "\x1b[0m";
		}
		for (int i = 1; i <= 25; i++) // поле игрока2
		{
			cout << "\x1b[31m";
			switch (i) {
			case 1:
				cout << namespac[1] << " ";
				break;
			case 6:
				cout << endl << namespac[2] << " ";
				break;
			case 11:
				cout << endl << namespac[3] << " ";
				break;
			case 16:
				cout << endl << namespac[4] << " ";
				break;
			case 21:
				cout << endl << namespac[5] << " ";
				break;
			}
			cout << player2[i] << " ";
		}
		cout << "\x1b[0m";
		//-------------------------------------------------

		cout << endl;

		//------------------------------------------------- ИГРОК 1
		cout << endl << "  ";
		for (int i = 6; i <= 11; i++) //Буквы ирока 1
		{
			cout << "\x1b[36m";
			if (i != 11) { cout << namespac[i] << " "; }
			else { cout << namespac[i]; }
			cout << "\x1b[0m";
		}
		for (int i = 1; i <= 25; i++) // поле игрока1
		{
			cout << "\x1b[36m";
			switch (i) {
			case 1:
				cout << namespac[1] << " ";
				break;
			case 6:
				cout << endl << namespac[2] << " ";
				break;
			case 11:
				cout << endl << namespac[3] << " ";
				break;
			case 16:
				cout << endl << namespac[4] << " ";
				break;
			case 21:
				cout << endl << namespac[5] << " ";
				break;
			}
			cout << player1T[i] << " ";
		}
		cout << "\x1b[0m";
		//-------------------------------------------------

		cout << "\n\nВыберите место для кораблей \nИспользуйте WSAD и 1 для потовности \nВаш выбор: ";
		cin >> korablPl2;
		switch (korablPl2) {
		case 'w':
			if (xPl2 - 5 > 0)
			{
				if (player2[xPl2 - 5] != 'O') {
					player2[xPl2] = '-';
					player2[xPl2 - 5] = 'o';
					xPl2 -= 5;
				}
				else if (xPl2 - 10 > 0) {
					player2[xPl2] = '-';
					player2[xPl2 - 10] = 'o';
					xPl2 -= 10;
				}
			}
			else { cout << "нельзя"; }

			break;

		case 's':
			if (xPl2 + 5 < 26)
			{
				if (player2[xPl2 + 5] != 'O') {
					player2[xPl2] = '-';
					player2[xPl2 + 5] = 'o';
					xPl2 += 5;
				}
				else if (xPl2 + 10 < 26) {
					player2[xPl2] = '-';
					player2[xPl2 + 10] = 'o';
					xPl2 += 10;
				}
			}
			else { cout << "нельзя"; }
			break;

		case 'a':
			if (xPl2 - 1 > 0)
			{
				if (player2[xPl2 - 1] != 'O') {
					player2[xPl2] = '-';
					player2[xPl2 - 1] = 'o';
					xPl2 -= 1;
				}
				else if (xPl2 - 2 > 0) {
					player2[xPl2] = '-';
					player2[xPl2 - 2] = 'o';
					xPl2 -= 2;
				}
			}
			else { cout << "нельзя"; }
			break;

		case 'd':
			if (xPl2 + 1 < 26)
			{
				if (player2[xPl2 + 1] != 'O') {
					player2[xPl2] = '-';
					player2[xPl2 + 1] = 'o';
					xPl2 += 1;
				}
				else if (xPl2 + 2 < 26)
				{
					player2[xPl2] = '-';
					player2[xPl2 + 2] = 'o';
					xPl2 += 2;
				}
			}
			else { cout << "нельзя"; }
			break;
		case '1':
			player2[xPl2] = 'O';
			xPl2 = 1;
			korablsPl2++;

			break;
		default:
			cout << "\nОтвет не принят";
			break;
		}
	}
	system("cls");




	//Функция битвы
	while (true) {
		cout << "\nПередайте устройство другому игроку... \nНажмите для продолжения: ";
		cin >> gotov;

		if (peredBlue == 1 || gotov)
		{
			gotov = false;
			popadanie = false;
			while (mimoPl1 != 1) { // Первый игрок

				system("cls");
				cout << "Ходят Синии";
				cout << endl << "  ";
		

				//------------------------------------------------- ИГРОК 2
				for (int i = 6; i <= 11; i++) //Буквы ирока 2
				{
					cout << "\x1b[31m";
					if (i != 11) { cout << namespac[i] << " "; }
					else { cout << namespac[i]; }
					cout << "\x1b[0m";
				}
				for (int i = 1; i <= 25; i++) // поле игрока2
				{
					cout << "\x1b[31m";
					switch (i) {
					case 1:
						cout << namespac[1] << " ";
						break;
					case 6:
						cout << endl << namespac[2] << " ";
						break;
					case 11:
						cout << endl << namespac[3] << " ";
						break;
					case 16:
						cout << endl << namespac[4] << " ";
						break;
					case 21:
						cout << endl << namespac[5] << " ";
						break;
					}
					cout << player2T[i] << " ";
				}
				cout << "\x1b[0m";
				//-------------------------------------------------

				cout << endl;

				//------------------------------------------------- ИГРОК 1
				cout << endl << "  ";
				for (int i = 6; i <= 11; i++) //Буквы ирока 1
				{
					cout << "\x1b[36m";
					if (i != 11) { cout << namespac[i] << " "; }
					else { cout << namespac[i]; }
					cout << "\x1b[0m";
				}
				for (int i = 1; i <= 25; i++) // поле игрока1
				{
					cout << "\x1b[36m";
					switch (i) {
					case 1:
						cout << namespac[1] << " ";
						break;
					case 6:
						cout << endl << namespac[2] << " ";
						break;
					case 11:
						cout << endl << namespac[3] << " ";
						break;
					case 16:
						cout << endl << namespac[4] << " ";
						break;
					case 21:
						cout << endl << namespac[5] << " ";
						break;
					}
					cout << player1[i] << " ";
				}
				cout << "\x1b[0m";
				//-------------------------------------------------

				cout << "\n\nВыберите место для выстрела \nИспользуйте WSAD и 1 для выстрела \nВаш выбор: ";
				cin >> korablPl1T;
				switch (korablPl1T) {
				case 'w':
					if (xPlT2 - 5 > 0)
					{
						if (player2T[xPlT2 - 5] != 'X') {
							player2T[xPlT2] = '-';
							player2T[xPlT2 - 5] = 'x';
							xPlT2 -= 5;
						}
						else if (xPlT2 - 10 > 0) {
							player2T[xPlT2] = '-';
							player2T[xPlT2 - 10] = 'x';
							xPlT2 -= 10;
						}
					}
					else { cout << "нельзя"; }

					break;

				case 's':
					if (xPlT2 + 5 < 26)
					{
						if (player2T[xPlT2 + 5] != 'X') {
							player2T[xPlT2] = '-';
							player2T[xPlT2 + 5] = 'x';
							xPlT2 += 5;
						}
						else if (xPlT2 + 10 < 26) {
							player2T[xPlT2] = '-';
							player2T[xPlT2 + 10] = 'x';
							xPlT2 += 10;
						}
					}
					else { cout << "нельзя"; }
					break;

				case 'a':
					if (xPlT2 - 1 > 0)
					{
						if (player2T[xPlT2 - 1] != 'X') {
							player2T[xPlT2] = '-';
							player2T[xPlT2 - 1] = 'x';
							xPlT2 -= 1;
						}
						else if (xPlT2 - 2 > 0) {
							player2T[xPlT2] = '-';
							player2T[xPlT2 - 2] = 'x';
							xPlT2 -= 2;
						}
					}
					else { cout << "нельзя"; }
					break;

				case 'd':
					if (xPlT2 + 1 < 26)
					{
						if (player2T[xPlT2 + 1] != 'X') {
							player2T[xPlT2] = '-';
							player2T[xPlT2 + 1] = 'x';
							xPlT2 += 1;
						}
						else if (xPlT2 + 2 < 26)
						{
							player2T[xPlT2] = '-';
							player2T[xPlT2 + 2] = 'x';
							xPlT2 += 2;
						}
					}
					else { cout << "нельзя"; }
					break;
				case '1':

					if (player2[xPlT2] == 'O')
					{
						popadanie = true;
						popadaniePl1++;
						player2T[xPlT2] = 'X';
						xPlT2 = 1;
						mimoPl2 = 1;
						mimoPl1 = 0;

						if (popadaniePl1 == 4) {
							system("cls");
							cout << "\n\n\t\x1b[36m СИНИЕ ПОБЕДИЛИ! \x1b[0m\n\n";
							cout << "\t Спасибо за игру!\n\n";
							Sleep(5000);
							return 0;
						}
					}
					else
					{
						player2T[xPlT2] = '-';
						xPlT2 = 1;
						mimoPl1 = 1;
						mimoPl2 = 0;
						peredBlue = 0;
						gotov = false;

						if (popadaniePl1 == 4) {
							system("cls");
							cout << "\n\n\t\x1b[36m СИНИЕ ПОБЕДИЛИ! \x1b[0m\n\n";
							cout << "\t Спасибо за игру!\n\n";
							Sleep(5000);
							return 0;
						}

					}


					break;
				default:
					cout << "\nОтвет не принят";
					break;
				}
			}
			system("cls");


		}



		cout << "\nПередайте устройство другому игроку... \nНажмите для продолжения: ";
		cin >> gotov;


		if (peredBlue == 0 || gotov)
		{
			gotov = false;
			popadanie = false;
			 while (mimoPl2 != 1) { // второй игрок

				 if (popadaniePl1 == 4)
				 {
					 winBlue = true;
					 continue;
				 }
				 else if (popadaniePl2 == 4)
				 {
					 winRed = true;
					 continue;
				 }

				 system("cls");
				 cout << "Ходят Красные";
				 cout << endl << "  ";

				 //------------------------------------------------- ИГРОК 1
				 cout << endl << "  ";
				 for (int i = 6; i <= 11; i++) //Буквы ирока 1
				 {
					 cout << "\x1b[36m";
					 if (i != 11) { cout << namespac[i] << " "; }
					 else { cout << namespac[i]; }
					 cout << "\x1b[0m";
				 }
				 for (int i = 1; i <= 25; i++) // поле игрока1
				 {
					 cout << "\x1b[36m";
					 switch (i) {
					 case 1:
						 cout << namespac[1] << " ";
						 break;
					 case 6:
						 cout << endl << namespac[2] << " ";
						 break;
					 case 11:
						 cout << endl << namespac[3] << " ";
						 break;
					 case 16:
						 cout << endl << namespac[4] << " ";
						 break;
					 case 21:
						 cout << endl << namespac[5] << " ";
						 break;
					 }
					 cout << player1T[i] << " ";
				 }
				 cout << "\x1b[0m";
				 //-------------------------------------------------

				 cout << endl;

				 //------------------------------------------------- ИГРОК 2
				 for (int i = 6; i <= 11; i++) //Буквы ирока 2
				 {
					 cout << "\x1b[31m";
					 if (i != 11) { cout << namespac[i] << " "; }
					 else { cout << namespac[i]; }
					 cout << "\x1b[0m";
				 }
				 for (int i = 1; i <= 25; i++) // поле игрока2
				 {
					 cout << "\x1b[31m";
					 switch (i) {
					 case 1:
						 cout << namespac[1] << " ";
						 break;
					 case 6:
						 cout << endl << namespac[2] << " ";
						 break;
					 case 11:
						 cout << endl << namespac[3] << " ";
						 break;
					 case 16:
						 cout << endl << namespac[4] << " ";
						 break;
					 case 21:
						 cout << endl << namespac[5] << " ";
						 break;
					 }
					 cout << player2[i] << " ";
				 }
				 cout << "\x1b[0m";
				 //-------------------------------------------------

		 


				 cout << "\n\nВыберите место для выстрела \nИспользуйте WSAD и 1 для выстрела \nВаш выбор: ";
				 cin >> korablPl2T;
				 switch (korablPl2T) {
				 case 'w':
					 if (xPlT1 - 5 > 0)
					 {
						 if (player1T[xPlT1 - 5] != 'X') {
							 player1T[xPlT1] = '-';
							 player1T[xPlT1 - 5] = 'x';
							 xPlT1 -= 5;
						 }
						 else if (xPlT1 - 10 > 0) {
							 player1T[xPlT1] = '-';
							 player1T[xPlT1 - 10] = 'x';
							 xPlT1 -= 10;
						 }
					 }
					 else { cout << "нельзя"; }

					 break;

				 case 's':
					 if (xPlT1 + 5 < 26)
					 {
						 if (player1T[xPlT1 + 5] != 'X') {
							 player1T[xPlT1] = '-';
							 player1T[xPlT1 + 5] = 'x';
							 xPlT1 += 5;
						 }
						 else if (xPlT1 + 10 < 26) {
							 player1T[xPlT1] = '-';
							 player1T[xPlT1 + 10] = 'x';
							 xPlT1 += 10;
						 }
					 }
					 else { cout << "нельзя"; }
					 break;

				 case 'a':
					 if (xPlT1 - 1 > 0)
					 {
						 if (player1T[xPlT1 - 1] != 'X') {
							 player1T[xPlT1] = '-';
							 player1T[xPlT1 - 1] = 'x';
							 xPlT1 -= 1;
						 }
						 else if (xPlT1 - 2 > 0) {
							 player1T[xPlT1] = '-';
							 player1T[xPlT1 - 2] = 'x';
							 xPlT1 -= 2;
						 }
					 }
					 else { cout << "нельзя"; }
					 break;

				 case 'd':
					 if (xPlT1 + 1 < 26)
					 {
						 if (player1T[xPlT1 + 1] != 'X') {
							 player1T[xPlT1] = '-';
							 player1T[xPlT1 + 1] = 'x';
							 xPlT1 += 1;
						 }
						 else if (xPlT1 + 2 < 26)
						 {
							 player1T[xPlT1] = '-';
							 player1T[xPlT1 + 2] = 'x';
							 xPlT1 += 2;
						 }
					 }
					 else { cout << "нельзя"; }
					 break;
				 case '1':

					 if (player1[xPlT1] == 'O')
					 {
						 popadanie = true;
						 popadaniePl2++;
						 player1T[xPlT1] = 'X';
						 xPlT1 = 1;
						 mimoPl1 = 1;
						 mimoPl2 = 0;

						 if (popadaniePl2 == 4) {
							 system("cls");
							 cout << "\n\n\t\x1b[31m КРАСНЫЕ ПОБЕДИЛИ! \x1b[0m\n\n";
							 cout << "\t Спасибо за игру!\n\n";
							 Sleep(5000);
							 return 0;
						 }
					 }
					 else
					 {
						 player1T[xPlT1] = '-';
						 xPlT1 = 1;
						 mimoPl2 = 1;
						 mimoPl1 = 0;
						 peredBlue = 1;
						 gotov = false;

						 if (popadaniePl2 == 4) {
							 system("cls");
							 cout << "\n\n\t\x1b[31m КРАСНЫЕ ПОБЕДИЛИ! \x1b[0m\n\n";
							 cout << "\t Спасибо за игру!\n\n";
							 Sleep(5000);
							 return 0;
						 }

					 }

					 break;
				 default:
					 cout << "\nОтвет не принят";
					 break;
				 }
				 system("cls");
			 }
			 
		}


		cout << "Ход следующего";


	}
	

}