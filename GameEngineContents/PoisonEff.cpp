

#include "PreCompile.h"
#include "PoisonEff.h"
#include "GlobalContentsValue.h"
#include <GameEngineCore/GameEngineLevel.h>

#include "UnitBase.h"



PoisonEff::PoisonEff()
	: Speed(0.0f)
	, Renderer(nullptr)
	, m_Dir({ 0 })
	, TarGet(nullptr)
	, m_dotDam(0.f)
{
}

PoisonEff::~PoisonEff()
{
	Death();
}




void PoisonEff::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 40.f,40.f,1.f });
		//Renderer->GetTransform().SetWorldPosition({ -1050.f,370.f,0.f });

		Renderer->CreateFrameAnimationFolder("zspark", FrameAnimation_DESC("zspark", 0.1f));
		Renderer->ChangeFrameAnimation("zspark");

	}

	m_Info.Dammage = 10;

	//Death(5.f);

}

void PoisonEff::Update(float _DeltaTime)
{
	Speed += _DeltaTime;

	if (TarGet)
	{
		float4 TargetPos = TarGet->GetTransform().GetWorldPosition();
		TargetPos.z = -45.f;
		GetTransform().SetWorldPosition(TargetPos);

		m_dotDam += _DeltaTime;

		if (m_dotDam >= 1.f)
		{
			m_dotDam -= 1.f;
			((UnitBase*)TarGet)->m_Info.m_Hp -= m_Info.Dammage;

			if (((UnitBase*)TarGet)->m_Info.m_Hp <= 0.f)
			{
				Death();
			}

		}

	}
	else
	{
		Death();
		return;
	}


	if (Speed >= 5.f)
	{
		Death();
		return;
	}

	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -45.f, WorldPos.w });


}