#include <Servo.h>
/* Automação do robozinho Mark2
 domingo  07/09/2025 
 Fonte de inspiração
 Deus em Jesus Cristo que nos dá forças e a capacidade mental para continuar*/

// Definição de constantes
#define servoGarra 4
#define servoCotovelo 6
#define servoOmbro 5
#define servoBase 3

// Funções para movimento suave dos motores

void moveBaseDireita(const int tempoespera, int inicio, int fim);
void moveBaseEsquerda(const int tempoespera, int inicio, int fim);
void moveOmbroFrente(const int tempoespera, int inicio, int fim);
void moveOmbroTras(const int tempoespera, int inicio, int fim);
void moveCotoveloCima(const int tempoespera, int inicio, int fim); 
void moveCotoveloBaixo(const int tempoespera, int inicio, int fim);


// Funções de Manipulação vai e vem, direita e esquerda
void GuinOrigin(unsigned char baseInicio, unsigned char basefim, unsigned char OmbroInicio, unsigned char Ombrofim, unsigned char CotoveloInicio, unsigned char Cotovelofim);

void GuinOrigin2(unsigned char baseInicio, unsigned char basefim, unsigned char OmbroInicio, unsigned char Ombrofim, unsigned char CotoveloInicio, unsigned char Cotovelofim);
void GuinDestino(unsigned char baseInicio, unsigned char basefim, unsigned char OmbroInicio, unsigned char Ombrofim, unsigned char CotoveloInicio, unsigned char Cotovelofim);
//    positionGuin(BASE INICIAL, BASE FINAL, OMBRO INICIAL, OMBRO FINAL, COTOVELO INICIAL, COTOVELO FINAL, PUNHO INICIAL, PUNHO FINAL);
// Atribuição de objetos (servos do braço)
Servo servo_Base, servo_Ombro, servo_Cotovelo, servo_Garra;

void setup() {
  pinMode(servoGarra, OUTPUT);
  pinMode(servoCotovelo, OUTPUT);
  pinMode(servoOmbro, OUTPUT);
  pinMode(servoBase, OUTPUT);

  servo_Base.attach(3);
  servo_Ombro.attach(5);
  servo_Cotovelo.attach(6);
  servo_Garra.attach(4);
  
//Angulo inicial
servo_Base.write( 135);
delay(3000);
servo_Ombro.write(100);
delay(2000); 
servo_Cotovelo.write(175);
delay(1000); 
servo_Garra.write(150);
delay(500);


   }  //FIM DO SETUP

void loop() {

 // OBJETO 01
          // base    //ombro     //cotovelo
  //        B   B      O   O     C   C
 //INICIO DO OBJETO 1

GuinOrigin(135, 20,     100, 150,       175, 155); 
delay(300);
servo_Garra.write(95); 
 delay(300);

GuinOrigin(20, 20,     150, 100,      155, 175); 
  delay(300);

GuinOrigin2(20, 160,    100, 120,       175, 100); 
delay(300);              
                                      
GuinDestino(160, 160,    120, 120,    130, 130);             
servo_Garra.write(150); 
 delay(2000);       
 
 servo_Base.write(160);
 delay(500); 
servo_Ombro.write(100);
delay(1000); 
servo_Cotovelo.write(175);
delay(1600);

    //ORIGIN ONDE ESTA E ORIGIN DO SETUP                                    
//FIM DO OBJETO 1

// INICIO DO OBJETO 2

  //             base    //ombro     //cotovelo
  //            B   B     O   O        C    C
  GuinOrigin(  160, 20,   100, 150,   175, 155);  
  delay(300);

  servo_Garra.write(95);  
  delay(300);

  GuinOrigin(20, 20, 150, 100, 155, 175);  
  delay(300);

  GuinOrigin2(20, 160, 100, 140, 175, 130);  
  delay(300); 

  servo_Garra.write(150);  
  delay(300); 

  GuinDestino(160, 160, 140, 140, 130, 130);  
servo_Base.write(160);
delay(2000); 
 
 servo_Base.write(160);
 delay(300); 
 servo_Ombro.write(100);
delay(1000); 
servo_Cotovelo.write(175);
delay(1600);
//ORIGIN ONDE ESTA E ORIGIN DO SETUP
// FIM OBJETO 2
//INICIO DO OBJETO 3

GuinOrigin(160, 20,       100, 150,       175, 155);
 delay(300);

servo_Garra.write(95); 
 delay(300);

GuinOrigin(20, 20,       150, 100,       155, 175);
 delay(300);

GuinOrigin2(20, 140,       100, 120,       175,100);
 delay(300);             
servo_Garra.write(150); 
 delay(300);  

GuinDestino(140, 140,   120, 120,    100, 100); 
delay(2000);             
  
servo_Base.write(140);
delay(300); 
servo_Ombro.write(100);
delay(1000); 
servo_Cotovelo.write(175);
delay(1600);
// FIM DO OBJETO 3

//INICIO DO OBJETO 4

GuinOrigin(140, 20, 100, 150, 175, 155);
 delay(1000);

servo_Garra.write(95); 
 delay(1000);

GuinOrigin(20, 20, 150, 100, 155, 175); 
  delay(1000);

GuinOrigin2(20, 135, 100, 135, 175, 140);
 delay(1000);              
                                      
GuinDestino(135, 135, 135, 135, 140, 140);             
servo_Garra.write(150);          
  delay(2000);

servo_Base.write(135);
delay(300); 
servo_Ombro.write(100);
delay(1000); 
servo_Cotovelo.write(175);
delay(1600);
// FIM DO OBJETO 4

}

                 // unsigned utiliza de zero a 255 e char(variaveis de 8 bits) vai de zero a -128 bits a 127
void GuinOrigin(unsigned char baseInicio, unsigned char basefim, unsigned char OmbroInicio, unsigned char Ombrofim, unsigned char CotoveloInicio, unsigned char Cotovelofim) {
  // Movimenta a base

  if (baseInicio < basefim) {
    moveBaseDireita(30, baseInicio, basefim);  //move a base para direita
    delay(100);
  } else {
    moveBaseEsquerda(30, baseInicio, basefim);  //move a base para esquerda
    delay(100);
  }
  // Fim movimentação da base

  // Movimenta o cotovelo
  if (CotoveloInicio < Cotovelofim) {
    moveCotoveloCima(20, CotoveloInicio, Cotovelofim);
    delay(100);
  } else {
    moveCotoveloBaixo(20, CotoveloInicio, Cotovelofim);
    delay(100);
  }
  //Fim da  movimentação do cotovelo

  // Movimenta o ombro
  if (OmbroInicio < Ombrofim) {
    moveOmbroFrente(20, OmbroInicio, Ombrofim);
    delay(100);
  } else {
    moveOmbroTras(20, OmbroInicio, Ombrofim);
    delay(100);
  }
  // Fim da movimentação do ombro
  //Fim da movimentação
}

void GuinOrigin2(unsigned char baseInicio, unsigned char basefim, unsigned char OmbroInicio, unsigned char Ombrofim, unsigned char CotoveloInicio, unsigned char Cotovelofim) {  // Movimenta a base
  if (baseInicio < basefim) {
    moveBaseDireita(30, baseInicio, basefim);  //move a base para direita
    delay(100);
  } else {
    moveBaseEsquerda(30, baseInicio, basefim);  //move a base para esquerda
    delay(100);
  }
  // Fim movimentação da base
  // Movimenta o cotovelo
  if (CotoveloInicio < Cotovelofim) {
    moveCotoveloCima(20, CotoveloInicio, Cotovelofim);
    delay(100);
  } else {
    moveCotoveloBaixo(20, CotoveloInicio, Cotovelofim);
    delay(100);
  }
  //Fim da  movimentação

  // Movimenta o ombro
  if (OmbroInicio < Ombrofim) {
    moveOmbroFrente(20, OmbroInicio, Ombrofim);
    delay(100);
  } else {
    moveOmbroTras(20, OmbroInicio, Ombrofim);
    delay(100);
  }
  // Fim da movimentação do ombro

}  //Fim da movimentação guinOrigen2

void GuinDestino(unsigned char baseInicio, unsigned char basefim, unsigned char OmbroInicio, unsigned char Ombrofim, unsigned char CotoveloInicio, unsigned char Cotovelofim) {  // Movimenta a base
  if (baseInicio < basefim) {
    moveBaseDireita(30, baseInicio, basefim);  //move a base para direita
    delay(100);
  } else {
    moveBaseEsquerda(30, baseInicio, basefim);  //move a base para esquerda
    delay(100);
  }
  // Fim movimentação da base

  // Movimenta o cotovelo
  if (CotoveloInicio < Cotovelofim) {
    moveCotoveloCima(20, CotoveloInicio, Cotovelofim);
    delay(100);
  } else {
    moveCotoveloBaixo(20, CotoveloInicio, Cotovelofim);
    delay(100);
  }
  //Fim da  movimentação do cotovelo

  // Movimenta o ombro
  if (OmbroInicio < Ombrofim) {
    moveOmbroFrente(20, OmbroInicio, Ombrofim);
    delay(100);
  } else {
    moveOmbroTras(20, OmbroInicio, Ombrofim);
    delay(100);
  }
  // Fim da movimentação do ombro

}  //Fim do GuinDestino

//FIM DO LAÇO FOR
//FIM DO MOVE
void moveCotoveloCima(const int tempoespera, int inicio, int fim) {
  //Tempo sugerido é de 10 ms(servos de auto torque
  for (int i = inicio; i < fim; i++) {
    servo_Cotovelo.write(i);
    delay(tempoespera);
    //Fim do movimento do cotovelo para cima ++
  }  //FIM DO LAÇO FOR
}  //FIM DO MOVE
void moveCotoveloBaixo(const int tempoespera, int inicio, int fim) {
  for (int i = inicio; i > fim; i--) {
    servo_Cotovelo.write(i);
    delay(tempoespera);

    //Fim do movimento do cotovelo para baixo --
  }  //FIM DO LAÇO FOR
}  //FIM DO MOVE
void moveOmbroFrente(const int tempoespera, int inicio, int fim) {
  for (int i = inicio; i < fim; i++) {
    servo_Ombro.write(i);
    delay(tempoespera);

    //Fim do movimento do ombro para frente ++
  }  //FIM DO LAÇO FOR
}  //FIM DO MOVE
void moveOmbroTras(const int tempoespera, int inicio, int fim) {
  for (int i = inicio; i > fim; i--) {
    servo_Ombro.write(i);
    delay(tempoespera);
    //Fim do movimento do ombro para tras --
  }  //FIM DO LAÇO FOR
}  //FIM DO MOVE
void moveBaseDireita(const int tempoespera, int inicio, int fim) {
  for (int i = inicio; i < fim; i++) {
    servo_Base.write(i);
    delay(tempoespera);

    //Fim do movimento da base para direita ++
  }  //FIM DO LAÇO FOR
}  //FIM DO MOVE
void moveBaseEsquerda(const int tempoespera, int inicio, int fim) {
  for (int i = inicio; i > fim; i--) {
    servo_Base.write(i);
    delay(tempoespera);

    //Fim do movimento da base para esquerda--
  }  //FIM DO LAÇO FOR
  
}  //FIM DO MOVE
   //FIM DA PROGRAMAÇÃO
