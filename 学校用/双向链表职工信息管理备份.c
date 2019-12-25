#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void print_all(void);
void input_all(void);
void search_all(void);
void edit_all(void);
void del_all(void);

struct node{
	struct node* pre;
	char name[20];
	char number[30];
	char xingbie[7];//male and female
	int age;
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
		printf("Error!\n");
		exit(0);
	}
	printf("sort is:name,number,xingbie,age\n");
	scanf("%s%s%s%d",p->name,p->number,p->xingbie,&(p->age));
	p->next=NULL;
	p->pre=NULL;
	return (p);
}
node *creat_list(int n)
{
	node *p,*new1,*head;
	int i;
	if(n>=1){
	new1=creat_node();
	head=new1; 
	p=new1;
	} 
	for(i=2;i<=n;i++){
		new1=creat_node();
		p->next=new1;
		new1->pre=p;
		p=new1;
		last=p;
	}
	if(n>=1){
		return (head);
	}
	else{
		return 0;
	}
	 
 }
 void fake_main(void){
 	
 	int n;
 	node* nothing;
 	printf("What do u want to do?\n1:creat,2:print all staff,3:serach,4:edit,5:del\n");
 	scanf("%d",&n);
 	switch(n){
 		case 1:input_all();break;
 		case 2:print_all();break;
 		case 3:search_all();break;
		case 4:edit_all();break;
		case 5:del_all();break;
		default :printf("Error!\n"); 
	 }
 	
 } 


int main()
{
	while(1){
		fake_main();
	}
	return 0;
}
void input_all(void){
	int n;
	printf("how many staffs do u want to creat?\n");
	scanf("%d",&n);
	head=creat_list(n);
}
void print_all(void)
{
	node *head1;
	head1=head;
	while(head1!=NULL){
		printf("name:%s  number:%s  xingbie:%s  age:%d\n",head1->name,head1->number,head1->xingbie,head1->age);
		head1=head1->next;
	}
}
void search_all(void)
{
	node *head2;
	head2=head;
	char ser[20];
	int judge=0;
	printf("Inpout his name to search:");
	scanf("%s",ser);
	
	while(head2!=NULL){
		if(strcmp(ser,head2->name)==0){
			judge=1;
			break;
		}
		
		head2=head2->next;
	}
	if(judge!=1){
		printf("There is no this people\n");
	}
	else{
		printf("OK!I have found one!!!\nhis name:%s,his number:%s,his xingbie:%s,his age:%d\n",head2->name,head2->number,head2->xingbie,head2->age);
	}
}
void edit_all(void){
	node *head1;
	int judge=0;
	head1=head;
	printf("which one do want to edit??Input his number:");
	char num[30];
	scanf("%s",num);
	while(head1!=NULL){
		if(strcmp(num,head1->number)==0){
			judge=1;
			break;
		}
		head1=head1->next;
	}
	if(judge==0){
		printf("Input correct number,please!\n");
	}
	else{
		printf("Ok,edit it!!\nsort:name,number,xingbie,age\n");
		scanf("%s%s%s%d",head1->name,head1->number,head1->xingbie,&(head1->age));
	}
	
}
void del_all(void){
	node* head1;
	head1=head;
	int judge=0;
	char num[30];
	printf("Which staff do you want to remove?Input his number:");
	scanf("%s",num);
	while(head1!=NULL){
		if(strcmp(num,head1->number)==0){
			judge=1;
			break;
		}
		head1=head1->next;
	}
	if(judge==0){
		printf("Input correct number,please!\n");
	}
	else{
		if(head1==head&&head1==last){
		
			head=NULL;
		
		} 
		else if(head1==last){
			(head1->pre)->next=NULL;
			last=head1->pre; 
		}
		else if(head1==head){
			head=head->next;
		}
		else{
		(head1->pre)->next=head1->next;
		(head1->next)->pre=head1->pre;
	}
		
	}
	
}

