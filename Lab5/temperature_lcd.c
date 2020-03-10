#include "esos.h"
#include "revF14.h"
#include "esos_pic24.h"
#include <stdio.h>
#include "esos_lcd44780.h"
#include "esos_pic24_lcd44780.h"

ESOS_USER_TASK(dummy){
    ESOS_TASK_BEGIN();
    
    while(TRUE){
        esos_lcd44780_clearScreen();
        esos_lcd44780_writeString(0, 0, "test");
        esos_lcd44780_writeString(1, 0, "test");
        ESOS_TASK_YIELD();
    }
    ESOS_TASK_END();
}

void user_init(){
    esos_lcd44780_init();
    esos_lcd44780_configDisplay();
    esos_RegisterTask(dummy);
}