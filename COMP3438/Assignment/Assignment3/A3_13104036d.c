#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

/* Some definitions */
#define MAXBUFSIZE  1000
#define Max_Token_Size 100

typedef enum {
	KEYWORD, COMMA, SEMOCOLON, ASSIGN, PERIOD, NUM, PLUS, MINUS,
	MUL, DIV, LBRACE, RBRACE, ID, ERROR, SKIP, FINISH
}TokenType;


/*----- The prototype of functions in this functions---*/
TokenType  get_next_token(void);
int scan(void);
void print_token(TokenType);
int fail(int);

/*--------------- The Global variables----------------*/
int  fd;			  /* File descriptor to the input file*/

char input_buf[MAXBUFSIZE];  /* Maximum buffer size */


char *start_pt;		/*The pointer pointing to the starting  position for
					the current token recongnizatioin*/

int forward;			  /*The distance from start_pt for the
						  current token recongnization*/
char token_val[Max_Token_Size];	  /* The token lexeme value*/


/*----------Function: print_token()--------------------
Print token based on definition and requirement
------------------------------------------------------*/
void print_token(TokenType token)
{
	switch (token) {
	case KEYWORD:
		printf("KEYWORD\t\t\t| %s\n", token_val);
		break;
	case COMMA:
		printf("COMMA\t\t\t| %s\n", token_val);
		break;
	case SEMOCOLON:
		printf("SEMICLON\t\t| %s\n", token_val);
		break;
	case ASSIGN:
		printf("ASSIGN\t\t\t| %s\n", token_val);
		break;
	case PERIOD:
		printf("PERIOD\t\t\t| %s\n", token_val);
		break;
	case NUM:
		printf("NUM\t\t\t| %s\n", token_val);
		break;
	case PLUS:
		printf("PLUS\t\t\t| %s\n", token_val);
		break;
	case MINUS:
		printf("MINUS\t\t\t| %s\n", token_val);
		break;
	case MUL:
		printf("MUL\t\t\t| %s\n", token_val);
		break;
	case DIV:
		printf("DIV\t\t\t| %s\n", token_val);
		break;
	case LBRACE:
		printf("LBRACE\t\t\t| %s\n", token_val);
		break;
	case RBRACE:
		printf("RBRACE\t\t\t| %s\n", token_val);
		break;
	default:
		printf("ID\t\t\t| %s\n", token_val);
		break;
	}
}

/*---------Function: fail()----------------------------
Based on the current state, to decide the next state
current state < 12, next state <- 12
else, next state = -1
-------------------------------------------------------*/
int fail(int cstate)
{
	int next_state = -1;
	forward = 0;

	if (cstate < 12)
		next_state = 12;

	return next_state;
}

/*--------Function: get_next_token()-----------------------
Return the next token.
Note: Return FINISH if normal finish;
Return ERROR if there is non-recongnizd a character
---------------------------------------------------------*/
TokenType  get_next_token()
{
	char c;
	int i;
	int current_state = 0;
	forward = 0;

	while (1) {
		c = start_pt[forward];
		//printf("|%c|\n", c);

		switch (current_state) {
		case 0:
			if (c == '\0') {
				return FINISH;
			}
			if (c == ',') {
				for (i = 0; i <= forward; i++)
					token_val[i] = start_pt[i];
				token_val[i] = '\0';
				return COMMA;
			}
			if (c == ';') {
				for (i = 0; i <= forward; i++)
					token_val[i] = start_pt[i];
				token_val[i] = '\0';
				return SEMOCOLON;
			}
			if (c == '=') {
				for (i = 0; i <= forward; i++)
					token_val[i] = start_pt[i];
				token_val[i] = '\0';
				return ASSIGN;
			}
			if (c == '.') {
				for (i = 0; i <= forward; i++)
					token_val[i] = start_pt[i];
				token_val[i] = '\0';
				return PERIOD;
			}
			if (c == '+') {
				for (i = 0; i <= forward; i++)
					token_val[i] = start_pt[i];
				token_val[i] = '\0';
				return PLUS;
			}
			if (c == '-') {
				for (i = 0; i <= forward; i++)
					token_val[i] = start_pt[i];
				token_val[i] = '\0';
				return MINUS;
			}
			if (c == '*') {
				for (i = 0; i <= forward; i++)
					token_val[i] = start_pt[i];
				token_val[i] = '\0';
				return MUL;
			}
			if (c == '/') {
				for (i = 0; i <= forward; i++)
					token_val[i] = start_pt[i];
				token_val[i] = '\0';
				return DIV;
			}
			if (c == '(') {
				for (i = 0; i <= forward; i++)
					token_val[i] = start_pt[i];
				token_val[i] = '\0';
				return LBRACE;
			}
			if (c == ')') {
				for (i = 0; i <= forward; i++)
					token_val[i] = start_pt[i];
				token_val[i] = '\0';
				return RBRACE;
			}
			if (c == 'v') {
				forward++;
				current_state = 1;
			}
			else if (c == 'b') {
				forward++;
				current_state = 2;
			}
			else if (c == 'e') {
				forward++;
				current_state = 3;
			}
			else if (c >= 48 && c <= 57) {
				forward++;
				current_state = 9;
			}
			else if (c == ' ' || c == '\n' || c == '\t') {
				return SKIP;
			}
			else {
				current_state = fail(current_state);
			}
			break;
		case 1:
			if (c == 'a') {
				forward++;
				current_state = 4;
			}
			else {
				current_state = fail(current_state);
			}
			break;
		case 2:
			if (c == 'e') {
				forward++;
				current_state = 5;
			}
			else {
				current_state = fail(current_state);
			}
			break;
		case 3:
			if (c == 'n') {
				forward++;
				current_state = 6;
			}
			else {
				current_state = fail(current_state);
			}
			break;
		case 4:
			if (c == 'r') {
				for (i = 0; i <= forward; i++)
					token_val[i] = start_pt[i];
				token_val[i] = '\0';
				return KEYWORD;
			}
			current_state = fail(current_state);
			break;
		case 5:
			if (c == 'g') {
				forward++;
				current_state = 7;
			}
			else {
				current_state = fail(current_state);
			}
			break;
		case 6:
			if (c == 'd') {
				for (i = 0; i <= forward; i++)
					token_val[i] = start_pt[i];
				token_val[i] = '\0';
				return KEYWORD;
			}
			current_state = fail(current_state);
			break;
		case 7:
			if (c == 'i') {
				forward++;
				current_state = 8;
			}
			else {
				current_state = fail(current_state);
			}
			break;
		case 8:
			if (c == 'n') {
				for (i = 0; i <= forward; i++)
					token_val[i] = start_pt[i];
				token_val[i] = '\0';
				return KEYWORD;
			}
			current_state = fail(current_state);
			break;
		case 9:
			if (c >= 48 && c <= 57) {
				forward++;
			}
			else if (c == '.') {
				forward++; 
				current_state = 10;
			}
			else {
				forward--;
				for (i = 0; i <= forward; i++)
					token_val[i] = start_pt[i];
				token_val[i] = '\0';
				return NUM;
			}
			break;
		case 10:
			if (c >= 48 && c <= 57) {
				forward++;
				current_state = 11;
			}
			else {
				current_state = fail(current_state);
			}
			break;
		case 11:
			if (c >= 48 && c <= 57) {
				forward++;
			}
			else {
				forward--;
				for (i = 0; i <= forward; i++)
					token_val[i] = start_pt[i];
				token_val[i] = '\0';
				return NUM;
			}
			break;
		case 12:
			if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
				forward++;
				current_state = 13;
			}
			else {
				current_state = fail(current_state);
			}
			break;
		case 13:
			if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57)) {
				forward++;
			}
			else {
				forward--;
				for (i = 0; i <= forward; i++)
					token_val[i] = start_pt[i];
				token_val[i] = '\0';
				return ID;
			}
			break;
		default:
			printf("Unrecognized character |%c| (should not occur)\n", c);
			return ERROR;
		}
	}
}

/*-------------Function: scan() ---------------------------
Get the return token and call print_token to print it
----------------------------------------------------------*/
int scan()
{
	TokenType ret;
	int rbytes;

	start_pt = input_buf;

	/* Read the input file into a buffer */
	/* Only consider the simple case when the buffer is big enough*/
	rbytes = read(fd, input_buf, MAXBUFSIZE);

	if (rbytes  < 0) {
		printf("Could not read from the file\n");
		close(fd);
		return -1;
	}
	if (rbytes == 0) {
		printf("The input file is empty.\n");
		close(fd);
		return -1;
	}

	input_buf[rbytes - 1] = '\0';  /*the file ends with \0*/

	printf("Token Name\t\t|Token Value \n");
	printf("--------------------------------------------\n");
	while ((ret = get_next_token()) != ERROR && ret != FINISH) {
		if (ret == SKIP) {
			start_pt += 1;
			continue;
		}
		print_token(ret);
		start_pt = start_pt + forward + 1;
	}

	if (ret == FINISH)
		printf("\nSucessfuly finish scan.\n");
	else
		printf("\nError: Non-recongnizable character in the input file.\n");

	close(fd);
	return 1;
}

int main(int argc, char *argv[])
{
	/* Check the number of input*/
	if (argc != 2) {
		printf("Usage: scan input_file \n");
		return -1;
	}

	/* Open the source fie*/
	if ((fd = open(argv[1], O_RDONLY)) < 0) {
		printf("Can not open the file (File_Name:%s).\n", argv[1]);
		return -1;
	}

	/* Process lexical analysis*/
	if (scan() > 0)
		return 1;
	return -1;
}