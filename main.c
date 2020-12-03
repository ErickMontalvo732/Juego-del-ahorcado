#include <stdio.h>
#include <stdlib.h>  // PARA GENERAR LOS NUMEROS RANDOM
#include <string.h>  // PARA TRABAJAR MUCHO MEJOR CON LAS CADENAS USAMOS ESTA LIBRERIA
#include <conio.h>
#include <time.h>    // PARA GENERAR LOS NUMEROS RANDOM


//FUNCION PRINCIPAL MAIN
int main() {
    char frutas[20][15] = {
            "MANGO",        //POSICION 0
            "MELON",        //POSICION 1
            "ARANDANO",     //POSICION 2
            "PAPAYA",       //POSICION 3
            "SANDIA",       //POSICION 4
            "PLATANO",      //POSICION 5
            "FRAMBUESA"     //POSICION 6
            "MANZANA",      //POSICION 7
            "PERA",         //POSICION 8
            "NARANJA",      //POSICION 9
            "PINA"          //POSICION 10
            "UVA",          //POSICION 11
            "CEREZA",       //POSICION 12
            "CIRUELA",      //POSICION 13
            "KIWI",         //POSICION 14
            "FRESA",        //POSICION 15
            "MANDARINA",    //POSICION 16
            "LIMON",        //POSICION 17
            "AGUACATE",     //POSICION 18
            "COCO"          //POSICION 19
    };
    int posicion, i, j, longitud, espacios, score = 500;
    char letra;
    int aciertos = 0;
    int intentos = 0;
    srand(time(NULL));
    posicion = rand() % 19; //SE GENERA UN NUMERO ALEATORIO COMPRENDIDO ENTRE 0 Y 19
    longitud = strlen(frutas[posicion]); //SE ALMACENA LA LONGITUD DE LA PALABRA
    char frase[longitud];               //CREAMOS OTRO ARREGLO PARA LA PALABRA ALEATORIA CON EL LENGHT DE LA NUEVA PALABRA

    //SE COLOCAN GUIONES BAJOS EN EL ARRAY DE CARACTERES FRASE
    for (i = 0; i < longitud; i++) {
        frase[i] = '_';
    }


    do {
        aciertos = 0;
        printf("\n----------------------------------------------------------\n");
        printf("\t\tBIENVENIDO AL JUEGO EL AHORCADO\n\n");
        printf("NOTA: LA VIRGULILLA DE LA ENE ES SUSTITUIDA POR 'N'\n");
        printf("INGRESA TODOS LOS CARACTERES CON MAYUSCULA\n");
        printf("NO SE CONSIDERAN ACENTOS\n");
        printf("\n\t\t\tA JUGAR!\n");
        printf("\n----------------------------------------------------------\n");
        printf(" Intentos Disponibles: %i\t\t\t\tPuntuacion: %i\n\n", 5 - intentos, score);


        //IMPRIME EL ARRAY DE CARACTERES FRASE
        printf("\n\n\n");
        for (i = 0; i < longitud; i++) {
            printf(" %c ", frase[i]);
        }


        if (intentos == 6) {
            printf("\n\n PERDISTE!!\n");
            printf(" LA SOLUCION ERA: %s\n\n", frutas[posicion]);
            printf(" Presiona una tecla para volver a jugar..");
            getch();
            // categorias();
        }


        //PROCESO QUE COMPRUEBA SI SE HA ADIVINADO LA PALABRA
        espacios = 0;

        for (i = 0; i < longitud; i++) {
            if (frase[i] == '_')
                espacios++;
        }


        if (espacios == 0) {
            printf("\n\n FELICIDADES.. GANASTE!!\n\n");
            printf(" Presiona una tecla para volver a jugar..");
            getch();
            //  categorias();
        }


        printf("\n\n Ingresa una letra: ");
        scanf(" %c", &letra);

        //PROCESO QUE VERIFICA SI LA LETRA INGRESADA EXISTE EN LA PALABRA, SI ESTO ES VERDADERO, SE REEMPLAZA EL CARACTER GUION BAJO POR LA LETRA INGRESADA
        for (j = 0; j < longitud; j++) {
            if (letra == frutas[posicion][j]) {
                frase[j] = letra;
                aciertos++;
            }
        }

        if (aciertos == 0) {
            intentos++;
            score -= 100;
        }


    } while (intentos != 6);

    printf("\n\n");

    return 0;
}

