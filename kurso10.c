/*10. База данных "Авиакасса"
 Пополнение базы.
 Редактирование базы.
 Удаление записей. +
 Подбор маршрута с наименьшим временем ожидания при пересадке. +
 Подбор маршрута с наименьшей стоимостью. +
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#define MAXLINE 500

typedef struct Node
{
	//Data
	long int n_flight;//номер рейса!!!(Номер рейса свой для каждого рейса)!!!
	char to[50];//город, в который направляется рейс
	float price;//цена 
	char time_t_l[15];//время вылета-прилёта
	int time_wait;//премя ожидания при пересадке(в минутах)

	//Pointer to next Node
	struct Node *ptr_next;
} Node;

static Node *head_ptr;//указатель на первый элемент списка

/*функция для инициализации полей одного узла, используя строку(строка содержит все поля одного узла,
поля в строке разделены меду собой одним пробелом)*/
void give_Data(char buf[], Node *pNode)
{
	int i;
	char line[50];
	char *ptr_line = line , *ptr_buf = buf;

	//инициализация n_flight
	while (*ptr_buf != ' ')
	{
		*ptr_line = *ptr_buf;
		ptr_line++;
		ptr_buf++;
	}
	*ptr_line = '\n';
	*ptr_line++;
	*ptr_line = '\0';
	pNode->n_flight = atoi(ptr_line);
	ptr_buf++;
	ptr_line = line;

	//инициализация to[]
	i = 0;
	while (*ptr_buf != ' ')
	{
		pNode->to[i] = *ptr_buf;
		ptr_buf++;
		i++;
	}
	pNode->to[i] = '\n';
	i++;
	pNode->to[i] = '\0';
	ptr_buf++;

	//инициализация price
	while (*ptr_buf != ' ')
	{
		*ptr_line = *ptr_buf;
		ptr_line++;
		ptr_buf++;
	}
	*ptr_line = '\n';
	*ptr_line++;
	*ptr_line = '\0';
	pNode->price =(float) atof(ptr_line);
	ptr_buf++;
	ptr_line = line;

	//инициализация time_t_l
	i = 0;
	while (*ptr_buf != ' ')
	{
		pNode->time_t_l[i] = *ptr_buf;
		ptr_buf++;
		i++;
	}
	pNode->time_t_l[i] = '\n';
	i++;
	pNode->time_t_l[i] = '\0';
	ptr_buf++;

	//инициализация time_wait
	while (*ptr_buf >='0' && *ptr_buf<='9' )
	{
		*ptr_line = *ptr_buf;
		ptr_line++;
		ptr_buf++;
	}
	*ptr_line = '\n';
	*ptr_line++;
	*ptr_line = '\0';
	pNode->time_wait = atoi(ptr_line);
	
}

//функция для получения нового узла
Node * give_next_Node(Node *pNode)//аргумент-указатель на данный узел. Выделяет память,инициализирует ptr_next для следующего узла и возвращает указатель на следующий узел
{
	
	Node *Nnode;//указатель на новый узел
	Nnode = (Node *)malloc(sizeof(Node));//выделение памяти для нового узла
	pNode->ptr_next = Nnode;
	Nnode->ptr_next = NULL;//инициализакия следующего указаделя нового узла
	return Nnode;
}

//функция для удаления узла
void delete_node(Node *pNode)
{
	Node *nNode;
	Node *prevNode;

	//Если удаляемый узел в начале вписка
	if (pNode == head_ptr)
	{
		head_ptr = pNode->ptr_next;
		free(pNode);
	}
	else
	{//если удаляемый узел в конце списка
		if (pNode->ptr_next == NULL)
		{
			nNode = head_ptr;
			prevNode = nNode;
			while (nNode->ptr_next != NULL)
			{
				prevNode = nNode;
				nNode = nNode->ptr_next;
			}
			free(nNode);  
			prevNode->ptr_next = NULL;
		}
		else//если удаляемый узел не является началом или концом списка
		{
			nNode = head_ptr;
			prevNode = nNode;
			nNode = nNode->ptr_next;
			while (prevNode->ptr_next != pNode)
			{
				prevNode = nNode;
				nNode = nNode->ptr_next;
			} 

			prevNode->ptr_next = nNode->ptr_next;
			free(nNode);
		}
	}
}

//вывод на экран всех рейсов
void print_table(void)
{
	Node *nNode;
	nNode = head_ptr;
	char *ptr = NULL;

	while (nNode->ptr_next != NULL)
	{
		printf("%d ", nNode->n_flight);
		printf(" ");

		ptr = nNode->to;
		while (*ptr != '\n' || *ptr != '\0')
		{
			putchar(*ptr);
			ptr++;
		}
		printf(" ");

		printf("%f ", nNode->price);
		printf(" ");

		ptr = nNode->time_t_l;
		while (*ptr != '\n' || *ptr != '\0')
		{
			putchar(*ptr);
			ptr++;
		}
		printf(" ");
		
		printf("%d\n ", nNode->time_wait);

		nNode = nNode->ptr_next;
	}
}

//добавление нового рейса. Параметр функции-номер строки, куда пользователь хочет впихнуть новый рейс (для того что бы можно было добавлять не только в конец.
Node * add_flight(int num_string_add)
{
	Node *nNode;
	Node *prevNode;
	Node *new_ptr;

	if (num_string_add = 1)
	{
		new_ptr = (Node *)malloc(sizeof(Node));
		new_ptr->ptr_next = head_ptr;
		head_ptr = new_ptr;
		return head_ptr;
	}
	
	nNode = head_ptr;
	prevNode = nNode;

	for (; num_string_add > 1; num_string_add--)
	{
		if (nNode->ptr_next = NULL)//следует необходимо добавить в конец списка
		{
			new_ptr = (Node *)malloc(sizeof(Node));
			nNode->ptr_next = new_ptr;
			new_ptr->ptr_next = NULL;
			return new_ptr;
		}

		prevNode = nNode;
		nNode = nNode->ptr_next;

	}
	
	new_ptr = (Node *)malloc(sizeof(Node));
	prevNode->ptr_next = new_ptr;
	new_ptr->ptr_next = nNode;
	return new_ptr;
}

int edit_Node(int num_flight)//редактирование рейса(осталось сделать так, что бы редактировать некоторый поля)
{
	Node *nNode = head_ptr;

	while (nNode->n_flight != num_flight)
	{
		nNode = nNode->ptr_next;
		if (nNode == NULL)
		{
			printf("Такого рейса нет");
			return 1;
		}
	}

	printf("Введите изменённый номер рейса:");
	scanf("%d", &nNode->n_flight);
	printf("\n");

	printf("Введите город в который направляется рейс:");
	gets(nNode->to);
	printf("\n");

	printf("Введите цену рейса в рублях:");
	scanf("%f", &nNode->price);
	printf("\n");

	printf("Введите время вылета-приземления фаормата :'10:50-15:30'");
	gets(nNode->time_t_l);
	printf("\n");

	printf("Введите врея ожидания при пересадках в минутах: ");
	scanf("%d", &nNode->time_wait);
	printf("\n");





}

int main()
{
	FILE *fptr,*fptr_out;//указатели на файлы
	char *ptr;//Указатель для получаемой строки из исходного файла
	char line[MAXLINE];
	Node *Node_ptr = NULL;
	int choice_main;//переменная для выбора одного из 5 (см. ТЗ)
	int num_flight;
	Node *add_Node_ptr =NULL;
	int num_delete;
	int min;
	Node *Node_min = NULL;

	system("chcp 1251");//для использования русской кодировки

	fptr = fopen( "AviaCassa.txt", "rt");
	fptr_out = fopen( "AviaCassa2.txt", "wt");

	if ((fptr || fptr_out) == NULL)
	{
		printf("Error opening or creating files or my code is fu*king turd");
		return 1;
	}

	//выделение памяти и инициализация полей Data первого Node
	if (!feof(fptr))
	{

		if ((ptr = fgets(line, MAXLINE, fptr)) != NULL)
		{
			head_ptr = (Node *)malloc(sizeof(Node));//выделение памяти для первого узла списка
			head_ptr->ptr_next = NULL;//инициализация следующего указателя

			give_Data(line, head_ptr);//заполнение полей Data первого узла звписка
		}
	}
	//выделение памяти и инициализация полей Data второго Node
	if (!feof(fptr))
	{

		if ((ptr = fgets(line, MAXLINE, fptr)) != NULL)
		{
			Node_ptr = give_next_Node(head_ptr);
			give_Data(line, Node_ptr);
		}
	}
	//выделение памяти и инициализация полей Data оставшихся Node
	while (!feof(fptr))
	{
		if ((ptr = fgets(line, MAXLINE, fptr)) != NULL)
		{
			Node_ptr = give_next_Node(Node_ptr);
			give_Data(line, Node_ptr);
		}
	}
	//внесение данных из файла в поля списка закончено

	system("cls");//очиска консоли
	
	do
	{

		printf("[0] Выйти из программы.\n[1] Добавить рейс.\n[2] Редактировать рейс.\n[3] Удалить рейс.\n[4] Подобрать маршрут с наименьшим временем ожидания при пересадке.\n[5] Подобратьмаршрут с наименьшей стоимостью.\n");
		scanf("%d", &choice_main);

		switch (choice_main)
		{
			case 1:
				system("cls");
				//добавить рейс
				print_table();
				printf("Введите номер строки, в которую нужно впихнуть новый рейс");
				scanf("%d", &num_flight);

				add_Node_ptr = add_flight(num_flight);

				system("cls");
				//заполнеие узла списка

				printf("Введите номер рейса:");
				scanf("%d", &add_Node_ptr->n_flight);
				printf("\n");

				printf("Введите город в который направляется рейс:");
				gets(add_Node_ptr->to);
				printf("\n");

				printf("Введите цену рейса в рублях:");
				scanf("%f", &add_Node_ptr->price);
				printf("\n");

				printf("Введите время вылета-приземления фаормата :'10:50-15:30'");
				gets(add_Node_ptr->time_t_l);
				printf("\n");

				printf("Введите врея ожидания при пересадках в минутах: ");
				scanf("%d", &add_Node_ptr->time_wait);
				printf("\n");

				system("pause");

			case 2:
				system("cls");
				//редактировать рейс
				print_table();
				printf("Введите номер рейса, который хотите редактировать");
				scanf("%d", &num_flight);

				edit_Node(num_flight);//редактирование рейса

				system("pause");

			case 3:
				system("cls");
				//удалить рейс
				print_table();
				printf("Введите номер рейса, который хотите удалить");
				scanf("%d",&num_delete);

				Node_ptr = head_ptr;

				while (Node_ptr->n_flight != num_delete)
				{
					Node_ptr = Node_ptr->ptr_next;
				}

				delete_node(Node_ptr);

			case 4:
				system("cls");
				//подобрать маршрут с наименьшим временем ожиданя при пересадке
				print_table();
				printf("Введите город в который вы хотите полететь\n");
				gets_s(line, 50);

				Node_ptr = head_ptr;
				min = 2100000000;
				while (Node_ptr->ptr_next != NULL)
				{
					if (strcmp(line, Node_ptr->to) == 0)
					{
						if (Node_ptr->time_wait < min)
						{
							min = Node_ptr->time_wait;
							Node_min = Node_ptr;
						}
					}
					Node_ptr = Node_ptr->ptr_next;
				}

				printf("На маршруте номер %d наименьшее время ожидания при пересадке: %d минут\n", Node_min->n_flight,Node_min->time_wait);
				system("pause");

			case 5:
				system("cls");
				//подобрать маршрут наименьший по стоимости

				print_table();
				printf("Введите город в который вы хотите полететь\n");
				gets_s(line, 50);

				Node_ptr = head_ptr;
				min = 2100000000;
				while (Node_ptr->ptr_next != NULL)
				{
					if (strcmp(line, Node_ptr->to) == 0)
					{
						if (Node_ptr->time_wait < min)
						{
							min = Node_ptr->time_wait;
							Node_min = Node_ptr;
						}
					}
					Node_ptr = Node_ptr->ptr_next;
				}

				printf("До города %s самый дешёвый рейс номер: %d\n", line, Node_min->n_flight);
				system("pause");
					
			default:
				break;
		};


	} while ( choice_main != 0 );


	return 0;
}
