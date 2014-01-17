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

template<int tid>
struct object_type
{
};

#include "objects.h"

// Because minimal rebuild bug, that should be inited in every .obj file
template<typename T>
const OBJECT_TYPES object_id<T>::tid = NOTANOBJECT;

#define BIND_OBJECT_TYPE_ID(_type_, _tid_) \
  const OBJECT_TYPES object_id<_type_>::tid = _tid_; \
  template<>                                          \
  struct object_type<_tid_>                            \
  {                                                     \
    typedef _type_ type;                                 \
  };                                                      \
  static_assert(object_id<object_type<_tid_>::type>::tid == _tid_, "Failed bind " TOSTRING(_type_))

BIND_OBJECT_TYPE_ID(objects::valve, VALVE);
BIND_OBJECT_TYPE_ID(objects::gate_valve, GATE_VALVE);
BIND_OBJECT_TYPE_ID(objects::air_condenser, AIR_CONDENSER);
BIND_OBJECT_TYPE_ID(objects::hs, HS);
BIND_OBJECT_TYPE_ID(objects::pump, PUMP);
BIND_OBJECT_TYPE_ID(objects::sensor, SENSOR);