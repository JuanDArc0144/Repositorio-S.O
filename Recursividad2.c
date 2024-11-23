#include <stdio.h>


int potencia(int a, int b); //Prototipos de función
int division(int a, int b);
int multiplicar(int a, int b);


int main(){ 
    //Izquierda:Divisor. Derecha:dividendo
    int d = division(3, 6);
    int p = potencia(2,5);
    printf("La division es %d\n", d);
    printf("La potencia es %d\n", p);
}
int division(int a, int b){
    if(b==a){
        return 1;
    }else {
        return 1 + division(a, b - a);
    }
}
int potencia(int a, int b){
    if(b==0){
        return 1;
    }
    else{
        return multiplicar(a, potencia(a, b-1));
    }
    
}
int multiplicar(int a, int b){
    if(b==0){
        return 0;
    } else{
        return a + multiplicar(a, b-1);
    }

}