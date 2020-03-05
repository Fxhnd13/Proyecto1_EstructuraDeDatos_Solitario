#include "Carta.hpp"

bool Carta::getVisible(){
    return visible;
}

void Carta::setVisible(bool parametro){
    visible = parametro;
}

int Carta::getValor(){
    return valor;
}


void Carta::setValor(int parametro){
    valor = parametro;
}

int Carta::getTipo(){
    return tipo;
}

void Carta::setTipo(int parametro){
    tipo = parametro;
}

void Carta::escribirCarta(){
    if(visible){
        if(tipo==(-1)){
            cout<<"Vacio";
        }
        if(tipo==0){
            if(valor==1){
                cout<<"A<>";
            }else{
                if(valor<11){
                    cout<<valor<<"<>";
                }else{
                    if(valor==11)cout<<"J<>";
                    if(valor==12)cout<<"Q<>";
                    if(valor==13)cout<<"K<>";
                }
            }
        }
        if(tipo==1){
            if(valor==1){
                cout<<"A<3";
            }else{
                if(valor<11){
                    cout<<valor<<"<3";
                }else{
                    if(valor==11)cout<<"J<3";
                    if(valor==12)cout<<"Q<3";
                    if(valor==13)cout<<"K<3";
                }
            }
        }
        if(tipo==2){
            if(valor==1){
                cout<<"A!!";
            }else{
                if(valor<11){
                    cout<<valor<<"!!";
                }else{
                    if(valor==11)cout<<"J!!";
                    if(valor==12)cout<<"Q!!";
                    if(valor==13)cout<<"K!!";
                }
            }
        }
        if(tipo==3){
            if(valor==1){
                cout<<"AE3";
            }else{
                if(valor<11){
                    cout<<valor<<"E3";
                }else{
                    if(valor==11)cout<<"JE3";
                    if(valor==12)cout<<"QE3";
                    if(valor==13)cout<<"KE3";
                }
            }
        }
    }else{
        cout<<"###";
    }
}