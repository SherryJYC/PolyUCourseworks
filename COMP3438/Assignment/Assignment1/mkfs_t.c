#include "header.h"

int init_super_block() {
    SuperBlock* sb = (SuperBlock*) malloc(sizeof(SuperBlock));
    sb->inode_offset = INODE_OFFSET;
    sb->data_offset = DATA_OFFSET;
    sb->max_inode = MAX_INODE;
    sb->max_data_blk = MAX_DATA_BLK;
    sb->next_available_inode = 0;
    sb->next_available_blk = DATA_OFFSET;
    sb->blk_size = BLOCK_SIZE;
    
    write_by_offset(0, sizeof(SuperBlock), sb);
    free(sb);
    return 0;
}

int mkfs_t(const char* filename) {
    hd = open(filename, O_RDWR);

    struct stat stat;
    fstat(hd, &stat);
	int size = (int)stat.st_size;

    char* empty = (char*)malloc(size);
    close(hd);

    hd = open(filename, O_RDWR | O_TRUNC);
    write_by_offset(0, size, empty);

    if (hd == -1) {
        printf("mkfs_t: the file does not exist: %s\n", filename);
        return -1;
    }
	
    init_super_block();

    *cwd_number = -1;
    mkdir_t("");
    *cwd_number = 0;

	printf("mkfs_t: successfully built SFS!\n");

    close(hd);

    return 0;
}