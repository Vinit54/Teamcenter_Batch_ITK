#include "Header.h"

int ITK_user_main(int argc, char* argv[]) {

    if (argc == 5)
    {
        int ifail = 0;
        int iPropCount = 0;
        char** cPropName = NULL;
        char* cPropValue = NULL;

        char* cUserID = ITK_ask_cli_argument("-u=");
        char* cPassword = ITK_ask_cli_argument("-p=");
        char* cGroup = ITK_ask_cli_argument("-g=");
        char* cItemID = ITK_ask_cli_argument("-item_id=");

        tag_t tItem = NULLTAG;
        tag_t tRev = NULLTAG;

        // Initialize the module
        reportError(ITK_init_module(cUserID, cPassword, cGroup));
        printf("\n\n Login Success");

        // Find Item
        reportError(ITEM_find_item(cItemID, &tItem));
        printf("\n\n Item find success");

        // Find latest revision
        reportError(ITEM_ask_latest_rev(tItem, &tRev));
        printf("\n\n Item find success");

        // Get property names
        reportError(AOM_ask_prop_names(tRev, &iPropCount, &cPropName));
        printf("\n\n Property name find success");

        for (int i = 0; i < iPropCount; i++) {
            reportError(AOM_UIF_ask_value(tRev, cPropName[i], &cPropValue));

            // Only print if cPropValue is not NULL
            if (cPropValue != NULL) {
                printf("\n\n Prop name : %s ----> Prop value : %s", cPropName[i], cPropValue);
            }
        }

        // Free allocated memory for property names
        if (cPropName) {
            MEM_free(cPropName);
        }

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
