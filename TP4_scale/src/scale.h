/*=====[Scale]===========================================================
 * Copyright 2022, Guillermo Luis Castiglioni 
 * Mail: guillermo.castiglioni@ciop.unlp.edu.ar
 * Centro de Investigaciones Opticas
 * All rights reserved.
 * 
 * Version: 1.0.0
 * Creation Date: 2022/06/01
 */

/*=====[Avoid multiple inclusion - begin]====================================*/

#ifndef _SCALE_H_
#define _SCALE_H_

/*=====[Inclusions of public function dependencies]==========================*/
#include "stdbool.h"

/*=====[C++ - Guard]=========================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*=====[Definition macros of public constants]===============================*/

/*=====[Public function-like macros]=========================================*/

bool scale_init(void);

bool scale_getConfigStatus(void);

float scale_updateWeigth(void);

bool scale_newWeigth(void);

void scale_setAvg( bool enable_avg);
/*=====[Definitions of public data types]====================================*/

/*=====[Prototypes (declarations) of public functions]=======================*/

/*=====[Prototypes (declarations) of public interrupt functions]=============*/

/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* _SCALE_H_ */
