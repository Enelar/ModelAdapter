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
    // ��� ���������
    enumValueColor =  8,//����
    enumValueStyle =  9,//����� �����
    enumValueBrush = 10,//����� ��������
    enumValuePoint = 11,//�����
    enumValueSize  = 12,//������
    enumValueRect  = 13,//�������
    enumValueAligH = 14,//������������ �� �����������
    enumValueAligV = 15,//������������ �� ���������
    enumValueFont  = 16,//������� ������
  };
}