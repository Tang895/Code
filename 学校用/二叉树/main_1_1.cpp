#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<Windows.h>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<set>

using namespace std;
template<class T>
class btnode {
private:
	btnode<T>* right;
	btnode<T>* left;
	int rank;
	T data;
public:
	btnode<T>() {
		right = NULL;
		left = NULL;
		rank = 0;
		T *data = new T;
	}
	btnode<T>(T data, btnode<T>* left = NULL, btnode<T>* right = NULL) {
		btnode<T>::data = data;
		btnode<T>::left = left;
		btnode<T>::right = right;
	}
	void init(T data,int rank, btnode<T>* left=NULL, btnode<T>* right=NULL) {
		btnode<T>::data = data;
		btnode<T>::left = left;
		btnode<T>::right = right;
		btnode<T>::rank = rank;
	}
	void changeleftchild(btnode<T>* left) {
		btnode<T>::left = left;
	}
	void changerightchild(btnode<T>* right) {
		btnode<T>::right = right;
	}
	btnode<T>* getright() {
		return right;
	}
	btnode<T>* getleft() {
		return left;
	}
	T getdata() {
		return data;
	}
	void changedata(T data) {
		btnode<T>::data = data;
	}
	btnode<T>* getleftchild() {
		return left;
	}
	btnode<T>* getrightchild() {
		return right;
	}
};
template<class T>
class bt {
private:
	int size;
	btnode<T>* head;
public:
	bt<T>(int len) {
		size = len;
		btnode<T>* a = new btnode<T>[len];
		head = a;
		for (int i = 0; i < len; i++) {
			T data;
			cin >> data;
			a[i].init(data,i);
		}
		for (int i = 0; i < len; i++) {
			if (2 * i + 1 > len-1){
				break;
			}
			a[i].changeleftchild(&a[2*i+1]);
			if (2 * i + 2  > len-1) {
				break;
			}
			a[i].changerightchild(&a[2*i+2]);
		}

	}
	btnode<T>* gethead() {
		return head;
	}
	int getsize() {
		return size;
	}

	void display_fun(btnode<T>* head) {
		btnode* pointer =head;//get the root node;
		if(pointer!=NULL)
		cout << pointer->getdata()<<endl;
		if(pointer->getleft()!=NULL)
		display_fun(pointer->getleft());
		if(pointer->getright()!=NULL)
		display_fun(pointer->getright());
		return;
	}
	void display() {
		display_fun(head);
		return;
	}
};
//垂直输出二叉树
template<class T>
void PrintBt(btnode<T>* root);

template<class T>
void display1(btnode<T> *root) {
	if (root->getdata() != NULL) {
		cout << root->getdata() << " ";
	}
	if (root->getleft() != NULL) {
		display1(root->getleft());
	}
	if (root->getright() != NULL) {
	    display1(root->getright());
	}
}

//快速排序,二叉树
template<class T>
void quicksort(btnode<T>*root,vector<T> numbers) {
	root->changedata(numbers[0]);
	if (numbers.size()==1)
		return;
	vector<T> left;
	vector<T> right;
	for (int i = 1; i < numbers.size(); i++) {
		if (numbers[i] >= numbers[0])
			left.push_back(numbers[i]);
		else {
			right.push_back(numbers[i]);
		}
	}
	if (!left.empty()) {
		btnode<T>* newleft = new btnode<T>;
		quicksort(newleft, left);
		root->changeleftchild(newleft);
	}
	if (!right.empty()) {
		btnode<T>* newright = new btnode<T>;
		quicksort(newright, right);
		root->changerightchild(newright);
	}
}
//快排，非递归
template<class T>
vector<T> quicksort2(vector<T> num) {
	int size = num.size();

}

//非递归，顺序转链式
template<class T>
class binarytree {
private:
	int size;
	btnode<T>* root;

public:
	binarytree() {}
	binarytree(vector<T> tree) {
		size = tree.size();
		btnode<T>* newnode = new btnode<T>[size];
		root = &newnode[0];
		for (int i = 0; i < size; i++) {
			newnode[i].changedata(tree[i]);

		}
		for (int i = 0; i < size; i++) {
			if (2 * i + 2 > size) break;
			newnode[i].changeleftchild(&newnode[2 * i + 1]);
			if (2 * i + 3 > size) break;
			newnode[i].changerightchild(&newnode[2 * i + 2]);
		}
	}
	binarytree(queue<T> tree) {
		size = tree.size();
		btnode<T>* newnode = new btnode<T>[size];
		root = &newnode[0];
		for (int i = 0; i < size; i++) {
			newnode[i].changedata(tree.front());
			tree.pop();
			
		}
		for (int i = 0; i < size; i++) {
			if (2 * i + 1 > size - 1)
				break;
			newnode[i].changeleftchild(&newnode[2 * i + 1]);
			if (2 * i + 2 > size - 1)
				break;
			newnode[i].changerightchild(&newnode[2*i+2]);
		}
	}
	
	void display() {
		display1(root);
	}
	btnode<T>* getroot() {
		return root;
	}
};
//递归，顺序转链式
template<class T>
class binarytree2 {
private:
	int size;
	btnode<T>* root;

public:
	btnode<T>* creatbt(btnode<T>* root,queue<T> &tree) {
		if (tree.size() == 0)
			return NULL;
		btnode<T>*leftnewnode = new btnode<T>;
		root->changedata(tree.front());
		tree.pop();
		root->changeleftchild(creatbt(leftnewnode,tree));
		btnode<T>* rightnewnode = new btnode<T>;
		root->changerightchild(creatbt(rightnewnode,tree));
		return root;
	}
	binarytree2(queue<T> tree) {
		size = tree.size();
		root = new btnode<T>;
		creatbt(root, tree);
	}
	void display() {
		display1(root);
	}
};
//template<class T>
//btnode<T>* func(btnode<T>* root) {
//	if (root->data != NULL) {
//		return root;
//	}
//	if (root->left != NULL) {
//		func(root->left);
//	}
//	if (root->right != NULL) {
//		func(root->right);
//	}
//}
template<class T>
btnode<T>* creatbt(btnode<T>* root, queue<T>& tree) {
	if (tree.size() == 0)
		return NULL;
	btnode<T>* leftnewnode = new btnode<T>;
	root->changedata(tree.front());
	tree.pop();
	root->changeleftchild(creatbt(leftnewnode, tree));
	btnode<T>* rightnewnode = new btnode<T>;
	root->changerightchild(creatbt(rightnewnode, tree));
	return root;
}
template<class T>
void exchangetochainfunc(btnode<T> *root,queue<T> &tree) {
	if(root->getdata()!=NULL)
		tree.push(root->getdata());
	if (root->getleftchild() != NULL) {
		exchangetochainfunc(root->getleftchild(),tree);
	}
	if (root->getrightchild() != NULL) {
		exchangetochainfunc(root->getrightchild(),tree);
	}
}
template<class T>
queue<T> exchangetochain(btnode<T>* root) {
	queue<T> *tree = new queue<T>;
	exchangetochainfunc(root,*tree);
	return *tree;
}
//层次遍历
template<class T>
void level(btnode<T>* root) {
	if (root == NULL) {
		return;
	}
	queue<btnode<T>*> q;
	q.push(root);
	while (!q.empty()) {
		root = q.front();
		q.pop();
		cout << root->getdata()<<" ";
		if (root->getleft()) {
			q.push(root->getleft());
			if (root->getright()) {
				q.push(root->getright());
		    }
		}
	}
}
//垂直输出二叉树
template<class T>
void PrintBt(btnode<T>* root) {
	int screenwidth=200;
	if (root == NULL)
		return;
	int level = 0;
	queue<btnode<T>*> q;
	q.push(root);
	while (!q.empty()) {
		int numbers = q.size();
		vector<btnode<T>*> node;
		for (int i = 0; i < numbers; i++) {
			node.push_back(q.front());
			q.pop();
		}
		for (int i = 0; i < numbers; i++) {
			cout.width(screenwidth/(pow(2,level)+1));
			if(node[i]==NULL)
				cout.width(screenwidth / (pow(2, level) + 1));
			else
				cout << node[i]->getdata();
			if (node[i]->getleft()) {
				q.push(node[i]->getleft());
			}
			if (node[i]->getright()) {
				q.push(node[i]->getright());
			}
		}
		cout << endl;
		level++;
	}
}

//前序遍历非递归
template<class T>
void display_1(btnode<T>* root) {
	stack<btnode<T>*> recorder;
	recorder.push(root);
	while (!recorder.empty()) {
		root=recorder.top();
		recorder.pop();
		cout << root->getdata()<<" ";
		if (root->getright())
			recorder.push(root->getright());
		if (root->getleft())
			recorder.push(root->getleft());
	}
}
//中序遍历非递归
template<class T>
void display_2(btnode<T>* root) {
	if (root == NULL)
		return;
	stack<btnode<T>*> recorder;
	while (!recorder.empty()||root!=NULL) {
		if (root != NULL) {
			recorder.push(root);
			root = root->getleft();
		}
		else {
			root = recorder.top();
			cout << root->getdata() << " ";
			recorder.pop();
			root = root->getright();
		}
	}
}
//后序非递归
template<class T>
void display_3(btnode<T>* root) {
	stack<btnode<T>*> recorder;
	while (!recorder.empty() || root != NULL) {
		if (root != NULL) {
			recorder.push(root);
			root = root->getleft();
		}
		else {
			root = recorder.top();
			cout << root->getdata() << " ";
			recorder.pop();
			root = root->getright();
		}
	}
}
//计算二叉树叶子节点数目
template<class T>
void cul_fun(btnode<T>* root,int &size) {
	if (root->getleft()==NULL&&root->getright()==NULL) {
		size++;
	}
	if (root->getleft() != NULL) {
		cul_fun(root->getleft(),size);
	}
	if (root->getright() != NULL) {
		cul_fun(root->getright(),size);
	}
	return;
}
template<class T>
int cul(btnode<T>* root) {
	int size = 0;
	cul_fun(root,size);
	return size;
}
//计算度的节点,cul取1或2
template<class T>
void cul_fun2(btnode<T>* root,int &size,int cul) {
	switch (cul) {
		case 1:
			if ((root->getleft() && root->getright() == NULL) || root->getright() && root->getleft() == NULL) {
				size++;
			}
			
			break;
		case 2:
			if ((root->getleft() && root->getright()) || root->getright() && root->getleft()) {
				size++;
			}
			break;
		default:
			cout << "exception" << endl;
	}
	if (root->getleft() != NULL) {
		cul_fun2(root->getleft(), size, cul);
	}
	if (root->getright() != NULL) {
		cul_fun2(root->getright(), size,cul);
	}
}
template<class T>
void cul2(btnode<T> *root,int cul) {
	int size = 0;
	cul_fun2(root,size,cul);
	return size;
}
//汉诺塔,递归
int tower(int ans) {
	if (ans == 1)
		return 1;
	else {
		return (2 * tower(ans - 1) + 1);
	}
}
//汉诺塔非递归
int hanoi(int ans) {
	int* num = new int[ans];
	num[0] = 1;
	for (int i = 1; i < ans; i++) {
		num[i] = 2 * num[i-1] + 1;
	}
	ans = num[ans-1];
	free(num);
	return ans;
}
int main() {

	/*int n;
	cin >> n;
	int* a;
	int* b;
	a = (int*)malloc(n * sizeof(int));
	b = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << endl;
		cout << b[i] << endl;
	}
	free(a);
	free(b);*/
	/*int n;
	cout << "Input the numbers of binary tree node" << endl;
	cin >> n;
	bt a(n);

	a.display();*/

	btnode<int> F(98);
	btnode<int> E(9);
	btnode<int> C(88,&E, &F);
	btnode<int> G(77);
	btnode<int> D(33, &G);
	btnode<int> B(22,NULL,&D);
	btnode<int> A(23, &B, &C);//root node
	//层次遍历
	//level(&A);

	//中序遍历
	display_2(&A);

	/*vector<int> tree;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		tree.push_back(data);
	}*/

	cout << hanoi(3);
	//快排
	/*btnode<int> *root=new btnode<int>;
	quicksort(root, tree);
	display_2(root);
	cout << endl << endl;
	cout<<cul(root);*/
	/*queue<int> tree;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		tree.push(data);
	}
	binarytree2<int> tree2(tree);
	tree2.display();*/
	/*queue<int> a;
	a = exchangetochain<int>(&A);
	for (int i = 0; i < a.size(); i++) {
		cout << a.front()<<" ";
		a.pop();
	}*/

	
	return 0;
}