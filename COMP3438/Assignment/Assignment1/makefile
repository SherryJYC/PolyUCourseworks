all: mkfs_t tshell

mkfs_t: cat_t.c cd_t.c cp_t.c external_cp.c ls_t.c mkdir_t.c mkfs.c open_t.c read_t.c utils.c write_t.c header.h mkfs_t.c
	gcc -o mkfs_t cat_t.c cd_t.c cp_t.c external_cp.c ls_t.c mkdir_t.c mkfs.c open_t.c read_t.c utils.c write_t.c mkfs_t.c

tshell: cat_t.c cd_t.c cp_t.c external_cp.c ls_t.c mkdir_t.c open_t.c read_t.c tshell.c utils.c write_t.c header.h mkfs_t.c
	gcc -o tshell cat_t.c cd_t.c cp_t.c external_cp.c ls_t.c mkdir_t.c open_t.c read_t.c tshell.c utils.c write_t.c mkfs_t.c