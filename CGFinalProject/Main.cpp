#pragma once
#include <GL/glut.h>
#include<math.h>
#include<iostream>
#include <vector>
#pragma once
#include "GitHubInterigation.h"
#include "MaterialStruct.h"
using namespace std;
void drawCuboid(double a, double b, double c,
	double x, double y, double z,
	MaterialStruct color);
void drawCuboid(double a, double b, double c,
	double x, double y, double z,
	MaterialStruct color,
	double theta,
	double nx, double ny, double nz);

//����(������g�U������ʌ���ʒu)
GLfloat lightAmb[] = { 0.f, 0.f, 0.f, 1.f };
GLfloat lightDiff[] = { .8f, .8f, .8f, 0.5f };
GLfloat lightSpec[] = { .8f, .8f, .8f, 0.5f };
GLfloat lightPos[] = { .8f, .8f, .8f, 0.f };//���s����

int WindowPositionX = 100;  //��������E�B���h�E�ʒu��X���W
int WindowPositionY = 100;  //��������E�B���h�E�ʒu��Y���W
int WindowWidth = 512;    //��������E�B���h�E�̕�
int WindowHeight = 512;    //��������E�B���h�E�̍���

double angle = 0.0;
//----------------------------------------------------
// �����̂̒�`
//----------------------------------------------------
GLdouble vertex[][3] = {
  { 0.0, 0.0, 0.0 },
  { 2.0, 0.0, 0.0 },
  { 2.0, 2.0, 0.0 },
  { 0.0, 2.0, 0.0 },
  { 0.0, 0.0, 30.0 },
  { 2.0, 0.0, 30.0 },
  { 2.0, 2.0, 30.0 },
  { 0.0, 2.0, 30.0 }
};
int face[][4] = {//�ʂ̒�`
  { 0, 1, 2, 3 },
  { 1, 5, 6, 2 },
  { 5, 4, 7, 6 },
  { 4, 0, 3, 7 },
  { 4, 5, 1, 0 },
  { 3, 2, 6, 7 }
};

float color[][3] = {
	{52.f / 255,9.f / 255,91.f / 255},
	{37.f / 255,0.f / 255,120.f / 255}
};

//----------------------------------------------------
// �֐��v���g�^�C�v�i��ɌĂяo���֐����ƈ����̐錾�j
//----------------------------------------------------
void Initialize(void);
void Display(void);
void Ground(void);
void keyHandler(unsigned char key, int x, int y);
void reshape(int w, int h);
void timer(int value);

int counter = 0;
double colorRate = 0.0;

vector<WeekContribution> contributionData;
int th = 0.0;
MaterialStruct material1 = ms_emerald;
MaterialStruct material2 = ms_copper;

int main(int argc, char* argv[]) {
	string name;

	//If you want to omit APIKey confirmation,
	//you can just assign ApiKey value into apiKey
	string apiKey;
	while (1) {
		printf("This program visualizes a GitHub user's contribution data\n");
		if (apiKey.empty()) {
			printf("First, you have to input GitHub personal access key.\n");
			cin >> apiKey;
		}
		printf("Input the target GitHub username...");
		cin >> name;
		try {
			contributionData = getContribution(name,apiKey);
			break;
		}
		catch (const std::exception& e)
		{
			printf("Error:%s\n", e.what());
			printf("Please retry\n");
		}
	}
	glutInit(&argc, argv);//���̏�����
	glutInitWindowPosition(WindowPositionX, WindowPositionY);//�E�B���h�E�̈ʒu�̎w��
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(900, 600);
	string title = name;
	title.append("'s GitHub Contribution Chart TYPE[C] to change design");
	glutCreateWindow(title.c_str());
	glutDisplayFunc(Display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyHandler);
	Initialize(); //�����ݒ�̊֐����Ăяo��
	glutTimerFunc(20.0, timer, 0);
	glutMainLoop();
	return 0;
}

void Initialize(void) {
	glEnable(GL_DEPTH_TEST);//�f�v�X�o�b�t�@���g�p�FglutInitDisplayMode() �� GLUT_DEPTH ���w�肷��

	gluPerspective(50.0, (double)WindowWidth / (double)WindowHeight, 0.1, 1000.0); //�������e�@�̎��̐�
	glClearColor(0.1f, 0.f, 0.1f, 1.f);
	glClearDepth(1.f);
	glEnable(GL_DEPTH_TEST);

	//�����ݒ�(����g�U����ʂ̂�)
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiff);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpec);

	//�����ƃ��C�e�B���O�L����
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);

}

void drawGitHub() {
	for (size_t i = 0; i < contributionData.size(); i++) {
		for (int j = 0; j < 7; j++) {
			if (contributionData.at(i).contributions[j] != 0)
				drawCuboid(4.0, 4.0, (contributionData.at(i).contributions[j] * 2.0), i * 5.0 - contributionData.size() * 2.5, j * 5.0, 5.0, material2);
			//cout << contributionData.at(i).contributions[j]<<" ";
		}
		//		cout << endl;
	}
	drawCuboid(contributionData.size() * 5.0, 40.0, 5.0, 0.0, 15.0, 0.0, material1);
}

void Display(void) {
	float cRate;
	if (colorRate > 1.0f) {
		cRate = 2.0f - colorRate;
	}
	else {
		cRate = colorRate;
	}
	if (colorRate >= 2.0f) {
		colorRate = 0.0f;
	}
	else {
		colorRate += 0.004f;
	}
	glClearColor(color[0][0] * cRate+ color[1][0]*(1-cRate), 
		color[0][1] * cRate + color[1][1] * (1 - cRate), 
		color[0][2] * cRate + color[1][2] * (1 - cRate), 1.f);
	th++;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glFlush();
	glLoadIdentity();
	gluLookAt(
		190 * cos(angle * 3.14 / 180), 170 * sin(angle * 3.14 / 180), 30.0, // ���_�̈ʒux,y,z;
		10.0, 0.0, 0.0,   // ���E�̒��S�ʒu�̎Q�Ɠ_���Wx,y,z
		0.0, 0.0, 1.0);  //���E�̏�����̃x�N�g��x,y,z

	//�����̈ʒu�ݒ�
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	Ground();
	drawGitHub();
	glutSwapBuffers();
}

void Ground(void) {
	double ground_max_x = 500.0;
	double ground_max_y = 500.0;
	glColor3d(0.8, 0.8, 0.8);
	glBegin(GL_LINES);
	for (double ly = -ground_max_y; ly <= ground_max_y; ly += 10.0) {
		glVertex3d(-ground_max_x, ly, 0);
		glVertex3d(ground_max_x, ly, 0);
	}
	for (double lx = -ground_max_x; lx <= ground_max_x; lx += 10.0) {
		glVertex3d(lx, ground_max_y, 0);
		glVertex3d(lx, -ground_max_y, 0);
	}
	glEnd();
}

void keyHandler(unsigned char key, int x, int y) {
	if (key == 27) exit(0);
	if (key == 99) {
		material1 = materials[rand() % materialNum];
		material2 = materials[rand() % materialNum];
	}
}

void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, double(w) / h, 0.1, 400.0);
	glutSwapBuffers();
	glMatrixMode(GL_MODELVIEW);
}


void timer(int value) {
	glutPostRedisplay();
	glutTimerFunc(20.0, timer, value);
	counter++;
	if (counter > 1000) {
		material1 = materials[rand() % materialNum];
		material2 = materials[rand() % materialNum];
		counter = 0;
	}
	angle += 0.12;
	if (angle > 360.0) {
		angle -= 360.0;
	}
}


// �����̂̕`��
void drawCuboid(double a, double b, double c,
	double x, double y, double z,
	MaterialStruct color) {
	glEnable(GL_LIGHTING);
	GLdouble vertex[][3] = {
		{ -a / 2.0, -b / 2.0, -c / 2.0 },
		{  a / 2.0, -b / 2.0, -c / 2.0 },
		{  a / 2.0,  b / 2.0, -c / 2.0 },
		{ -a / 2.0,  b / 2.0, -c / 2.0 },
		{ -a / 2.0, -b / 2.0,  c / 2.0 },
		{  a / 2.0, -b / 2.0,  c / 2.0 },
		{  a / 2.0,  b / 2.0,  c / 2.0 },
		{ -a / 2.0,  b / 2.0,  c / 2.0 }
	};
	int face[][4] = {//�ʂ̒�`
		{ 3, 2, 1, 0 },
		{ 1, 2, 6, 5 },
		{ 4, 5, 6, 7 },
		{ 0, 4, 7, 3 },
		{ 0, 1, 5, 4 },
		{ 2, 3, 7, 6 }
	};
	GLdouble normal[][3] = {//�ʂ̖@���x�N�g��
	  { 0.0, 0.0, -1.0 },
	  { 1.0, 0.0, 0.0 },
	  { 0.0, 0.0, 1.0 },
	  {-1.0, 0.0, 0.0 },
	  { 0.0,-1.0, 0.0 },
	  { 0.0, 1.0, 0.0 }
	};

	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, color.ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color.diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color.specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &color.shininess);

	glTranslated(x, y, z);//���s�ړ��l�̐ݒ�
	glBegin(GL_QUADS);
	for (int j = 0; j < 6; ++j) {
		glNormal3dv(normal[j]); //�@���x�N�g���̎w��
		for (int i = 0; i < 4; ++i) {
			glVertex3dv(vertex[face[j][i]]);
		}
	}
	glEnd();
	glPopMatrix();
	glDisable(GL_LIGHTING);
}

//��]���l�����������̂̕`��
void drawCuboid(double a, double b, double c,
	double x, double y, double z,
	MaterialStruct color,
	double theta,
	double nx, double ny, double nz) {
	double nn = sqrt(pow(nx, 2) + pow(ny, 2) + pow(nz, 2));
	if (nn > 0.0) {
		nx = nx / nn;
		ny = ny / nn;
		nz = nz / nn;
	}
	glPushMatrix();
	glTranslated(x, y, z);//���s�ړ��l�̐ݒ�
	glPushMatrix();
	if (theta != 0 && nn > 0.0) glRotated(theta, nx, ny, nz);
	drawCuboid(a, b, c, 0, 0, 0, color);
	glPopMatrix();
	glPopMatrix();
}