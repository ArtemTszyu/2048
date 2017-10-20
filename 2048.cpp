#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void vlevo(int zone[4][4]) {
	for (int x = 0; x<4; x++) {
		int n = 0;
		for (int y = 0; y < 4; y++) {
			if (zone[x][y] != 0) { 
			zone[x][n] = zone[x][y]; if (n != y) zone[x][y] = 0; n++; 
			} 
		}
		for (int y = 0; y<4; y++) {
			if ((zone[x][y] == zone[x][y + 1]) && (zone[x][y] != 0)) {
			zone[x][y] += zone[x][y + 1]; zone[x][y + 1] = 0; 
			} 
		}
		for (int y = 0; y<3; y++) {
		 	if (zone[x][y] == 0) {
			zone[x][y] = zone[x][y + 1]; zone[x][y + 1] = 0; 
			} 
		}
	}
}

void vpravo(int zone[4][4]) {
	for (int x = 0; x<4; x++) {
		int n = 3;
		for (int y = 3; y > -1; y--) {
		 	if (zone[x][y] != 0) { 
			zone[x][n] = zone[x][y]; if (n != y) zone[x][y] = 0; n--; 
			} 
		}
		for (int y = 3; y > -1; y--) {
		 	if ((zone[x][y] == zone[x][y - 1]) && (zone[x][y] != 0)) {
			zone[x][y] += zone[x][y - 1]; zone[x][y - 1] = 0; 
			} 
		}
		for (int y = 3; y > 0; y--) {
		 	if (zone[x][y] == 0) {
			zone[x][y] = zone[x][y - 1]; zone[x][y - 1] = 0;
			} 
		}
	}	
}

void vverh(int zone[4][4]) {
	for (int x = 0; x<4; x++) {
		int n = 0;
		for (int y = 0; y < 4; y++) { 
			if (zone[y][x] != 0) { 
			zone[n][x] = zone[y][x]; if (n != y) zone[y][x] = 0; n++;
			} 
		}
		for (int y = 0; y<4; y++) { 
			if ((zone[y][x] == zone[y + 1][x]) && (zone[y][x] != 0)) {
			zone[y][x] += zone[y + 1][x]; zone[y + 1][x] = 0;
			} 
		}
		for (int y = 0; y<3; y++) {
			if (zone[y][x] == 0) {
			zone[y][x] = zone[y + 1][x]; zone[y + 1][x] = 0; 
			} 
		}
	}
}

void vniz(int zone[4][4]) {
	for (int x = 0; x<4; x++) {
		int n = 3;
		for (int y = 3; y > -1; y--) {
			if (zone[y][x] != 0) {
			zone[n][x] = zone[y][x]; if (n != y) zone[y][x] = 0; n--;
			} 
		}
		for (int y = 3; y > -1; y--) { 
			if ((zone[y][x] == zone[y - 1][x]) && (zone[y][x] != 0)) { 
			zone[y][x] += zone[y - 1][x]; zone[y - 1][x] = 0;
			} 
		}
		for (int y = 3; y > 0; y--) {
			if (zone[y][x] == 0) {
			zone[y][x] = zone[y - 1][x]; zone[y - 1][x] = 0;
			} 
		}
	}
}

void print(int zone[4][4]) {
	for (int y = 0; y < 4; y++){
		for (int x = 0; x < 4; x++) {
			if (zone[y][x] != 0) cout << zone[y][x];
			else cout << '*';
			}
	cout << endl;
	}
	cout << endl;
}

bool read(int matrix[4][4]) {
	bool result = true;
	for (int y = 0; y<4; y++) {
		string string;
		getline(cin, string);
		istringstream stream(string);
		for (int x = 0; x < 4; ++x) {
			if (!(stream >> matrix[y][x])) {
				result = false;
				break;
				}
			}
		}
	return result;
}

int main() {
	int zone[4][4];
	char znak;
	if (readpole(zone)) {
		for (; cin >> znak;) {
			switch (znak) {
			case'h': { vlevo(zone); printpole(zone); break; }
			case 'l': { vpravo(zone); printpole(zone); break; }
			case 'k': { vverh(zone); printpole(zone); break; }
			case 'x': { vniz(zone); printpole(zone); break; }
			default: { cout << "Error" << endl; break; }
			}
		}
	}
	else { cout << "Error" << endl; return 0; }
}
