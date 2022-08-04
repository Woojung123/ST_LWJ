
#include "PreCompile.h"
#include "CorSplash.h"
#include <GameEngineBase/GameEngineInput.h>
#include <iostream>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineDefaultRenderer.h>

#include "UnitBase.h"

CorSplash::CorSplash()
	: Speed(0.f)
	, Renderer(nullptr)
	, m_Dir({ 0 })
	, BAniChange(false)
	, DamCheck(false)
	, TarGet(nullptr)
{
}

CorSplash::~CorSplash()
{
}

void CorSplash::AttEnd(const FrameAnimation_DESC& _Info)
{
	BAniChange = true;

}



void CorSplash::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 64.f,64.f,1.f });
		//Renderer->GetTransform().SetWorldPosition({ -1050.f,370.f,0.f });

		Renderer->CreateFrameAnimationFolder("Corsair_Splash", FrameAnimation_DESC("Corsair_Splash", 0.1f));
		Renderer->ChangeFrameAnimation("Corsair_Splash");
		Renderer->AnimationBindEnd("Corsair_Splash", &CorSplash::AttEnd, this);
	}

	m_Info.Dammage = 10;
}

void CorSplash::Update(float _DeltaTime)
{


	if (!DamCheck)
	{
		if (TarGet)
		{
			((UnitBase*)TarGet)->m_Info.m_Hp -= m_Info.Dammage;;
			DamCheck = true;

		}



	}

	if (BAniChange)
		Death();

	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -46.f, WorldPos.w });

}