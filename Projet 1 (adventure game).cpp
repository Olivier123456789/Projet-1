#include <iostream>
#include <string>
#include <windows.h>
#include <random>
#include <fstream>
#include <stdio.h>
#include <conio.h>

using namespace std;

struct Personnage {
	std::string nom;
	int yp = 0;
	int xp = 0;
	int vie = 1;
};

enum tile_type {
	ground = 0,
	water = 1,
	mountain = 2,
	sortie = 3
};

int lecture(int map[10][20], int niveau, Personnage* perso) {
	std::string file;
	if (niveau == 1) {
		file = "Maps/Niveau1.txt";
	}
	if (niveau == 2) {
		file = "Maps/Niveau2.txt";
	}
	if (niveau == 3) {
		file = "Maps/Niveau3.txt";
	}
	ifstream fichier(file);
	if (fichier)
	{
		string ligne;
		int en = 1;
		int  carvalide = 0;
		int sortievalide = 0;
		int posdepart = 0;
		for (int y = 0; y < 10; ++y) {
			getline(fichier, ligne);
			for (int x = 0; x < 20; ++x) {
				if (ligne[x] == '.') {
					map[y][x] = ground;
					carvalide += 1;
				}
				else if (ligne[x] == 'X') {
					perso[en].yp = y;
					perso[en].xp = x;
					carvalide += 1;
					en++;
				}
				else if (ligne[x] == '~') {
					map[y][x] = water;
					carvalide += 1;
				}
				else if (ligne[x] == 'A') {
					map[y][x] = mountain;
					carvalide += 1;
				}
				else if (ligne[x] == 'E') {
					map[y][x] = sortie;
					perso[6].yp = y;
					perso[6].xp = x;
					sortievalide += 1;
					carvalide += 1;
				}
				else if (ligne[x] == 'H') {
					perso[0].yp = y;
					perso[0].xp = x;
					posdepart += 1;
					carvalide += 1;
				}
			}
		}
		if (posdepart == 0) {
			cout << "ERREUR: Le fichier ne contient pas de position de depart." << endl;
			return 1;
		}
		else if (sortievalide == 0) {
			cout << "ERREUR: Le fichier ne contient pas de sortie." << endl;
			return 1;
		}
		else if (carvalide < 200) {
			cout << "ERREUR: Le fichier contient un caractere invalide" << endl;
			return 1;
		}
		else if (en < 6) {
			cout << "ERREUR: Le fichier ne contient pas assez de personnages ennemis." << endl;
			return 1;
		}
		else if (en > 6) {
			cout << "ERREUR: Le fichier contient trop de personnages ennemis." << endl;
			return 1;
		}
	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
		return 1;
	}
	return 0;
}

int creation(int map[10][20], int niveau, Personnage* perso) {
	if (niveau == 1) {
		int lectureinvalide = lecture(map, niveau, perso);
		if (lectureinvalide == 1) {
			return 1;
		}
		else {
			return 0;
		}
	}
	if (niveau == 2) {
		int lectureinvalide = lecture(map, niveau, perso);
		if (lectureinvalide == 1) {
			return 1;
		}
		else {
			return 0;
		}
	}
	if (niveau == 3) {
		int lectureinvalide = lecture(map, niveau, perso);
		if (lectureinvalide == 1) {
			return 1;
		}
		else {
			return 0;
		}
	}
	return 0;
}

void afficher(int map[10][20], Personnage* perso) {
	for (int y = 0; y < 10; ++y) {
		for (int x = 0; x < 20; ++x) {
			bool find = false;
			for (int a = 0; a < 6; ++a) {
				if (y == perso[a].yp && x == perso[a].xp) {
					std::cout << perso[a].nom;
					find = true;
					break;
				}
			}
			if (find)
				continue;
			else if (map[y][x] == ground) {
				std::cout << '.';
			}
			else if (map[y][x] == water) {
				std::cout << '~';
			}
			else if (map[y][x] == mountain) {
				std::cout << 'A';
			}
			else if (map[y][x] == sortie) {
				std::cout << 'E';
			}
		}
		std::cout << '\n';
	}
};

int mouvement(int map[10][20], Personnage* perso, int niveau) {
	std::random_device rd;
	std::mt19937 gen(rd());
	char touche;
	while (1) {
		touche = _getch();
		if (touche == 'x' || touche == 'X') {
			return (1);
		}
		if (touche == 'z' || touche == 'Z') {
			if (map[perso[0].yp - 1][perso[0].xp] != mountain && perso[0].yp - 1 >= 0) {
				perso[0].yp -= 1;
			}
		}
		if (touche == 'q' || touche == 'Q') {
			if (map[perso[0].yp][perso[0].xp - 1] != mountain && perso[0].xp - 1 >= 0) {
				perso[0].xp -= 1;
			}
		}
		if (touche == 's' || touche == 'S') {
			if (map[perso[0].yp + 1][perso[0].xp] != mountain && perso[0].yp + 1 < 10) {
				perso[0].yp += 1;
			}
		}
		if (touche == 'd' || touche == 'D') {
			if (map[perso[0].yp][perso[0].xp + 1] != mountain && perso[0].xp + 1 < 20) {
				perso[0].xp += 1;
			}
		}
		for (int a = 1; a < 6; ++a) {
			std::uniform_int_distribution<int> distrib(1, 4);
			int movement = distrib(gen);
			if (movement == 1) {
				if (map[perso[a].yp + 1][perso[a].xp] != mountain && map[perso[a].yp + 1][perso[a].xp] != sortie && perso[a].yp + 1 < 10) {
					perso[a].yp += 1;
				}
			}
			else if (movement == 2) {
				if (map[perso[a].yp - 1][perso[a].xp] != mountain && map[perso[a].yp - 1][perso[a].xp] != sortie && perso[a].yp - 1 >= 0) {
					perso[a].yp -= 1;
				}
			}
			else if (movement == 3) {
				if (map[perso[a].yp][perso[a].xp + 1] != mountain && map[perso[a].yp][perso[a].xp + 1] != sortie && perso[a].xp + 1 < 20) {
					perso[a].xp += 1;
				}
			}
			if (movement == 4) {
				if (map[perso[a].yp][perso[a].xp - 1] != mountain && map[perso[a].yp][perso[a].xp - 1] != sortie && perso[a].xp - 1 >= 0) {
					perso[a].xp -= 1;
				}
			}
		}
		for (int a = 1; a < 6; ++a) {
			if (perso[0].yp == perso[a].yp && perso[0].xp == perso[a].xp) {
				perso[0].vie -= 1;
			}
			if (perso[0].vie == 0) {
				std::cout << "GAME OVER !";
				return (1);
			}
		}
		if (perso[0].yp == perso[6].yp && perso[0].xp == perso[6].xp) {
			std::cout << "Niveau " << niveau << " termine !!!" << "\n" << "\n";
			return (0);

		}
		afficher(map, perso);
		std::cout << "\n";

	}
}

int main() {
	int niveau = 1;
	int map[10][20] = {};
	Personnage perso[7] = { { "H",0,0,1 },{ "X",0,0 },{ "X",0,0 },{ "X",0,0 },{ "X",0,0 },{ "X",0,0 },{ "E",0,0 } };
	for (int n = 1; n < 4; ++n) {
		std::cout << "Niveau " << niveau << " :" << "\n" << "\n";
		int niveauinvalide = creation(map, niveau, perso);
		if (niveauinvalide == 1) {
			break;
		}
		afficher(map, perso);
		int victoire = mouvement(map, perso, niveau);
		if (victoire == 1) {
			break;
		}
		else {
			niveau += 1;
		}
	}
	if (niveau == 4) {
		std::cout << "\n" << "\n" << "FELICITATION !!!! VOUS AVEZ GAGNE !!!!";
	}
}