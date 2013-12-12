#pragma once

#include "mapper\mapper.h"

#include "exported\air_condenser.h"
#include "exported\gate_valve.h"
#include "exported\hs.h"
#include "exported\pump.h"
#include "exported\scheme_data.h"
#include "exported\sensor.h"
#include "exported\valve.h"

#include "object_types.h"
#include <vector>
extern std::vector<OBJECT_TYPES> supported_types;

#include "info.h"
#include <map>
extern std::map<OBJECT_TYPES, info> objects_info;