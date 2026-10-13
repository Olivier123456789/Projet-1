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
			if (map[i][j] == ground) {
				std::cout << ".";
			}
			if (map[i][j] == water) {
				std::cout << "~";
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
	for (int i = 4; i < 10; ++i) {
		for (int j = 12; j < 20; ++j) {
			map[i][j] = 1;
		}
	}
	for (int i = 8; i < 10; ++i) {
		for (int j = 6; j < 20; ++j) {
			map[i][j] = 2;
		}
	}
	afficher(map);
}
