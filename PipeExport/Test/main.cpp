#include "../exported_pipe.h"

void main()
{
  exported_pipe t("�������");
  int id = t.GetID(12, "Z-15");
  t.GetServerObject(id);
}