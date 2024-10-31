#ifndef STRUCT
#define STRUCT
typedef struct admin      //管理员--结构体
{
	int ID;               //管理员账户
	char code[50];        //管理员密码 
}ADM;

typedef struct package    //套餐--结构体
{
	int ID;               //套餐账户
	char name[25];        //套餐名称
	float money;          //套餐价格
	float mobileData4G;   //套餐4G流量
	float mobileData5G;   //套餐5G流量
	float callDuration;   //套餐通话时长
	int Broadband;        //套餐宽带带宽
}PKG;

typedef struct user       //用户--结构体
{
	int ID;               //用户账户
	char code[50];        //用户密码 
	char name[25];        //用户用户名
	float balance;        //用户余额
	int packageID;          //用户套餐ID
}USER;

#endif 

