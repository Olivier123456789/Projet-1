#include <iostream>
#include <string>

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
};
void afficher(int map[10][20], Personnage* perso) {
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 20; ++j) {


			//for pour parcourir pers
			//mettre un bool a true si perso sur la case
			// premier if de a haine suivante test le bool et continue si vrai
			if (map[i][j] == ground) {
				int preuve = 0;
				for (int a = 1; a < 6; ++a) {
					if (perso[a].xhero == j && perso[a].yhero == i) {
						std::cout << "X";
						preuve = +1;
					}

				}
				if (i == perso[0].yhero && j == perso[0].xhero && preuve == 0) {
					std::cout << perso[0].nom;
				}
				else if (preuve==0){
					std::cout << ".";
				}
			}
				else if (map[i][j] == water) {
				int preuve = 0;
				for (int a = 1; a < 6; ++a) {
					if (perso[a].xhero == j && perso[a].yhero == i) {
						std::cout << "X";
						preuve = +1;
					}
				}
				if (i == perso[0].yhero && j == perso[0].xhero && preuve == 0) {
						std::cout << perso[0].nom;
					}
					else if (preuve ==0) {
						std::cout << "~";
					}
					
			}
			else if (map[i][j] == mountain) {
				std::cout << "A";
			}
		}
		std::cout << '\n';
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
	Personnage perso[6] = {{"H",5,0,1},{"X",0,0},{"X",0,1},{"X",0,2},{"X",0,3},{"X",0,4}};
	
	afficher(map, perso);
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
		for (int a = 1; a < 6; ++a) {
			if (perso[0].yhero == perso[a].yhero && perso[0].xhero == perso[a].xhero) {
				perso[0].vie -= 1;
			}
			if (perso[0].vie == 0) {
				std::cout << "GAME OVER";
				return 0;
			}
		}
		afficher(map, perso);
		std::cin >> touche;
	}
}