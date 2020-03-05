/**
 * Solitario en C++
 *
 Autor: José Carlos Soberanis Ramírez
 Carnet: 201730246

 Estructura De Datos
 
 */

#include <iostream>
#include <cstdlib>
#include "Carta.cpp"

using namespace std;

struct NodoPila{
    Carta carta;
    NodoPila *sig=NULL;
};

struct NodoLista {
    NodoPila *inicio=NULL;
    NodoLista *sig=NULL;
    NodoLista *ant=NULL;
};

//metodos para la manipulacion de las estructuras
    bool isEmpty(NodoPila *&);
    NodoLista* getAt(int, NodoLista *&);
    void Primero(NodoLista *&);
    void Ultimo(NodoLista *&);
    void agregarNodoLista(NodoLista *&);
    void sacarCarta(NodoPila *&, Carta);
    void agregarCarta(NodoPila *&, Carta);
    void escribirPila(NodoPila *&);
    void verBanco();
    Carta cartaTopePila(NodoPila *&);
    NodoPila* copiarPila(NodoPila *&);
    NodoPila* getColumna(int);
    int longitud(NodoPila *&);
    bool cantidadDeCartasValida(NodoPila *&, int);
    void moverCarta(int, int, int);
    void voltearCartaDe(int);
    void agregarCartaA(int);
    void sacarCartaDe(int);
    
//metodos para el juego en general
    bool compatibles(int, int);
    void mezclarCartas(int[], int);//mezcla las cartas
    bool existe(int, int[]);//verifica si el numero enviado existe dentro del arreglo de numeros
    void llenarJuego(int[]);//sirve para meter dentro de cada pila las cartas para iniciar el juego
    void mostrarCartas(void);//muestra en pantalla todas las cartas
    void mostrarMenu(void);
    bool verificarVictoria(void);
    void menuMoverCarta(void);
    void verSiguiente(void);
    bool compatiblesJuego(int, int);

//declaracion de las variables a utilizar en el juego
    NodoPila *banco=NULL, *bancoVista=NULL, *diamantes=NULL, *picas=NULL, *corazones=NULL, *treboles=NULL;
    NodoLista *columnas=NULL;
    int numeros[52];
    int semilla;
    bool victoria = false;
    bool valorGlobal = false;

int main(){
    cout<<"Por favor ingrese la semilla de juego que desea: ";//pregunta al usuario cual juego desea "jugar"
    cin>>semilla;//dependiendo de la semilla mezcla las cartas
    mezclarCartas(numeros, semilla);//mezcla las cartas
    llenarJuego(numeros);
    while(!victoria&&!valorGlobal){
        cout<<"\n\n\n"<<endl;
        //se muestran las cartas
        mostrarCartas();    
        cout<<""<<endl;
        //se da a escoger una opcion del menu
        mostrarMenu();
        //se verifica que las pilas diamantes, corazones, picas y treboles no tengan una longitud de 13
        victoria = verificarVictoria();//si tienen una longitud de 13 entonces victoria =true, y termina le juego
        //si no se repetirá infinitamente
    }
}

//Implementacion de los metodos para la manipulacion de las estructuras------------------------------------

    int longitud(NodoPila *& pila){
        int contador = 0;
        NodoPila *aux = pila;
        if(!isEmpty(aux)){
            contador++;
            while(aux->sig){
                aux = aux->sig;
                contador++;
            }   
        }
        aux = NULL;
        delete aux;
        return contador;
    }

    void Primero(NodoLista *&plista) {
        while(plista && plista->ant){
            plista = plista->ant;
        }
    }

    void Ultimo(NodoLista *&plista) {
        while(plista && plista->sig) plista = plista->sig;
    }

    //Metodo para agregar las columans a la lista de pilas
    void agregarNodoLista(NodoLista *&nodo){
        Ultimo(nodo);
        NodoLista *nuevoNodo = new NodoLista();
        if(nodo==NULL){
            nuevoNodo->sig = NULL;
            nuevoNodo->ant = NULL;
            nodo = nuevoNodo;
        }else{
            nuevoNodo->sig = NULL;
            nuevoNodo->ant = nodo;
            nodo->sig = nuevoNodo;
            nodo = nuevoNodo;
        }
    }

    //Metodo que retorna el nodo que se encuentra en el indice indicado empezando por el primer elemento
    NodoLista* getAt(int indice, NodoLista *&nodo){
        NodoLista *nodoLista = new NodoLista();
        nodoLista = nodo;
        Primero(nodoLista);
        if(indice == 0){
            return nodoLista;
        }else{
            for (int i = 0; i < indice; i++)
            {
                nodoLista = nodoLista->sig;
            }
            return nodoLista;
        }
    }

    //Metodo que retorna verdadero si la pila se encuentra vacia
    bool isEmpty(NodoPila *&nodo){
        return (nodo==NULL);
    }

    //Metodo para sacar una carta de la pila
    void sacarCarta(NodoPila *&nodo){
        NodoPila *aux = nodo;
        nodo = nodo->sig;
        delete aux;
    }

    void sacarCartaDe(int columna){
        switch(columna){
            case 0:
                sacarCarta(bancoVista);break;
            case 1:
                sacarCarta((getAt(0, columnas))->inicio); break;
            case 2:
                sacarCarta((getAt(1, columnas))->inicio); break;
            case 3:
                sacarCarta((getAt(2, columnas))->inicio); break;
            case 4:
                sacarCarta((getAt(3, columnas))->inicio); break;
            case 5:
                sacarCarta((getAt(4, columnas))->inicio); break;
            case 6:
                sacarCarta((getAt(5, columnas))->inicio); break;
            case 7:
                sacarCarta((getAt(6, columnas))->inicio); break;
            case 8:
                sacarCarta(diamantes); break;
            case 9:
                sacarCarta(corazones); break;
            case 10:
                sacarCarta(picas); break;
            case 11:
                sacarCarta(treboles); break;
        }
    }

    void agregarCartaA(int columna, Carta carta){
        switch(columna){
            case 0:
                agregarCarta(bancoVista, carta);break;
            case 1:
                agregarCarta((getAt(0, columnas))->inicio, carta); break;
            case 2:
                agregarCarta((getAt(1, columnas))->inicio, carta); break;
            case 3:
                agregarCarta((getAt(2, columnas))->inicio, carta); break;
            case 4:
                agregarCarta((getAt(3, columnas))->inicio, carta); break;
            case 5:
                agregarCarta((getAt(4, columnas))->inicio, carta); break;
            case 6:
                agregarCarta((getAt(5, columnas))->inicio, carta); break;
            case 7:
                agregarCarta((getAt(6, columnas))->inicio, carta); break;
            case 8:
                agregarCarta(diamantes, carta); break;
            case 9:
                agregarCarta(corazones, carta); break;
            case 10:
                agregarCarta(picas, carta); break;
            case 11:
                agregarCarta(treboles, carta); break;
        }
    }

    void voltearCartaDe(int columna){
        switch(columna){
            case 1:
                if(!isEmpty((getAt(0, columnas))->inicio))(getAt(0, columnas))->inicio->carta.setVisible(true); break;
            case 2:
                if(!isEmpty((getAt(1, columnas))->inicio))(getAt(1, columnas))->inicio->carta.setVisible(true); break;
            case 3:
                if(!isEmpty((getAt(2, columnas))->inicio))(getAt(2, columnas))->inicio->carta.setVisible(true); break;
            case 4:
                if(!isEmpty((getAt(3, columnas))->inicio))(getAt(3, columnas))->inicio->carta.setVisible(true); break;
            case 5:
                if(!isEmpty((getAt(4, columnas))->inicio))(getAt(4, columnas))->inicio->carta.setVisible(true); break;
            case 6:
                if(!isEmpty((getAt(5, columnas))->inicio))(getAt(5, columnas))->inicio->carta.setVisible(true); break;
            case 7:
                if(!isEmpty((getAt(6, columnas))->inicio))(getAt(6, columnas))->inicio->carta.setVisible(true); break;
        }
    }

    //Metodo para ver la carta que hay en la cima de la pila
    Carta verCarta(NodoPila *&nodo){
        return nodo->carta;
    }

    //Metodo para agregar una carta a la pila
    void agregarCarta(NodoPila *&nodo, Carta carta){
        NodoPila *nuevoNodo = new NodoPila();
        nuevoNodo->carta = carta;
        if(isEmpty(nodo)){
            nuevoNodo->sig = NULL;
            nodo = nuevoNodo;
        }else{
            nuevoNodo->sig = nodo;
            nodo = nuevoNodo;
        }
    }

    //Metodo que sirve para escribir la pila en pantalla
    void escribirPila(NodoPila *&nodo){
        if(!isEmpty(nodo)){
            NodoPila *nodoPila = new NodoPila();
            nodoPila = nodo;
            NodoPila *aux = new NodoPila();
            while((nodoPila->sig)!=NULL){
                Carta carta = nodoPila->carta;
                agregarCarta(aux, carta);
                nodoPila = nodoPila->sig;
            }
            Carta carta = nodoPila->carta;
            agregarCarta(aux, carta);
            nodoPila = nodoPila->sig;
            while(!isEmpty(aux->sig)){
                Carta carta = aux->carta;
                cout<<"|";
                carta.escribirCarta();
                sacarCarta(aux);
            }
            nodoPila = NULL;
            aux = NULL;
            delete nodoPila;
            delete aux;
        }else{
            cout<<"|---";
        }
    }

    //Metodo que sirve para escribir el banco que se ve
    void verBanco(){
        if(isEmpty(banco)){
            while(!isEmpty(bancoVista)){
                Carta carta = bancoVista->carta;
                sacarCarta(bancoVista);
                agregarCarta(banco, carta);
            }
        }else{
            Carta carta = banco->carta;
            sacarCarta(banco);
            agregarCarta(bancoVista, carta);
        }
    }

    //Metodo que sirve para retornar unicamente la carta que está en la cima de una pila
    Carta cartaTopePila(NodoPila *&nodo){
        return (nodo->carta);
    }

//Implementacion de los metodos necesarios para el funcionamiento del juego----------------------------------

    bool verificarVictoria(){
        if((longitud(diamantes)==13)&&(longitud(picas)==13)&&(longitud(treboles)==13)&&(longitud(corazones)==13)){
            return true;
        }else{
            return false;
        }
    }

    //metodo que muestra el menu de juego
    void mostrarMenu(){
        cout<<"Eliga una de las siguientes opciones:"<<endl;
        cout<<"1.- Usar Banco"<<endl;
        cout<<"2.- Mover Carta"<<endl;
        cout<<"3.- Ver Siguiente de una carta"<<endl;
        cout<<"4.- Salir"<<endl;
        cout<<""<<endl;
        cout<<"Por favor ingrese el numero de la opcion que desea realizar: ";
        int opcion = 0;
        cin>>opcion;
        switch(opcion){
            case 1:{
                verBanco(); break;
            }
            case 2:{
                menuMoverCarta(); break;
            }
            case 3:{
                verSiguiente(); break;
            }    
            case 4:{
                valorGlobal = true;
            }
        }
    }

    void verSiguiente(){
        cout<<"Ingrese el numero de columna que desea 'analizar': ";
        int columna;
        cin>>columna;
        cout<<"Ingrese el numero de carta a la cual desea ver el siguiente (de derecha a izquierda):";
        int cantidad;
        cin>>cantidad;
        NodoPila *auxiliar = getColumna(columna);
        if(cantidad<longitud(auxiliar)){
            for (int i = 0; i < cantidad; i++)
            {
                auxiliar = auxiliar->sig;
            }
            cout<<"La carta que le sigue es: ";
            bool valor = auxiliar->carta.getVisible();
            auxiliar->carta.setVisible(true);
            auxiliar->carta.escribirCarta();
            auxiliar->carta.setVisible(valor);
        }else{
            cout<<"La carta seleccionada no tiene un siguiente";
        }
        auxiliar = NULL;
        delete auxiliar;
    }    
    
    //metodo que muestra el menu para mover una carta y verifica que el movimiento sea "valido"
    void menuMoverCarta(){
        cout<<"Por favor ingrese el numero de la columna de la cual desea mover las cartas: ";
        int colSalida;
        cin>>colSalida;
        cout<<"Por favor ingrese el numero de la columna a la cual desea mover las cartas: ";
        int colDestino;
        cin>>colDestino;
        cout<<"Por favor ingrese la cantidad de cartas que desea mover: ";
        int cantidad;
        cin>>cantidad;
        moverCarta(colSalida, colDestino, cantidad);
    }

    //metodo que mueve una carta de una pila a otra
    void moverCarta(int colSalida, int colDestino, int cantidad){
        NodoPila *pilaSalida = getColumna(colSalida);
        NodoPila *pilaDestino = getColumna(colDestino);
        NodoPila *auxiliar = NULL;
        bool huboMovimiento = false;
        if(cantidadDeCartasValida(pilaSalida, cantidad)){
            for (int i = 0; i < cantidad; i++){
                Carta tmp = pilaSalida->carta;
                pilaSalida = pilaSalida->sig;
                sacarCartaDe(colSalida);
                agregarCarta(auxiliar, tmp);
            }
            if((colSalida==0)||(colSalida>7)){//si se saca del banco o de las pilas ordenadas
                if(cantidad==1){//si solo saca una carta
                    if(colDestino>7){//si se quiere mover a una de las pilas ordenadas
                        int tipoDestino;
                        switch(colDestino){
                            case 8: tipoDestino = 0; break;
                            case 9: tipoDestino = 1; break;
                            case 10: tipoDestino = 2; break;
                            case 11: tipoDestino = 3; break;
                        }
                        if((auxiliar->carta.getTipo())==tipoDestino){
                            if(isEmpty(pilaDestino)){//si la pila destino esta vacia
                                if(auxiliar->carta.getValor()==1){//si la carta es un As se apila
                                    Carta carta = auxiliar->carta;
                                    sacarCarta(auxiliar);
                                    agregarCartaA(colDestino, carta);
                                    huboMovimiento = true;
                                }else{//si la carta no es una as
                                    cout<<"No se puede mover una carta que no sea un As a una pila ordenada vacia.";
                                    Carta carta = auxiliar->carta;
                                    sacarCarta(auxiliar);
                                    agregarCartaA(colSalida, carta);
                                }
                            }else{
                                if((auxiliar->carta.getValor())>(pilaDestino->carta.getValor())){
                                    Carta carta = auxiliar->carta;
                                    sacarCarta(auxiliar);
                                    agregarCartaA(colDestino, carta);
                                    huboMovimiento = true;
                                }else{
                                    cout<<"No se puede mover una carta que es menor a la pila.";
                                    Carta carta = auxiliar->carta;
                                    sacarCarta(auxiliar);
                                    agregarCartaA(colSalida, carta);
                                }
                            }
                        }else{
                            cout<<"No se puede mover la carta a las pilas ordenadas no son del mismo tipo.";
                            Carta carta = auxiliar->carta;
                            sacarCarta(auxiliar);
                            agregarCartaA(colSalida, carta);
                        }
                    }else{//si se quiere mover a una de las pilas del juego principal
                        if(compatiblesJuego(auxiliar->carta.getTipo(), (pilaDestino->carta.getTipo()))){//si son compatibles
                            if((auxiliar->carta.getValor())<(pilaDestino->carta.getValor())){//si la carta a mover es menor que la carta en la cima se mueve
                                Carta carta = auxiliar->carta;
                                sacarCarta(auxiliar);
                                agregarCartaA(colDestino, carta);
                                huboMovimiento = true;
                            }else{
                                cout<<"No es un movimiento valido.";
                                Carta carta = auxiliar->carta;
                                sacarCarta(auxiliar);
                                agregarCartaA(colSalida, carta);
                            }
                        }else{//si no son compatibles
                            cout<<"No es un movimiento valido.";
                            Carta carta = auxiliar->carta;
                            sacarCarta(auxiliar);
                            agregarCartaA(colSalida, carta);
                        }
                    }
                }else{//si no se saca una sola carta
                    cout<<"No se puede mover mas de una carta a las pilas ordenadas.";
                    while(!isEmpty(auxiliar)){
                        Carta carta = auxiliar->carta;
                        sacarCarta(auxiliar);
                        agregarCartaA(colSalida, carta);
                    }
                }
            }else{//si se saca de cualquier otra pila que no sea el banco, o las pilas ordenadas
                if(colDestino>7){//si se quiere mover a una de las pilas ordenadas
                    int tipoDestino;
                    switch(colDestino){
                        case 8: tipoDestino = 0; break;
                        case 9: tipoDestino = 1; break;
                        case 10: tipoDestino = 2; break;
                        case 11: tipoDestino = 3; break;
                    }
                    if(cantidad==1){
                        if(auxiliar->carta.getTipo()==tipoDestino){
                            if(isEmpty(pilaDestino)){//si la pila destino esta vacia
                                if(auxiliar->carta.getValor()==1){//si la carta es un As se apila
                                    Carta carta = auxiliar->carta;
                                    sacarCarta(auxiliar);
                                    agregarCartaA(colDestino, carta);
                                    huboMovimiento = true;
                                }else{//si la carta no es una as
                                    cout<<"No se puede mover una carta que no sea un As a una pila ordenada vacia.";
                                    Carta carta = auxiliar->carta;
                                    sacarCarta(auxiliar);
                                    agregarCartaA(colSalida, carta);
                                }
                            }else{
                                if((auxiliar->carta.getValor())>(pilaDestino->carta.getValor())){
                                    Carta carta = auxiliar->carta;
                                    sacarCarta(auxiliar);
                                    agregarCartaA(colDestino, carta);
                                    huboMovimiento = true;
                                }else{
                                    cout<<"No se puede mover una carta que es menor a la pila.";
                                    Carta carta = auxiliar->carta;
                                    sacarCarta(auxiliar);
                                    agregarCartaA(colSalida, carta);
                                }
                            }
                        }else{
                            cout<<"No se puede mover la carta a las pilas ordenadas no son del mismo tipo.";
                            Carta carta = auxiliar->carta;
                            sacarCarta(auxiliar);
                            agregarCartaA(colSalida, carta);
                        }
                    }else{
                        cout<<"No se puede mover mas de una carta a las pilas ordenadas.";
                        while(!isEmpty(auxiliar)){
                            Carta carta = auxiliar->carta;
                            sacarCarta(auxiliar);
                            agregarCartaA(colSalida, carta);
                        }
                    }
                }else{//si se quiere mover a una de las pilas del juego principal
                    if(colDestino==0){
                        cout<<"No se pueden mover cartas al banco";
                        while(!isEmpty(auxiliar)){
                            Carta carta = auxiliar->carta;
                            sacarCarta(auxiliar);
                            agregarCartaA(colSalida, carta);
                        }
                    }else{
                        if(!isEmpty(pilaDestino)){
                            if((auxiliar->carta.getValor())<(pilaDestino->carta.getValor())){
                                if(compatiblesJuego((pilaDestino->carta.getTipo()), (auxiliar->carta.getTipo()))){
                                    while(!isEmpty(auxiliar)){
                                        Carta carta = auxiliar->carta;
                                        sacarCarta(auxiliar);
                                        agregarCartaA(colDestino, carta);
                                        huboMovimiento = true;
                                    }
                                }else{
                                    cout<<"No es un movimiento valido.";
                                    while(!isEmpty(auxiliar)){
                                        Carta carta = auxiliar->carta;
                                        sacarCarta(auxiliar);
                                        agregarCartaA(colSalida, carta);
                                    }
                                }
                            }else{
                                cout<<"No es un movimiento valido";
                                while(!isEmpty(auxiliar)){
                                    Carta carta = auxiliar->carta;
                                    sacarCarta(auxiliar);
                                    agregarCartaA(colSalida, carta);
                                }
                            }
                        }else{
                            if((auxiliar->carta.getValor())==13){
                                while(!isEmpty(auxiliar)){
                                    Carta carta = auxiliar->carta;
                                    sacarCarta(auxiliar);
                                    agregarCartaA(colDestino, carta);
                                    huboMovimiento = true;
                                }    
                            }else{
                                cout<<"Solo se puede poner una K en una pila vacia.";
                                while(!isEmpty(auxiliar)){
                                    Carta carta = auxiliar->carta;
                                    sacarCarta(auxiliar);
                                    agregarCartaA(colSalida, carta);
                                }
                            }
                        }
                    }
                }   
            }
            if(huboMovimiento){
                voltearCartaDe(colSalida);
            }
            pilaSalida = NULL;
            pilaDestino = NULL;
            delete pilaSalida;
            delete pilaDestino; 
            delete auxiliar;
        }else{
            cout<<"No se puede mover la cantidad de cartas que desea."<<endl;
        }
    }

    //metodo que retorna la pila que corresponde segun el numero de columna pasado de argumento;
    NodoPila *getColumna(int columna){
        NodoPila *nodo = NULL;
        switch(columna){
            case 0:{
                nodo = bancoVista; break;
            }
            case 1:{
                nodo = getAt(0, columnas)->inicio; break;
            }
            case 2:{
                nodo = getAt(1, columnas)->inicio; break;
            }
            case 3:{
                nodo = getAt(2, columnas)->inicio; break;
            }
            case 4:{
                nodo = getAt(3, columnas)->inicio; break;
            }
            case 5:{
                nodo = getAt(4, columnas)->inicio; break;
            }
            case 6:{
                nodo = getAt(5, columnas)->inicio; break;
            }
            case 7:{
                nodo = getAt(6, columnas)->inicio; break;
            }
            case 8:{
                nodo = diamantes; break;
            }
            case 9:{
                nodo = corazones; break;
            }
            case 10:{
                nodo = picas; break;
            }
            case 11:{
                nodo = treboles; break;
            }
        }
        return nodo;
    }

    //metodo que verifica que la cantidad de cartas que se desea mover se pueda mover
    bool cantidadDeCartasValida(NodoPila *&nodo, int cantidad){
        bool valor = true;
        if(!isEmpty(nodo)){
            int cantidadCartasVolteadas = 0;
            NodoPila *aux = nodo;
            cantidadCartasVolteadas++;
            while(aux->sig){
                aux = aux->sig;
                if(aux->carta.getVisible())cantidadCartasVolteadas++;
            }   
            aux = NULL;
            delete aux;
            if(cantidad>cantidadCartasVolteadas){
                valor = false;
            }
        }else{
            valor = false;
        }
        return valor;
    }

    //metodo que verifica que una carta puede ponerse sobre otra
    bool compatiblesJuego(int a, int b){
        bool valor = false;
        if((a==0)&&(b==2))valor = true;
        if((a==0)&&(b==3))valor = true;
        if((a==1)&&(b==2))valor = true;
        if((a==1)&&(b==3))valor = true;
        if((a==2)&&(b==0))valor = true;
        if((a==2)&&(b==1))valor = true;
        if((a==3)&&(b==0))valor = true;
        if((a==3)&&(b==1))valor = true;
        return valor;
    }

    //algoritmo que verifica si el numero existe dentro del arreglo numeros
    bool existe(int numero, int numeros[]){
        bool valor = false;
        for (int i = 0; i < 52; i++)
        {
            if(numero==numeros[i])valor=true;
        }
        return valor;
    }

    //algoritmo para obtener un vector de numeros del 1-52 mezclado
    void mezclarCartas(int numeros[], int semilla){
        srand(semilla);
        for (int i = 0; i < 52; i++)
        {
            int numero = (1+(rand()%53));
            while(existe(numero, numeros)){
                numero = (1+(rand()%53));
            }
            numeros[i] = numero;
        }
    }

    //metodo para agregar a cada pila las cartas que le correspondan
    void llenarJuego(int numeros[]){
        for(int i=0; i<7; i++){
            agregarNodoLista(columnas);
        }
        for(int i=0; i<52; i++){
            for(int j=0; j<24; j++){
                Carta carta(numeros[i]);
                carta.setVisible(true);
                agregarCarta(banco, carta);
                i++;//para que siga agreagndo las cartas que siguen
            }
            for(int j=0; j<1; j++){
                Carta carta(numeros[i]);
                carta.setVisible(true);
                agregarCarta(getAt(0,columnas)->inicio, carta);
                i++; //para que siga agregando las cartas que siguen
            }
            for(int j=0; j<2; j++){
                Carta carta(numeros[i]);
                if(j==1)carta.setVisible(true);
                agregarCarta(getAt(1,columnas)->inicio, carta);
                i++;
            }
            for(int j=0; j<3; j++){
                Carta carta(numeros[i]);
                if(j==2)carta.setVisible(true);
                agregarCarta(getAt(2,columnas)->inicio, carta);
                i++;
            }
            for(int j=0; j<4; j++){
                Carta carta(numeros[i]);
                if(j==3)carta.setVisible(true);
                agregarCarta(getAt(3,columnas)->inicio, carta);
                i++;
            }
            for(int j=0; j<5; j++){
                Carta carta(numeros[i]);
                if(j==4)carta.setVisible(true);
                agregarCarta(getAt(4,columnas)->inicio, carta);
                i++;
            }
            for(int j=0; j<6; j++){
                Carta carta(numeros[i]);
                if(j==5)carta.setVisible(true);
                agregarCarta(getAt(5,columnas)->inicio, carta);
                i++;
            }
            for(int j=0; j<7; j++){
                Carta carta(numeros[i]);
                if(j==6)carta.setVisible(true);
                agregarCarta(getAt(6,columnas)->inicio, carta);
                i++;
            }
        }
    }

    //metodo para mostrar todas las cartas en pantalla
    void mostrarCartas(){
        Primero(columnas);
        if(isEmpty(banco)&&isEmpty(bancoVista)){
            cout<<"---|(Col 0): ---||||";
        }
        if(isEmpty(banco)&&!isEmpty(bancoVista)){
            cout<<"---|(Col 0): ";
            bancoVista->carta.escribirCarta();
            cout<<"||||";
        }
        if(!isEmpty(banco)&&isEmpty(bancoVista)){
            cout<<"###|(Col 0): ---||||";
        }
        if(!isEmpty(banco)&&!isEmpty(bancoVista)){
            cout<<"###|(Col 0): ";
            bancoVista->carta.escribirCarta();
            cout<<"||||";
        }
        cout<<"Diamantes(Col 8): ";
        if(isEmpty(diamantes)){
            cout<<"---|";
        }else{
            diamantes->carta.escribirCarta();
            cout<<"|";
        }
        cout<<"Corazones(Col 9): ";
        if(isEmpty(corazones)){
            cout<<"---|";
        }else{
            corazones->carta.escribirCarta();
            cout<<"|";
        }
        cout<<"Picas(Col 10): ";
        if(isEmpty(picas)){
            cout<<"---|";
        }else{
            picas->carta.escribirCarta();
            cout<<"|";
        }
        cout<<"Treboles(Col 11): ";
        if(isEmpty(treboles)){
            cout<<"---|";
        }else{
            treboles->carta.escribirCarta();
            cout<<"|";
        }
        cout<<""<<endl;
        cout<<""<<endl;
        for (int i = 0; i < 7; i++){
            cout<<"Col "<<(i+1)<<": ";
            escribirPila(getAt(i, columnas)->inicio);
            cout<<""<<endl;
        }
    }