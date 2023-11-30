#include <stdio.h>

// Structs
int main(void){

  struct horario{
    int hora;
    int minuto;
    int segundo;
  }

  struct horario agora, *depois; 
  depois = &agora; 

  *depois.hora = 20; //da errado pq tem precedencia de sinais
  (*depois).hora = 20; //da certo pq ele pega o ponteiro certinho 
  (*depois).minuto = 20;
  (*depois).segundo = 20;

  (*depois)->hora = 20; 
  (*depois)->minuto = 20;
  (*depois)->segundo = 20;


}

// Operações Matemáticas
int main(void){

  struct horario{
    int hora;
    int minuto;
    int segundo;
  }

  struct horario agora, *depois; 
  depois = &agora; 

  (*depois)->hora = 20; 
  (*depois)->minuto = 80;
  (*depois)->segundo = 50;


  int somatorio = 100;
  struct horario antes;

  antes.hora = somatorio + depois->segundo;
  antes.minuto = agora.hora + depois->segundo;
  antes.segundo = depois->minuto + depois->segundo;


}





/*
RESUMO



*/