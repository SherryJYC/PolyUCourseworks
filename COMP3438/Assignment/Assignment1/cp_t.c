#include "header.h"

int cp_t(char* sour, char* dest_dir) {
    int i_number = open_t(sour, 2);
	if (i_number == ERROR) {
		return -1;
	}
	void* buf = (void*)malloc(get_size(i_number));
    read_t(i_number, DEFAULT, buf, DEFAULT);
    int f_number = open_t(dest_dir, 0);
	if (f_number == ERROR) {
		return -1;
	}
    write_t(f_number, DEFAULT, buf, get_size(i_number));
    return 0;
}