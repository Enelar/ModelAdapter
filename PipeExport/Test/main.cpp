#include "../exported_pipe.h"

void main()
{
  exported_pipe t("Name");
  t.GetPipeElement(12, "PV10-229");
}