#pragma once

namespace original_project_source_code
{
  // BaseType.h : 43
  typedef enum  EDataTypes
  {
    // Специфика модели
#undef  DATATYPE
#define DATATYPE( Id, Nomer, Text, Icon ) id_##Id = Nomer,
#include <BaseType.hpp>
    //
    id_ObjInfo = 19,// 19 - расширенная информация об объекте
    id_GetInfo = 115,// 115
    id_PHS = 120,                     // 120 многопозиционный ключ
    id_Intermodel = 121,// 121 межмодельные связи
    // Специфика Yokogawa
    id_AcyMin = 0x0200,
#undef   YOKO_TYPE
#define  YOKO_TYPE( a, b, c ) id_##b = 0x##a,
#include <YokogawaType.hpp>
    id_AcyMax = 0x530C,
  } EDataTypes;
#undef DATA_TYPE
#undef YOKO_TYPE
}

enum OBJECT_TYPES
{
  NOTANOBJECT = 0,
  VALVE = original_project_source_code::id_Klapan,
  GATE_VALVE = original_project_source_code::id_Zadv,
  AIR_CONDENSER = original_project_source_code::id_KVO, // конденсатор воздушного охлаждения
  HS = original_project_source_code::id_HS,
  PUMP = original_project_source_code::id_Pump,
  SENSOR = original_project_source_code::id_Sensor
};

template<typename T>
struct object_id
{
  const static OBJECT_TYPES tid;
};

#include "objects.h"

// Because minimal rebuild bug, that should be inited in every .obj file
template<typename T>
const OBJECT_TYPES object_id<T>::tid = NOTANOBJECT;
const OBJECT_TYPES object_id<objects::valve>::tid = VALVE;
const OBJECT_TYPES object_id<objects::gate_valve>::tid = GATE_VALVE;
const OBJECT_TYPES object_id<objects::air_condenser>::tid = AIR_CONDENSER;
const OBJECT_TYPES object_id<objects::hs>::tid = HS;
const OBJECT_TYPES object_id<objects::pump>::tid = PUMP;
const OBJECT_TYPES object_id<objects::sensor>::tid = SENSOR;
