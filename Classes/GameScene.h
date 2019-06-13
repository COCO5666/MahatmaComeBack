#pragma once
#include "cocos2d.h"
#include <string.h>
#include "Player.h"
#include <vector>
#include "ShortestPathStep.h"
#include "SocketService.h"
#include "ui/CocosGUI.h"
#include "cocostudio/ActionTimeline/CSLoader.h"
USING_NS_CC;
using namespace std;
using namespace ui;
class GameScene :public Layer, public EditBoxDelegate
{
public:
	static GameScene* create(string json);

	static Scene* createScene(string json);

	bool init(string json);

	void updatePlayerDirection(Vec2 point);

	void update(float delta);
public: //�Զ�Ѱ·
	void moveTowardPoint(Vec2 point);//�ƶ���Ŀ���

	Vec2 tileCoordForPosition(Vec2 point);//������ת����ͼ������

	bool isWallAtTileCoord(Vec2 tilecoord);

	Vec2 moveMap(Vec2 point);//�ƶ���ͼ

	void insertInOpenSteps(ShortestPathStep* step);//��·�����뵽open����

	int computeHScoreFromCoordToCoord(Vec2 fromCoord, Vec2 toCoord);//��������֮������·��

	int costToMoveFromStepToAdjacentStep(ShortestPathStep *fromStep, ShortestPathStep *toStep);

	vector<Vec2> walkableAdjacentTilesCoordForTileCoord(Vec2 tileCoord);//������Χ�Ŀ������

	int getStepIndex(Vector<ShortestPathStep*> steps, ShortestPathStep* step);

	void playAnimate();

	virtual void editBoxReturn(EditBox* editBox);

	virtual void editBoxTextChanged(EditBox* editBox, const std::string& text);

	void sendMessageCallBack(Ref* r, Widget::TouchEventType type);
public:

	Player* player;
	TMXTiledMap* map;

	Vector<Sprite*>nearplayers;

	Vector<ShortestPathStep*> openSteps;
	Vector<ShortestPathStep*> closeSteps;


	Node* messageNode;

	ListView* listview;

	string message;
};

