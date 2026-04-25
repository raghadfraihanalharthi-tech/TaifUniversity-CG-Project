#include <GL/glut.h>
#include <cmath>
#include <string>

// Raghad Alblahdi - Project CG

bool isDaytime = true;
float catX = -0.95f;
bool doorOpen = false;

void drawRect(float x1, float y1, float x2, float y2)
{
    glBegin(GL_QUADS);
        glVertex2f(x1, y1);
        glVertex2f(x2, y1);
        glVertex2f(x2, y2);
        glVertex2f(x1, y2);
    glEnd();
}

void drawCircle(float cx, float cy, float r, int segments = 40)
{
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, cy);
        for (int i = 0; i <= segments; i++) {
            float angle = 2.0f * 3.14159f * i / segments;
            glVertex2f(cx + r * cos(angle), cy + r * sin(angle));
        }
    glEnd();
}

void drawText(float x, float y, const char* text)
{
    glRasterPos2f(x, y);
    while (*text)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *text++);
}

void drawSky()
{
    if (isDaytime)
        glColor3f(0.39f, 0.70f, 0.96f);
    else
        glColor3f(0.05f, 0.05f, 0.18f);
    drawRect(-1.0f, 0.0f, 1.0f, 1.0f);
}

void drawSkyObject()
{
    if (isDaytime) {
        glColor3f(1.0f, 0.92f, 0.20f);
        drawCircle(0.75f, 0.80f, 0.09f);
    } else {
        glColor3f(0.95f, 0.95f, 0.85f);
        drawCircle(0.75f, 0.80f, 0.07f);
        glColor3f(0.05f, 0.05f, 0.18f);
        drawCircle(0.80f, 0.83f, 0.055f);
        glColor3f(1.0f, 1.0f, 0.90f);
        float sx[] = {0.10f, 0.30f, 0.50f, 0.20f, 0.60f, -0.10f, -0.40f};
        float sy[] = {0.85f, 0.75f, 0.90f, 0.60f, 0.68f,  0.70f,  0.80f};
        for (int i = 0; i < 7; i++)
            drawCircle(sx[i], sy[i], 0.008f, 8);
    }
}

void drawGround()
{
    if (isDaytime)
        glColor3f(0.85f, 0.78f, 0.65f);
    else
        glColor3f(0.40f, 0.35f, 0.28f);
    drawRect(-1.0f, -0.55f, -0.25f, -0.20f);

    if (isDaytime)
        glColor3f(0.45f, 0.45f, 0.45f);
    else
        glColor3f(0.20f, 0.20f, 0.20f);
    drawRect(-0.25f, -1.0f, 1.0f, -0.20f);

    glColor3f(1.0f, 1.0f, 1.0f);
    for (int i = 0; i < 7; i++) {
        float lx = -0.10f + i * 0.28f;
        drawRect(lx, -0.62f, lx + 0.12f, -0.58f);
    }

    for (int i = 0; i < 8; i++) {
        float kx = -1.0f + i * 0.25f;
        if (i % 2 == 0) glColor3f(0.0f, 0.0f, 0.0f);
        else             glColor3f(1.0f, 1.0f, 1.0f);
        drawRect(kx, -0.23f, kx + 0.125f, -0.20f);
    }
}

void drawBuilding()
{
    if (isDaytime)
        glColor3f(0.93f, 0.87f, 0.72f);
    else
        glColor3f(0.45f, 0.42f, 0.32f);
    drawRect(-1.0f, -0.20f, -0.28f, 0.72f);

    if (isDaytime)
        glColor3f(0.80f, 0.73f, 0.58f);
    else
        glColor3f(0.35f, 0.32f, 0.24f);
    drawRect(-1.0f, 0.68f, -0.28f, 0.74f);

    float winColors[2][3] = {
        {0.65f, 0.85f, 0.95f},
        {1.00f, 0.95f, 0.50f}
    };
    int day = isDaytime ? 0 : 1;
    glColor3f(winColors[day][0], winColors[day][1], winColors[day][2]);

    float startX = -0.94f, startY = 0.20f;
    float winW = 0.14f, winH = 0.18f, gapX = 0.20f, gapY = 0.28f;
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 3; col++) {
            float wx = startX + col * gapX;
            float wy = startY + row * gapY;
            drawRect(wx, wy, wx + winW, wy + winH);
            glColor3f(0.60f, 0.54f, 0.40f);
            drawRect(wx, wy + winH * 0.48f, wx + winW, wy + winH * 0.52f);
            drawRect(wx + winW * 0.48f, wy, wx + winW * 0.52f, wy + winH);
            glColor3f(winColors[day][0], winColors[day][1], winColors[day][2]);
        }
    }

    if (isDaytime)
        glColor3f(0.55f, 0.40f, 0.25f);
    else
        glColor3f(0.25f, 0.18f, 0.10f);

    float doorX = -0.68f;
    float doorW = doorOpen ? 0.04f : 0.14f;
    drawRect(doorX, -0.20f, doorX + doorW, 0.05f);

    glColor3f(0.80f, 0.65f, 0.10f);
    drawCircle(doorX + doorW - 0.02f, -0.08f, 0.012f);

    if (isDaytime) glColor3f(0.88f, 0.82f, 0.68f);
    else           glColor3f(0.38f, 0.35f, 0.28f);
    drawRect(-0.74f, -0.20f, -0.70f, 0.12f);
    drawRect(-0.58f, -0.20f, -0.54f, 0.12f);

    if (isDaytime) glColor3f(0.82f, 0.76f, 0.62f);
    else           glColor3f(0.35f, 0.32f, 0.26f);
    drawRect(-0.78f, -0.26f, -0.50f, -0.22f);
    drawRect(-0.76f, -0.30f, -0.52f, -0.26f);
}

void drawStreetLight(float x, float groundY)
{
    if (isDaytime) glColor3f(0.55f, 0.55f, 0.55f);
    else           glColor3f(0.30f, 0.30f, 0.30f);
    drawRect(x - 0.012f, groundY, x + 0.012f, groundY + 0.50f);
    drawRect(x, groundY + 0.48f, x + 0.06f, groundY + 0.50f);

    if (isDaytime)
        glColor3f(0.70f, 0.70f, 0.70f);
    else
        glColor3f(1.00f, 0.95f, 0.60f);
    drawRect(x + 0.04f, groundY + 0.46f, x + 0.10f, groundY + 0.50f);
}

void drawTree(float x, float groundY)
{
    if (isDaytime) glColor3f(0.45f, 0.28f, 0.10f);
    else           glColor3f(0.22f, 0.14f, 0.06f);
    drawRect(x - 0.025f, groundY, x + 0.025f, groundY + 0.16f);

    if (isDaytime) glColor3f(0.25f, 0.55f, 0.20f);
    else           glColor3f(0.10f, 0.28f, 0.08f);
    drawCircle(x, groundY + 0.22f, 0.08f);
}

void drawPot(float x, float y)
{
    if (isDaytime) glColor3f(0.65f, 0.30f, 0.15f);
    else           glColor3f(0.30f, 0.14f, 0.07f);
    glBegin(GL_QUADS);
        glVertex2f(x - 0.025f, y);
        glVertex2f(x + 0.025f, y);
        glVertex2f(x + 0.018f, y + 0.06f);
        glVertex2f(x - 0.018f, y + 0.06f);
    glEnd();

    if (isDaytime) glColor3f(0.20f, 0.50f, 0.15f);
    else           glColor3f(0.10f, 0.25f, 0.08f);
    drawCircle(x, y + 0.09f, 0.04f);
}

void drawCat(float x)
{
    float y = -0.35f;

    if (isDaytime) glColor3f(0.55f, 0.45f, 0.35f);
    else           glColor3f(0.28f, 0.22f, 0.16f);
    drawCircle(x + 0.06f, y, 0.055f, 30);

    if (isDaytime) glColor3f(0.55f, 0.45f, 0.35f);
    else           glColor3f(0.28f, 0.22f, 0.16f);
    drawCircle(x + 0.13f, y + 0.04f, 0.038f, 30);

    if (isDaytime) glColor3f(0.55f, 0.45f, 0.35f);
    else           glColor3f(0.28f, 0.22f, 0.16f);
    glBegin(GL_TRIANGLES);
        glVertex2f(x + 0.108f, y + 0.072f);
        glVertex2f(x + 0.118f, y + 0.072f);
        glVertex2f(x + 0.110f, y + 0.098f);
        glVertex2f(x + 0.130f, y + 0.072f);
        glVertex2f(x + 0.145f, y + 0.072f);
        glVertex2f(x + 0.148f, y + 0.098f);
    glEnd();

    if (!isDaytime) glColor3f(0.40f, 0.90f, 0.20f);
    else            glColor3f(0.05f, 0.05f, 0.05f);
    drawCircle(x + 0.138f, y + 0.048f, 0.007f, 10);

    glColor3f(0.90f, 0.50f, 0.55f);
    drawCircle(x + 0.152f, y + 0.032f, 0.005f, 10);

    if (isDaytime) glColor3f(0.50f, 0.40f, 0.30f);
    else           glColor3f(0.24f, 0.18f, 0.12f);
    glBegin(GL_QUAD_STRIP);
        glVertex2f(x + 0.01f, y + 0.01f);
        glVertex2f(x - 0.01f, y + 0.01f);
        glVertex2f(x - 0.02f, y + 0.05f);
        glVertex2f(x - 0.04f, y + 0.05f);
        glVertex2f(x - 0.03f, y + 0.10f);
        glVertex2f(x - 0.05f, y + 0.10f);
        glVertex2f(x - 0.01f, y + 0.13f);
        glVertex2f(x - 0.03f, y + 0.14f);
    glEnd();

    if (isDaytime) glColor3f(0.50f, 0.40f, 0.30f);
    else           glColor3f(0.24f, 0.18f, 0.12f);
    drawRect(x + 0.02f, y - 0.05f, x + 0.04f, y);
    drawRect(x + 0.05f, y - 0.05f, x + 0.07f, y);
    drawRect(x + 0.09f, y - 0.05f, x + 0.11f, y);
    drawRect(x + 0.12f, y - 0.05f, x + 0.14f, y);
}

void drawHUD()
{
    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(-0.98f, -0.98f, "D: Day/Night  |  Arrow Keys: Move Cat  |  SPACE: Open/Close Door");
    drawText(-0.98f,  0.92f, isDaytime ? "Mode: DAY" : "Mode: NIGHT");
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawSky();
    drawSkyObject();
    drawGround();
    drawBuilding();
    drawStreetLight(0.05f, -0.20f);
    drawStreetLight(0.40f, -0.20f);
    drawStreetLight(0.70f, -0.20f);
    drawTree(-0.22f, -0.20f);
    drawTree(-0.14f, -0.20f);
    drawPot(-0.56f, -0.20f);
    drawPot(-0.46f, -0.20f);
    drawCat(catX);
    drawHUD();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 'd' || key == 'D')
        isDaytime = !isDaytime;
    if (key == ' ')
        doorOpen = !doorOpen;
    glutPostRedisplay();
}

void specialKeys(int key, int x, int y)
{
    if (key == GLUT_KEY_RIGHT) catX += 0.04f;
    if (key == GLUT_KEY_LEFT)  catX -= 0.04f;
    if (catX > 1.1f)  catX = -1.1f;
    if (catX < -1.1f) catX =  1.1f;
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(900, 600);
    glutCreateWindow("Project CG");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
    glutMainLoop();
    return 0;
}
