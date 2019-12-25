#include<stdio.h>
#include<stdlib.h>
struct node{
	int num;
	struct node* pre;
	struct node* next;
};
typedef struct node node;
node *head;
node *last; 
node *creat_node(void)
{
	node *p;
	p=(node*)malloc(sizeof(node));
	if(p==NULL){
		printf("ERROR!!!!!!\n");
		exit(0);
	}
	scanf("%d",&(p->num));
	p->pre=NULL;
	p->next=NULL; 
	return (p);
}
node *creat_list(int n)
{
	node *p;
	node *a,*b;
	int i;
	if(n>=1){
		b=creat_node();
	}
	p=b;
	for(i=2;i<=n;i++){
		a=creat_node();
		p->next=a;
		a->pre=p;
		p=a;
		last=a;
	}
	if(n>=1){
		return (b);
	}
	else{
		return 0;
	}
}
void printans(void)
{
	while(head!=NULL){
		printf("%d\n",head->num);
		head=head->next;
	}
}
void sort(void)
{
	int max;
	int t;
	node *head1;
	node *last1;
	last1=last;
	head1=head;
	while(last1!=head1){
	while((head1!=last1)){
		if((head1->num)>(last1->num)){
			t=head1->num;
			head1->num=last1->num;
			last1->num=t;
		}
		head1=head1->next;
	}
	last1=last1->pre;
	head1=head;
}
}
int main()
{
	int n;
	scanf("%d",&n);
	head=creat_list(n);
	sort();
	printans();
	return 0;
}
