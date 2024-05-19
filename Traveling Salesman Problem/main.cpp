#include "Graph.h" // ����������� ����� � ������������ ��������� ������ 
#include <gl/glut.h> // ����������� ������������� ����� ���������� OpenGL
#include <iostream> // ����������� ������������� �����, ������� ��������� ������������ ��������� ����-�����
using namespace std; // ��������� ������������� ������������ ���� ����������� ���������� 

int main(int argc, char** argv) {
	system("chcp 1251"); // ������������ ������� �������� ��� ����������� ����������� ������� ��������
	glutInit(&argc, argv); // ������������� GLUT
	createGraph(); //  ����� ������� �������� �����
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // ������� ������ ����������� ����
	glutInitWindowSize(width, height); // ������� ������� ����
	glutCreateWindow("Graph"); // �������� ���� � ���������� 
	glutDisplayFunc(display); // ������� ������� ��� ����������� ����������� ����
	glutReshapeFunc(reshape); // ������� �������, ������� ���������� ��� ��������� �������� ����
	glutMouseFunc(mouseClick); // ������� �������, ������� ����� ���������� ��� ����� ����
	glutPassiveMotionFunc(mouseMove); // ������� �������, ������� ����� ���������� ��� �������� ������� ����
	glutMainLoop(); // ������ �������� ����� ��������� ������� GLUT
	return 0; // ���������� ���������� ���������
}