#include <stdio.h>
#include "string.h"

int my_strlen(char *c)
{
	int i=0;
	
	while(*(c+i) != '\0')
		{
		i++;
		}
	return i;
};
void mystrcpy(char *s,char *d)
{
	int i=0;
	while(*(s+i) != '\0')
		{
		if(*(s+i) != '\0')
			{
			*(d+i)=*(s+i);
			}
		i++;
		};
};
int mystrcmp (char *s, char *d)
{	
	int i=0;
	while((d[i]!='\0')&&(s[i]!='\0'))
	{
		if(s[i]<d[i])
			return -1;
		if(s[i]>d[i])
			return 1;
		i++;
	}
	if(s[i]<d[i])
		return -1;
	if(s[i]>d[i])
		return 1;
	
	return 0;};
int str2upper(char *s)
{	
	int i=0;
	while(s[i]!='\0')
	{
		if((s[i]>='a')&&(s[i]<='z'))
		{
			s[i]=s[i]-' ';
		}
	i++;
	}};
int str2lower_(char *s)
{	
	int i=0;
	while(s[i]!='\0')
	{
		if((s[i]>='A')&&(s[i]<='Z'))
		{
			s[i]=s[i]+' ';
		}
	i++;
	}
};

char *strdupl(char *s)
{		char *x;
		x=(char*)malloc(sizeof(char)*my_strlen(s));
		mystrcpy(s,x);
		return x;
};

int str_strip_numbers(char *s)
{
	int i=0;
	int y=0;
	
	while(*(s+i) != '\0')
		{
		if((*(s+i)>='0') && (*(s+i)<='9'))
			{
			while(*(s+y) != '\0')
				{
				*(s+y)=*(s+y+1);
				y++;
				};			
			};
		i++;
		y=i;
		};
	
	return i;
	
};
