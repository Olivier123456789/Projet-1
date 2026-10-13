#include <iostream>
#include <string>


enum tile_type {
	ground = 0,
	water = 1,
	mountain = 2,
	hero = 3,
};
void afficher(int map[10][20],int yhero,int xhero) {
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 20; ++j) {
			if (map[i][j] == ground) {
				if (i == yhero && j == xhero) {
					std::cout<<"H";
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
		int yhero = 5;
		int xhero = 0;
		afficher(map, yhero, xhero);
		char touche = 'm';
		std::cin >> touche;
		while (touche != 'x' ) {
			if (touche == 'z' || touche == 'Z') {				
				yhero -= 1;
				if (map[yhero][xhero] == 2) {
					yhero += 1;
				}
			}
			if (touche == 'q' || touche == 'Q') {				
				xhero -= 1;
				if (map[yhero][xhero] == 2) {
					xhero += 1;
				}
			}
			if (touche == 's' || touche == 'S') {			
				yhero += 1;
				if (map[yhero][xhero] == 2) {
					yhero -= 1;
				}
			}
			if (touche == 'd' || touche == 'D') {			
				xhero += 1;
				if (map[yhero][xhero] == 2) {
					xhero -= 1;
				}
			}
			if (xhero < 0) {
				xhero += 1;
			}
			if (xhero == 20) {
				xhero -= 1;
			}
			if (yhero < 0) {
				yhero += 1;
			}
			if (yhero == 10) {
				yhero -= 1;
			}
			afficher(map, yhero, xhero);
			std::cin >> touche;
		}
}
