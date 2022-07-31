

#include "PreCompile.h"
#include "SporeHit.h"
#include <GameEngineBase/GameEngineInput.h>
#include <iostream>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineDefaultRenderer.h>
SporeHit::SporeHit()
	: Speed(0.f)
	, Renderer(nullptr)
	, m_Dir({ 0 })
	, BAniChange(false)
{
}

SporeHit::~SporeHit()
{
	Death();
}

void SporeHit::AttEnd(const FrameAnimation_DESC& _Info)
{
	BAniChange = true;

}


void SporeHit::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 72.f,72.f,1.f });
		//Renderer->GetTransform().SetWorldPosition({ -1050.f,370.f,0.f });

		Renderer->CreateFrameAnimationFolder("SporeHit", FrameAnimation_DESC("SporeHit", 0.05f));
		Renderer->ChangeFrameAnimation("SporeHit");
		Renderer->AnimationBindEnd("SporeHit", &SporeHit::AttEnd, this);
	}
}

void SporeHit::Update(float _DeltaTime)
{

	if (BAniChange)
		Death();


	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -50.f, WorldPos.w });

}