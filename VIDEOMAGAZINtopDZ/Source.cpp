#include<iostream>
#include <string>
#include"structs.h"

using namespace std;

const int sizeArr = 100;

void printFile(magazin filmsArr[], int indexToInsert)
{
	cout << filmsArr[indexToInsert].name << "|"
		<< filmsArr[indexToInsert].director << "|";
	switch (filmsArr[indexToInsert].Genre)
	{
	case 0: 
		cout << " HORROR |";
		break;
	case 1:
		cout << " THRILLER |";
		break;
	case 2: 
		cout << " MELODRAMA |";
		break;
	case 3:
		cout << " PHILOSOPHY |";
		break;
	default:
		cout << " No Info |";
		break;
	}
		cout << filmsArr[indexToInsert].rating << "|"
		<< filmsArr[indexToInsert].price << "|" << endl;
}

magazin addingFile()
{
	magazin film;
	cout << "Name of the film: "<<endl;
	getline(cin, film.name);
	cout << "Director of the film: " << endl;
	getline(cin, film.director);
	cout << "Genre:\n1 - HORROR\n2 - THRILLER\n3 - MELODRAMA\n4 - PHILOSOPHY" << endl;
	short genre;
	cin >> genre;
	//cin.ignore();
	switch (genre)
	{
	case 1:
		film.Genre = genre::horror;
		break;
	case 2:
		film.Genre = genre::thriller;
		break;
	case 3:
		film.Genre = genre::melodrama;
		break;
	case 4:
		film.Genre = genre::philosophy;
		break;

	default:
		cout << "Wrong input!" << endl;
		break;
	}

	cout << "Enter the rating: " << endl;
	cin >> film.rating;



	cout << "Enter the price: " << endl;
	cin >> film.price;

	

	return film;
}

void mostPopularInGenre(magazin filmsArr[], int indexToInsert)
{
	cout << "Enter the genre:\n1 - HORROR\n2 - THRILLER\n3 - MELODRAMA\n4 - PHILOSOPHY" << endl;
	genre Genre;
	short genre;
	string strGenre;
	cin >> genre;
	int ans;
	double rating = 0;
	switch (genre)
	{
	case 1:
		Genre = genre::horror;
		strGenre = "horror";
		break;
	case 2:
		Genre = genre::thriller;
		strGenre = "thriller";
		break;
	case 3:
		Genre = genre::melodrama;
		strGenre = "melodrama";
		break;
	case 4:
		Genre = genre::philosophy;
		strGenre = "philosophy";
		break;

	default:
		cout << "Wrong input!" << endl;
		break;
	}

	bool foundFilm = false;


	for (int i = 0; i < indexToInsert; i++)
	{
		if (filmsArr[i].Genre == Genre && filmsArr[i].rating > rating)
		{
			ans = i;
			rating = filmsArr[i].rating;
			foundFilm = true;
		}
	}
	
	if (foundFilm)
	{
		cout << "The most popular in genre " << strGenre << ":\n";
		printFile(filmsArr, ans);
	}
	else
		cout << "No such films" << endl;
}


void searchByGenre(magazin filmsArr[], int indexToInsert)
{
	cout << "Enter the genre:\n1 - HORROR\n2 - THRILLER\n3 - MELODRAMA\n4 - PHILOSOPHY" << endl;
	genre Genre;
	short genre;
	string strGenre;
	cin >> genre;
	switch (genre)
	{
	case 1:
		Genre = genre::horror;
		strGenre = "horror";
		break;
	case 2:
		Genre = genre::thriller;
		strGenre = "thriller";
		break;
	case 3:
		Genre = genre::melodrama;
		strGenre = "melodrama";
		break;
	case 4:
		Genre = genre::philosophy;
		strGenre = "philosophy";
		break;
	default:
		cout << "Wrong input!" << endl;
		break;
	}

	cout << "All the films in " << strGenre << " genre: " << endl;
	for (int i = 0; i < indexToInsert; i++)
	{
		if (filmsArr[i].Genre == Genre)
		{
			printFile(filmsArr, i);
		}
	}
}

bool proverka(int value, string str, string pdstr)
{
	for (int i = 0; i < pdstr.size(); i++)
	{
		if (pdstr[i] != str[value])
			return false;
		value++;
	}
	return true;
}

void searchByDirector(magazin filmsArr[], int indexToInsert)
{
	cout << "Enter the director: " << endl;
	string dir;
	cin >> dir;
	cout << "Results of searching by director \"" << dir << "\": " << endl;
	for (int i = 0; i < indexToInsert; i++)
	{
		for (int j = 0; j < filmsArr[i].director.size(); j++)
		{
			if (filmsArr[i].director[j] == dir[0])
				if (proverka(j, filmsArr[i].director, dir))
				{
					printFile(filmsArr, i);
					break;
				}
		}
	}
}

void searchByName(magazin filmsArr[], int indexToInsert)
{
	cout << "Enter the name: " << endl;
	string podStroka;
	cin >> podStroka;
	cout << "Results of searching by name \"" << podStroka << "\": " << endl;
	for (int i = 0; i < indexToInsert; i++)
	{
		for (int j = 0; j < filmsArr[i].name.size(); j++)
		{
			if (filmsArr[i].name[j] == podStroka[0])
			{
				if (proverka(j, filmsArr[i].name, podStroka))
				{
					printFile(filmsArr, i);
					break;
				}
					
			
			}
		}
	}
}





int main()
{
	cout << "---VIDEO MAGAZIN---" << endl;

	
	magazin filmsArr[sizeArr];
	int indexToInsert = 0; //для нахождения свободного элемента в массиве
	bool TurnOn = true;
	short choice;

	while (TurnOn)
	{
		cout << "1 - Add a new film\n2 - Show the entire library\n3 - Quit\n4 - The most popular film in genre\n5 - Search with genre"
			<< "\n6 - Search by name\n7 - Search by director" << endl;
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 1:
		{
			system("cls");
			magazin newFile = addingFile();
			filmsArr[indexToInsert] = newFile;
			printFile(filmsArr, indexToInsert);
			indexToInsert++;
			break;
		}
			
		case 2:
			system("cls");
			cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\nLIBRARY\n";
			for (int i = 0; i < indexToInsert; i++)
			{
				printFile(filmsArr, i);
			}
			cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
			break;
		case 3:
			system("cls");
			TurnOn = false;
			break;
		case 4:
			system("cls");
			if (indexToInsert == 0)
			{
				cout << "No films in library..." << endl;
				break;
			}
			cout << "The most popular film in genre";
			mostPopularInGenre(filmsArr, indexToInsert);
			break;

		case 5:
			system("cls");
			cout << "Search by genre";
			searchByGenre(filmsArr, indexToInsert);
			break;

		case 6:
			system("cls");
			cout << "Search by name";
			searchByName(filmsArr, indexToInsert);
			break;

		case 7:
			system("cls");
			cout << "Search by name";
			searchByDirector(filmsArr, indexToInsert);
			break;

		default:
			cout << "Wrong input!" << endl;
			break;
		}

	}

	return 0;

}
