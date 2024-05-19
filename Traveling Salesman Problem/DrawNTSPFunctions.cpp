#include "Graph.h" // подключение файла с определением структуры данных 
using namespace std; // разрешает использование пространства имен стандартной библиотеки 

int width = 1080; // ширина
int height = 780; // высота
int radius; // радиус окружностей
int buttonBacklight; // переменная, которая будет содержать номер кнопки, на которую наведен курсор

vertCoord coordinates[maxSize + 2]; // вектор координат
Graph graph; // объявление объекта класса 

vector<pair<int, int>> indexes; // вектор пар для хранения индексов
vector<int> newIndexes; // правильная последовательность индексов для решения задачи коммивояжера


void Graph::drawGraph() { // функция для отображения графа
	int n = graph.amountVertices(); // получение количества вершин в графе
	for (int i = 0; i < n; i++) { // цикл для установки координат для всех вершин
		coords(i, n); // установка координат для вершины с индексом i
	}
	for (int i = 0; i < n; i++) { // основной цикл для рисования рёбер
		for (int j = 0; j < n; j++) { // подцикл для проверки наличия рёбер между вершинами
			int a = adjMatrix[i][j]; // получение веса ребра между вершинами i и j
			if (a != 0) { // если ребро существует
				drawLine(a, coordinates[j].x, coordinates[j].y, coordinates[i].x, coordinates[i].y); // рисование линии
			}
		}
	}
	drawVertex(n); // рисование вершин
	glutPostRedisplay(); // обновление отображения
}


int** modificaMatrix() { // получение измененной матрицы
	int n = graph.amountVertices(); // получение количества вершин в графе
	int** matrix = new int* [n]; // создание новой матрицы размером n x n
	for (int i = 0; i < n; i++)
		matrix[i] = new int[n];
	for (int i = 0; i < n; i++) { // заполнение матрицы элементами из исходной матрицы смежности
		for (int j = 0; j < n; j++) {
			int elem = graph.getElFromAdjMatrix(i, j); // получение значения элемента исходной матрицы смежности
			if (elem == 0 || i == j) // если элемент равен нулю или i равно j
				matrix[i][j] = -1;
			else // в противном случае сохраняется значение элемента
				matrix[i][j] = elem;
		}
	}
	return matrix; // возврат измененной матрицы
}


int* searchMinEl(int* line, int n) { // поиск минимального элемента
	int min = 1000000; // инициализация переменной min максимально возможным значением
	for (int j = 0; j < n; j++) { // перебор всех вершин
		if (line[j] >= 0 && line[j] < min) { // поиск минимального положительного элемента
			min = line[j];
		}
	}
	for (int j = 0; j < n; j++) { // перебор всех вершин
		if (line[j] >= 0) { // уменьшение всех элементов на значение минимального
			line[j] -= min; // обновление
		}
	}
	return line; // возвращение измененного массива
}



int** reductMatrix(int** oldmatrix) { // функция редуцирует матрицу смежности
	int** matrix = oldmatrix; // указатель на матрицу смежности
	int n = graph.amountVertices(); // количество вершин в графе
	for (int i = 0; i < n; i++) { // цикл проходит по всем строкам матрицы смежности
		matrix[i] = searchMinEl(matrix[i], n); // поиск минимального элемента в строке i и его редукция
	}
	for (int i = 0; i < n; i++) { // этот цикл проходит по всем столбцам матрицы смежности
		int min = 1000000; // инициализация min максимально возможным значением
		for (int j = 0; j < n; j++) { // цикл находит минимальный положительный элемент в столбце i
			if (matrix[j][i] >= 0 && matrix[j][i] < min) // если элемент matrix[j][i] положительный и меньше min
				min = matrix[j][i]; // обновление
		}
		for (int j = 0; j < n; j++) { // цикл уменьшает все элементы в столбце i на min
			if (matrix[j][i] >= 0) // если элемент matrix[j][i] положительный
				matrix[j][i] -= min; // уменьшение
		}
	}
	return matrix; // возврат редуцированной матрицы
}


int** findZero(int** oldmatrix) { // функция возвращает измененную матрицу
	int n = graph.amountVertices(); // получение количества вершин в графе
	int** matrix = reductMatrix(oldmatrix); // получаем редуцированной матрицы
	int max = -1; // инициализация переменной, которая будет содержать максимальное значение
	int line, column; // инициализация переменных для хранения индексов
	for (int i = 0; i < n; i++) { // перебор строк матрицы
		for (int j = 0; j < n; j++) { // перебор столбцов матрицы
			if (matrix[i][j] == 0) { // если элемент матрицы равен нулю
				int minLine = 1000000; // инициализация переменной, которая будет содержать минимальное значение среди строк
				int minColumn = 1000000; // инициализация переменной, которая будет содержать минимальное значение среди столбцов
				for (int k = 0; k < n; k++) { // перебор всех строк матрицы
					if (matrix[i][k] != -1 && k != j && matrix[i][k] < minLine) // условие для поиска минимального элемента среди строк
						minLine = matrix[i][k]; // обновление
				}
				for (int k = 0; k < n; k++) { // перебор столбцов матрицы
					if (matrix[k][j] != -1 && k != i && matrix[k][j] < minColumn) // условие для поиска минимального элемента среди столбцов
						minColumn = matrix[k][j];
				}
				if (max < minColumn + minLine) { // условие для обновления максимального значения
					max = minColumn + minLine; // обновление
					line = i; // обновление
					column = j; // обновление
				}
			}
		}
	}
	pair<int, int> p; // объявление пары для хранения индексов
	p.first = line + 1; // обновление первого элемента пары 
	p.second = column + 1; // обновление второго элемента пары 
	indexes.push_back(p); // добавление пары в вектор пар
	matrix[line][column] = -1; // устанавление элементов матрицы равными -1
	matrix[column][line] = -1;// устанавление элементов матрицы равными -1
	for (int i = 0; i < n; i++) { // перебор всех строк матрицы
		matrix[line][i] = -1; // устанавление элементов строки равными -1
		matrix[i][column] = -1; // устанавление элементов стобцов равными -1
	}
	return matrix; // возврат измененной матрицы
}


void printAnswer() { // функция печатает результат работы программы
	int second = indexes[0].second; // second используется для хранения индекса второго узла в пути
	int i = 2; // переменная i используется для подсчёта количества добавленных в путь узлов
	newIndexes.push_back(indexes[0].first); // добавление первого узла в путь
	newIndexes.push_back(indexes[0].second); // добавление второго узла в путь
	while (i != graph.amountVertices() + 1) { // пока количество добавленных узлов меньше количества всех узлов в графе
		for (int j = 1; j < graph.amountVertices(); j++) { // поиск следующего узла в пути
			if (indexes[j].first == second) { // если текущий узел равен второму узлу в пути
				second = indexes[j].second; // обновление второго узла в пути
				newIndexes.push_back(second); // добавление нового второго узла в путь
				i++; // увеличение счётчика добавленных узлов
				break; // выход из цикла, так как узел найден
			}
		}
	}
	cout << "Решение задачи коммивояжера: "; // печать результата
	for (int i = 0; i < newIndexes.size(); i++) { // перебор всех узлов в пути
		cout << newIndexes[i]; // печать текущего узла
		if (i != newIndexes.size() - 1) { // если текущий узел не последний
			cout << " -> "; // печать символа перехода к следующему узлу
		}
	}
	int sum = 0; // сумма длин ребер в найденном пути
	for (int i = 0; i < indexes.size(); i++) { // перебор всех ребер в пути
		int line = indexes[i].first - 1; // получение номера строки для текущего ребра
		int column = indexes[i].second - 1; // получение номера столбца для текущего ребра
		sum += graph.getElFromAdjMatrix(line, column); // добавление длины ребра к сумме
	}
	cout << endl << "S = " << sum << endl << endl; // печать суммы длин ребер
}




void drawCircle(int x, int y, int radius) { // отрисовка окружности для вершины
	glColor3f(255.0f, 235.0f, 192.0f); // установка цвета круга
	glBegin(GL_POLYGON); { // начало рисования
		float theta;
		float X, Y;
		for (int i = 0; i < 360; i++) {
			theta = 2.0f * 3.1415926f * float(i) / float(360); // вычисление координат точки на окружности
			X = radius * sin(theta) + x; // координата по x для окружности
			Y = radius * cos(theta) + y; // координата по y для окружности
			glVertex2f(X, Y); // добавление точки
		}
	}
	glEnd(); // конец рисования 
	glBegin(GL_LINE_LOOP); { // начало рисования замкнутой линии
		for (int i = 0; i < 360; i++) {
			float theta;
			float X, Y;
			theta = 2.0f * 3.1415926f * float(i) / float(360);  // вычисление координат точки на окружности
			X = radius * sin(theta) + x; // координата по x для линии
			Y = radius * cos(theta) + y; // координата по x для линии
			glVertex2f(X, Y); // добавление точки к линии
		}
	}
	glEnd(); // конец рисования замкнутой линии
}

void drawText(int text, int x1, int y1) { // отображение текста 
	glColor3f(0.0, 0.0, 0.0); // установка цвета текста
	GLvoid* font = GLUT_BITMAP_HELVETICA_18; // установка шрифта
	std::string s = std::to_string(text); // преобразование числа text в строку
	glRasterPos2i(x1 - 5, y1 - 5); // определение позиции текста
	for (size_t j = 0; j < s.length(); j++) { // отображение каждого символа строки
		glutBitmapCharacter(font, s[j]);
	}
}


void drawLine(int text, int x0, int y0, int x1, int y1) { // отрисовка линий(ребер)
	glColor3i(0, 0, 0); // установка цвета линии 
	glBegin(GL_LINES); // рисование линии
	glVertex2i(x0, y0); // указание начала линии
	glVertex2i(x1, y1); // указание конца линии
	glEnd();  // конец рисования линии
	drawText(text, (x0 + x1) / 2 + 10, (y0 + y1) / 2 + 10); // рисование текста с информацией о линии
}


void drawVertex(int n) { // функция для отрисовки вершин графа
	for (int i = 0; i < n; i++) { // цикл для перебора всех вершин
		drawCircle(coordinates[i].x, coordinates[i].y, radius); // отрисовка круга (вершины)
		drawText(i + 1, coordinates[i].x, coordinates[i].y); // отрисовка текста (номера вершины)
	}
}


void coords(int i, int n) { // функция для установки координат вершин графа
	int radius2; // переменная для хранения радиуса круга
	int x0 = width / 2.8; // координаты центра графа
	int y0 = height / 2;
	if (width > height) { // проверка соотношения сторон окна
		radius = 3 * (height / 13) / n; // расчет радиуса круга
		radius2 = height / 2 - radius - 10; // расчет координаты 
	}
	else {
		radius = 3 * (width / 13) / n; // расчет радиуса круга
		radius2 = width / 2 - radius - 10; // расчет координаты 
	}
	float theta = 2.0f * 3.1415926f * i / n; // рсасчет угла theta для i-й вершины
	int y1 = radius2 * cos(theta) + y0; // расчет координаты y1
	int x1 = radius2 * sin(theta) + x0; // расчет координаты x1
	coordinates[i].x = x1; // установка координаты x для i-й вершины
	coordinates[i].y = y1; // установка координаты y для i-й вершины
}


void createGraph() { // функция для создания графа
	int amountVerts, AmountEdges, originalVertex, finalVertex, weight; // объявление переменных
	cout << "Введите количество вершин: "; // запрос у пользователя количества вершин
	cin >> amountVerts; // ввод количества вершин
	cout << "Введите количество ребер: "; // запрос у пользователя количества рёбер
	cin >> AmountEdges; // ввод количества рёбер
	cout << endl; // переход на новую строку
	for (int i = 1; i <= amountVerts; i++) { // цикл для добавления всех вершин в граф
		graph.insertVertex(i); // добавление вершины в граф
	}
	for (int i = 0; i < AmountEdges; i++) { // цикл для добавления всех ориентированных ребер в граф 
		cout << "Введите начальную вершину: "; // запрос у пользователя исходной вершины
		cin >> originalVertex; // ввод исходной вершины
		cout << "Введиите конечную вершину: "; // запрос у пользователя конечной вершины
		cin >> finalVertex; // ввод конечной вершины
		cout << "Введите вес ребра: "; // запрос у пользователя веса ребра
		cin >> weight; // ввод веса ребра
		cout << endl;
		graph.insertEdge(originalVertex, finalVertex, weight); // добавление ребра в граф
	}
	cout << endl; // переход на новую строку
	graph.print(); // вывод графа на экран
}

bool checkData(int** matrix) { // функция проверяет, есть ли данные для решения задачи коммивояжера
	if (graph.checkEmpty()) // проверка, пуст ли граф
		return false;
	for (int i = 0; i < graph.amountVertices(); i++) { // для каждого узла в графе
		int cnt = 0; // счет количества соседей текущего узла
		for (int j = 0; j < graph.amountVertices(); j++) {
			if (matrix[i][j] > 0) // если есть ребро от текущего узла к j-му узлу
				cnt++; // увеличение
		}
		if (cnt < 1) // если узел не имеет соседей, возврат false
			return false;
	}
	return true; // если все узлы имеют соседей, возврат true
}


void drawButton1() { // отрисовка 1 кнопки
	if (buttonBacklight == 1) { // проверка состояния подсветки кнопки
		glColor3f(245.0f / 255.0f, 222.0f / 255.0f, 179.0f / 255.0f); // установка цвета подсветки
	}
	else {
		glColor3f(0.9, 0.8, 0.9); // установка цвета кнопки
	}
	glBegin(GL_QUADS); { // рисовка кнопки
		glVertex2i(width - width / 6, height - height / 10 - 20); // верхний левый угол кнопки
		glVertex2i(width - width / 6, height - 2 * (height / 10)); // нижний левый угол кнопки
		glVertex2i(width - 50, height - 2 * (height / 10)); // нижний правый угол кнопки
		glVertex2i(width - 50, height - height / 10 - 20); // верхний правый угол кнопки
	}
	glEnd();
	glColor3f(0.0f, 0.0f, 0.0f); // установка цвета для границ кнопки
	glBegin(GL_LINE_LOOP); { // граница вокруг кнопки
		glVertex2i(width - width / 6, height - height / 10 - 20);  // верхний левый угол кнопки
		glVertex2i(width - width / 6, height - 2 * (height / 10)); // нижний левый угол кнопки
		glVertex2i(width - 50, height - 2 * (height / 10)); // нижний правый угол кнопки
		glVertex2i(width - 50, height - height / 10 - 20); // верхний правый угол кнопки
	}
	glEnd();
	string name = "TSP"; // имя кнопки
	glRasterPos2i(width - 130, 0.83 * height); // определение позиции для текста на кнопке
	for (int i = 0; i < name.length(); i++) {
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, name[i]); // рисовка текста на кнопке
	}
}

void drawButton2() { // отрисовка 2 кнопки
	if (buttonBacklight == 2) { // проверка состояния подсветки кнопки
		glColor3f(245.0f / 255.0f, 222.0f / 255.0f, 179.0f / 255.0f); // установка цвета подсветки
	}
	else {
		glColor3f(0.9, 0.8, 0.9); // установка цвета кнопки
	}
	glBegin(GL_QUADS); { // рисовка кнопки
		glVertex2i(width - width / 6, height - 2 * (height / 10) - 20); // верхний левый угол кнопки
		glVertex2i(width - width / 6, height - 3 * (height / 10)); // нижний левый угол кнопки
		glVertex2i(width - 50, height - 3 * (height / 10)); // нижний правый угол кнопки
		glVertex2i(width - 50, height - 2 * (height / 10) - 20); // верхний правый угол кнопки
	}
	glEnd();
	glColor3f(0.0f, 0.0f, 0.0f); // установка цвета для границ кнопки
	glBegin(GL_LINE_LOOP); { // граница вокруг кнопки
		glVertex2i(width - width / 6, height - 2 * (height / 10) - 20);  // верхний левый угол кнопки
		glVertex2i(width - width / 6, height - 3 * (height / 10)); // нижний левый угол кнопки
		glVertex2i(width - 50, height - 3 * (height / 10)); // нижний правый угол кнопки
		glVertex2i(width - 50, height - 2 * (height / 10) - 20); // верхний правый угол кнопки
	}
	glEnd();
	string name = "print matrix"; // имя кнопки
	glRasterPos2i(width - 160, 0.73 * height); // определение позиции для текста на кнопке
	for (int i = 0; i < name.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, name[i]);  // рисовка текста на кнопке
}
void drawButton3() { // отрисовка 3 кнопки
	if (buttonBacklight == 3) { // проверка состояния подсветки кнопки
		glColor3f(245.0f / 255.0f, 222.0f / 255.0f, 179.0f / 255.0f); // установка цвета подсветки
	}
	else {
		glColor3f(0.9, 0.8, 0.9); // установка цвета кнопки
	}
	glBegin(GL_QUADS); { // рисовка кнопки
		glVertex2i(width - width / 6, height - 3 * (height / 10) - 20); // верхний левый угол кнопки
		glVertex2i(width - width / 6, height - 4 * (height / 10)); // нижний левый угол кнопки
		glVertex2i(width - 50, height - 4 * (height / 10)); // нижний правый угол кнопки
		glVertex2i(width - 50, height - 3 * (height / 10) - 20); // верхний правый угол кнопки
	}
	glEnd();
	glColor3f(0.0f, 0.0f, 0.0f); // установка цвета для границ кнопки
	glBegin(GL_LINE_LOOP); { // граница вокруг кнопки
		glVertex2i(width - width / 6, height - 3 * (height / 10) - 20);  // верхний левый угол кнопки
		glVertex2i(width - width / 6, height - 4 * (height / 10)); // нижний левый угол кнопки
		glVertex2i(width - 50, height - 4 * (height / 10)); // нижний правый угол кнопки
		glVertex2i(width - 50, height - 3 * (height / 10) - 20); // верхний правый угол кнопки
	}
	glEnd();
	string name = "add vertex"; // имя кнопки
	glRasterPos2i(width - 160, 0.63 * height); // определение позиции для текста на кнопке
	for (int i = 0; i < name.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, name[i]); // рисовка текста на кнопке

}
void drawButton4() { // отрисовка 4 кнопки
	if (buttonBacklight == 4) { // проверка состояния подсветки кнопки
		glColor3f(245.0f / 255.0f, 222.0f / 255.0f, 179.0f / 255.0f); // установка цвета подсветки
	}
	else {
		glColor3f(0.9, 0.8, 0.9); // установка цвета кнопки
	}
	glBegin(GL_QUADS); { // рисовка кнопки
		glVertex2i(width - width / 6, height - 4 * (height / 10) - 20); // верхний левый угол кнопки
		glVertex2i(width - width / 6, height - 5 * (height / 10)); // нижний левый угол кнопки
		glVertex2i(width - 50, height - 5 * (height / 10)); // нижний правый угол кнопки
		glVertex2i(width - 50, height - 4 * (height / 10) - 20); // верхний правый угол кнопки
	}
	glEnd();
	glColor3f(0.0f, 0.0f, 0.0f); // установка цвета для границ кнопки
	glBegin(GL_LINE_LOOP); { // граница вокруг кнопки
		glVertex2i(width - width / 6, height - 4 * (height / 10) - 20);  // верхний левый угол кнопки
		glVertex2i(width - width / 6, height - 5 * (height / 10)); // нижний левый угол кнопки
		glVertex2i(width - 50, height - 5 * (height / 10)); // нижний правый угол кнопки
		glVertex2i(width - 50, height - 4 * (height / 10) - 20); // верхний правый угол кнопки
	}
	glEnd();
	string name = "delete vertex"; // имя кнопки
	glRasterPos2i(width - 163, 0.53 * height); // определение позиции для текста на кнопке
	for (int i = 0; i < name.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, name[i]); // рисовка текста на кнопке
}
void drawButton5() { // отрисовка 5 кнопки
	if (buttonBacklight == 5) { // проверка состояния подсветки кнопки
		glColor3f(245.0f / 255.0f, 222.0f / 255.0f, 179.0f / 255.0f); // установка цвета подсветки
	}
	else {
		glColor3f(0.9, 0.8, 0.9); // установка цвета кнопки
	}
	glBegin(GL_QUADS); { // рисовка кнопки
		glVertex2i(width - width / 6, height - 5 * (height / 10) - 20); // верхний левый угол кнопки
		glVertex2i(width - width / 6, height - 6 * (height / 10)); // нижний левый угол кнопки
		glVertex2i(width - 50, height - 6 * (height / 10)); // нижний правый угол кнопки
		glVertex2i(width - 50, height - 5 * (height / 10) - 20); // верхний правый угол кнопки
	}
	glEnd();
	glColor3f(0.0f, 0.0f, 0.0f); // установка цвета для границ кнопки
	glBegin(GL_LINE_LOOP); { // граница вокруг кнопки
		glVertex2i(width - width / 6, height - 5 * (height / 10) - 20);  // верхний левый угол кнопки
		glVertex2i(width - width / 6, height - 6 * (height / 10)); // нижний левый угол кнопки
		glVertex2i(width - 50, height - 6 * (height / 10)); // нижний правый угол кнопки
		glVertex2i(width - 50, height - 5 * (height / 10) - 20); // верхний правый угол кнопки
	}
	glEnd();
	string name = "add edge"; // имя кнопки
	glRasterPos2i(width - 160, 0.43 * height); // определение позиции для текста на кнопке
	for (int i = 0; i < name.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, name[i]); // рисовка текста на кнопке
}
void drawButton6() { // отрисовка 6 кнопки
	if (buttonBacklight == 6) { // проверка состояния подсветки кнопки
		glColor3f(245.0f / 255.0f, 222.0f / 255.0f, 179.0f / 255.0f); // установка цвета подсветки
	}
	else {
		glColor3f(0.9, 0.8, 0.9); // установка цвета кнопки
	}
	glBegin(GL_QUADS); { // рисовка кнопки
		glVertex2i(width - width / 6, height - 6 * (height / 10) - 20); // верхний левый угол кнопки
		glVertex2i(width - width / 6, height - 7 * (height / 10)); // нижний левый угол кнопки
		glVertex2i(width - 50, height - 7 * (height / 10)); // нижний правый угол кнопки
		glVertex2i(width - 50, height - 6 * (height / 10) - 20); // верхний правый угол кнопки
	}
	glEnd();
	glColor3f(0.0f, 0.0f, 0.0f); // установка цвета для границ кнопки
	glBegin(GL_LINE_LOOP); { // граница вокруг кнопки
		glVertex2i(width - width / 6, height - 6 * (height / 10) - 20);  // верхний левый угол кнопки
		glVertex2i(width - width / 6, height - 7 * (height / 10)); // нижний левый угол кнопки
		glVertex2i(width - 50, height - 7 * (height / 10)); // нижний правый угол кнопки
		glVertex2i(width - 50, height - 6 * (height / 10) - 20); // верхний правый угол кнопки
	}
	glEnd();
	string name = "delete edge"; // имя кнопки
	glRasterPos2i(width - 160, 0.33 * height); // определение позиции для текста на кнопке
	for (int i = 0; i < name.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, name[i]); // рисовка текста на кнопке
}

void hoverCheckButton(int x, int y) { // проверка, курсор находится на кнопке или нет
	if (x > (width - width / 6) && x < (width - 50) && y >(height - 2 * (height / 10)) && y < (height - (height / 10) - 20)) {
		buttonBacklight = 1; // если курсор находится над первой кнопкой, то подсветка кнопки устанавливается в значение 1
	}
	else if (x > (width - width / 6) && x < (width - 50) && y >(height - 3 * (height / 10)) && y < (height - 2 * (height / 10) - 20)) {
		buttonBacklight = 2; // если курсор находится над второй кнопкой, то подсветка кнопки устанавливается в значение 2
	}
	else if (x > (width - width / 6) && x < (width - 50) && y >(height - 4 * (height / 10)) && y < (height - 3 * (height / 10) - 20)) {
		buttonBacklight = 3; // Если курсор находится над третьей кнопкой, то подсветка кнопки устанавливается в значение 3
	}
	else if (x > (width - width / 6) && x < (width - 50) && y >(height - 5 * (height / 10)) && y < (height - 4 * (height / 10) - 20)) {
		buttonBacklight = 4; // если курсор находится над четвёртой кнопкой, то подсветка кнопки устанавливается в значение 4
	}
	else if (x > (width - width / 6) && x < (width - 50) && y >(height - 6 * (height / 10)) && y < (height - 5 * (height / 10) - 20)) {
		buttonBacklight = 5; // если курсор находится над пятой кнопкой, то подсветка кнопки устанавливается в значение 5
	}
	else if (x > (width - width / 6) && x < (width - 50) && y >(height - 7 * (height / 10)) && y < (height - 6 * (height / 10) - 20)) {
		buttonBacklight = 6; // если курсор находится над шестой кнопкой, то подсветка кнопки устанавливается в значение 6
	}
	else {
		buttonBacklight = 0; // если курсор не находится ни над одной из кнопок, то подсветка кнопки устанавливается в значение 0
	}
}

void mouseMove(int x, int y) { // перемещение мыши по экрану
	y = height - y; // переворот оси Y для корректного отображения
	hoverCheckButton(x, y); // проверка на какой кнопкой находится курсор
	glutPostRedisplay(); // обновление отображения окна
}

void mouseClick(int button, int state, int x, int y) { // действия при нажатии на кнопки
	if (x > (width - width / 6) && x < (width - 50) && y > 93 && y < 150) { // подходят ли текущие координаты под кнопку 1
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) { // нажата ли кнопка
			newIndexes.clear(); // очищение вектора
			indexes.clear(); // очищение вектора
			cout << ": " << endl;
			int** matrix = modificaMatrix(); // получение редуцированной матрицы
			bool checker = checkData(matrix); // проверка, подходят ли данные
			if (!checker) {
				cout << "Неподходящие данные для решения задачи коммивояжера!" << endl;
				return;
			}
			int n = graph.amountVertices(); // количество вершин
			while (indexes.size() < n)
				matrix = findZero(matrix); // нахождение измененной матрицы
			cout << endl;
			printAnswer(); // вывод ответа на задачу коммивояжера
			return;
		}
	}
	if (x > (width - width / 6) && x < (width - 50) && y >175 && y < 233) { // подходят ли текущие координаты под кнопку 2
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) { // нажата ли кнопка
			graph.print(); // печать матрицы смежности
			return;
		}
	}
	if (x > (width - width / 6) && x < (width - 50) && y >253 && y < 312) { // подходят ли текущие координаты под кнопку 3
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) { // нажата ли кнопка
			int cur = graph.amountVertices(); // количество вершин
			graph.insertVertex(cur + 1); // вставка вершины
			coordinates[cur].x = width / 2; // обновление координат
			coordinates[cur].y = height / 2; // обновление координат
			return;
		}
	}
	if (x > (width - width / 6) && x < (width - 50) && y > 330 && y < 390) { // подходят ли текущие координаты под кнопку 4
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) { // нажата ли кнопка
			graph.eraseVertex(); // удаление вершины
			return;
		}
	}
	if (x > (width - width / 6) && x < (width - 50) && y > 408 && y < 466) { // подходят ли текущие координаты под кнопку 5
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) { // нажата ли кнопка
			int firstVertex, secondVertex, Weight;
			cout << "Введите первую вершину для ребра: ";
			cin >> firstVertex;
			cout << "Введите вторую вершину для ребра: "; 
			cin >> secondVertex;
			cout << "Введите вес нового ребра: ";
			cin >> Weight;
			cout << endl;
			graph.insertEdge(firstVertex, secondVertex, Weight); // вставка заданного ребра
			return;
		}
	}
	if (x > 899 && x < 1030 && y <= 546 && y >= 486) { // подходят ли текущие координаты под кнопку 6
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) { // нажата ли кнопка
			int firstVertex, secondVertex;
			cout << "Введите первую вершину для ребра: "; 
			cin >> firstVertex;
			cout << "Введите вторую вершину для ребра: "; 
			cin >> secondVertex;
			cout << endl;
			graph.eraseEdge(firstVertex, secondVertex); // удаление заданного ребра
			return;
		}
	}
}

void drawTitle() { // вывод заголовка
	string title = "ELECTIVE ACTIONS"; // имя заголовка
	glRasterPos2i(900, height-60); // координаты заголовка
	for (int i = 0; i < title.length(); i++) // отрисовка по букве
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, title[i]);
}

void reshape(int w, int h) { // ресайз окна OpenGL
	width = w; // ширину нового окна
	height = h; // высоту нового окна
	glViewport(0, 0, (GLsizei)width, (GLsizei)height); // область просмотра для нового размера окна
	glMatrixMode(GL_PROJECTION); // переключение на матрицу проекции
	glLoadIdentity(); // очистка текущей матрицы
	gluOrtho2D(0, (GLdouble)width, 0, (GLdouble)height); // определение проекции с центром в начале координат и размерами окна
	glutPostRedisplay(); // обновление отображения окна
}

void display() { // основной цикл отрисовки
	glMatrixMode(GL_PROJECTION); // переключение на матрицу проекции
	glLoadIdentity(); // очистка текущей матрицы
	gluOrtho2D(0, width, 0, height); // определение проекции с центром в начале координат и размерами окна
	glViewport(0, 0, width, height); // область просмотра для текущего размера окна
	glClearColor(1.0, 0.8, 0.8, 0.8); // цвет фона
	glClear(GL_COLOR_BUFFER_BIT); // очистка экрана
	drawTitle(); // рисовка заголовка
	drawButton1(); // рисовка первой кнопки
	drawButton2(); // рисовка второй кнопки
	drawButton3(); // рисовка третьей кнопки
	drawButton4(); // рисовка четвертой кнопки
	drawButton5(); // рисовка пятой кнопки
	drawButton6(); // рисовка шестой кнопки
	graph.drawGraph(); // рисовка графика
	glutSwapBuffers(); // смена буферов
}