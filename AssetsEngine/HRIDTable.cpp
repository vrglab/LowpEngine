#include "pch.h"
#include "HRIDTable.h"

std::string HRIDTable::GetGUIDFromHRID(std::string hrid_id)
{
	for (size_t i = 0; i < hrids.size(); i++)
	{
		HRID hrid = hrids[i];
		if (hrid.hrid == hrid_id)
		{
			return hrid.guid;
		}
	}
	return "";
}
