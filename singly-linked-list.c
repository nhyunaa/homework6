/*
 * singly linked list
 *
 *  Data Structures
 *  School of Computer Science 
 *  at Chungbuk National University
 */


#include<stdio.h>
#include<stdlib.h>



typedef struct Node {//Node ����ü ����
	int key; // ������ ���� key����
	struct Node* link; //����ü ������ ���� link ����
} listNode; 

typedef struct Head {//Head ����ü ����
	struct Node* first; //����ü ������ ���� first ����
}headNode;



headNode* initialize(headNode* h); 
int freeList(headNode* h);

int insertFirst(headNode* h, int key);
int insertNode(headNode* h, int key);
int insertLast(headNode* h, int key);

int deleteFirst(headNode* h);
int deleteNode(headNode* h, int key);
int deleteLast(headNode* h);
int invertList(headNode* h);

void printList(headNode* h);

int main()
{
	char command; // char �� ���� command ����
	int key; // ������ ���� key ����
	headNode* headnode=NULL; // headNode ����ü ������ ���� headnode NULL�� �ʱ�ȭ

	do{
        printf("[----- [������] [2022041065] -----]\n");

		printf("----------------------------------------------------------------\n");
		printf("                     Singly Linked List                         \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command); // char�� ����command �Է¹ޱ�

		switch(command) {
		case 'z': case 'Z'://�Է¹��� command�� z �ų� Z �ΰ��
			headnode = initialize(headnode); //headnode�� initialize �Լ��� ȣ���� ����� ����
			break;
		case 'p': case 'P'://�Է¹��� command�� p �ų� P �ΰ��
			printList(headnode);//printList�Լ� ȣ��
			break;
		case 'i': case 'I'://�Է¹��� command�� i �ų� I �ΰ��
			printf("Your Key = ");
			scanf("%d", &key);//������ ���� key�Է� 
			insertNode(headnode, key);//insertNode�Լ� ȣ��
			break;
		case 'd': case 'D': //�Է¹��� command�� d�ų� D �ΰ��
			printf("Your Key = ");
			scanf("%d", &key);//������ ���� Key�Է�
			deleteNode(headnode, key);//deleteNode�Է�
			break;
		case 'n': case 'N'://�Է¹��� command�� n �ų� N �ΰ��
			printf("Your Key = ");
			scanf("%d", &key);//������ ���� key�Է�
			insertLast(headnode, key);//insertLast�Լ� ȣ��
			break;
		case 'e': case 'E'://�Է¹��� command�� e �ų� E�ΰ��
			deleteLast(headnode);//deleteLast �Լ� ȣ��
			break;
		case 'f': case 'F'://�Է¹��� command�� f�ų� F �ΰ��
			printf("Your Key = ");
			scanf("%d", &key);//������ ���� key�Է�
			insertFirst(headnode, key);//insertFirst�Լ� ȣ�� 
			break;
		case 't': case 'T'://�Է¹��� command�� t �ų� T �ΰ��
			deleteFirst(headnode);//deleteFirst�Լ� ȣ��
			break;
		case 'r': case 'R'://�Է¹��� command�� r �ų� R �ΰ��
			invertList(headnode);//invertList �Լ� ȣ��
			break;
		case 'q': case 'Q'://�Է¹��� command�� q �ų� Q �ΰ��
			freeList(headnode);//freeList �Լ� ȣ��
			break;
		default://���� �Է¹��� ���� �ƴ� �ٸ����� �Է¹������
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;// switch ���� ����
		}

	}while(command != 'q' && command != 'Q');//�Է¹��� command�� ���� q�� Q�� �Է¹��������� �ݺ�

	return 1;
}

headNode* initialize(headNode* h) {  //headNode�� �ʱ�ȭ�ϴ� �Լ�

	if(h != NULL)//headNode ������ ���� h�� NULL���� �ƴѰ�쿡 freeList�Լ��� ȣ��
		freeList(h);

	headNode* temp = (headNode*)malloc(sizeof(headNode));
	//headNode�� ������ ���� temp�� �����Ҵ����� �޸𸮸� �Ҵ��Ų��.

	temp->first = NULL;//temp�� first�����͸� NULL������ �ʱ�ȭ
	return temp;//temp ��ȯ
}

int freeList(headNode* h){ //����Ʈ�� �޸𸮸� �����ϴ� �Լ�
	
	listNode* p = h->first; //listNode�� ������ ���� P�� h�� �����ϴ� first���� ����
	listNode* prev = NULL; //listNode�� ������ ���� prev�� NULL������ �ʱ�ȭ

	while(p != NULL) { //p�� NULL�� �ƴ϶�� �ݺ�
		prev = p;//p�� prev�� ����
		p = p->link;//p�� p�� �����ϴ� link������ ����
		free(prev);//prev �����Ҵ� ����
	}
	free(h);//h�����Ҵ� ����
	return 0;
}


int insertNode(headNode* h, int key) { //��带 �����ϴ� �Լ�

	listNode* node = (listNode*)malloc(sizeof(listNode));
	//listNode�� node�� �����Ҵ��Ͽ� �޸𸮸� �Ҵ�
	node->key = key;//node�� key���� key ������ ����
	node->link = NULL;//node�� link�� NULL������ �ʱ�ȭ

	if (h->first == NULL)//h�� frist�� NULL���϶� h�� first���� node�� ����
	{
		h->first = node;
		return 0;
	}

	listNode* n = h->first; //listNode�� n�� h�� first������ ����
	listNode* trail = h->first; //listNode�� trail�� h�� first�� ����


	while(n != NULL) {//n�� NULL���� �ƴ϶�� �ݺ�
		if(n->key >= key) {//n�� key���� key ������ ũ�ų� ������ ����
			
			if(n == h->first) {//n���� h�� first���� �����ϸ� ����
				h->first = node;//h�� first���� node�� ����
				node->link = n;//node�� link���� n�� ����
			} else {//n���� h�� first���� �������� ���� �� ���� 
				node->link = n;//node�� link���� n�� ����
				trail->link = node;//trail�� link ���� node�� ����
			}
			return 0;
		}

		trail = n;//tril�� n�� ����
		n = n->link;//n���� n�� link �� ����
	}

	
	trail->link = node;//trail�� link�� node������
	return 0;
}


int insertLast(headNode* h, int key) {//����� �������� ��带 �߰��ϴ� �Լ� 

	listNode* node = (listNode*)malloc(sizeof(listNode));//listNode�� node ���� �����Ҵ����� �޸� �Ҵ�
	node->key = key;//node�� key ���� key������ ����
	node->link = NULL;//node�� link���� NULL������ �ʱ�ȭ

	if (h->first == NULL)//h�� first���� NULL���� �� ����
	{
		h->first = node;//h�� first���� node������ ����
		return 0;
	}

	listNode* n = h->first;//listNode�� n���� h�� first������ ����
	while(n->link != NULL) {//n�� link���� NULL ���� �ƴҶ� ����
		n = n->link;//n�� ���� n�� link������ ����
	}
	n->link = node;//n�� link�� node ������ ����
	return 0;
}

int insertFirst(headNode* h, int key) {//����� ó���� ��带 �߰��ϴ� �Լ� 

	listNode* node = (listNode*)malloc(sizeof(listNode));//listNode�� node�� �����Ҵ����� �޸� �Ҵ�
	node->key = key; //node�� key ���� key ������ ����

	node->link = h->first; //node�� link���� h�� first������ ����
	h->first = node;//h�� first���� node������ ����

	return 0;
}

int deleteNode(headNode* h, int key) { //��带 �����ϴ� �Լ�

	if (h->first == NULL) //h�� first���� NULL���� ������
	{
		printf("nothing to delete.\n");//nothing to delete.���
		return 0;
	}

	listNode* n = h->first; //listNode�� n���� h�� first������ ����
	listNode* trail = NULL; //listNOde�� trail���� NULL������ ����

	while(n != NULL) { //n���� NULL�� �ƴҶ� �ݺ�
		if(n->key == key) {//n�� key ���� key ���� ������ �� ����

			if(n == h->first) {//n�� ���� h�� first���� �����Ҷ� ����
				h->first = n->link;//h�� first���� n�� link�� ����
			} else {//n�� ���� h�� first���� �������� ���� �� ����
				trail->link = n->link;//trail�� link���� n�� link���� ����
			}
			free(n);//n�� �����Ҵ� ���� 
			return 0;
		}

		trail = n;//trail���� n������ ����
		n = n->link;//n�� n�� link������ ����
	}

	printf("cannot find the node for key = %d\n", key);//key�� ���
	return 0;

}

int deleteLast(headNode* h) { //����� �������� �����ϴ� �Լ�

	if (h->first == NULL)//h�� first���� NULL�� �϶� ����
	{
		printf("nothing to delete.\n");//nothing to delete. ���
		return 0;
	}

	listNode* n = h->first;//listNode�� n���� h�� first������ ����
	listNode* trail = NULL;//listNode�� trail���� NULL������ �ʱ�ȭ

	if(n->link == NULL) { //n�� link���� NULL���϶� ����
		h->first = NULL;//h�� first���� NULL������ �ʱ�ȭ
		free(n);//n�� �����Ҵ� ����
		return 0;
	}

	while(n->link != NULL) {//n�� link ���� NULL���� �ƴҶ� ����
		trail = n;//trail�� n���� ����
		n = n->link;//n���� n�� link������ ����
	}
	trail->link = NULL;//trail�� link���� NULL������ �ٲ�
	free(n);//n�� �����Ҵ� ����

	return 0;
}

int deleteFirst(headNode* h) {//ù��° ��带 �����ϴ� �Լ�

	if (h->first == NULL)// h�� first���� NULL���� �����Ҷ� ����
	{
		printf("nothing to delete.\n");//nothing to delete.���
		return 0;
	}
	listNode* n = h->first;//listNode�� n�� h�� first������

	h->first = n->link;//h�� first�� n�� link�� ����
	free(n);//n �����Ҵ� ����

	return 0;
}



int invertList(headNode* h) { //list�� �������� ���ġ�ϴ� �Լ�


	if(h->first == NULL) {//h�� first���� NULL���϶� ����
		printf("nothing to invert...\n");//nothing to invert...���
		return 0;
	}
	listNode *n = h->first;//listNode�� n�� h�� first���� ����
	listNode *trail = NULL;//listNode�� trail���� NULL������ ����
	listNode *middle = NULL;//listNode�� middle���� NULL������ ����

	while(n != NULL){//n�� NULL���� �ƴҶ� ����
		trail = middle;//trail ���� middle�� ����
		middle = n;//middle�� n�� ����
		n = n->link;//n���� n�� link�� ����
		middle->link = trail;//middle�� link���� trail����
	}

	h->first = middle;//h�� first���� middle �� ����

	return 0;
}


void printList(headNode* h) { //list�� ����ϴ� �Լ�
	int i = 0;//������ ���� i���� 0���� �ʱ�ȭ
	listNode* p;//listNode����ü *P����

	printf("\n---PRINT\n");

	if(h == NULL) {//h�� NULL���϶� ����
		printf("Nothing to print....\n");//Nothing to print....���
		return;//�Լ� ����
	}

	p = h->first;//p�� h�� first�� ����

	while(p != NULL) {//p�� NULL���� �ƴ� �� ����
		printf("[ [%d]=%d ] ", i, p->key);//i���� p�� key �� ���
		p = p->link;//p�� p�� link���� ����
		i++;//i�� ����(i++)
	}

	printf("  items = %d\n", i);//i�� ���
}
