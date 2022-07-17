#define _CRT_SECURE_NO_WARNINGS 1

/*�������Ϊָ���ļ���һ��ָ��
FILE * fopen ( const char * filename, const char * mode )�����ļ�
int fputs ( const char * str, FILE * stream )��дһ���ַ��������׼�������Ļ�ȣ���ȥ
int fputc ( int character, FILE * stream )��дһ���ַ��������׼�������Ļ�ȣ���ȥ
int fgetc ( FILE * stream )�����������׼���루���̵ȣ��ж�ȡһ���ַ�
char * fgets ( char * str, int num, FILE * stream )���������׼���루���̵ȣ��ж�ȡһ���ַ���num������ַ���
int fprintf ( FILE * stream, const char * format, ... )����ʽ��������ݣ����ڴ浽�ļ���
int fscanf ( FILE * stream, const char * format, ... )����ʽ���������ݣ����ļ����ڴ棩
size_t fwrite ( const void * ptr, size_t size, size_t count, FILE * stream )��������д������
size_t fread ( void * ptr, size_t size, size_t count, FILE * stream )�������ж�ȡ���ݵ�ptrָ���λ��
int fseek ( FILE * stream, long int offset, int origin )����λ�ļ�ָ��
void rewind ( FILE * stream )�����ļ�ָ��ص���ʼλ��

int feof ( FILE * stream )���ļ���ȡ����ʱ���ж��Ƕ�ȡʧ�ܽ������������ļ�β����
�����������ļ�ĩβ��������EOF�����ط� 0 ֵ�����򷵻�0

int ferror ( FILE * stream )���������ϳ��ֵĴ����д��ط�0���޴���0

long int ftell ( FILE * stream )�������ʼλ�õ�ƫ����
offset��ƫ����
origin��
SEEK_SET    Beginning of file
SEEK_CUR	Current position of the file pointer
SEEK_END	End of file *

int fclose ( FILE * stream )���ر��ļ�
*/

#include <stdio.h>
#include <string.h>
#include <errno.h>

struct Stu
{
	char name[20];
	int age;
};

int main()
{
	//����fputc
	//FILE* pf = fopen("test.txt", "w");
	//if (pf == NULL)
	//{
	//	printf("%s\n", strerror(errno));
	//	return 0;
	//}
	//fputc('h', pf);
	//fputc('e', pf);
	//fputc('l', pf);
	//fputc('l', pf);
	//fputc('o', pf);
	//fclose(pf);
	//pf = NULL;


	//����fputs
	//FILE* pf = fopen("test.txt", "w");
	//if (pf == NULL)
	//{
	//	printf("%s\n", strerror(errno));
	//	return 0;
	//}
	//char* str = "hello world";
	//fputs(str, pf);
	//fclose(pf);
	//pf = NULL;

	//����fgetc
	/*char buf[1024] = { 0 };
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	char ch;
	ch = fgetc(pf);
	printf("%c", ch);
	ch = fgetc(pf);
	printf("%c", ch);
	fclose(pf);
	pf = NULL;*/


	//����fgets
	/*
	char buf[1024] = { 0 };
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	fgets(buf, 1024, pf);
	printf("%s", buf);
	fclose(pf);
	pf = NULL;
	*/

	//����fprintf
	/*
	FILE* pf = fopen("test.txt", "w");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	struct Stu s = { "xiaoming",15 };
	fprintf(pf, "%s %d", s.name, s.age);
	fclose(pf);
	pf = NULL;
	*/

	//����fscanf
	/*FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	struct Stu s = { 0 };
	fscanf(pf, "%s %d", s.name, &(s.age));
	printf("%s %d", s.name, s.age);
	fclose(pf);
	pf = NULL;*/

	//����fwrite
	//FILE* pf = fopen("test.txt", "wb");   //�Զ�������ʽд���ļ���
	//if (pf == NULL)
	//{
	//	printf("%s\n", strerror(errno));
	//	return 0;
	//}
	//struct Stu s = { "zhangsan",20 };
	//fwrite(&s, sizeof(struct Stu), 1, pf);
	//fclose(pf);
	//pf = NULL;

	//����fread
	/*
	FILE* pf = fopen("test.txt", "rb");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	struct Stu s = { 0 };
	fread(&s, sizeof(struct Stu), 1, pf);
	printf("%s %d", s.name, s.age);
	fclose(pf);
	pf = NULL;
	*/

	//����fseek��ftell��rewind
	//FILE* pf = fopen("test.txt", "r");   //�ļ��洢abcde��pfָ��a
	//if (pf == NULL)
	//{
	//	printf("%s\n", strerror(errno));
	//	return 0;
	//}
	//fseek(pf, 2, SEEK_SET);            //����ʼλ������ƫ��2���ֽڣ�pfָ��c
	//int pos = ftell(pf);               //posΪpf�����ʼλ�õ�ƫ������pos=2
	//int c = fgetc(pf);                 //��ȡ�ַ�c
	//printf("%d %c\n", pos, c);
	//rewind(pf);                        //ʹpf����ָ����ʼλ�ã���pfָ��a
	//printf("%c\n", fgetc(pf));         
	//fclose(pf);
	//pf = NULL;

    //����ferror��feof
	FILE* pf = fopen("test.txt", "r");   //�ļ��洢abcde
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	char c;
	while ((c = fgetc(pf)) != EOF)       //��ȡ�ַ�ֱ���ļ�ĩβ��EOF��
	{
		putchar(c);                      //��ӡ�ַ�
	}
	printf("\n");
	if (ferror(pf))                      //����ڲ������Ĺ����������������ӡerror in stream
	{
		puts("error in stream.\n");
	}
	else if (feof(pf))
	{
		puts("end of file.\n");          //����ļ�������ȡ����������EOF�������ӡend of file
	}
	fclose(pf);
	pf = NULL;
	return 0;
}