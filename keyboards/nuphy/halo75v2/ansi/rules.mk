SRC += user_kb.c
SRC += rf.c
SRC += side.c

# can be separated with needed fields implemented in ansi.h
SRC += mcu_pwr.c sleep.c debounce.c rf_driver.c rf_queue.c

UART_DRIVER_REQUIRED = yes
MOUSEKEY_ENABLE = yes

OPT ?= 2
CUSTOM_MATRIX = lite
SRC += matrix.c

# CONSOLE_ENABLE = yes
