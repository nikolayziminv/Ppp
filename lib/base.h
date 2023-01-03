#include <stdlib.h>
#include <string>
#include <math.h>
#include <time.h>

#define HALF_PI 1.57079632679489661923
#define PI 3.14159265358979323846
#define QUARTER_PI 0.7853982
#define TWO_PI 6.28318530717958647693
#define TAU TWO_PI
#define boolean bool
#define UP GLUT_UP
#define DOWN GLUT_DOWN
#define LEFT 37
#define RIGHT 39
#define CENTER 3
#define ALT 18
#define CONTROL 17
#define SHIFT 16
#define BACKSPACE 8
#define F1 112
#define F2 113
#define F3 114
#define F4 115
#define F5 116
#define F6 117
#define F7 118
#define F8 119
#define F9 120
#define F10 121
#define F11 122
#define F12 123
#define ENTER 10
#define SPACE 32

namespace Processing{

int mouseButton;
int mouseState;
int width, height;
int mouseX=0, mouseY=0,pmouseX=0,pmouseY=0;
bool mouseIsPressed,keyIsPressed;
unsigned char key;
std::string title = "sketch";
long frameCount=0;


void setup();
void draw();
void mousePressed();
void mouseReleased();
void keyPressed();



void size(int w, int h) {
  width=w;
  height=h;
}

void rect(float x, float y, float w, float h) {
  glRecti(x, y, w+x, y+h);
}

void ellipse(float x, float y, float w, float h) {
}

void triangle(float x, float y, float x1, float y1, float x2, float y2) {
  glBegin(GL_TRIANGLES);
  glVertex2d(x, y);
  glVertex2f(x1, y1);
  glVertex2d(x2, y2);
  glEnd();
}

void strokeWeight(float w) {
  glLineWidth(w);
}

void line(float x, float y, float x1, float y1) {
  glBegin(GL_LINES);
  glVertex2d(x, y);
  glVertex2d(x1, y1);
  glEnd();
}

void quad(float x, float y, float x1, float y1, float x2, float y2, float x3, float y3) {
  glBegin(GL_QUADS);
  glVertex2d(x, y);
  glVertex2d(x1, y1);
  glVertex2d(x2, y2);
  glVertex2d(x3, y3);
  glEnd();
}

void background(int r, int g, int b) {
  glColor3ub(r, g, b);
  rect(0,0,width,height);
}

void fill(int r, int g, int b) {
  glColor3ub(r, g, b);
}


float dist(float x2, float y2, float x1, float y1) {
  float x=x1-x2;
  float y=y1-y2;
  float d=sqrt(x*x+y*y);
  return d;
}




void randomSeed(int seed){
	srand(seed);
}

int random(int start = 0, int end = 1024){
	return rand()%(start-end)+start;
}

void display()
{
  draw();
  //glutSwapBuffers();
  frameCount++;
  pmouseX=mouseX;
  pmouseY=mouseY;
  glFlush();
  glEnd();
}

void mousePress(int button, int state, int x, int y) {
  mouseButton=button;
  mouseIsPressed=state==DOWN;
  if(mouseIsPressed){
    mousePressed();
  }else{
    mouseReleased();
  }
  glutPostRedisplay();
}



void mouseCoordinate(int x, int y)
{
  mouseX=x;
  mouseY=y;
  glutPostRedisplay();
}  


void keyPress(unsigned char k, int x, int y)
{
	key = k;
	keyPressed();
}

void setTitle(std::string title){
	glutSetWindowTitle(title.c_str());
}


}





