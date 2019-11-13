#include <iostream>

const char *Dzialania[4] = { "dodawania","odejmowania","mnozenia","dzielenia", };

double calculate(double a, double b, double(double, double));
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
int dzialanie();
void pobieranie(double liczby[2], int znak, int nr);


int main()
{
	std::cout << *Dzialania << "\n" << *(Dzialania + 1) << "\n" << Dzialania[2] << "\n" << Dzialania[3] << "\n";
	// wskaznik na tablice wskaznikow funkcji
	double(*pf[4])(double, double) = { *add,*subtract,*multiply,*divide }; //== { add,subtract,multiply,divide }; <- to to samo-  w obu przypadkach przekazujemy adres
	while (1)
	{
		int znak;
		double liczby[2];
		znak = dzialanie();
		if (znak == 10)
		{
			std::cout << "\nWprowadzono \"0\". \nKoniec programu";
			break;
		}
		pobieranie(liczby, znak, 0);
		switch (znak)
		{
		case 0:
			std::cout << "Wynik " << Dzialania[0] << " liczb " << liczby[0] << " i "
				<< liczby[1] << " daje wynik " << calculate(liczby[0], liczby[1], pf[0]) << std::endl << std::endl;
			break;
		case 1:
			std::cout << "Wynik " << Dzialania[1] << " liczb " << liczby[0] << " i "
				<< liczby[1] << " daje wynik " << calculate(liczby[0], liczby[1], pf[1]) << std::endl << std::endl;
			break;
		case 2:
			std::cout << "Wynik " << Dzialania[2] << " liczb " << liczby[0] << " i "
				<< liczby[1] << " daje wynik " << calculate(liczby[0], liczby[1], pf[2]) << std::endl << std::endl;
			break;
		case 3:
			if (liczby[1] == 0)
				std::cout << "Nie dzieli sie przez 0\nHInzu jest glupi\n";
			else
				std::cout << "Wynik " << Dzialania[3] << " liczb " << liczby[0] << " i "
				<< liczby[1] << " daje wynik " << calculate(liczby[0], liczby[1], pf[3]) << std::endl << std::endl;
		}
	}

	std::cin.get();
	return 0;
}

void pobieranie(double liczby[2], int znak, int nr)
{
	if (nr < 2)
	{
		std::cout << "podaj " << nr + 1 << " liczbe do " << Dzialania[znak] << " : ";
		std::cin >> liczby[nr];
		if (!std::cin)
		{
			std::cin.clear();
			while (std::cin.get() != '\n')
				continue;
			std::cout << "blad wprowadzania liczb.\n";
			pobieranie(liczby, znak, nr);
			return;
		}
		if (nr < 1)
			pobieranie(liczby, znak, nr + 1);
	}




}

int dzialanie()
{
	int funkcja;
	char znak;
	std::cout << "podaj znak dzialania które chcesz wykonac:\n\"+\"  " << *Dzialania << "\t\"-\"  " << *(Dzialania + 1)
		<< "\t\"*\"  " << *(Dzialania + 2) << "\t\":\"  " << *(Dzialania + 3) << "\t \"0\" aby zakaczyc\n:";
	std::cin >> znak;
	switch (znak)
	{
	case '+':
		funkcja = 0;
		break;
	case '-':
		funkcja = 1;
		break;
	case '*':
		funkcja = 2;
		break;
	case ':':
	case ';':
		funkcja = 3;
		break;
	case '0':
		funkcja = 10;
		break;
	default:
		while (std::cin.get() != '\n')
			continue;
		funkcja = dzialanie();  //recursion

	}
	return funkcja;
}


double calculate(double a, double b, double pf(double, double))
{
	return pf(a, b);
}


double add(double a, double b)
{
	//double result;
	return a + b;
}


double subtract(double a, double b)
{
	double result;
	return result = a - b;
}


double multiply(double a, double b)
{
	double result;
	return result = a * b;
}


double divide(double a, double b)
{
	double result;
	return result = a / b;
}