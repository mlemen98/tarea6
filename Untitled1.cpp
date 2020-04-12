#include<iostream>
#include<stdlib.h>
#include<string.h>
#include <fstream>
using namespace std;

void menu();
void crear_pedido();

struct Datos{
	string dia,mod,cat;
}datos;

int main(){
	menu();
	
	system ("pause");
	return 0;
	
}
void menu(){
	int opcion;
	
	do{
		
		cout<<"\tMENU"<<endl;
		cout<<"1. Creacion de solicitud de modelos"<<endl;
		cout<<"2. Modificacion del pedido de modelo"<<endl;
		cout<<"3. Eliminacion de pedido"<<endl;
		cout<<"4. Reporte de ventas"<<endl;
		cout<<"5. Salir"<<endl;
		cout<<"Opcion: ";
		cin>>opcion;
		
		switch(opcion){
			case 1: crear_pedido();
			cout<<"\n";
			system("pause");
			
			break;
		}
		system("cls");
	}while(opcion !=5);
}
void crear_pedido(){
	ofstream archivo;
	char rpt;
	
	archivo.open("TiendaModelos.txt",ios::out);
	
	if(archivo.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);	
	}
	
	archivo<<"\tTienda Modelos"<<endl;
	
	do{
		fflush(stdin);
		cout<<"Digite el dia:";
		getline(cin,datos.dia);
		cout<<"Digite el tipo de modelo:";
		getline(cin,datos.mod);
		cout<<"Digite el monto:";
		getline(cin,datos.cat);
		cout<<"\n";
		
		
		archivo<<"Dia"<<datos.dia<<endl;
		archivo<<"Modelo"<<datos.mod<<endl;
		archivo<<"Monto"<<datos.cat<<endl<<endl;
		
		cout<<"Desea solicitar mas pedidos(s\n): ";
		cin>>rpt;	
	}while(rpt== 'S' || rpt == 's');
	
	archivo.close();	
}
