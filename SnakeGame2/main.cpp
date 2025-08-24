//
//  main.cpp
//  SnakeGame2
//
//  Created by Mohamed Nayef on 12/05/2024.
//

// ************************* Begin Include library section *************************
#define GL_SILENCE_DEPRECATION
#include <iostream>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <deque>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <ctime>
//#include "../files/stb_image.h"
// ************************* End Include library section *************************
#define GL_SILENCE_DEPRECATION
using namespace std;
// ************************* Begin Global variable section *************************
int WidthOfWindow = 630; // 630 / 18 = 35
int HightOfWindow = 630; // 630 / 18 = 35
int bord[35][35] = {
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};
const int EMPTY = 0;
const int BODY = 1;
const int APPLE = 2;
int APPLE_X = 14;
int APPLE_Y = 20;
enum directions{UP,DOWN,LEFT,RIGHT};
directions snakeDirection = DOWN;
struct location {
  int r;
  int c;
};
deque<location> snakeBody;
// ************************* End Global variable section *************************

// ************************* Begin Functions decleration section *************************
void drawBoard(void);
void initSnake();
void drawSnakeBody(int r, int c);
void moveSnake();
void eraseSnakeBody(int r, int c);
void drawApple(int r, int c);
void handleSpecialKey(int key, int x, int y);
// ************************* End Functions decleration section *************************

// ************************* Main function *************************
int main(int argc, char * argv[]) {
  srand((unsigned int)(time(nullptr)));
  for(int i=0; i<10; i++) {
    cout << rand()%100 << endl;
  }
  deque<location> x;
  glutInit(&argc, argv); // Initialize GLUT
  glutInitWindowPosition(0, 0);
  glutInitWindowSize(WidthOfWindow, HightOfWindow);
  glutCreateWindow("OpenGLTest");
  gluOrtho2D(0, WidthOfWindow, 0, HightOfWindow);
  drawApple(5, 20);
  initSnake();
  glutDisplayFunc(moveSnake);
  glutSpecialFunc(handleSpecialKey);
  
  glutMainLoop();
  
  
  return 0;
}

// this function draw the bord[][] 2d array
void drawBoard(void) {
  glClearColor(0.192, 0.192, 0.192, 1); // color of window
  glClear(GL_COLOR_BUFFER_BIT); // delete the temp data in butter
  
  for(int r=0; r<35; r++) {
    for(int c=0; c<35; c++) {
      switch (bord[r][c]) {
        case EMPTY:
          break;
        case BODY:
          drawSnakeBody(r,c);
          break;
        case APPLE:
          drawApple(r,c);
          break;
        default:
          break;
      }
    }
  }
} // Done

// this function set the initial values of snake
void initSnake() {
  location loc;
  loc.r = 2;
  loc.c = 10;
  
  for(int i=0; i<=4; i++) {
    snakeBody.push_back(loc);
    bord[loc.r][loc.c] = BODY;
    loc.r++;
  }
  drawBoard();
} // Done

// this function draw one pixel of bord that (r,c)
void drawSnakeBody(int r, int c) {
  int x = r * 18;
  int y = c * 18;
  
  glColor3f(0, 0.8, 0);
  glPointSize(20);
  glEnable(GL_POINT_SMOOTH); // make point like circle not square
  
  glBegin(GL_QUADS);
    glVertex2d(x+1, y+1);
    glVertex2d(x+17, y+1);
    glVertex2d(x+17, y+17);
    glVertex2d(x+1, y+17);
  glEnd();
  
  glFlush();
} // Done

// this function draw the new head and erase the tail of snake
// so, u see as moving
void moveSnake() {
  location head = snakeBody.back();
  switch (snakeDirection) {
    case UP:
      head.c++;
      if(head.c > 34)
//        snakeDirection = DOWN;
        head.c = 0;
      break;
    case DOWN:
      head.c--;
      if(head.c < 0)
//        snakeDirection = UP;
        head.c = 34;
      break;
    case LEFT:
      head.r--;
      if(head.r < 0)
//        snakeDirection = RIGHT;
        head.r = 33;
      break;
    case RIGHT:
      head.r++;
      if(head.r > 34)
//        snakeDirection = LEFT;
        head.r = 0;
      break;
    default:
      break;
  }
  snakeBody.push_back(head);
  if(bord[head.r][head.c] == BODY) {
    return;
  }
  bord[head.r][head.c] = BODY;
  drawSnakeBody(head.r, head.c);
  
  drawApple(APPLE_X, APPLE_Y);
  
  location tail = snakeBody.front();
//  snakeBody.pop_front();
  bord[tail.r][tail.c] = EMPTY;
  if(head.r == APPLE_X && head.c == APPLE_Y) {
    APPLE_X = rand()%31+2;
    APPLE_Y = rand()%31+2;
    if(APPLE_X%2==1)
      APPLE_X++;
    if(APPLE_Y%2==1)
      APPLE_Y++;
  }
  else {
    snakeBody.pop_front();
    eraseSnakeBody(tail.r, tail.c);
  }
  
  this_thread::sleep_for(chrono::milliseconds(100));

  glutPostRedisplay();
} // Done

// this function erase a 1 pixel of snake that (r,c)
void eraseSnakeBody(int r, int c) {
  int x = r * 18;
  int y = c * 18;
  
  glColor3f(0.192, 0.192, 0.192);
  glPointSize(20);
  
  glBegin(GL_QUADS);
    glVertex2d(x+1, y+1);
    glVertex2d(x+17, y+1);
    glVertex2d(x+17, y+17);
    glVertex2d(x+1, y+17);
  glEnd();
  
  glFlush();
} // Done

// this function draw one pixel of bord that (r,c)
void drawApple(int r, int c) {
  int x = r * 18;
  int y = c * 18;
  
  glColor3f(0.8,0.1, 0);
  glPointSize(10);
  glEnable(GL_POINT_SMOOTH); // make point like circle not square
  
  glBegin(GL_QUADS);
    glVertex2d(x+1, y+1);
    glVertex2d(x+17, y+1);
    glVertex2d(x+17, y+17);
    glVertex2d(x+1, y+17);
  glEnd();
} // Done

// this funciton handle the key arrow from keyboard
void handleSpecialKey(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            snakeDirection = UP;
            break;
        case GLUT_KEY_DOWN:
            snakeDirection = DOWN;
            break;
        case GLUT_KEY_LEFT:
            snakeDirection = LEFT;
            break;
        case GLUT_KEY_RIGHT:
            snakeDirection = RIGHT;
            break;
        default:
            break;
    }
} // Done

// ************************* End Program   *************************
