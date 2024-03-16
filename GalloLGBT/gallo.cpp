#include <gl/glut.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>

void drawLegs(){
    glColor3f(0.0, 1.0, 0.0); // Verde
    glBegin(GL_QUADS);
    glVertex2i(422, 163);
    glVertex2i(428, 163);
    glVertex2i(428, 110);
    glVertex2i(422, 110);
    glEnd();
    glColor3f(0.0f, 0.5f, 1.0f); // Azul
    int num_segments = 100;
    float center_x = 425; // Posición en x 
    float center_y = 95;  // Posición en y
    
    float radius_x = 50;  // Radio en x
    float radius_y = 10;  // Radio en y
    glBegin(GL_POLYGON);
    for(int i = 0; i < num_segments; i++){
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x = radius_x * cosf(theta);
        float y = radius_y * sinf(theta);
        glVertex2f(x + center_x, y + center_y);
    }
    glEnd();
}

void drawTail(){
    glColor3f(0.0f, 1.0f, 0.0f); // Verde
    glBegin(GL_TRIANGLES);
    glVertex2i(398, 250);
    glVertex2i(373, 200);
    glVertex2i(338, 250);
    glEnd();
    glColor3f(0.5f, 0.0f, 1.0f); // Morado
    glBegin(GL_QUADS);
    glVertex2i(398, 252);
    glVertex2i(338, 252);
    glVertex2i(308, 302);
    glVertex2i(368, 302);
    glEnd();
    glColor3f(1.0f, 0.0f, 1.0f); // Morado
    glBegin(GL_TRIANGLES);
    glVertex2i(306, 302);
    glVertex2i(336, 252);
    glVertex2i(302, 185);
    glEnd();
}

void drawBody(){
    glColor3f(0.0f, 1.0f, 0.0f); // Verde
    glBegin(GL_POLYGON);
    glVertex2i(400, 250);
    glVertex2i(450, 250);
    glVertex2i(475, 200);
    glVertex2i(425, 165);
    glVertex2i(375, 200);
    glEnd();    
}

void drawHead(){
    glColor3f(0.0f, 1.0f, 0.0f); // Verde
    glBegin(GL_TRIANGLES);
    glVertex2i(450, 252);
    glVertex2i(400, 252);
    glVertex2i(450, 340);
    glEnd();
    glColor3f(0.5f, 0.0f, 1.0f); // Morado
    glBegin(GL_QUADS);
    glVertex2i(452, 300);
    glVertex2i(492, 300);
    glVertex2i(492, 340);
    glVertex2i(452, 340);
    glEnd();
    glColor3f(1.0f, 0.0f, 1.0f); // Morado
    glBegin(GL_TRIANGLES);
    glVertex2i(422, 342);
    glVertex2i(492, 342);
    glVertex2i(450, 390);
    glEnd();
    glColor3f(1.0f, 0.0f, 1.0f); // Morado
    glBegin(GL_TRIANGLES);
    glVertex2i(494, 300);
    glVertex2i(494, 335);
    glVertex2i(520, 300);
    glEnd();
    glColor3f(1.0f, 0.0f, 1.0f); // Morado
    glBegin(GL_TRIANGLES);
    glVertex2i(472, 299);
    glVertex2i(454, 265);
    glVertex2i(488, 265);
    glEnd();
}

void myInit() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 800.0, 0.0, 600.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    drawBody();
    drawLegs();
    drawTail();    
    drawHead();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("gallo");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

