#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/mman.h>

#define SB_OFFSET 4096 /* The offset of superblock region*/
#define INODE_OFFSET 8192 /* The offset of inode region */
#define DATA_OFFSET 8388608 /* The offset of data region */
#define MAX_INODE 170 /* The maximum number of inodes */
#define MAX_DATA_BLK 20480 /* The maximum number of blocks */
#define BLOCK_SIZE 4096 /* The size per block */
#define MAX_NESTING_DIR 10 /* The nesting number of directory */
#define MAX_COMMAND_LENGTH 50 /* The maximum command length */

#define MAX_ABS_DIR 121 /*10 directory name + 11 "/" + 1 file name*/
#define MAX_FILE_NAME 10
#define MAX_FILE_SIZE 4202496

#define FALSE 0
#define TRUE 1
#define ERROR -1
#define DEFAULT -1

typedef struct superblock /*The key information of filesystem */
{
    int inode_offset; /* The start offset of the inode region */
    int data_offset; /* The start offset of the data region */
    int max_inode; /* The maximum number of inodes */
    int max_data_blk; /* The maximum number of data blocks */
    int next_available_inode; /* The index of the next free inode */
    int next_available_blk; /* The index of the next free block */
    int blk_size; /* The size per block */
}SuperBlock;

typedef struct inode /* The structure of inode, each file has only one inode */
{
    int i_number; /* The inode number */
    time_t i_mtime; /* Creation time of inode*/
    int i_type; /* Regular file for 1, directory file for 0 */
    int i_size; /* The size of file */
    int i_blocks; /* The total numbers of data blocks */
    int direct_blk[2]; /*Two direct data block pointers */
    int indirect_blk; /*One indirect data block pointer */
    int file_num; /* The number of file in directory, it is 0 if it is file*/
}INode;

typedef struct dir_mapping /* Record file information in directory file */
{
    char dir[10]; /* The file name in current directory */
    int inode_number; /* The corresponding inode number */
}DirMapping;

//mkdir_t.c
int mkfs_t();
int init_boot();
int init_super_block();
int init_inode();
int init_blocks();

//open_t_c
int open_t(const char* pathname, int flags);

//ls_t.c
int ls_t();

//read_t.c
int read_t(int inode_number, int offset, void *buf, int count);

//write_f.c
int write_t(int inode_number, int offset, void *buf, int count);

//mkdir.t.c
int mkdir_t(const char* d_name);

//cp_t.c
int cp_t(char* sour, char* dest_dir);

//cd_t.c
int cd_t(char* path);

//external_cp_t.c
int external_cp(char* sour, char* dest_dir);

//cat_t.c
int cat_t(const char* path);

//mkfs_t.c
int init_super_block();
int mkfs_t(const char* filename);

//utils.c
SuperBlock* get_superblock();
int get_ava_inode();
int get_ava_block();
int update_superblock(int ava_inode, int ava_block);
int cal_inode_offset(int inode_number);
DirMapping* get_dir_mapping(int i_number);
INode* get_inode(int i_number);
void set_inode(INode* i_node);
int write_by_offset(int offset, int size_to_write, void* buf);
int read_by_offset(int offset, int size_to_read, void* buf);
char** str_split(char* a_str, const char a_delim);
int get_size(int i_number);
void my_strncpy(char* dest, const char* sour);
int starts_with(const char *pre, const char *str);
void clean_stdin(void);

//global variable
extern int hd;
extern int *cwd_number;
extern char* cwd_path;

#endif