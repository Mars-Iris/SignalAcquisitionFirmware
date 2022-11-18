#ifndef	__BSP_H
#define	__BSP_H

#include	"./User/config.h"

#define TOTAL_IT EA

void BSP_Init(void);

void Cmd_Start_Callback(void);
void Cmd_Stop_Callback(void);


#endif