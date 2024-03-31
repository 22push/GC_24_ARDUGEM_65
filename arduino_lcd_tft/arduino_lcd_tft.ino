
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <Wire.h>
#include <Adafruit_ILI9341.h>
#define TFT_CS     10
#define TFT_RST    12
#define TFT_DC     9
#define TFT_WIDTH  128
#define TFT_HEIGHT 128
#define SHIP_WIDTH  5
#define SHIP_HEIGHT 5
#define BLOCK_WIDTH  10
#define BLOCK_HEIGHT 10
#define	BLACK   0x0000
#define	RED     0x001F
#define	BLUE    0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0  
#define WHITE   0xFFFF
static const unsigned char PROGMEM PROGMEM goingcar[] =  {
0x3f, 0xfc, 
0x7f, 0xfe, 
0xff, 0xff, 
0xff, 0xff, 
0xf8, 0x1f, 
0xe0, 0x07, 
0xc0, 0x03, 
0xc0, 0x03, 
0xc0, 0x03, 
0xa0, 0x05, 
0x90, 0x09, 
0x9f, 0xf9, 
0x9f, 0xf9, 
0x9f, 0xf9, 
0x9f, 0xf9, 
0x9f, 0xf9, 
0x9f, 0xf9, 
0x9f, 0xf9, 
0x9f, 0xf9, 
0xb8, 0x1d, 
0xe0, 0x07, 
0xe0, 0x07, 
0x7f, 0xfe, 
0x3f, 0xfc
};
static const unsigned char PROGMEM PROGMEM upcomingcar[] =  {
0x3f, 0xfc, 
0x7f, 0xfe, 
0xe0, 0x07, 
0xe0, 0x07, 
0xb8, 0x1d, 
0x9f, 0xf9, 
0x9f, 0xf9, 
0x9f, 0xf9, 
0x9f, 0xf9, 
0x9f, 0xf9, 
0x9f, 0xf9, 
0x9f, 0xf9, 
0x9f, 0xf9, 
0x90, 0x09, 
0xa0, 0x05, 
0xc0, 0x03, 
0xc0, 0x03, 
0xc0, 0x03, 
0xe0, 0x07, 
0xf8, 0x1f, 
0xff, 0xff, 
0xff, 0xff, 
0x7f, 0xfe, 
0x3f, 0xfc
};
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
#define INITIAL_CAR_SPEED 3
int MAX_CAR_SPEED = 15;
#define SPEED_INCREMENT_INTERVAL 10000
int CAR_SPEED =3;
unsigned long lastSpeedUpdateTime = 0;
int up_button = 2;
int down_button = 4;
int left_button = 5;
int right_button = 3;
int start_button = 6;
int select_button = 7;
int joystick_button = 8;
int play=0;
int playcarrace=0;
int z=0;
int x=0;
int y=0;
int playc=0;
int score = 0;
#define JOY_X 0 // Analog pin connected to joystick X-axis
#define JOY_Y 1 // Analog pin connected to joystick Y-axis
int carX =78;
int carY = 104; 
int joyx=0;
int joyy=0;
int CAR_HEIGHT=24;
int CAR_WIDTH=16;
int car1Y, car2Y, car3Y;
int car1X, car2X, car3X;
int playerscore =0;
int takedata=1;
int playpong = 0;
int shipX = 64;
int shipY = 64; 
float directionX; 
float directionY;
int ratepX =0;
int ratenX =-1;
int ratepY = 0;
int ratenY = -1; 
int xpos = 44;
int ypos = 5;
int direc = 5;
int ownposx = 44;
int joyX = 332;
int joyY = 332;
int win = 0;
void Firstscreen() {
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.setCursor(35, 40); 
  tft.println("Hii..");
  tft.setTextSize(2);
  tft.setCursor(23, 65); 
  tft.println("Welcome");
  delay(5000);
  play = 1;
  tft.fillScreen(BLACK);
}
void Showgames(){
  tft.setTextColor(RED);
  tft.setTextSize(2);
  tft.setCursor(30, 20); 
  tft.println("Select");
  tft.setTextSize(2);
  tft.setCursor(40, 40);
  tft.println("Game");
  if(z==0){
      tft.setTextColor(BLUE);
  tft.setTextSize(1);
  tft.setCursor(35, 65); 
  tft.println("1. Pong ");
  tft.setTextColor(WHITE);
  tft.setTextSize(1);
  tft.setCursor(35, 80);
  tft.println("2. Car Race");
  }
  static int select=2;
  if (digitalRead(up_button) == LOW) {
    select = 2;
    z=1;
      tft.setTextColor(BLUE);
    tft.setTextSize(1);
    tft.setCursor(35, 65); 
    tft.println("1. Pong ");
    tft.setTextColor(WHITE);
    tft.setTextSize(1);
    tft.setCursor(35, 80);
    tft.println("2. Car Race");
  } 
  else if (digitalRead(down_button) == LOW) {
    select = 3; 
    z=1;
    tft.setTextColor(WHITE);
    tft.setTextSize(1);
    tft.setCursor(35, 65); 
    tft.println("1. Pong ");
    tft.setTextColor(BLUE);
    tft.setTextSize(1);
    tft.setCursor(35, 80);
    tft.println("2. Car Race");
  }
  if (digitalRead(start_button) == 0) {
      play=select;
      select=2;
      z=0;
      tft.fillScreen(BLACK);
      }
  delay(50);
}
void carraceinterface(String S){
   tft.setTextColor(RED);
  tft.setTextSize(2);
  tft.setCursor(20, 20); 
  tft.println(S);
  if(x==0){
      tft.setTextColor(BLUE);
  tft.setTextSize(1);
  tft.setCursor(35, 65); 
  tft.println("1. Play ");
  tft.setTextColor(WHITE);
  tft.setTextSize(1);
  tft.setCursor(35, 80);
  tft.println("2. Rules");
  }
  static int select=1;
  if (digitalRead(up_button) == LOW) {
    select = 1;
    x=1;
      tft.setTextColor(BLUE);
    tft.setTextSize(1);
    tft.setCursor(35, 65); 
    tft.println("1. Play ");
    tft.setTextColor(WHITE);
    tft.setTextSize(1);
    tft.setCursor(35, 80);
    tft.println("2. Rules");
  } 
  else if (digitalRead(down_button) == LOW) {
    select = 2;
    x=1;
    tft.setTextColor(WHITE);
    tft.setTextSize(1);
    tft.setCursor(35, 65); 
    tft.println("1. Play");
    tft.setTextColor(BLUE);
    tft.setTextSize(1);
    tft.setCursor(35, 80);
    tft.println("2. Rules");
  }
  if (digitalRead(start_button) == 0) {
      playcarrace=select;
      select=1;
      tft.fillScreen(BLACK);
      x=0;
      }
  delay(50);
}
void playgamecarrace(){
  switch (playc) {
        case 0:
          handleUserInput();
          showscore();
          moveCar();
          drawTrack();
          randomCarGenerate();
          updateCarSpeed();
          cheackcollision();
          delay(50);
          break;
        case 1:
          showfinalscore();
          break;
    } 
}
void rulespong(){
  tft.setTextColor(RED);
  tft.setTextSize(2);
  tft.setCursor(35, 5); 
  tft.println("Rules");
  tft.setTextColor(WHITE);
  tft.setTextSize(1);
  tft.setCursor(6, 24); 
  tft.println("1.Control the blue paddle using the joystick to hit the ball.");
  tft.setCursor(6, 58); 
  tft.println("2.Prevent the ball from reaching the bottom of the screen by hitting it with the paddle.");
  tft.setCursor(6, 91); 
  tft.println("3.The game ends when the player fails to hit the ball and it reaches the bottom of the screen.");
  playcarrace=0;
  delay(5000);
  tft.fillScreen(BLACK);
}
void rulescarrace(){
   tft.setTextColor(RED);
  tft.setTextSize(2);
  tft.setCursor(35, 5); 
  tft.println("Rules");
  tft.setTextColor(WHITE);
  tft.setTextSize(1);
  tft.setCursor(6, 24); 
  tft.println("1.Control the white car using the joystick to avoid collisions with other cars.");
  tft.setCursor(6, 58); 
  tft.println("2.Navigate through the track lanes to avoid obstacles.");
  tft.setCursor(6, 91); 
  tft.println("3.The game ends when the player's car collides with another car on the track.");
  playcarrace=0;
  delay(5000);
  tft.fillScreen(BLACK);
}
void handleUserInput() {
  joyx = analogRead(JOY_X)-332;
  joyy = analogRead(JOY_Y)-332;
}

void moveCar() {
  int newcarX= carX+joyx/40;
  int newcarY= carY-joyy/40;
  if (newcarX < 0) {
    newcarX = 0;
  } else if (newcarX + CAR_WIDTH > 128) {
    newcarX = newcarX - CAR_WIDTH;
  }
  if (newcarY < 0) {
    newcarY = 3;
  } else if (newcarY + CAR_HEIGHT > 128) {
    newcarY = newcarY - CAR_HEIGHT+3;
  }
  tft.drawBitmap(carX,carY,goingcar,16,24,BLACK);
  tft.drawBitmap(newcarX,newcarY,goingcar,16,24,0xFFFF); 
  carX= newcarX;
  carY= newcarY;
}

void drawTrack() {
  // Draw the race track
  tft.drawLine(32, 0, 32, 128, WHITE);
  tft.drawLine(64, 0, 64, 128, WHITE);
  tft.drawLine(96, 0, 96, 128, WHITE);
}


void randomCarGenerate() {
  int a= random(1,100);
  int b= random(1,100);
  int c= random(1,100);
  static unsigned long lastUpdateTime = 0;
  unsigned long currentTime = millis();
  
  if (currentTime - lastUpdateTime >= 0.3) {
    lastUpdateTime = currentTime;
    tft.drawBitmap(car1X,car1Y,upcomingcar,16,24,BLACK);
    tft.drawBitmap(car2X,car2Y,upcomingcar,16,24,BLACK);
    tft.drawBitmap(car3X,car3Y,upcomingcar,16,24,BLACK);
    car1Y += CAR_SPEED;
    car2Y += CAR_SPEED;
    car3Y += CAR_SPEED;
    tft.drawBitmap(car1X,car1Y,upcomingcar,16,24,RED);
    tft.drawBitmap(car2X,car2Y,upcomingcar,16,24,CYAN);
    tft.drawBitmap(car3X,car3Y,upcomingcar,16,24,GREEN);
    if (car1Y >= TFT_HEIGHT + CAR_HEIGHT) {
      car1Y = -a;
      score++; 
      int lane = random(4);
      switch (lane) {
        case 0:
          car1X = 12; 
          break;
        case 1:
          car1X = 43; 
          break;
        case 2:
          car1X = 78; 
          break;
        case 3:
          car1X = 107; 
          break;
      }
    }
    if (car3Y >= TFT_HEIGHT + CAR_HEIGHT) {
      car3Y = -c;
      score++;
      int lane = random(4);
      switch (lane) {
        case 0:
          car3X = 12;
          break;
        case 1:
          car3X = 43;
          break;
        case 2:
          car3X = 78;
          break;
        case 3:
          car3X = 107;
          break;
      }
    }
    if (car2Y >= TFT_HEIGHT + CAR_HEIGHT) {
      car2Y = -b;
      score++; 
      int lane = random(4); 
      switch (lane) {
        case 0:
          car2X = 12;
          break;
        case 1:
          car2X = 43;
          break;
        case 2:
          car2X = 78;
          break;
        case 3:
          car2X = 107;
          break;
      }
    }
  }
}
void showscore(){
  // tft.fillScreen(BLACK); // Clear the screen
  tft.setTextColor(BLACK); // Set text color to white
  tft.setTextSize(1); // Set text size to 2
  tft.setCursor(10, 5); 
   tft.print("Score:-"); // Set cursor position
  tft.print(score-1);
  tft.setTextColor(WHITE); // Set text color to white
  tft.setTextSize(1); // Set text size to 2
  tft.setCursor(10, 5);
  tft.print("Score: ");  // Set cursor position
  tft.print(score); // Display "Pong" text
}
void showfinalscore(){
  tft.fillScreen(BLACK);
  tft.setTextColor(MAGENTA); 
  tft.setTextSize(3);
  tft.setCursor(27, 10);
  tft.print("GAME");
  tft.setTextColor(MAGENTA); 
  tft.setTextSize(3);
  tft.setCursor(27, 40);
  tft.print("OVER");
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.setCursor(10, 70);
  tft.print("Score:");
  tft.print(score);
  play=1;
  playc=0;
  delay(6000);
  tft.fillScreen(BLACK);
  carX =78; 
  carY = 104;
  car1Y=-30;
  car2Y=0;
  car3Y=-60;
  CAR_SPEED=3;
  score=0;
  playcarrace=0; 
}
void cheackcollision(){

  if (carY + CAR_HEIGHT >= car1Y && carY <= car1Y + CAR_HEIGHT &&
        carX + CAR_WIDTH >= car1X && carX <= car1X + 15) {
      Serial.println("Collision with Car 1!");
      playc=1;
    }
    if (carY + CAR_HEIGHT >= car2Y && carY <= car2Y + CAR_HEIGHT &&
        carX + CAR_WIDTH >= car2X && carX <= car2X + 15) {
      Serial.println("Collision with Car 2!");
      playc=1;
    }
    if (carY + CAR_HEIGHT >= car3Y && carY <= car3Y + CAR_HEIGHT &&
        carX + CAR_WIDTH >= car3X && carX <= car3X + 15) {
      Serial.println("Collision with Car 3!");
    playc=1;
    }
}
void updateCarSpeed() {
  unsigned long currentTime = millis();
  if (currentTime - lastSpeedUpdateTime >= SPEED_INCREMENT_INTERVAL) {
    lastSpeedUpdateTime = currentTime;
    if (CAR_SPEED < MAX_CAR_SPEED) {
      CAR_SPEED=CAR_SPEED+1;
    }
  }
}
void moveShipLinearly() {
  int newShipX = shipX + directionX;
  int newShipY = shipY + directionY;
  if (newShipX < 0 || newShipX + SHIP_WIDTH > TFT_WIDTH) {
    if(newShipX + SHIP_WIDTH > TFT_WIDTH){
      directionX = random(-10, -3);
      Serial.print(directionX);
    }
    else {
      directionX = random(4, 10);
      Serial.print(directionX);
    }
    newShipX = shipX + directionX;
  }

  if (newShipY <= 6 && newShipX <= xpos+74 &&  newShipX >= xpos-4) {
      directionY = random(1, 10);
    }
  else if (newShipY < 6  && ( newShipX < xpos-4 ||  newShipX > xpos+74 )){
      directionY=0;
      directionX=0;
      direc=0;
      takedata=0;
      win=0;
      playpong=1;
  }
  if( newShipY > 123 && newShipX <= ownposx+44 &&  newShipX >= ownposx-4){
    directionY = random(-10, -7);
  }
  
  else if(newShipY > 120 && (newShipX < ownposx-4 ||  newShipX > ownposx+44)) {
    directionY=0;
    directionX=0;
    direc=0;
    takedata=0;
    win=1;
    playpong=1;
  }
   
    newShipY = shipY + directionY;
    newShipX = shipX + directionX;
  tft.fillCircle(shipX, shipY, 3, ILI9341_BLACK);
  tft.fillCircle(newShipX, newShipY, 3, ILI9341_BLUE);

  shipX = newShipX;
  shipY = newShipY;
}
void comppaddle(){
  int newxpos = xpos + direc;
  if(newxpos <0 || newxpos + 70 > TFT_WIDTH){
    direc = -direc;
  }
  tft.fillRect(xpos, 5, 70, 5, ILI9341_BLACK);
  tft.fillRect(newxpos, 5, 70, 5, 0xF81F);
  xpos=newxpos;
}

void moveownrect(){
  if(takedata==1){
     joyX = analogRead(JOY_X)-332;
    joyY = analogRead(JOY_Y);
  }
  int newownposx = ownposx + joyX/25;
  if(newownposx<0){
    newownposx = 0;
  }
  if(newownposx + 40 > TFT_WIDTH){
    newownposx = 88;
  }
  tft.fillRect(ownposx, 120, 40, 5, ILI9341_BLACK);
  tft.fillRect(newownposx, 120, 40, 5, ILI9341_RED);
  ownposx=newownposx;
}
void pongscore(){
  tft.fillScreen(BLACK);
  tft.setTextColor(MAGENTA);
  tft.setTextSize(3);
  tft.setCursor(27, 10);
  tft.print("GAME");
  tft.setTextColor(MAGENTA);
  tft.setTextSize(3);
  tft.setCursor(27, 40);
  tft.print("OVER");
  tft.setTextColor(WHITE); 
  tft.setTextSize(2);
  tft.setCursor(25, 80);
  if(win==0){
    tft.print("YOU WIN");
  }
  else {
    tft.print("YOU LOST");
  }
  delay(5000);
   directionY=5;
    directionX=7;
    direc=4;
    takedata=1;
    win=0;
    playpong=0;
    playcarrace=0;
    play=1;
    shipX=64;
    shipY=64;
    tft.fillScreen(BLACK);
}
void playgamepong() {
  switch (playpong) {
        case 0:
          moveShipLinearly();
          comppaddle();
          moveownrect();
          break;
        case 1:
          pongscore();
          break;
      }
      delay(70);
}
void pong(){
  switch (playcarrace) {
        case 0:
          carraceinterface("--PONG--");
          break;
        case 1:
          playgamepong();
          break;
        case 2:
          rulespong();
          break;
      }
}
void carrace(){
  switch (playcarrace) {
        case 0:
          carraceinterface("Car Race");
          break;
        case 1:
          playgamecarrace();
          break;
        case 2:
          rulescarrace();
          break;
      }
}
void setup() {
  tft.initR(INITR_BLACKTAB);
  tft.fillScreen(BLACK);
  directionX=random(4,8);
  directionY=random(4,8);
  Serial.begin(9600);
}
void loop(){
  switch (play) {
        case 0:
          Firstscreen();
          break;
        case 1:
          Showgames();
          break;
        case 2:
          pong();
          break;
        case 3:
          carrace();
          break;
      }
}