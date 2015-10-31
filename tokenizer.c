#include <stdio.h>
#include <stdlib.h>

char ** mytoc(char *str, char delim)
{
	int i, j, token_length, tokens = 0;
	char *token_start;

	//Counting the amount of tokens by ignoring delimeters.
	for(i = 0; str[i] != '\0'; i++)
	{
		if(str[i] != delim)
		{
			while(str[i] != delim && str[i+1] != '\0') i++;
			tokens++;
		}
	}

	if(tokens == 0) write(2, "No tokens to parse, returning empty vector!\n", 44);

	//Allocating the vector for the tokens, end is a null pointer.
	char **tokenVec = (char **)calloc(tokens + 1, sizeof(char*));
	tokenVec[tokens] = (char*)0;

	//Creating string from each token and assigning them to an index in the vector.
	for(i = 0, tokens = 0; str[i] != 0; i++)
	{
		if(str[i] != delim)
		{
			token_start = &str[i];
			token_length = 0;
			while(str[i] != delim && str[i] !=0)
			{
				token_length++;
				i++;
			}
			//Allocating the string to an index in the vector, end is a null pointer.
			tokenVec[tokens] = (char*)malloc(sizeof(char) * (token_length + 1));
			tokenVec[tokens][token_length] = '\0';
			for(j = 0; j < token_length; j++){
				tokenVec[tokens][j] = token_start[j];
			}
			tokens++;
		}
		if(str[i] == 0) break;
	}
	return tokenVec;
}
