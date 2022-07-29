

#include "PreCompile.h"
#include "BloodBEff.h"
#include <GameEngineBase/GameEngineInput.h>
#include <iostream>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineDefaultRenderer.h>
BloodBEff::BloodBEff()
	: Speed(0.f)
	, Renderer(nullptr)
	, m_Dir({ 0 })
	, BAniChange(false)
{
}

BloodBEff::~BloodBEff()
{
	Death();
}

void BloodBEff::AttEnd(const FrameAnimation_DESC& _Info)
{
	BAniChange = true;

}


void BloodBEff::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 64.f,64.f,1.f });
		//Renderer->GetTransform().SetWorldPosition({ -1050.f,370.f,0.f });

		Renderer->CreateFrameAnimationFolder("MutalDead0", FrameAnimation_DESC("MutalDead0", 0.05f));
		Renderer->ChangeFrameAnimation("MutalDead0");
		Renderer->AnimationBindEnd("MutalDead0", &BloodBEff::AttEnd, this);
	}
}

void BloodBEff::Update(float _DeltaTime)
{

	if (BAniChange)
		Death();


	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -50.f, WorldPos.w });

}