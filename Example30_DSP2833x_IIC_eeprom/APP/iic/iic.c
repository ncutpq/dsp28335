/*
 * iic.c
 *
 *  Created on: 2018-2-5
 *      Author: Administrator
 */

#include "iic.h"


/*******************************************************************************
* 函 数 名         : IIC_Init
* 函数功能		   : IIC初始化
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void IICA_Init(void)
{
	EALLOW;
	SysCtrlRegs.PCLKCR3.bit.GPIOINENCLK = 1;// 开启GPIO时钟
	GpioCtrlRegs.GPBPUD.bit.GPIO32 = 0;	  	//上拉
	GpioCtrlRegs.GPBDIR.bit.GPIO32 = 1;   	// 输出端口
	GpioCtrlRegs.GPBMUX1.bit.GPIO32 = 0;  	// IO口
	GpioCtrlRegs.GPBQSEL1.bit.GPIO32 = 3; 	// 不同步

	GpioCtrlRegs.GPBPUD.bit.GPIO33 = 0;	  	//上拉
	GpioCtrlRegs.GPBDIR.bit.GPIO33 = 1;   	// 输出端口
	GpioCtrlRegs.GPBMUX1.bit.GPIO33 = 0;  	// IO口
	GpioCtrlRegs.GPBQSEL1.bit.GPIO33 = 3;   // 不同步
	EDIS;
}

/*******************************************************************************
* 函 数 名         : SDA_OUT
* 函数功能		   : SDA输出配置
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void SDA_OUT(void)
{
	EALLOW;
	GpioCtrlRegs.GPBDIR.bit.GPIO32=1;       //Output. SDA
	EDIS;
}

/*******************************************************************************
* 函 数 名         : SDA_IN
* 函数功能		   : SDA输入配置
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void SDA_IN(void)
{
	EALLOW;
	GpioCtrlRegs.GPBDIR.bit.GPIO32=0;       //Input, SDA
	EDIS;
}

/*******************************************************************************
* 函 数 名         : IIC_Start
* 函数功能		   : 产生IIC起始信号
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void IIC_Start(void)
{
	SDA_OUT();     //sda线输出
	IIC_SDA_SETH;   // 空闲状态,两条总线均被上拉为高电平
	IIC_SCL_SETH;
	DELAY_US(5);
	IIC_SDA_SETL;//START:SCL高期间，SDA变低
	DELAY_US(6);
	IIC_SCL_SETL;//钳住I2C总线，准备发送或接收数据
}

/*******************************************************************************
* 函 数 名         : IIC_Stop
* 函数功能    : 产生IIC停止信号
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void IIC_Stop(void)
{
	SDA_OUT(); //sda线输出
	IIC_SCL_SETL;
	IIC_SDA_SETL;  // 拉低SDA，否则无法产生由低到高的跳变
	IIC_SCL_SETH;  // SCL高电平
 	DELAY_US(6);
 	IIC_SDA_SETH;  //STOP:SCL高期间，SDA由低变高
	DELAY_US(6);
}

/*******************************************************************************
* 函 数 名         : IIC_Wait_Ack
* 函数功能	 : 等待应答信号到来
* 输    入         : 无
* 输    出         : 1，接收应答失败
        			 0，接收应答成功
*******************************************************************************/
unsigned char IIC_Wait_Ack(void)
{
	unsigned char tempTime=0;

	IIC_SDA_SETH;  //先将数据线拉高,看看有没有应答信号将其拉低
	DELAY_US(1);
	SDA_IN();      //SDA设置为输入
	IIC_SCL_SETH;  //时钟线拉高,准备读数据
	DELAY_US(1);
	while(READ_SDA) //未收到应答,准备产生停止位
	{
		tempTime++;
		if(tempTime>250)
		{
			IIC_Stop();
			return 1;
		}
	}
	IIC_SCL_SETL; //时钟线拉低,准备传输下一帧的数据
	return 0;
}

/*******************************************************************************
* 函 数 名         : IIC_Ack
* 函数功能	 : 产生ACK应答
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void IIC_Ack(void)
{
	IIC_SCL_SETL;  //时钟线拉低,准备放数据
	SDA_OUT();  //SDA输出状态才可以控制GPIO电平
	IIC_SDA_SETL; //数据线SDA输出低电平（应答）
	DELAY_US(2);  // 延时时长根据不同的IIC设备而定
	IIC_SCL_SETH;  //时钟线拉高,准备读数据
	DELAY_US(5);
	IIC_SCL_SETL; //时钟线拉低,准备传输下一帧的数据
}

/*******************************************************************************
* 函 数 名         : IIC_NAck
* 函数功能	 : 产生NACK非应答
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void IIC_NAck(void)
{
	IIC_SCL_SETL;
	SDA_OUT();
	IIC_SDA_SETH;
	DELAY_US(2);
	IIC_SCL_SETH;
	DELAY_US(5);
	IIC_SCL_SETL;
}

/*******************************************************************************
* 函 数 名         :  IIC_Send_Byte
* 函数功能	 : IIC发送一个字节
* 输    入         : txd：发送一个字节
* 输    出         : 无
*******************************************************************************/
void IIC_Send_Byte(unsigned char txd)
{
	unsigned char t;
	SDA_OUT(); //SDA设置为输出
	IIC_SCL_SETL; //拉低时钟，往SDA放数据
    for(t=0;t<8;t++)
    {
        // 将待发送的数据模拟为SDA线上的高低电平
        if((txd&0x80)>0) //0x80  1000 0000
        	IIC_SDA_SETH;
		else
			IIC_SDA_SETL;
        txd<<=1;   //每次将txd中的最高位是否为1，判断完之后向左移位，将下一位放到最高位
        DELAY_US(2);   //对TEA5767这三个延时都是必须的
        IIC_SCL_SETH;   //拉高时钟,让接收端读取数据
		DELAY_US(2);
		IIC_SCL_SETL; //拉低时钟，往SDA放数据
		DELAY_US(2);
    }
}

/*******************************************************************************
* 函 数 名         : IIC_Read_Byte
* 函数功能	: IIC读一个字节
* 输    入         : ack=1时，发送ACK，ack=0，发送nACK
* 输    出         : 应答或非应答
*******************************************************************************/
unsigned char IIC_Read_Byte(unsigned char ack)
{
	unsigned char i,receive=0;
	SDA_IN();   //SDA设置为输入
    for(i=0;i<8;i++ )
	{
    	IIC_SCL_SETL; //拉低时钟,让从机放数据
    	DELAY_US(2);
        IIC_SCL_SETH; //拉高时钟,读取数据
        receive<<=1; //接收到数据后左移,放到高位,腾出当前位接收新的数据
        if(READ_SDA)receive++; //如果接收到高电平,将当前位设为1
        DELAY_US(1);
    }
    if (!ack)
        IIC_NAck();//发送nACK
    else
        IIC_Ack(); //发送ACK
    return receive;
}

