#include "Header.h"

int ITK_user_main(int argc, char* argv[]) {

	int ifail = 0;
	char* cError = NULL;

	char* cUserID = NULL;
	char* cPassword = NULL;
	char* cGroup = NULL;

	char* cItemID = NULL;
	char* cIitemName = NULL;

	tag_t tItem = NULLTAG;
	tag_t tRev = NULLTAG;

	if (argc == 6)
	{
		cUserID = ITK_ask_cli_argument("-u=");
		cPassword = ITK_ask_cli_argument("-p=");
		cGroup = ITK_ask_cli_argument("-g=");

		cItemID = ITK_ask_cli_argument("-item_id=");
		cIitemName = ITK_ask_cli_argument("-obj_name=");

		// ifail = ITK_init_module("infodba", "inodba", "dba");
		ifail = ITK_init_module(cUserID, cPassword, cGroup);
		if (ifail == ITK_ok)
		{
			printf("\n\n Login Success");
			ifail = ITEM_create_item(cItemID, cIitemName, "Item", "", &tItem, &tRev); 
			if (ifail == ITK_ok)
			{
				printf("\n\n create Item Success");
				ifail = ITEM_save_item(tItem);
				if (ifail == ITK_ok)
				{
					printf("\n\n Save item Success");
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
		if (cError)
		{
			MEM_free(cError);
		}
	}
	else
	{
		printf("\n\n Argument count is less");
	}

	return 0;
}