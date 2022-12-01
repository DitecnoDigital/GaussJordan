#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

char variables[] = {'p','q','s','t','u','v','w','x','y','z'};
char eleccion;
int n;
float aux;
int main(){   
    //Establecer precisión y escribir valores de punto flotante en notación de punto fijo
    cout<< setprecision(3)<< fixed;

	cout<<"----------------------------------------------------"<<endl;
    cout<<"---------Resolucion de Sitemas de Ecuaciones--------"<<endl;
    cout<<"----------------------------------------------------"<<endl;
    cout<<"Ingrese la cantidad de Incognitas: ";
	cin>>n;
    float a[n+1][n+2], x[n+1];

    //Leyendo los datos de incognitas e resultados de la matriz
	for(int i = 1; i <= n; i++){
        cout<<"\nEcuacion "<<i<<endl;
		for(int j = 1; j <= n+1; j++){
			if(j <= n){
                cout<<"     f"<<i<<" ("<<variables[j]<<") = ";
            }else{
                cout<<"     Resultado = ";
            }
            cin>>a[i][j];
            while(a[i][j] == 0 && i == j){
                cout<<"Error. El valor de esta incognita no puede ser 0."<<endl;
                cout<<"Desea corregir el error (S/N): ";
                cin>>eleccion;
                if(eleccion == 'S' || eleccion == 's'){
                    cout<<"Ingrese Correctamente= ";
                    cin>>a[i][j];
                }else{
                    return 0;
                }
            }
		}
	}
    //Aplicando la Eliminacion de Gauss Jordan
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i!=j){
                aux = a[j][i]/a[i][i];
                for(int k = 1; k <= n+1; k++){
                    a[j][k] = a[j][k] - aux*a[i][k];
                }
            }
        }
    }
    
    //Mostrando Soluciones
    cout<<"\nSoluciones: "<<endl;
    for(int i = 1; i <= n; i++){
        cout<<"("<<variables[i]<<") = "<<a[i][n+1]/a[i][i]<<endl;
    }
    return 0;
}