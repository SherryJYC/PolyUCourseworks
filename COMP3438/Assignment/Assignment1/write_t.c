#include "header.h"

int write_t(int inode_number, int offset, void *buf, int count) {
    //printf("In write_t()\n");
    //printf("count is: %i\n", count);
    //1. write new file
    //1.1 set new inode, except direct/indirect_blk
    INode* i_node = get_inode(inode_number);
    i_node->i_size = count;
    i_node->i_blocks = count / 4096 + 1 < MAX_DATA_BLK ? count / 4096 +  1 : MAX_DATA_BLK;

    //1.2 write data & set (in/)direct_blk
    unsigned int allocated_blk = 0;
    int remained = count;
    if (offset == DEFAULT)
        offset = get_ava_block();
    
    int* indirect_blok = (int*)malloc(BLOCK_SIZE);
    while (remained > 0 && allocated_blk < (2 + BLOCK_SIZE / sizeof(int))) {
        if ((offset - DATA_OFFSET) / 4096 > MAX_DATA_BLK) {
            printf("write_t: the file system is full!\n");
            break;
        }		
    	if (allocated_blk == 0) {
            i_node->direct_blk[0] = offset;
        } else if(allocated_blk == 1) {
            i_node->direct_blk[1] = offset;
        } else if(allocated_blk == 2) {
            i_node->indirect_blk = offset;
            offset += BLOCK_SIZE;
        }
        if (allocated_blk >= 2) {
            indirect_blok[allocated_blk - 2] = offset;
        }
        int size_to_write = remained < BLOCK_SIZE ? remained : BLOCK_SIZE;
        
    	write_by_offset(offset, size_to_write, buf);
        remained -= size_to_write;
        allocated_blk++;
        offset += BLOCK_SIZE;
    }
    //1.3 write indirect_blk
    if (allocated_blk >= 2) {
        write_by_offset(i_node->indirect_blk, BLOCK_SIZE, indirect_blok);
    }
    //1.4 write inode
    set_inode(i_node);     

    //3 update superblock
    update_superblock(DEFAULT, offset);

    free(i_node);
    free(indirect_blok);
    return count;
}

