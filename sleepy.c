/*
영어로 되어 있는 FILE명을 명령행 인수로 받아 읽어서
 Eclass에 올려논 파일: OSParadigmShift.txt을 사용
 Line count, word count, character count를 화면에 출력하고
 대문자는 소문자로, 소문자는 대문자로 변환하여 동일한 FILE명에 extension을 rev로 바꾼 파일에 저장하고, 저장했다는 message를 화면에 출력한다
 저장된 --.rev 파일의 내용을 확인한다

예를 들어
 Myprog infile.txt				를 입력하면
 <Count Result>
 Line count:			25
 Word count:		   134
 Character count:      568		가 화면에 출력되고
 File Saved in infilee.rev       가 화면에 출력되고
                                대소문자 변환도니 내용이
								infile.rev 에 저장후 확인
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
