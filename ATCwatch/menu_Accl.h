
#pragma once
#include "Arduino.h"
#include "class.h"
#include "images.h"
#include "menu.h"
#include "display.h"
#include "menuAppsBase.h"
#include "ble.h"
#include "time.h"
#include "battery.h"
#include "accl.h"
#include "push.h"
#include "heartrate.h"


class AcclScreen : public TheScreen
{
  public:
    AcclScreen() {
    }

    virtual void pre()
    {
      displayRect(0, 0, 240, 240, 0x0000);
      displayPrintln(0, 0, "Accl:", 0xFFFF, 0x0000, 2);
      displayPrintln(0, 16, "X:", 0xFFFF, 0x0000, 2);
      displayPrintln(0, 32, "Y:", 0xFFFF, 0x0000, 2);
      displayPrintln(0, 48, "Z:", 0xFFFF, 0x0000, 2);
      displayPrintln(0, 64, "Temp:", 0xFFFF, 0x0000, 2);
      displayPrintln(0, 64 + 32, "Steps:", 0xFFFF, 0x0000, 2);
    }

    virtual void main()
    {
      accl_data_struct accl_data = get_accl_data();

      displayPrintln((2 * 5 * 3), 16, (String)accl_data.x + "    ", 0xFFFF, 0x0000, 2);
      displayPrintln((2 * 5 * 3), 16 + 16, (String)accl_data.y + "    ", 0xFFFF, 0x0000, 2);
      displayPrintln((2 * 5 * 3), 16 + 16 + 16, (String)accl_data.z + "    ", 0xFFFF, 0x0000, 2);
      displayPrintln((2 * 5 * 3), 16 + 16 + 16 + 16 + 16, (String)accl_data.temp + "    ", 0xFFFF, 0x0000, 2);
      displayPrintln((2 * 5 * 3), 16 + 16 + 16 + 16 + 16 + 32, (String)accl_data.steps + "    ", 0xFFFF, 0x0000, 2);
    }

    virtual void up()
    {

    }

    virtual void down()
    {

    }

  private:

};
