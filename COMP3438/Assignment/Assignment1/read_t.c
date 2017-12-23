#include "header.h"

int read_t(int inode_number, int offset, void *buf, int count) {
	//printf("In read_t() for inode: %i\n", inode_number);
    INode* i_node;
    i_node = get_inode(inode_number);
    
    int readed = 0;
    int remained = count == DEFAULT ? i_node->i_size : count;
    int readed_blk = 0;
    int cur_offset = offset == DEFAULT ? i_node->direct_blk[0] : offset;
    
	//printf("Offset to readed:%i   size to read:%i\n", i_node->direct_blk[0], remained);
    while(remained > 0) {
        if (readed_blk == 2) {
            cur_offset += BLOCK_SIZE;
        }                   
        int size_to_read = remained < BLOCK_SIZE ? remained : BLOCK_SIZE;
		//printf("cur_offset:%i, size_to_read:%i\n", cur_offset, size_to_read);
        read_by_offset(cur_offset, size_to_read, (char*)buf + readed);
        readed += size_to_read;
        remained -= BLOCK_SIZE;
        readed_blk++;
        cur_offset += BLOCK_SIZE;
    }
	//printf("Finish reading\n");
	int size = i_node->i_size;
    free(i_node);
    return size;
}
