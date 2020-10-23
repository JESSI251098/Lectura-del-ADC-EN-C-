//INSTITUTO TECNOLOGICO SUPERIOR DE COATZACOALCOS 
//EQUIPO= LA EGG-CELENCIA 
//INGENIERIA MECATRÓNICA    Práctica 1: LECTURA DE ADC EN C
//MATERIA: MICROCONTROLADORES
// INTEGRANTES:
// Agustín Madrigal Luis           17080167           imct17.lagustinm@itesco.edu.mx
//Cruz Gallegos Isaac             17080186           imct17.icruzg@itesco.edu.mx
//Godínez Palma Jessi Darissel    17080205 	         imct17.jgodinezp@itesco.edu.mx
//Guzmán García Omar de Jesús     17080211           imct17.oguzmang@itesco.edu.mx
//Medina Ortiz Mauricio           17080237           imct17.mmedinao@itesco.edu.mx
//Méndez Osorio Julia Vanessa     17080238           imct17.jmendezo@itesco.edu.mx
//DOCENTE: JORGE ALBERTO SILVA VALENZUELA
//SEMESTRE: 7 °     GRUPO: A
//FECHA:  22 / 10 / 2020
//librerias 
#include <pic16f887.h>  
#include <xc.h>
#define _XTAL_FREQ 4000000
#define ADC 10
// CONFIG1 2007
#pragma config FOSC = INTRC_NOCLKOUT
#pragma config WDTE = OFF       
#pragma config PWRTE = ON       
#pragma config MCLRE = ON       
#pragma config CP = OFF         
#pragma config CPD = OFF        
#pragma config BOREN = OFF      
#pragma config IESO = OFF       
#pragma config FCMEN = OFF      
#pragma config LVP = OFF       

// CONFIG2 2008
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

void main(void) {
    
    
    //OSCCONbits.SCS=0b00;
    ANSEL =0XFF;
    
    TRISA=1; //ENTRADA
    TRISD=0;
    TRISC=0;
    ADCON1bits.VCFG0=0;
    ADCON1bits.VCFG1=0;
    ADCON1bits.ADFM=1;
    ADCON0=0b01000001;
    
    while(1)	//ciclo constante de trabajo
    {
        //ADCON0bits.GO_nDONE=1;
        ADCON0bits.GO_DONE=1;
        while(ADCON0bits.GO_DONE==1);
        PORTD=ADRESL;
        PORTC=ADRESH;
    }
    return;
}
