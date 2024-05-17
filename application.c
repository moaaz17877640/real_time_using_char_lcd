/*
 * File: application.c
 * Author: MOAAZ
 *
 * Created on December 1, 2023, 10:21 PM
 */
#include "application.h"
volatile uint8 tmr1_counter = 0 ;


 chr_lcd_4bit_t lcd_1 = {
  .pin_Rs.port = PORTC_INDEX,
   .pin_Rs.pin = PIN0,
   .pin_Rs.direction = OUTPUT,
   .pin_Rs.logic =LOGIC_LOW,
   .pin_en.port = PORTC_INDEX,
   .pin_en.pin = PIN1,
   .pin_en.direction = OUTPUT,
   .pin_en.logic = LOGIC_LOW,
    
  .lcd_pins[0].port = PORTC_INDEX,
  .lcd_pins[0].logic = LOGIC_LOW,
  .lcd_pins[0].direction = OUTPUT,
  .lcd_pins[0].pin = PIN2,
   
  .lcd_pins[1].port = PORTC_INDEX,
  .lcd_pins[1].pin = PIN3,
  .lcd_pins[1].direction = OUTPUT,
   .lcd_pins[1].logic = LOGIC_LOW,
   
   .lcd_pins[2].port = PORTC_INDEX,
    .lcd_pins[2].pin = PIN4,
  .lcd_pins[2].direction = OUTPUT,
  .lcd_pins[2].logic = LOGIC_LOW,
   
   .lcd_pins[3].port = PORTC_INDEX,
   .lcd_pins[3].pin = PIN5,
   .lcd_pins[3].direction = OUTPUT,
   .lcd_pins[3].logic = LOGIC_LOW,
 
};
   
void TMR_Isr(void){
    tmr1_counter++;
  //  led_toggle(&led_2);
}

void app_initialize(void);
Timer1_t int1 ;
void interrupt_init1(void){
int1.Prescaler_value = TIMER1_PRESCALER_DIV_8 ;
int1.TIMER1_INTERRUPT_HANDLER = TMR_Isr ;
//int1.counter_mode =TIMER1_SYNCHRONOUS_mode ;
int1.timer1_mode =  TIMER1_TIMER_MODE_CFG ;
int1.timer1_osc_cfg = TIMER1_Disable_osc_cfg ;
int1.timer1_preload_value = 3536 ; // given 2ms   for call back
int1.timer1_register_size = TIMER1_16_RW_reg ;
TMR1_Init(&int1);
}

Std_ReturnType ret = E_NOT_OK;
uint8 second_num= 0;
uint8 minute_num = 0;
uint8 hour_num = 0 ;
uint8 second_nums[5];
uint8 minute_nums[5];
uint8 hour_nums[5];

uint8 second_nums2[5];
uint8 minute_nums2[5];
uint8 hour_nums2[5];
int main() {
     app_initialize();
   interrupt_init1();

    while(1){
        if(tmr1_counter  == 4){
           second_num++;
           tmr1_counter = 0;
        }
        ret = lcd_4bit_send_data_string_posit(&lcd_1 ,1,1, "clock :");
        convert_uint8_to_string(second_num%10 ,second_nums );
        convert_uint8_to_string(minute_num%10 ,minute_nums );
        convert_uint8_to_string(hour_num%10 ,hour_nums );
        convert_uint8_to_string(second_num/10 ,second_nums2 );
        convert_uint8_to_string(minute_num/10  ,minute_nums2 );
        convert_uint8_to_string(hour_num/10  ,hour_nums2 );
        
        lcd_4bit_send_data_char_posit(&lcd_1 ,1,10, ':');
        lcd_4bit_send_data_char_posit(&lcd_1 ,1,13, ':');
        
        lcd_4bit_send_data_string_posit(&lcd_1 ,1,8 ,hour_nums2 );
        lcd_4bit_send_data_string_posit(&lcd_1 , 1,9,hour_nums );
        lcd_4bit_send_data_string_posit(&lcd_1 , 1,11,minute_nums2 );
        lcd_4bit_send_data_string_posit(&lcd_1 ,1,12 ,minute_nums );
        lcd_4bit_send_data_string_posit(&lcd_1 , 1,14,second_nums2 );
        lcd_4bit_send_data_string_posit(&lcd_1 , 1,15,second_nums );
             
             if(second_num == 60){
                 second_num= 0;
             minute_num++;
             }
              if(minute_num == 60){
                  minute_num = 0;
             hour_num++;
             }
       
        
       
        
        
        
        
     
    }
   
     return (EXIT_SUCCESS);
}

void  app_initialize(void) {
  
 lcd_4bit_initialize(&lcd_1);
}