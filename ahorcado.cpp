/*archivo .cpp*/

#include<iostream>
#include<string.h>
#include<time.h>
#include<conio.h>
#include<windows.h> // para system("mode con cols=80 lines=25");//
using namespace std;

//FUNCIONES PROTOTIPOS
void categoria();
void ingresar_categ(int opcion);
void empezar_juego(char palabras[][20], char nombrec[]);
void dibujo (int intentos);


//MAIN

int main(){
    system("mode con cols=80 lines=25");
    categoria();
    system("pause");
    return 0;

}

//FUNCIONES

void categoria(){  //imprime categorias y puedo elegir una
    int opcion;
    do{

        cout<<"///////// JUEGO DEL AHORCADO /////////"<<endl;
        cout<<"/// CATEGORIAS ///"<<endl;
        cout<<"1- PAISES"<<endl;
        cout<<"2- FRUTAS"<<endl;
        cout<<"3- OBJETOS"<<endl;
        cout<<"4- ANIMALES"<<endl;
        cout<<"5- MARCAS"<<endl;
        cout<<" Ingrese una opcion: ";
        cin>>opcion;
    }while(opcion<1 || opcion>5);

    if(opcion==1){
        ingresar_categ(opcion);
    }
    if(opcion==2){
        ingresar_categ(opcion);
    }
    if(opcion==3){
        ingresar_categ(opcion);
    }
    if(opcion==4){
        ingresar_categ(opcion);
    }
    if(opcion==5){
        ingresar_categ(opcion);
    }


}

void ingresar_categ(int opcion){
    char nombrecateg[5][20]={"Paises", "Frutas", "Objetos", "Animales", "Marcas"};
    char paises[10][20]={"PERU","COLOMBIA","ARGENTINA","NICARAGUA","ITALIA","MEXICO","CANADA","VENEZUELA","ECUADOR","BRASIL"};
    char frutas[10][20]={"MELON","PAPAYA","SANDIA","MANZANA","PERA","NARANJA","UVA","CEREZA","CIRUELA","KIWI"};
    char objetos[10][20]={"MOCHILA","RELOJ","ZAPATILLA","MUEBLE","CUADERNO","SILLA","MESA","CELULAR","PUERTA","AURICULARES"};
    char animales[10][20]={"PERRO","GATO","CABALLO","GALLINA","JIRAFA","MONO","VACA","CONEJO","TORTUGA","LOBO"};
    char marcas[10][20]={"APPLE","NIKE","ADIDAS","VANS","CONVERSE","FERRARI","LAMBORGHINI","LACOSTE","ZARA","DIESEL"};

    switch (opcion){
     case 1:
        empezar_juego(paises,nombrecateg[opcion-1]);
        break;
     case 2:
        empezar_juego(frutas,nombrecateg[opcion-1]);
        break;
     case 3:
        empezar_juego(objetos,nombrecateg[opcion-1]);
        break;
     case 4:
        empezar_juego(animales,nombrecateg[opcion-1]);
        break;
     case 5:
        empezar_juego(marcas,nombrecateg[opcion-1]);
        break;
    }
}

void empezar_juego(char palabras[][20], char nombrec[]){  // en esta funcion se encuentra el algoritmo principal para el juego
        int opcion,longitud, espacios,puntos=2000;
        char letras;
        int aciertos=0;
        int intentos=0;


        srand(time(NULL));     // para que salga aleatorio
        opcion=rand()%10  ;     // se genera un n° aleatorio entre 0 y 9, simbolizando las palabras
        longitud=strlen(palabras[opcion])  ;  // se guarda la longitud de la palabra
        char frases[longitud];


        for(int i;i<longitud;i++){ //se colocan guiones por cada letra de la palabra
            frases[i]= '_';
        }

        do{
            aciertos=0;

            cout<<"///////// JUEGO DEL AHORCADO /////////"<<endl;
            cout<<"/// CATEGORIA: "<<nombrec<<" ///"<<endl;
            cout<<endl;
            cout<<endl;
            cout<<" INTENTOS DISPONIBLES: "<<6-intentos<<"                            "<<" PUNTUACION: "<<puntos<<endl;
            dibujo(intentos);

            cout<<endl;
            cout<<endl;
            cout<<endl;

            for (int i=0;i<longitud;i++){
                cout<<frases[i];
            }

            if(intentos==6){
                cout<<endl;
                cout<<endl;
                cout<<"PERDISTE!!"<<endl;
                cout<<"La solucion es: "<<palabras[opcion]<<endl;
                cout<<"Presiona una tecla para volver a jugar...";
                getch();
                categoria();
            }


            //a partir de acá, se comprueba si se ha adivinado la palabra


            espacios=0;

            for(int i=0; i <longitud;i++){
                if(frases[i]== '_'){
                    espacios++;
                }
            }

            if(espacios==0){
                cout<<endl;
                cout<<endl;
                cout<<"GANASTE!! :) "<<endl;
                cout<<"Presiona una tecla para volver a jugar...";
                getch();
                categoria();
            }

            cout<<endl;
            cout<<endl;
            cout<<"ADVERTENCIA: RECUERDE UTILIZAR SOLO MAYUSCULAS !!! "<<endl;
            cout<<"Ingrese una letra: ";
            cin>>letras;



            //a partir de acá, se comprueba si una letra existe o no en la palabra
            // si existe, se reemplaza el guion con la letra correspondiente

            for(int j=0;j<longitud;j++){
                if(letras==palabras[opcion][j]){
                    frases[j]=letras;
                    aciertos++;
                }
            }

            if(aciertos==0){
                intentos++;
                puntos-=200;
            }


        }while(intentos!=7);

     cout<<endl;

}

//funcion de diseño que se encarga de dibujar al ahorcado por partes.
// por cada intento fallido se le agrega una parte al cuerpo

void dibujo (int intentos){
	switch(intentos){
		case 0:
			cout<<("\n     _______\n    |       |\n    |\n    |\n    |\n    |\n    |\n ----------");
			break;
		case 1:
			cout<<("\n     _______\n    |       |\n    |       0\n    |\n    |\n    |\n    |\n ----------");
			break;
		case 2:
			cout<<("\n     _______\n    |       |\n    |       0\n    |       |\n    |\n    |\n    |\n ----------");
			break;
		case 3:
			cout<<("\n     _______\n    |       |\n    |       0\n    |      /|\n    |\n    |\n    |\n ----------");
			break;
		case 4:
			cout<<("\n     _______\n    |       |\n    |       0\n    |      /|");
			cout<<("\\");
			cout<<("\n");
			cout<<("    |\n    |\n    |\n ----------");
			break;
		case 5:
			cout<<("\n     _______\n    |       |\n    |       0\n    |      /|");
			cout<<("\\");
			cout<<("\n");
			cout<<("    |      /\n    |\n    |\n ----------");
			break;
		case 6:
			cout<<("\n     _______\n    |       |\n    |       0\n    |      /|");
			cout<<("\\");
			cout<<("\n");
			cout<<("    |      / ");
			cout<<("\\");
			cout<<("\n");
			cout<<("    |\n    |\n ----------");
			break;
	}

}
