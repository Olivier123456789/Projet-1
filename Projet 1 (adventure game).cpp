#include <iostream>
#include <string>
#include <windows.h>
#include <random>

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
	sortie = 3,
};

void creation(int map[10][20], int ysortie, int xsortie) {
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 20; ++j) {
			map[i][j] = 0;
		}
	}
	for (int i = 4; i < 6; ++i) {
		for (int j = 12; j < 20; ++j) {
			map[i][j] = 1;
		}
	}
	for (int i = 7; i < 8; ++i) {
		for (int j = 6; j < 20; ++j) {
			map[i][j] = 2;
		}
	}
	map[ysortie][xsortie] = 3;
}

void afficher(int map[10][20], Personnage* perso) {
	int coordonnees[10][20] = {};
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 20; ++j) {
<<<<<<< Updated upstream
			for (int a = 0; a < 6; ++a) {
				if (perso[a].xhero == j && perso[a].yhero == i) {
					coordonnees[i][j] = 1;
				}
				else {
					coordonnees[i][j] = 0;
				}
			}
=======
			if (map[i][j] == ground) {
				std::cout << ".";
			}
			else if (map[i][j] == water) {
				std::cout << "~";
			}
			else if (map[i][j] == mountain) {
				std::cout << "A";
			}
			else if (map[i][j] == sortie) {
				std::cout << "E";
			}
			for (int a = 0; a < 6; ++a) {
				if (perso[a].xhero == j && perso[a].yhero == i) {
					std::cout << perso[a].nom;
					continue;
				}
			}
>>>>>>> Stashed changes
		}
	}
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 20; ++j) {
			for (int a = 0; a < 6; ++a) {
				if (perso[a].xhero == j && perso[a].yhero == i) {
					if (coordonnees[i][j] == 1) {
						std::cout << perso[a].nom;
					}
				}
			}
			if (coordonnees[i][j] == 0) {

				if (map[i][j] == ground) {
					std::cout << ".";
				}
				if (map[i][j] == water) {
					std::cout << "~";
				}
				if (map[i][j] == mountain) {
					std::cout << "A";
				}
				if (map[i][j] == sortie) {
					std::cout << "E";
				}
			}

		}
		std::cout << "\n";
	}
};

int main() {
	int map[10][20] = {};
	int ysortie = 9;
	int xsortie = 19;
<<<<<<< Updated upstream
	creation(map, ysortie, xsortie);
	Personnage perso[6] = { {"H",5,0,1},{"X",0,0},{"X",1,1},{"X",2,2},{"X",3,3},{"X",4,4} };
	afficher(map, perso);
	char touche = 'm';
	std::cin >> touche;
	while (touche != 'x') {
		if (touche == 'z' || touche == 'Z') {
			perso[0].yhero -= 1;
			if (map[perso[0].yhero][perso[0].xhero] == 2) {
				perso[0].yhero += 1;
			}
=======
	int defaite = 0;
	Personnage perso[6] = { {"H",0,0,1},{"X",0,0},{"X",0,0},{"X",0,0},{"X",0,0},{"X",0,0} };
		for (int niveau = 1; niveau < 3; ++niveau) {
			std::cout << "Niveau " << niveau << " :" << "\n" << "\n";
			creation(map, ysortie, xsortie, niveau);
			positions(map, perso);
			afficher(map, perso);
			mouvement(map, perso, ysortie, xsortie, defaite,niveau);
>>>>>>> Stashed changes
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
				std::cout << "GAME OVER";
				return 0;
			}
		}
		for (int a = 1; a < 6; ++a) {
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<int> distrib(1, 4);
			int movement = distrib(gen);
			if (movement == 1) {
				if (map[perso[a].yhero + 1][perso[a].xhero] == 2) {
					perso[a].yhero += 0;
				}
				else { perso[a].yhero += 1; }
			}
			if (movement == 2) {
				if (map[perso[a].yhero - 1][perso[a].xhero] == 2) {
					perso[a].yhero -= 0;
				}
				else { perso[a].yhero -= 1; }
			}
			if (movement == 3) {
				if (map[perso[a].yhero][perso[a].xhero+1] == 2) {
					perso[a].xhero += 0;
				}
				else { perso[a].xhero += 1; }
			}
			if (movement == 4) {
				if (map[perso[a].yhero][perso[a].xhero-1] == 2) {
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
				std::cout << "GAME OVER";
				return 0;
			}
		}
		if (perso[0].yhero == ysortie && perso[0].xhero == xsortie) {
			std::cout << "Niveau termine !!!";
			return 0;
		}
		afficher(map, perso);
		std::cin >> touche;
	}
}