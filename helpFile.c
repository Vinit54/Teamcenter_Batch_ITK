#include "Header.h"

int ITK_user_main(int argc, char* argv[]) {

    if (ITK_ask_cli_argument("-h") || ITK_ask_cli_argument("-help")) {
        displayUsage();
    }

    //if (argc == 5)
    //{
    //    int iSecObjCount = 0;
    //    char* cSecObjName = NULL;

    //    int ifail = 0;

    //    char* cUserID = ITK_ask_cli_argument("-u=");
    //    char* cPassword = ITK_ask_cli_argument("-p=");
    //    char* cGroup = ITK_ask_cli_argument("-g=");
    //    char* cItemID = ITK_ask_cli_argument("-item_id=");

    //    tag_t tItem = NULLTAG;
    //    tag_t tRev = NULLTAG;
    //    tag_t tRelation = NULLTAG;
    //    tag_t tRelationType = NULLTAG;
    //    tag_t* tSecObjects = NULLTAG;

    //    // Initialize the module
    //    reportError(ITK_init_module(cUserID, cPassword, cGroup));
    //    printf("\n\n Login Success");

    //    // Create revision
    //    reportError(ITEM_find_rev(cItemID, "A", &tRev));
    //    printf("\n\n Item revision success");

    //    // Find relation type(Real-Name)
    //  /*  reportError(GRM_find_relation_type("IMAN_specification", &tRelationType));
    //    printf("\n\n Relation type success");*/

    //    // Find relation type using (Display Name)
    //    reportError(GRM_find_relation_type("Rendering", &tRelationType));
    //    printf("\n\n Relation type success");

    //    // Create dataset
    //    reportError(GRM_list_secondary_objects_only(tRev, tRelationType, &iSecObjCount, &tSecObjects));
    //    printf("\n\nList secondary obj success");

    //    FILE* new = NULL;
    //    errno_t err = fopen_s(&new, "abc.txt", "w");

    //    //check err
    //    if (err != 0 || new == NULL) {
    //        printf("\n\n Err open file");
    //        return 1;
    //    }

    //    for (int i = 0; i < iSecObjCount; i++) {
    //        reportError(WSOM_ask_name2(tSecObjects[i], &cSecObjName));
    //        printf("\n\n Dataset name : %s", cSecObjName);

    //        fprintf(new, "Name is : %s", cSecObjName);
    //    } fclose(new);

    //    if (tSecObjects) {
    //        MEM_free(tSecObjects);
    //    }

    //    // Logout from the module
    //    reportError(ITK_exit_module(TRUE));
    //    printf("\n\n Logout Success");
    //}
    //else
    //{
    //    printf("\n\n Argument count is less");
    //}

    return 0;
}
