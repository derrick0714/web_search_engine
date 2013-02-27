#include "generating.h"
#include "parser/parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
using namespace std;

int main( char /* **argv */, int/* argc */)
{
	char *page;
	char *pool;
	FILE *fd;
	int len;
	int ret;
	char url[] = "http://cis.poly.edu/cs912/";



	fd = fopen("data/sample.html", "r");
	if (fd == NULL)
	{
		printf("can not be opened!\n");
		exit(1);
	}

	fseek(fd, 0, SEEK_END);
	len = ftell(fd);
	fseek(fd, 0, SEEK_SET);

	page = (char*)malloc(len);
	fread(page, 1, len, fd);
	fclose(fd);
	pool = (char*)malloc(2*len+1);

	// parsing page
	ret = parser(url, page, pool, 2*len+1);

	// output words and their contexts
	if (ret > 0)
		printf("%s", pool);

	free(pool);
	free(page);
	return 0;
}

