#include "pch.h"
#include "HRIDTable.h"

std::string GetGUIDFromHRID(std::string hrid_id, HRIDTable tabel)
{
	if(hrid_id != "")
	{
		size_t i = 0;
		for (i = 0; i < tabel.hrids.size(); i++)
		{
			HRID hrid = tabel.hrids[i];
			if (hrid.hrid == hrid_id)
			{
				return hrid.guid;
			}
		}
		IFERRRET(i == tabel.hrids.size(), "Couldn't find asset with HRID: ", hrid_id, hrid_id)
	}
	else
	{
		return hrid_id;
	}
}
