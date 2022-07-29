

#include "PreCompile.h"
#include "DraBallEff.h"
#include <GameEngineBase/GameEngineInput.h>
#include <iostream>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineDefaultRenderer.h>
DraBallEff::DraBallEff()
	: Speed(0.f)
	, Renderer(nullptr)
	, m_Dir({ 0 })
	, BAniChange(false)
{
}

DraBallEff::~DraBallEff()
{
	Death();
}

void DraBallEff::AttEnd(const FrameAnimation_DESC& _Info)
{
	BAniChange = true;

}


void DraBallEff::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 64.f,64.f,1.f });
		//Renderer->GetTransform().SetWorldPosition({ -1050.f,370.f,0.f });

		Renderer->CreateFrameAnimationFolder("draboom", FrameAnimation_DESC("draboom", 0.05f));
		Renderer->ChangeFrameAnimation("draboom");
		Renderer->AnimationBindEnd("draboom", &DraBallEff::AttEnd, this);
	}
}

void DraBallEff::Update(float _DeltaTime)
{

	if (BAniChange)
		Death();


	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -50.f, WorldPos.w });
	
}