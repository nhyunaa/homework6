/*
 * singly linked list
 *
 *  Data Structures
 *  School of Computer Science 
 *  at Chungbuk National University
 */


#include<stdio.h>
#include<stdlib.h>



typedef struct Node {//Node 구조체 정의
	int key; // 정수형 변수 key선언
	struct Node* link; //구조체 포인터 변수 link 선언
} listNode; 

typedef struct Head {//Head 구조체 정의
	struct Node* first; //구조체 포인터 변수 first 선언
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
	char command; // char 형 변수 command 선언
	int key; // 정수형 변수 key 선언
	headNode* headnode=NULL; // headNode 구조체 포인터 변수 headnode NULL로 초기화

	do{
        printf("[----- [노현아] [2022041065] -----]\n");

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
		scanf(" %c", &command); // char형 변수command 입력받기

		switch(command) {
		case 'z': case 'Z'://입력받은 command가 z 거나 Z 인경우
			headnode = initialize(headnode); //headnode를 initialize 함수를 호출한 결과로 대입
			break;
		case 'p': case 'P'://입력받은 command가 p 거나 P 인경우
			printList(headnode);//printList함수 호출
			break;
		case 'i': case 'I'://입력받은 command가 i 거나 I 인경우
			printf("Your Key = ");
			scanf("%d", &key);//정수형 변수 key입력 
			insertNode(headnode, key);//insertNode함수 호출
			break;
		case 'd': case 'D': //입력받은 command가 d거나 D 인경우
			printf("Your Key = ");
			scanf("%d", &key);//정수형 변수 Key입력
			deleteNode(headnode, key);//deleteNode입력
			break;
		case 'n': case 'N'://입력받은 command가 n 거나 N 인경우
			printf("Your Key = ");
			scanf("%d", &key);//정수형 변수 key입력
			insertLast(headnode, key);//insertLast함수 호출
			break;
		case 'e': case 'E'://입력받은 command가 e 거나 E인경우
			deleteLast(headnode);//deleteLast 함수 호출
			break;
		case 'f': case 'F'://입력받은 command가 f거나 F 인경우
			printf("Your Key = ");
			scanf("%d", &key);//정수형 변수 key입력
			insertFirst(headnode, key);//insertFirst함수 호출 
			break;
		case 't': case 'T'://입력받은 command가 t 거나 T 인경우
			deleteFirst(headnode);//deleteFirst함수 호출
			break;
		case 'r': case 'R'://입력받은 command가 r 거나 R 인경우
			invertList(headnode);//invertList 함수 호출
			break;
		case 'q': case 'Q'://입력받은 command가 q 거나 Q 인경우
			freeList(headnode);//freeList 함수 호출
			break;
		default://위의 입력받은 값이 아닌 다른값을 입력받은경우
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;// switch 문을 나옴
		}

	}while(command != 'q' && command != 'Q');//입력받은 command의 값이 q나 Q를 입력받을때까지 반복

	return 1;
}

headNode* initialize(headNode* h) {  //headNode를 초기화하는 함수

	if(h != NULL)//headNode 포인터 변수 h가 NULL값이 아닌경우에 freeList함수를 호출
		freeList(h);

	headNode* temp = (headNode*)malloc(sizeof(headNode));
	//headNode의 포인터 변수 temp를 동적할당으로 메모리를 할당시킨다.

	temp->first = NULL;//temp의 first포인터를 NULL값으로 초기화
	return temp;//temp 반환
}

int freeList(headNode* h){ //리스트의 메모리를 해제하는 함수
	
	listNode* p = h->first; //listNode의 포인터 변수 P에 h가 참조하는 first값을 대입
	listNode* prev = NULL; //listNode의 포인터 변수 prev를 NULL값으로 초기화

	while(p != NULL) { //p가 NULL이 아니라면 반복
		prev = p;//p를 prev에 대입
		p = p->link;//p를 p가 참조하는 link값으로 대입
		free(prev);//prev 동적할당 해제
	}
	free(h);//h동적할당 해제
	return 0;
}


int insertNode(headNode* h, int key) { //노드를 삽입하는 함수

	listNode* node = (listNode*)malloc(sizeof(listNode));
	//listNode의 node를 동적할당하여 메모리를 할당
	node->key = key;//node의 key값에 key 값으로 대입
	node->link = NULL;//node의 link를 NULL값으로 초기화

	if (h->first == NULL)//h의 frist가 NULL값일때 h의 first값을 node로 대입
	{
		h->first = node;
		return 0;
	}

	listNode* n = h->first; //listNode의 n을 h의 first값으로 대입
	listNode* trail = h->first; //listNode의 trail을 h의 first로 대입


	while(n != NULL) {//n이 NULL값이 아니라면 반복
		if(n->key >= key) {//n의 key값이 key 값보다 크거나 같으면 실행
			
			if(n == h->first) {//n값과 h의 first값이 동일하면 실행
				h->first = node;//h의 first값에 node를 대입
				node->link = n;//node의 link값에 n을 대입
			} else {//n값과 h의 first값이 동일하지 않을 때 실행 
				node->link = n;//node의 link값에 n을 대입
				trail->link = node;//trail의 link 값에 node를 대입
			}
			return 0;
		}

		trail = n;//tril에 n값 대입
		n = n->link;//n값에 n의 link 값 대입
	}

	
	trail->link = node;//trail의 link에 node값대입
	return 0;
}


int insertLast(headNode* h, int key) {//노드의 마지막에 노드를 추가하는 함수 

	listNode* node = (listNode*)malloc(sizeof(listNode));//listNode의 node 값을 동적할당으로 메모리 할당
	node->key = key;//node의 key 값을 key값으로 대입
	node->link = NULL;//node의 link값을 NULL값으로 초기화

	if (h->first == NULL)//h의 first값이 NULL값일 때 실행
	{
		h->first = node;//h의 first값을 node값으로 대입
		return 0;
	}

	listNode* n = h->first;//listNode의 n값을 h의 first값으로 대입
	while(n->link != NULL) {//n의 link값이 NULL 값이 아닐때 실행
		n = n->link;//n의 값을 n의 link값으로 대입
	}
	n->link = node;//n의 link를 node 값으로 대입
	return 0;
}

int insertFirst(headNode* h, int key) {//노드의 처음에 노드를 추가하는 함수 

	listNode* node = (listNode*)malloc(sizeof(listNode));//listNode의 node를 동적할당으로 메모리 할당
	node->key = key; //node의 key 값을 key 값으로 대입

	node->link = h->first; //node의 link값을 h의 first값으로 대입
	h->first = node;//h의 first값을 node값으로 대입

	return 0;
}

int deleteNode(headNode* h, int key) { //노드를 삭제하는 함수

	if (h->first == NULL) //h의 first값이 NULL값과 같을때
	{
		printf("nothing to delete.\n");//nothing to delete.출력
		return 0;
	}

	listNode* n = h->first; //listNode의 n값을 h의 first값으로 대입
	listNode* trail = NULL; //listNOde의 trail값을 NULL값으로 대입

	while(n != NULL) { //n값이 NULL이 아닐때 반복
		if(n->key == key) {//n의 key 값과 key 값이 동일할 때 실행

			if(n == h->first) {//n의 값과 h의 first값이 동일할때 실행
				h->first = n->link;//h의 first값에 n의 link값 대입
			} else {//n의 값과 h의 first값이 동일하지 않을 때 실행
				trail->link = n->link;//trail의 link값에 n의 link값을 대입
			}
			free(n);//n을 동적할당 해제 
			return 0;
		}

		trail = n;//trail값을 n값으로 대입
		n = n->link;//n을 n의 link값으로 대입
	}

	printf("cannot find the node for key = %d\n", key);//key값 출력
	return 0;

}

int deleteLast(headNode* h) { //노드의 마지막을 삭제하는 함수

	if (h->first == NULL)//h의 first값이 NULL값 일때 실행
	{
		printf("nothing to delete.\n");//nothing to delete. 출력
		return 0;
	}

	listNode* n = h->first;//listNode의 n값을 h의 first값으로 대입
	listNode* trail = NULL;//listNode의 trail값을 NULL값으로 초기화

	if(n->link == NULL) { //n의 link값이 NULL값일때 실행
		h->first = NULL;//h의 first값을 NULL값으로 초기화
		free(n);//n을 동적할당 해제
		return 0;
	}

	while(n->link != NULL) {//n의 link 값이 NULL값이 아닐때 실행
		trail = n;//trail을 n으로 대입
		n = n->link;//n값을 n의 link값으로 대입
	}
	trail->link = NULL;//trail의 link값을 NULL값으로 바꿈
	free(n);//n을 동적할당 해제

	return 0;
}

int deleteFirst(headNode* h) {//첫번째 노드를 삭제하는 함수

	if (h->first == NULL)// h의 first값이 NULL값과 동일할때 실행
	{
		printf("nothing to delete.\n");//nothing to delete.출력
		return 0;
	}
	listNode* n = h->first;//listNode의 n에 h의 first값대입

	h->first = n->link;//h의 first에 n의 link값 대입
	free(n);//n 동적할당 해제

	return 0;
}



int invertList(headNode* h) { //list를 역순으로 재배치하는 함수


	if(h->first == NULL) {//h의 first값이 NULL값일때 실행
		printf("nothing to invert...\n");//nothing to invert...출력
		return 0;
	}
	listNode *n = h->first;//listNode의 n을 h의 first값을 대입
	listNode *trail = NULL;//listNode의 trail값을 NULL값으로 대입
	listNode *middle = NULL;//listNode의 middle값을 NULL값으로 대입

	while(n != NULL){//n이 NULL값이 아닐때 실행
		trail = middle;//trail 값에 middle값 대입
		middle = n;//middle에 n값 대입
		n = n->link;//n값에 n의 link값 대입
		middle->link = trail;//middle의 link값에 trail대입
	}

	h->first = middle;//h의 first값에 middle 값 대입

	return 0;
}


void printList(headNode* h) { //list를 출력하는 함수
	int i = 0;//정수형 변수 i값을 0으로 초기화
	listNode* p;//listNode구조체 *P선언

	printf("\n---PRINT\n");

	if(h == NULL) {//h가 NULL값일때 실행
		printf("Nothing to print....\n");//Nothing to print....출력
		return;//함수 종료
	}

	p = h->first;//p에 h의 first값 대입

	while(p != NULL) {//p가 NULL값이 아닐 때 실행
		printf("[ [%d]=%d ] ", i, p->key);//i값과 p의 key 값 출력
		p = p->link;//p에 p의 link값을 저장
		i++;//i값 증가(i++)
	}

	printf("  items = %d\n", i);//i값 출력
}
