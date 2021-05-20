#include "stdc++.h"
#include <sys/stat.h>

using namespace std;

inline bool exists (const string& name) {
  struct stat buffer;   
  return (stat (name.c_str(), &buffer) == 0); 
}

void calcularCoef(const string &filepath){
	double somatorioPonderado=0;
	double somatorio=0;
	int quantidade=0;
	double somatorioPesos=0;
	ifstream file(filepath);
    if(file.is_open()){
    	string materia;
    	getline(file,materia); // remove header
    	while(file.good()){
			materia="";
    		int peso, nota;
    		file>>materia>>peso>>nota;
			if(!materia.empty()){ 
				if (materia.rfind("_ignore_", 0) != 0) {
					somatorioPesos+=peso;
					somatorio+=nota;
					somatorioPonderado+=nota*peso;
					quantidade++;
				}	
			}
    	}
		file.close();
    }
    double coeficiente=somatorioPonderado/somatorioPesos;
    double media=somatorio/quantidade;
	cout<<"Seu coeficiente é: "<<coeficiente<<" - média: "<<media<<" - materias: "<<quantidade<<endl;
}

int main(){
	calcularCoef("notas.txt");
	if (exists("notas_corretas_sem_erro.txt")){
		cout<<"\nDeconsiderando pontos explicitamente errados:"<<endl;
		calcularCoef("notas_corretas_sem_erro.txt");
	}
	return 0;
}