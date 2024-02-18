#include "pch.h"
#include "AssetsBatch.h"

std::string AssetsBatch::GetByGUID(std::string id)
{
	for (size_t i = 0; i < assets.size(); i++)
	{
		FileAsset file = assets[i];
		if(file.id == id)
		{
			return file.file_content;
		}
	}
	return "";
}
