#include <iostream>
#include "windows.h"
#include "conio.h"
#include "gl/Gl.h"
#include "gl/glut.h"
using namespace std;


void MyInit() {
	glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
	glClearColor(0.5, 0.5, 0.5, 1); // Background Color

	//Other Inits
	glLineWidth(3.0);// Road White Line Points Size

	glMatrixMode(GL_PROJECTION); //Image Matrix mode
	glLoadIdentity(); // Loading Identity Matrix
	gluOrtho2D(0.0, 200.0, 0.0, 200.0); // 2D pane x-y axis
	//gluOrtho2D(0.0, 600.0, 0.0, 600.0); // 2D pane x-y axis
}

void mainMenuShow() {
	printf("\n");
	printf(" |===========================================================|\n");
	printf(" |===>Well Come to 'Semester Project Numl BSCS-34 Morning<===|\n");
	printf(" #----Graphics Project:-'Simulation of Khayaban-E-Johar'------#\n");
	printf(" |-----------------------------------------------------------|\n");
	printf(" |                                                           |\n");
	printf(" #------------             KeyBindings         --------------#\n");
	printf(" |    |> Press 'Shift' or 'Q' to Press Clutch of Car         |\n");
	printf(" |    |> Press Gear Key with Clutch to change Car Speed      |\n");
	printf(" |    W = 1st, S = 2nd, E = 3rd, D = 4th F = 5th             |\n");
	printf(" |    Clutch + R = HandBrake  or SpaceBar for Breaks         |\n");
	printf(" |                                                           |\n");
	printf(" |    |> Press 'n' or 'N' to make it Night Time              |\n");
	printf(" |    |> Press 'm' or 'M' to make it Day Time                |\n");
	printf(" |                                                           |\n");
	printf(" |    |> Press RIGHT MOUSE BUTTON to display menu            |\n");
	printf(" |       |> Select  'Disable' to remove Mouse Handler        |\n");
	printf(" |       |> Select  'Enable' to add Mouse Handler            |\n");
	printf(" |       |> Select  'Exit' to Exit the application           |\n");
	printf(" |                                                           |\n");
	printf(" |                      Gaming Mode                          |\n");
	printf(" |           Use Arrow Up   for Overtaking  (Accelartion)    |\n");
	printf(" |           Use Arrow Down for Speed Limit (Constant Speed) |\n");
	printf(" |-----------------------------------------------------------|\n");
	printf(" |======	    Developer :  Github.com/mzubair21      ======|\n");
	printf(" |===========================================================|\n");
}

//Sky
bool day = true;
void MoonLight(int x, int y)
{
	glBegin(GL_POLYGON); //Sky  
	glColor3f(0.04, 0.04, 0.02);
	glVertex2i(-200, 30);//bottomleft
	glVertex2i(350, 30);//bottomleft


	float th;
	glBegin(GL_POLYGON);
	glColor3f(0.85, 0.85, 0.84);

	glVertex2f(x, y + 5);


	glEnd();

}
void Moon(int x, int y)
{
	float th;
	glBegin(GL_POLYGON);
	if (!day) {
		glColor3f(1.65, 1.70, 1.75);
	}
	else {
		glColor3f(0.97, 0.84, 0.10);
	}
	for (int i = 0; i < 360; i++)
	{
		th = i * (3.1416 / 180);
		glVertex2f(x + 11 * cos(th), y + 11 * sin(th));
	}

	glEnd();

}
void Sky() {
	//Two Color Gradient Screen
	if (day) {


		glBegin(GL_POLYGON); //Sky  
		glColor3f(0.4, 0.5, 1.0);
		glVertex2i(0, 200); // topleft
		glVertex2i(200, 200);// topright
		glColor3f(0.7, 0.7, 1.0);
		glVertex2i(200, 0);//bottomright
		glVertex2i(0, 0);//bottomleft
		glEnd();
		Moon(40, 150);
		//cout << "\n Creating Sky ..... Completed";
	}
	else {
		glBegin(GL_POLYGON); //Sky  
		glColor3f(0.1, 0.2, 0.4);
		glVertex2i(0, 200); // topleft
		glVertex2i(200, 200);// topright
		glColor3f(0.2, 0.1, 0.5);
		glVertex2i(200, 0);//bottomright
		glVertex2i(0, 0);//bottomleft
		glEnd();
		MoonLight(100, 150);
		Moon(100, 150);
	}
}
//Building
void Building1() {

	glTranslatef(0, 0, 0);
	//Building-1
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);
	glVertex2i(120, 40);
	glVertex2i(90, 40);
	glVertex2i(90, 170);
	glVertex2i(120, 170);
	glEnd();

	//Window-1
	glColor3f(0.0f, 1.0f, 0.2f);
	glBegin(GL_QUADS);
	glVertex2i(115, 50);
	glVertex2i(95, 50);
	glVertex2i(95, 70);
	glVertex2i(115, 70);
	glEnd();
	//Window-1-frame-x
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_LINES);
	glLineWidth(6.0);
	glVertex2i(120, 60);
	glVertex2i(90, 60);
	glEnd();
	//Window-1-frame-y
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_LINES);
	glLineWidth(6.0);
	glVertex2i(110, 50);
	glVertex2i(110, 70);
	glEnd();

	//Window-2
	glColor3f(0.0f, 1.0f, 0.2f);
	glBegin(GL_QUADS);
	glVertex2i(115, 75);
	glVertex2i(95, 75);
	glVertex2i(95, 95);
	glVertex2i(115, 95);
	glEnd();
	//Window-2-frame-x
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_LINES);
	glLineWidth(6.0);
	glVertex2i(120, 85);
	glVertex2i(90, 85);
	glEnd();
	//Window-2-frame-y
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_LINES);
	glLineWidth(6.0);
	glVertex2i(100, 75);
	glVertex2i(100, 95);
	glEnd();

	//Window-3
	glColor3f(0.0f, 1.0f, 0.2f);
	glBegin(GL_QUADS);
	glVertex2i(115, 100);
	glVertex2i(95, 100);
	glVertex2i(95, 120);
	glVertex2i(115, 120);
	glEnd();
	//Window-3-frame-x
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_LINES);
	glLineWidth(6.0);
	glVertex2i(120, 110);
	glVertex2i(90, 110);
	glEnd();
	//Window-3-frame-y
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_LINES);
	glLineWidth(6.0);
	glVertex2i(110, 100);
	glVertex2i(110, 120);
	glEnd();

	//Window-4
	glColor3f(0.0f, 1.0f, 0.2f);
	glBegin(GL_QUADS);
	glVertex2i(115, 125);
	glVertex2i(95, 125);
	glVertex2i(95, 160);
	glVertex2i(115, 160);
	glEnd();
}


//Trees
void Tree(int Treex) {
	glTranslatef(Treex, 0, 0);
	//Tree-1
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex2i(40, 40);
	glVertex2i(45, 40);
	glVertex2i(45, 60);
	glVertex2i(40, 60);
	glEnd();

	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	glVertex2i(35, 60);
	glVertex2i(50, 60);
	glVertex2i(42, 90);
	glEnd();
}

// Road 
void Line(int a, int b)
{
	glColor3f(1, 1, 1);
	glBegin(GL_LINES);
	glVertex2i(a, 20); // line starting x
	glVertex2i(b, 20); // line ending x
	glEnd();
	//cout << "\n Creating White Line ..... ";
}
float Roadx = 0;
void Road() { // Black Road Carpet
	// If Stop Car Road x = 0
	glTranslatef(Roadx, 0, 0);
	glColor3f(0.152, 0.152, 0.152);
	glBegin(GL_POLYGON);
	glVertex2i(0, 0);
	glVertex2i(0, 40);
	glVertex2i(500, 40);
	glVertex2i(500, 0);
	glEnd();
	//cout << "\n Creating Balck Road .....";
}
//Car
void window(int w1, int w2)
{
	glColor3f(0.10, 0.10, 0.10);
	glBegin(GL_POLYGON);
	glVertex2f(w1, 160);
	glVertex2f(w1, 185);
	glVertex2f(w2, 185);
	glVertex2f(w2, 160);
	glEnd();
}
void wheel(int x, int y)
{
	float th;
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	for (int i = 0; i < 360; i++)
	{
		th = i * (3.1416 / 180);
		glVertex2f(x + 20 * cos(th), y + 20 * sin(th));
	}

	glEnd();

}
void cloud(int x, int y, float tx, float ty)
{

	glPushMatrix();
	glTranslatef(tx, ty, 0);
	float th;
	glBegin(GL_POLYGON);
	glColor3f(1.25, 0.924, 0.930);
	for (int i = 0; i < 360; i++)
	{
		th = i * (3.1416 / 180);
		glVertex2f(x + 10 * cos(th), y + 10 * sin(th));
	}
	glEnd();
	glPopMatrix();
}
//Clouds All 3 blocks
void CompileCloud(float x, float y, float sx, float sy) {
	glPushMatrix();
	glTranslatef(x, y, 0);
	glScalef(sx, sy, 0);
	cloud(100, 130, 4, -3);
	cloud(100, 130, 0, 0);
	cloud(100, 130, -4, -3);
	glPopMatrix();
}


void Car(int x, int y, float r, float g, float b) {
	/// CAR
	glPushMatrix();
	glTranslatef(x, y, 0);
	glScalef(0.12, 0.15, 0);
	glColor3f(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2f(155, 100);
	glVertex2f(155, 160);
	glVertex2f(452, 160);
	glVertex2f(452, 100);
	glEnd();

	//Top Part
	glBegin(GL_POLYGON);
	glVertex2f(150, 160);
	glVertex2f(200, 200);
	glVertex2f(400, 200);
	glVertex2f(450, 160);

	glEnd();
	window(200, 270);
	window(280, 330);
	window(340, 390);
	wheel(200, 100);
	wheel(380, 100);
	glPopMatrix();
}

//////////////////
int lap = 0;
float Carx = 0;
float carR = 0.4, carG = 0.1, carB = 0;
void changeLap() {
	lap++;
	if (lap > 1) {
		lap = 0;
	}
	carR = (float)rand() / RAND_MAX;
	carG = (float)rand() / RAND_MAX;
	carB = (float)rand() / RAND_MAX;
}
float Treex = 0;
float Buildx = 0;
float C1x = 0;
float C2x = 0;
//////////////////

void CompiledRoad() { // Putting White Lines on Road
	glPushMatrix();
	Road();
	int startx = 7; // Line Starting x axis
	for (int i = 0; i < 47; i++)
	{
		Line(startx, startx + 5);
		startx = startx + 10;
	}

	glPopMatrix();

	//Building Anim
	glPushMatrix();
	glTranslatef(Buildx, 0, 0);
	Building1();
	glPopMatrix();

	//Tree Anim
	glPushMatrix();
	glTranslatef(Treex, 0, 0);
	Tree(20);
	Tree(70);
	Tree(50);
	Tree(80);
	Tree(70);
	Tree(50);
	glPopMatrix();


	//Clouds

	glPushMatrix();
	glTranslatef(C1x, 0, 0);
	CompileCloud(0, 0, 1, 1);
	glPopMatrix();

	/*glPushMatrix();
	glTranslatef(C2x, 0, 0);
	CompileCloud(100, 110, 0.8, 0.6);
	CompileCloud(0, 110, 0.6, 0.5);
	CompileCloud(70, 100, 0.8, 0.5);
	CompileCloud(-67, 100, 0.8, 0.5);
	glPopMatrix();*/

	glPushMatrix();
	glTranslatef(C2x, 0, 0);
	CompileCloud(0, 110, 0.8, 0.6);
	CompileCloud(50, 80, 0.8, 0.6);
	CompileCloud(200, 110, 0.8, 0.6);
	CompileCloud(250, 80, 0.8, 0.6);
	glPopMatrix();







	//-------------- opponent Car -------------- //
	// Car Translated Seperately not with Road.
	glPushMatrix();
	//If stop opposite car Carx = 0
	glTranslatef(Carx, 0, 0);
	Car(200, 15, carR, carG, carB);
	glPopMatrix();
	//cout << "\n Compiling Road and Lines ..... Completed \n\n\n";






}


//////////////////////
int Gear = 0;// Car Gear
float gearRx = 0;
float gearCx = 0;
float gearTx = 0;
float gearBx = 0;
float gearC1x = 0;
float gearC2x = 0;
//////////////////////
void RoadAnim() {

	switch (Gear) {
	case(0): { // we road build stop clouds little move OppCar Fast;
		gearRx = 0;
		if (lap == 0) {
			gearCx = 0.15;
		}
		else if (lap == 1) {
			gearCx = 0.3;
		}
		gearTx = 0.0;
		gearBx = 0.0;
		gearC1x = 0.01;
		gearC2x = 0.001;
		break;
	}
	case(1): { // we road build move slow OppCar little slow  clouds tree more move;
		gearRx = 0.05;
		if (lap == 0) {
			gearCx = 0.03;
		}
		else if (lap == 1) {
			gearCx = 0.1;
		}
		gearTx = 0.03;
		gearBx = 0.001;
		gearC1x = 0.01;
		gearC2x = 0.005;
		break;
	}
	case(2): {
		gearRx = 0.12;
		gearCx = 0.01;
		gearTx = 0.09;
		gearBx = 0.005;
		gearC1x = 0.03;
		gearC2x = 0.008;
		break;
	}
	case(3): {
		gearRx = 0.18;
		gearCx = 0.001;
		gearTx = 0.15;
		gearBx = 0.02;
		gearC1x = 0.05;
		gearC2x = 0.03;
		break;
	}
	case(4): {
		gearRx = 0.2;
		gearCx = 0.01;
		gearTx = 0.2;
		gearBx = 0.07;
		gearC1x = 0.09;
		gearC2x = 0.05;
		break;
	}case(5): {
		gearRx = 0.4;
		gearCx = 0.2;
		gearTx = 0.3;
		gearBx = 0.09;
		gearC1x = 0.2;
		gearC2x = 0.1;
		break;
	}
	}


	Roadx = Roadx - gearRx; // Control Speed of Road -----------------------
	if (Roadx <= -100) {
		Roadx = 0;

	}

	Treex = Treex - gearTx; // Control Speed of Tree -----------------------
	if (Treex <= -200) {
		Treex = 0;
	}

	Buildx = Buildx - gearBx; // Control Speed of Tree -----------------------
	if (Buildx <= -120) {
		Buildx = 115;
	}

	C1x = C1x - gearC1x; // Control Speed of Mid Cloud -----------------------
	if (C1x <= -120) {
		C1x = 115;
	}

	C2x = C2x - gearC2x; // Control Speed of Mid Cloud -----------------------
	if (C2x <= -200) {
		C2x = 0;
	}


	// Gear 0 RX-> 0.0  - cx 0.1
	// Gear 1 RX-> 0.02 - cx 0.08


	if (Gear <= 2) {
		// Overtaking Going Forward
		Carx = Carx + gearCx; // Control Speed of Road -----------------------
		if (Carx >= -20) {
			Carx = -260; // resetting position to end
			changeLap();
		}
	}
	else {
		/*Overtaken Going Back*/
		Carx = Carx - gearCx; // Control Speed of Road -----------------------
		if (Carx <= -260) {
			Carx = -20; // Starting point is at End of road - to go back
			changeLap();
		}
	}





	glutPostRedisplay();
}



void MouseFunc(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON and state == GLUT_DOWN) {
		if (Gear < 4) {
			Gear = Gear + 1;
			cout << "\nGear --- " << Gear;
		}


	}
	if (button == GLUT_RIGHT_BUTTON and state == GLUT_DOWN) {
		if (Gear > 0) {
			Gear = Gear - 1;
			cout << "\nGear --- " << Gear;
		}




	}
	glutPostRedisplay();

}
bool ClutchisPressed = false;
bool QisPressed = false;
unsigned char ClutchKey = 'q';
unsigned char ClutchSecondaryKey = 'Q';
void KeyboardFunc(unsigned char button, int x, int y) {
	if (button == 'n' || button == 'N') {
		day = false;
	}
	else if (button == 'm' || button == 'M') {
		day = true;

	}
	if (button == ClutchKey || button == ClutchSecondaryKey) {
		QisPressed = true;
	}

	if (glutGetModifiers() == GLUT_ACTIVE_SHIFT || QisPressed) {
		ClutchisPressed = true;
		mainMenuShow();
		cout << "Clutch True";
	}

	///Breaks
	switch (button) {
	case ' ':
		Gear = 0;
		break;
	}
	///Gears
	if (ClutchisPressed) {
		switch (button) {

		case 'w':
		case 'W': {
			Gear = 1;
			break;
		}
		case 's':
		case 'S': {
			Gear = 2;
			break;
		}
		case 'e':
		case 'E': {
			Gear = 3;
			break;
		}
		case 'd':
		case 'D': {
			Gear = 4;
			break;
		}
		case 'f':
		case 'F': {
			Gear = 5;
			break;
		}
		case 'r':
		case 'R': {
			Gear = 0;
			break;
		}

		}

	}
	else {
		//Gear = 0; // Stop car if gear not change with clutch
	}

}

void KeyboardUpFunc(unsigned char button, int x, int y) {

	ClutchisPressed = false;

	mainMenuShow();
	cout << " Clutch False";
	if (button == ClutchKey || button == ClutchSecondaryKey) {
		QisPressed = false;
	}
	if (QisPressed) {
		ClutchisPressed = true;
	}


}
bool UpisPressed = false;

void SpecialFunc(int button, int x, int y) {
	if (button == GLUT_KEY_UP) {
		UpisPressed = true;
		if (UpisPressed) {
			Gear = 5;
		}
	}

	if (button == GLUT_KEY_DOWN) {
		Gear = 3;
	}
}
void SpecialUpFunc(int button, int x, int y) {
	if (button == GLUT_KEY_UP) {
		UpisPressed = false;
		if (!UpisPressed) {
			Gear = 1;
		}
	}

	if (button == GLUT_KEY_DOWN) {
		Gear = 2;
	}
}


int mx = 0; int my = 0; bool MouseHandler = false;
void PassiveFunc(int x, int y) {

	glutSetCursor(GLUT_CURSOR_FULL_CROSSHAIR);
	if (MouseHandler) {
		if (y != my) {
			if (y < my) {
				if (Gear < 4) {
					Gear = Gear + 1;
					cout << "\nGear --- " << Gear;
				}
			}
			else if (y > my) {
				if (Gear > 1) {
					Gear = Gear - 1;
					cout << "\nGear --- " << Gear;
				}
			}
		}

		mx = x; my = y;
	}

}
void menu(int id) {
	switch (id) {
	case 1: {
		MouseHandler = false;
		break;
	}
	case 2: {
		MouseHandler = true;
		break;
	}
	case 3: {
		Gear = 5;
		break;
	}case 4: {
		day = true;
		break;
	}
	case 5: {
		day = false;
		break;
	}
	case 6: {
		exit(0);
		break;
	}
	}
	glFlush();
}
void createMenu() {




	int m2 = glutCreateMenu(menu);
	glutAddMenuEntry("Day", 4);
	glutAddMenuEntry("Night", 5);


	int sub2 = glutCreateMenu(menu);
	glutAddSubMenu("Time", m2);



	glutAddMenuEntry("Disable Mouse Handler", 1);
	glutAddMenuEntry("Enable Mouse Handler", 2);

	int sub3 = glutCreateMenu(menu);
	glutAddSubMenu("MouseHandler", sub2);

	glutAddMenuEntry("Sports Mode", 3);
	glutAddMenuEntry("Exit", 6);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);// Clear Screen With default bg Color

	// Dispaly
	Sky();
	CompiledRoad();
	Car(0, 0, 0, 0, 1);

	glFlush();


}

int main(int argc, char* argv[]) {
	mainMenuShow();

	glutInit(&argc, argv);
	glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 500);// Window Size
	glutInitWindowPosition(300, 150); // Window Position
	glutCreateWindow("GTA - Numlian H9, Islamabad"); // Window Title

	glutDisplayFunc(MyDisplay);// Window Display Funtion

	//Functions
	glutMouseFunc(MouseFunc);
	glutKeyboardFunc(KeyboardFunc);
	glutKeyboardUpFunc(KeyboardUpFunc);
	glutSpecialFunc(SpecialFunc);
	glutSpecialUpFunc(SpecialUpFunc);
	glutPassiveMotionFunc(PassiveFunc);
	glutIdleFunc(RoadAnim);
	MyInit(); // GLUT Initial Values - BackgroundColor- Matrix Mode etc

	//Menu
	createMenu();

	glutMainLoop(); // Waiting for input
	return 0;
}