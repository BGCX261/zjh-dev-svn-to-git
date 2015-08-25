#ifndef _UI_DEF_H_
#define _UI_DEF_H_

class UI_ZOrder
{
public:
	static const int SLOTS_CONTAINER = 10;
	static const int NORMAL_SLOT = 11;
	static const int WINLINE = 18;
	static const int WIN_SLOT = 30;
	static const int WINFRAME = 31;
	static const int WINTEXT = 32;
};

class UI_IdDef
{
public:
	// Info bar
	static const int INFOBAR_UIFRAME = 90;
	static const int INFOBAR_BTN_SHOW = 100;
	static const int INFOBAR_BTN_CHANGEGAME = 101;
	static const int INFOBAR_BTN_ENTRYLEVEL = 102;
	static const int INFOBAR_BTN_MAXENTRY = 103;
	static const int INFOBAR_PIC_WIN = 104;
	static const int INFOBAR_LABEL_WIN = 105;
	static const int INFOBAR_PIC_WINPOINTS = 106;
	static const int INFOBAR_LABEL_WINPOINTS = 107;
	static const int INFOBAR_PIC_ENTRYLEVEL = 108;
	static const int INFOBAR_LABEL_ENTRYLEVEL = 109;

	//freespin
	static const int FREESPIN_FRAME = 1000;
	static const int FREESPIN_CONGRATION_ANIM = 1001;
	static const int FREESPIN_CONGRATION_LABEL = 1002;
};

#endif /* _UI_DEF_H_ */
