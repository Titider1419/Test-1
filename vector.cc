#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<char> > Matriu;
typedef vector< vector<int> > Matriuent;

void mostrar_tauler(Matriu &mat,unsigned int &fil, unsigned int &col, Matriuent &hor, Matriuent &ver, unsigned int &m){
	cout << "  ";
	for(unsigned int i = 0; i<col; ++i){
		//inv: genera el nombre de columnes que hi ha( en fila )
		cout << "  " << i+1;
	}
	cout << " ";
	cout << endl;
	cout << "    ";
	for(unsigned int i = 0; i<col; ++i){
		//Inv: genera una secuencia de "-", genera de "---" cada vegada
		//exeptuant el ultim que genera "--" (part superior)
		if (i+1<col) cout << "---";
		else cout << "--";
	}
	cout << endl;
	for(unsigned int i = 0; i<fil; ++i){
		
		if (i+1<10) cout << " " << i+1 << " |";
		//numero ini de la fila( columna)
		else cout << i+1 << " |";
		//"" ultim
		for(unsigned int j=0; j<col; ++j){
			//genera el contingut de la matri (int main-->Taula('.'))
			if(j+1<col) cout << mat[i][j] << "  ";
			else cout << mat[i][j];
		}
		cout << " |";
		for(unsigned int j=0; j<hor[i].size(); ++j){
			//inv: genera les piste horizontals (part de la dreta) 
			//int main(pistes_hor)
			if (j+1 < hor[i].size()) cout << " " << hor[i][j];
			else cout <<" "<< hor[i][j];
		}
		cout << endl;
	}
	cout << "    ";
	for(unsigned int i = 0; i<col; ++i){
		//Inv: genera una secuencia de "-", genera de "---" cada vegada
		//exeptuant el ultim que genera "--" (part inferior)
		if (i+1<col) cout << "---";
		else cout << "--";
	}
	cout << endl;
	for(unsigned int j = 0; j<m; ++j){
		//inv: max 
		//inv: genera les piste de la part inferior
		cout << "  ";
		for(unsigned int i = 0; i<col; ++i){
			//inv: columne, piste_ver
			if (j < ver[i].size()) cout << "  " << ver[i][j];
			else cout << "   ";
		}
		cout << endl;
	}
	cout << endl;
}

bool solucio(Matriu &mat,unsigned int &fil, unsigned int &col, Matriuent &hor, Matriuent &ver, unsigned int &m){
	bool res=false;
	
	int v_fil=hor[0].size();
    int v_col=ver[0].size();
    vector<int> res_pistaF(v_fil);
	vector<int> res_pistaC(v_col);
	
	unsigned int i=0;
	unsigned int j=0;
	int x=0;
	int y=0;
	int b=0;
	int count_fila=0;
		int count_columna=0;
	while(i<fil and not res){
		
		while(j<col and not res){
		if(mat[i][j]=='X'){
			++count_fila;
			cout<<"count:"<<count_fila<<endl;
			}
			
	    if(mat[j][i]=='X'){
			++count_columna;
			cout<<"count:"<<count_columna<<endl;
			}
		else if(j>0){
			 if (mat[i][j]=='.'){
			    if (mat[i][j-1]=='X'){
			res_pistaF[x]=count_fila;
			cout<<"preH"<<res_pistaF[x] <<endl;
			++x;
	    	   }
	    	   count_fila=0;
		    }
			 else if (mat[j][i]=='.'){
			 if( mat[j-1][i]=='X'){
			res_pistaC[y]=count_columna;
			cout<<"preC"<<res_pistaC[y] <<endl;
			++y;
	    	}
	    	count_columna=0;
		}
		}
	    	++j;
	    	
		}
		res_pistaC[y]=count_columna;
		cout<<"endC"<<res_pistaC[y] <<endl;
		res_pistaF[x]=count_fila;
		cout<<"endF"<<res_pistaF[x] <<endl;
	
		x=y=0;
		int a=0;
		while(a<v_fil and not res){
			cout<<"vector:"<<res_pistaC[a] <<endl;
			cout<<"pistaH:"<<hor[b][a]<<" "<<b<<" "<<a<<endl;
			cout<<"vector2:"<<res_pistaF[a]<<endl;
			cout<<"pistaV:"<<ver[b][a]<<" "<<b<<" "<<a<<endl;
			
			if(res_pistaF[a]!=hor[b][a]){
				res=true;
				}
				else if (res_pistaC[a]!=ver[b][a]){
				res=true;
				}
				++a;
			}
			++i;
			++b;
		count_columna=0;
		count_fila=0;
	}
	return not res;
}

int main(){
	unsigned int files, columnes;
	cin >> files >> columnes;
	Matriu tauler(files, vector<char>(columnes, '.'));
	Matriuent pistes_hor(files, vector<int>());
	for(unsigned int i=0; i<files; ++i){
		//inv: llegeix les pistes, n(nombre de pistes), m(valor de la pista)
		//( pistes_hor[files][n] = m)
		unsigned int n, m;
		cin >> n;
		for(unsigned int j=0; j<n; ++j){
			//Inv:guarda el valor de les piste en el vector pistes_hor[n]
			cin >> m;
			pistes_hor[i].push_back(m);
		}
	}
	Matriuent pistes_ver(columnes, vector<int>());
	unsigned int max = 0;
	//max??
	for(unsigned int i=0; i<columnes; ++i){
		//inv: llegeix la segona mitat de les pistes i els guarda en
		// la matriu pistes_ver[columnes][n]
		unsigned int n, m;
		cin >> n;
		if (n>max) max = n;
		for(unsigned int j=0; j<n; ++j){
			//Inv:guarda el valor de les piste m en el vector pistes_hor[i][n]
			cin >> m;
			pistes_ver[i].push_back(m);
		}
	}
	mostrar_tauler(tauler, files, columnes, pistes_hor, pistes_ver, max);
	bool Z = false, resolt = false;
	int contador=0;
	while(not resolt and not Z){
		//inv: mentres que no llegeixi una Z, o resolgi el nonograma
		//realitzara la operacio seguents: si entra una A posa una 'x' en 
		// la matriu tauler [fil1-1][col1-1] i en cas E posa una '.'
		//  si entra una S executa la acio mostra_tauler  
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
				 //inv: Marca totes les caselles del tauler[fil1] [col1] fins
				 //tauler [fil2] [col2] amb 'X' i suma 1 al contador
            for (unsigned int j = col1; j <= col2; ++j) {
				//inv:
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
				 //inv: Marca totes les caselles del tauler[fil1] [col1] fins
				 //tauler [fil2] [col2] amb '.' i suma 1 al contador
            for (unsigned int j = col1; j <= col2; ++j) {
				//inv:
                tauler[i-1][j-1] = '.';
                
                        }
                }
                ++contador;
	    }
        else if (operacio == 'R'){
			for (unsigned int i = 0; i <= files-1; ++i) {
				 //inv: Marca totes les caselles del tauler[1] [1] fins
				 //tauler [files-1] [columnes-1] amb '.' i canvia el
				 //valor del contador a 0
            for (unsigned int j = 0; j <= columnes-1; ++j) {
                tauler[i][j] = '.';
                        }
                }
			contador=0;
			}
		
		else if (operacio == 'S'){
			mostrar_tauler(tauler, files, columnes, pistes_hor, pistes_ver, max);
			
			if(solucio (tauler, files, columnes, pistes_hor, pistes_ver, max )){
				cout<<"solucio"<<endl;
				}
						else if(not solucio (tauler, files, columnes, pistes_hor, pistes_ver, max )){
				cout<<"no solucio"<<endl;
				}
			}
		 
		else if (operacio == 'Z') Z = true;
	}
	cout<<"Nombre de moviments: "<<contador<<endl;
}
