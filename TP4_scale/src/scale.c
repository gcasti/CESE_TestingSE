/*=====[Scale]===========================================================
 * Copyright 2022, Guillermo Luis Castiglioni 
 * Mail: guillermo.castiglioni@ciop.unlp.edu.ar
 * Centro de Investigaciones Opticas
 * All rights reserved.
 * 
 *
 * Version: 1.0.0
 * Creation Date: 2022/06/01
 */
 
/*=====[Inclusion of own header]=============================================*/

#include "scale.h"
#include "stdint.h"
#include "ads1232.h"

/*=====[Inclusions of private function dependencies]=========================*/

/*=====[Definition macros of private constants]==============================*/

/*=====[Private function-like macros]========================================*/

/*=====[Definitions of private data types]===================================*/
typedef struct{
    bool  config_status;
    float m;        // [UnitWeigth/code]
    float Wzero;    // [UnitWeigth]
    float Wtare;    // [UnitWeigth]
}scale_t;

typedef struct{
    bool new_value;
    float weigth;
}state_t;   
/*=====[Definitions of external public global variables]=====================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

static scale_t sparms = {false,1,0,0};
static state_t scale_state = {false, 0};

/*=====[Prototypes (declarations) of private functions]======================*/

/*=====[Implementations of public functions]=================================*/

bool scale_init(void)
{
    bool retVal = false;
    
    ads1232_init();
    if( sparms.m != 0)
    {
        sparms.config_status = true;
        retVal = true;
    }
    scale_state.new_value = false;
    return retVal;
}

bool scale_getConfigStatus(void)
{
    return sparms.config_status;
}

bool scale_newWeigth(void)
{
    return scale_state.new_value;
}

float scale_updateWeigth(void)
{
    int32_t code = 0;
    
    if(ads1232_newValue){
        code = ads1232_readCode();
    }

    scale_state.weigth = sparms.m * code + sparms.Wzero - sparms.Wtare;
    scale_state.new_value = true;

    return scale_state.weigth;
}

/*=====[Implementations of interrupt functions]==============================*/

/*=====[Implementations of private functions]================================*/