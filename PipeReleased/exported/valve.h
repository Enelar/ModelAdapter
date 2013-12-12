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
    // Дублер
    double Vent_Dubler;//Положение дублёра
    double Vent_AirB;  //Байпас по воздуху
    double Vent_OilB;  //Байпас по маслу
    enum EPumpCode
    {
      enumOpen = 0,// Открыть
      enumNeitral = 1,// Нейтраль
      enumClose = 2 // Закрыть
    };
    EPumpCode ePumpCode;
    bool m_bZacepka;    // Зацепление дублёра за регулирующий клапан
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
  m.Register("closing_percentage", &mapped::VentZ); // Задание
}