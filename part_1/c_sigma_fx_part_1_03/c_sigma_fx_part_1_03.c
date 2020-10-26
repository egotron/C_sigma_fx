#include <stdio.h>

void	expression_unary()
{
	int i = 1;
	int* pi = &i;

	printf("[ unary expression ]\n");
	printf("i = %d\n", i);
	printf("&i = %p\n", &i);
	printf("*pi = %d\n", *pi);
	printf("~i = %d\n", ~i);
	printf("!i = %d\n", !i);
	i++;
	printf("i++ = %d\n", i);
	--i;
	printf("--i = %d\n", --i);
}

void	main(void)
{
	expression_unary();
}
