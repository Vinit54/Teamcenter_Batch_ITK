#include "Header.h"

int ITK_user_main(int argc, char* argv[]) {

	int ifail = 0;
	char* cError = NULL;

	char* cUserID = NULL;
	char* cPassword = NULL;
	char* cGroup = NULL;

	if (argc == 4)
	{
		cUserID = ITK_ask_cli_argument("-u=");
		cPassword = ITK_ask_cli_argument("-p=");
		cGroup = ITK_ask_cli_argument("-g=");

		// ifail = ITK_init_module("infodba", "inodba", "dba");
		ifail = ITK_init_module(cUserID, cPassword, cGroup);
		if (ifail == ITK_ok) 
		{
			printf("\n\n Login Success");
			ifail = ITK_exit_module(TRUE);
			if (ifail == ITK_ok) 
			{
				printf("\n\n Logout Success");
			}
			else
			{
				EMH_ask_error_text(ifail, &cError);
				printf("\n\n Error is : %s", cError);
			}
		}
		else 
		{
			EMH_ask_error_text(ifail, &cError);
			printf("\n\n Error is : %s", cError);
		}
	}
	else
	{
		printf("\n\n Argument count is less");
	}

	return 0;
}
