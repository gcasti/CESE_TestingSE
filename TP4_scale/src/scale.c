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
#include "stdio.h"
#include "ads1232.h"
#include "utils.h"

/*=====[Inclusions of private function dependencies]=========================*/

/*=====[Definition macros of private constants]==============================*/

/*=====[Private function-like macros]========================================*/

/*=====[Definitions of private data types]===================================*/
typedef struct{
    bool  config_status;
    float m;        // [UnitWeigth/code]
    float Wzero;    // [UnitWeigth]
    float Wtare;    // [UnitWeigth]
    uint8_t avg_num;
}scale_t;

typedef struct{
    bool new_value;
    float weigth;
    bool avg_flag;   
}state_t;   
/*=====[Definitions of external public global variables]=====================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

static scale_t sparms = {false,1,0,0,0};
static state_t scale_state = {false, 0, false};

/*=====[Prototypes (declarations) of private functions]======================*/

/*=====[Implementations of public functions]=================================*/

bool scale_init(void)
{
    bool retVal = false;
    
    ads1232_InitDriver();
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
    float code = 0;
    int32_t codes[3];
    float acc = 0;
    int index = 0;
    
    if(ads1232_newData()){
        code = ads1232_readCode();
    }
    if(scale_state.avg_flag)
    {
        utils_getValues(codes);
           
        for(index=0 ; index < 3 ; index++)
        {
            acc += codes[index];
        }
        code = acc/3;
    }

    scale_state.weigth = sparms.m * code + sparms.Wzero - sparms.Wtare;
    scale_state.new_value = true;

    return scale_state.weigth;
}

void scale_setAvg(bool enable_avg)
{
    scale_state.avg_flag = enable_avg;
}

void scale_setAvgNum(uint8_t num)
{
    sparms.avg_num = num;
}
/*=====[Implementations of interrupt functions]==============================*/

/*=====[Implementations of private functions]================================*/