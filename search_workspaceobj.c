#include"Header.h"

int ITK_user_main(int argc, char* argv[]) {
	int iCount = 0;
	char* cItemID = NULL;
	char* cItemName = NULL;
	tag_t* tSearchList = NULLTAG;
	tag_t tUser = NULLTAG;
	WSO_search_criteria_t tCriteria;

	// Initialize module
	reportError(ITK_init_module("infodba", "infodba", "dba"));
	printf("\n\n Login success");

	// Search criteria
	reportError(WSOM_clear_search_criteria(&tCriteria));
	printf("\n\n clear search criteria");

	//find user
	reportError(SA_find_user2("infodba", &tUser));
	printf("\n\n Find user success");

	tCriteria.owner = tUser;
	tc_strcpy(tCriteria.name, "*");
	tc_strcpy(tCriteria.class_name, "Item");

	// search criteria
	reportError(WSOM_search(tCriteria, &iCount, &tSearchList));
	printf("\n\n Search success");

	// name of file type
	for (int i = 0; i < iCount; i++) {
		reportError(WSOM_ask_name2(tSearchList[i], &cItemName));
		printf("\n\n  name of file type success ");

		// find id string
		reportError(WSOM_ask_id_string(tSearchList[i], &cItemID));
		printf("\n\n ID : %s & Name : %s", cItemID, cItemName);
	}

	if (tSearchList) {
		MEM_free(tSearchList);
	}

	// Logout from the module
	reportError(ITK_exit_module(TRUE));
	printf("\n\n Logout Success");

	return 0;
}