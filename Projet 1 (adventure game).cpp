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

void creation(int map[10][20], int niveau, Personnage* perso) {
	if (niveau == 1) {
		ifstream fichier("Maps/Niveau1.txt");
		if (fichier)
		{
			string ligne;
			for (int i = 0; i < 10; ++i) {
				getline(fichier, ligne);
				for (int j = 0; j < 20; ++j) {
					if (ligne[j] == '.') {
						map[i][j] = ground;
					}
					else if (ligne[j] == '~') {
						map[i][j] = water;
					}
					else if (ligne[j] == 'A') {
						map[i][j] = mountain;
					}
					else if (ligne[j] == 'E') {
						map[i][j] = sortie;
						perso[6].yp = i;
						perso[6].xp = j;
					}
					else if (ligne[j] == 'H') {
						perso[0].yp = i;
						perso[0].xp = j;
					}
				}
			}
		}
		else
		{
			cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
		}
		return;
	}
	if (niveau == 2) {
		ifstream fichier("Maps/Niveau2.txt");
		if (fichier)
		{
			string ligne;
			for (int i = 0; i < 10; ++i) {
				getline(fichier, ligne);
				for (int j = 0; j < 20; ++j) {
					if (ligne[j] == '.') {
						map[i][j] = ground;
					}
					else if (ligne[j] == '~') {
						map[i][j] = water;
					}
					else if (ligne[j] == 'A') {
						map[i][j] = mountain;
					}
					else if (ligne[j] == 'E') {
						map[i][j] = sortie;
						perso[6].yp = i;
						perso[6].xp = j;
					}
					else if (ligne[j] == 'H') {
						perso[0].yp = i;
						perso[0].xp = j;
					}
				}
			}
		}
		else
		{
			cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
		}
		return;
	}
	if (niveau == 3) {
		ifstream fichier("Maps/Niveau3.txt");
		if (fichier)
		{
			string ligne;
			for (int i = 0; i < 10; ++i) {
				getline(fichier, ligne);
				for (int j = 0; j < 20; ++j) {
					if (ligne[j] == '.') {
						map[i][j] = ground;
					}
					else if (ligne[j] == '~') {
						map[i][j] = water;
					}
					else if (ligne[j] == 'A') {
						map[i][j] = mountain;
					}
					else if (ligne[j] == 'E') {
						map[i][j] = sortie;
						perso[6].yp = i;
						perso[6].xp = j;
					}
					else if (ligne[j] == 'H') {
						perso[0].yp = i;
						perso[0].xp = j;
					}
				}
			}
		}
		else
		{
			cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
		}
		return;
	}
}
void positions(int map[10][20], Personnage* perso) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> posx(0, 19);
	std::uniform_int_distribution<int> posy(0, 9);
	for (int i = 1; i < 6; ++i) {
		int posenx = posx(gen);
		perso[i].xp = posenx;
		int poseny = posy(gen);
		perso[i].yp = poseny;
		if (map[perso[i].yp][perso[i].xp] == 2 || map[perso[i].yp][perso[i].xp] == 3) {
			while (map[perso[i].yp][perso[i].xp] == 2 || map[perso[i].yp][perso[i].xp] == 3) {
				int posenx = posx(gen);
				perso[i].xp = posenx;
				int poseny = posy(gen);
				perso[i].yp = poseny;
			}
		}
	}
}
void afficher(int map[10][20], Personnage* perso) {
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 20; ++j) {
			bool find = false;
			for (int a = 0; a < 6; ++a) {
				if (i == perso[a].yp && j == perso[a].xp) {
					std::cout << perso[a].nom;
					find = true;
					break;
				}
			}
			if (find)
				continue;
			else if (map[i][j] == ground) {
				std::cout << '.';
			}
			else if (map[i][j] == water) {
				std::cout << '~';
			}
			else if (map[i][j] == mountain) {
				std::cout << 'A';
			}
			else if (map[i][j] == sortie) {
				std::cout << 'E';
			}
		}
		std::cout << '\n';
	}
};

int mouvement(int map[10][20], Personnage* perso, int* d, int niveau) {
	std::random_device rd;
	std::mt19937 gen(rd());
	char touche ;
	while (1) {
		if (_kbhit) {
			touche = _getch();
			if (touche == 'x' || touche == 'X') {
				return (1);
			}
	
				if (touche == 'z' || touche == 'Z') {
					perso[0].yp -= 1;
					if (map[perso[0].yp][perso[0].xp] == 2) {
						perso[0].yp += 1;
					}
				}
				if (touche == 'q' || touche == 'Q') {
					perso[0].xp -= 1;
					if (map[perso[0].yp][perso[0].xp] == 2) {
						perso[0].xp += 1;
					}
				}
				if (touche == 's' || touche == 'S') {
					perso[0].yp += 1;
					if (map[perso[0].yp][perso[0].xp] == 2) {
						perso[0].yp -= 1;
					}
				}
				if (touche == 'd' || touche == 'D') {
					perso[0].xp += 1;
					if (map[perso[0].yp][perso[0].xp] == 2) {
						perso[0].xp -= 1;
					}
				}

				if (perso[0].xp < 0) {
					perso[0].xp += 1;
				}
				if (perso[0].xp == 20) {
					perso[0].xp -= 1;
				}
				if (perso[0].yp < 0) {
					perso[0].yp += 1;
				}
				if (perso[0].yp == 10) {
					perso[0].yp -= 1;
				}
				for (int a = 1; a < 6; ++a) {
					std::uniform_int_distribution<int> distrib(1, 4);
					int movement = distrib(gen);
					if (movement == 1) {
						if (map[perso[a].yp + 1][perso[a].xp] == 2 || map[perso[a].yp + 1][perso[a].xp] == 3) {
							perso[a].yp += 0;
						}
						else { perso[a].yp += 1; }
					}
					if (movement == 2) {
						if (map[perso[a].yp - 1][perso[a].xp] == 2 || map[perso[a].yp - 1][perso[a].xp] == 3) {
							perso[a].yp -= 0;
						}
						else { perso[a].yp -= 1; }
					}
					if (movement == 3) {
						if (map[perso[a].yp][perso[a].xp + 1] == 2 || map[perso[a].yp][perso[a].xp + 1] == 3) {
							perso[a].xp += 0;
						}
						else { perso[a].xp += 1; }
					}
					if (movement == 4) {
						if (map[perso[a].yp][perso[a].xp - 1] == 2 || map[perso[a].yp][perso[a].xp - 1] == 3) {
							perso[a].xp -= 0;
						}
						else { perso[a].xp -= 1; }
					}
					if (perso[a].xp < 0) {
						perso[a].xp += 1;
					}
					if (perso[a].xp == 20) {
						perso[a].xp -= 1;
					}
					if (perso[a].yp < 0) {
						perso[a].yp += 1;
					}
					if (perso[a].yp == 10) {
						perso[a].yp -= 1;
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
}

int main() {
	int niveau = 1;
	int map[10][20] = {};
	int defaite = 0;
	int* d = &defaite;
	Personnage perso[7] = { { "H",0,0,1 },{ "X",0,0 },{ "X",0,0 },{ "X",0,0 },{ "X",0,0 },{ "X",0,0 },{ "E",0,0 } };
	for (int n = 1; n < 4; ++n) {
		std::cout << "Niveau " << niveau << " :" << "\n" << "\n";
		creation(map, niveau, perso);
		positions(map, perso);
		afficher(map, perso);
		int victoire = mouvement(map, perso, d, niveau);
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
