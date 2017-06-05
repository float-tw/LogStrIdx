#include <stdio.h>

#define Mlog(str) {__attribute__ ((__section__ (".log.text"))) static const char log_string[] = str;mlog(log_string);}

char a[] = "test_a";

void mlog(const char *str)
{
	printf("%p\n", str);
}

int main()
{
	Mlog("test");
	Mlog("test2");

	return 0;
}
