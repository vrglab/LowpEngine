#include "pch.h"
#include "HRIDTable.h"

std::string GetGUIDFromHRID(std::string hrid_id, HRIDTable tabel)
{
	for (size_t i = 0; i < tabel.hrids.size(); i++)
	{
		HRID hrid = tabel.hrids[i];
		if (hrid.hrid == hrid_id)
		{
			return hrid.guid;
		}
	}
	return "";
}
