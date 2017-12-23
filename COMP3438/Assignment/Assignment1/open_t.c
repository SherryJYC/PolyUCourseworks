#include "header.h"

//flags:
//0:new file; 1:new dir; 2:existing
int open_t(const char* pathname, int flags) {
	if (strncmp("/", pathname, MAX_COMMAND_LENGTH) == 0)
		return 0;
    char temp[MAX_ABS_DIR] = "";
    my_strncpy(temp, pathname);
    char** names = str_split(temp, '/');

	int nesting = ((int) sizeof(names)) / ((int) sizeof(names[0]));
	if (nesting > MAX_NESTING_DIR) {
		printf("open_t: the maximum nesting directory is 10\n");
		return -1;
	}

    DirMapping* dm_info;
    INode* c_node;

    int c_number = 0;
    int is_found = FALSE;
    const char* c_file_name = "";
    int p_number;
    int offset;

    int i;
    for (i = 0; *(names + i); i++) {
        //printf("Searching for %s under inode %i\n", *(names + i), c_number);
        c_file_name = *(names + i);

        c_node = get_inode(c_number);
		dm_info = (DirMapping*)malloc(get_size(c_number));
        read_t(c_number, DEFAULT, dm_info, DEFAULT);

        is_found = FALSE;
        //printf("File number: %i\n", c_node->file_num);
        //printf("Reading %d DM file\n", get_size(c_number) / sizeof(DirMapping));
        for (offset = 0; offset < c_node->file_num; offset++) {
            //printf("Compare with |***%s***| |***%i***|...\n", dm_info[offset].dir, dm_info[offset].inode_number);
            if (strncmp(dm_info[offset].dir, *(names + i), 10) == 0) {
                c_number = dm_info[offset].inode_number;
                is_found = TRUE;
                break;
            }
        }

        free(c_node);
        free(dm_info);

		if (!is_found)
			break;
    }
	free(names);
    //existing file
    if (flags == 2) {
		//printf("Existing i_number: %i\n", c_number);
        if (!is_found) {
			printf("open_t: no such file or directory: %s\n", pathname);
			return ERROR;
		}
        return c_number;
    }

	if (is_found) {//replace 
		//printf("Found! Current i_number is %i\n", c_number);
		c_node = get_inode(c_number);
	} else {//create
        //printf("Not found!\n");
		if (offset + 1 < nesting) {
			printf("open_t: the distination directory doesn't exist: %s\n", pathname);
			return ERROR;
		}
        p_number = c_number;

        c_number = get_ava_inode();

		if (c_number < 0) {
			printf("open_t: no available inode remained. The file system is full.\n");
			return ERROR;
		}

        c_node = (INode*)malloc(sizeof(INode));
        update_superblock(c_number + 1, DEFAULT);

        if (p_number != -1) {
            //printf("Update parent directory of inode %i!\n", p_number);
            //2.1 get parent inode
            INode* p_node = get_inode(p_number);
            //printf("Old file num: %i\n", p_node->file_num);

            //2.2 check wheather duplicate
            int offset = p_node->direct_blk[0] + p_node->i_size;

            //2.3 write new file name in directory
            DirMapping* dm = (DirMapping*)malloc(sizeof(DirMapping));
            dm->inode_number = c_number;
            my_strncpy(dm->dir, c_file_name);
            write_by_offset(offset, sizeof(DirMapping), dm);

            //2.4 update parent inode if not duplicate
            p_node->i_size = p_node->i_size + (int)sizeof(DirMapping);
            p_node->file_num = p_node->file_num + 1;
            set_inode(p_node);
            //printf("New file num: %i\n", get_inode(p_number)->file_num);

            free(p_node);
            free(dm);
        }
    }

    c_node->i_number = c_number;
    c_node->i_mtime = time(0);
    c_node->i_type = flags == 0 ? 1 : 0;
    c_node->file_num = flags == 0 ? 0 : 2;
    c_node->i_size = flags == 0 ? 0 : 2 * (int)sizeof(DirMapping);

    set_inode(c_node);
    free(c_node);

	return c_number;
}