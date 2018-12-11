/*
����� �Ǿ� �ִ� FILE���� ����� �μ��� �޾� �о
 Eclass�� �÷��� ����: OSParadigmShift.txt�� ���
 Line count, word count, character count�� ȭ�鿡 ����ϰ�
 �빮�ڴ� �ҹ��ڷ�, �ҹ��ڴ� �빮�ڷ� ��ȯ�Ͽ� ������ FILE�� extension�� rev�� �ٲ� ���Ͽ� �����ϰ�, �����ߴٴ� message�� ȭ�鿡 ����Ѵ�
 ����� --.rev ������ ������ Ȯ���Ѵ�

���� ���
 Myprog infile.txt				�� �Է��ϸ�
 <Count Result>
 Line count:			25
 Word count:		   134
 Character count:      568		�� ȭ�鿡 ��µǰ�
 File Saved in infilee.rev       �� ȭ�鿡 ��µǰ�
                                ��ҹ��� ��ȯ���� ������
								infile.rev �� ������ Ȯ��
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calc(FILE *f, FILE *f2);

int main(int argc, char* argv[])
{
	FILE *f, *f2;
	char c[50];
	
	int n = strlen(argv[argc - 1]);
	n -= 4;
	strncpy(c, argv[argc - 1], n);
	strcat(c, ".rev");
	
	if((f = fopen(argv[argc - 1], "r")) == NULL)
	{
		printf("ERROR READING %s\n", argv[argc - 1]);
		exit(1);
	}
	
	if((f2 = fopen(c, "w")) == NULL)
	{
		printf("ERROR WRITING %s\n", c);
		exit(1);
	}
	
	printf("<Count Result>\n");
	calc(f, f2);
	printf("File saved in %s\n", c);
	
	system("pause");
	return 1;
}

void calc(FILE *f, FILE *f2)
{
	int line = 0, word = 0, character = 0;
	char c;
	
	while(!feof(f))
	{
		c = fgetc(f);
		character ++;
		if(c == '\n')
		{
			line++;
		}
		
		if(c == ' ')
		{
			word++;
		}
		
		fputc((c >= 65 && c <= 90) ? c + 32 : (c >= 97 && c <= 122) ? c - 32 : c, f2);
	}
	
	printf("Line count:             %4d\n", line);
	printf("Word count:             %4d\n", word);
	printf("Character count:        %4d\n", character);
}
