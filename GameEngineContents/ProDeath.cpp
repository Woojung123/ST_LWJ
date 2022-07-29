

#include "PreCompile.h"
#include "ProDeath.h"
#include <GameEngineBase/GameEngineInput.h>
#include <iostream>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineDefaultRenderer.h>
ProDeath::ProDeath()
	: Speed(0.f)
	, Renderer(nullptr)
	, m_Dir({ 0 })
	, BAniChange(false)
{
}

ProDeath::~ProDeath()
{
}

void ProDeath::AttEnd(const FrameAnimation_DESC& _Info)
{
	BAniChange = true;

}


void ProDeath::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 128.f,128.f,1.f });
		//Renderer->GetTransform().SetWorldPosition({ -1050.f,370.f,0.f });

		Renderer->CreateFrameAnimationFolder("zelotDead0", FrameAnimation_DESC("zelotDead0", 0.05f));
		Renderer->ChangeFrameAnimation("zelotDead0");
		Renderer->AnimationBindEnd("zelotDead0", &ProDeath::AttEnd, this);
	}
}

void ProDeath::Update(float _DeltaTime)
{

	
	if (BAniChange)
		Death();


	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -20.f, WorldPos.w });

}