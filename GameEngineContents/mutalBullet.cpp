
#include "PreCompile.h"
#include "mutalBullet.h"
#include "MutalEff.h"
#include "GlobalContentsValue.h"
#include <GameEngineCore/GameEngineLevel.h>

#include "UnitBase.h"



mutalBullet::mutalBullet()
	: Speed(1000.0f)
	, Renderer(nullptr)
	, m_Dir({ 0 })
	, TarGet(nullptr)
	, TarGet2(nullptr)
	, TarGet3(nullptr)
	, DamCheck(false)
	, TarGetNum(0)
{
}

mutalBullet::~mutalBullet()
{
	Death();
}




void mutalBullet::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 72.f,72.f,1.f });
		//Renderer->GetTransform().SetWorldPosition({ -1050.f,370.f,0.f });

		Renderer->CreateFrameAnimationFolder("Mutalblt", FrameAnimation_DESC("Mutalblt", 0.1f));
		Renderer->ChangeFrameAnimation("Mutalblt");

	}
	m_Info.Dammage = 140;
}

void mutalBullet::Update(float _DeltaTime)
{


	


	if (TarGet)
	{

		float4 TargetPos = TarGet->GetTransform().GetWorldPosition();
		float4 MyPos = GetTransform().GetWorldPosition();

		if (TargetPos.x <= -1400.f)
		{
			Death();
		}


		m_Dir = (TargetPos - MyPos);
		m_Dir.Normalize();
		GetTransform().SetWorldMove(m_Dir * _DeltaTime * Speed);

		if ((int)(MyPos.x + 3) > (int)(TargetPos.x) &&
			(int)(MyPos.x - 3) < (int)(TargetPos.x)
			&& (int)(MyPos.y - 3) < (int)(TargetPos.y)
			&& (int)(MyPos.y + 3) > (int)(TargetPos.y))
		{
			if (TarGetNum == 0)
			{
				MutalEff* TestUni = GetLevel()->CreateActor<MutalEff>(OBJECTORDER::Effect);
				TestUni->GetTransform().SetWorldPosition(MyPos);
				((UnitBase*)TarGet)->m_Info.m_Hp -= m_Info.Dammage;
				++TarGetNum;
				TarGet = TarGet2;
			}
			else if (TarGetNum == 1)
			{
				MutalEff* TestUni = GetLevel()->CreateActor<MutalEff>(OBJECTORDER::Effect);
				TestUni->GetTransform().SetWorldPosition(MyPos);
				((UnitBase*)TarGet)->m_Info.m_Hp -= m_Info.Dammage;
				++TarGetNum;
				TarGet = TarGet3;
			}
			else if (TarGetNum == 2)
			{
				MutalEff* TestUni = GetLevel()->CreateActor<MutalEff>(OBJECTORDER::Effect);
				TestUni->GetTransform().SetWorldPosition(MyPos);
				((UnitBase*)TarGet)->m_Info.m_Hp -= m_Info.Dammage;
				Death();

			}
			

		}

	}
	else
	{
		Death();
		return;
	}


	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -45.f, WorldPos.w });


}