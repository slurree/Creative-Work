#include "Graph.h" // подключение файла с определением структуры данных 
#include <gl/glut.h> // подключение заголовочного файла библиотеки OpenGL
#include <iostream> // подключение заголовочного файла, который позволяет использовать потоковый ввод-вывод
using namespace std; // разрешает использование пространства имен стандартной библиотеки 

int main(int argc, char** argv) {
	system("chcp 1251"); // установление кодовой страницы для корректного отображения русских символов
	glutInit(&argc, argv); // инициализация GLUT
	createGraph(); //  вызов функции создания графа
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // задание режима отображения окна
	glutInitWindowSize(width, height); // задание размера окна
	glutCreateWindow("Graph"); // создание окна с заголовком 
	glutDisplayFunc(display); // задание функции для отображения содержимого окна
	glutReshapeFunc(reshape); // задание функции, которая вызывается при изменении размеров окна
	glutMouseFunc(mouseClick); // задание функции, которая будет вызываться при клике мыши
	glutPassiveMotionFunc(mouseMove); // задание функции, которая будет вызываться при движении курсора мыши
	glutMainLoop(); // запуск главного цикла обработки событий GLUT
	return 0; // завершение выполнения программы
}