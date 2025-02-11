#include "Header.h"

int ITK_user_main(int argc, char* argv[]) {

	int ifail = ITK_ok;

	char* cItemName = ITK_ask_cli_argument("-item_name=");

	tag_t tItemType = NULLTAG;
	tag_t tItem = NULLTAG;
	tag_t tItemCreateInput = NULLTAG;

	// Login to the infodba module (assuming reportError handles errors)
	reportError(ITK_init_module("infodba", "infodba", "dba"));
	printf("\n\nLogin success");

	reportError(TCTYPE_ask_type("Item", &tItemType));
	printf("\n\n  Type name found");

	reportError(TCTYPE_construct_create_input(tItemType, &tItemCreateInput));
	printf("\n\n Type of BO found");

	reportError(AOM_set_value_string(tItemCreateInput, "object_name", cItemName));
	printf("\n\n sets value on single-type-property");

	reportError(TCTYPE_create_object(tItemCreateInput, &tItem));
	printf("\n\n  Creates an object according to the creation data in the CreateInput object");

	reportError(AOM_save_with_extensions(tItem));
	printf("\n\n Item create success");

	// Logout from the module
	reportError(ITK_exit_module(TRUE));
	printf("\n\nLogout Success\n");

	return ifail;
}