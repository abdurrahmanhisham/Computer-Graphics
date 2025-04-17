#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

static float tp3 = 0;
static float pm = 300.0;
static float bm = 350.0;
static float tm = 300.0;
static float cm = -300.0;
static float cm2 = 300.0;
float spin = 0.0;

GLfloat tx = 5;
GLfloat ty = 5;

void circle(GLfloat rx, GLfloat ry, GLfloat x, GLfloat y) {
    int i;
    float rad = 0;
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    for (i = 0; i <= 360; i++) {
        rad = i * (3.1416 / 180);
        glVertex2f(x + rx * cos(rad), y + ry * sin(rad));
    }
    glEnd();
}

void sun() {
    glPushMatrix();
    glTranslated(270, 260, 0);
    glColor3f(1.0, 0.76, 0.3);
    circle(20, 30, 0, 0);
    glPopMatrix();
}

void make_cloud(int x, int y) {
    glColor3f(1.0, 1.0, 1.0);

    circle(10, 10, x, y);
    circle(10, 10, x + 10, y);
    circle(10, 10, x + 30, y);
    circle(10, 10, x + 5, y - 10);
    circle(10, 10, x + 20, y - 10);
    circle(10, 10, x + 5, y + 10);
    circle(10, 10, x + 20, y + 10);
}

void cloud_move_right(GLfloat t) {
    tp3 = tp3 + t;
    if (tp3 > 600)
        tp3 = -300;
    glutPostRedisplay();
}

void cloud() {
    glPushMatrix();
    glTranslatef(tp3, 0, 0);
    make_cloud(-300, 280);
    make_cloud(-500, 280);
    make_cloud(-200, 250);
    make_cloud(-400, 250);
    make_cloud(200, 250);
    make_cloud(-100, 250);
    make_cloud(-350, 230);
    glPopMatrix();
    cloud_move_right(.1);
}

void rectangle(int x, int y, int x1, int y1) {
    glBegin(GL_QUADS);
    glVertex2d(x, y);
    glVertex2d(x, y1);
    glVertex2d(x1, y1);
    glVertex2d(x1, y);
    glEnd();
}

void triangle(int x, int y, int x1, int x2, int y1) {
    glBegin(GL_POLYGON);
    glVertex2d(x, y);
    glVertex2d(x1, y);
    glVertex2d(x1, y);
    glVertex2d(x2, y1);
    glVertex2d(x2, y1);
    glVertex2d(x, y);
    glEnd();
}

void rectangle1(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    glBegin(GL_QUADS);
    glVertex2d(x1, y1);
    glVertex2d(x3, y3);
    glVertex2d(x4, y4);
    glVertex2d(x2, y2);
    glEnd();
}

void hill() {
    glColor3f(0.5, 0.87, 1.0);
    circle(70, 120, -250, 90);
    circle(70, 120, -100, 90);
    circle(70, 120, 50, 100);
    circle(70, 120, 200, 90);
}

void soil() {
    glColor3f(0.75, 0.75, 0.75);
    rectangle(-300, -10, 300, 130);
}

void ground() {
    glColor3f(0.3, 1.0, 0.53);
    rectangle(-300, -300, 300, -10);
}

void road() {

    glColor3f(0.3, 0.3, 0.3);
    rectangle(-300, -200, 300, -30);

    glColor3f(0.0, 0.0, 0.0);
    rectangle(-300, -30, 300, -33);

    glColor3f(0.0, 0.0, 0.0);
    rectangle(-300, -205, 300, -200);

    glColor3f(1.0, 1.0, 1.0);
    rectangle(-270, -120, -230, -110);
    rectangle(-270, -120, -200, -110);
    rectangle(-150, -120, 0, -110);
    rectangle(50, -120, 150, -110);
    rectangle(200, -120, 290, -110);
}

void flag() {

    glColor3f(0.0, 0.0, 0.0);
    rectangle(-170, -9, -167, 125);

    glColor3f(0.18, 0.72, 0.18);
    rectangle(-167, 75, -120, 125);

    glColor3f(0.9, 0.0, 0.0);
    circle(10, 20, -143, 100);
}

void shaheed_minar() {
    glColor3f(0.0, 0.0, 0.0);
    rectangle(-270, -9, -268, 60);
    rectangle(-262, -9, -260, 60);
    rectangle(-268, 58, -260, 60);
    rectangle(-255, -9, -253, 65);
    rectangle(-247, -9, -245, 65);
    rectangle(-255, 62, -245, 65);
    glColor3f(0.9, 0.0, 0.0);
    circle(12, 20, -231, 40);
    glColor3f(0.0, 0.0, 0.0);
    rectangle(-240, -9, -238, 75);
    rectangle(-232, -9, -230, 75);
    rectangle(-224, -9, -222, 75);
    rectangle(-240, 73, -222, 75);
    rectangle(-217, -9, -215, 65);
    rectangle(-209, -9, -207, 65);
    rectangle(-217, 62, -207, 65);
    rectangle(-202, -9, -200, 60);
    rectangle(-194, -9, -192, 60);
    rectangle(-202, 58, -192, 60);
}

void college() {
    glColor3f(1.0, 1.0, 0.3);
    rectangle(-100, -9, 60, 120);
    glColor3f(0.0, 0.0, 0.7);
    rectangle1(-100, 120, 60, 120, -90, 140, 70, 140);
    glColor3f(0.4, 1.0, 1.0);
    rectangle1(60, -9, 70, 0, 60, 120, 70, 140);
    glColor3f(0, 0, 0);
    rectangle(-35, -9, -5, 30);
    rectangle(-90, 100, -70, 80);
    rectangle(-60, 100, -40, 80);
    rectangle(-30, 100, -10, 80);
    rectangle(0, 100, 20, 80);
    rectangle(30, 100, 50, 80);
    rectangle(-90, 70, -70, 50);
    rectangle(-60, 70, -40, 50);
    rectangle(-30, 70, -10, 50);
    rectangle(0, 70, 20, 50);
    rectangle(30, 70, 50, 50);
}

void make_plane() {
    glColor3f(0.0, 0.0, 0.0);
    circle(20, 15, 0, 0);
    rectangle(0, -15, 70, 15);
    glColor3f(0.0, 0.0, 0.0);
    rectangle1(70, -15, 90, 35, 70, 15, 90, 40);
    glColor3f(1.0, 0.0, 0.0);
    rectangle1(30, 15, 50, 15, 60, 35, 55, 30);
    glColor3f(1.0, 1.0, 1.0);
    circle(5, 5, 10, 0);
    circle(5, 5, 30, 0);
    circle(5, 5, 50, 0);
    circle(5, 5, 65, 0);
    rectangle(-5, -5, 0, 10);
}

void planeMove() {
    pm = pm - 0.5;
    if (pm < -500)
        pm = 300;
    glutPostRedisplay();
}

void plane() {
    planeMove();
    glPushMatrix();
    glTranslatef(pm, 250, 0);
    make_plane();
    glPopMatrix();
}

void makeprivatecar() {
    glColor3f(1.0, 0.0, 0.0);
    circle(5, 15, 0, 0);
    rectangle(0, -15, 60, 15);
    glColor3f(0.2, 0.47, 1.0);
    triangle(5, 15, 20, 20, 45);
    triangle(40, 15, 60, 40, 45);
    glColor3f(0, 0, 0);
    rectangle(20, 15, 40, 45);
    glColor3f(1.0, 0.0, 0.0);
    circle(5, 10, 80, -5);
    glColor3f(1.0, 0.0, 0.0);
    rectangle1(60, -15, 80, -15, 60, 15, 80, 5);
    glColor3f(0, 0, 0);
    circle(7, 14, 10, -15);
    circle(7, 14, 60, -15);
    glColor3f(1.0, 1.0, 1.0);
    circle(6, 12, 10, -15);
    circle(6, 12, 60, -15);
}

void privatecarMove() {
    cm = cm + 0.5;
    if (cm > 330)
        cm = -350;
    glutPostRedisplay();
}

void privatecar() {
    privatecarMove();
    glPushMatrix();
    glTranslatef(cm, -50, 0);
    makeprivatecar();
    glPopMatrix();
}

void makeprivatecar2() {
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glRotatef(180, 0, 1, 0);

    glColor3f(0.0, 0.0, 1.0);
    circle(5, 15, 0, 0);
    rectangle(0, -15, 60, 15);

    glColor3f(1.0, 0.47, 0.2);
    triangle(5, 15, 20, 20, 45);
    triangle(40, 15, 60, 40, 45);

    glColor3f(0, 0, 0);
    rectangle(20, 15, 40, 45);

    glColor3f(0.0, 0.0, 1.0);
    circle(5, 10, 80, -5);

    glColor3f(0.0, 0.0, 1.0);
    rectangle1(60, -15, 80, -15, 60, 15, 80, 5);

    glColor3f(0, 0, 0);
    circle(7, 14, 10, -15);
    circle(7, 14, 60, -15);

    glColor3f(1.0, 1.0, 1.0);
    circle(6, 12, 10, -15);
    circle(6, 12, 60, -15);

    glPopMatrix();
}

void privatecarMove2() {
    cm2 = cm2 - 0.5;
    if (cm2 < -350)
        cm2 = 300;
    glutPostRedisplay();
}

void privatecar2() {
    privatecarMove2();
    glPushMatrix();
    glTranslatef(cm2, -150, 0);
    makeprivatecar2();
    glPopMatrix();
}

void railline() {
    glColor3f(0, 0, 0);
    rectangle(-300, -230, 300, -225);
    rectangle(-300, -260, 300, -265);
    int i = 0;
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_QUADS);
    for (i = -305; i <= 300; i = i + 30) {
        glVertex2d(i, -260);
        glVertex2d(i + 5, -260);
        glVertex2d(i + 20, -225);
        glVertex2d(i + 25, -225);
    }
    glEnd();
}

void station() {
    int baseY = -270;
    int height = 200;
    int leftX = -200;
    int rightX = 200;


    glColor3f(0.4f, 0.2f, 0.0f);
    rectangle(leftX, baseY, leftX + 20, baseY + height);
    rectangle(rightX - 20, baseY, rightX, baseY + height);


    glColor3f(0.0f, 1.0f, 1.0f);
    rectangle(leftX, baseY + height - 10, rightX, baseY + height + 10);


    int textX = (leftX + rightX) / 2;
    int textY = baseY + height - 5;


    glColor3f(0.0f, 0.0f, 0.0f);
    glRasterPos2f(textX - 40, textY);

    const char* text = "Uttara North Station";
    for (int i = 0; text[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }


    glColor3f(0.5f, 0.35f, 0.05f);
    rectangle(-140, baseY + 20, -60, baseY + 30);
    rectangle(-135, baseY + 30, -130, baseY + 60);

    rectangle(60, baseY + 20, 140, baseY + 30);
    rectangle(135, baseY + 30, 130, baseY + 60);


    glColor3f(0.7f, 0.7f, 0.7f);
    rectangle(-300, baseY, 300, baseY + 10);


    glColor3f(0.6f, 0.6f, 0.6f);
    rectangle(-120, baseY + 10, -117, baseY + 100);
    rectangle(120, baseY + 10, 123, baseY + 100);


    glColor3f(1.0f, 1.0f, 0.0f);
    circle(5, 5, -118.5, baseY + 100);
    circle(5, 5, 121.5, baseY + 100);
}

void makerail() {
    glColor3f(0, 0, 0);
    circle(8, 15, -70, -2);
    circle(8, 15, -53, -2);
    circle(8, 15, -20, -2);
    circle(8, 15, -3, -2);
    circle(8, 15, 30, -2);
    circle(8, 15, 47, -2);
    circle(8, 15, 75, -2);
    circle(8, 15, 93, -2);
    rectangle(-70, 0, -70, 2);
    glColor3f(1, 1, 1);
    rectangle(-70, 0, 100, 60);
    glColor3f(0.4, 0.4, 0.4);
    rectangle1(-100, 0, -70, 0, -100, 20, -70, 60);
    glColor3f(0.75, 0.75, 0.75);
    rectangle1(-70, 60, 100, 60, -75, 70, 105, 70);
    glColor3f(1.0, 1.0, 0.7);
    rectangle1(100, 0, 104, 10, 100, 60, 105, 70);
    glColor3f(0.6, 0.87, 1.0);
    rectangle1(-100, 20, -70, 60, -95, 35, -75, 70);
    glColor3f(0.4, 0.4, 0.4);
    circle(12, 15, -97, 15);
    glColor3f(0, 1, 1);
    rectangle(-60, 10, -50, 50);
    rectangle(-45, 30, -35, 50);
    rectangle(-30, 30, -20, 50);
    rectangle(-15, 30, -5, 50);
    rectangle(0, 10, 10, 50);
    rectangle(15, 30, 25, 50);
    rectangle(30, 30, 40, 50);
    rectangle(45, 30, 55, 50);
    rectangle(60, 10, 70, 50);
    rectangle(75, 30, 85, 50);
    rectangle(90, 30, 99, 50);
    rectangle(-70, 0, -70, 2);
}

void trainMove() {
    tm = tm - 1;
    if (tm < -350)
        tm = 350;
    glutPostRedisplay();
}

void train() {
    trainMove();
    glPushMatrix();
    glTranslatef(tm, -245, 0);
    makerail();
    glPopMatrix();
}

void spinDisplay_left() {
    spin = spin - 0.3;
    glutPostRedisplay();
}

void house() {
    glColor3f(0.1f, 0.1f, 1.0f);
    rectangle1(200, -9, 350, -9, 200, 80, 350, 80);
    rectangle1(200, 80, 250, 80, 200, 120, 250, 120);
    glColor3f(0.0f, 0.1f, 0.0f);
    triangle(195, 120, 255, 225, 150);
    glColor3f(0.4, 1.0, 1.0);
    rectangle1(215, 95, 235, 95, 215, 115, 235, 115);
    glColor3f(0.95, 0.95, 0.95);
    rectangle1(220, -9, 250, -9, 220, 40, 250, 40);
}

void make_tree() {
    glColor3f(0.0, 0.6, 0.0);
    circle(20, 30, 0, 0);
    circle(20, 30, 20, 0);
    circle(20, 30, 40, 0);
    circle(20, 30, 30, 30);
    circle(20, 30, 10, 30);
    circle(20, 30, 10, -30);
    circle(20, 30, 30, -30);
    circle(10, 20, 50, -70);
    circle(10, 20, 60, -60);
    circle(10, 20, 60, -80);
    glColor3f(0.75, 0.5, 0.25);
    rectangle1(10, -130, 30, -130, 10, -30, 30, -30);
    rectangle1(10, -30, 17, -30, 5, 0, 5, 0);
    rectangle1(17, -30, 22, -30, 19, 0, 19, 0);
    rectangle1(22, -30, 30, -30, 35, 0, 35, 0);
    rectangle1(30, -90, 30, -100, 55, -70, 55, -75);
}

void tree() {
    glPushMatrix();
    glTranslated(-320, 120, 0);
    make_tree();
    glPopMatrix();
    glPushMatrix();
    glTranslated(270, 120, 0);
    make_tree();
    glPopMatrix();
    glPushMatrix();
    glTranslated(100, 120, 0);
    make_tree();
    glPopMatrix();
}

void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    sun();
    cloud();
    hill();
    soil();
    ground();
    road();
    tree();
    flag();
    shaheed_minar();
    college();
    house();
    plane();
    privatecar();
    privatecar2();
    railline();
    train();
    station();
    glFlush();
}

void init() {
    glClearColor(0.3, 0.65, 1, 1.0);
    glOrtho(-300, 300, -300, 300, -150, 500);
}

void my_keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'b':
            glutIdleFunc(NULL);
            break;
        default:
            break;
    }
}

void spe_key(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            ty += 5;
            glutPostRedisplay();
            break;
        case GLUT_KEY_DOWN:
            ty -= 5;
            glutPostRedisplay();
            break;
        case GLUT_KEY_RIGHT:
            tx += 5;
            glutPostRedisplay();
            break;
        case GLUT_KEY_LEFT:
            tx -= 5;
            glutPostRedisplay();
            break;
        default:
            break;
    }
}

int main() {
    PlaySound("1.wav", NULL, SND_FILENAME | SND_ASYNC);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1500, 700);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Computer Graphics Project");
    init();
    glutDisplayFunc(myDisplay);
    glutSpecialFunc(spe_key);
    glutKeyboardFunc(my_keyboard);
    glutMainLoop();
    return 0;
}
