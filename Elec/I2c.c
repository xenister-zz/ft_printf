#include <xc.h>
#include <sys/attribs.h>

void	i2c_init(void)
{

	I2C1CONbits.PCIE	//Stop condition interrupt flag
	I2C1CONbits.SCIE	//Strat confition interrupt flag
	I2C1CONbits.ACKDT		//Acknowledge data bit
	I2C1CONbits.ACKen		//Acknowlegde enable bit
	I2C1CONbits.A10M = 0;	//set I2CxADD as 7-bit slave address
	I2C1CONbits.AHEN		//Adress hold enable bit -> 0 = Disable
	I2C1CONbits.DHEN		//Data hold enable bit -> 0 = Disable
	I2C1CONbits.ON			//I2C Enable bit
	I2C1CONbits.RCEN		//Receive enable bit
	I2C1CONbits.PEN			//Stop condition enable bit
	I2C1CONbits.RSEN		//Restart condition enable bit
	I2C1CONbits.SEN			//Start condition enable bit


	I2C1STATbits.ACKSTAT	//Acknowlegde status bit -> 0 = Received
	I2C1STATbits.TRSTAT		//Stransmit status bit -> 0 = Master transmit is not in progess
	I2C1STATbits.
}
