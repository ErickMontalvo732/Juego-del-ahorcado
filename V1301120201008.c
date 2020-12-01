#include <stdio.h>
#include <string.h > // PARA TRABAJAR MUCHO MEJOR CON LAS CADENAS USAMOS ESTA LIBRERIA
#include <stdlib.h > // PARA GENERAR LOS NUMEROS RANDOM
#include <time.h>    // PARA GENERAR LOS NUMEROS RANDOM

// **************** FUNCIONES  ****************


int generarNumeroAleatorio(){
    // ESTA FUNCION USA LAS LIBRERIAS Y GENERA NUMEROS ENTRE 0 Y 20
    srand(time(NULL));
    int numeroRandomFuncion = rand()%19;
    return  numeroRandomFuncion;
}





// **************** FIN FUNCIONES  ****************









// INICIO DE CLASE PRINCIPAL
int main() {
    // LISTA DE 20 PALABRAS
    char palabras[][20] =
            {
              "arandano",
              "pera",
              "uva",
              "platano",
              "kiwi",
              "mandarina",
              "papaya",
              "fresa",
              "limon",
              "frambuesa",
              "naranja",
              "melon",
              "sandia",
              "coco",
              "mango",
              "pina",
              "aguacate",
              "guayaba",
              "melocoton",
              "carambola",
            };
    // FIN DE LISTA


    // DECLARACION DE VARIABLES
    int numeroRandom; // AL QUE ASIGNAREMOS EL NUMERO RANDOM DE LA FUNCION EN LA CLASE MAIN
    int tamanoArreglo;
    // FIN DE DECLARACION DE VARIABLES

    /* **************************
       * AQUI EMPIEZA EL CODIGO *
       **************************
    */


    // EMPEZAMOS EL CODIGO GENERANDO UNA POSICION DE NUESTRO ARREGLO
    numeroRandom = generarNumeroAleatorio(); // ASIGNAMOS EL NUMERO A LA VARIABLE GLOBAL
    // PRESENTACION DEL JUEGO
    printf("----------------------------------------------------------\n" );
    printf("\tBIENVENIDO AL JUEGO DEL AHORCADO\n" );
    printf("\tEN ESTA RONDA USAREMOS LA FRUTA: %s\n", palabras[numeroRandom]);
    printf("-----------------------------------------------------------\n" );
    // VIDAS RESTANTES
    for(int i=5; i>=1;i--){
        printf("\tVIDAS RESTANTES:  %d\n", i);

    }
    printf( "");


    return 0;
}

// TERMINA CLASE PRINCIPAL(MAIN)


