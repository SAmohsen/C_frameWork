#include "tree.h"

static int stackArr[STACKSIZE];
static int top = -1;
static int queue[QUEUESIZE];
static int rear = -1;
static int front = -1;

/* stack impelementation*/
static int fullstack() {
	if (top == (STACKSIZE - 1)) {
		return 1;
	}
	return 0;
}

static int emptystack() {
	if (top == -1) {
		return 1;
	}
	return 0;
}

static void push(int data) {
	if (!fullstack()) {
		top++;
		stackArr[top] = data;
	}
}

static int pop() {
	int data;
	if (!emptystack()) {
		data = stackArr[top];
		top--;
		return data;
	}
	return 0;
}

static int fullqueue() {
	if (((rear + 1) % QUEUESIZE) == front) {
		return 1;
	} else
		return 0;
}

static int emptyqueue() {

	if (rear == front) {
		return 1;
	} else
		return 0;

}

static void enqueue(int data) {
	if (!fullqueue()) {
		rear = (rear + 1) % QUEUESIZE;
		queue[rear] = data;
	}
}

static int dequeue() {
	if (!emptyqueue()) {
		front = (front + 1) % QUEUESIZE;
		int data = queue[front];
		return data;
	}
	return -1;
}
/*breadth first search : visit node in levels  */
void breadthFristSearch(struct treenode *treeArray, int size) {

	int i;
	/*finding root tree node to start traversal: node that has no parents  */
	for (i = 0; i < size; i++) {
		if (treeArray[i].father == '0') {
			enqueue(treeArray[i].name);
			break;
		}
	}

	char parent;
	char sons[size];/* worst case that rot has all sons */
	/*traversal until queue is empty */
	while (!emptyqueue()) {
		parent = dequeue();
		printf("%c ", parent);
		int sonsNum = 0;
		for (i = 0; i < 12; i++) {
			if (treeArray[i].father == parent) {
				sons[treeArray[i].order] = treeArray[i].name;
				sonsNum++;
			}
		}

		for (i = 1; i <= sonsNum; i++) {
			enqueue(sons[i]);
		}

	}

}

/*depth first search : visit depth of nodes   */
void depthFristSearch(struct treenode *treeArray, int size) {

	int i;
	/*finding root tree node to start traversal: node that has no parents  */
	for (i = 0; i < size; i++) {
		if (treeArray[i].father == '0') {
			push(treeArray[i].name);
			break;
		}
	}
	char parent;
	char sons[size];/* worst case that rot has all sons */
	/*traversal until stack is empty */
	while (!emptystack()) {
		parent = pop();
		printf("%c ", parent);
		int sonsNum = 0;
		for (i = 0; i < 12; i++) {
			if (treeArray[i].father == parent) {
				sons[treeArray[i].order] = treeArray[i].name;
				sonsNum++;
			}
		}

		for (i = 1; i <= sonsNum; i++) {
			push(sons[i]);
		}

	}

}

/*driver code */

int treedriver() {

	struct treenode treeArray[12] = {
			{ 'A', 'M', 2 }, { 'B', 'M', 1 }, { 'C','A', 1 },
			{ 'D', 'H', 3 }, { 'F', 'H', 1 }, { 'G', 'H', 2 },
			{ 'H','M', 3 }, { 'K', 'B', 2 }, { 'M', '0', 0 },
			{ 'P', 'K', 2 }, { 'X','K', 1 }, { 'Y', 'B', 1 } };

	breadthFristSearch(treeArray, 12);
	printf("\n");
	depthFristSearch(treeArray, 12);

	return 0;
}

