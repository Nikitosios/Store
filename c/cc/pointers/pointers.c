#include <stdio.h>

unsigned char variable = 0;
unsigned char* variablePointer = NULL;

void main ()
{
	variablePointer = &variable;

	printf("\n");

	printf("Введите значение переменной variable: ");
	scanf("%d", variablePointer);
	printf("\nЗначение переменной variable(%i) хранится в памяти по адресу %p.", variable, variablePointer);

	printf("\n\n");
	return;
}

