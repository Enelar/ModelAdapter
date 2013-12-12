#pragma once

namespace original_source_code
{
  struct CShBase
  {
    // ���� ��������
    enum RetCodes { rcOK = 0, rcNO = 1 };
    //
    CShBase(int nSize)
    {
      memset(this, 0, nSize);
      m_nSize = nSize;
      RetCode = rcNO;
    }
    //
    int  RetCode; // ��� ��������
    int  m_nSize;
    int  Busy;    // ������� ������������ ��������
    bool m_bAOFS;
  };
  struct CFlagsW
  {
    int Ctrl_Flags;	 // ����������
    int State_Flags; char charMode;// ���������
    int Blk_Flags;   // ����������
    int Use_Flags;	 // �������������
    enum// ����� ���� Ctrl_Flags
    {
      //
      OPEN_DOWN = 0x002,// ������ ������ �������(����)
      OPEN_UP = 0x020,// ������ ������ �������
      //
      STOP_DOWN = 0x008,// ������ ������ ����
      STOP_UP = 0x080,// ������ ������ ����
      //
      CLOSE_DOWN = 0x004,// ������ ������ �������(����)
      CLOSE_UP = 0x040,// ������ ������ �������
      //
      NO_ACTIONS = 0x10000,// �� ��������� �������� �� ���
    };
  };
  struct CFlags : public CFlagsW
  {
    int Type_Flags;
  };
}