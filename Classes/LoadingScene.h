#ifndef ____LOADINGSCENE_____
#define ____LOADINGSCENE_____

#include "cocos2d.h"
#include <iostream>
#include <vector>
#include "ui/CocosGUI.h"
using namespace std;
USING_NS_CC;
using namespace ui;
class LoadingScene :public Layer
{
public:
	float totalnumber;        //�ܹ�Ҫ���ص���Դ��Ŀ
	float alreadynumber;      //�Ѿ����ص���Դ��Ŀ
	vector<string> audioPath; //���������Դ����Ŀ
	vector<string> plistPath;  //���plist��Դ·��������
	vector<string> pngPath;    //���png��Դ·��������
	ProgressTimer* loadingbar; //����������
public:
	CREATE_FUNC(LoadingScene);

	static Scene* createScene();

	bool init();

	void callBack(Texture2D* texture);

	void plistCallBack(Texture2D* texture, int i);
	
};

#endif // ____LOADINGSCENE_____