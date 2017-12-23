#include "header.h"

int cat_t(const char* path) {
    int i_number = open_t(path, 2);
	if (i_number == ERROR) {
		return -1;
	}
    char* buf = (char*)malloc(get_size(i_number));
	//printf("Before reading %i data\n", get_size(i_number));
    read_t(i_number, DEFAULT, buf, DEFAULT);
	//printf("Before printing...\n");
    printf("%s", buf);
	free(buf);
    return 0;
}