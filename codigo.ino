#include "Ultrasonic.h"
const int echoPin = 7;
const int trigPin = 6;

int led_vermelho = 10;
int led_azul = 9;
int led_verde = 8;

Ultrasonic ultrasonic(trigPin, echoPin);

int distancia;
String resultadoS;

void setup() {
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);

  pinMode(led_vermelho, OUTPUT);
  pinMode(led_azul, OUTPUT);
  pinMode(led_verde, OUTPUT);

  Serial.begin(9600);
}
void loop() {
  lerDistancia();
  ligarLED();
}

void lerDistancia() {
  distancia = ultrasonic.Ranging(CM);
  resultadoS = String(distancia);
  Serial.println("Distancia " + resultadoS + " cm.");
  delay(100);
}

void desligarLED() {
  digitalWrite(led_vermelho, LOW);
  digitalWrite(led_verde, LOW);
  digitalWrite(led_azul, LOW);
}

void ligarVermelho() {
  desligarLED();
  digitalWrite(led_vermelho, HIGH);
}

void ligarAmarelo() {
  desligarLED();
  digitalWrite(led_vermelho, HIGH);
  digitalWrite(led_verde, HIGH);
}

void ligarVerde() {
  desligarLED();
  digitalWrite(led_verde, HIGH);
}

void ligarLED() {

  if (distancia < 5) {
    Serial.println("PERTO");
    ligarVermelho();
  }
  else if (distancia >= 5 && distancia < 14) {
    Serial.println("NORMAL");
    ligarAmarelo();
  }
  else if (distancia >= 14 && distancia < 30) {
    Serial.println("LONGE");
    ligarVerde();
  }
}
