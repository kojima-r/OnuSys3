/*
 * SerialController.cpp
 *
 *  Created on: 2013/10/22
 *      Author: susrobo
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include "SerialController.h"

using namespace std;

SerialController::SerialController():openFlag(false) {
	// TODO Auto-generated constructor stub

}

SerialController::~SerialController() {
	// TODO Auto-generated destructor stub
}

void SerialController::setDefault(unsigned int baudrate ){
	bzero(&newtio, sizeof(newtio)); // 新しいポートの設定の構造体をクリアする

		/*
	BAUDRATE: ボーレートの設定．cfsetispeed と cfsetospeed も使用できる．
	CRTSCTS : 出力のハードウェアフロー制御 (必要な結線が全てされているケー
	ブルを使う場合のみ．Serial-HOWTO の7章を参照のこと)
	CS8     : 8n1 (8 ビット，ノンパリティ，ストップビット 1)
	CLOCAL  : ローカル接続，モデム制御なし
	CREAD   : 受信文字(receiving characters)を有効にする．
		 */
		newtio.c_cflag = baudrate | CRTSCTS | CS8 | CLOCAL | CREAD;

		/*
	IGNPAR  : パリティエラーのデータは無視する
	ICRNL   : CR を NL に対応させる(これを行わないと，他のコンピュータで
	CR を入力しても，入力が終りにならない)
	それ以外の設定では，デバイスは raw モードである(他の入力処理は行わない)
		 */
		newtio.c_iflag = IGNPAR ;//| ICRNL;

		/*
		   Raw モードでの出力
		 */
		newtio.c_oflag = 0;

		/*
	ICANON  : カノニカル入力を有効にする
	全てのエコーを無効にし，プログラムに対してシグナルは送らせない
		 */
		newtio.c_lflag = 0;//ICANON;

		/*
		   全ての制御文字を初期化する
		   デフォルト値は /usr/include/termios.h を見れば分かるが，コメントに書
		   いてあるので，ここでは見る必要はない．
		 */
		newtio.c_cc[VINTR]    = 0;     /* Ctrl-c */
		newtio.c_cc[VQUIT]    = 0;     /* Ctrl-\ */
		newtio.c_cc[VERASE]   = 0;     /* del */
		newtio.c_cc[VKILL]    = 0;     /* @ */
		newtio.c_cc[VEOF]     = 0;     /* Ctrl-d */
		//タイムアウト設定
		newtio.c_cc[VTIME]    = 1;    // *1/10sec
		newtio.c_cc[VMIN]     = 0;     //最低の受信
		//タイムアウト設定なし
		//newtio.c_cc[VTIME]    = 0;   // *1/10sec
		//newtio.c_cc[VMIN]     = 1;   // 1文字来るまで，読み込みをブロック

		newtio.c_cc[VSWTC]    = 0;     /* '\0' */
		newtio.c_cc[VSTART]   = 0;     /* Ctrl-q */
		newtio.c_cc[VSTOP]    = 0;     /* Ctrl-s */
		newtio.c_cc[VSUSP]    = 0;     /* Ctrl-z */
		newtio.c_cc[VEOL]     = 0;     /* '\0' */
		newtio.c_cc[VREPRINT] = 0;     /* Ctrl-r */
		newtio.c_cc[VDISCARD] = 0;     /* Ctrl-u */
		newtio.c_cc[VWERASE]  = 0;     /* Ctrl-w */
		newtio.c_cc[VLNEXT]   = 0;     /* Ctrl-v */
		newtio.c_cc[VEOL2]    = 0;     /* '\0' */

}
int SerialController::send(const void* ptr,size_t n){
	return write(fd,ptr,n);
}
int SerialController::recv(void* ptr,unsigned int n){
	int ret=read(fd,ptr,n);
	return ret;
}
int SerialController::recvAll(void* ptr,unsigned int n){
	int ret=0;
	int cnt=0;
	do{
		if(ptr!=NULL){
		ret=read(fd,(unsigned char*)ptr+cnt,1);
		cnt+=ret;
		}else{
			char temp[1];
			ret=read(fd,temp,1);
		}
	}while(ret!=0);
	return ret;
}
void SerialController::recvClear(){
	tcflush(fd,TCIFLUSH);
}
void SerialController::close(){
	if(openFlag){
		openFlag=false;
		tcsetattr(fd,TCSANOW,&oldtio);
		::close(fd);
	}
}
void SerialController::setTimeout(int t){
	//タイムアウト設定
	newtio.c_cc[VTIME]    = t;    // *1/10sec
	newtio.c_cc[VMIN]     = 0;     //最低の受信
	tcsetattr(fd,TCSANOW,&newtio);
}
void SerialController::init(int baudrate,const string& devname){

	//   読み書きのためにモデムデバイスをオープンする．ノイズによって CTRL-C
	//   がたまたま発生しても接続が切れないように，tty 制御はしない．
	fd = ::open(devname.c_str(), O_RDWR | O_NOCTTY );
	if (fd <0) {perror(devname.c_str()); exit(-1); }
	tcgetattr(fd,&oldtio); // 現在のシリアルポートの設定を待避させる
	setDefault(baudrate);
	//  モデムラインをクリアし，ポートの設定を有効にする
	tcflush(fd, TCIFLUSH);
	tcsetattr(fd,TCSANOW,&newtio);
	openFlag=true;
}
