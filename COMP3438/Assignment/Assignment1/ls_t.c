#include "header.h"

int ls_t() {
    INode* i_node = get_inode(*cwd_number);
    int i_size = i_node->i_size;
    int file_num = i_node->file_num;
    DirMapping* buf = (DirMapping*)malloc(i_size);
    read_t(*cwd_number, DEFAULT, buf, DEFAULT);
    free(i_node);
	printf("| Inode Number | Creation Time | Type | Size |\n");
    int i;
    for (i = 2; i < file_num; i++) {
        i_node = get_inode(buf[i].inode_number);
        printf("| %i | %i | %i | %i |\n", i_node->i_number, (int)i_node->i_mtime, i_node->i_type, i_node->i_size);
        free(i_node);
    }

    free(buf);
    return 0;
}