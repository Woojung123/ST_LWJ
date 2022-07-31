#include "PreCompile.h"
#include "ContentsCore.h"
#include "GameEngineContents/StageLogo.h"
#include "GameEngineContents/StageMain.h"

#pragma comment(lib, "GameEngineBase.lib")

ContentsCore::ContentsCore() 
	: GameEngineCore()
{
}

ContentsCore::~ContentsCore() 
{
}

void ContentsCore::Start()
{

	
	// ���ҽ� �ε� ����
	
	//Main UI
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("UI");

		std::vector<GameEngineFile> Shaders = Dir.GetAllFile();

		for (size_t i = 0; i < Shaders.size(); i++)
		{
			GameEngineTexture::Load(Shaders[i].GetFullPath());
		}


	}

	//logo Button
	{


		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("MenuUI");

		Dir.Move("MenuExitCheck");
		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../MenuSinglePlayerCheck0");
		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../MenuEditor0");
		GameEngineFolderTexture::Load(Dir.GetFullPath());


	}

	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");

		std::vector<GameEngineFile> Shaders = Dir.GetAllFile();

		for (size_t i = 0; i < Shaders.size(); i++)
		{
			GameEngineTexture::Load(Shaders[i].GetFullPath());
		}


	}

	

	if (false == GameEngineInput::GetInst()->IsKey("LevelChangeKey"))
	{
		GameEngineInput::GetInst()->CreateKey("LevelChangeKey", 'P');
	}

	//���� 
	// ������Ʈ
	//���
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Unit");
		Dir.Move("protoss");
		Dir.Move("DragoonMain");


		Dir.Move("DragonAttack15");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../DragonStand0");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

	}


	//����ĳ��
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Building");
		Dir.Move("Cannon");
	


		Dir.Move("CannonAtt");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../CannonStand");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

	}


	//��ū
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Unit");
		Dir.Move("zerg");
		Dir.Move("Build");
		Dir.Move("sunken");
		Dir.Move("sunkenAtt");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../sunkenStand");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

	}

	//��Ʈ��
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Unit");
		Dir.Move("zerg");
		Dir.Move("ultra");


		Dir.Move("ultraMoveD");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../ultraMoveU");

		GameEngineFolderTexture::Load(Dir.GetFullPath());
		\
		Dir.Move("../ultraMoveL");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../ultraMoveR");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../ultraStand");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

	}


	//��Ʈ��1
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Unit");
		Dir.Move("zerg");
		Dir.Move("ultra");


		Dir.Move("ultraAttack0");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../ultraAttack1");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../ultraAttack2");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../ultraAttack3");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../ultraAttack4");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

	}

	//��Ʈ��2
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Unit");
		Dir.Move("zerg");
		Dir.Move("ultra");


		Dir.Move("ultraAttack5");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../ultraAttack6");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../ultraAttack7");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../ultraAttack8");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../ultraAttack9");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

	}


	//��Ʈ��3
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Unit");
		Dir.Move("zerg");
		Dir.Move("ultra");


		Dir.Move("ultraAttack10");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../ultraAttack11");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../ultraAttack12");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../ultraAttack13");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../ultraAttack14");

		GameEngineFolderTexture::Load(Dir.GetFullPath());


		Dir.Move("../ultraAttack15");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

	}


	//����1
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Unit");
		Dir.Move("protoss");
		Dir.Move("DarkT");


		Dir.Move("DarkTAttack0");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../DarkTAttack1");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../DarkTAttack2");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../DarkTAttack3");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../DarkTAttack4");

		GameEngineFolderTexture::Load(Dir.GetFullPath());


		Dir.Move("../DarkTStand12");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

	}

	//����2
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Unit");
		Dir.Move("protoss");
		Dir.Move("DarkT");


		Dir.Move("DarkTAttack5");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../DarkTAttack6");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../DarkTAttack7");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../DarkTAttack8");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../DarkTAttack9");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

	}


	//����3
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Unit");
		Dir.Move("protoss");
		Dir.Move("DarkT");


		Dir.Move("DarkTAttack10");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../DarkTAttack11");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../DarkTAttack12");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../DarkTAttack13");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../DarkTAttack14");

		GameEngineFolderTexture::Load(Dir.GetFullPath());


		Dir.Move("../DarkTAttack15");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

	}


	//�ƺ���1
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Unit");
		Dir.Move("protoss");
		Dir.Move("Arbitor");


		Dir.Move("ArbitorMove0");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../ArbitorMove1");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../ArbitorMove2");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../ArbitorMove3");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../ArbitorMove4");

		GameEngineFolderTexture::Load(Dir.GetFullPath());


		Dir.Move("../ArbitorMove5");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

	}

	//�ƺ���2
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Unit");
		Dir.Move("protoss");
		Dir.Move("Arbitor");


		Dir.Move("ArbitorMove6");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../ArbitorMove7");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../ArbitorMove8");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../ArbitorMove9");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../ArbitorMove10");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

	}


	//�ƺ���3
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Unit");
		Dir.Move("protoss");
		Dir.Move("Arbitor");


		Dir.Move("ArbitorMove11");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../ArbitorMove12");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../ArbitorMove13");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../ArbitorMove14");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../ArbitorMove15");

		GameEngineFolderTexture::Load(Dir.GetFullPath());



	}


	//�ƺ���3
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Unit");
		Dir.Move("protoss");
		Dir.Move("Archon");


		Dir.Move("aulora0");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

	}



	//�����ε�
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Unit");
		Dir.Move("zerg");
		Dir.Move("overload");


		Dir.Move("overloadD");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../overloadL");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../overloadR");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../overloadU");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

	}


	//��ٿ췯
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Unit");
		Dir.Move("zerg");
		Dir.Move("Divaoler");

		Dir.Move("DivaolerMoveD");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../DivaolerMoveU");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../DivaolerMoveL");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../DivaolerMoveR");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

	}

	//Ŀ����
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Unit");
		Dir.Move("protoss"); 
		Dir.Move("corsair");

		Dir.Move("corsairMoveD");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../corsairMoveU");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../corsairMoveL");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../corsairMoveR");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

	}

	//Ŀ����1
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Unit");
		Dir.Move("protoss");
		Dir.Move("corsair");

		Dir.Move("corsairAttack0");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../corsairAttack1");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../corsairAttack2");

		GameEngineFolderTexture::Load(Dir.GetFullPath());


		Dir.Move("../corsairAttack3");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../corsairAttack4");

		GameEngineFolderTexture::Load(Dir.GetFullPath());



	}
	//Ŀ����2
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Unit");
		Dir.Move("protoss");
		Dir.Move("corsair");


		Dir.Move("corsairAttack5");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../corsairAttack6");

		GameEngineFolderTexture::Load(Dir.GetFullPath());


		Dir.Move("../corsairAttack7");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../corsairAttack8");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../corsairAttack9");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../corsairAttack10");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

	}

	//Ŀ����3
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Unit");
		Dir.Move("protoss");
		Dir.Move("corsair");

		
		Dir.Move("corsairAttack11");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../corsairAttack12");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../corsairAttack13");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../corsairAttack14");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../corsairAttack15");

		GameEngineFolderTexture::Load(Dir.GetFullPath());



	}


	//�������÷�1
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Unit");
		Dir.Move("protoss");
		Dir.Move("hitempler");

		Dir.Move("hitemplerAttack0");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../hitemplerAttack1");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../hitemplerAttack2");

		GameEngineFolderTexture::Load(Dir.GetFullPath());


		Dir.Move("../hitemplerAttack3");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../hitemplerAttack4");

		GameEngineFolderTexture::Load(Dir.GetFullPath());



	}
	//�������÷�2
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Unit");
		Dir.Move("protoss");
		Dir.Move("hitempler");


		Dir.Move("hitemplerAttack5");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../hitemplerAttack6");

		GameEngineFolderTexture::Load(Dir.GetFullPath());


		Dir.Move("../hitemplerAttack7");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../hitemplerAttack8");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../hitemplerAttack9");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../hitemplerAttack10");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

	}

	//�������÷�3
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Unit");
		Dir.Move("protoss");
		Dir.Move("hitempler");


		Dir.Move("hitemplerAttack11");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../hitemplerAttack12");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../hitemplerAttack13");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../hitemplerAttack14");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../hitemplerAttack15");

		GameEngineFolderTexture::Load(Dir.GetFullPath());


		Dir.Move("../hitemplerMove12");

		GameEngineFolderTexture::Load(Dir.GetFullPath());



	}



	//��ī��
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Unit");
		Dir.Move("protoss");
		Dir.Move("Scout");
	
		Dir.Move("ScoutMoveD");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../ScoutMoveU");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../ScoutMoveL");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../ScoutMoveR");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

	}

	//��Ʈ1
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Unit");
		Dir.Move("Terran");
		Dir.Move("Ghost");

		Dir.Move("ChostStand");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../GhostAttack0");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../GhostAttack1");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../GhostAttack2");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../GhostAttack3");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../GhostAttack4");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../GhostAttack5");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../GhostAttack6");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

	


	}
	//��Ʈ2
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Unit");
		Dir.Move("Terran");
		Dir.Move("Ghost");

		Dir.Move("GhostAttack7");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../GhostAttack8");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../GhostAttack9");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../GhostAttack10");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../GhostAttack11");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../GhostAttack12");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../GhostAttack13");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../GhostAttack14");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../GhostAttack15");

		GameEngineFolderTexture::Load(Dir.GetFullPath());


	}



	//����1
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Unit");
		Dir.Move("Terran");
		Dir.Move("Marine");


		Dir.Move("MarrineStand");

		GameEngineFolderTexture::Load(Dir.GetFullPath());


		Dir.Move("../MarineAttack0");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../MarineAttack1");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../MarineAttack2");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../MarineAttack3");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../MarineAttack4");

		GameEngineFolderTexture::Load(Dir.GetFullPath());



	}
	//����2
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Unit");
		Dir.Move("Terran");
		Dir.Move("Marine");


		Dir.Move("MarineAttack5");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../MarineAttack6");

		GameEngineFolderTexture::Load(Dir.GetFullPath());


		Dir.Move("../MarineAttack7");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../MarineAttack8");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../MarineAttack9");

		GameEngineFolderTexture::Load(Dir.GetFullPath());



	}

	//����3
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Unit");
		Dir.Move("Terran");
		Dir.Move("Marine");


		Dir.Move("MarineAttack10");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../MarineAttack11");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../MarineAttack12");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../MarineAttack13");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../MarineAttack14");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../MarineAttack15");

		GameEngineFolderTexture::Load(Dir.GetFullPath());


	}



	//����1
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Unit");
		Dir.Move("protoss");
		Dir.Move("zelot");

		Dir.Move("zelotAttack0");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../zelotAttack1");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../zelotAttack2");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		
		Dir.Move("../zelotAttack3");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../zelotAttack4");

		GameEngineFolderTexture::Load(Dir.GetFullPath());



	}
	//����2
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Unit");
		Dir.Move("protoss");
		Dir.Move("zelot");


		Dir.Move("zelotAttack5");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../zelotAttack6");

		GameEngineFolderTexture::Load(Dir.GetFullPath());


		Dir.Move("../zelotAttack7");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../zelotAttack8");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../zelotAttack9");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../zelotStand12");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

	}

	//����3
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Unit");
		Dir.Move("protoss");
		Dir.Move("zelot");


		Dir.Move("zelotAttack10");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../zelotAttack11");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../zelotAttack12");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../zelotAttack13");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../zelotAttack14");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../zelotAttack15");

		GameEngineFolderTexture::Load(Dir.GetFullPath());


	}



	//�����1
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Unit");
		Dir.Move("zerg");
		Dir.Move("hidra");

		Dir.Move("hidraAttack0");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../hidraAttack1");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../hidraAttack2");

		GameEngineFolderTexture::Load(Dir.GetFullPath());


		Dir.Move("../hidraAttack3");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../hidraAttack4");

		GameEngineFolderTexture::Load(Dir.GetFullPath());



	}
	//�����2
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Unit");
		Dir.Move("zerg");
		Dir.Move("hidra");


		Dir.Move("hidraAttack5");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../hidraAttack6");

		GameEngineFolderTexture::Load(Dir.GetFullPath());


		Dir.Move("../hidraAttack7");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../hidraAttack8");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../hidraAttack9");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../hidraAttack10");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

	}

	//�����3
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Unit");
		Dir.Move("zerg");
		Dir.Move("hidra");


		Dir.Move("hidraAttack11");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../hidraAttack12");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../hidraAttack13");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../hidraAttack14");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../hidraAttack15");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../hidraMove12");

		GameEngineFolderTexture::Load(Dir.GetFullPath());


	}





	//���۸�1
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Unit");
		Dir.Move("zerg");
		Dir.Move("zergling");

		Dir.Move("zerglingAttack0");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../zerglingAttack1");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../zerglingAttack2");

		GameEngineFolderTexture::Load(Dir.GetFullPath());


		Dir.Move("../zerglingAttack3");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../zerglingAttack4");

		GameEngineFolderTexture::Load(Dir.GetFullPath());



	}
	//���۸�2
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Unit");
		Dir.Move("zerg");
		Dir.Move("zergling");


		Dir.Move("zerglingAttack5");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../zerglingAttack6");

		GameEngineFolderTexture::Load(Dir.GetFullPath());


		Dir.Move("../zerglingAttack7");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../zerglingAttack8");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../zerglingAttack9");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../zerglingAttack10");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

	}

	//���۸�3
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Unit");
		Dir.Move("zerg");
		Dir.Move("zergling");


		Dir.Move("zerglingAttack11");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../zerglingAttack12");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../zerglingAttack13");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../zerglingAttack14");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../zerglingAttack15");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../zerglingMove12");

		GameEngineFolderTexture::Load(Dir.GetFullPath());


	}






	//�����1
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Unit");
		Dir.Move("zerg");
		Dir.Move("Gardian");

		Dir.Move("GardianMove0");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../GardianMove1");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../GardianMove2");

		GameEngineFolderTexture::Load(Dir.GetFullPath());


		Dir.Move("../GardianMove3");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../GardianMove4");

		GameEngineFolderTexture::Load(Dir.GetFullPath());



	}
	//�����2
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Unit");
		Dir.Move("zerg");
		Dir.Move("Gardian");


		Dir.Move("GardianMove5");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../GardianMove6");

		GameEngineFolderTexture::Load(Dir.GetFullPath());


		Dir.Move("../GardianMove7");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../GardianMove8");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../GardianMove9");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../GardianMove10");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

	}

	//�����3
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Unit");
		Dir.Move("zerg");
		Dir.Move("Gardian");


		Dir.Move("GardianMove11");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../GardianMove12");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../GardianMove13");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../GardianMove14");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../GardianMove15");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

	

	}



	//�Ѿ�
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Bullet");
		
		Dir.Move("Draball");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../Mutalblt");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../storm");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../Spore");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../BolldBullet");

		GameEngineFolderTexture::Load(Dir.GetFullPath());


		/*Dir.Move("../storm");

		GameEngineFolderTexture::Load(Dir.GetFullPath());*/


	}


	////�Ѿ�2
	//{
	//	GameEngineDirectory Dir;

	//	Dir.MoveParentToExitsChildDirectory("ConstantResources");
	//	Dir.Move("ConstantResources");
	//	Dir.Move("Texture");
	//	Dir.Move("Multi");
	//	Dir.Move("Bullet");

	//	Dir.Move("HTstorm");

	//	GameEngineFolderTexture::Load(Dir.GetFullPath());
	//}

	//����Ʈ1
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Effect");

		Dir.Move("draboom");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../scoutblt");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../GardianDead0");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../tenta");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../SporeHit");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Dir.Move("../MutalDead0");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

	}

	//����Ʈ2
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Effect");

		Dir.Move("zspark");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

		
	}


	//�����佺 ���� ����Ʈ
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Texture");
		Dir.Move("Multi");
		Dir.Move("Unit");
		Dir.Move("protoss");
		Dir.Move("zelot");


		Dir.Move("zelotDead0");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

	
	}


	// ���ҽ� �ε� ��

	CreateLevel<StageLogo>("Title");
	CreateLevel<StageMain>("Play");
	ChangeLevel("Title");

	GameEngineGUI::CreateGUIWindow<GameEngineStatusWindow>("EngineStatus", nullptr);

}

void ContentsCore::Update(float _DeltaTime)
{
	
	
}

void ContentsCore::End()
{
}