#include <CheapStepper.h>
#include <Servo.h>

// SERVOS
#define CLAW_SERVO 9
#define WRIST_SERVO 8

// DELAYS
#define DELAY_TURN 1000 // Tempo para girar a garra
#define DELAY_OPEN 400 // Tempo para abrir a garra
#define DELAY_CLOSE 400 // Tempo para fechar a garra
#define DELAY_MOVE 10 // Tempo para mover o eixo 1mm

// PARAMS
#define AXIS_SIZE 145 // Tamanho do eixo em graus
#define AXIS_MM 5.25 // 1mm em graus
#define CLAW_OPEN 35 // Ângulo para abrir a garra
#define CLAW_CLOSE 90 // Ângulo para fechar a garra

// ACTIONS
#define ACTION_RESET 0
#define ACTION_DEMO 1

Servo claw, claw_wrist;
CheapStepper axis(2, 3, 4, 5);

void setup ()
{
  Serial.begin(9600);
  axis.setRpm(20);
}

void loop() {
  while (Serial.available() == 0);
  
  int action = Serial.parseInt();

  switch(action) {
    case ACTION_RESET: reset(); break;
    case ACTION_DEMO: demo(); break;
  }
}

void demo() {
  claw_open();
  claw_turn_cw();
  claw_close();
  move(AXIS_SIZE);
  claw_open();
}

void reset() {
  claw_close();
  claw_turn_ccw();
  move(-AXIS_SIZE);
  claw_open();
}

void claw_open()
{
  claw.attach(CLAW_SERVO);
  claw.write(CLAW_OPEN);
  delay(DELAY_OPEN);
  claw.detach();
}

void claw_close()
{
  claw.attach(CLAW_SERVO);
  claw.write(CLAW_CLOSE);
  delay(DELAY_CLOSE);
  claw.detach();
}

void claw_turn_cw()
{
  claw_wrist.attach(WRIST_SERVO);
  claw_wrist.write(0);
  delay(DELAY_TURN);
  claw_wrist.detach();
}

void claw_turn_ccw()
{
  claw_wrist.attach(WRIST_SERVO);
  claw_wrist.write(90);
  delay(DELAY_TURN);
  claw_wrist.detach();
}

void move(int val) {
  axis.moveDegrees(val > 0, abs(val * AXIS_MM));
  delay(DELAY_MOVE * abs(val));
}