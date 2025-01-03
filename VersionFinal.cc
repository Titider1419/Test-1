#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<char> > Matriu;
typedef vector< vector<int> > Matriuent;

//Mostra per la sortida el tauler del nonograma.
//Pre: "mat" és una matriu de caracters, "fil" és el nombre de files pel
//     pel qual està format la matriu "mat", "col" és el nombre de columnes
//     pel qual està format la matriu "mat", "hor" és una matriu d'enters
//     que conté les pistes horitzontals, "ver" és una matriu d'enters que
//     conté les pistes verticals i "m" és el nombre de elements que conté
//     la fila més gran de la matriu "ver".
//Post: mostra la matriu "mat" amb les pistes de les matrius "ver" i
//      "hor" i numeros que indiquen les cordenades.
void mostrar_tauler(Matriu &mat,unsigned int &fil, unsigned int &col, Matriuent &hor, Matriuent &ver, unsigned int &m){
	cout << "    ";
	for(unsigned int i = 0; i<col; ++i){
		//Inv: mostra el valor de l'eix de les columnes
		if (i < col-1){
			if (i<9) cout << i+1 << "  ";
			else cout << i+1 << " ";
		}
		else cout << i+1 << " ";
	}
	cout << endl;
	cout << "    ";
	for(unsigned int i = 0; i<col; ++i){
		//Inv: genera una secuencia de guions que separen el
		//    nombre de columnes amb la matriu "mat"
		if (i+1<col) cout << "---";
		else cout << "--";
	}
	cout << endl;
	for(unsigned int i = 0; i<fil; ++i){
		//Inv: mostra el valor de l'eix de les files, i
		//    separa aquests nombres i la matriu "mat" amb unes barres.
		//    A més a més mostra el valor de totes les caselles amb
		//    amb índex de fila menor a "i" de la matriu "mat".
		//    Després separa aquestes files de les pistes horitzontals
		//    amb una barra i finalment mostra el valor de les
		//    caselles amb índex de fila menor a "i" de la matriu "hor"
		if (i+1<10) cout << " " << i+1 << " |";
		else cout << i+1 << " |";
		for(unsigned int j=0; j<col; ++j){
			//Inv: mostra el valor de totes les caselles amb
			//    amb índex de fila menor que "i" de la matriu "mat" 
			//    i també les caselles amb índex de fila igual a "i"
			//    i índex de columna menor que "j" de la matriu "mat".
			if(j+1<col) cout << mat[i][j] << "  ";
			else cout << mat[i][j];
		}
		cout << " |";
		for(unsigned int j=0; j<hor[i].size(); ++j){
			//Inv: mostra el valor de totes les caselles amb
			//    amb índex de fila menor que "i" de la matriu "hor" 
			//    i també les caselles amb índex de fila igual a "i"
			//    i índex de columna menor que "j" de la matriu "hor".
			if (j+1 < hor[i].size()) cout << " " << hor[i][j];
			else cout <<" "<< hor[i][j];
		}
		cout << endl;
	}
	cout << "    ";
	for(unsigned int i = 0; i<col; ++i){
		//Inv: genera una secuencia de guions que separen les pistes
		//    verticals amb la matriu "mat"
		if (i+1<col) cout << "---";
		else cout << "--";
	}
	cout << endl;
	for(unsigned int j = 0; j<m; ++j){
		//Inv: mostra el valor de totes les caselles amb
		//    amb índex de columna menor que "j" de la matriu "ver"
		cout << "    ";
		for(unsigned int i = 0; i<col; ++i){
			//Inv: mostra el valor de totes les caselles amb
			//    amb índex de columna menor que "j" de la matriu "ver" 
			//    i també les caselles amb índex de columna igual a "j"
			//    i índex de fila menor que "i" de la matriu "ver"
			if (j < ver[i].size()){
				if(i < col-1){
					if(ver[i][j] < 10) cout << ver[i][j] << "  ";
					else cout << ver[i][j] << " ";
				}
				else cout << ver[i][j];
			}
			else {
				if (i < col-1) cout << "   ";
				else cout << "  ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

//Comprova que la matriu "mat" conté totes les "X" posades de manera que
//  compleixi les pistes verticals i horitzontals retornant true; en
//  cas contrari retorna false
//Pre: "mat" és una matriu de caracters, "fil" és el nombre de files pel
//     pel qual està format la matriu "mat", "col" és el nombre de columnes
//     pel qual està format la matriu "mat", "hor" és una matriu d'enters
//     que conté les pistes horitzontals i "ver" és una matriu d'enters que
//     conté les pistes verticals
//Post: retorna true si les caselles de la matriu "mat" compleix totes
//    totes les pistes, en cas contrari retorna true.
bool comprovacio(Matriu &mat, unsigned int &fil, unsigned int &col, Matriuent &hor, Matriuent &ver){
    bool trobat = false;
	unsigned int i = 0;
	while(not trobat and i < fil){
		//Inv: trobat és true si i només si la mida d'alguna sequencia 
		//  de les caselles, que contenen una "X", amb index de fila 
		//  menor que "i" diferent a les pistes horitzontals
		unsigned int k = 0;
		unsigned int j = 0;
		bool marcat = false;
		int cont = 0;
		while (not trobat and j<col){
			//Inv:trobat és true si i només si la mida d'alguna
			//  sequencia les caselles, que contenen una "X", amb
			//  índex de fila que "i" diferent a les pistes horitzontals
			//  i també caselles amb índex de fila igual a "i"
			//  i índex columna menor que "j". A més a més "cont" conté
			//  la mida de l'última sequencia d'aquestes que finalitzi 
			//  amb una "X" i "marcat" si hi ha hagut alguna
			//  casella amb "X" en una seqüencia sense ".".
			if(mat[i][j] == 'X'){
				marcat = true;
				++cont;
			}
			else if (marcat and k<hor[i].size()){
				if(cont != hor[i][k]) trobat = true;
				cont = 0;
				marcat = false;
				++k;
			}
			++j;
		}
		if (k<hor[i].size()){
			if(cont != hor[i][k]) trobat = true;
		}
		++i;
	}
	i = 0;
	while(not trobat and i < col){
		//Inv: trobat és true si i només si la mida d'alguna sequencia 
		//  de les caselles, que contenen una "X", amb index de columna 
		//  menor que "i" diferent a les pistes horitzontals
		unsigned int j = 0;
		bool marcat = false;
		int cont = 0;
		unsigned int k = 0;
		while (not trobat and j<fil){
			//Inv:trobat és true si i només si la mida d'alguna
			//  sequencia les caselles, que contenen una "X", amb
			//  índex de columna que "i" diferent a les pistes verticals
			//  i també caselles amb índex de columna igual a "i"
			//  i índex fila menor que "j". A més a més "cont" conté
			//  la mida de l'última sequencia d'aquestes que finalitzi 
			//  amb una "X" i "marcat" si hi ha hagut alguna
			//  casella amb "X" en una seqüencia sense ".".
			if(mat[j][i] == 'X'){
				marcat = true;
				++cont;
			}
			else if (marcat and k<ver[i].size()){
				if(cont != ver[i][k]) trobat = true;
				cont = 0;
				marcat = false;
				++k;
			}
			++j;
		}
		if (k<ver[i].size()){
			if(cont != ver[i][k]) trobat = true;
		}
		++i;
	}
	return not trobat;
}

int main(){
	unsigned int files, columnes;
	cin >> files >> columnes;
	Matriu tauler(files, vector<char>(columnes, '.'));
	Matriuent pistes_hor(files, vector<int>());
	for(unsigned int i=0; i<files; ++i){
		//Inv: totes les caselles amb índex de fila menor a "i" estan 
		//    omplertes amb nombres naturals llegits de teclat.
		unsigned int n, m;
		cin >> n;
		for(unsigned int j=0; j<n; ++j){
			// Inv: totes les caselles amb índex de fila menor que "i" i 
			//    les caselles amb índex de fila igual a "i" i índex
			//    de columna menor que "j" estan amb nombres naturals 
			//    llegits de teclat.
			cin >> m;
			pistes_hor[i].push_back(m);
		}
	}
	Matriuent pistes_ver(columnes, vector<int>());
	unsigned int max = 0;
	for(unsigned int i=0; i<columnes; ++i){
		//Inv: totes les caselles amb índex de fila menor a "i" estan 
		//    omplertes amb nombres naturals llegits de teclat.
		unsigned int n, m;
		cin >> n;
		if (n>max) max = n;
		for(unsigned int j=0; j<n; ++j){
			// Inv: totes les caselles amb índex de fila menor que "i" i 
			//    les caselles amb índex de fila igual a "i" i índex
			//    de columna menor que "j" estan amb nombres naturals llegits 
			//    de teclat.
			cin >> m;
			pistes_ver[i].push_back(m);
		}
	}
	mostrar_tauler(tauler, files, columnes, pistes_hor, pistes_ver, max);
	bool Z = false, resolt = false;
	int contador=0;
	while(not resolt and not Z){
		//Inv: "Z" és true si i només si li arriba la lletra Z per
		//   teclat; en cas contrari es false. "Resolt" és trué si i
		//   només si comprovació retorna true; en cas contrari és
		//   false. "Contador" conté el nombre de moviments que s'ha
		//   realitzat
		char operacio;
		cin >> operacio;
		unsigned int fil1, col1, fil2, col2;
		if (operacio == 'A'){
			cin >> fil1 >> col1;
			tauler[fil1-1][col1-1] = 'X';
			++contador;
		}
		else if (operacio == 'B'){
			cin >> fil1 >> col1>> fil2 >>col2;
			for (unsigned int i = fil1; i <= fil2; ++i) {
				 //Inv: Marca totes les caselles amb índex de fila menor
				 //   que "i" amb una "X"
                for (unsigned int j = col1; j <= col2; ++j) {
					//Inv: Marca totes les caselles amb índex de fila
					//   menor que "i" amb una "X" i també les caselles
					//   amb índex de fila igual a "i" i índex de
					//   columna menor que "j"
                    tauler[i-1][j-1] = 'X';
                }
        }
         ++contador;
		}
		
		
		else if (operacio == 'E'){
			cin >> fil1 >> col1;
			tauler[fil1-1][col1-1] = '.';
			++contador;
		}
		else if (operacio == 'F'){
			cin >> fil1 >> col1>> fil2 >>col2;
			for (unsigned int i = fil1; i <= fil2; ++i) {
				 //Inv: Marca totes les caselles amb índex de fila menor
				 //   que "i" amb una "."
                for (unsigned int j = col1; j <= col2; ++j) {
					//Inv: Marca totes les caselles amb índex de fila
					//   menor que "i" amb una "." i també les caselles
					//   amb índex de fila igual a "i" i índex de
					//   columna menor que "j"
                    tauler[i-1][j-1] = '.';
                    }
                }
                ++contador;
	    }
        else if (operacio == 'R'){
			for (unsigned int i = 0; i <= files-1; ++i) {
				 //Inv: Marca totes les caselles amb índex de fila menor
				 //   que "i" amb una "."
                for (unsigned int j = 0; j <= columnes-1; ++j) {
					//Inv: Marca totes les caselles amb índex de fila
					//   menor que "i" amb una "." i també les caselles
					//   amb índex de fila igual a "i" i índex de
					//   columna menor que "j"
                    tauler[i][j] = '.';
					}
                }
			contador=0;
			}
		else if (operacio == 'S') mostrar_tauler(tauler, files, columnes, pistes_hor, pistes_ver, max);
		else if (operacio == 'Z') Z = true;
		if(comprovacio(tauler, files, columnes, pistes_hor, pistes_ver)){
			resolt = true;
			mostrar_tauler(tauler, files, columnes, pistes_hor, pistes_ver, max);
		}
	}
	if (resolt) cout << "Enhorabona! Has resolt el nonograma." << endl;
	else cout << "Has sortit del joc. Fins aviat!" << endl;
	cout<<"Nombre de moviments: "<<contador<<endl;
}
