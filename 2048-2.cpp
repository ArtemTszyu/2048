#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
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

void stndzone(int zone [4] [4]){
	for (int y=0; y<4; y++){
		for (int x=0; x<4; x++){
			int a=a+1;
			zone [x][y]=0;
			if (a==5||a==9||a==13){cout<<endl;
				}		
			}
		}
	}
	void zapolnenie(int zone [4] [4]){
    int	x = rand() % 4;
	int y = rand() % 4;
	int	b = rand() % 5;
	if (zone[x][y] == 0 && b == 1 )
	{zone[x][y] =4;}
	 else if (zone[x][y] ==0 )
	 {zone[x][y] = 2;}
	 else zapolnenie(zone);
    
 
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
void save(int zone0[4][4], int zone[4][4]) {
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++)
		zone0[x][y] = zone[x][y];
	}
}
int check(int zone0[4][4], int zone[4][4]) {
	int r = false;
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++)
			if (zone0[x][y] != zone[x][y]) return r = false;
			else r = true;
	}
	return r;
}
int block(int zone[4][4]) 
{
	int v = false;
	for (int x = 0; x<4; x++) {
		for (int y = 0; y<4; y++)
			if (zone[x][y] == zone[x + 1][y] || zone[x][y] == zone[x][y + 1] || zone[x][y] == 0) {
				v = true;
				break;
			}
		if (v == true) break;
	}

	if (v != true) {return -1; }
	return 0;
}



int main() {
	int zone [4][4];
	int zone0[4][4];
	srand(time(NULL));
	stndzone(zone);
	zapolnenie(zone);
	
	print (zone);
	

	char z;
		for (; cin >> z;) {
			block (zone);
			switch (z) {
				
			case'h': { vlevo(zone);  if (!(check(zone0, zone))) { zapolnenie(zone); } print(zone); break; }
			case 'l': { vpravo(zone);  if (!(check(zone0, zone))) { zapolnenie(zone); } print(zone); break; }
			case 'k': { vverh(zone);  if (!(check(zone0, zone))) { zapolnenie(zone); } print(zone); break; }
			case 'x': { vniz(zone);  if (!(check(zone0, zone))) { zapolnenie(zone); } print(zone); break; }
			default: { cout << "Error" << endl; break; }
			}
			save (zone0, zone);
		}
	}

