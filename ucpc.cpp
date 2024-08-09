// BST 구현
// 문제를 단순화하기 위해, 키만 존재하고 원소를 키라 가정
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	int key;
	struct NODE* parent;
	struct NODE* lChild;
	struct NODE* rChild;
} NODE;

NODE* g_root;

NODE* createNode(int key, NODE* parent);
int findKey(int key);  // 트리에서 키를 저장한 노드를 찾아 키를 반환하는 함수
void insertKey(int key);
NODE* treeSearch(int key);	// 트리에서 키를 저장한 내부 노드를 반환하는 함수, 혹은 그런 노드가 없다면 삽입될 위치의 외부 노드를 반환
int removeNode(int key);
int isExternal(NODE* node);
int isInternal(NODE* node);
NODE* getSibling(NODE* node);
NODE* inorderSucc(NODE* node);			// 중위순회 계승자를 반환하는 함수
void reduceExternal(NODE* removeNode);	// 외부 노드를 제거하고 트리를 재구성하는 함수
void printPreorder(NODE* node);

int main() {
	char cmd;
	int key;
	int res;

	// 초기화: 외부 노드만 있는 빈 트리 생성
	g_root = createNode(0, NULL);
	while (1) {
		scanf(" %c", &cmd);
		if (cmd == 'i') {  // insert
			scanf(" %d", &key);
			insertKey(key);
		} else if (cmd == 'd') {  // delete
			scanf(" %d", &key);
			res = removeNode(key);
			printf("%d\n", res == -1 ? 'X' : res);	// 키가 존재하지 않으면 X 출력
		} else if (cmd == 's') {					// search
			scanf(" %d", &key);
			res = findKey(key);
			printf("%d\n", res == -1 ? 'X' : res);	// 키가 존재하지 않으면 X 출력
		} else if (cmd == 'p') {					// print
			printPreorder(g_root);
			printf("\n");
		} else if (cmd == 'q') {  // quit
			break;
		}
	}

	return 0;
}

NODE* createNode(int key, NODE* parent) {
	NODE* newNode = (NODE*)malloc(1 * sizeof(NODE));
	newNode->key = key;
	newNode->lChild = NULL;
	newNode->rChild = NULL;
	newNode->parent = parent;
	return newNode;
}

// 트리에서 키를 저장한 노드를 찾아 키를 반환하는 함수
int findKey(int key) {
	NODE* node = treeSearch(key);
	if (isExternal(node)) {
		return -1;	// 키가 존재하지 않으면 -1 반환
	} else {
		return node->key;
	}
}

void insertKey(int key) {
	NODE* node = treeSearch(key);
	if (!isExternal(node)) return;	// 이미 존재하면 삽입 안함

	node->key = key;
	node->lChild = createNode(0, node);
	node->rChild = createNode(0, node);
}

// 트리에서 키를 저장한 내부 노드를 반환하는 함수, 혹은 그런 노드가 없다면 삽입될 위치의 외부 노드를 반환
NODE* treeSearch(int key) {
	NODE* node = g_root;
	while (!isExternal(node)) {
		if (key == node->key)
			return node;  // 키를 찾으면 노드 반환
		else if (key < node->key)
			node = node->lChild;  // 키가 작으면 왼쪽으로 이동
		else
			node = node->rChild;  // 키가 크면 오른쪽으로 이동
	}
	return node;  // 삽입될 위치의 외부 노드 반환
}

int removeNode(int key) {
	NODE* node = treeSearch(key);
	if (isExternal(node)) return -1;  // 존재하지 않으면 -1 반환

	NODE* removeNode;
	if (isExternal(node->lChild))  // 왼쪽 자식이 외부 노드인 경우
		removeNode = node->lChild;
	else if (isExternal(node->rChild))	// 오른쪽 자식이 외부 노드인 경우
		removeNode = node->rChild;
	else {
		NODE* successorNode = inorderSucc(node);  // 두 자식이 모두 내부 노드인 경우
		node->key = successorNode->key;			  // 중위 순회 후계자의 키를 복사
		removeNode = successorNode->lChild;		  // successorNode의 왼쪽 자식을 removeNode로 설정
	}

	reduceExternal(removeNode);	 // 외부 노드를 제거하고 트리를 재구성
	return key;
}

int isExternal(NODE* node) {
	return (node->lChild == NULL && node->rChild == NULL);
}

int isInternal(NODE* node) {
	return (node->lChild != NULL || node->rChild != NULL);
}

NODE* getSibling(NODE* node) {
	if (node->parent == NULL) return NULL;

	if (node == node->parent->lChild)
		return node->parent->rChild;  // 왼쪽 자식인 경우 오른쪽 형제 반환
	else
		return node->parent->lChild;  // 오른쪽 자식인 경우 왼쪽 형제 반환
}

// 중위순회 계승자
NODE* inorderSucc(NODE* node) {
	NODE* nextNode = node->rChild;
	while (isInternal(nextNode->lChild)) {
		nextNode = nextNode->lChild;  // 왼쪽 자식으로 계속 이동
	}
	return nextNode;
}

// 외부 노드를 제거하고 트리를 재구성하는 함수
void reduceExternal(NODE* externalNode) {
	NODE* parentNode = externalNode->parent;
	NODE* siblingNode = getSibling(externalNode);
	if (parentNode == g_root) {
		g_root = siblingNode;
		siblingNode->parent = NULL;
	} else {
		NODE* grandparentNode = parentNode->parent;
		siblingNode->parent = grandparentNode;
		if (parentNode == grandparentNode->lChild)
			grandparentNode->lChild = siblingNode;	// parentNode가 왼쪽 자식인 경우
		else
			grandparentNode->rChild = siblingNode;	// parentNode가 오른쪽 자식인 경우
	}

	free(externalNode);
	free(parentNode);
}

void printPreorder(NODE* node) {
	if (isExternal(node)) return;

	printf(" %d", node->key);	  // 노드 출력
	printPreorder(node->lChild);  // 왼쪽 자식으로 이동
	printPreorder(node->rChild);  // 오른쪽 자식으로 이동
}

/*
i 9
i 2
i 15
i 1
i 7
i 11
i 5
i 8
i 3
i 4
p
*/
