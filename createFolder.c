#include "Header.h"

int ITK_user_main(int argc, char* argv[]) {

    if (argc == 8)
    {
        int ifail = 0;

        char* cUserID = ITK_ask_cli_argument("-u=");
        char* cPassword = ITK_ask_cli_argument("-p=");
        char* cGroup = ITK_ask_cli_argument("-g=");
        char* cFolderName = ITK_ask_cli_argument("-folder_name=");
        char* cFolderDesc = ITK_ask_cli_argument("-folder_desc=");
        char* cItemID = ITK_ask_cli_argument("-item_id=");
        char* cItemName = ITK_ask_cli_argument("-obj_name=");

        tag_t tNewFolder = NULLTAG;
        tag_t tUser = NULLTAG;
        tag_t tHome = NULLTAG;
        tag_t tItem = NULLTAG;
        tag_t tRev = NULLTAG;

        // Initialize the module
        reportError(ITK_init_module(cUserID, cPassword, cGroup));
        printf("\n\n Login Success");

        // Create the folder
        reportError(FL_create2(cFolderName, cFolderDesc, &tNewFolder));
        printf("\n\n Create Folder Success");

        // Save the folder
        reportError(AOM_save_without_extensions(tNewFolder));
        printf("\n\n Folder is saved");

        // Find the user and their home folder
        reportError(SA_find_user2(cUserID, &tUser));
        printf("\n\n Find user success");

        reportError(SA_ask_user_home_folder(tUser, &tHome));
        printf("\n\n Select in home folder");

        // Insert the new folder into the user's home folder
        reportError(FL_insert(tHome, tNewFolder, 999));
        printf("\n\n Folder inserted into home folder");

        // Save the updated home folder
        reportError(AOM_save_without_extensions(tHome));
        printf("\n\n Home folder updated with new folder");

        // Create the item
        reportError(ITEM_create_item(cItemID, cItemName, "Item", "", &tItem, &tRev));
        printf("\n\n Create Item Success");

        // Save the item
        reportError(ITEM_save_item(tItem));
        printf("\n\n Item is saved");

        // Insert the item into the new folder
        reportError(FL_insert(tNewFolder, tItem, 999));
        printf("\n\n Item inserted into the new folder");

        // Save the folder with the item
        reportError(AOM_save_without_extensions(tNewFolder));
        printf("\n\n Folder with item is saved");

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
