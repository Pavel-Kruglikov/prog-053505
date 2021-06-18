// ConsoleApplication12.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_SIZE 256

typedef struct node {
	struct node* left;
	struct node* right;
	char data;
} Node;

typedef struct tree {
	Node* root;
	int length;
} Tree;

Node* addElement(char data, Node* node, Tree* tree) {
	if (node == NULL) {
		node = (Node*)malloc(sizeof(Node));
		node->data = data;
		node->left = NULL;
		node->right = NULL;
		if (!tree->length) {
			tree->root = node;
		}
		tree->length++;
	}
	else {
		if (data > node->data) {
			node->right = addElement(data, node->right, tree);
		}
		else {
			node->left = addElement(data, node->left, tree);
		}
	}
	return node;
}

int countLeafs(Node* node) {
	if (node != NULL) {
		if ((node->left == NULL) && (node->right == NULL)) {
			return 1;
		}
		else {
			return
				countLeafs(node->left) +
				countLeafs(node->right);
		}
	}
}

void printNLR(Node* node) {
	if (node != NULL) {
		printf("%c\n", node->data);
		printNLR(node->left);
		printNLR(node->right);
	}
}

Node* clearTree(Node* node, Tree* tree) {
	if (node != NULL) {
		clearTree(node->left, tree);
		clearTree(node->right, tree);
		printf("deleted=%c\n", node->data);
		free(node);
		tree->length--;
	}
}

int main() {
	char text[MAX_TEXT_SIZE];

	printf("Type your string:\n");
	fgets(text, MAX_TEXT_SIZE, stdin);
	Tree tree;
	tree.length = 0;
	tree.root = NULL;
	for (int i = 0; i < strlen(text) - 1; i++) {
		if (text[i] != ' ') {
			addElement(text[i], tree.root, &tree);
		}
	}
	printf("Tree direct trace:\n");
	printNLR(tree.root);
	printf("Leafs count=%d\n", countLeafs(tree.root));
	clearTree(tree.root, &tree);// Clear tree

	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
