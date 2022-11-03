

#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>


static float shift = 0;
static float cloud1 = 10, ty = 0;
static float cloud2 = -40;
static float cloud3 = -80;
static float cloud4 = -100;



void circle(GLfloat rx, GLfloat ry, GLfloat x, GLfloat y)
{
    int i = 0;
    float angle;
    GLfloat PI = 2.0f * 3.1416;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (i = 0;i < 100;i++)
    {
        angle = 2 * PI * i / 100;
        glVertex2f(x + (cos(angle) * rx), y + (sin(angle) * ry));
    }
    glEnd();
}


static float boat = 0;
void boatMove()
{
    boat += 0.0005;
    if (boat > .7) {
        boat = 0;
    }
    glutPostRedisplay();
}


void cloudMove()
{
    cloud1 += 0.002;
    if (cloud1 > 100) {
        cloud1 = -20;
    }
    glutPostRedisplay();



    cloud2 += .002;
    if (cloud2 > 100) {
        cloud2 = -30;
    }
    glutPostRedisplay();

    cloud3 += .002;
    if (cloud2 > 100) {
        cloud2 = -60;
    }
    glutPostRedisplay();

    cloud4 += .004;
    if (cloud2 > 100) {
        cloud2 = -80;
    }
    glutPostRedisplay();
}



void movingCloud()
{

    glColor3f(0.5, 0.5, 0.5);
    cloudMove();
    glPushMatrix();
    glTranslatef(cloud1, -1, 0);
    circle(3, 5, 5, 88);
    circle(3, 5, 8, 91);
    circle(3, 5, 12, 92);
    circle(3, 5, 12, 87);
    circle(3, 5, 7, 85);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cloud2, -7, 0);
    circle(4, 5, 5, 88);
    circle(3, 5, 8, 91);
    circle(5, 5, 12, 92);
    circle(4, 5, 12, 87);
    circle(3, 6, 7, 85);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(cloud3, -0, 0);
    circle(4, 5, 5, 88);
    circle(3, 5, 8, 91);
    circle(7, 5, 12, 92);
    circle(4, 5, 12, 87);
    circle(2, 6, 7, 85);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cloud4, -4, 0);
    circle(4, 7, 5, 88);
    circle(2, 5, 8, 91);
    circle(5, 5, 12, 92);
    circle(3, 5, 12, 87);
    circle(3, 6, 7, 85);
    glPopMatrix();
}


void rainMove()
{
    shift += 5;
    shift = (shift > 70) ? 0 : shift;
    glutPostRedisplay();
}

void home() {

    //middle
    glColor4ub(255, 222, 222, 255);
    glBegin(GL_QUADS);
    glVertex2f(25, 30);
    glVertex2f(45, 30);
    glVertex2f(45, 50);
    glVertex2f(25, 50);
    glEnd();

    //leftsidehome
    glColor4ub(145, 222, 222, 255);
    glBegin(GL_QUADS);
    glVertex2f(17, 50);
    glVertex2f(25, 50);
    glVertex2f(25, 30);
    glVertex2f(17, 32);
    glEnd();


    //roofside
    glColor4ub(97, 133, 255, 255);
    glBegin(GL_TRIANGLES);
    glVertex2f(25, 50);
    glVertex2f(20, 62);
    glVertex2f(17, 50);
    glEnd();


    //up
    glColor4ub(255, 115, 115, 255);
    glBegin(GL_QUADS);
    glVertex2f(25, 47);
    glVertex2f(48, 47);
    glVertex2f(43, 62);
    glVertex2f(20, 62);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(29, 47);
    glVertex2f(24, 62);

    glVertex2f(34, 47);
    glVertex2f(29, 62);

    glVertex2f(39, 47);
    glVertex2f(34, 62);

    glVertex2f(44, 47);
    glVertex2f(39, 62);

    glEnd();

    //under
    glColor4ub(255, 115, 115, 255);
    glBegin(GL_QUADS);
    glVertex2f(25, 30);
    glVertex2f(45, 30);
    glVertex2f(45, 32);
    glVertex2f(25, 32);
    glEnd();

    glColor4ub(97, 133, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(25, 30);
    glVertex2f(25, 32);
    glVertex2f(17, 33);
    glVertex2f(17, 31);
    glEnd();


    //window right
    glColor3f(0.1, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(39, 40);
    glVertex2f(39, 45);
    glVertex2f(43, 45);
    glVertex2f(43, 40);
    glEnd();

    // window front left
    glColor3f(0.1, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(27, 40);
    glVertex2f(27, 45);
    glVertex2f(31, 45);
    glVertex2f(31, 40);
    glEnd();
    // window leftside home
    glColor3f(0.1, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(19, 40);
    glVertex2f(19, 45);
    glVertex2f(23, 45);
    glVertex2f(23, 40);
    glEnd();

    //doorbox
    glColor3f(0.1, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(32.5, 32);
    glVertex2f(32.5, 37);
    glVertex2f(37.5, 37);
    glVertex2f(37.5, 32);
    glEnd();

    //doorright
    glColor3ub(140, 101, 60);
    glBegin(GL_QUADS);
    glVertex2f(32.5, 32);
    glVertex2f(32.5, 37);
    glVertex2f(34, 35);
    glVertex2f(34, 32);
    glEnd();

    //doorleft
    glColor3ub(140, 101, 60);
    glBegin(GL_QUADS);
    glVertex2f(36, 32);
    glVertex2f(36, 35);
    glVertex2f(37.5, 37);
    glVertex2f(37.5, 32);
    glEnd();

    //home2
    glColor4ub(255, 222, 222, 255);
    glBegin(GL_QUADS);
    glVertex2f(55, 47);
    glVertex2f(65, 47);
    glVertex2f(65, 57);
    glVertex2f(55, 57);
    glEnd();

    glColor4ub(255, 115, 115, 255);
    glBegin(GL_QUADS);
    glVertex2f(53, 53);
    glVertex2f(67, 53);
    glVertex2f(65, 57);
    glVertex2f(55, 57);
    glEnd();

    //window
    glColor3f(0.1, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(62.5, 50);
    glVertex2f(62.5, 52);
    glVertex2f(64, 52);
    glVertex2f(64, 50);
    glEnd();

    glColor3f(0.1, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(56, 50);
    glVertex2f(56, 52);
    glVertex2f(57.5, 52);
    glVertex2f(57.5, 50);
    glEnd();

    glColor4ub(255, 115, 115, 255);
    glBegin(GL_QUADS);
    glVertex2f(55, 47);
    glVertex2f(65, 47);
    glVertex2f(65, 48);
    glVertex2f(55, 48);
    glEnd();

    //door2
    glColor3f(0.1, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(59.5, 48);
    glVertex2f(59.5, 50);
    glVertex2f(61, 50);
    glVertex2f(61, 48);
    glEnd();

    glColor3f(0.1, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(55, 53);
    glVertex2f(57, 57);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(57, 53);
    glVertex2f(59, 57);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(60, 53);
    glVertex2f(60, 57);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(63, 53);
    glVertex2f(61, 57);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(65, 53);
    glVertex2f(63, 57);
    glEnd();

    //boat bamboo
    glColor3ub(93, 41, 6);
    glBegin(GL_POLYGON);
    glVertex2f(6, 14);
    glVertex2f(7.5, 14);
    glVertex2f(7.5, 25);
    glVertex2f(6, 25);
    glEnd();

    glColor3f(0.1f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(6, 25);
    glVertex2f(7.5, 25);
    glEnd();

    glColor3f(0.1f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(6, 21);
    glVertex2f(7.5, 21);
    glEnd();

    glColor3f(0.1f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(6, 21.5);
    glVertex2f(7.5, 21.5);
    glEnd();

    glColor3f(0.1f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(6, 22);
    glVertex2f(7.5, 22);
    glEnd();

    glColor3f(0.1f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(7.5, 21);
    glVertex2f(15, 13.5);
    glEnd();


    //bigtree

    glColor3ub(135, 62, 35);
    glBegin(GL_POLYGON);
    glVertex2f(82, 25);
    glVertex2f(91, 25);
    glVertex2f(91, 52);
    glVertex2f(82, 52);
    glEnd();

    glColor3ub(135, 62, 35);
    glBegin(GL_POLYGON);
    glVertex2f(82, 25);
    glVertex2f(91, 25);
    glVertex2f(94, 20);
    glEnd();
    glColor3ub(135, 62, 35);
    glBegin(GL_POLYGON);
    glVertex2f(82, 25);
    glVertex2f(91, 25);
    glVertex2f(78, 20);
    glEnd();
    glColor3ub(135, 62, 35);
    glBegin(GL_POLYGON);
    glVertex2f(82, 25);
    glVertex2f(91, 25);
    glVertex2f(86, 20);
    glEnd();

    glColor3ub(135, 62, 35);
    glBegin(GL_POLYGON);
    glVertex2f(91, 52);
    glVertex2f(87, 52);
    glVertex2f(96, 58);
    glEnd();

    glColor3ub(135, 62, 35);
    glBegin(GL_POLYGON);
    glVertex2f(82, 52);
    glVertex2f(86, 52);
    glVertex2f(78, 58);
    glEnd();

    glColor3ub(135, 62, 35);
    glBegin(GL_POLYGON);
    glVertex2f(91, 52);
    glVertex2f(87, 52);
    glVertex2f(85, 58);
    glEnd();

    glColor4ub(34, 153, 84, 255);
    circle(5, 6, 80, 60);
    circle(5, 6, 85, 60);
    circle(5, 6, 90, 60);
    circle(5, 6, 95, 60);
    circle(5, 6, 83, 64);
    circle(5, 6, 87, 68);
    circle(5, 6, 93, 63);


    //grass
    glColor4ub(5, 69, 0, 255);
    glBegin(GL_LINES);
    glVertex2f(71, 22);
    glVertex2f(71.5, 23);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(71, 22);
    glVertex2f(70, 23);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(71, 22);
    glVertex2f(72, 23);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(71, 22);
    glVertex2f(70.5, 23);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(71, 22);
    glVertex2f(71, 23);
    glEnd();


    //2
    glBegin(GL_LINES);
    glVertex2f(51, 32);
    glVertex2f(51, 33);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(51, 32);
    glVertex2f(51.5, 33);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(51, 32);
    glVertex2f(52, 33);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(51, 32);
    glVertex2f(50.5, 33);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(51, 32);
    glVertex2f(50, 33);
    glEnd();


    //3
    glBegin(GL_LINES);
    glVertex2f(65, 32);
    glVertex2f(65, 33);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(65, 32);
    glVertex2f(65.5, 33);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(65, 32);
    glVertex2f(66, 33);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(65, 32);
    glVertex2f(64.5, 33);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(65, 32);
    glVertex2f(64, 33);
    glEnd();



    //4
    glBegin(GL_LINES);
    glVertex2f(45, 21);
    glVertex2f(45, 22);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(45, 21);
    glVertex2f(45.6, 22);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(45, 21);
    glVertex2f(46, 22);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(45, 21);
    glVertex2f(44.5, 22);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(45, 21);
    glVertex2f(44, 22);
    glEnd();



    //5
    glBegin(GL_LINES);
    glVertex2f(48, 21);
    glVertex2f(48, 22);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(48, 21);
    glVertex2f(48.5, 22);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(48, 21);
    glVertex2f(49, 22);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(48, 21);
    glVertex2f(47.5, 22);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(48, 21);
    glVertex2f(47, 22);
    glEnd();



    //6
    glBegin(GL_LINES);
    glVertex2f(58, 24);
    glVertex2f(57.5, 25);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(58, 24);
    glVertex2f(57, 25);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(58, 24);
    glVertex2f(58, 25);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(58, 24);
    glVertex2f(58.5, 25);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(58, 24);
    glVertex2f(59, 25);
    glEnd();



    //7
    glBegin(GL_LINES);
    glVertex2f(75, 34);
    glVertex2f(75, 35);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(75, 34);
    glVertex2f(75.5, 35);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(75, 34);
    glVertex2f(76, 35);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(75, 34);
    glVertex2f(74.5, 35);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(75, 34);
    glVertex2f(74, 35);
    glEnd();


    //8
    glBegin(GL_LINES);
    glVertex2f(95, 34);
    glVertex2f(95.5, 35);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(95, 34);
    glVertex2f(96, 35);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(95, 34);
    glVertex2f(95, 35);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(95, 34);
    glVertex2f(94, 35);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(95, 34);
    glVertex2f(94.7, 35);
    glEnd();


    //khor
    glColor4ub(243, 200, 96, 255);
    glBegin(GL_QUADS);
    glVertex2f(3, 30);
    glVertex2f(11, 30);
    glVertex2f(9, 45);
    glVertex2f(5, 45);
    glEnd();

    glColor4ub(243, 200, 96, 255);
    circle(2, 3, 7, 45);
    glColor4ub(243, 200, 96, 255);
    circle(3, 8, 7, 38);
    glColor4ub(243, 200, 96, 255);
    circle(3.5, 6, 7, 36);

    glColor3ub(93, 41, 6);
    glBegin(GL_POLYGON);
    glVertex2f(6.5, 48);
    glVertex2f(7.5, 48);
    glVertex2f(7.5, 51);
    glVertex2f(6.5, 51);
    glEnd();

    glColor3ub(93, 41, 6);
    glBegin(GL_POLYGON);
    glVertex2f(3.5, 28.5);
    glVertex2f(4.5, 28.5);
    glVertex2f(4.5, 30);
    glVertex2f(3.5, 30);
    glEnd();

    glColor3ub(93, 41, 6);
    glBegin(GL_POLYGON);
    glVertex2f(9.5, 28.5);
    glVertex2f(10.5, 28.5);
    glVertex2f(10.5, 30);
    glVertex2f(9.5, 30);
    glEnd();

    //flower
    glColor4ub(5, 69, 0, 255);
    glBegin(GL_LINES);
    glVertex2f(95, 15);
    glVertex2f(95.5, 5);
    glEnd();

    glColor3ub(204, 204, 0);
    circle(0.7, 1.2, 95, 15);
    glColor3ub(255, 0, 0);
    circle(0.3, 0.6, 95, 15);

    glColor4ub(5, 69, 0, 255);
    glBegin(GL_LINES);
    glVertex2f(95.5, 5);
    glVertex2f(90.5, 15);
    glEnd();

    glColor3ub(204, 204, 0);
    circle(0.7, 1.2, 90.5, 15);
    glColor3ub(255, 0, 0);
    circle(0.3, 0.6, 90.5, 15);

    glColor4ub(5, 69, 0, 255);
    glBegin(GL_LINES);
    glVertex2f(95.5, 5);
    glVertex2f(92.5, 15);
    glEnd();

    glColor4ub(5, 69, 0, 255);
    glBegin(GL_LINES);
    glVertex2f(95.5, 5);
    glVertex2f(97.5, 15);
    glEnd();


    glColor4ub(5, 69, 0, 255);
    glBegin(GL_LINES);

    glVertex2f(63.5, 15);
    glVertex2f(60.5, 20);

    glVertex2f(63.5, 15);
    glVertex2f(66.5, 20);

    glVertex2f(63.5, 15);
    glVertex2f(62.5, 20);

    glVertex2f(55.5, 15);
    glVertex2f(58.5, 20);

    glVertex2f(55.5, 15);
    glVertex2f(56.5, 20);

    glVertex2f(55.5, 15);
    glVertex2f(53.5, 20);

    glVertex2f(68.5, 15);
    glVertex2f(70.5, 20);

    glVertex2f(68.5, 15);
    glVertex2f(72.5, 20);

    glVertex2f(68.5, 15);
    glVertex2f(67.5, 20);

    glVertex2f(61.5, 15);
    glVertex2f(64.5, 20);

    glVertex2f(61.5, 15);
    glVertex2f(59.5, 20);

    glVertex2f(61.5, 15);
    glVertex2f(61.5, 20);

    glVertex2f(78.5, 15);
    glVertex2f(74.5, 20);

    glVertex2f(78.5, 15);
    glVertex2f(77, 20);

    glVertex2f(78.5, 15);
    glVertex2f(79.5, 20);

    glEnd();

    glColor3ub(204, 204, 0);
    circle(0.7, 1.2, 77, 20);
    glColor3ub(255, 0, 0);
    circle(0.3, 0.6, 77, 20);

    glColor3ub(204, 204, 0);
    circle(0.7, 1.2, 61.5, 20);
    glColor3ub(255, 0, 0);
    circle(0.3, 0.6, 61.5, 20);

    glColor3ub(204, 204, 0);
    circle(0.7, 1.2, 67.5, 20);
    glColor3ub(255, 0, 0);
    circle(0.3, 0.6, 67.5, 20);

    glColor3ub(204, 204, 0);
    circle(0.7, 1.2, 56.5, 20);
    glColor3ub(255, 0, 0);
    circle(0.3, 0.6, 56.5, 20);


    //boat

    glPushMatrix();
    boatMove();

    glColor3f(0.1f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(2, 15 - +boat);
    glVertex2f(9, 9 - +boat);
    glVertex2f(30, 9 - +boat);
    glVertex2f(37, 15 - +boat);
    glVertex2f(30, 16 - +boat);
    glVertex2f(10, 16 - +boat);
    glEnd();

    glColor3ub(130, 73, 11);
    glBegin(GL_POLYGON);
    glVertex2f(4, 14 - +boat);
    glVertex2f(9, 12 - +boat);
    glVertex2f(30, 12 - +boat);
    glVertex2f(35, 14 - +boat);
    glVertex2f(30, 15 - +boat);
    glVertex2f(10, 15 - +boat);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(10, 12 - +boat);
    glVertex2f(11, 12 - +boat);
    glVertex2f(11, 15 - +boat);
    glVertex2f(10, 15 - +boat);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(16, 12 - +boat);
    glVertex2f(17, 12 - +boat);
    glVertex2f(17, 15 - +boat);
    glVertex2f(16, 15 - +boat);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(22, 12 - +boat);
    glVertex2f(23, 12 - +boat);
    glVertex2f(23, 15 - +boat);
    glVertex2f(22, 15 - +boat);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(28, 12 - +boat);
    glVertex2f(29, 12 - +boat);
    glVertex2f(29, 15 - +boat);
    glVertex2f(28, 15 - +boat);
    glEnd();

    glPopMatrix();

}





void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);


    //mud
    glColor3f(0.6, 0.5, 0.2);
    glBegin(GL_QUADS);
    glVertex2f(0, 20);
    glVertex2f(100, 5);
    glVertex2f(100, 65);
    glVertex2f(0, 65);
    glEnd();


    //water
    glColor3f(0.3, 0.3, 1);

    circle(30, 5, 67, 9.5);
    circle(7, 5, 78, 6.5);
    circle(30, 5, 20, 15);



    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(0, 20);
    glVertex2f(100, 5);
    glVertex2f(100, 0);


    glEnd();

    //sky
    glColor3f(0.1, 0.4, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(0, 65);
    glVertex2f(100, 65);
    glVertex2f(100, 100);
    glVertex2f(0, 100);
    glEnd();


    //tree1
    glColor3ub(135, 62, 35);
    glBegin(GL_QUADS);
    glVertex2f(8, 65);
    glVertex2f(10, 65);
    glVertex2f(9, 72);
    glVertex2f(8, 72);
    glEnd();

    //tree2
    glColor3ub(135, 62, 35);
    glBegin(GL_QUADS);
    glVertex2f(38, 65);
    glVertex2f(39, 65);
    glVertex2f(39, 72);
    glVertex2f(38, 72);
    glEnd();

    //tree3

    glColor3ub(135, 62, 35);
    glBegin(GL_QUADS);
    glVertex2f(74, 65);
    glVertex2f(77, 65);
    glVertex2f(76, 72);
    glVertex2f(75, 72);
    glEnd();



    //forestcircle
    glColor4ub(5, 69, 0, 255);
    circle(5, 3, 5, 65);
    circle(5, 3, 14, 65);
    circle(5, 3, 20, 65);
    circle(5, 3, 28, 65);
    circle(5, 3, 32, 65);
    circle(5, 3, 40, 65);
    circle(5, 3, 48, 65);
    circle(5, 3, 50, 65);
    circle(5, 3, 55, 65);
    circle(5, 3, 61, 65);
    circle(5, 3, 70, 65);
    circle(5, 3, 80, 65);
    circle(5, 3, 85, 65);
    circle(5, 3, 91, 65);
    circle(5, 3, 96, 65);
    circle(5, 3, 14, 65);


    //forest
    glBegin(GL_QUADS);
    glVertex2f(0, 65);
    glVertex2f(100, 65);
    glVertex2f(100, 60);
    glVertex2f(0, 60);
    glEnd();

    glColor4ub(88, 122, 2, 255);
    glBegin(GL_QUADS);
    glVertex2f(0, 60);
    glVertex2f(100, 60);
    glVertex2f(100, 40);
    glVertex2f(0, 50);
    glEnd();


    //sun
    glColor4ub(251, 182, 0, 255);
    circle(4, 7, 75, 90);
    glColor3f(0.5, 0.5, 0.5);
    circle(2, 3, 74, 87);
    circle(6, 2.8, 77, 87);
    circle(2, 3, 80, 87);
    circle(2, 3, 77, 87);
    circle(2, 3, 79, 90);

    glPushMatrix();

    movingCloud();

    //treecircle
    glColor4ub(34, 153, 84, 255);
    circle(2, 2.5, 8.5, 73);


    glColor4ub(34, 153, 84, 255);
    glBegin(GL_TRIANGLES);
    glVertex2f(36, 70);
    glVertex2f(41, 70);
    glVertex2f(39, 75);
    glEnd();


    glColor4ub(34, 153, 84, 255);
    glBegin(GL_TRIANGLES);
    glVertex2f(36, 73);
    glVertex2f(41, 73);
    glVertex2f(39, 78);
    glEnd();

    glColor4ub(34, 153, 84, 255);
    circle(2, 2.5, 74.5, 72);
    circle(2, 2.5, 76.5, 72);
    circle(2, 2.5, 75.5, 73);



    home();

    //rain
    rainMove();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glVertex2f(50, 98 - shift);
    glVertex2f(50, 96 - shift);

    glBegin(GL_LINES);
    glVertex2f(55, 75 - shift);
    glVertex2f(55, 77 - shift);

    glBegin(GL_LINES);
    glVertex2f(60, 97 - shift);
    glVertex2f(60, 99 - shift);

    glBegin(GL_LINES);
    glVertex2f(65, 74 - shift);
    glVertex2f(65, 76 - shift);


    glBegin(GL_LINES);
    glVertex2f(70, 98 - shift);
    glVertex2f(70, 96 - shift);

    glBegin(GL_LINES);
    glVertex2f(75, 75 - shift);
    glVertex2f(75, 77 - shift);


    glBegin(GL_LINES);
    glVertex2f(80, 98 - shift);
    glVertex2f(80, 96 - shift);

    glBegin(GL_LINES);
    glVertex2f(85, 75 - shift);
    glVertex2f(85, 77 - shift);


    glBegin(GL_LINES);
    glVertex2f(90, 98 - shift);
    glVertex2f(90, 96 - shift);

    glBegin(GL_LINES);
    glVertex2f(95, 75 - shift);
    glVertex2f(95, 73 - shift);


    glBegin(GL_LINES);
    glVertex2f(100, 98 - shift);
    glVertex2f(100, 96 - shift);

    glBegin(GL_LINES);
    glVertex2f(40, 98 - shift);
    glVertex2f(40, 96 - shift);

    glBegin(GL_LINES);
    glVertex2f(45, 75 - shift);
    glVertex2f(45, 77 - shift);

    glBegin(GL_LINES);
    glVertex2f(30, 98 - shift);
    glVertex2f(30, 96 - shift);

    glBegin(GL_LINES);
    glVertex2f(35, 75 - shift);
    glVertex2f(35, 77 - shift);

    glBegin(GL_LINES);
    glVertex2f(20, 98 - shift);
    glVertex2f(20, 96 - shift);

    glBegin(GL_LINES);
    glVertex2f(25, 75 - shift);
    glVertex2f(25, 77 - shift);

    glBegin(GL_LINES);
    glVertex2f(10, 98 - shift);
    glVertex2f(10, 96 - shift);

    glBegin(GL_LINES);
    glVertex2f(5, 75 - shift);
    glVertex2f(5, 77 - shift);

    glBegin(GL_LINES);
    glVertex2f(15, 75 - shift);
    glVertex2f(15, 73 - shift);

    glBegin(GL_LINES);
    glVertex2f(1, 98 - shift);
    glVertex2f(1, 96 - shift);



    glEnd();
    glPopMatrix();

    glFlush();
}


void init(void)
{
    glClearColor(0.10, 0.10, 0.10, 0.0);
    glOrtho(0, 100.0, 0, 100.0, 0, 100.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("A Rainy Day");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}