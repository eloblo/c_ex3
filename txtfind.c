#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE 256
#define WORD 30

int getLine(char *word, int len);
int findWord(char *line, char *word, int len, int wlen);
int getWord(char *word, int len);
int contains(char *word, char *sub, int len);

int main(){
	char w[WORD] = "\0";
	char l[2];
	while(*fgets(l,2,stdin) != '\n'){
		if(*l == ' '){
			fgets(l,2,stdin);
			break;
		}
		else{
			strcat(w,l);
		}
	}
	if(*l == 'a'){
		while(getLine(w,strlen(w)) == 0);
	}
	else if(*l == 'b'){
		while(getWord(w,strlen(w)) == 0);
	}
	else{
		printf("invalid option\n");
		return 0;
	}
	return 0;
}

int getLine(char *word, int len){
	char s[LINE] = "\0";
	char l[2];
	if(fgets(l,2,stdin) == NULL){
		return 1;
	}
	if(*l == '\n'){
		return 0;
	}
	strcat(s,l);
	while(fgets(l,2,stdin) != NULL && *l != '\n'){
		strcat(s,l);
	}
	if(findWord(s,word,strlen(s),len) == 0){
		printf("%s\n",s);
	}
	return 0;
}

int findWord(char *line, char *word, int len, int wlen){
	int flag = 1;
	int i,j;
	for(i = 0; i < len - wlen; i++){
		if(*(line+i) == *word){
			for(j = 1; j < wlen; j++){
				if(*(line+i+j) == *(word+j)){
					flag = 0;
				}
				else{
					flag = 1;
					break;
				}
			}
		}
		if(flag == 0){
			return 0;
		}
	}
	return 1;
}

int getWord(char *word, int len){
	char s[WORD] = "\0";
	char l[2];
	if(fgets(l,2,stdin) == NULL){
		return 1;
	}
	if(*l == '\n' || *l == ' '){
		return 0;
	}
	strcat(s,l);
	while(fgets(l,2,stdin) != NULL && *l != '\n' && *l != ' ' && *l != '\r'){
		strcat(s,l);
	}
	int slen = strlen(s);
	if(slen - 1 == len || slen == len){
		if(contains(s,word,slen) == 0){
			printf("%s\n",s);
		}
	}
	return 0;
}

int contains(char *word, char *sub, int len){
	int i, j = 0, err = 0;
	for(i = 0; i <= len; i++){
		if(err == 2){
			return 1;
		}
		if(*(word+i) == *(sub+j)){
			j++;
		}
		else{
			err++;
		}
	}
	return 0;
}































