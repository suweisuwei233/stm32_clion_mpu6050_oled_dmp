//
// Created by 18292649286 on 2022/10/16.
//

#ifndef INC_06_DEMO_GAME_OLED12864_H
#define INC_06_DEMO_GAME_OLED12864_H
#include "main.h"
#define OLED_MODE 0
#define SIZE 8
#define XLevelL		0x00
#define XLevelH		0x10
#define Max_Column	128
#define Max_Row		64
#define	Brightness	0xFF
#define X_WIDTH 	128
#define Y_WIDTH 	64

#define u8 unsigned char
#define u32 unsigned int
//-----------------OLED IIC端口定义----------------
/**
 * GPIOB3 -> SCL
 * GPIOB4 -> SDA
 */

#define OLED_SCLK_Clr() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET) //GPIOB_3//SCL
#define OLED_SCLK_Set() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET) //GPIO_SetBits(GPIOA,GPIO_Pin_5)

#define OLED_SDIN_Clr() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET) // GPIO_ResetBits(GPIOA,GPIO_Pin_7)//SDA
#define OLED_SDIN_Set() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET) // GPIO_SetBits(GPIOA,GPIO_Pin_7)


#define OLED_CMD  0	//写命令
#define OLED_DATA 1	//写数据


//OLED控制用函数
void OLED_WR_Byte(unsigned dat,unsigned cmd);
void OLED_DisplayOn(void);
void OLED_DisplayOff(void);
void OLED_Init(void);
void OLED_Clear(void);
void OLED_DrawPoint(u8 x,u8 y,u8 t);
void OLED_Fill(u8 x1,u8 y1,u8 x2,u8 y2,u8 dot);
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 Char_Size);
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size);
void OLED_ShowString(u8 x,u8 y, u8 *p,u8 Char_Size);
void OLED_SetPos(unsigned char x, unsigned char y);

void OLED_DrawBMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char BMP[]);
void Delay_50ms(unsigned int Del_50ms);
void Delay_1ms(unsigned int Del_1ms);
void OLED_FillPicture(unsigned char fill_Data);
void Picture();
void IIC_Start();
void IIC_Stop();
void IIC_WriteCommand(unsigned char IIC_Command);
void IIC_WriteData(unsigned char IIC_Data);
void IIC_WriteByte(unsigned char IIC_Byte);

void IIC_WaitAck();

// 快速绘制图像
void OLED_DrawBMPFast(unsigned char BMP[]);

// 显示地面
void OLED_DrawGround();

// 绘制云朵
void OLED_DrawCloud();

// 绘制小恐龙
void OLED_DrawDino();

// 绘制仙人掌障碍物
void OLED_DrawCactus();

// 绘制跳跃小恐龙
int OLED_DrawDinoJump(char reset);

// 绘制随机出现的仙人掌障碍物
int OLED_DrawCactusRandom(unsigned char ver, unsigned char reset);

// 绘制重启
void OLED_DrawRestart();
// 绘制封面
void OLED_DrawCover();

//绘制跳动
void OLED_DrawJump();
//绘制小恐龙 通过 小恐龙 16x32 左上方的(x,y)坐标
//OLED_SetPos(16,y) x 限定为 16  y的高度限定 y:[6:4]
//同时修改结构体
void OLED_Draw_Dino_By_X_Y(unsigned int x,unsigned int y );
//清空绘制小恐龙容器
void Clear_Draw_Container();

/**
 * OLED  显示小数函数
 * @param x
 * @param y
 * @param num
 * @param z_len
 * @param f_len
 * @param size2
 */
void OLED_Showdecimal(u8 x,u8 y,float num,u8 z_len,u8 f_len,u8 size2);

#endif //INC_06_DEMO_GAME_OLED12864_H
