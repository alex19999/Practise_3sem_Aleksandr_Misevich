#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<unistd.h>
#include<string.h>

#define MAX_SYM 1000
#define MAX_WORDS 100

// delimeter или separator ... divider - делитель, а у вас тут разделитель
#define MAX_DIVIDER 100

// fixit: после запятой нужен пробел здесь и далее
void Split(char* str_in,char* divider,char** tokens,int* quantity);

int main() {
	char* str_in;
	int cnt = 0;	
	int* quantity;
	char** tokens;
	char* divider;
	quantity = (int*)calloc(MAX_WORDS,sizeof(int));
        str_in = (char*)calloc(MAX_SYM,sizeof(char));
	printf("please,give me a string to divide it into tokens\n");
	fgets(str_in,MAX_SYM,stdin);
        printf("please,give me a symbol to divide\n");
	fgets(divider,MAX_WORDS,stdin);
	Split(str_in,divider,tokens,quantity);
	// fixit: на каждый вызов calloc должен быть вызов free
return 0;
}



void Split(char* str_in,char* divider,char** tokens,int* quantity) {
        int counter = 0;
        int iter = 0;
	char* istr;
	int length_of_token = 0;
	tokens = (char**)calloc(MAX_WORDS,sizeof(char*));
	str_in[strlen(str_in) - 1] = 0; 
	divider[strlen(divider) - 1] = 0;
	istr =(char*)calloc(MAX_DIVIDER,sizeof(char));
	char* new_str = str_in;
	strcat(str_in,divider);
	// fixit: похоже, что вместо || надо &&
	if(str_in != NULL || divider != NULL) {
		for(iter == 0; iter <= strlen(str_in); iter++) {
			istr = strstr(str_in,divider);
			length_of_token = strlen(str_in) - strlen(istr);
			if(istr == NULL) {
				tokens[counter] = (char*)calloc(strlen(new_str),sizeof(char));
				strcpy(tokens[counter],new_str);
				counter++;
				break;
			} else {
				tokens[counter] = (char*)calloc(length_of_token,sizeof(char));
				strncpy(tokens[counter],str_in,length_of_token);
				counter++;
				str_in = istr + strlen(divider);
				
			}
		}
        *quantity = counter;
	// fixit: ф-я должна только находить разбиение строки на слова ... вывод снаружи где-то
        // в следующем домашнем упражнении надо будет переиспользовать эту ф-ю ... там выводить разбиение на экран не надо
        printf("%d\n",*quantity);
	}
}
