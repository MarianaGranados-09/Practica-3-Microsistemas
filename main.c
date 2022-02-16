#include <18F4450.h>


#FUSES HS
#FUSES NOWDT
#FUSES NOBROWNOUT
#FUSES PLL1 
#FUSES CPUDIV1
#FUSES NOPROTECT

#use delay(crystal=8MHz)


//Direcciones de memoria de los registros principales para el control de interrupciones
#BYTE INTCON=0xFF2
#BYTE INTCON2=0xFF1
#BYTE INTCON3=0xFF0

//Direcciones de memoria de los registros del puerto D para los leds
//Direcciones de memoria de los registros para el puerto B 
#BYTE PORTD=0xF83
#BYTE TRISD=0xF95

#BYTE PORTB=0xF81
#BYTE TRISB=0xF93

int8 i=0;

#int_ext
void interrupcion1()
{
   PORTD=0xFF;
   delay_ms(500);
   PORTD=0x00;
   delay_ms(500);
   PORTD=0xFF;
   delay_ms(500);
   PORTD=0x00;
   delay_ms(500);
}
#int_ext1
void interrupcion2()
{
   //disable_interrupts(int_ext);
   PORTD=0xF0;
   delay_ms(1000);
   PORTD=0x0F;
   delay_ms(1000);
   PORTD=0xF0;
   delay_ms(1000);
   PORTD=0x0F;
   delay_ms(1000);
}

void main()
{

   //Puerto D como salida para los LEDs
   TRISD=0x00;
   //Puerto B PINB0 y PINB1 como entradas para los botones
   TRISB=0b11000000;
   
   
   //INTCON
   //Bit 7 para las interrupciones globales (1 para habilitar)
   //Bit 6 para las interrupciones de los perifericos (0 para deshabilitar)
   //Bit 5 para la interrupcion del TMR0
   //Bit 4 para la interrupcion externa del INT0 (1 para habilitar)
   //Bit 3 para la interrupcion RB cambio de puerto
   //Bit 2 para la interrupcion por bandera del TMR0
   //Bit 1 para la interrupcion por bandera del INT0 externo
   //Bit 0 para la interrupcion por bandera de RB cambio de puerto
   INTCON=0b10010000;
   
   //INTCON2
   //Bit 7 para pull-ups del puerto B
   //Bit 6 para interrupcion externa 0 edge //Flanco de subida cambiar a 1
   //Bit 5 para interrupcion externa 1 edge //Flanco de subida cambiar a 1
   //Bit 4 para interrupcion externa 2 edge
   //Bit 3 se lee como 0
   //Bit 2 para interrupcion con prioridad del TMR0
   //Bit 1 se lee como 0
   //Bit 0 para interrupcion con prioridad del puerto RB
   INTCON2=0b11000000;
   
   //INTCON3
   //Bit 7 para la interrupcion con prioridad del INT2 (1 PARA HIGH, 0 PARA LOW)
   //Bit 6 para la interrupcion con prioridad del INT1 (1 PARA HIGH, 0 PARA LOW)
   //Bit 5 se lee como 0
   //Bit 4 para habilitar la interrupcion INT2
   //Bit 3 para habilitar la interrupcion INT1
   //Bit 2 se lee como 0
   //Bit 1 para la interrupcion externa INT2 con bandera
   //Bit 0 para la interrupcion externa INT1 con bandera
   INTCON3=0b00001000;
   
   //enable_interrupts(GLOBAL);
   //enable_interrupts(int_ext);
   //enable_interrupts(int_ext1);

   while(TRUE)
   {
      for(i=0;i<255;i++)
      {
         PORTD=i;
         delay_ms(200);
      
      }
   }

}
