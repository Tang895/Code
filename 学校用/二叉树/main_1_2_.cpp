#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
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
	~btnode<T>(){
		//delete data;
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

//垂直输出二叉树，书上的方法
struct Location {
	int xindent, ylevel;
};
void Gotoxy(int x,int y) {
	static int level = 0, indent = 0;
	if (y == 0) {
		indent = 0;
		level = 0;
	}
	if (level != y) {
		cout << endl;
		indent = 0;
		level++;
	}
	cout.width(x - indent);
	indent = x;
}
template<class T>
void PrintBTree(btnode<T>* t, int screenwidth) {
	if (t == NULL) return;
	int level = 0, offset = screenwidth / 2;
	Location fLoc, cLoc;
	queue<btnode<T>*> Q;
	queue<Location> LQ;
	fLoc.xindent = offset;
	fLoc.ylevel = level;
	Q.push(t);
	LQ.push(fLoc);
	while (!Q.empty()) {
		t = Q.front();
		Q.pop();
		fLoc = LQ.front();
		LQ.pop();
		Gotoxy(fLoc.xindent, fLoc.ylevel);
		cout << t->getdata();
		if (fLoc.ylevel != level) {
			level++;
			offset = offset / 2;
		}
		if (t->getleft()) {
			Q.push(t->getleft());
			cLoc.ylevel = fLoc.ylevel + 1;
			cLoc.xindent = fLoc.xindent - offset / 2;
			LQ.push(cLoc);
		}
		if (t->getright()) {
			Q.push(t->getright());
			cLoc.ylevel = fLoc.ylevel + 1;
			cLoc.xindent = fLoc.xindent + offset / 2;
			LQ.push(cLoc);
		}
	}
	cout << endl;

}

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
	//没写出来
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
//template<class T>
//class binarytree2 {
//private:
//	int size;
//	btnode<T>* root;
//
//public:
//	btnode<T>* creatbt(btnode<T>* root,queue<T> &tree) {
//		if (tree.size() == 0)
//			return NULL;
//		btnode<T>*leftnewnode = new btnode<T>;
//		root->changedata(tree.front());
//		tree.pop();
//		root->changeleftchild(creatbt(leftnewnode,tree));
//		btnode<T>* rightnewnode = new btnode<T>;
//		root->changerightchild(creatbt(rightnewnode,tree));
//		return root;
//	}
//	binarytree2(queue<T> tree) {
//		size = tree.size();
//		root = new btnode<T>;
//		creatbt(root, tree);
//	}
//	void display() {
//		display1(root);
//	}
//};
//递归，顺序转链式
template<class T>
btnode<T>* exchangetochain2(vector<T> &tree,int pos) {
	if (pos > tree.size())
		return NULL;
	btnode<T>* root = new btnode<T>;
	root->changedata(tree[pos]);
	if (2 * pos + 1 < tree.size()) {
		if (tree[2 * pos + 1] != NULL) {
			btnode<T>* newleftnode = new btnode<T>;
			root->changeleftchild(exchangetochain2(tree, 2 * pos + 1));
		}
	}
	if (2 * pos + 2 < tree.size()) {
		if (tree[pos * 2 + 2] != NULL) {
			btnode<T>* newrightnode = new btnode<T>;
			root->changerightchild(exchangetochain2(tree, 2 * pos + 2));
		}
	}
	return root;
}
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
//失败
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
//垂直输出二叉树, 失败的
template<class T>
void PrintBt(btnode<T>* root) {
	int screenwidth=80;
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
//计算二叉树的高度/深度,递归
template<class T>
int depth(btnode<T>* root) {
	if (root == NULL)
		return -1;
	int l=depth(root->getleft());
	int r=depth(root->getright());
	return 1+(l>r?l:r);
}
//递归，二叉树的复制
template<class T>
btnode<T>* copybt(btnode<T> *root) {
	if (root == NULL)
		return NULL;
	btnode<T>* newrootnode = new btnode<T>;
	newrootnode->changedata(root->getdata());
	btnode<T>* newleftnode = new btnode<T>;
	newleftnode = copybt(root->getleftchild());
	btnode<T>* newrightnode = new btnode<T>;
	newrightnode = copybt(root->getrightchild());
	newrootnode->changeleftchild(newleftnode);
	newrootnode->changerightchild(newrightnode);
	return newrootnode;
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
//求幂集,递归
template<class T>
void power(vector<vector<T>>& ans,vector<T> &sl,int pos) {
	cout << "求幂集: ";


	cout << endl;
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
	delete num;
	return ans;
}
//交换左右孩子节点
template<class T>
void changechild(btnode<T>*root) {
	btnode<T>* temp = root->getleftchild();
	root->changeleftchild(root->getrightchild());
	root->changerightchild(temp);
	if (root->getleftchild())
		changechild(root->getleftchild());
	if (root->getrightchild())
		changechild(root->getrightchild());
	
}
//反向打印stack
template<class T>
void printstack(stack<T> a) {
	vector<T> b;
	int size = a.size();
	for (int i = 0; i < size; i++) {
		b.push_back(a.top());
		a.pop();
	}
	for (int i = size - 1; i >= 0; i--) {
		cout << vector[i];
	}
}
//计算从根节点到叶子节点的所有路径,回溯,失败的,2020/10/14
template<class T>
void culculateallpath_fun(btnode<T>* root,vector<T> &path,vector<string> &result) {
	if (root!=NULL)
		path.push_back(root->getdata());
	else return;
	if (root->getleftchild() == NULL && root->getrightchild() == NULL) {
		string sPath;
		for (int i = 0; i < path.size()-1; i++) {
			sPath += to_string(path[i]);
			sPath += "->";
		}
		sPath += to_string(path[path.size()-1]);
		result.push_back(sPath);
		return;
	}
	if (root->getleftchild()!=NULL) {
		culculateallpath_fun(root, path, result);
		path.pop_back();
	}
	if (root->getrightchild()!=NULL) {
		culculateallpath_fun(root, path, result);
		path.pop_back();
	}
}
template<class T>
void culculateallpath(btnode<T>* root) {
	vector<string> result;
	vector<T> path;
	culculateallpath_fun(root, path, result);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
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

	//前序遍历
	display1(&A);
	cout << endl;
	//垂直输出二叉树
	//
	PrintBTree(&A,80);
	cout << endl << endl << endl;
	vector<int> tree;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		tree.push_back(data);
	}
	btnode<int>* root=new btnode<int>;
	root = exchangetochain2(tree,0);
	display1(root);
	cout << endl;

	culculateallpath(root);
	cout << endl;


	cout << depth(root);
	cout << endl << endl;
	cout << hanoi(3);
	cout << endl;
	btnode<int>* root2 = new btnode<int>;
	root2 = copybt(root);
	//display1(root2);
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