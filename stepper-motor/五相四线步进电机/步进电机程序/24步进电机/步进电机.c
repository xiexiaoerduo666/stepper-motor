/******************************�������������************************************* 
;FOSC = 12MHz 
;--------------------------------------------------------------------------------- 
; ��������������źű���Ϊ�����ź�!!! ת�����ٶȺ������Ƶ�ʳ�����!!! 
; ���������������Ϊ 5.625/61�� . һȦ 360 �� , ��Ҫ4096���������!!! 
;---------------------------------------------------------------------------------
 ; A����Ȧ��Ӧ P0.0 ; B����Ȧ��Ӧ P0.1 ; C����Ȧ��Ӧ P0.2 ; D����Ȧ��Ӧ P0.3 
; ��ת����: AB��--BC��--CD��--DA�� (��һ������,��ת5.625��) 
;---------------------------------------------------------------------------------- 
**********************************************************************************/  
/*ͷ�ļ�*/ 
#include <reg52.h>       
#include <intrins.h> 
#define uint unsigned int
#define uchar unsigned char 
#define nop() _nop_()  
uchar code table1[]={0x03,0x06,0x0c,0x09};  /*��ת��*/ 
uchar code table2[]={0x03,0x09,0x0c,0x06};  /*��ת��*/
#define motor P0   

void delay(uchar ms) /*��ʱ*/
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
  
  //��ת1Ȧ��4096������   j=0; 
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
 
  //��ת1Ȧ��4096������   j=0; 
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
//unsigned char code F_Rotation[4]={0x02,0x04,0x08,0x10};//��ת���
//unsigned char code B_Rotation[4]={0x03,0x09,0x0c,0x06};//��ת���
//
//void Delay(unsigned int i)//��ʱ
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
//  for(i=0;i<4;i++)      //4��
//     {
//     P0=B_Rotation[i];  //�����Ӧ���� �������л��ɷ�ת���
//     Delay(500);        //�ı�����������Ե������ת��
//	 }
//  Delay1000ms();
//  for(i=0;i<4;i++)      //4��
//     {
//     P0=F_Rotation[i];  //�����Ӧ���� �������л��ɷ�ת���
//     Delay(500);        //�ı�����������Ե������ת��
//	 }
//  }
//}