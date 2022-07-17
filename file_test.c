#define _CRT_SECURE_NO_WARNINGS 1

/*这里的流为指向文件的一个指针
FILE * fopen ( const char * filename, const char * mode )：打开文件
int fputs ( const char * str, FILE * stream )：写一行字符到流或标准输出（屏幕等）中去
int fputc ( int character, FILE * stream )：写一个字符到流或标准输出（屏幕等）中去
int fgetc ( FILE * stream )：：从流或标准输入（键盘等）中读取一个字符
char * fgets ( char * str, int num, FILE * stream )：从流或标准输入（键盘等）中读取一行字符，num是最大字符数
int fprintf ( FILE * stream, const char * format, ... )：格式化输出数据（从内存到文件）
int fscanf ( FILE * stream, const char * format, ... )：格式化输入数据（从文件到内存）
size_t fwrite ( const void * ptr, size_t size, size_t count, FILE * stream )：将数据写到流中
size_t fread ( void * ptr, size_t size, size_t count, FILE * stream )：从流中读取数据到ptr指向的位置
int fseek ( FILE * stream, long int offset, int origin )：定位文件指针
void rewind ( FILE * stream )：让文件指针回到起始位置

int feof ( FILE * stream )：文件读取结束时，判断是读取失败结束还是遇到文件尾结束
若正常读到文件末尾（即遇到EOF）返回非 0 值，否则返回0

int ferror ( FILE * stream )：测试流上出现的错误，有错返回非0，无错返回0

long int ftell ( FILE * stream )：相对起始位置的偏移量
offset：偏移量
origin：
SEEK_SET    Beginning of file
SEEK_CUR	Current position of the file pointer
SEEK_END	End of file *

int fclose ( FILE * stream )：关闭文件
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
	//测试fputc
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


	//测试fputs
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

	//测试fgetc
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


	//测试fgets
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

	//测试fprintf
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

	//测试fscanf
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

	//测试fwrite
	//FILE* pf = fopen("test.txt", "wb");   //以二进制形式写到文件中
	//if (pf == NULL)
	//{
	//	printf("%s\n", strerror(errno));
	//	return 0;
	//}
	//struct Stu s = { "zhangsan",20 };
	//fwrite(&s, sizeof(struct Stu), 1, pf);
	//fclose(pf);
	//pf = NULL;

	//测试fread
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

	//测试fseek与ftell与rewind
	//FILE* pf = fopen("test.txt", "r");   //文件存储abcde，pf指向a
	//if (pf == NULL)
	//{
	//	printf("%s\n", strerror(errno));
	//	return 0;
	//}
	//fseek(pf, 2, SEEK_SET);            //从起始位置向右偏移2个字节，pf指向c
	//int pos = ftell(pf);               //pos为pf相对起始位置的偏移量，pos=2
	//int c = fgetc(pf);                 //读取字符c
	//printf("%d %c\n", pos, c);
	//rewind(pf);                        //使pf重新指向起始位置，即pf指向a
	//printf("%c\n", fgetc(pf));         
	//fclose(pf);
	//pf = NULL;

    //测试ferror和feof
	FILE* pf = fopen("test.txt", "r");   //文件存储abcde
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	char c;
	while ((c = fgetc(pf)) != EOF)       //读取字符直到文件末尾（EOF）
	{
		putchar(c);                      //打印字符
	}
	printf("\n");
	if (ferror(pf))                      //如果在操作流的过程中遇到错误则打印error in stream
	{
		puts("error in stream.\n");
	}
	else if (feof(pf))
	{
		puts("end of file.\n");          //如果文件正常读取结束（遇到EOF），则打印end of file
	}
	fclose(pf);
	pf = NULL;
	return 0;
}