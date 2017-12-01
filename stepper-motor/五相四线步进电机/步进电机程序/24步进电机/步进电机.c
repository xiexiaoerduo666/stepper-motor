/******************************步进电机的驱动************************************* 
;FOSC = 12MHz 
;--------------------------------------------------------------------------------- 
; 步进电机的驱动信号必须为脉冲信号!!! 转动的速度和脉冲的频率成正比!!! 
; 本步进电机步进角为 5.625/61度 . 一圈 360 度 , 需要4096个脉冲完成!!! 
;---------------------------------------------------------------------------------
 ; A组线圈对应 P0.0 ; B组线圈对应 P0.1 ; C组线圈对应 P0.2 ; D组线圈对应 P0.3 
; 正转次序: AB组--BC组--CD组--DA组 (即一个脉冲,正转5.625度) 
;---------------------------------------------------------------------------------- 
**********************************************************************************/  
/*头文件*/ 
#include <reg52.h>       
#include <intrins.h> 
#define uint unsigned int
#define uchar unsigned char 
#define nop() _nop_()  
uchar code table1[]={0x03,0x06,0x0c,0x09};  /*正转表*/ 
uchar code table2[]={0x03,0x09,0x0c,0x06};  /*反转表*/
#define motor P0   

void delay(uchar ms) /*延时*/
 { 
    uchar j;    
	 while(ms--)
	 { 
        for(j=0;j<250;j++)           
		  {;}        
	 }    
 } 
void Delay1000ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 43;
	j = 6;
	k = 203;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void main() 
{ 
 uchar i,j;  
  
  //正转1圈共4096个脉冲   j=0; 
  for(i=0;i<2;i++)
  {   
   motor = 0x00; 
   motor = table2[j];   
   j++; 
   if(j>=4)
   j=0;
   delay(2); 
  } 
  delay(200);  
  delay(200); 
  delay(200);   
  delay(200);   
  delay(200);  
 
  //反转1圈共4096个脉冲   j=0; 
  for(i=0;i<4096;i++)
  {    
   motor = 0x00; 
   motor = table2[j];   
   j++; 
   if(j>=4)
   j=0;  
   delay(2);  
  } 
  delay(200); 
  delay(200);  
  delay(200); 
  delay(200);  
  delay(200);      
  }  
   
















//
//
//#include <reg52.h>
//#include<intrins.h>
//
//unsigned char code F_Rotation[4]={0x02,0x04,0x08,0x10};//正转表格
//unsigned char code B_Rotation[4]={0x03,0x09,0x0c,0x06};//反转表格
//
//void Delay(unsigned int i)//延时
//{
// while(--i);
//}
//
//void Delay1000ms()		//@11.0592MHz
//{
//	unsigned char i, j, k;
//
//	_nop_();
//	_nop_();
//	i = 43;
//	j = 6;
//	k = 203;
//	do
//	{
//		do
//		{
//			while (--k);
//		} while (--j);
//	} while (--i);
//}
//
//
//main()
//{
// 
// unsigned char i;
//
// while(1)
// {
//  for(i=0;i<4;i++)      //4相
//     {
//     P0=B_Rotation[i];  //输出对应的相 可以自行换成反转表格
//     Delay(500);        //改变这个参数可以调整电机转速
//	 }
//  Delay1000ms();
//  for(i=0;i<4;i++)      //4相
//     {
//     P0=F_Rotation[i];  //输出对应的相 可以自行换成反转表格
//     Delay(500);        //改变这个参数可以调整电机转速
//	 }
//  }
//}