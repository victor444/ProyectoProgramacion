# ProyectoProgramacion
SOLITARIO

#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <ctime>
#include <conio.h>
using namespace std;

int ancho = 11;
int alto = 11;

int seleccionadoPalo[1];
int seleccionadoNumero[1];

int pila_mazo_palo[7][19];
int pila_mazo_numero[7][19];
/*int seleccionadoPalo[8][22];
int seleccionadoNumero[8][22];
*/

enum { BV = 179, ESD = 191, EII, BH = 196, EID = 217, ESI };
enum {CORAZON = 003, DIAMANTE, TREBOL, PICA};
enum {AS = 65, JACK = 74, REY, REYNA = 81};

int Baraja ();
int Marco(int,int);
int MazoCarta1 ();
int MazoCarta2 ();
int MazoCarta3 ();
int MazoCarta4 ();
int PilaMazo1 ();
int PilaMazo2 ();
int PilaMazo3 ();
int PilaMazo4 ();
int PilaMazo5 ();
int PilaMazo6 ();
int PilaMazo7 ();
int CartasAElegir ();

int Carta_reverso(int x,int y);

void gotoxy(int , int);
int MarcoVACIO (int x, int y);
void Tablero (int a[],int b[]);
int Seleccion (int x, int y);

void Barajar( int[][15], int[], int[]);
void PintarCarta (int x, int y, int orden);

int Semi_marco (int x, int y);
int semi_Seleccion (int x, int y);

void PintarCarta (int x, int y,int ordenP, int ordenN);

int main() 
{
	
    int cartas, x, y;
	bool game_over = false;
	bool copiado = false;
	
	int cards[7][15] = { {0, 0} };
	int a[53];
	int b[53];
	
	char tecla;
	
	int orden;
	
	srand(time(NULL));
	
	Barajar( cards, a, b);
	
	for(int j=1,i=1; j<=7; ++j,++i){// ESTE FOR ASIGNA LOS VALORES A LAS 7 PILAS DE CARTAS(el de abajo
		for(int k=1; k<=j; ++k){
			pila_mazo_palo[j][k] = a[i];
			pila_mazo_numero[j][k] = b[i];
			++i;
		}
	}
	//******************* for para hacer pruebas
	for(int j=0; j<=2; ++j){// ESTE FOR ASIGNA LOS VALORES A LAS 7 PILAS DE CARTAS(el de abajo
		for(int k=0; k<=19; ++k){
			cout<<pila_mazo_palo[j][k]<<endl;
			cout<<pila_mazo_numero[j][k]<<endl;
			cout << j <<" , " << k<< endl;
		}
	}
	system("pause");
	//*********************
	system("color 2F") ; // pinta de color verde   
	system("mode con lines=63 cols=92") ;  //MODIFICA TAMAÑO DEl EJECUTABLE
	
	Tablero(a, b); // se pinta el tablero
	/*x=15,y=2;
	c += 1;
	PintarCarta(x,y,a,b); //Llamada a función para pintar las cartas.*/
	  orden = 2;
	x=80;
	y=2;
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),78); //Pinta la seleccion color rojo
	semi_Seleccion (x,y);
	
//------------------------control de seleccion------------------------------------------
	while(!game_over){
		Sleep(300);
		if(kbhit()){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),47);
			semi_Seleccion (x,y);
			//MarcoVACIO (x,y); // limpia la seleccion

			tecla = getch ();
			if(tecla == 'a'){// SE PUEDE SIMPLIFICAR
				if (x == 15 || x == 28) x-=13;
				if (x == 41){
					if(y >= 14)x-=13;
					else x=15;
				} 
				if (x >= 54) x-=13;
			}
			if(tecla == 'd'){// SE PUEDE SIMPLIFICAR
				if (x >= 28 && x < 80) x+=13;
				if (x == 15){
					if(y >= 14)x+=13;
					else x=41;
				}
				if (x == 2) x+=13;
			}
			if(tecla == 'w'){// SE PUEDE SIMPLIFICAR
				if (y == 14){
					if (x == 28) x=15,y=2;
					else y=2;
				}
				if(y > 14) y-=2;
			}// SE PUEDE SIMPLIFICAR
			if(tecla == 's'){
				if (y > 2 && y < 50) y+=2;
				if (y == 2) y=14;
				//-------------------------------------------------------------------------------------
				/*
				for(int k=14,j=1; k <= 52; k+=2,j++){
					for(int l=2,i=1; l <= 80; l+=13,i++){
						if(x == l && y == k){
							if (pila_mazo_palo[i][j+1] == 0){
								if (y > 2 && y < 50) y+=2;
								if (y == 2) y=14;
							}
						}
					}
				}
				*/
				//---------------------------------------------------------------------------------------
			}
			if(tecla == 'f'){
				if(copiado == true){
					
					for(int k=14,j=1; k <= 52; k+=2,j++){
						for(int l=2,i=1; l <= 80; l+=13,i++){
							if(x == l && y == k){
								if(pila_mazo_palo[i][j] == 0 && pila_mazo_palo[i][j-1] !=0){
								// no esta condicionado para funcionar bien con la primera carta de un mazo
									pila_mazo_palo[i][j] = seleccionadoPalo[1];
									pila_mazo_numero[i][j] = seleccionadoNumero[1];
									PintarCarta(x,y,i,j);
									copiado = false;
									l = 80;
									k = 52;
								}
							}
						}
					}
					
					
				/*	if(x==15){ // ESTO SOLO SIRVE PARA COPIAR LA PRIMERA CARTA DE LA PILAMAZO1 :´(
						
						//PUEDO USAR ORDEN PARA ALGO QUE OLVIDE....... :´(
						pila_mazo_palo[2][orden] = seleccionadoPalo[1];
						pila_mazo_numero[2][orden] = seleccionadoNumero[1];
						cout << pila_mazo_palo[orden][orden] <<endl;
						cout << pila_mazo_numero[orden][orden] <<endl;
						
						//-------- se copio la carta seleccionada en el mazo donde se desea colocarla
						
						y+=4; // se baja dos posiciones para que la carta que se movio se imprima
						PintarCarta(x,y, 2,j); // se imprime la carta movida
						copiado = false; 
						
						// ----------- se pinta una zona vacia de donde se tomo la carta
						x=2,y=14;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),47);
						MarcoVACIO (x,y);
						Seleccion (x,y);
						
						// se regresa a la posicion donde se hizo el cambio de carta y se arregla el marco
						x=15,y=14;
						if(pila_mazo_palo[orden-1][orden-1] <= 4){
      						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),252); 
   						}else{
      						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
  						} 
						Semi_marco ( x,  y);
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),47);
						
						 //------- se borra la carta que se movio del mazo donde se habia tomado
						//pila_mazo_palo[1][1] = 0;
					}*/
				}else{// --------ESTE FOR RECUPERA EL VALOR DE LAS 7 PILAS DE CARTAS USANDO LA POSICION X, Y
					for(int k=14,j=1; k <= 52; k+=2,j++){
						for(int l=2,i=1; l <= 80; l+=13,i++){
							if(x == l && y == k){
								if(pila_mazo_palo[i][j] != 0){
									seleccionadoPalo[1] = pila_mazo_palo[i][j];
									seleccionadoNumero[1] = pila_mazo_numero[i][j];
									// la seleccion se queda con el valor anterior cuando se seleccona un valor cero
								}
							}
						}
					}
					orden = orden+1;//USO ORDEN PARA IR ASIGNANDOLES VALORES A LAS CASILLAS SIGUIENTES DE UN MAZO
					copiado = true;		
				}	
			}
	
//-------------------------------------------------------------------
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),47);
			//Tablero(ancho, alto);
			
			//PintarCarta(x,y,a,b);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),78); //Pinta la seleccion.
			//Semi_marco ( x+13,  y);
			semi_Seleccion (x,y);
			
		}
	}
	x=1;
	y=30;
     gotoxy(x,y); 
     
 
    
 	system("pause");
	return 0;
}
//******************************************************************************
int Baraja ()
{
 	int x=2,y=2;
 	Carta_reverso(x,y);
 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),47);
}

//******************************************************************************

int CartasAElegir ()
{
 	int x=15,y=2;
 	Seleccion (x,y);
}

//******************************************************************************

int MazoCarta1 ()
{
 	int x=41,y=2;
 	Seleccion (x,y);
}

//******************************************************************************

int MazoCarta2 ()
{
 	int x=54,y=2;
 	Seleccion (x,y);
}

//******************************************************************************

int MazoCarta3 ()
{
 	int x=67,y=2;
 	Seleccion (x,y);
}
//******************************************************************************

int MazoCarta4 ()
{
 	int x=80,y=2;
 	Seleccion (x,y);
}
//******************************************************************************

int PilaMazo1 ()
{
 	int x=2,y=14;
	int orden = 1;
 	PintarCarta(x,y,orden);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),47);
}

//******************************************************************************

int PilaMazo2 ()
{
 	int x=15,y=14;
	int orden1 = 2;
	int orden2 = 1;
 	for(int i = 1; i <= 1; i++){
 		orden2 = 1;
 		PintarCarta(x,y,orden1, orden2);
 		y += 2;
	}
	orden2 = 2;
	PintarCarta(x,y,orden1, orden2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),47);
}

//******************************************************************************

int PilaMazo3 ()
{
 	int x=28,y=14;
 	int orden1 = 3;
	int orden2 = 0;
 	for(int i = 1; i <= 2; i++){
 		orden2 += 1;
 		PintarCarta(x,y,orden1, orden2);
 		y += 2;
	}
	orden2 = 3;
	PintarCarta(x,y,orden1, orden2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),47);
}

//******************************************************************************

int PilaMazo4 ()
{
 	int x=41,y=14;
 	int orden1 = 4;
	int orden2 = 0;
 	for(int i = 1; i <= 3; i++){
 		orden2 += 1;
 		PintarCarta(x,y,orden1, orden2);
 		y += 2;
	}
	orden2 = 4;
	PintarCarta(x,y,orden1, orden2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),47);
}

//******************************************************************************

int PilaMazo5 ()
{
 	int x=54,y=14;
 	int orden = 5;
 	for(int i = 1; i <= 4; i++){
 		Carta_reverso(x,y);
 		y += 2;
	}
	PintarCarta(x,y,orden);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),47);
}

//******************************************************************************

int PilaMazo6 ()
{
 	int x=67,y=14;
 	int orden = 6;
 	for(int i = 1; i <= 5; i++){
 		Carta_reverso(x,y);
 		y += 2;
	}
	PintarCarta(x,y,orden);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),47);
}

//******************************************************************************

int PilaMazo7 ()
{
 	int x=80,y=14;
 	int orden = 7;
 	for(int i = 1; i <= 6; ++i){
 		Carta_reverso(x,y);
 		y += 2;
	}
	PintarCarta(x,y,orden);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),47);
}

//******************************************************************************

int Marco(int x,int y)
{    
   gotoxy(x,y);//Imprime la primera parte de la carta.
   cout << (char) ESI;
   for (int i=2; i < ancho; ++i) cout << (char) BH;
   cout << (char) ESD << endl;	
   
   for (int j = 1; j < alto; ++j){//Imprime la estructura de la carta.
	  gotoxy(x,++y);
	  cout << (char) BV;
	  for (int i=2; i < ancho; ++i) cout << " ";
      cout << (char) BV << endl;
   }
   gotoxy(x, y);
   cout << (char) EII; // Imprime segunda parte de la carta.
   for (int i=2; i < ancho; ++i) cout << (char) BH;
   cout << (char) EID << endl;
}

//******************************************************************************

int MarcoVACIO (int x, int y)
{
   gotoxy(x,y);
  	for (int i=0; i < ancho; ++i) cout << " ";
	cout << endl;	
   	for (int j = 1; j < alto; ++j){
	   gotoxy(x,++y);
	   for (int i=0; i < ancho; ++i) cout << " ";
       cout << endl;
   	}
   	gotoxy(x, y);
  	for (int i=0; i < ancho; ++i) cout << " ";
  	y -= 10;
}

int Seleccion (int x, int y)
{
   gotoxy(x,y);
   cout << (char) ESI;
   for (int i=2; i < ancho; ++i) cout << (char) BH;
   cout << (char) ESD << endl;	
	
   	for (int j = 2; j <= alto; ++j){
	   gotoxy(x,++y);
	   for (int i=0; i <= 10; i+=10){
	   	gotoxy(x+i,y);cout << (char) BV;
       cout << endl;
	   } 
   	}
   	gotoxy(x, y);
  	cout << (char) EII; // Imprime segunda parte de la carta.
    for (int i=2; i < ancho; ++i) cout << (char) BH;
    cout << (char) EID << endl;
  	y -= 10;
}

//******************************************************************************

void gotoxy (int x,int y) 
{
   HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
   COORD coord;
   coord.X = x-1;
   coord.Y = y-1;
   SetConsoleCursorPosition(handle,coord);
}

void Tablero (int a[],int b[])
{
	Baraja ();
	CartasAElegir ();
	
	MazoCarta1 ();
	MazoCarta2 ();
	MazoCarta3 ();
	MazoCarta4 ();
	
	PilaMazo1 ();
	PilaMazo2 ();
	PilaMazo3 ();
	PilaMazo4 ();
	PilaMazo5 ();
	PilaMazo6 ();
	PilaMazo7 ();
}

void Barajar(int Mazo[][15], int a[], int b[])
{
   int contador;
   int tipo_carta;
   int numero_carta;

   for ( contador = 1; contador <= 52; contador++ ){ //Se da el valor de las 52 cartas
      do{
         tipo_carta = 3 + rand() % 4; //Se elige al azar el palo
         
         numero_carta = 2 + rand() % 13; //Se elige al azar el numero 
        // cout << tipo_carta << " , " << numero_carta << endl;
         //cout << Mazo[tipo_carta][numero_carta] << endl;
        } while( 0 != Mazo[tipo_carta][numero_carta] ); //Evita que se llene una casilla ya llena

//cout << tipo_carta << " . " << numero_carta << endl;
      if ( 0 == Mazo[tipo_carta][numero_carta] ){ // Evita que se repitan cartas
         Mazo[tipo_carta][numero_carta] = contador;
         a[contador] = tipo_carta;
         b[contador] = numero_carta;
       }
       //cout << Mazo[tipo_carta][numero_carta] << "*" << endl;
   }
}

int Carta_reverso(int x,int y)
{  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),241);
   gotoxy(x,y);//Imprime la primera parte de la carta.
   cout << (char) ESI;
   for (int i=2; i < ancho; ++i) cout << (char) BH;
   cout << (char) ESD << endl;	
   
   for (int j = 1; j < alto; ++j){//Imprime la estructura de la carta.
	  gotoxy(x,++y);
	  cout << (char) BV;
	  for (int i=2; i < ancho; ++i) cout << (char) 178;
      cout << (char) BV << endl;
   }
   gotoxy(x, y);
   cout << (char) EII; // Imprime segunda parte de la carta.
   for (int i=2; i < ancho; ++i) cout << (char) BH;
   cout << (char) EID << endl;
}

void PintarCarta (int x, int y,int orden)
{
	int caracter, palo, numero;
	
	palo = pila_mazo_palo[orden][orden];
    numero = pila_mazo_numero[orden][orden];
    
	//int ancho = 11, alto = 11; //Tamaño de la carta. 
	//int x=79,y=17;
	/*for(int i=1;i<=cartas;i++){	//For que genera las cartas al azar.
       numero= 11;
       x=(1+rand()%50);
       y=(1+rand()%10);  
	}*/



   //int caracter= 3+rand()%4; //Simbolos al azar para las cartas; corazon, trebol, pica y rombo.
   if(palo <= DIAMANTE){
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),252); 
   }else{
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
   }				
   Marco(x,y);  //Llamada a función Marco.
   
   //switch para cartas, donde los simbolos se acomodan para formar las cartas de poker.
   if(numero >= 11){
      if(numero == 11) caracter = JACK;
	  if(numero == 12) caracter = REYNA;
	  if(numero == 13) caracter = REY;
      if(numero == 14) caracter = AS;
   }
   gotoxy(x+1,y+2);
   cout << (char) palo;
   gotoxy(x+9,y+8);
   cout << (char) palo;
   if(numero >= 11){
      gotoxy(x+1,y+1);
	  cout << (char) caracter;
	  gotoxy(x+9,y+9);
	  cout << (char) caracter;
   }else{
      gotoxy(x+1,y+1);
      cout << numero;
      if(numero != 10){
         gotoxy(x+9,y+9);
         cout << numero;
      }else{
         gotoxy(x+8,y+9);
         cout << numero;
      }
   }
   if(numero == 3 || numero == 5 || numero == 9 || numero >= 11){ 
      gotoxy(x+5,y+5);
	  cout << (char) palo;
   }
   if(numero == 2 || numero == 3){
      for(int i = 2; i <= 8; i += 6){
	     gotoxy(x+5,y+i);
		 cout << (char) palo;
      }
   }
   if(numero >= 4 && numero <= 10){
      for(int i = 3; i <= 7; i += 4){
         for(int j = 2; j <= 8; j += 6){
            gotoxy(x+i,y+j);
			cout << (char) palo;
         }
      }
      if(numero >= 6 && numero <= 8){
         for(int i = 3; i <= 7; i += 4){
			gotoxy(x+i,y+5);
			cout << (char) palo;
         }
      }else{
         if(numero == 9 || numero == 10){
            for(int i = 3; i <= 7; i += 4){
               for(int j = 4; j <= 6; j += 2){
				   gotoxy(x+i,y+j);
				   cout << (char )palo;
               }
            }
         }
	  }
      if(numero == 7 || numero == 8 || numero == 10){
         gotoxy(x+5,y+3);
		 cout << (char) palo;
		 if(numero == 8 || numero == 10){
		    gotoxy(x+5,y+7);
		    cout << (char) palo;
         }
      }	
   }
}
int Semi_marco (int x, int y)
{
   gotoxy(x,y);
   cout << (char) ESI;
   for (int i=2; i < ancho; ++i) cout << (char) BH;
   cout << (char) ESD << endl;	
	
   	for (int j = 2; j <= 2; ++j){
	   gotoxy(x,++y);
	   for (int i=0; i <= 10; i+=10){
	   	gotoxy(x+i,y);cout << (char) BV;
       cout << endl;
	   } 
   	}
  	y -= 2;
}

int semi_Seleccion (int x, int y)
{
   gotoxy(x,y);
   cout << (char) ESI;
   for (int i=2; i < ancho; ++i) cout << (char) BH;
   cout << (char) ESD << endl;	

   y -= 1;
}

void PintarCarta (int x, int y,int ordenP, int ordenN)
{
	int caracter, palo, numero;
	
	palo = pila_mazo_palo[ordenP][ordenN];
    numero = pila_mazo_numero[ordenP][ordenN];
    
	//int ancho = 11, alto = 11; //Tamaño de la carta. 
	//int x=79,y=17;
	/*for(int i=1;i<=cartas;i++){	//For que genera las cartas al azar.
       numero= 11;
       x=(1+rand()%50);
       y=(1+rand()%10);  
	}*/



   //int caracter= 3+rand()%4; //Simbolos al azar para las cartas; corazon, trebol, pica y rombo.
   if(palo <= DIAMANTE){
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),252); 
   }else{
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
   }				
   Marco(x,y);  //Llamada a función Marco.
   
   //switch para cartas, donde los simbolos se acomodan para formar las cartas de poker.
   if(numero >= 11){
      if(numero == 11) caracter = JACK;
	  if(numero == 12) caracter = REYNA;
	  if(numero == 13) caracter = REY;
      if(numero == 14) caracter = AS;
   }
   gotoxy(x+1,y+2);
   cout << (char) palo;
   gotoxy(x+9,y+8);
   cout << (char) palo;
   if(numero >= 11){
      gotoxy(x+1,y+1);
	  cout << (char) caracter;
	  gotoxy(x+9,y+9);
	  cout << (char) caracter;
   }else{
      gotoxy(x+1,y+1);
      cout << numero;
      if(numero != 10){
         gotoxy(x+9,y+9);
         cout << numero;
      }else{
         gotoxy(x+8,y+9);
         cout << numero;
      }
   }
   if(numero == 3 || numero == 5 || numero == 9 || numero >= 11){ 
      gotoxy(x+5,y+5);
	  cout << (char) palo;
   }
   if(numero == 2 || numero == 3){
      for(int i = 2; i <= 8; i += 6){
	     gotoxy(x+5,y+i);
		 cout << (char) palo;
      }
   }
   if(numero >= 4 && numero <= 10){
      for(int i = 3; i <= 7; i += 4){
         for(int j = 2; j <= 8; j += 6){
            gotoxy(x+i,y+j);
			cout << (char) palo;
         }
      }
      if(numero >= 6 && numero <= 8){
         for(int i = 3; i <= 7; i += 4){
			gotoxy(x+i,y+5);
			cout << (char) palo;
         }
      }else{
         if(numero == 9 || numero == 10){
            for(int i = 3; i <= 7; i += 4){
               for(int j = 4; j <= 6; j += 2){
				   gotoxy(x+i,y+j);
				   cout << (char )palo;
               }
            }
         }
	  }
      if(numero == 7 || numero == 8 || numero == 10){
         gotoxy(x+5,y+3);
		 cout << (char) palo;
		 if(numero == 8 || numero == 10){
		    gotoxy(x+5,y+7);
		    cout << (char) palo;
         }
      }	
   }
}
