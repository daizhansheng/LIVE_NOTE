#include <stdio.h>

int strlen(char *src)
{
	int ret = 0;

	if(src == NULL){
		printf("args error\n");
		return -1;
	}
	//hello'\0'
	while(src[ret])ret++;

	return ret;
}

char *strstr(char *src,char *sub)
{
	char *p = src,*q = sub;

	if(src == NULL || sub == NULL){
		printf("please check args\n");
		return NULL;
	}
	
	if(strlen(src)<strlen(sub)) return NULL;
	
	while(*src){
		p = src;
		q = sub;
		while(*p && *q && *p++ == *q++);
		if(*(--p) == *(--q) && *(++q) == '\0')return src;	
		p = ++src;
	}
	
	return NULL;

}

int main(int argc, const char *argv[])
{
	char *retval;
	char a[100] = {0};//"hello world"
	char b[50]  = {0};//"hello"

	printf("please input a[100] > ");
	scanf("%[^\n]",a);
	getchar();
	printf("please input b[50] > ");
	scanf("%[^\n]",b);

	retval = strstr(a,b);
	if(retval == NULL){
		printf("no found sub string\n");
		return -1;
	}

	printf("retval = %s\n",retval);

	return 0;
}
