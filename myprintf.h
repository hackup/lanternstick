#ifndef __MYPRINTF_H__
#define __MYPRINTF_H__

int serial_putc( char c, FILE * ) 
{
    Serial.write( c );
    return c;
} 

void printf_begin(void)
{
    fdevopen( &serial_putc, 0 );
}

#endif // __MYPRINTF_H__

