#pragma once

#include <array>

#include "Assembly.h"
#include "OffsetTable.h"
#include "Partition.h"

using Level = unsigned char;

Level Apart(Assembly, const OffsetTable&, const ReflectTable&,
            Partition p = Partition::All());
