#include "pch.h"
#include "AssetsControllBindings.h"

LP_Extern LP_BINDINGS_API char* GetHRIDFileContent(char* hrid)
{
    return GetFileContentFromHRID(hrid, assets_database).data();
}
