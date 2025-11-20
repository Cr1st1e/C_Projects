#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>


typedef struct 
{
	int characters;
	int words;
	int sentences;
	int syllables;
	double readability;
}properties;


int getCharacterCount(const char[], const char, int);
int getNumberOfWords(const char string[], const char alphabet, int size);
int getNumberOfSentences(const char string[], const char* alphabet, int size);
char* reverseString(const char*, int);

int main(void)
{
	char string[] = "abcdefghijke";
	int size = (sizeof(string) / sizeof(string[0]));
	char* clone = reverseString(string, size);
	printf("reverse string %s \n", clone);
	char stops[] = { '.', ';', '!', '?' };
	char alphabet='e';
	int alphaCount = getCharacterCount(string, alphabet ,size-1);
	int wordCount = getNumberOfWords(string, ' ', size-1);
	int sentenceCount = getNumberOfSentences(string, stops, size-1);
	printf("alphabet count %d word count %d  sentence count  %d \n", alphaCount, wordCount, sentenceCount);
	//printf("reverse string %s", clone);
	free(clone);
}

int getCharacterCount(const char string[], const char alphabet,int size)
{
	int count=0;
	for (int i = 0;i < size;i++) 
	{
		if( string[i] == alphabet)
		{
			count++;
		}
	}
	return count;
}
int getNumberOfWords(const char string[], const char alphabet, int size)
{
	int count = getCharacterCount(string,alphabet,size);
	return count+1;
}

int getNumberOfSentences(const char string[], const char* alphabet, int size)
{
	int count = 0;
	for (int i = 0;i <= 3;i++)
	{
		count += getCharacterCount(string, alphabet[i], size);
	}
	return count;
}

char* reverseString(const char* string, int size)
{
	char* clone = (char*)malloc(size * sizeof(char));
	if (clone == NULL) {
		exit(EXIT_FAILURE);
	}
	int k = 0;
	for (int i = size-1;i >=1;i--) 
	{
	    clone[k] = string[i-1];
		k++;
	}
	clone[size-1] = '\0';
	return clone;
}
