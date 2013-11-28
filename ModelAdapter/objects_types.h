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

enum OBJECT_TYPES
{
  VALVE = id_Klapan,
  GATE_VAVLE = id_Zadv,
  KVO = id_KVO,
  HS = id_HS,
  PUMP = id_Pump
};

