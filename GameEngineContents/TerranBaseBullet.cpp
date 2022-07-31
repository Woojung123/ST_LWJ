

#include "PreCompile.h"
#include "TerranBaseBullet.h"
#include <GameEngineBase/GameEngineInput.h>
#include <iostream>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineDefaultRenderer.h>

#include "UnitBase.h"


TerranBaseBullet::TerranBaseBullet()
	: Speed(0.f)
	, Renderer(nullptr)
	, m_Dir({ 0 })
	, BAniChange(false)
	, DamCheck(false)
{
}

TerranBaseBullet::~TerranBaseBullet()
{
}

void TerranBaseBullet::AttEnd(const FrameAnimation_DESC& _Info)
{
	BAniChange = true;

}


void TerranBaseBullet::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 40.f,40.f,1.f });
		//Renderer->GetTransform().SetWorldPosition({ -1050.f,370.f,0.f });

		Renderer->CreateFrameAnimationFolder("scoutblt", FrameAnimation_DESC("scoutblt", 0.05f));
		Renderer->ChangeFrameAnimation("scoutblt");
		Renderer->AnimationBindEnd("scoutblt", &TerranBaseBullet::AttEnd, this);
	}
	m_Info.Dammage = 20;

}

void TerranBaseBullet::Update(float _DeltaTime)
{

	if (!DamCheck)
	{
		((UnitBase*)TarGet)->m_Info.m_Hp -= m_Info.Dammage;;
		DamCheck = true;
	}

	if (BAniChange)
		Death();

	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -50.f, WorldPos.w });


	
	//TarGet->m_In

}