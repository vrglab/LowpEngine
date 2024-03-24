#include "pch.h"
#include "AssetsBatch.h"

std::string GetByGUID(std::string id, AssetsBatch batch)
{
	if(id != "")
	{
		size_t i = 0;
		for (i = 0; i < batch.assets.size(); i++)
		{
			FileAsset file = batch.assets[i];
			if (file.id == id)
			{
				return file.file_content;
			}
		}
		IFERRRET(i == batch.assets.size(), "Couldn't find asset with GUID: ", id, "")
	}
	else
	{
		return "";
	}
}
