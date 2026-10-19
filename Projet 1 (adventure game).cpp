#include <iostream>
#include <string>
#include <windows.h>
#include <random>
#include <fstream>

using namespace std;

struct Personnage {
	std::string nom;
	int yhero = 0;
	int xhero = 0;
	int vie = 1;
};
enum tile_type {
	ground = 0,
	water = 1,
	mountain = 2,
	sortie = 3
};
void creation(int map[10][20], int ysortie, int xsortie, int niveau, Personnage* perso) {
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
					ysortie = i;
					xsortie = j;
				}
				else if (ligne[j] == 'H') {
					perso[0].yhero = i;
					perso[0].xhero = j;
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
void positions(int map[10][20], Personnage* perso) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> posx(0, 19);
	std::uniform_int_distribution<int> posy(0, 9);
	for (int i = 1; i < 6; ++i) {
		int posenx = posx(gen);
		perso[i].xhero = posenx;
		int poseny = posy(gen);
		perso[i].yhero = poseny;
		if (map[perso[i].yhero][perso[i].xhero] == 2 || map[perso[i].yhero][perso[i].xhero] == 3) {
			while (map[perso[i].yhero][perso[i].xhero] == 2 || map[perso[i].yhero][perso[i].xhero] == 3) {
				int posenx = posx(gen);
				perso[i].xhero = posenx;
				int poseny = posy(gen);
				perso[i].yhero = poseny;
			}
		}
	}
}
void afficher(int map[10][20], Personnage* perso) {
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 20; ++j) {
			bool find = false;
			for (int a = 0; a < 6; ++a) {
				if (i == perso[a].yhero && j == perso[a].xhero) {
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

void mouvement(int map[10][20], Personnage* perso, int ysortie, int xsortie, int defaite, int niveau) {
	std::random_device rd;
	std::mt19937 gen(rd());
	char touche = 'm';
	std::cin >> touche;
	while (touche != 'x') {
		if (touche == 'z' || touche == 'Z') {
			perso[0].yhero -= 1;
			if (map[perso[0].yhero][perso[0].xhero] == 2) {
				perso[0].yhero += 1;
			}
		}
		if (touche == 'q' || touche == 'Q') {
			perso[0].xhero -= 1;
			if (map[perso[0].yhero][perso[0].xhero] == 2) {
				perso[0].xhero += 1;
			}
		}
		if (touche == 's' || touche == 'S') {
			perso[0].yhero += 1;
			if (map[perso[0].yhero][perso[0].xhero] == 2) {
				perso[0].yhero -= 1;
			}
		}
		if (touche == 'd' || touche == 'D') {
			perso[0].xhero += 1;
			if (map[perso[0].yhero][perso[0].xhero] == 2) {
				perso[0].xhero -= 1;
			}
		}
		if (touche == 'x' || touche == 'X') {
			defaite += 1;
		}
		if (perso[0].xhero < 0) {
			perso[0].xhero += 1;
		}
		if (perso[0].xhero == 20) {
			perso[0].xhero -= 1;
		}
		if (perso[0].yhero < 0) {
			perso[0].yhero += 1;
		}
		if (perso[0].yhero == 10) {
			perso[0].yhero -= 1;
		}
		for (int a = 1; a < 6; ++a) {
			if (perso[0].yhero == perso[a].yhero && perso[0].xhero == perso[a].xhero) {
				perso[0].vie -= 1;
			}
			if (perso[0].vie == 0) {
				std::cout << "GAME OVER !";
				defaite += 1;
				break;
			}
		}
		for (int a = 1; a < 6; ++a) {
			std::uniform_int_distribution<int> distrib(1, 4);
			int movement = distrib(gen);
			if (movement == 1) {
				if (map[perso[a].yhero + 1][perso[a].xhero] == 2 || map[perso[a].yhero + 1][perso[a].xhero] == 3) {
					perso[a].yhero += 0;
				}
				else { perso[a].yhero += 1; }
			}
			if (movement == 2) {
				if (map[perso[a].yhero - 1][perso[a].xhero] == 2 || map[perso[a].yhero - 1][perso[a].xhero] == 3) {
					perso[a].yhero -= 0;
				}
				else { perso[a].yhero -= 1; }
			}
			if (movement == 3) {
				if (map[perso[a].yhero][perso[a].xhero + 1] == 2 || map[perso[a].yhero][perso[a].xhero + 1] == 3) {
					perso[a].xhero += 0;
				}
				else { perso[a].xhero += 1; }
			}
			if (movement == 4) {
				if (map[perso[a].yhero][perso[a].xhero - 1] == 2 || map[perso[a].yhero][perso[a].xhero - 1] == 3) {
					perso[a].xhero -= 0;
				}
				else { perso[a].xhero -= 1; }
			}
			if (perso[a].xhero < 0) {
				perso[a].xhero += 1;
			}
			if (perso[a].xhero == 20) {
				perso[a].xhero -= 1;
			}
			if (perso[a].yhero < 0) {
				perso[a].yhero += 1;
			}
			if (perso[a].yhero == 10) {
				perso[a].yhero -= 1;
			}
		}
		for (int a = 1; a < 6; ++a) {
			if (perso[0].yhero == perso[a].yhero && perso[0].xhero == perso[a].xhero) {
				perso[0].vie -= 1;
			}
			if (perso[0].vie == 0) {
				std::cout << "GAME OVER !";
				defaite += 1;
				break;
			}
		}
		if (perso[0].yhero == ysortie && perso[0].xhero == xsortie) {
			std::cout << "Niveau " << niveau << " termine !!!" << "\n" << "\n";
			return;

		}
		afficher(map, perso);
		std::cin >> touche;
	}
}

int main() {
	int niveau = 1;
	int map[10][20] = {};
	int defaite = 0;
	int ysortie = 0;
	int xsortie = 0;
	Personnage perso[6] = { { "H",0,0,1 },{ "X",0,0 },{ "X",0,0 },{ "X",0,0 },{ "X",0,0 },{ "X",0,0 } };
		for (int niveau = 1; niveau < 3; ++niveau) {
			std::cout << "Niveau " << niveau << " :" << "\n" << "\n";
			creation(map, niveau, xsortie, ysortie, perso);
			positions(map, perso);
			afficher(map, perso);
			mouvement(map, perso, ysortie, xsortie, defaite, niveau);
		}
}