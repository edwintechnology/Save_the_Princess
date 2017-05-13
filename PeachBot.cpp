#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
	This function grabs the strings from the vector grid
	uses the find function that is in the string library
	looks for m and p.
	
	once found, calculates the index position (from [][] to [])
	r * size + c
	
	stores into the reference variables pos_m and pos_p
*/
void find(int size, vector<string> grid, int &pos_m, int &pos_p){
	int m_pos = -1;
	int p_pos = -1;
	
	for (int i = 0; i < size; i++){
		size_t m = grid[i].find("m");
		if (m != string::npos){
			m_pos = i * size + (int)m;
		}
		
	}
	for (int i = 0; i < size; i++){
		size_t p = grid[i].find("p");
		if (p != string::npos){
			p_pos = i * size + (int)p;
		}
	}
	
	pos_m = m_pos;
	pos_p = p_pos;
}

void displayPathtoPrincess(int n, vector <string> grid){
	string * s = &grid[0];
	int pos_m = 0; 
	int pos_p = 0;
	
	find(n, grid, pos_m, pos_p);
	
	// for bot
	int m_col = pos_m % n;
	int m_row = (pos_m - m_col) / n;
	// for princess
	int p_col = pos_p % n;
	int p_row = (pos_p - p_col) / n;


	// the up-down movement
	if (p_row < m_row){
		while (m_row != p_row){
			m_row--;
			cout << "UP" << endl;
		}
	}
	else{
		while (m_row != p_row){
			m_row++;
			cout << "DOWN" << endl;
		}
	}
	// the left-right movement
	if (p_col < m_col){
		while (m_col != p_col){
			m_col--;
			cout << "LEFT" << endl;
		}
	}
	else {
		while (m_col != p_col){
			m_col++;
			cout << "RIGHT" << endl;
		}
	}
}

int main(void) {

	int m;
	vector <string> grid;

	cin >> m;

	for (int i = 0; i<m; i++) {
		string s; 
		cin >> s;
		grid.push_back(s);
	}

	displayPathtoPrincess(m, grid);

	return 0;
}