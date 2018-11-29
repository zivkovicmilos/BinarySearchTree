#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct bstNode {

	int key;
	bstNode *left = nullptr;
	bstNode *right = nullptr;
	bstNode *parent = nullptr;

	bstNode() {
		this->key = NULL;
	}

	bstNode(int key) {
		this->key = key;
	}
};

struct bstTree {

	int height;
	bstNode* root;

	bstTree(bstNode* root) {
		this->root = root;
		height = -1;
	}

	bstTree() {
		this->root = nullptr;
		height = -1;
	}
	
};

void inorder(bstTree* tree) {

	stack <bstNode*> S;
	if (!tree->root) {
		cout << "BST does not exist" << endl;
		return;
	}
	bstNode* next = tree->root;
		
	do {

			while (next) {
				S.push(next);
				next = next->left;
			}
			if (!S.empty()) {
				next = S.top();
				S.pop();
				cout << next->key << " ";
				next = next->right;
			}
			else {
				cout << endl;
				return;
			}

		} while (true);
}

void levelorder(bstTree* tree) {

	if (!tree->root) {
		cout << "BST doesn't exist" << endl;
		return;
	}

	bstNode* next = tree->root;
	queue <bstNode*> Q;

	Q.push(next);

	while (!Q.empty()) {

		int nodeNum = Q.size();

		while (nodeNum > 0)
		{
			next = Q.front();
			Q.pop();
			cout << next->key << " ";
			if (next->left) {
				Q.push(next->left);
			}
			if (next->right) {
				Q.push(next->right);
			}
			nodeNum--;
		}
		cout << endl;
	}
}

void deleteTree(bstTree** tree) {

	stack <bstNode*> S;
	bstNode* next = (*tree)->root;

	while (next) {
		S.push(next);
		next = next->left;
	}

	while (!S.empty()) {
		next = S.top();
		S.pop();
		if (next->key > 0) {
			next->key = -next->key;
			S.push(next);
			next = next->right;
			while (next) {
				S.push(next);
				next = next->left;
			}
		}
		else {
			next->key = -next->key;
			delete next;
		}
	}
	(*tree)->root = nullptr;
	(*tree)->height = -1;

}

bstNode* bstFind(bstTree* tree, int key) {

	bstNode* temp = tree->root;

	while ((temp != nullptr) && (temp->key != key)) {
		if (key < temp->key) {
			temp = temp->left;
		}
		else if (key > temp->key) {
			temp = temp->right;
		} 
		else {
			return temp;
		}
	}

	return temp;
}

bool isFound(bstNode* node) {

	if (node) {
		return true;
	}
	else {
		return false;
	}
}

void deleteNode(bstTree** t, int key) {

	bstNode* temp = (*t)->root;
	bstNode* h1, *h2, *h3;
	h1 = h2 = h3 = nullptr;

	while (temp && key != temp->key) {
		
		if (key < temp->key) {
			temp = temp->left;
		}
		else {
			temp = temp->right;
		}

	}

	if (!temp) {
		cout << "\nKey not found" << endl;
	}

	if (!temp->left) {
		h1 = temp->right;
	} 
	else if (!temp->right) {
		h1 = temp->left;
	}
	else {
		h2 = temp;
		h1 = temp->right;
		h3 = temp->left;

		while (!h3) {
			h2 = h1;
			h1 = h3;
			h3 = h1->left;
		}

		if (h2 != temp) {
			h2->left = h1->right;
			h1->right = temp->right;
		}
		h1->left = temp->left;

	}

	if (!temp->parent) {
		(*t)->root = h1;
	}
	else if (temp == temp->parent->left) {
		temp->parent->left = h1;
	}
	else {
		temp->parent->right = h1;
	}

	delete temp;
	(*t)->height--;
}

bstNode* findMin(bstNode *n) {
	bstNode* temp = n;
	
	while (temp->left) {
		temp = temp->left;
	}

	return temp;
}

bstNode* nextNode(bstNode* n) {
	bstNode* temp = n;
	bstNode* prev;

	if (temp->right) {
		return findMin(temp->right);
	}
	else {
		prev = temp->parent;
		while ((temp == prev->right) && (prev != nullptr)) {
			temp = prev;
			prev = prev->parent;
		}
		return prev;
	}
}

void instBst(bstTree ** t, int key) {

	bstNode * temp = (*t)->root;
	bstNode * prev = nullptr;

	while (temp != nullptr) {
		prev = temp;

		if (key == temp->key) {
			bstNode* oldS = nextNode(temp);
			bstNode* n = new bstNode(key);
			n->right = oldS;
			n->left = oldS->left;

			if (oldS->parent->left == oldS) {
				oldS->parent->left = n;
			}
			else {
				oldS->parent->right = n;
			}

			n->parent = oldS->parent;
			oldS->parent = n;
			oldS->left = nullptr;

			(*t)->height++;
			cout << "\nKey already exists, but it was added as a successor this time" << endl;
			return;
		}
		else if (key < temp->key) {
			temp = temp->left;
		}
		else {
			temp = temp->right;
		}
	}


	if (!prev) {
		(*t)->root = new bstNode(key);
		(*t)->root->parent = nullptr;
		(*t)->height++;
	}
	else {
		if (key < prev->key) {
			prev->left = new bstNode(key);
			prev->left->parent = prev;
			(*t)->height++;
		}
		else {
			prev->right = new bstNode(key);
			prev->right->parent = prev;
			(*t)->height++;
		}
	}
}

bstNode* findNextMin(bstNode *n) {
	bstNode* temp = n;

	bstNode* minKey = findMin(n);

	temp = nextNode(minKey);
	return temp;
}

void menu() {
	cout << endl;
	cout << "\n  * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "  *            Main Menu              *" << endl;
	cout << "  * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "  *                                   *" << endl;
	cout << "  * 1. Form BST                       *" << endl;
	cout << "  * 2. Add to BST                     *" << endl;
	cout << "  * 3. Search BST                     *" << endl;
	cout << "  * 4. Find second smallest key       *" << endl;
	cout << "  * 5. Print BST                      *" << endl;
	cout << "  * 6. Delete a key                   *" << endl;
	cout << "  * 7. Delete BST                     *" << endl;
	cout << "  * 8. Stop                           *" << endl;
	cout << "  *                                   *" << endl;
	cout << "  * * * * * * * * * * * * * * * * * * *" << endl;
	cout << endl;
}


int main(void) {

	int odg = 0;
	bstNode* rootPtr = nullptr;
	bstTree* t = nullptr;

	do {
		menu();
		cout << "> ";
		cin >> odg;
		switch (odg) {
		case 1: 
			cout << "BST formed";
			t = new bstTree(rootPtr);
			break;
		case 2:
			int keyNum;
			int key;
			cout << "\nNumber of keys to add?\n";
			cout << "> ";
			cin >> keyNum;
			cout << "\nEnter the data: ";
			for (int i = 0; i < keyNum; i++) {
				cin >> key;
				instBst(&t, key);
			}
			break;
		case 3: 
			if (!t->root) {
				cout << "\nTree is empty" << endl;
				break;
			}
			int keyF;
			cout << "\nFind the key\n";
			cout << "> ";
			cin >> keyF;
			if (isFound(bstFind(t, keyF))) {
				cout << "Key found" << endl;
			}
			else {
				cout << "Key not found" << endl;
			}
			break;
		case 4:
			if (!t->root) {
				cout << "\nTree is empty" << endl;
				break;
			}
			cout << findNextMin(t->root)->key << endl;;
			break;
		case 5:
			int odg;
			cout << "Print tree: " << endl;
			cout << "1. Inorder" << endl;
			cout << "2. Levelorder" << endl;
			cin >> odg;
			if (odg == 1) {
				inorder(t);
			}
			else if (odg==2) {
				levelorder(t);
			}
			break;
		case 6:
			if (!t->root) {
				cout << "\nTree is empty" << endl;
				break;
			}
			int keyDel;
			cout << "Key to delete\n";
			cout << "> ";
			cin >> keyDel;
			deleteNode(&t, keyDel);
			break;
		case 7: 
			if (!t->root) {
				cout << "\nTree doesn't exist" << endl;
				break;
			}
			deleteTree(&t);
			cout << "BST deleted";
			break;
		case 8:
			return 0;
		}
	
	} while (true);
}