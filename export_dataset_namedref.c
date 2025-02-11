#include "Header.h"

int ITK_user_main(int argc, char* argv[]) {

    if (argc == 5)
    {
        int iRefCount = 0;
        int iSecObjCount = 0;
        char* cSecObjType = NULL;

        int ifail = 0;

        char* cUserID = ITK_ask_cli_argument("-u=");
        char* cPassword = ITK_ask_cli_argument("-p=");
        char* cGroup = ITK_ask_cli_argument("-g=");
        char* cItemID = ITK_ask_cli_argument("-item_id=");

        tag_t tItem = NULLTAG;
        tag_t tRev = NULLTAG;
        tag_t tRelation = NULLTAG;
        tag_t tRelationType = NULLTAG;
        tag_t* tSecObjects = NULLTAG;
        tag_t* tNameRef = NULLTAG;

        // Initialize the module
        reportError(ITK_init_module(cUserID, cPassword, cGroup));
        printf("\n\n Login Success");

        // Create revision
        reportError(ITEM_find_rev(cItemID, "A", &tRev));
        printf("\n\n Item revision success");

        // Find relation type(Real-Name)
        reportError(GRM_find_relation_type("IMAN_specification", &tRelationType));
        printf("\n\n Relation type success");

        // Find relation type using (Display Name)
       /* reportError(GRM_find_relation_type("Rendering", &tRelationType));
        printf("\n\n Relation type success");*/

        // Create dataset
        reportError(GRM_list_secondary_objects_only(tRev, tRelationType, &iSecObjCount, &tSecObjects));
        printf("\n\nList secondary obj success");

        for (int i = 0; i < iSecObjCount; i++) {
            reportError(WSOM_ask_object_type2(tSecObjects[i], &cSecObjType));
            printf("\n\n Dataset type : %s", cSecObjType);

           /* if (tc_strcmp(cSecObjType, "PDF") == 0) {
                reportError(AE_ask_all_dataset_named_refs2(tSecObjects[i],
                    "PDF_Reference",
                    &iRefCount,
                    &tNameRef));
                printf("\n\n All dataset found success");

                for (int j = 0; j < iRefCount; j++) {
                    printf("\n\n\ inside for");
                    reportError(AE_export_named_ref(tSecObjects[i], 
                        "PDF_Reference",
                        "C:\\Users\\AdminV\\Desktop\\qrcode\\testPDF.pdf"));
                    printf("\n\n Named PDF ref export success");
                }

                reportError(AE_save_myself(tSecObjects[i]));
                printf("\n\n Dataset save success");
                //  reportError(AOM_unlock(tSecObjects[i]));
                //   reportError(AOM_refresh(tSecObjects[i], FALSE));
                // printf("\n\n Check in success");

              
            }*/
             if (tc_strcmp(cSecObjType, "Text") == 0) {
                // reportError(AOM_lock(tSecObjects[i]));
                reportError(AE_ask_all_dataset_named_refs2(tSecObjects[i],
                    "Text",
                    &iRefCount,
                    &tNameRef));
                printf("\n\n Dataset checkout success");

                for (int j = 0; j < iRefCount; j++) {
                    reportError(AE_export_named_ref(tSecObjects[j],
                        "Text",
                        "C:\\Users\\AdminV\\Desktop\\qrcode\\aboc.txt"));
                    printf("\n\n Named Text ref export success");
                }
                //  reportError(AOM_unlock(tSecObjects[i]));
                //   reportError(AOM_refresh(tSecObjects[i], FALSE));
                //  printf("\n\n Check in success");

                reportError(AE_save_myself(tSecObjects[i]));
                printf("\n\n Dataset save success");
            }

        }

        if (tSecObjects) {
            MEM_free(tSecObjects);
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
