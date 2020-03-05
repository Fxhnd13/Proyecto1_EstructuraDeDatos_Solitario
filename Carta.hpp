#include <iostream>

using namespace std;

// clase Carta con constructor y destructor
class Carta
{
    // atributos
    int tipo, valor;//tipo sirve para reconocer que carta es y valor para saber el valor jerarquico que posee
    bool visible;

public:
    // constructor de base (nulo)
    Carta(){}
    Carta(int parametro) {
        visible=false;
        switch (parametro){
        case 1:
            tipo = 0; valor=1;
            break;
        case 2:
            tipo = 0; valor=2;
            break;
        case 3:
            tipo = 0; valor=3;
            break;
        case 4:
            tipo = 0; valor=4;
            break;
        case 5:
            tipo=0; valor=5;
            break;
        case 6:
            tipo=0; valor=6;
            break;
        case 7:
            tipo=0; valor=7;
            break;
        case 8:
            tipo=0; valor=8;
            break;
        case 9:
            tipo=0; valor=9;
            break;
        case 10:
            tipo=0; valor=10;
            break;
        case 11:
            tipo=0; valor=11;
            break;
        case 12:
            tipo=0; valor=12;
            break;
        case 13:
            tipo=0; valor=13;
            break;
        case 14:
            tipo=1; valor=1;
            break;
        case 15:
            tipo=1; valor=2;
            break;
        case 16:
            tipo=1; valor=3;
            break;
        case 17:
            tipo=1; valor=4;
            break;
        case 18:
            tipo=1; valor=5;
            break;
        case 19:
            tipo=1; valor=6;
            break;
        case 20:
            tipo=1; valor=7;
            break;
        case 21:
            tipo=1; valor=8;
            break;
        case 22:
            tipo=1; valor=9;
            break;
        case 23:
            tipo=1; valor=10;
            break;
        case 24:
            tipo=1; valor=11;
            break;
        case 25:
            tipo=1; valor=12;
            break;
        case 26:
            tipo=1; valor=13;
            break;
        case 27:
            tipo=2; valor=1;
            break;
        case 28:
            tipo=2; valor=2;
            break;
        case 29:
            tipo=2; valor=3;
            break;
        case 30:
            tipo=2; valor=4;
            break;
        case 31:
            tipo=2; valor=5;
            break;
        case 32:
            tipo=2; valor=6;
            break;
        case 33:
            tipo=2; valor=7;
            break;
        case 34:
            tipo=2; valor=8;
            break;
        case 35:
            tipo=2; valor=9;
            break;
        case 36:
            tipo=2; valor=10;
            break;
        case 37:
            tipo=2; valor=11;
            break;
        case 38:
            tipo=2; valor=12;
            break;
        case 39:
            tipo=2; valor=13;
            break;
        case 40:  
            tipo=3; valor=1;  
            break;
        case 41:
            tipo=3; valor=2;
            break;
        case 42:
            tipo=3; valor=3;
            break;
        case 43:
            tipo=3; valor=4;
            break;
        case 44:
            tipo=3; valor=5; 
            break;
        case 45:
            tipo=3; valor=6;
            break;
        case 46:
            tipo=3; valor=7;
            break;
        case 47:
            tipo=3; valor=8;
            break;
        case 48:
            tipo=3; valor=9;
            break;
        case 49:
            tipo=3; valor=10;
            break;
        case 50:
            tipo=3; valor=11;
            break;
        case 51:
            tipo=3; valor=12;
            break;
        case 52:
            tipo=3; valor=13;
            break;
        default:
            break;
        }
    }

    // destructor
    ~Carta() {}

    // métodos
    int getColumna();
    void setColumna(int);
    int getFila();
    void setFila(int);
    int getValor(void);
    void setValor(int);
    int getTipo(void);
    void setTipo(int);
    bool getVisible(void);
    void setVisible(bool);
    void escribirCarta(void);
};