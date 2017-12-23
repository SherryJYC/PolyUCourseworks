#include "header.h"

int cd_t(char* path) {
    int c_number = open_t(path, 2);
    if (c_number == ERROR) {
        return -1;
    }
	*cwd_number = c_number;

	if (c_number == 0)
		my_strncpy(cwd_path, "");
	else
		my_strncpy(cwd_path, path);
	return 0;
}