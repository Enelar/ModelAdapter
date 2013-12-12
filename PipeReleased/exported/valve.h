namespace original_source_code
{
  struct CKlapanW
  {
    double Vent;
    double VentZ;
    double Vent_In;
    double Vent_Out;
    double Vent_BP;
    double Vent_BP1;
    double Vent_BP2;
    double Vent_Drainage_In;
    double Vent_Drainage_Out;
    // ������
    double Vent_Dubler;//��������� ������
    double Vent_AirB;  //������ �� �������
    double Vent_OilB;  //������ �� �����
    enum EPumpCode
    {
      enumOpen = 0,// �������
      enumNeitral = 1,// ��������
      enumClose = 2 // �������
    };
    EPumpCode ePumpCode;
    bool m_bZacepka;    // ���������� ������ �� ������������ ������
    double Pi, Po;
    int Local_0_Remote;
  };
}

#include "../objects.h"

namespace objects
{
  typedef ::mapper<original_source_code::CKlapanW> valve;
}

template<>
void objects::valve::UpdateRouteTable(objects::valve &m)
{
  m.Register("closing_percentage", &mapped::VentZ); // �������
}