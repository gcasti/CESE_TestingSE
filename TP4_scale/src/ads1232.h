
#include "stdbool.h"
#include "stdint.h"

void ads1232_init(void);

bool ads1232_newValue(void);

int32_t ads1232_readCode(void);