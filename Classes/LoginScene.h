#pragma once
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Tools.h"
#include "SocketService.h"
#include "SelectPlayerScene.h"

USING_NS_CC;
using namespace ui;
class LoginScene :public Layer,public EditBoxDelegate
{
public:
	CREATE_FUNC(LoginScene);

	static Scene* createScene();

	bool init();

	void initLoginLayer();//��ʼ����¼����

	void initSelectServiceLayer();//��ʼ��ѡ�����������

	void initRegisterLayer();  //��ʼ��ע���

	void update(float delta);

	virtual void editBoxReturn(EditBox* editBox);
	virtual void editBoxTextChanged(EditBox* editBox, const std::string& text);

	void callBack(Ref* r, Widget::TouchEventType type);
public:
	Size size;
	EditBox* accountEdit;//�˺������
	EditBox* passwordEdit;//���������
	Layer* loginLayer;    //��½��
	Layer* SelectServiceLayer;//ѡ���������
	Layer* registerLayer;   //ע���
	string accountStr;    //�洢�˺��ַ���
	string passwordStr;   //�洢�����ַ���

};

