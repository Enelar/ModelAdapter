#pragma once

namespace original_source_code
{
  struct CShBase
  {
    // коды возврата
    enum RetCodes { rcOK = 0, rcNO = 1 };
    //
    CShBase(int nSize)
    {
      memset(this, 0, nSize);
      m_nSize = nSize;
      RetCode = rcNO;
    }
    //
    int  RetCode; // код возврата
    int  m_nSize;
    int  Busy;    // счетчик подключенных клиентов
    bool m_bAOFS;
  };
  struct CFlagsW
  {
    int Ctrl_Flags;	 // Управление
    int State_Flags; char charMode;// Состояние
    int Blk_Flags;   // Блокировки
    int Use_Flags;	 // Использование
    enum// Флаги поля Ctrl_Flags
    {
      //
      OPEN_DOWN = 0x002,// Нажата кнопка открыть(пуск)
      OPEN_UP = 0x020,// Отжата кнопка открыть
      //
      STOP_DOWN = 0x008,// Нажата кнопка стоп
      STOP_UP = 0x080,// Отжата кнопка стоп
      //
      CLOSE_DOWN = 0x004,// Нажата кнопка закрыть(стоп)
      CLOSE_UP = 0x040,// Отжата кнопка закрыть
      //
      NO_ACTIONS = 0x10000,// Не выполнять действий из АРМ
    };
  };
  struct CFlags : public CFlagsW
  {
    int Type_Flags;
  };
}