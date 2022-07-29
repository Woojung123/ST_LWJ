

#include "PreCompile.h"
#include "ZergDeath.h"
#include <GameEngineBase/GameEngineInput.h>
#include <iostream>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineDefaultRenderer.h>
ZergDeath::ZergDeath()
	: Speed(0.f)
	, Renderer(nullptr)
	, m_Dir({ 0 })
	, BAniChange(false)
{
}

ZergDeath::~ZergDeath()
{
}

void ZergDeath::AttEnd(const FrameAnimation_DESC& _Info)
{
	BAniChange = true;

}


void ZergDeath::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 140.f,140.f,1.f });
		//Renderer->GetTransform().SetWorldPosition({ -1050.f,370.f,0.f });

		Renderer->CreateFrameAnimationFolder("GardianDead0", FrameAnimation_DESC("GardianDead0", 0.05f));
		Renderer->ChangeFrameAnimation("GardianDead0");
		Renderer->AnimationBindEnd("GardianDead0", &ZergDeath::AttEnd, this);
	}
}

void ZergDeath::Update(float _DeltaTime)
{

	if (BAniChange)
		Death();

	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -20.f, WorldPos.w });

}