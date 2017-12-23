#include "header.h"

int external_cp(char* sour, char* dest_dir) {
    int i_number = open(sour, O_RDONLY);
	if (i_number <= 0) {
		printf("external_cp: error in opening %s\n", sour);
		return -1;
	}
    struct stat stat;
    fstat(i_number, &stat);
	int size_to_read = (int)stat.st_size;
	if (size_to_read > MAX_FILE_SIZE) {
		printf("external_cp: the file size: %i exceeds the maximum file size allowed. Only the first %i bytes will be copied.", size_to_read, MAX_FILE_SIZE);
		size_to_read = MAX_FILE_SIZE;
	}
    char* buf = (char*)malloc(size_to_read);
	read(i_number, buf, size_to_read);
    int f_number = open_t(dest_dir, 0);
	if (f_number == ERROR) {
		return -1;
	}
    write_t(f_number, DEFAULT, buf, size_to_read);
	free(buf);
    return 0;
}