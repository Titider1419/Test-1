#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<char> > Matriu;
typedef vector< vector<int> > Matriuent;

void mostrar_tauler(Matriu &mat,unsigned int &fil, unsigned int &col, Matriuent &hor, Matriuent &ver, unsigned int &m){
	cout << " ";
	for(unsigned int i = 0; i<col; ++i){
		cout << "  " << i+1;
	}
	cout << endl;
	cout << "   ";
	for(unsigned int i = 0; i<col; ++i){
		if (i+1<col) cout << "---";
		else cout << "--";
	}
	cout << endl;
	for(unsigned int i = 0; i<fil; ++i){
		if (i+1<10) cout << i+1 << " |";
		else cout << i+1 << "|";
		for(unsigned int j=0; j<col; ++j){
			if(j+1<col) cout << mat[i][j] << "  ";
			else cout << mat[i][j];
		}
		cout << " |";
		for(unsigned int j=0; j<hor[i].size(); ++j){
			if (j+1 < hor[i].size()) cout << hor[i][j] << " ";
			else cout << hor[i][j];
		}
		cout << endl;
	}
	cout << "   ";
	for(unsigned int i = 0; i<col; ++i){
		if (i+1<col) cout << "---";
		else cout << "--";
	}
	cout << endl;
	for(unsigned int j = 0; j<m; ++j){
		cout << " ";
		for(unsigned int i = 0; i<col; ++i){
			if (ver[i][j] != 0) cout << "  " << ver[i][j];
			else cout << "   ";
		}
		cout << endl;
	}
	cout << endl;
}

int main(){
	unsigned int files, columnes;
	cin >> files >> columnes;
	Matriu tauler(files, vector<char>(columnes, '.'));
	Matriuent pistes_hor(files, vector<int>());
	for(unsigned int i=0; i<files; ++i){
		unsigned int n, m;
		cin >> n;
		for(unsigned int j=0; j<n; ++j){
			cin >> m;
			pistes_hor[i].push_back(m);
		}
	}
	Matriuent pistes_ver(files, vector<int>());
	unsigned int max = 0;
	for(unsigned int i=0; i<columnes; ++i){
		unsigned int n, m;
		cin >> n;
		if (n>max) max = n;
		for(unsigned int j=0; j<n; ++j){
			cin >> m;
			pistes_ver[i].push_back(m);
		}
	}
	cout << pistes_ver.size() << endl;
	mostrar_tauler(tauler, files, columnes, pistes_hor, pistes_ver, max);
}
