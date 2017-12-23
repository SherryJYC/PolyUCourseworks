#include "header.h"

int mkdir_t(const char* d_name) {
    //initial information of ".." and "."
    DirMapping dir[2];
    const char* dir_name = "..";
    my_strncpy(dir[0].dir, dir_name);
    dir[0].inode_number = *cwd_number;
    dir_name = ".";
    my_strncpy(dir[1].dir, dir_name);

    char abs_path[MAX_ABS_DIR] = "";
    my_strncpy(abs_path, cwd_path);
    if (*cwd_number != -1) 
        strncat(abs_path, "/", strnlen("/", MAX_ABS_DIR));
    strncat(abs_path, d_name, strnlen(d_name, MAX_FILE_NAME));
    int i_number = open_t(abs_path, 1);
    if (i_number == ERROR) {
        return ERROR;
    }
	dir[1].inode_number = i_number;
    write_t(i_number, DEFAULT, dir, sizeof(dir));

    return 0;
}

