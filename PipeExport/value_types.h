#pragma once

namespace original_source_code
{
  enum EValueType : char
  {
    enumValueUnk = 0,
    enumValueDbl = 1,
    enumValueInt = 2,
    enumValueChr = 3,
    enumValueBol = 4,
    enumValueFlt = 5,
    enumValueStr = 6,
    enumValueI64 = 7,
    // Для редактора
    enumValueColor =  8,//Цвет
    enumValueStyle =  9,//Стиль линии
    enumValueBrush = 10,//Стиль закраски
    enumValuePoint = 11,//Точка
    enumValueSize  = 12,//Размер
    enumValueRect  = 13,//Область
    enumValueAligH = 14,//Выравнивание по горизонтали
    enumValueAligV = 15,//Выравнивание по вертикали
    enumValueFont  = 16,//Фамилия шрифта
  };
}