

#include "PreCompile.h"
#include "RiverBullet.h"
#include "RiverBoom.h"
#include "GlobalContentsValue.h"
#include <GameEngineCore/GameEngineLevel.h>

#include "UnitBase.h"
#include "RiverTrail.h"


RiverBullet::RiverBullet()
	: Speed(1000.0f)
	, Renderer(nullptr)
	, m_Dir({ 0 })
	, TarGet(nullptr)
	, DamCheck(false)
	, TrailTime(0)
{
}

RiverBullet::~RiverBullet()
{
	Death();
}




void RiverBullet::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 32.f,32.f,1.f });
		//Renderer->GetTransform().SetWorldPosition({ -1050.f,370.f,0.f });

		Renderer->CreateFrameAnimationFolder("Scarab0", FrameAnimation_DESC("Scarab0", 0.1f));
		Renderer->ChangeFrameAnimation("Scarab0");

	}
	m_Info.Dammage = 20;
}

void RiverBullet::Update(float _DeltaTime)
{
	TrailTime += _DeltaTime;

	float4 MyPos = GetTransform().GetWorldPosition();


	if (TrailTime >= 0.025f)
	{
		TrailTime -= 0.025f;

		RiverTrail* TestUni = GetLevel()->CreateActor<RiverTrail>(OBJECTORDER::Effect);
		TestUni->GetTransform().SetWorldPosition(MyPos);

	}

	if (TarGet)
	{

		float4 TargetPos = TarGet->GetTransform().GetWorldPosition();
		
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

			////DraBallEff
			RiverBoom* TestUni = GetLevel()->CreateActor<RiverBoom>(OBJECTORDER::Effect);
			TestUni->GetTransform().SetWorldPosition(MyPos);
			((UnitBase*)TarGet)->m_Info.m_Hp -= m_Info.Dammage;;
			Death();
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