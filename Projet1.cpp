#include <iostream>
#include <string>

enum tile_type {
	ground = 0,
	water = 1,
	mountain = 2,
};
void afficher(int map[10][20]) {
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 20; ++j) {
			if (map[i][j] == 0) {
				std::cout << ".";
			} 
			if (map[i][j] == 1) {
				std::cout << "~";
			}
			if (map[i][j] == 2) {
				std::cout << "A";
			}
		}
		std::cout<<"\n";
	}
};

int main() {
	int map[10][20] = {};
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 20; ++j) {
			if (i == 0) {
				map[i][j] = 0;
			}
			if (i == 1) {
				map[i][j] = 1;
			}
			else {
				map[i][j] = 2;
			}
		}
	}

	std::cout << map[10][20];
}
	