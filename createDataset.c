#include "Header.h"

int ITK_user_main(int argc, char* argv[]) {

    if (argc == 5)
    {
        int ifail = 0;

        char* cUserID = ITK_ask_cli_argument("-u=");
        char* cPassword = ITK_ask_cli_argument("-p=");
        char* cGroup = ITK_ask_cli_argument("-g=");
        char* cItemID = ITK_ask_cli_argument("-item_id=");

        tag_t tItem = NULLTAG;
        tag_t tRev = NULLTAG;
        tag_t tDatasetType = NULLTAG;
        tag_t tDataset = NULLTAG;
        tag_t tRelation = NULLTAG;
        tag_t tRelationType = NULLTAG;

        // Initialize the module
        reportError(ITK_init_module(cUserID, cPassword, cGroup));
        printf("\n\n Login Success");

        // Find item
        reportError(ITEM_find_item(cItemID, &tItem));
        printf("\n\n Item find success");

        // Create revision
        reportError(ITEM_find_revision(tItem, "A", &tRev));
        printf("\n\n Item revision success");

        // Find dataset type
        reportError(AE_find_datasettype2("PDF", &tDatasetType));
        printf("\n\n Dataset type success");

        // Create dataset
        reportError(AE_create_dataset_with_id(tDatasetType, "MyPDF", "", "", "", &tDataset));
        printf("\n\n Create dataset type success");

        // Save dataset
        reportError(AE_save_myself(tDataset));
        printf("\n\n Save dataset success");

        // Create relation type
        reportError(GRM_find_relation_type("IMAN_specification", &tRelationType));
        printf("\n\n Relation type success");

        // Create relation
        reportError(GRM_create_relation(tRev, tDataset, tRelationType, NULLTAG, &tRelation));
        printf("\n\n Create relation success");

        // Save relation
        reportError(GRM_save_relation(tRelation));
        printf("\n\n Save relation success");
      
        // Logout from the module
        reportError(ITK_exit_module(TRUE));
        printf("\n\n Logout Success");
    }
    else
    {
        printf("\n\n Argument count is less");
    }

    return 0;
}
