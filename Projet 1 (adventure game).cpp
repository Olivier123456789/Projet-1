#include <iostream>
#include <string>

struct Personnage {
	std::string nom;
	int yhero = 0;
	int xhero = 0;
};
enum tile_type {
	ground = 0,
	water = 1,
	mountain = 2,
};
void afficher(int map[10][20], int yhero, int xhero) {
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 20; ++j) {
			if (map[i][j] == ground) {
				if (i == yhero && j == xhero) {
					std::cout << "H";
				}
				else {
					std::cout << ".";
				}
			}
			if (map[i][j] == water) {
				if (i == yhero && j == xhero) {
					std::cout << "H";
				}
				else {
					std::cout << "~";
				}
			}
			if (map[i][j] == mountain) {
				std::cout << "A";
			}
		}
		std::cout << "\n";
	}
};

int main() {
	int map[10][20] = {};
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
	Personnage* perso = new Personnage[6];
	perso[0] = { "Hero",5,0 };
	afficher(map, perso[0].yhero, perso[0].xhero);
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
		afficher(map, perso[0].yhero, perso[0].xhero);
		std::cin >> touche;
	}
}