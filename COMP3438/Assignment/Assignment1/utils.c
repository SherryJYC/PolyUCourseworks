#include "header.h"

SuperBlock* get_superblock() {
    lseek(hd ,SB_OFFSET, SEEK_SET);
    SuperBlock* sb = (SuperBlock*)malloc(sizeof(SuperBlock));
    read(hd, sb, sizeof(SuperBlock));
    return sb;
}

int get_ava_inode() {
    SuperBlock* sb = get_superblock();
    int ava_i_number = sb->next_available_inode;
    free(sb);
    return ava_i_number;
}

int get_ava_block() {
    SuperBlock* sb = get_superblock();
    int ava_blk = sb->next_available_blk;
    free(sb);
    return ava_blk;
}

INode* get_inode(int i_number) {
    INode* nd = (INode*)malloc(sizeof(INode));
    lseek(hd, cal_inode_offset(i_number), SEEK_SET);
    read(hd, nd, sizeof(INode));
    return nd;
}

void set_inode(INode* i_node) {
    lseek(hd, cal_inode_offset(i_node->i_number), SEEK_SET);
    write(hd, i_node, sizeof(INode));
}

int get_size(int i_number) {
    INode* i_node = get_inode(i_number);
    int size = i_node->i_size;
    free(i_node);
    return size;
}

int update_superblock(int ava_inode, int ava_block) {
    SuperBlock* sb = get_superblock();
    if (ava_inode != DEFAULT)
        sb->next_available_inode = ava_inode;
    if (ava_block != DEFAULT)
        sb->next_available_blk = ava_block;
	if (sb->next_available_inode > MAX_INODE)
		sb->next_available_inode = -1;
    write_by_offset(SB_OFFSET, sizeof(SuperBlock), sb);
    free(sb);
    return 0;
}

int cal_inode_offset(int inode_number) {
    return INODE_OFFSET + (int)sizeof(INode) * inode_number;
}

int write_by_offset(int offset, int size_to_write, void* buf) {
    lseek(hd, offset, SEEK_SET);
    write(hd, buf, size_to_write);
    return 0;
}

int read_by_offset(int offset, int size_to_read, void* buf) {
    lseek(hd, offset, SEEK_SET);
    read(hd, buf, size_to_read);
	return 0;
}

char** str_split(char* a_str, const char a_delim)
{
    char** result;
    size_t count = 0;
    char* tmp = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
    knows where the list of returned strings ends. */
    count++;

    result = (char**)malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        *(result + idx) = 0;
    }

    return result;
}

void my_strncpy(char* dest, const char* sour) {
    strncpy(dest, sour, strnlen(sour, MAX_ABS_DIR));
    dest[strnlen(sour, MAX_ABS_DIR)] = '\0';
}

void clean_stdin()
{
	int c;
	do {
		c = getchar();
	} while (c != '\n' && c != EOF);
}