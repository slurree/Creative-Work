#include "Graph.h" // подключение файла с определением структуры данных 
using namespace std; // разрешает использование пространства имен стандартной библиотеки 

Graph::Graph() { // конструктор		                      
	for (int i = 0; i < maxSize; i++) { // цикл для  перебора ребер
		for (int j = 0; j < maxSize; j++) { // цикл для  перебора ребер
			adjMatrix[i][j] = 0; // по умолчанию ребра заполняются 0
		}
	}
}

Graph::~Graph() // деструктор
{ }

int Graph::vertexPosition(const int& vertex) { // нахождение позиции вершины в векторе вершин
	for (size_t i = 0; i < vertList.size(); i++) { // перебор всех вершин
		if (vertList[i] == vertex) // поиск индекса нужной вершины в векторе
			return i;
	}
	return -1;
}

bool Graph::checkEmpty() { // функция проверки, пуст ли граф
	if (vertList.size() != 0) // если элементов в векторе не 0
		return false;
	else
		return true;
}

bool Graph::checkFull() { // функция проверки, полон ли граф
	return (vertList.size() == maxSize); // если элементов в векторе не больше чем максимальный размер
}

void Graph::insertVertex(const int& vertex) { // добавление вершины к графу
	if (!checkFull()) // проверка, полон ли граф
		vertList.push_back(vertex); // добавление вершины в вектор
	else {
		cout << "Достигнуто максимальное количество вершин! " << endl << endl;
		return;
	}
}

void Graph::insertEdge(const int& vertex1, const int& vertex2, int weight) { // вставка нового ребра
	if (weight < 1) { // проверка веса
		cout << "Вес не может быть дробным или отрицательным значением!" << endl;
		return;
	}
	if (vertexPosition(vertex1) != (-1) && vertexPosition(vertex2) != (-1)) { // проверка существуют ли заданные вершины 
		int index = vertexPosition(vertex1);	// индекс первой заданной вершины
		int index2 = vertexPosition(vertex2); // индекс второй заданной вершины
		if (adjMatrix[index][index2] != 0 && adjMatrix[index2][index] != 0) { // проверка, есть ли уже такое ребро
			cout << "Такое ребро уже существует!" << endl;
			return;
		}
		else {
			adjMatrix[index][index2] = weight; // установка веса ребра
			adjMatrix[index2][index] = weight; // установка веса ребра
		}
	}
	else {
		cout << "Заданных вершин не существует! " << endl;
		return;
	}
}

void Graph::print() { // функция печати матрицы смежности
	if (!checkEmpty()) { // проверка, не пуст ли граф
		cout << "Матрица смежности: " << endl;
		cout << "    ";
		for (int i = 0; i < vertList.size(); ++i) { // обозначение вершин
			cout << vertList[i] << "   ";
		}
		cout << endl;
		for (int i = 0; i < vertList.size(); ++i) { // обозначение вершин
			cout << vertList[i] << "   ";
			for (int j = 0; j < vertList.size(); ++j) { // перебор для вывода веса ребер
				cout << adjMatrix[i][j] << "   ";
			}
			cout << endl << endl;
		}
	}
	else
		cout << "Граф пуст!" << endl << endl;
}

void Graph::eraseVertex() { // функция удаления ребра
	if (checkEmpty()) { // проверка на пустоту графа
		cout << "Граф пуст!" << endl;
		return;
	}
	int n = vertList.size(); // получение размера списка вершин
	for (int j = 0; j < n; j++) { // удаление ребер, ведущих к удаляемой вершине
		adjMatrix[n - 1][j] = 0; // обнуление элемента матрицы смежности для удаляемой вершины
		adjMatrix[j][n - 1] = 0; // обнуление элемента матрицы смежности для всех остальных вершин
	}
	vertList.pop_back(); // удаление вершины из списка вершин
}


void Graph::eraseEdge(const int& vertex1, const int& vertex2) { // функция удаления ребра
	if (vertexPosition(vertex1) != (-1) && vertexPosition(vertex2) != (-1)) { // проверка, существуют ли обе вершины в графе
		int position1 = vertexPosition(vertex1); // индекс первой вершины
		int position2 = vertexPosition(vertex2); // индекс первой вершины
		if (adjMatrix[position1][position2] == 0) {  // проверка, уществует ли ребро между вершинами
			cout << "Такого ребра не существует!" << endl;
			return;
		}
		else {
			adjMatrix[position1][position2] = 0; // обновление данных
			adjMatrix[position2][position1] = 0; // обновление данных
		}
	}
	else { // если заданных вершин не существует
		cout << "Такой вершины(вершин) не существует! " << endl;
		return;
	}
}