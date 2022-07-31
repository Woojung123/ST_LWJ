

#include "PreCompile.h"
#include "Spore.h"
#include "SporeHit.h"
#include "GlobalContentsValue.h"
#include <GameEngineCore/GameEngineLevel.h>

#include "UnitBase.h"



Spore::Spore()
	: Speed(1000.0f)
	, Renderer(nullptr)
	, m_Dir({ 0 })
	, TarGet(nullptr)
	,DamCheck(false)
{
}

Spore::~Spore()
{
	Death();
}




void Spore::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 60.f,60.f,1.f });
		//Renderer->GetTransform().SetWorldPosition({ -1050.f,370.f,0.f });

		Renderer->CreateFrameAnimationFolder("Spore", FrameAnimation_DESC("Spore", 0.1f));
		Renderer->ChangeFrameAnimation("Spore");

	}
	m_Info.Dammage = 20;
}

void Spore::Update(float _DeltaTime)
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

			////DraBallEff
			SporeHit* TestUni = GetLevel()->CreateActor<SporeHit>(OBJECTORDER::Effect);
			TestUni->GetTransform().SetWorldPosition(MyPos);
			((UnitBase*)TarGet)->m_Info.m_Hp -= m_Info.Dammage;
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