#include <CheapStepper.h>
#include <Servo.h>

// PORTS
#define CLAW_SERVO A2 // Porta analógica 0
#define WRIST_SERVO A3 // Porta analógica 1

// DELAYS
#define DELAY_TURN 1000 // Tempo para girar a garra
#define DELAY_OPEN 400 // Tempo para abrir a garra
#define DELAY_CLOSE 400 // Tempo para fechar a garra
#define DELAY_MOVE 10 // Tempo para mover o eixo 1mm

// PARAMS
#define NIVEIS 5 // Quantidade de níveis a construir
#define PIECE_HEIGHT 155 // Altura da peça
#define PIECE_WIDTH 210 // Largura da peça
#define DIMENSION 2000 // Tamanho dos lados da área de ação da garra
#define AXIS_TOTAL 760 // Tamanho do eixo em graus
#define AXIS_MM 5.25 // 1mm em graus
#define CLAW_OPEN 35
#define CLAW_CLOSE 90

#define ACTION_RESET 0
#define ACTION_DEMO 1

Servo claw, claw_wrist;
CheapStepper x1(0, 1, 2, 3), x2(4, 5, 6, 7), y(8, 9, 10, 11), z(12, 13, A0, A1);

void setup ()
{
  Serial.begin(9600);
  x1.setRpm(20);

  for(int i = 0; i < NIVEIS; i++) {
   
    move_z(-PIECE_HEIGHT);
    claw_close();
    move_z(PIECE_HEIGHT*(i+1));
    
    for(int j = 0; j < 3; j++) {
    
      if (i % 2 == 0) {
        place_even(j);
      } else {
        place_odd(j);
      }
    
    }
    
    move_z(-PIECE_HEIGHT*i);
    
  }
  
}

void place_even(int i) {
  move_x(DIMENSION / 2 + PIECE_WIDTH * i);
  move_y(DIMENSION / 2);
  move_z(-PIECE_HEIGHT);
  claw_open();
  move_z(PIECE_HEIGHT);
  move_y(-DIMENSION / 2);
  move_x(-(DIMENSION / 2 + PIECE_WIDTH * i));
}

void place_odd(int i) {
  move_x(DIMENSION / 2 + PIECE_WIDTH);
  move_y(DIMENSION / 2 + PIECE_WIDTH * (i - 1));
  claw_turn_cw();
  move_z(-PIECE_HEIGHT);
  claw_open();
  move_z(PIECE_HEIGHT);
  claw_turn_ccw();
  move_y(-(DIMENSION / 2 + PIECE_WIDTH * (i - 1)));
  move_x(-(DIMENSION / 2 + PIECE_WIDTH));
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

void move(CheapStepper motor, int val) {
  motor.moveDegrees(val > 0, abs(val * AXIS_MM));
  delay(DELAY_MOVE * abs(val));
}

void move_x(int val) {
  move(x1, val);
  //move(x2, val);
}

void move_y(int val) {
  move(y, val);
  delay(val * DELAY_MOVE);
}

void move_z(int val) {
  move(z, val);
  delay(val * DELAY_MOVE);
}