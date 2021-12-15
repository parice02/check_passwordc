#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	/* code */
	char *password = NULL;

	password = malloc(30 * sizeof(char));
	char *reg = "^[a-zA-Z0-9#_@.-]{10,}$";
	regex_t re;
	printf("Veuillez saisir votre mot de passe:\n");
	fgets(password, 30 * sizeof(char), stdin);
	if (!regcomp(&re, reg, REG_EXTENDED | REG_NOSUB))
	{
		int status = regexec(&re, password, 0, NULL, 0);
		regfree(&re);
		if (status)
		{
			printf("Le mot de passe ne correspond pas.\n");
		}
		else
		{
			printf("Le mot de passe correspond.\n");
		}
	}

	return 0;
}
