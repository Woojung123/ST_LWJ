
#include "PreCompile.h"
#include "Sunken.h"
#include <GameEngineBase/GameEngineInput.h>
#include <iostream>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineDefaultRenderer.h>

#include "UnitBase.h"

Sunken::Sunken()
	: Speed(0.f)
	, Renderer(nullptr)
	, m_Dir({ 0 })
	,BAniChange(false)
	, DamCheck(false)
	,TarGet(nullptr)
{
}

Sunken::~Sunken()
{
}

void Sunken::AttEnd(const FrameAnimation_DESC& _Info)
{
	BAniChange = true;

}



void Sunken::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 128.f,128.f,1.f });
		//Renderer->GetTransform().SetWorldPosition({ -1050.f,370.f,0.f });

		Renderer->CreateFrameAnimationFolder("tenta", FrameAnimation_DESC("tenta", 0.1f));
		Renderer->ChangeFrameAnimation("tenta");
		Renderer->AnimationBindEnd("tenta", &Sunken::AttEnd, this);
	}

	m_Info.Dammage = 20;
}

void Sunken::Update(float _DeltaTime)
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