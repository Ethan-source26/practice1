#include"tasks.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "tim.h"
#include "iwdg.h"

volatile uint32_t tick = 0;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM2)   
    {
        tick = tick +1;
        //HAL_IWDG_Refresh(&hiwdg);   //这是第二题，第三题时注释了

    }
}

void Tasks_Init(void)
{
    tick = 0;
    // 第一题 GPIO 
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET); 

    // 第二题 定时器
    HAL_TIM_Base_Start_IT(&htim2); 
}

#ifdef __cplusplus
}
#endif







