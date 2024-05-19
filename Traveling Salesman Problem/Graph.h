#pragma once // для предотвращения повторной обработки файлов
#include <gl/glut.h> // подключение заголовочного файла библиотеки OpenGL
#include <iostream> // подключение заголовочного файла, который позволяет использовать потоковый ввод-вывод
#include <vector> // подключение библиотеки для использования вектора
#include <string> // подключение библиотеки для использования строк
using namespace std; // разрешает использование пространства имен стандартной библиотеки 

const int maxSize = 20; // максимальное количество вершин в графе
extern int width; // ширина окна
extern int height; // высота окна
struct vertCoord { // структура для объектов с данными - координатами
	int x, y;
};

class Graph {
private:
	vector<int> vertList; // вектор вершин
	int adjMatrix[maxSize][maxSize]; // матрица смежности
public:
	Graph(); // конструктор
	~Graph(); // деструктор
	bool checkEmpty(); // функция проверки, пуст ли граф
	bool checkFull(); // функция проверки, полон ли граф
	int getElFromAdjMatrix(int i, int j) { return adjMatrix[i][j]; } // получение элемента матрицы смежности
	int amountVertices() { return vertList.size(); } // получение числа вершин
	int vertexPosition(const int& vertex); // получение позиции вершины
	void insertVertex(const int& vertex); // добавление вершины к графу
	void insertEdge(const int& vertex1, const int& vertex2, int weigth); // вставка нового ребра
	void print(); // функция печати матрицы смежности
	void eraseVertex(); // функция удаления вершины
	void eraseEdge(const int& vertex1, const int& vertex2); // функция удаления ребра
	void drawGraph(); // функция для отображения графа
};

bool checkData(int** matrix); // функция проверяет, есть ли данные для решения задачи коммивояжера
int** modificaMatrix(); // получение измененной матрицы
int* searchMinEl(int* line, int n); // поиск минимального элемента
int** reductMatrix(int** oldmatrix); // функция редуцирует матрицу смежности
int** findZero(int** oldmatrix); // функция возвращает измененную матрицу
void printAnswer(); // функция печатает результат работы программы

void drawButton1(); // отрисовка 1 кнопки
void drawButton2(); // отрисовка 2 кнопки
void drawButton3(); // отрисовка 3 кнопки
void drawButton4(); // отрисовка 4 кнопки
void drawButton5(); // отрисовка 5 кнопки
void drawButton6(); // отрисовка 6 кнопки

void drawCircle(int x, int y, int radius); // отрисовка окружности для вершины
void drawText(int num, int x1, int y1); // отображение текста 
void drawLine(int text, int x0, int y0, int x1, int y1); // отрисовка линий(ребер)
void drawVertex(int n); // функция для отрисовки вершин графа
void createGraph(); // функция для создания графа
void coords(int i, int n); // функция для установки координат вершин графа
void hoverCheckButton(int x, int y); // проверка, курсор находится на кнопке или нет
void mouseMove(int x, int y); // перемещение мыши по экрану
void mouseClick(int button, int state, int x, int y); // действия при нажатии на кнопки
void reshape(int w, int h); // ресайз окна OpenGL    
void display(); // основной цикл отрисовки