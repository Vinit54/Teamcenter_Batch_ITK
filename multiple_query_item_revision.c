#include "Header.h"

int ITK_user_main(int argc, char* argv[]) {

	int i = 0;
	int n_found = 0;
	int ifail = ITK_ok;
	int n_entry = 3;
	char* entry[3] = { "Name", "Type", "Description"};
	char** values = NULL;
	char* errmsg = NULL;
	char* cItemName = NULL;
	char* ResultItemId = NULL;
	char* cObjName = NULL;
	char* name = ITK_ask_cli_argument("-name=");
	char* type = ITK_ask_cli_argument("-type=");
	char* description = ITK_ask_cli_argument("-description=");
	tag_t tQuery = NULLTAG;
	tag_t query = NULLTAG;
	tag_t* tResult = NULLTAG;
	tag_t* result = NULL;

	ifail = ITK_init_module("infodba", "infodba", "dba");
	printf("\n\n Login success");

	values = (char**)MEM_alloc(n_entry * sizeof(char*));

	values[0] = (char*)MEM_alloc(tc_strlen(name) + 1);
	tc_strcpy(values[0], name);

	values[1] = (char*)MEM_alloc(tc_strlen(type) + 1);
	tc_strcpy(values[1], type);

	values[2] = (char*)MEM_alloc(tc_strlen(description) + 1);
	tc_strcpy(values[2], description);

	if (ifail == ITK_ok) {
		ifail = QRY_find2("Item Revison...", &tQuery);
		if (tQuery != NULLTAG) {
			ifail = QRY_execute(tQuery, 3, entry, values, &n_found, &tResult);
			if (tResult != NULL) {
				printf("\n\n Total number of object found: %d", n_found);
				for (i = 0; i < n_found; i++) {
					ifail = AOM_ask_value_string(tResult[i], "object_string", &cObjName);
					printf("\n\n Object name : %s", cObjName);
				}
			}
		}
	}
	// Logout from the module
	reportError(ITK_exit_module(TRUE));
	printf("\n\n Logout Success");

	return ifail;
}