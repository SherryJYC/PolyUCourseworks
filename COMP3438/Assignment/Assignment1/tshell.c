#include "header.h"

//for testing

//global variable
int hd;
int *cwd_number;
char* cwd_path;

int main(int argc, char *argv[]) {
	printf("tshell: starting SFS......\n");

	cwd_number = (int*)mmap(NULL, sizeof *cwd_number, PROT_READ | PROT_WRITE,
		MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	cwd_path = (char*)mmap(NULL, MAX_ABS_DIR, PROT_READ | PROT_WRITE,
		MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    hd = open("HD", O_RDWR);

	if (hd < 0) {
		printf("tshell: HD doesn't exist.\n");
		return 0;
	}

	if (!get_ava_inode()) {
		printf("tshel: the file system has not been built! Building SFS automatically!\n");
		close(hd);
		mkfs_t("HD");
		hd = open("HD", O_RDWR);
		return 0;
	}

    *cwd_number = 0;
	my_strncpy(cwd_path, "");

	char* command = (char*)malloc(MAX_COMMAND_LENGTH + 1);
	size_t nbytes = MAX_COMMAND_LENGTH;
	pid_t pid;
	char** split_cammand;
	while (TRUE) {
		printf("\ntshell### %s$ ", cwd_path);

		getline(&command, &nbytes, stdin);
		strtok(command, "\n");
		split_cammand = str_split(command, ' ');

		if (strncmp("exit", split_cammand[0], MAX_COMMAND_LENGTH) == 0) {
			munmap(cwd_number, sizeof(*cwd_number));
			munmap(cwd_path, MAX_ABS_DIR);
			return 0;
		}

		pid = fork();
		if (pid == 0)
			break;
		int status;
		wait(&status);
	}


	if (strncmp("ls_t", split_cammand[0], MAX_COMMAND_LENGTH) == 0) {
		ls_t();
	}
	else if (strncmp("cd_t", split_cammand[0], MAX_COMMAND_LENGTH) == 0) {
		cd_t(split_cammand[1]);
	}
	else if (strncmp("mkdir_t", split_cammand[0], MAX_COMMAND_LENGTH) == 0) {
		mkdir_t(split_cammand[1]);
	}
	else if (strncmp("external_cp", split_cammand[0], MAX_COMMAND_LENGTH) == 0) {
		external_cp(split_cammand[1], split_cammand[2]);
	}
	else if (strncmp("cp_t", split_cammand[0], MAX_COMMAND_LENGTH) == 0) {
		cp_t(split_cammand[1], split_cammand[2]);
	}
	else if (strncmp("cat_t", split_cammand[0], MAX_COMMAND_LENGTH) == 0) {
		cat_t(split_cammand[1]);
	} 
	else if (strncmp("cwd", split_cammand[0], MAX_COMMAND_LENGTH) == 0) {
		printf("%i : %s\n", *cwd_number, cwd_path);
	}
	else {
		printf("tshell: command not found: %s\n", split_cammand[0]);
	}

	exit(0);
}