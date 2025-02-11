#include "Header.h"

int ITK_user_main(int argc, char* argv[]) {

	int ifail = 0;
	// char* cError = NULL;

	char* cUserID = NULL;
	char* cPassword = NULL;
	char* cGroup = NULL;

	char* cItemID = NULL;
	char* cItemName = NULL;

	tag_t tItem = NULLTAG;
	tag_t tRev = NULLTAG;

	tag_t tUser = NULLTAG;
	tag_t tHomeFolder = NULLTAG;

	if (argc == 6)
	{
		cUserID = ITK_ask_cli_argument("-u=");
		cPassword = ITK_ask_cli_argument("-p=");
		cGroup = ITK_ask_cli_argument("-g=");

		cItemID = ITK_ask_cli_argument("-item_id=");
		cItemName = ITK_ask_cli_argument("-obj_name=");

		// ifail = ITK_init_module("infodba", "inodba", "dba");
		// ifail = ITK_auto_login();
		reportError(ITK_init_module(cUserID, cPassword, cGroup));
		printf("\n\n Login Success");
		reportError(ITEM_create_item(cItemID, cItemName, "Item", "", &tItem, &tRev));
		printf("\n\n create Item Success");
		reportError(ITEM_save_item(tItem));			
		printf("\n\n Save item Success");
		reportError(SA_find_user2(cUserID, &tUser));
		printf("\n\n Find user success");
		reportError(SA_ask_user_home_folder(tUser, &tHomeFolder));
		printf("\n\n Select in home folder");
		reportError(FL_insert(tHomeFolder, tItem, 999));
		printf("\n\n Save in home folder");
		reportError(AOM_save_without_extensions(tHomeFolder));
		printf("\n\n Save file in home folder");
		reportError(ITK_exit_module(TRUE));
		printf("\n\n Logout Success");
	}
	else
	{
		printf("\n\n Argument count is less");
	}

	return 0;
}