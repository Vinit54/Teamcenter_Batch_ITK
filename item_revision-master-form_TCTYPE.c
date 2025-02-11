#include "Header.h"

int ITK_user_main(int argc, char* argv[]) {

	int ifail = ITK_ok;

	char* cItemName = ITK_ask_cli_argument("-item_name=");

	tag_t IMRF_type_tag = NULLTAG;
	tag_t irmf_create_input_tag = NULLTAG;
	tag_t form_tag = NULLTAG;

	tag_t IR_type_tag = NULLTAG;
	tag_t rev_create_input_tag = NULLTAG;
	tag_t IR_tag = NULLTAG;

	tag_t itemType_tag = NULLTAG;
	tag_t item_tag = NULLTAG;
	tag_t item_create_input_tag = NULLTAG;

	const char* form_name[1] = { "000090/A" };
	const char* user_data_1[1] = { "User_data_1_value" };
	const char* object_desc[1] = { "Some_description-related_to_IR"};
	const char* item_id[1] = { "000090" };
	const char* object_name[1] = { "Test_TCTYPE1_item_revision_master_form" };


	// Login to the infodba module (assuming reportError handles errors)
	reportError(ITK_init_module("infodba", "infodba", "dba"));
	printf("\n\nLogin success");

	// IMRF
	reportError(TCTYPE_ask_type("ItemRevision Master", &IMRF_type_tag));
	printf("\n\n  ItemRevision Master found");

	reportError(TCTYPE_construct_create_input(IMRF_type_tag, &irmf_create_input_tag));
	printf("\n\n Type of BO found");

	reportError(TCTYPE_set_create_display_value(irmf_create_input_tag, "object_name", 1, form_name));
	printf("\n\n  Sets the display values for a property on a CreateInput descriptor");

	reportError(TCTYPE_set_create_display_value(irmf_create_input_tag, "user_data_1", 1, user_data_1));
	printf("\n\n  Sets the display values for a property on a CreateInput descriptor");

	reportError(TCTYPE_create_object(irmf_create_input_tag, &form_tag));
	printf("\n\n  Creates an object according to the creation data in the CreateInput object");

	reportError(AOM_save_with_extensions(form_tag));
	printf("\n\n imrf create success");

	// IR
	reportError(TCTYPE_ask_type("ItemRevision", &IR_type_tag));
	printf("\n\n ItemRevision found");

	reportError(TCTYPE_construct_create_input(IR_type_tag, &rev_create_input_tag));
	printf("\n\n Type of BO found");

	reportError(TCTYPE_set_create_display_value(rev_create_input_tag, "object_desc", 1, object_desc));
	printf("\n\n  Sets the display values for a property on a CreateInput descriptor");

	reportError(AOM_set_value_tag(rev_create_input_tag, "item_master_tag", form_tag));
	printf("\n\n sets value on single-type-property");

	// ITEM
	reportError(TCTYPE_ask_type("Item", &itemType_tag));
	printf("\n\n  Item found");

	reportError(TCTYPE_construct_create_input(itemType_tag, &item_create_input_tag));
	printf("\n\n Type of BO found");

	reportError(TCTYPE_set_create_display_value(item_create_input_tag, "item_id", 1, item_id));
	printf("\n\n  Sets the display values for a property on a CreateInput descriptor");

	reportError(TCTYPE_set_create_display_value(item_create_input_tag, "object_name", 1, object_name));
	printf("\n\n  Sets the display values for a property on a CreateInput descriptor");

	reportError(AOM_set_value_tag(item_create_input_tag, "revision", rev_create_input_tag));
	printf("\n\n Sets value on a single-valued property.");

	reportError(TCTYPE_create_object(item_create_input_tag, &item_tag));
	printf("\n\n  Creates an object according to the creation data in the CreateInput object");

	reportError(AOM_save_with_extensions(item_tag));
	printf("\n\n Item create success");

	// Logout from the module
	reportError(ITK_exit_module(TRUE));
	printf("\n\nLogout Success\n");

	return ifail;
}