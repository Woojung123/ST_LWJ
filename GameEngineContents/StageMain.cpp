

#include "PreCompile.h"
#include "StageMain.h"
#include "GlobalContentsValue.h"
#include <GameEngineCore/GameEngineCameraActor.h>
#include <GameEngineBase/GameEngineInput.h>

#include "MainMap.h"
#include "StageMainCamera.h"
#include "TestUnit.h"
#include "Overload.h"
#include "UltraMon.h"
#include "DivaolerMon.h"
#include "corsairMon.h"
#include "ScoutMon.h"
#include "GhostC.h"
#include "MarinC.h"
#include "ZealotC.h"
#include "CorsairC.h"
#include "HydraC.h"
#include "ZerglingC.h"
#include "GardianC.h"
#include "HighT.h"
#include "CannonB.h"
#include "UltraC.h"
#include "SunkenC.h"
#include "DarkTB.h"
#include "ArbitorB.h"



#include "TestUI.h"



StageMain::StageMain() :
	StartCheck(false),
	StartTime(1.f),//10
	GamePlayTime(0.f),
	MonCount(0),
	MonMax(20),//20
	MonTimeMax(0.5f),
	MonTime(0.f),
	StageCount(1)
{
}

StageMain::~StageMain()
{
}

void StageMain::Start()
{

	if (false == GameEngineInput::GetInst()->IsKey("FreeCameaOnOff"))
	{
		GameEngineInput::GetInst()->CreateKey("FreeCameaOnOff", 'O');
	}




	/*{
		GameEngineCameraActor* actor = CreateActor<GameEngineCameraActor>();
		actor->GetCameraComponent()->SetProjectionMode(CAMERAPROJECTIONMODE::Orthographic);
		actor->GetTransform().SetLocalPosition({ 0.0f, 0.0f, -500.0f });
	}*/


	{
		TestUI* NewPlayer = CreateActor<TestUI>(OBJECTORDER::UI);
	}



	MapPoint MapP;
	/*MapP.TurnPoint = float4(-1348.f, 617.f,1.f,0.f);
	CheckPoint.push_back(MapP);*/

	MapP.TurnPoint = float4(-1348.f, 424.f, 1.f, 0.f);
	CheckPoint.push_back(MapP);

	MapP.TurnPoint = float4(-682.f, 424.f, 1.f, 0.f);
	CheckPoint.push_back(MapP);

	MapP.TurnPoint = float4(-682.f, 604.f, 1.f, 0.f);
	CheckPoint.push_back(MapP);

	MapP.TurnPoint = float4(-924.f, 604.f, 1.f, 0.f);
	CheckPoint.push_back(MapP);

	MapP.TurnPoint = float4(-924.f, 62.f, 1.f, 0.f);
	CheckPoint.push_back(MapP);

	MapP.TurnPoint = float4(-681.f, 62.f, 1.f, 0.f);
	CheckPoint.push_back(MapP);

	MapP.TurnPoint = float4(-681.f, 245.f, 1.f, 0.f);
	CheckPoint.push_back(MapP);

	MapP.TurnPoint = float4(-1348.f, 245.f, 1.f, 0.f);
	CheckPoint.push_back(MapP);

	MapP.TurnPoint = float4(-1348.f, 62.f, 1.f, 0.f);
	CheckPoint.push_back(MapP);

	MapP.TurnPoint = float4(-1105.f, 62.f, 1.f, 0.f);
	CheckPoint.push_back(MapP);

	MapP.TurnPoint = float4(-1105.f, 633.f, 1.f, 0.f);
	CheckPoint.push_back(MapP);
	
	
	
	
	


	MainMap* NewMainMap;
	{
		NewMainMap = CreateActor<MainMap>(OBJECTORDER::BackGround);
	}


	StageMainCamera* NewMainCamera;

	{
		NewMainCamera = CreateActor<StageMainCamera>(OBJECTORDER::Camera);
	}

	{
		TestUnit* TestUni = CreateActor<TestUnit>(OBJECTORDER::Player);
		TestUni->GetTransform().SetWorldPosition({ -1050.f,370.f,0.f });
	}
	
	{
		GhostC* TestUni = CreateActor<GhostC>(OBJECTORDER::Player);
		TestUni->GetTransform().SetWorldPosition({ -990.f,370.f,0.f });
	}

	{
		MarinC* TestUni = CreateActor<MarinC>(OBJECTORDER::Player);
		TestUni->GetTransform().SetWorldPosition({ -990.f,310.f,0.f });
	}

	{
		ZealotC* TestUni = CreateActor<ZealotC>(OBJECTORDER::Player);
		TestUni->GetTransform().SetWorldPosition({ -1050.f,310.f,0.f });
	}

	{
		CorsairC* TestUni = CreateActor<CorsairC>(OBJECTORDER::Player);
		TestUni->GetTransform().SetWorldPosition({ -1050.f,190.f,0.f });
	}


	{
		HydraC* TestUni = CreateActor<HydraC>(OBJECTORDER::Player);
		TestUni->GetTransform().SetWorldPosition({ -990.f,190.f,0.f });
	}


	{
		ZerglingC* TestUni = CreateActor<ZerglingC>(OBJECTORDER::Player);
		TestUni->GetTransform().SetWorldPosition({ -870.f,370.f,0.f });
	}

	{
		GardianC* TestUni = CreateActor<GardianC>(OBJECTORDER::Player);
		TestUni->GetTransform().SetWorldPosition({ -870.f,310.f,0.f });
	}
	
	
	{
		HighT* TestUni = CreateActor<HighT>(OBJECTORDER::Player);
		TestUni->GetTransform().SetWorldPosition({ -810.f,310.f,0.f });
	}


	{
		CannonB* TestUni = CreateActor<CannonB>(OBJECTORDER::Player);
		TestUni->GetTransform().SetWorldPosition({ -1170.f,370.f,0.f });
	}

	{
		UltraC* TestUni = CreateActor<UltraC>(OBJECTORDER::Player);
		TestUni->GetTransform().SetWorldPosition({ -1170.f,310.f,0.f });
	}

	{
		SunkenC* TestUni = CreateActor<SunkenC>(OBJECTORDER::Player);
		TestUni->GetTransform().SetWorldPosition({ -1230.f,310.f,0.f });
	}

	{
		DarkTB* TestUni = CreateActor<DarkTB>(OBJECTORDER::Player);
		TestUni->GetTransform().SetWorldPosition({ -1230.f,370.f,0.f });
	}

	
	{
		ArbitorB* TestUni = CreateActor<ArbitorB>(OBJECTORDER::Player);
		TestUni->GetTransform().SetWorldPosition({ -1290.f,370.f,0.f });
	}





	

}
void StageMain::Update(float _DeltaTime)
{


	if (GameEngineInput::GetInst()->IsDown("FreeCameaOnOff"))
	{
		// ;
		GetMainCameraActor()->FreeCameraModeOnOff();
	}


	GamePlayTime += _DeltaTime;
	
	
	//1.몬스터가 다 죽었을때
	//몬스터 리스트.사이즈 = 0일때 


	if (!StartCheck)
	{
		if (GamePlayTime >= StartTime)//10초후 시작
		{
			StartCheck = true;
		}


	}
	else
	{
		if (StageCount == 1)
		{
			Stage1(_DeltaTime);

		}
		else if (StageCount == 2)
		{

			Stage2(_DeltaTime);
		}
		else if (StageCount == 3)
		{

			Stage3(_DeltaTime);
		}
		else if (StageCount == 4)
		{

			Stage4(_DeltaTime);
		}
		else if (StageCount == 5)
		{

			Stage5(_DeltaTime);
		}
		else if (StageCount == 6)
		{

			Stage6(_DeltaTime);
		}


	}
	


}
void StageMain::End() 
{


}


void StageMain::Stage1(float _DeltaTime)
{
	MonTime += _DeltaTime;

	if (MonTime >= MonTimeMax)
	{

		if (MonCount == MonMax)
		{


			if (GetGroup(OBJECTORDER::Monster).size() == 0)
			{
				MonTime = 0.f;
				GamePlayTime = 0.f;
				MonCount = 0;
				++StageCount;
				StartCheck = false;
			}

			return;
		}
		MonTime -= MonTimeMax;

		{
			corsairMon* TestUni = CreateActor<corsairMon>(OBJECTORDER::Monster);
			TestUni->m_Info.m_Hp = 1300;
			TestUni->m_Info.Gold = 8;
			auto	iter = CheckPoint.begin();
			auto	iterEnd = CheckPoint.end();

			for (; iter != iterEnd; ++iter)
			{
				TestUni->SetCheckPoinr(*iter);
			}

		}


		++MonCount;



	}

}
void StageMain::Stage2(float _DeltaTime)
{
	MonTime += _DeltaTime;

	if (MonTime >= MonTimeMax)
	{

		if (MonCount == MonMax)
		{


			if (GetGroup(OBJECTORDER::Monster).size() == 0)
			{
				MonTime = 0.f;
				GamePlayTime = 0.f;
				MonCount = 0;
				++StageCount;
				StartCheck = false;
			}

			return;
		}
		MonTime -= MonTimeMax;

		{
			ScoutMon* TestUni = CreateActor<ScoutMon>(OBJECTORDER::Monster);
			TestUni->m_Info.m_Hp = 340;
			TestUni->m_Info.Gold = 8;
			auto	iter = CheckPoint.begin();
			auto	iterEnd = CheckPoint.end();

			for (; iter != iterEnd; ++iter)
			{
				TestUni->SetCheckPoinr(*iter);
			}

		}


		++MonCount;



	}
}
void StageMain::Stage3(float _DeltaTime)
{
	MonTime += _DeltaTime;

	if (MonTime >= MonTimeMax)
	{

		if (MonCount == MonMax)
		{


			if (GetGroup(OBJECTORDER::Monster).size() == 0)
			{
				MonTime = 0.f;
				GamePlayTime = 0.f;
				MonCount = 0;
				++StageCount;
				StartCheck = false;
			}

			return;
		}
		MonTime -= MonTimeMax;

		{
			DivaolerMon* TestUni = CreateActor<DivaolerMon>(OBJECTORDER::Monster);
			TestUni->m_Info.m_Hp = 380;
			TestUni->m_Info.Gold = 8;
			auto	iter = CheckPoint.begin();
			auto	iterEnd = CheckPoint.end();

			for (; iter != iterEnd; ++iter)
			{
				TestUni->SetCheckPoinr(*iter);
			}

		}


		++MonCount;



	}
}
void StageMain::Stage4(float _DeltaTime)
{
	MonTime += _DeltaTime;

	if (MonTime >= MonTimeMax)
	{

		if (MonCount == MonMax)
		{


			if (GetGroup(OBJECTORDER::Monster).size() == 0)
			{
				MonTime = 0.f;
				GamePlayTime = 0.f;
				MonCount = 0;
				++StageCount;
				StartCheck = false;
			}

			return;
		}
		MonTime -= MonTimeMax;

		{
			UltraMon* TestUni = CreateActor<UltraMon>(OBJECTORDER::Monster);
			TestUni->m_Info.m_Hp = 420;
			TestUni->m_Info.Gold = 8;
			auto	iter = CheckPoint.begin();
			auto	iterEnd = CheckPoint.end();

			for (; iter != iterEnd; ++iter)
			{
				TestUni->SetCheckPoinr(*iter);
			}

		}

		++MonCount;

	}


}

void StageMain::Stage5(float _DeltaTime)
{
	MonTime += _DeltaTime;

	if (MonTime >= MonTimeMax)
	{

		if (MonCount == MonMax)
		{


			if (GetGroup(OBJECTORDER::Monster).size() == 0)
			{
				MonTime = 0.f;
				GamePlayTime = 0.f;
				MonCount = 0;
				++StageCount;
				StartCheck = false;
			}

			return;
		}
		MonTime -= MonTimeMax;

		{
			Overload* TestUni = CreateActor<Overload>(OBJECTORDER::Monster);
			TestUni->m_Info.m_Hp = 460;
			TestUni->m_Info.Gold = 8;
			auto	iter = CheckPoint.begin();
			auto	iterEnd = CheckPoint.end();

			for (; iter != iterEnd; ++iter)
			{
				TestUni->SetCheckPoinr(*iter);
			}

		}

		++MonCount;

	}
}
void StageMain::Stage6(float _DeltaTime)
{
	MonTime += _DeltaTime;


	int BosMax = 1;

	if (MonTime >= MonTimeMax)
	{

		if (MonCount == BosMax)
		{


			if (GetGroup(OBJECTORDER::Monster).size() == 0)
			{
				MonTime = 0.f;
				GamePlayTime = 0.f;
				MonCount = 0;
				++StageCount;
				StartCheck = false;
			}

			return;
		}
		MonTime -= MonTimeMax;

		{
			Overload* TestUni = CreateActor<Overload>(OBJECTORDER::Monster);
			TestUni->m_Info.m_Hp = 5000;
			TestUni->m_Info.Gold = 8;
			auto	iter = CheckPoint.begin();
			auto	iterEnd = CheckPoint.end();

			for (; iter != iterEnd; ++iter)
			{
				TestUni->SetCheckPoinr(*iter);
			}

		}

		++MonCount;

	}
}
void StageMain::Stage7(float _DeltaTime)
{

}
void StageMain::Stage8(float _DeltaTime)
{

}
void StageMain::Stage9(float _DeltaTime)
{

}
void StageMain::Stage10(float _DeltaTime)
{

}
void StageMain::Stage12(float _DeltaTime)
{

}
void StageMain::Stage13(float _DeltaTime)
{

}
void StageMain::Stage14(float _DeltaTime)
{

}
void StageMain::Stage15(float _DeltaTime)
{

}
void StageMain::Stage16(float _DeltaTime)
{

}
void StageMain::Stage17(float _DeltaTime)
{

}
void StageMain::Stage18(float _DeltaTime)
{

}
void StageMain::Stage19(float _DeltaTime)
{

}
void StageMain::Stage20(float _DeltaTime)
{

}
void StageMain::Stage21(float _DeltaTime)
{

}
void StageMain::Stage22(float _DeltaTime)
{

}
void StageMain::Stage23(float _DeltaTime)
{

}
void StageMain::Stage24(float _DeltaTime)
{

}
void StageMain::Stage25(float _DeltaTime)
{

}