#include<cstdlib>
#include<cstdio>
#include<iostream>
//#define Type int
using namespace  std;
template<class Type>
struct Node {
	Node<Type>* prev;
	Node<Type>* next;
	Type data;
	//Node(Type t):data(t) {

	//}
};
//typedef struct Node Node;
template<class Type>
struct List {
	Node<Type> *head;
	Node<Type> *tail;
	int size;
};
template<typename Type>
void Init(List<Type>* L) {
	L->head = new Node<Type>;
	/*L->head = (Node*)malloc(sizeof(Node));
	if (L->head == NULL) {
		cout << "Memory allocation failure!" << endl;
		exit(1);

	}*/
	L->head->prev = NULL;
	L->tail = new Node<Type>;
	/*L->tail = (Node*)malloc(sizeof(Node));
	if (L->tail == NULL) {
		cout << "Memory allocation failure" << endl;
		exit(1);
	}*/
	L->tail->next = NULL;
	L->head->next = L -> tail;
	L->tail->prev = L->head;
	//L->tail->data = "Start";
	//L->head->data = "End";
	L->size = 0;
}
template<typename Type>
Node<Type>* End(List<Type>* L) {
	return L->tail->prev;
}
template<typename Type>
Node<Type>* Begin(List<Type>* L) {
	return L->head->next;
}

//传入某链表地址，在哪个地方插入，插入的值
template<class Type>
Node<Type>* Insert(List<Type>* L, Node<Type>* current, Type item) {
	if (current == L->tail) {
		cout << "ERROR!!!" << endl;
		return current;
	}
	Node<Type>* p = current;
	Node<Type>* new_Node = new Node<Type>;
	new_Node->data = item;
	new_Node->next = p ->next;
	p->next->prev = new_Node;
	p->next = new_Node;
	new_Node->prev = p;
	L->size++;
	return p;
	//p->prev->next = p->next;
}
template<class Type>
Node<Type>* Erase(List<Type>* L, Node<Type>* current) {
	if (current == L->tail) {
		cout<<"ERROR!!"<<endl;
		return current;
	}
	if (current == L->head) {
		cout << "ERROR!!" << endl;
		return current;
	}
	Node<Type>* p = current;
	p->prev->next = p -> next;
	p->next->prev = p->prev;
	L->size--;
	//free(p);
	delete[]p;
}
template<typename Type>
Node<Type>* Get_next(Node<Type>* current) {
	return current->next;
}
template<typename Type>
Node<Type>* Get_prev(Node<Type>* current) {
	return current->prev;
}
template<class Type>
void Display_List(Node<Type>* first,Node<Type>* last) {

	for (; first != last; first = first->next) {
		if (first->next == NULL) {
			cout << "Error!!!" << endl;
			break;
		}
		cout << first->data<<" ";
	}
	cout << last->data ;
	cout << endl;
}
template<class Type>
void Display(List<Type>* L) {
	Display_List(Begin(L),End(L));
}
template<class Type>
int Get_data(Node<Type>* current) {
	return current->data;
}
template<class Type>
void Push_back(List<Type>* L,Type item) {
	Node<Type>* p;
	p = Insert(L,End(L),item);
}
template<class Type>
void Pop_back(List<Type>* L) {
	Node* p;
	p=Erase(L,End(L));
}
template<class Type>
Type Back_data(List<Type>* L) {
	return End(L)->data;
}
template<class Type>
Type Front_data(List<Type>* L) {
	return Begin(L)->data;
}
