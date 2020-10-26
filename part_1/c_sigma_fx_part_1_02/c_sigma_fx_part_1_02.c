#include <stdio.h>

void	main()
{
	char	c = 'A';
	short	s = 0x1234;
	int		i = 0x12345678;
	__int64	i64 = 0x1234567812345678;
	float	f = 0.1234567f;
	double	d = 0.123456789012345;
	void* p = 0;

	printf("c   = %-20c, size = %zd byte(s)\n", c, sizeof(c));
	printf("s   = %-20i, size = %zd byte(s)\n", s, sizeof(s));
	printf("i   = %-20d, size = %zd byte(s)\n", i, sizeof(i));
	printf("i64 = %-20I64d, size = %zd byte(s)\n", i64, sizeof(i64));
	printf("f   = %-20.7f, size = %zd byte(s)\n", f, sizeof(f));
	printf("d   = %-20.15f, size = %zd byte(s)\n", d, sizeof(d));
	printf("p   = %-20p, size = %zd byte(s)\n", p, sizeof(p));
}
