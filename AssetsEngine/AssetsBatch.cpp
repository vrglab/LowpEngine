#include "pch.h"
#include "AssetsBatch.h"

std::string GetByGUID(std::string id, AssetsBatch batch)
{
	for (size_t i = 0; i < batch.assets.size(); i++)
	{
		FileAsset file = batch.assets[i];
		if(file.id == id)
		{
			return file.file_content;
		}
	}
	return "";
}
