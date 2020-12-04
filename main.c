#include <stdio.h>
#include <stdlib.h>  // PARA GENERAR LOS NUMEROS RANDOM
#include <string.h>  // PARA TRABAJAR MUCHO MEJOR CON LAS CADENAS USAMOS ESTA LIBRERIA
#include <conio.h>   // PARA LA FUNCION GETCH
#include <time.h>    // PARA GENERAR LOS NUMEROS RANDOM

// METODO RECURSIVO PARA SER LLAMADO A SI MISMO CUANDO PRESIONAS UNA TECLA
comenzarJuego(char frutas[][15]) {
    int posicion;
    int longitud;
    int espacios;
    int score = 500;
    char letra;
    int aciertos;
    int masVidas = 0;
    int intentos = 0; // EMPEZAMOS LOS INTENTOS EN 0 Y SE VAN INCREMENTANDO DE ACUERDO A LAS VECES QUE FALLEMOS
    srand(time(0)); // PARA ASEGURARNOS QUE NO SE GENERE DE NUEVO ESA POSICION
    posicion = rand() % 19; //SE GENERA UN NUMERO ALEATORIO COMPRENDIDO ENTRE 0 Y 19
    longitud = strlen(frutas[posicion]); //SE ALMACENA LA LONGITUD DE LA PALABRA
    char frase[longitud];  //CREAMOS OTRO ARREGLO PARA LA PALABRA ALEATORIA CON EL LENGHT DE LA NUEVA PALABRA


    //SE COLOCAN GUIONES BAJOS DE ACUERDO AL LENGHT DE LA CADENA
    //CADA FRASE GENERADA DEBE SER CUBIERTA POR GUIONRES BAJOS
    for (int i = 0; i < longitud; i++) {
        frase[i] = '_';
    }

    //FIN DE GUIONES

    do {
        aciertos = 0;
        printf("\n----------------------------------------------------------\n");
        printf("\t\tBIENVENIDO AL JUEGO EL AHORCADO\n\n");
        printf("NOTA: LA VIRGULILLA DE LA ENE ES SUSTITUIDA POR 'N'\n");
        printf("INGRESA TODOS LOS CARACTERES CON MAYUSCULA\n");
        printf("NO SE CONSIDERAN ACENTOS\n");
        printf("\n\t\t\tADIVINA LA FRUTA!\n");
        printf("\n----------------------------------------------------------\n");
        printf("Vidas: %i\t\t\t\tScore: %i\n\n", 5 - intentos, score);


        // PRESENTAMOS LA PALABRA CUBIERTA CON GUIONES
        // IMPRIME EL ARRAY DE CARACTERES FRASE
        printf("\n");
        for (int i = 0; i < longitud; i++) {
            printf(" %c ", frase[i]);
        }


        // AQUI COMPROBAMOS SI PERDIO O NO DE ACUERDO A LOS INTENTOS QUE LE RESTAN
        // CUANDO LOS INTENTOS SON 5 QUIERE DECIR QUE HA OCUPADO TODAS SUS VIDAD Y PUEDE JUGAR DE NUEVO
        if (intentos == 5) {
            printf("\n LO SIENTO, PERDISTE!!\n");
            printf(" LA SOLUCION ERA: %s\n", frutas[posicion]);
            printf(" PRESIONA UNA TECLA PARA VOLVER A JUGAR");
            getch();
            comenzarJuego(frutas);
            // continuar = true;
        }





        //COMPROBAMOS SI LA POSICION i TIENE "_", DE SER ASI LOS ESPACIOS SEGUIRAN AUMENTANDO
        espacios = 0; // SE DEBE AUMENTAR LA VARIABLE PORQUE AQUI LE ASIGNAMOS 0
        for (int i = 0; i < longitud; i++) {
            if (frase[i] == '_')
                espacios++; // RETORNAMOS LA VARIABLE CON LOS ESPACIOS CON "_" PARA ASI VERIFICAR SI GANAMOS O PERDEMOS
        }

        // AQUI COMPROBAMOS SI GANO DE ACUERDO A LOS ESPACIOS CON "_" RESTANTEs
        // SI YA NO HAY GUIONES EN EL ARREGLO FRASE QUIERE DECIR QUE YA GANASTE
        if (espacios == 0) {
            printf("\n FELICIDADES, BIEN HECHO!\n\n");
            printf(" Presiona una tecla para volver a jugar..");
            getch();
            comenzarJuego(frutas);
            // continuar = true;
            // PARA HACER UNA PAUSA
        }








        // AQUI INICIA EL JUEGO Y SOLICITAMOS CADA LETRA PARA DESCUBRIR LA FRASE
        printf("\n\n Ingresa una letra para descubrir la palabra: ");
        scanf(" %c", &letra);


        // PARA NO RESTAR MAS VIDAS INGRSANDO LA LETRA MAS DE 2 VECES
        char letraAcumulada;

        if (letraAcumulada == letra) {
            printf("\n*************************************************");
            printf("\nYA INGRESASTE ESA LETRA Y NO RESTARAS MAS VIDAS");
            printf("\n*************************************************");
            aciertos++;
        }


        //PROCESO QUE VERIFICA SI LA LETRA INGRESADA EXISTE EN LA PALABRA, SI ESTO ES VERDADERO, SE REEMPLAZA EL CARACTER GUION BAJO POR LA LETRA INGRESADA
        for (int j = 0; j < longitud; j++) {
            if (letra == frutas[posicion][j]) { // COMPROBAMOS QUE EXISTA LA LETRA QUE PEDIMOS EN LA VARIABLE
                // Y RECORREMOS HASTA EL INDICE DE LA PALABRA PARA RECORRER LETRA A LETRA LA CADEA
                frase[j] = letra;
                aciertos++; // ACUMULAMOS LA CANTIDAD DE LETRAS QUE SI COINCIDEN CON LAS POSICIONES DE FRUTAS
                // printf("ACIERTOS %d ", aciertos);
            }
        }



        letraAcumulada = letra;






        // LOS ACIERTOS SE SUAMAN DE ACUERDO A LAS VECES QUE APARECEN EN EL ARREGLO FRUTAS
        // POR LO TANTO NO SIEMPRE SERA 1, PUEDEN SER 3 LETRAS REPETIDAS
        // POR ESO CUALQUIER DATO QUE SEA DIFERENTE DE 0 SE INTERPRETA COMO 1 SOLA UNIDAD
        if (aciertos != 0) {
            masVidas++;
        }


//        printf("EXISTE %d VEZ", masVidas);

        // SI NINGUNA LETRA INGRESADA EN LA VARIABLE LETRA COINCIDE CON ALGUNA POSCISION DE FRUTAS
        // ENTONCES NO ACERTAMOS Y SUBIMOS LOS INTENTES QUE ESTAN EN 0 A 1 MAS PARA RESTARLO EN LA PRESENTACION CON EL SCORE
        // QUEDARIA 5 INTENTENTOS - 1 Y SCORE EN 500 -100
        // SOLAMENTE RESTAMOS VIDAS Y SCORE CUANDO NO EXISTE ESA LETRA EN FRUTAS[POSICION]
        if (aciertos == 0) {
            intentos++;
            score -= 100;
        }




        // AUMENTAMOS LAS VIDAS DESPUES DE 3 ACIERTOS O 6 QUE ES NUMERO PAR DE 3
        if (masVidas == 3 || masVidas == 6) {
            printf("\n*************************************************");
            printf("\n\tFELICIDADES, SUMASTE UNA VIDA EXTRA\n");
            printf("\n*************************************************");
            intentos--;
            score += 100;
        }


    } while (intentos != 6); // POR LO TANTO CONSIDERAMOS INTENTOS DE 1 A 5


}

//FUNCION PRINCIPAL MAIN
int main() {
    // PRECARGAMOS NUESTRAS 20 FRUTAS Y PASAMOS EL ARREGLO A LA FUNCION COMENZARJUEGO()
    char frutas[20][15] = { //20 ESPACIOS CON LONGITUD DE 15 CADA CADENA
            "MANGO",        //POSICION 0
            "MELON",        //POSICION 1
            "ARANDANO",     //POSICION 2
            "PAPAYA",       //POSICION 3
            "SANDIA",       //POSICION 4
            "PLATANO",      //POSICION 5
            "FRAMBUESA",     //POSICION 6
            "MANZANA",      //POSICION 7
            "PERA",         //POSICION 8
            "NARANJA",      //POSICION 9
            "PINA",          //POSICION 10
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

    comenzarJuego(frutas);
    return 0;
}

