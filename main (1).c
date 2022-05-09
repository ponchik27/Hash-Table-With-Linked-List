
#include<stdio.h>
#include<stdlib.h>

#define size 7

struct node
{
    int data;
    struct node* next;
};

struct node* chain[size]; // глобальная переменная, которая представляет собой хеш-таблицу

void init()
{
    int i;
    for (i = 0; i < size; i++)
        chain[i] = NULL;
}

void insert(int value)
{
    //Создаём новую связь со значаением
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    //Вычисляем адрес элемента
    int key = value % size;

    //Проверяем chain[key] пустой ли? 
    if (chain[key] == NULL)
        chain[key] = newNode;
    //Коллизия(chain[key] уже занята)
    else
    {
        //добавлямм новую запись в конец chain[key].
        struct node* temp = chain[key];
        while (temp->next)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void print()
{
    int i;

    for (i = 0; i < size; i++)
    {
        struct node* temp = chain[i];
        printf("chain[%d]-->", i);
        while (temp)
        {
            printf("%d -->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    //Создаём хеш-таблицу, которая будет представлять собой массив односвязных списоков
    init();

    insert(7);
    insert(0);
    insert(3);
    insert(10);
    insert(4);
    insert(5);

    print();

    return 0;
}
