#pragma once
#include "bills/BillList.h"

int CaluclateTotalEarningsFromDateRange(BillPosition head, Date fromDate, Date toDate, float* sumPrice);
