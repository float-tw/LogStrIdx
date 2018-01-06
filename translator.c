#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/io.h>
#include <sys/mman.h>

int main(int argc, char *argv[])
{
	unsigned char *f;
	int size;
	struct stat s;
	const char * file_name = "log_text_section";
	int fd = open (file_name, O_RDONLY);
	int base = (int)strtol(argv[1], NULL, 16);
	int offset;
	char input[32];

	/* Get the size of the file. */
	int status = fstat (fd, &s);
	size = s.st_size;

	f = (char *) mmap (0, size, PROT_READ, MAP_PRIVATE, fd, 0);

	while(fgets(input, sizeof(input), stdin)) {
		if (strncmp("format: ", input, 8) != 0) {
			if (strncmp("argc: ", input, 5) != 0) {
				strtok(input, "\n");
				printf(", %s", &input[6]);
			}
			continue;
		}
		offset = (int)strtol(input + 8, NULL, 16) - base;
		printf("\nprintf \"%s\\n\"", f + offset);
	}
	printf("\n");

	return 0;
}
