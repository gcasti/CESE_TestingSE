/*=====[Module Name]===========================================================
 * Copyright YYYY Author Compelte Name <author@mail.com>
 * All rights reserved.
 * License: license text or at least name and link 
         (example: BSD-3-Clause <https://opensource.org/licenses/BSD-3-Clause>)
 *
 * Version: 0.0.0
 * Creation Date: YYYY/MM/DD
 */
 
/*=====[Inclusion of own header]=============================================*/

#include "scale.h"
#include "stdint.h"
#include "ads1232.h"

/*=====[Inclusions of private function dependencies]=========================*/

/*=====[Definition macros of private constants]==============================*/

/*=====[Private function-like macros]========================================*/

/*=====[Definitions of private data types]===================================*/

static bool scale_config = true;
static int32_t m = 1;
static bool new_value = false;
static float Wzero = 0 , Wtare = 0;
/*=====[Definitions of external public global variables]=====================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Prototypes (declarations) of private functions]======================*/

/*=====[Implementations of public functions]=================================*/

bool scale_init(void)
{
    bool retVal = false;
    
    if(m != 0){
        retVal = true;
    }
    new_value = false;
    return retVal;
}

bool scale_getConfigStatus(void)
{
    return scale_config;
}
bool scale_newWeigth(void){
    return new_value;
}

float scale_updateWeigth(void){
    int32_t code = 0;
    float weigth = 0;

    if(ads1232_newValue){
        code = ads1232_readCode();
    }

    weigth = m * code + Wzero - Wtare;
    new_value = true;

    return weigth;
}

/*=====[Implementations of interrupt functions]==============================*/

/*=====[Implementations of private functions]================================*/