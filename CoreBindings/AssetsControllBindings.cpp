#include "pch.h"
#include "AssetsControllBindings.h"
#include <AssetsEngine/AssetsEngine.h>

LP_Extern LP_Export char* GetHRIDFileContent(char* hrid)
{
    return AssetsEngine::database.GetFileContentFromHRID(hrid).data();
}
