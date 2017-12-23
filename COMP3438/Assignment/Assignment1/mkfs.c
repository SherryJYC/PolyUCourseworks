#include "header.h"

int hd;
int *cwd_number;
char* cwd_path;

int main(int argc, char *argv[]) {

    cwd_number = (int*)malloc(sizeof(int));
    cwd_path = (char*)malloc(MAX_ABS_DIR);

	if (argc != 2) {
		printf("mkfs_t: invalid parameter number\n");
		return -1;
	}
	return mkfs_t(argv[1]);
}