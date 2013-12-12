#include "object_types.h"
#include "objects.h"

std::vector<OBJECT_TYPES> supported_types = {
  VALVE,
  GATE_VALVE,
  AIR_CONDENSER,
  HS,
  PUMP,
  SENSOR
};

std::map<OBJECT_TYPES, info> objects_info = {
  {VALVE, info()}
};