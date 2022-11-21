#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <string.h>


bool move1 = false;

bool move2 = false;

bool clicked = false;

float ballX = 0;
float ballY = 0;

int speed=26;

int red = 0;
int green = 0;
int blue = 0;

int time1 = 0;


float player1X = 0;
float player1Y = 0;
float player2X = 0;
float player2Y = 0;
bool RightPlayer1 ,LeftPlayer1,UpPlayer1,DownPlayer1;
bool RightPlayer2 ,LeftPlayer2,UpPlayer2,DownPlayer2;

float DistanceBetween1 = 0;
float DistanceBetween2 = 0;

int score1=0;
int score2=0;



void drawCircle(int x, int y, float r);
void Key(unsigned char key, int x, int y);
void Timer(int value);
void Mouse(int button, int state, int x, int y);



void Mouse(int button, int state, int x, int y) {
  // calculate the Y coordinate of the tip of the arm
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
    
        clicked=true;
    }

    
    // color the background green
    
 

  // ask OpenGL to recall the display function to reflect the changes on the window
  glutPostRedisplay();

}
    
void Timer(int value) {
  // set the ball's Y coordinate to a random number between 10 and 780 (since the window's height is 800)
    float cX= 310+ballX;
        float cY= 400+ballY;
        float p1X= 310+player1X;
        float p1Y= 160+player1Y;
        float p2X= 310+player2X;
        float p2Y= 630+player2Y;
        

        DistanceBetween1=sqrt((p1X-cX)*(p1X-cX)+(p1Y-cY)*(p1Y-cY));
        
        DistanceBetween2=sqrt((p2X-cX)*(p2X-cX)+(p2Y-cY)*(p2Y-cY));
   
    if(DistanceBetween1<=45){
        
        move1=true;
        move2=false;
        speed=26;

    }
    
    if(DistanceBetween2<=45){
       
         move2 = true;
        move1=false;
        speed=26;

        
        


    }
   
    if (move1==true) {
        ballY+=speed;
        speed-=0.29;
      
        
    }
    if (move2==true ) {
        ballY-=speed;
        speed-=0.29;
        
    }
    
    
    if (ballY>=350 ) {
        score1+=1;
        player1X=0;
        player1Y=0;
        player2X=0;
        player2Y=0;
        ballX=0;
        ballY=0;
        move1=false;
        move2=false;
        
    }
    
    if (ballY<=-350 ) {
        score2+=1;
        player1X=0;
        player1Y=0;
        player2X=0;
        player2Y=0;
        ballX=0;
        ballY=0;
        move1=false;
        move2=false;
    }
    
    if(clicked==true && time1<350){
        green=1;
        speed=78;
        speed-=0.87;
        
        
    }
    if ( time1>350 && speed!=0) {
        green=0;
        time1=0;
        
        clicked=false;
    }
    
    if ( time1>350 && speed==0) {
        green=0;
        time1=0;
        speed=0;
        clicked=false;
    }
 
    time1++;
  // ask OpenGL to recall the dis
    
    

  // ask OpenGL to recall the display function to reflect the changes on the window
  glutPostRedisplay();

  // recall the Timer function after 20 seconds (20,000 milliseconds)
    glutTimerFunc(1, Timer, 0);
}



void print(int x, int y, char* string)
{
    int len, i;

    //set the position of the text in the window using the x and y coordinates
    glRasterPos2f(x, y);

    //get the length of the string to display
    len = (int)strlen(string);

    //loop to display character by character
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
    }
}







void drawCircle(int x, int y, float r) {
  glPushMatrix();
  glTranslatef(x, y, 0);
  GLUquadric *quadObj = gluNewQuadric();
  gluDisk(quadObj, 0, r, 50, 50);
  glPopMatrix();
}


void drawPlayer(int x, int y) {
    glPushMatrix();
    glTranslatef(x, y, 0);
    GLUquadric* quadObj = gluNewQuadric();
    gluDisk(quadObj, 0, 30, 50, 50); //r=30
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-10,-10, 0);
    glVertex3f(10,-10, 0);
    glVertex3f(10,10, 0);
    glVertex3f(-10,10, 0);
    glEnd();
    
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-8,-8, 0);
    glVertex3f(8,-8, 0);
    glVertex3f(8,8, 0);
    glVertex3f(-8,8, 0);
    glEnd();
   
    
 
    
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-8,-8, 0);
    glVertex3f(8,8, 0);
    glEnd();
    
    glPopMatrix();
    
}

void Key(unsigned char key, int x, int y) {

    if (key == 'a'){
        LeftPlayer1=true;
    }
    else if (key == 'd'){
        RightPlayer1=true;
    }
    else if (key == 'w' ){
        UpPlayer1=true;
    }
    else if (key == 's'){
        DownPlayer1=true;
    }
    
    
    else if (key == 'j' ){
      LeftPlayer2=true;
    }
    else if (key == 'l' ){
    RightPlayer2=true;
    }
    else if (key == 'i' ){
        UpPlayer2=true;
    }
    else  if (key == 'k' ){
        DownPlayer2=true;
    }
    // if the key 'z' is pressed, decrement bar1Y until it reaches the bottom limit of its support
    glutPostRedisplay();
  }

void KeyUp(unsigned char key, int x, int y) {
    if (key == 'a'){
        LeftPlayer1=false;
    }
  else  if (key == 'd'   ){
        RightPlayer1=false;
    }
  else if (key == 'w'    ){
        UpPlayer1=false;
    }
  else if (key == 's' ){
        DownPlayer1=false;
    }
    
    
  else if (key == 'j' ){
      LeftPlayer2=false;
    }
  else if (key == 'l' ){
    RightPlayer2=false;
    }
  else if (key == 'i' ){
        UpPlayer2=false;
    }
  else if (key == 'k' ){
        DownPlayer2=false;
    }
    
    
    glutPostRedisplay();
}
    




void Display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUAD_STRIP   );
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(50.0f, 50.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(550.0f, 50.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f( 50.0f, 750.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(550.0f, 750.0f, 0.0f);
    glEnd();
    
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(50.0f, 400.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(550.0f, 400.0f, 0.0f);
    glEnd();
    
    
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(225.0f, 750.0f, 0.0f);
    
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(225.0f, 670.0f, 0.0f);
    
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(375.0f, 670.0f, 0.0f);
    
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(375.0f, 750.0f, 0.0f);
    glEnd();
    
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(225.0f, 50.0f, 0.0f);
    
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(225.0f, 120.0f, 0.0f);
    
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(375.0f, 120.0f, 0.0f);
    
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(375.0f, 50.0f, 0.0f);
    glEnd();
    
    
    glPushMatrix();
   
    glTranslatef(ballX,ballY,0);
    glColor3f(red,green,blue);
    drawCircle(310, 400, 15);
   

    glPopMatrix();
    
    
    glPushMatrix();
  glTranslatef( player1X, player1Y,0);
    glColor3f(1,0,0);
    
    drawPlayer(310, 160);
   
 
    glPopMatrix();
    
    
    glPushMatrix();
    glColor3f(0,0,1);
   glTranslatef( player2X, player2Y,0);
    drawPlayer(310, 630);
    glPopMatrix();
    
    
    
    glColor3f(1, 0, 0);
    char* p0s[20];
    sprintf((char*)p0s, "Score: %d", score1);
    print(260, 20, (char*)p0s);
    
    glColor3f(0, 0, 1);
    char* p1s[20];
    sprintf((char*)p1s, "Score: %d", score2);
    print(260, 760, (char*)p1s);
    
    
    
    
    
    if(RightPlayer1==true &&  player1X < 210 )
        player1X+=10;
     if(LeftPlayer1==true&& player1X > -230)
        player1X-=10;
     if(UpPlayer1==true && player1Y < 210)
        player1Y+=10;
     if(DownPlayer1==true &&  player1Y > -80)
        player1Y-=10;
        
    
    if(RightPlayer2==true &&  player2X < 210 )
        player2X+=10;
     if(LeftPlayer2==true && player2X > -230)
        player2X-=10;
     if(UpPlayer2==true && player2Y < 100  )
        player2Y+=10;
     if(DownPlayer2==true && player2Y > -200)
        player2Y-=10;
    


    if (score1==5) {
        
        glBegin(GL_QUAD_STRIP   );
            glColor3f(0.0f, 0.0f,0.0f);
            glVertex3f(50.0f, 50.0f, 0.0f);
        glColor3f(0.0f, 0.0f,0.0f);
            glVertex3f(550.0f, 50.0f, 0.0f);
        glColor3f(0.0f, 0.0f,0.0f);
            glVertex3f( 50.0f, 750.0f, 0.0f);
        glColor3f(0.0f, 0.0f,0.0f);
            glVertex3f(550.0f, 750.0f, 0.0f);
        glEnd();
        
        glColor3f(1, 0, 0);
        char* p2s[20];
        sprintf((char*)p2s, "RED WINS");
        print(260, 360, (char*)p2s);


    }


    if (score2==5) {
        glBegin(GL_QUAD_STRIP   );
            glColor3f(0.0f, 0.0f,0.0f);
            glVertex3f(50.0f, 50.0f, 0.0f);
        glColor3f(0.0f, 0.0f,0.0f);
            glVertex3f(550.0f, 50.0f, 0.0f);
        glColor3f(0.0f, 0.0f,0.0f);
            glVertex3f( 50.0f, 750.0f, 0.0f);
        glColor3f(0.0f, 0.0f,0.0f);
            glVertex3f(550.0f, 750.0f, 0.0f);
        glEnd();
        glColor3f(0, 0, 1);
        char* p2s[20];
        sprintf((char*)p2s, "BLUE WINS");
        print(260, 420, (char*)p2s);

    }
//  // ask OpenGL to recall the display function to reflect the changes on the window
  glutPostRedisplay();

    
    
    

    
    glFlush();

}


int main(int argc, char** argr) {
    glutInit(&argc, argr);

    glutInitWindowSize(600, 800);
    glutInitWindowPosition(150, 150);

    glutCreateWindow("Hockey Game");
    glutDisplayFunc(Display);
    
    glutKeyboardFunc(Key);
    glutKeyboardUpFunc(KeyUp);
    glutMouseFunc(Mouse);
    glutTimerFunc(0, Timer, 0);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    gluOrtho2D(0.0, 600, 0.0, 800);

    glutMainLoop();
    return 0;
}
