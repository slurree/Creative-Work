#include "Graph.h" // ����������� ����� � ������������ ��������� ������ 
using namespace std; // ��������� ������������� ������������ ���� ����������� ���������� 

Graph::Graph() { // �����������		                      
	for (int i = 0; i < maxSize; i++) { // ���� ���  �������� �����
		for (int j = 0; j < maxSize; j++) { // ���� ���  �������� �����
			adjMatrix[i][j] = 0; // �� ��������� ����� ����������� 0
		}
	}
}

Graph::~Graph() // ����������
{ }

int Graph::vertexPosition(const int& vertex) { // ���������� ������� ������� � ������� ������
	for (size_t i = 0; i < vertList.size(); i++) { // ������� ���� ������
		if (vertList[i] == vertex) // ����� ������� ������ ������� � �������
			return i;
	}
	return -1;
}

bool Graph::checkEmpty() { // ������� ��������, ���� �� ����
	if (vertList.size() != 0) // ���� ��������� � ������� �� 0
		return false;
	else
		return true;
}

bool Graph::checkFull() { // ������� ��������, ����� �� ����
	return (vertList.size() == maxSize); // ���� ��������� � ������� �� ������ ��� ������������ ������
}

void Graph::insertVertex(const int& vertex) { // ���������� ������� � �����
	if (!checkFull()) // ��������, ����� �� ����
		vertList.push_back(vertex); // ���������� ������� � ������
	else {
		cout << "���������� ������������ ���������� ������! " << endl << endl;
		return;
	}
}

void Graph::insertEdge(const int& vertex1, const int& vertex2, int weight) { // ������� ������ �����
	if (weight < 1) { // �������� ����
		cout << "��� �� ����� ���� ������� ��� ������������� ���������!" << endl;
		return;
	}
	if (vertexPosition(vertex1) != (-1) && vertexPosition(vertex2) != (-1)) { // �������� ���������� �� �������� ������� 
		int index = vertexPosition(vertex1);	// ������ ������ �������� �������
		int index2 = vertexPosition(vertex2); // ������ ������ �������� �������
		if (adjMatrix[index][index2] != 0 && adjMatrix[index2][index] != 0) { // ��������, ���� �� ��� ����� �����
			cout << "����� ����� ��� ����������!" << endl;
			return;
		}
		else {
			adjMatrix[index][index2] = weight; // ��������� ���� �����
			adjMatrix[index2][index] = weight; // ��������� ���� �����
		}
	}
	else {
		cout << "�������� ������ �� ����������! " << endl;
		return;
	}
}

void Graph::print() { // ������� ������ ������� ���������
	if (!checkEmpty()) { // ��������, �� ���� �� ����
		cout << "������� ���������: " << endl;
		cout << "    ";
		for (int i = 0; i < vertList.size(); ++i) { // ����������� ������
			cout << vertList[i] << "   ";
		}
		cout << endl;
		for (int i = 0; i < vertList.size(); ++i) { // ����������� ������
			cout << vertList[i] << "   ";
			for (int j = 0; j < vertList.size(); ++j) { // ������� ��� ������ ���� �����
				cout << adjMatrix[i][j] << "   ";
			}
			cout << endl << endl;
		}
	}
	else
		cout << "���� ����!" << endl << endl;
}

void Graph::eraseVertex() { // ������� �������� �����
	if (checkEmpty()) { // �������� �� ������� �����
		cout << "���� ����!" << endl;
		return;
	}
	int n = vertList.size(); // ��������� ������� ������ ������
	for (int j = 0; j < n; j++) { // �������� �����, ������� � ��������� �������
		adjMatrix[n - 1][j] = 0; // ��������� �������� ������� ��������� ��� ��������� �������
		adjMatrix[j][n - 1] = 0; // ��������� �������� ������� ��������� ��� ���� ��������� ������
	}
	vertList.pop_back(); // �������� ������� �� ������ ������
}


void Graph::eraseEdge(const int& vertex1, const int& vertex2) { // ������� �������� �����
	if (vertexPosition(vertex1) != (-1) && vertexPosition(vertex2) != (-1)) { // ��������, ���������� �� ��� ������� � �����
		int position1 = vertexPosition(vertex1); // ������ ������ �������
		int position2 = vertexPosition(vertex2); // ������ ������ �������
		if (adjMatrix[position1][position2] == 0) {  // ��������, ��������� �� ����� ����� ���������
			cout << "������ ����� �� ����������!" << endl;
			return;
		}
		else {
			adjMatrix[position1][position2] = 0; // ���������� ������
			adjMatrix[position2][position1] = 0; // ���������� ������
		}
	}
	else { // ���� �������� ������ �� ����������
		cout << "����� �������(������) �� ����������! " << endl;
		return;
	}
}