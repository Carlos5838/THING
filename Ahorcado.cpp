#include <iostream>
#include <stdio.h>
using namespace std;
bool win = false; //Variable que checa si se ganó el juego
int num_caracteres = 0; //Variable para contar la cantidad de caracteres de la palabra
bool letras_encontradas[50];

void Impresion_Ahorcado(int fase) {
    cout << endl;
    switch (fase) {
    case 6:
        cout << "+---+" << endl;
        cout << "|   |" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        break;
    case 5:
        cout << "+---+" << endl;
        cout << "|   |" << endl;
        cout << "|   O" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        break;
    case 4:
        cout << "+---+" << endl;
        cout << "|   |" << endl;
        cout << "|   O" << endl;
        cout << "|   |" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        break;
    case 3:
        cout << "+---+" << endl;
        cout << "|   |" << endl;
        cout << "|   O" << endl;
        cout << "|  /|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        break;
    case 2:
        cout << "+---+" << endl;
        cout << "|   |" << endl;
        cout << "|   O" << endl;
        cout << "|  /|\\" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        break;
    case 1:
        cout << "+---+" << endl;
        cout << "|   |" << endl;
        cout << "|   O" << endl;
        cout << "|  /|\\" << endl;
        cout << "|  /" << endl;
        cout << "|" << endl;
        break;
    case 0:
        cout << "+---+" << endl;
        cout << "|   |" << endl;
        cout << "|   O" << endl;
        cout << "|  /|\\" << endl;
        cout << "|  / \\" << endl;
        cout << "|" << endl;
        break;
    }
}

void Fin_Juego() {
    win = true;
    for (int i = 0; i < num_caracteres; i++) {
        if (letras_encontradas[i] == 0) {
            win = false;
        }
    }
    cout << "Win: " << win << endl;
}

int main()
{
    char palabra[50]; //Array tipo char para contener a la palabra
    char entrada_jugador; //Variable para la letra ingresada por el usuario

    cout << "Ingrese la palabra para el juego: ";
    cin.getline(palabra, 49); //Toma lo ingresado por el usuario con todo y espacios

    //Contador de letras en la palabra
    do {
        if (palabra[num_caracteres] == NULL) {
            break;
        }

        num_caracteres++;

    } while (num_caracteres < 50);

    cout << "La palabra tiene " << num_caracteres << " caracteres" << endl;


    bool letra_encontrada = false;
    int intentos = 6; //variable para 6 intentos antes de perder el juego
    do {

        Impresion_Ahorcado(intentos);
        cout << "\nPalabra: ";
        for (int i = 0; i < num_caracteres; i++) {
            if (palabra[i] == ' ') {
                cout << " ";
                letras_encontradas[i] = true;
            }
            else if (letras_encontradas[i] == true) {
                cout << palabra[i];
            }
            else {
                cout << "_";
            }
        }

        cout << "\nIngrese una letra: ";
        cin >> entrada_jugador;

        for (int i = 0; i < num_caracteres; i++) {
            if (entrada_jugador == palabra[i]) {
                letras_encontradas[i] = true;
                letra_encontrada = true;
            }
        }

        if (letra_encontrada == true) {
            cout << "Letra encontrada" << endl;
            letra_encontrada = false;
        }
        else {
            cout << "Letra no encontrada. Intentos restantes: " << intentos - 1 << endl;
            intentos--;
        }

        Fin_Juego();
        if (win == true) {
            cout << "\nFelicidades, adivinaste la palabra!";
            break;
        }

    } while (intentos > 0);

    if (intentos == 0) {
        Impresion_Ahorcado(intentos);
        cout << "Se acabaron los intentos. Fin del Juego";
    }

    return 0;
}