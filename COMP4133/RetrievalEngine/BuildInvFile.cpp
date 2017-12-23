
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "..//stem.h"
#include "..//IInvFile.h"

IInvFile InvFile;

int main()
{
	FILE * fpp = NULL;
	FILE * fpf = NULL;
	hnode * h;
	post * p;
	int count = 0;
	char tmp[10000];
	char sql[200];
	int wordcount;
	char term[200];
	char name[100];
	char * path = (char*)malloc(200 * sizeof(char*));
	int docid;
	int pos;

	// open file post and file
	fpp = fopen("..//post1.txt", "rb");
	if (!fpp) {
		printf("file post open fail!\n");
		system("pause");
		exit(0);
	}
	fpf = fopen("..//file.txt", "rb");
	if (!fpf) {
		printf("file file open fail!\n");
		system("pause");
		exit(0);
	}

	// convert table post to posting
	// only execute once to build table posting
	// operate in memory
	InvFile.MakeHashTable(13023973);
	
	while (fgets(tmp, 10000, fpp) != NULL) {
		// Get the stem, the document identifier and the location
		sscanf(tmp, "%s %d %d", &(term[0]), &docid, &pos);

		// Add posting into the Integrated Inverted index
		// See lecture notes on Implementation
		h = InvFile.FindNode(term);
		if (!h) {
			h = InvFile.MakeNode(term);
		}
		h->df++;
		p = InvFile.FindPost(h, docid);
		if (!p) {
			p = InvFile.AddPost(h, docid, 1);
		}
		else {
			p->freq++;
		}
		// Keep us informed about the progress
		count++;
		if ((count % 100000) == 0) printf("Added [%d]\r\n", count);
	}

	printf("Saving inverted file ...\r\n");
	InvFile.WriteInvFile("..//InvFile.txt");

    return 0;
}

