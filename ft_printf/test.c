#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putptr(unsigned long long ptr);
int	ft_putnbr(int n);
int	ft_putunbr(unsigned int n);
int	ft_puthex(unsigned int n, char c);
int	ft_check_format(va_list *ap, const char *format);

int	main(void)
{
	int	PF, MY;

	PF = 0;
	MY = 0;

	printf("-------------------\n");
	printf("WELCOME TO THE TEST\n");
	printf("-------------------\n");

	printf("[NULL PTR AS STR]\n");
	printf("INPUT : (\"%%s\", (char *)NULL)\n");
	PF = printf("PF: %s\n", (char *)NULL);
	MY = ft_printf("MY: %s\n", (char *)NULL);
	printf("PF: %d\n", PF);
	printf("MY: %d\n", MY);

	printf("------------------\n");

	printf("[NULL PTR AS PTR ADDRESS]\n");
	printf("INPUT : (\"%%p\", (void *)NULL)\n");
	PF = printf("PF: %p\n", (void *)NULL);
	MY = ft_printf("MY: %p\n", (void *)NULL);
	printf("PF: %d\n", PF);
	printf("MY: %d\n", MY);

	printf("------------------\n");

	printf("[NULL PTR AS CHAR]\n");
	printf("INPUT : (\"%%c\", (char)NULL)\n");
	PF = printf("PF: %c\n", (char)NULL);
	MY = ft_printf("MY: %c\n", (char)NULL);
	printf("PF: %d\n", PF);
	printf("MY: %d\n", MY);

	printf("------------------\n");

	printf("[INSUFFICIENT ARGUMENTS]\n");
	printf("INPUT : (\"%%d %%d\", 42)\n");
	PF = printf("PF: %d %d\n", 42);
	MY = ft_printf("MY: %d %d\n", 42);
	printf("PF: %d\n", PF);
	printf("MY: %d\n", MY);

	printf("------------------\n");

	printf("[EXTRA ARGUMENTS]\n");
	printf("INPUT : (\"%%d %%d\", 42, 42, 42)\n");
	PF = printf("PF: %d %d\n", 42, 42, 42);
	MY = ft_printf("MY: %d %d\n", 42, 42, 42);
	printf("PF: %d\n", PF);
	printf("MY: %d\n", MY);

	printf("------------------\n");

	printf("[ARGUMENT AND FORMAT DO NOT MATCH]\n");
	printf("INPUT : (\"%%d %%d\", 42, \"42\")\n");
	PF = printf("PF: %d %d\n", 42, "42");
	MY = ft_printf("MY: %d %d\n", 42, "42");
	printf("PF: %d\n", PF);
	printf("MY: %d\n", MY);

	printf("------------------\n");

	printf("[INT_MAX, INT_MIN]\n");
	printf("INPUT : (\"%%d %%d\", INT_MAX, INT_MIN)\n");
	PF = printf("PF: %d %d\n", INT_MAX, INT_MIN);
	MY = ft_printf("MY: %d %d\n", INT_MAX, INT_MIN);
	printf("PF: %d\n", PF);
	printf("MY: %d\n", MY);

	printf("------------------\n");

	printf("UNSIGNED INT MAX\n");
	printf("INPUT : (\"%%u\", UINT_MAX)\n");
	PF = printf("PF: %u\n", UINT_MAX);
	MY = ft_printf("MY: %u\n", UINT_MAX);
	printf("PF: %d\n", PF);
	printf("MY: %d\n", MY);

	printf("------------------\n");

	printf("[NEGATIVE INTEGER]\n");
	printf("INPUT : (\"%%i\", -42)\n");
	PF = printf("PF: %i\n", -42);
	MY = ft_printf("MY: %i\n", -42);
	printf("PF: %d\n", PF);
	printf("MY: %d\n", MY);

	printf("------------------\n");

	printf("[PRINT %%]\n");
	printf("INPUT : (\"%%%%%%%%\")\n");
	PF = printf("PF: %%%%%%%%\n");
	MY = ft_printf("MY: %%%%%%%%\n");
	printf("PF: %d\n", PF);
	printf("MY: %d\n", MY);

	printf("------------------\n");
	
	printf("[HEX LOWERCASE]\n");
	printf("INPUT : (\"%%x\", 42)\n");
	PF = printf("PF: %x\n", 42);
	MY = ft_printf("MY: %x\n", 42);
	printf("PF: %d\n", PF);
	printf("MY: %d\n", MY);

	printf("------------------\n");

	printf("[HEX UPPERCASE]\n");
	printf("INPUT : (\"%%X\", 42)\n");
	PF = printf("PF: %X\n", 42);
	MY = ft_printf("MY: %X\n", 42);
	printf("PF: %d\n", PF);
	printf("MY: %d\n", MY);

	printf("------------------\n");

	char long_str[1000];
	for (int i = 0; i < 999; i++) {
		long_str[i] = 'A';
	}
	long_str[999] = '\0';
	
	printf("[LONG STR]\n");
	printf("INPUT : (\"%%s\", \"AAAAAAAAAAAA....A\")\n");
	PF = printf("PF: %s\n", long_str);
	MY = ft_printf("MY: %s\n", long_str);
	printf("PF: %d\n", PF);
	printf("MY: %d\n", MY);

	printf("------------------\n");

	char c = 'A';
	char *str = "Hello, 42!";
	int d = 123;
	unsigned int u = 456;
	unsigned int x = 0xabc;
	unsigned int X = 0xDEF;
	void *p = NULL;

	printf("[MIXED FORMAT]\n");
	printf("INPUT : (\"Char: %%c, String: %%s, Pointer: %%p, Decimal: %%d, Unsigned: %%u, Hex (lower): %%x, Hex (upper): %%X, Percent: %%\", c, str, p, d, u, x, X)\n");
	PF = printf("Char: %c, String: %s, Pointer: %p, Decimal: %d, Unsigned: %u, Hex (lower): %x, Hex (upper): %X, Percent: %%\n", c, str, p, d, u, x, X);
	MY = ft_printf("Char: %c, String: %s, Pointer: %p, Decimal: %d, Unsigned: %u, Hex (lower): %x, Hex (upper): %X, Percent: %%\n", c, str, p, d, u, x, X);
	printf("PF: %d\n", PF);
	printf("MY: %d\n", MY);

	printf("-----------------\n");
	printf("TESTING COMPLETED\n");
	printf("-----------------\n");

	return (0);
}
